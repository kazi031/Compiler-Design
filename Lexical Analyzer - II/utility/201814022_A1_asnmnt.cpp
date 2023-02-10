#include<bits/stdc++.h>
#define SIZE 101
using namespace std;

string s1[12] = {"if", "else", "else if", "for", "while", "int", "char", "float", "double", "break", "void" , "return"};
string s2[10];
string s3[14] = {"==",">","<","!=",">=","<=","+","-","*","/","%","++","--","="};
int id_count = 0;





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
            freopen("Symboltable.txt","a",stdout);
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
            freopen("Symboltable.txt","a",stdout);
            printf("<%s , %s> inserted at position (%d,%d)\n",s,t,hash_val,count);
        }
        else if(hashtable[hash_val]->next==NULL){
            hashtable[hash_val]->next = temp;
            count++;
            freopen("Symboltable.txt","a",stdout);
            printf("<%s , %s> inserted at position (%d,%d)\n",s,t,hash_val,count);
        }
        else{
            SymbolInfo * temp1 = hashtable[hash_val];
            while(temp1->next != NULL){
                temp1 = temp1->next;
                count++;
            }
            temp1->next = temp;
            freopen("Symboltable.txt","a",stdout);
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
            freopen("Symboltable.txt","a",stdout);
            printf("%s not found\n",s);
        }
        else{
            SymbolInfo * temp = hashtable[hash_val];
            int count = 0;
            bool flag = false;
            while(temp!=NULL){
                if(strcmp(temp->symbol,s)==0){
                    freopen("Symboltable.txt","a",stdout);
                    printf("<%s , %s> found at position (%d,%d)\n",s,temp->type,hash_val,count);
                    flag = true;
                }
                count++;
                temp = temp->next;
            }
            if(flag == false){
                freopen("Symboltable.txt","a",stdout);
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
                freopen("SymboltablePrint.txt","a",stdout);
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
            freopen("Symboltable.txt","a",stdout);
            printf("%s not found\n",s);
        }
        else if(strcmp(hashtable[hash_val]->symbol,s)==0){
            SymbolInfo * temp = hashtable[hash_val];
            hashtable[hash_val]=hashtable[hash_val]->next;
            delete temp;
            freopen("Symboltable.txt","a",stdout);
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
                freopen("Symboltable.txt","a",stdout);
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


SymbolTable s10;







bool Identifier_checking(string s){

    for(int i=0;i<id_count;i++){
        if(s == s2[i]){
            return true;
        }
    }
    return false;
}
bool operator_checking(string s){
    for(int i=0;i<14;i++){
        if(s == s3[i]){
            return true;
        }
    }
    return false;

}
bool keyword_checking(string s){
    for(int i=0;i<12;i++){
        if(s == s1[i])
        {
            return true;
        }
    }
    return false;
}
void Identifier_write(string s,int count){
    freopen("output_Identifier.txt","a",stdout);
    cout << s << "  " << count+1 << endl;
    char * strarr = new char[s.size()+1];
    strcpy(strarr,s.c_str());
    s10.insert(strarr,"Identifier");
    delete [] strarr;
}
void keyword_write(string s,int count){
    freopen("output_keyword.txt","a",stdout);
    cout << s << "  " <<count+1 <<  endl;
    char * strarr = new char[s.size()+1];
    strcpy(strarr,s.c_str());
    s10.insert(strarr,"Keyword");
    delete [] strarr;

}
void Function_write(string s,int count){

    freopen("output_Function.txt","a",stdout);
    cout << s << "  " << count+1 << endl;
    char * strarr = new char[s.size()+1];
    strcpy(strarr,s.c_str());
    s10.insert(strarr,"Function");
    delete [] strarr;

}
void Operator_write(string s,int count){
    freopen("output_Operator.txt","a",stdout);
    cout << s << "  " << count+1 << endl;
    char * strarr = new char[s.size()+1];
    strcpy(strarr,s.c_str());
    s10.insert(strarr,"Operator");
    delete [] strarr;

}
void symbol_table_print(){

    freopen("SymboltablePrint.txt","a",stdout);
    s10.Print();
}
void symbol_table_print_clear(){
    freopen("SymboltablePrint.txt","w",stdout);
    printf("");
}

void Identifier_clear(){
    freopen("output_Identifier.txt","w",stdout);
    printf("");
}
void keyword_clear(){
    freopen("output_keyword.txt","w",stdout);
    printf("");
}
void Function_clear(){

    freopen("output_Function.txt","w",stdout);
    printf("");

}
void Operator_clear(){
    freopen("output_Operator.txt","w",stdout);
    printf("");

}
void symbol_table_clear(){

    freopen("Symboltable.txt","w",stdout);
    printf("");

}

void Tokenizer(string line,int count){
    string arr = "";
    string buff = "";
    for(int i=0;i<line.size();i++){
        //cout << line[i] << endl;
        if(line[i]==' ' || ((line[i]<'A'||line[i]>'Z') && (line[i]<'a'||line[i]>'z')) && line[i]!='"'){
            //cout << arr << " Line no." << count+1 << endl;
            bool check = keyword_checking(arr);
            bool check2 = keyword_checking(buff);
            if(check == true){
                keyword_write(arr,count);
                //cout << arr << " Keyword" << " " <<count+1 <<  endl;
                buff = arr;
                arr = "";
            }
            else if(check == false and line[i]=='('){
                Function_write(arr,count);
                //cout <<arr << " Function" << " " << count+1 << endl;
                //buff = arr;
                arr = "";
            }
            else if(check2 == true && line[i] != '(' && arr!="" && Identifier_checking(arr)==false){
                s2[id_count] = arr;
                id_count++;
                //cout << arr << " Identifier" << " " << count+1 << endl;
                Identifier_write(arr,count);
                string op2 = "" ;
                if(line[i] == ' '){
                    op2 = op2 + line[i+1] + line[i+2];
                    if(operator_checking(op2)==true){
                        //cout << op2 << " Operator" << " " << count+1 << endl;
                        Operator_write(op2,count);
                        //printf("  This is second check\n");
                    }
                    else{
                        op2 = "";
                        op2 = op2 + line[i+1];
                        if(operator_checking(op2)==true){
                            //cout << op2 << " Operator" << " " << count+1 << endl;
                            Operator_write(op2,count);
                            //printf("  This is Third check\n");
                        }
                    }
                }
                else if(line[i]!=' '){
                    op2 = op2 + line[i] + line[i+1];
                    if(operator_checking(op2)==true){
                        //cout << op2 << " Operator" << " " << count+1 << endl;
                        Operator_write(op2,count);
                        //printf("  This is second check\n");
                    }
                    else{
                        op2 = "";
                        op2 = op2 + line[i];
                        if(operator_checking(op2)==true){
                            //cout << op2 << " Operator" << " " << count+1 << endl;
                            Operator_write(op2,count);
                            //printf("  This is Third check\n");
                        }
                    }
                }
                arr = "";

            }
            else if(Identifier_checking(arr)==true){
                //cout << arr << " Identifier" << " " << count+1 << endl;
                Identifier_write(arr,count);
                string op2 = "" ;
                if(line[i] == ' '){
                    op2 = op2 + line[i+1] + line[i+2];
                    if(operator_checking(op2)==true){
                        //cout << op2 << " Operator" << " " << count+1 << endl;
                        Operator_write(op2,count);
                        //printf("  This is second check\n");
                    }
                    else{
                        op2 = "";
                        op2 = op2 + line[i+1];
                        if(operator_checking(op2)==true){
                            //cout << op2 << " Operator" << " " << count+1 << endl;
                            Operator_write(op2,count);
                            //printf("  This is Third check\n");
                        }
                    }
                }
                else if(line[i]!=' '){
                    op2 = op2 + line[i] + line[i+1];
                    if(operator_checking(op2)==true){
                        //cout << op2 << " Operator" << " " << count+1 << endl;
                        Operator_write(op2,count);
                        //printf("  This is second check\n");
                    }
                    else{
                        op2 = "";
                        op2 = op2 + line[i];
                        if(operator_checking(op2)==true){
                            //cout << op2 << " Operator" << " " << count+1 << endl;
                            Operator_write(op2,count);
                            //printf("  This is Third check\n");
                        }
                    }
                }


                //cout << op2 << endl;
                arr = "";
            }
            else{

                arr = "";
            }

        }


        else{
            arr = arr + line[i];
        }

    }



}

int main(){

    Identifier_clear();
    keyword_clear();
    Function_clear();
    Operator_clear();
    symbol_table_clear();
    symbol_table_print_clear();
    int count = 0;
    string line;
    ifstream inpfile;
    inpfile.open("sample input.txt");
    if(inpfile.is_open()){
        while(getline(inpfile,line)){
            Tokenizer(line,count);
            count++;
        }
        inpfile.close();
    }
    else{
        cout<<"Unable to open the file."<<endl;
    }
//    for(int i=0;i<10;i++){
//        cout << s2[i] << endl;
//    }
    symbol_table_print();
}
