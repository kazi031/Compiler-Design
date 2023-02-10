#include<bits/stdc++.h>
#define SIZE 101
using namespace std;
int Hash_func(char * s){

    int length = strlen(s);
    int mid_val;
    if (length%2 == 0){
        mid_val = length/2;
    }
    else{
        mid_val = length/2 + 1;
    }

    int ascii = s[mid_val-1] ;

    int Hash_val = (ascii*22)%101;
    return Hash_val;
}
class SymbolInfo{
public:
    char * symbol;
    char * type;
    SymbolInfo * next;
};

class SymbolTable{
private:
    SymbolInfo ** hashtable;
public:
    SymbolTable(){
        hashtable = (SymbolInfo**)calloc(SIZE,sizeof(SymbolInfo*));
    }
    void insert(char * s, char * t){
        bool flag = Lookup1(s);
        if(flag == true){
            printf("<%s , %s> already exists\n",s,t);
        }
        else{
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
        else if(hashtable[hash_val]->next==NULL){
            hashtable[hash_val]->next = temp;
            count++;
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
    }
    bool Lookup1(char * s){
        int hash_val = Hash_func(s);
        if(hashtable[hash_val]==NULL){
            return false;
        }
        else{
            SymbolInfo * temp = hashtable[hash_val];
            int count = 0;
            bool flag = false;
            while(temp!=NULL){
                if(strcmp(temp->symbol,s)==0){
                    flag = true;
                }
                count++;
                temp = temp->next;
            }
            if(flag == false){
                return false;
            }
            else{
                return true;
            }
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
        bool flag = Lookup1(s);
        int hash_val = Hash_func(s);
        if(flag == false){
            printf("%s not found\n",s);
        }
        else if(strcmp(hashtable[hash_val]->symbol,s)==0){
            SymbolInfo * temp = hashtable[hash_val];
            hashtable[hash_val]=hashtable[hash_val]->next;
            delete temp;
            printf("Deleted from (%d,%d)\n",hash_val,0);
        }
        else{
            int count = 0;
            SymbolInfo * temp = hashtable[hash_val];
            while(temp!=NULL)
            {
                if(strcmp(temp->next->symbol,s)==0)
                {
                    SymbolInfo * temp3 = temp->next;
                    temp->next = temp->next->next;
                    delete temp3;
                    count++;
                }
                temp = temp ->next;
                printf("Deleted from (%d,%d)\n",hash_val,count);
            }
        }
    }
    ~SymbolTable(){
        for(int i=0;i<SIZE;i++){
            SymbolInfo * temp;
            while(hashtable[i] != NULL){
                temp = hashtable[i];
                hashtable[i] = hashtable[i]->next;
                free(temp);
            }
        }

    }
};


int main(){
    SymbolTable s1;
    ifstream inpfile;
    inpfile.open("input.txt");
    string s;
    while(inpfile>>s){
        char * arr = new char[3];
        strcpy(arr,s.c_str());
        if(strcmp(arr,"I")==0){
            char * symbol = new char[10];
            char * type = new char[10];
            inpfile>>s;
            strcpy(symbol,s.c_str());
            inpfile>>s;
            strcpy(type,s.c_str());
            s1.insert(symbol,type);
            delete [] type;
            delete [] symbol;
            delete [] arr;
        }
        else if(strcmp(arr,"L")==0){
        char * symbol = new char[10];
        inpfile>>s;
        strcpy(symbol,s.c_str());
        s1.Lookup(symbol);
        delete [] symbol;
        delete [] arr;
        }
        else if(strcmp(arr,"D")==0){
        char * symbol = new char[10];
        inpfile>>s;
        strcpy(symbol,s.c_str());
        s1.Delete(symbol);
        delete [] symbol;
        delete [] arr;
        }
        else if(strcmp(arr,"P")==0){
        s1.Print();
        delete [] arr;
        }
    }
    inpfile.close();
    return 0;
}
