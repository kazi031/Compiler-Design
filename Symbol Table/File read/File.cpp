#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream inpfile;
    inpfile.open("input.txt");
    char * arr;
    arr = (char*)malloc(3*sizeof(char));
    string s;
    while(inpfile>>s){
        strcpy(arr,s.c_str());
        if(strcmp(arr,"I")==0){
            printf("This is insert Function\n");
            char * symbol;
            char * type;
            symbol = (char*)malloc(10*sizeof(char));
            type = (char*)malloc(10*sizeof(char));
            inpfile>>s;
            strcpy(symbol,s.c_str());
            inpfile>>s;
            strcpy(type,s.c_str());
            printf("Insert <%s , %s>\n",symbol,type);
            free(symbol);
            free(type);
            free(arr);
        }
        else if(strcmp(arr,"L")==0){
        printf("This is Look-up Function\n");
        char * symbol;
        symbol = (char*)malloc(10*sizeof(char));
        inpfile>>s;
        strcpy(symbol,s.c_str());
        printf("Look-up %s\n",symbol);
        free(symbol);
        free(arr);
        }
        else if(strcmp(arr,"D")==0){
        printf("This is Delete Function\n");
        char * symbol;
        symbol = (char*)malloc(10*sizeof(char));
        inpfile>>s;
        strcpy(symbol,s.c_str());
        printf("Delete %s\n",symbol);
        free(symbol);
        free(arr);
        }
        else if(strcmp(arr,"P")==0){
        printf("This is Print Function\n");
        free(arr);
        }
    }
    inpfile.close();
    return 0;
}
