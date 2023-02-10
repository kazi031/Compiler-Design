%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int yylex(void);
int t_count = 1;

void yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);
	return;
}

char * generateToken(int i)
{
	char * token = (char*)calloc(10,sizeof(char));
	token[0] = 't' ;
	token[1] = i + '0' ;
	token[2] = '\0' ;
	return token ;
}

%}

%union { double dval; char ivar[5]; }
%token <dval> DOUBLE
%token <ivar> NAME
%type <ivar> expr
%type <ivar> term
%left LEFTSHIFT RIGHTSHIFT
%left '+' '-'
%left '*' '/'
%left ASTERISK SLASH MOD 
%left PM MP MM PP
%left INC DEC
%left DOUBLEASTERISK
%left '(' ')'
%%
program:
	line program			{
							}
	| line					{
							}
	;
line:
	expr 	'\n' 		    {	
								t_count =1;	
							}
	| NAME '=' expr '\n' 	{	
								printf(" %s = %s \n",$1,$3);
								t_count = 1;
							}
	;
expr:
	expr '+' expr 			{ 
								printf("t%d = %s + %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr '-' expr 		{ 
								printf("t%d = %s - %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	
	| expr '*' expr 		{ 
								printf("t%d = %s * %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr '/' expr 		{ 
								printf("t%d = %s / %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr '%' expr         {
								printf("t%d = %s %% %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr PM expr 			{
								printf("t%d = %s +- %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr PP expr          {
								printf("t%d = %s ++ %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr MP expr 			{
								printf("t%d = %s -+ %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr MM expr			{
								printf("t%d = %s -- %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr INC				{
								printf("t%d = %s + 1 \n",t_count,$1);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr DEC				{
								printf("t%d = %s - 1 \n",t_count,$1);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr LEFTSHIFT expr   {
								printf("t%d = %s << %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr RIGHTSHIFT expr  {
								printf("t%d = %s >> %s\n",t_count,$1,$3);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	| expr DOUBLEASTERISK expr {
									printf("t%d = %s ** %s\n",t_count,$1,$3);
									strcpy($$, generateToken(t_count));
									t_count++;
								}
	| term 				    { 				
								strcpy($$, $1);
							}
	| '(' expr ')' 			{
								printf("t%d = (%s)\n",t_count,$2);
								strcpy($$, generateToken(t_count));
								t_count++;
							}
	;
term:
	
	NAME 					{ 
								strcpy($$,$1);
							}
	| DOUBLE 				{ 	
								
							}
	;
%%

int main(void)
{
	yyparse();
	return 0;
}