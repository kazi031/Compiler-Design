
#include<stdio.h>

#include<string.h>

using namespace std;

int Hashfunc(char * s){

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


int main(){

    char *inp = new char[10];

    scanf("%s",inp);

   //printf("%s",inp);

    //int b = 'a';
    int c = Hashfunc(inp);

    printf("%d\n",c);
    printf("%d", '3' );
    delete [] inp;
}
