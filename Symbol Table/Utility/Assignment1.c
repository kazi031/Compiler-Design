#include<stdio.h>
#include<conio.h>
#include<string.h>
//Hash Func
struct SymbolInfo;
int Hash_func(char * s){

    int length = strlen(s);
    int mid_val;
    int ascii;
    if(length == 1){
        ascii = s[0];
    }
    else if (length%2 == 0){
        ascii = s[length-1]+s[length-2];
    }
    else{
        ascii = s[0] + s[1];
    }
    int Hash_val = (ascii*22)%101;
    return Hash_val;
}
struct SymbolInfo
{
    char * symbol;
    char * type;
    SymbolInfo * next;
};

struct SymbolTable
{
public:

    SymbolInfo ** hashtable;

    void init(){
        hashtable = (SymbolInfo**)calloc(SIZE,sizeof(SymbolInfo*));
    }
    void insert(char * s, char * t){
        SymbolInfo * temp = new SymbolInfo;
        temp->symbol = new char[strlen(s)+1];
        strcpy(temp->symbol,s);
        temp->type = new char[strlen(t)+1];
        strcpy(temp->type,t);
        temp->next = NULL;
        int hash_val = Hash_func(s);
        int count = 0;
        if(hashtable[hash_val]==NULL){
            hashtable[hash_val] = temp;
            printf("<%s , %s> inserted at position (%d,%d)\n",s,t,hash_val,count);
        }
        else{
            SymbolInfo * temp1 = hashtable[hash_val];
            while(temp1->next != NULL){
                temp1 = temp1->next;
                count++;
            }
            temp1->next = temp;
            printf("<%s , %s> inserted at position (%d,%d)\n",s,t,hash_val,count);
        }
    }
    void Lookup(char * s){
        int hash_val = Hash_func(s);
        if(hashtable[hash_val]==NULL){
            printf("%s not found\n",s);
        }
        else{
            SymbolInfo * temp = hashtable[hash_val];
            int count = 0;
            bool flag = false;
            while(temp!=NULL){
                if(strcmp(temp->symbol,s)==0){
                    printf("<%s , %s> found at position (%d,%d)\n",s,temp->type,hash_val,count);
                    flag = true;
                }
                count++;
                temp = temp->next;
            }
            if(flag == false){
                printf("%s not found\n",s);
            }
        }
    }
    void Print()
    {
        for(int i=0;i<SIZE;i++)
        {
            printf("%d ",i);
            SymbolInfo * temp = hashtable[i];
            while(temp != NULL)
            {
                printf("--> <%s , %s> ",temp->symbol,temp->type);
                temp = temp->next;
            }
            printf("\n");
        }
    }
    void Delete(char * s){
        int hash_val = Hash_func(s);
        SymbolInfo * temp = hashtable[hash_val];
        int count = 0;
        if(temp==NULL){
            printf("%s not found\n",s);
        }
        else if(strcmp(temp->symbol,s)==0){
            SymbolInfo * temp1 = temp;
            hashtable[hash_val] = temp->next;
            delete temp1;
            printf("Deleted from (%d,%d)\n",hash_val,count);
        }
        else{
            while(strcmp(temp->next->symbol,s) != 0){
                count++;
            }
            SymbolInfo * temp1 = temp;
            temp->next = temp->next->next;
            delete temp1;
            printf("Deleted from (%d,%d)\n",hash_val,count+1);
        }
    }
    void dispose(){
        for(int i=0;i<SIZE;i++){
            SymbolInfo * temp = hashtable[i];
            while(temp != NULL){
                SymbolInfo * temp1 = temp;
                temp = temp->next;
                free(temp1);
            }
        }

    }
};
int main(){
    SymbolTable s1;
    s1.init();
    s1.insert("123","Number");
    s1.insert("foo","Function");
    s1.Print();
    s1.Lookup("foo");
    s1.Lookup("ja");
    s1.Delete("foo");
    s1.Delete("Ja");
    s1.Print();
    s1.dispose();








}
