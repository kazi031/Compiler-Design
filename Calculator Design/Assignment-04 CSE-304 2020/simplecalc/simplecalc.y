%{

#include <stdio.h>

#include <stdlib.h>

#include<math.h>

#define YYSTYPE double          /* yyparse() stack type */

FILE * out;

void yyerror(const char *s)	{ fprintf("%s\n",s);
 }


int yylex(void);


%}


%token NEWLINE NUMBER LPAREN RPAREN

%left LEFTSHIFT RIGHTSHIFT

%left PLUS MINUS 

%left ASTERISK SLASH MOD DOUBLEASTERISK

%left INC DEC 

%%

input:        /* empty string */
    
| input line
 ;

line: NEWLINE
    
| expr NEWLINE 		{ fprintf("\t%.10g\n",$1); }
 ;

expr: expr PLUS expr 	{ $$ = $1 + $3; }
	
| expr MINUS expr  		{ $$ = $1 - $3; }
   	
| expr ASTERISK expr 	{ $$ = $1 * $3; }

| expr MOD expr			{
							if((int)$1 != $1 || (int)$3 != $3)
							{
								yyerror("MOD error");
							}
							else
							{
								$$ = (int)$1%(int)$3;
							}
						}
| expr SLASH expr{ 
					if($3 == 0)
					{
						yyerror("Div error");
					}
					else
					{
						$$ = $1 / $3;
					}
				 }

| expr INC {
				$$ = $1 + 1;
		   }

| INC expr{
				$$ = $2 + 1;
		   }
		

| expr DEC {
				$$ = $1 - 1;
		   }

| DEC expr{
				$$ = $2 - 1;
		   }
		
| expr RIGHTSHIFT expr {
							if((int)$1!=$1 || (int)$3!=$3)
							{
								yyerror("Shift error");
							}
							else
							{
								$$ = (int)$1 * 2 * (int)$3;
							}

					   }

| expr LEFTSHIFT expr {
							if((int)$1!=$1 || (int)$3!=$3)
							{
								yyerror("Shift error");
							}
							else
							{
								$$ = (int)$1 /( 2 * (int)$3);
							}

						}
			 
| expr DOUBLEASTERISK expr{
							$$ = pow($1,$3);
						  }
	
| MINUS expr 		 { $$ = -$2; }

| factor
 ;

factor:  LPAREN expr RPAREN  { $$ = $2; }
	  
| NUMBER
 ;

%%

int main()

{

file_inp();
fp = fopen("out.txt", "w");  
yyparse();
fclose(fp);
return 1;
    
}
