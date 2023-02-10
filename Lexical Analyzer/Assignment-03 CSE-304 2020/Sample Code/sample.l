%option noyywrap

%{
#include <stdio.h>
int word_count = 0;
int line_num=0;
%}

delim 			[  \t\n]
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
SEMICOLON		[;]
COMMA			[,]
Q				["]
OP2				({COMMA}|{SEMICOLON}|{PAREN}|{NUMBER}|{Exp}|{point}|{id})
OP				({ARop}|{OR}|{AND}|{ASop}|{LT}|{GT}|{NOT}|{Relop}|{Lop}|{plus}|{minus}|{INCop}|{DECop})
LITERAL			{Q}+({digit}|{letter}|{delim}|{OP}|{OP2})*{Q}+
%%
if {printf("<KEYWORD, %s>\n",yytext);}
then {printf("<KEYWORD, %s>\n",yytext);}
else {printf("<KEYWORD, %s>\n",yytext);}
else" "if {printf("<KEYWORD, %s>\n",yytext);}
switch {printf("<KEYWORD, %s>\n",yytext);}
case {printf("<KEYWORD, %s>\n",yytext);}
while {printf("<KEYWORD, %s>\n",yytext);}
for {printf("<KEYWORD, %s>\n",yytext);}
int {printf("<KEYWORD, %s>\n",yytext);}
break {printf("<KEYWORD, %s>\n",yytext);}
default {printf("<KEYWORD, %s>\n",yytext);}
main {printf("<KEYWORD, %s>\n",yytext);}
printf {printf("<KEYWORD, %s>\n",yytext);}

exit   {return 1;}
{id}	{printf("<ID, %s>\n",yytext); word_count++;}
{delim}+ {}
{ARop}   { printf("<ARop, %s>\n",yytext);}
{Lop}	{ printf("<Lop, %s>\n",yytext);}
{Relop} {printf("<Relop, %s>\n",yytext);}
{ASop} {printf("<ASop, %s>\n",yytext);}
{INCop} {printf("<INCop, %s>\n",yytext);}
{DECop} {printf("<DECop, %s>\n",yytext);}
{NUMBER} {printf("<NUMBER, %s>\n",yytext);}
{PAREN} {printf("<PAREN, %s>\n",yytext);}
[/]{1}[/]{1}[a-zA-Z0-9]* {}
{SEMICOLON} {printf("<SEMICOLON, %s>\n",yytext);}
{COMMA} {printf("<COMMA, %s>\n",yytext);}
{LITERAL} {printf("<LITERAL, %s>\n",yytext);}
%%

int main() {
yyin=fopen("in.txt","r");
yyout=fopen("out.txt","w");
yylex();
printf("Total Word: %d\n", word_count);
fclose(yyin);
}
