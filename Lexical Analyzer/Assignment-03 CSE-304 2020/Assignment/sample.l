%option noyywrap

%{
#include <stdio.h>
#include<conio.h>
int word_count = 0;
int line_num=1;
%}
newline			[\n]
delim 			[  \t]

line			{newline}
digit			[0-9]
letter          [A-Za-z\_]
id              {letter}+({letter}|{digit})*
ARop 			[-+*%/]
OR				[|]
AND				[&]
ASop			[=]
LT				[<]
GT				[>]
NOT				[!]
Relop			({ASop}{ASop}|{NOT}{ASop}|{LT}|{LT}{ASop}|{GT}{ASop}|{GT})
Lop				({OR}{OR}|{AND}{AND}|{NOT})   
plus			[+]
minus			[-]
INCop			({plus}{plus})
DECop			({minus}{minus})
point			[.]
Exp				[E]
PM				({plus}|{minus})
NUMBER			({PM}*+({digit}+|{digit}+{point}{digit}+|{digit}+{Exp}{PM}{digit}+|{digit}+{point}{digit}+{Exp}{PM}{digit}+))
PAREN			[()]
CURLY			[{}]
SEMICOLON		[;]
COMMA			[,] 
Q				["]
OP2				({COMMA}|{SEMICOLON}|{PAREN}|{NUMBER}|{Exp}|{point}|{id})
OP				({ARop}|{OR}|{AND}|{ASop}|{LT}|{GT}|{NOT}|{Relop}|{Lop}|{plus}|{minus}|{INCop}|{DECop})
LITERAL			{Q}+({digit}|{letter}|{delim}|{OP}|{OP2})*{Q}+
%%
if {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
then {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
else {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
else" "if {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
switch {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
case {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
while {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
for {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
int {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
float {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
double {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
break {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
default {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
main {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}
printf {fprintf(yyout,"<KEYWORD, %s>\t Line num = %d\n",yytext,line_num);}

exit   {return 1;}
{id}	{fprintf(yyout,"<ID, %s>\t Line num = %d\n",yytext,line_num); word_count++;}
{delim}+ {}
{ARop}   { fprintf(yyout,"<ARop, %s>\t Line num = %d\n",yytext,line_num);}
{Lop}	{ fprintf(yyout,"<Lop, %s>\t Line num = %d\n",yytext,line_num);}
{Relop} {fprintf(yyout,"<Relop, %s>\t Line num = %d\n",yytext,line_num);}
{ASop} {fprintf(yyout,"<ASop, %s>\t Line num = %d\n",yytext,line_num);}
{INCop} {fprintf(yyout,"<INCop, %s>\t Line num = %d\n",yytext,line_num);}
{DECop} {fprintf(yyout,"<DECop, %s>\t Line num = %d\n",yytext,line_num);}
{NUMBER} {fprintf(yyout,"<NUMBER, %s>\t Line num = %d\n",yytext,line_num);}
{PAREN} {fprintf(yyout,"<PAREN, %s>\t Line num = %d\n",yytext,line_num);}
{CURLY} {fprintf(yyout,"<CURLY, %s>\t Line num = %d\n",yytext,line_num);}
[/]{1}[/]{1}[a-zA-Z0-9]* {}   
{SEMICOLON} {fprintf(yyout,"<SEMICOLON, %s>\t Line num = %d\n",yytext,line_num);}
{COMMA} {fprintf(yyout,"<COMMA, %s>\t Line num = %d\n",yytext,line_num);}
{LITERAL} {fprintf(yyout,"<LITERAL, %s>\t Line num = %d\n",yytext,line_num);}
{line} {line_num++;fprintf(yyout,"\n\n\n");}
%%

int main() {
yyin=fopen("input.txt","r");
yyout=fopen("out.txt","w");
char singleline22[150];

yylex();


fprintf(yyout,"Total word count %d \n",word_count);
fclose(yyin);
}








