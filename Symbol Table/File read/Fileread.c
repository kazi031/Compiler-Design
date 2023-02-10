#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    FILE * fp;
    fp = fopen("input.txt","r");
    char * arr;
    Main :
    arr = malloc(3*sizeof(char));
    fscanf(fp,"%s",arr);
    if(strcmp(arr,"I")==0){
        printf("This is insert Function\n");
        char * symbol;
        char * type;
        symbol = malloc(10*sizeof(char));
        type = malloc(10*sizeof(char));
        fscanf(fp,"%s",symbol);
        fscanf(fp,"%s",type);
        printf("Insert <%s , %s>\n",symbol,type);
        free(symbol);
        free(type);
        free(arr);
        goto Main;
    }
    else if(strcmp(arr,"L")==0){
        printf("This is Look-up Function\n");
        char * symbol;
        symbol = malloc(10*sizeof(char));
        fscanf(fp,"%s",symbol);
        printf("Look-up %s\n",symbol);
        free(symbol);
        free(arr);
        goto Main;
    }
    else if(strcmp(arr,"D")==0){
        printf("This is Delete Function\n");
        char * symbol;
        symbol = malloc(10*sizeof(char));
        fscanf(fp,"%s",symbol);
        printf("Delete %s\n",symbol);
        free(symbol);
        free(arr);
        goto Main;
    }
    else if(strcmp(arr,"P")==0){
        printf("This is Print Function\n");
        goto Main;
        free(arr);
    }
    else if(arr == NULL){
        free(arr);
        return 0;
    }
}
