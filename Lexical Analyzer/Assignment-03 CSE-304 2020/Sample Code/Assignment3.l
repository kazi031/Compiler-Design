%option noyywrap

%{
#include <stdio.h>
int word_count = 0;
int line_num = 0;
%}

nl			[\n]
delim		[ \t]
digit		[0-9]
letter		[A-Za-z\_]
id			{letter}+({digit}|{letter})*
assignment	[=]
assignop	{assignment}
arithmaticop	[+\-*/%]
logical		[&|!]
logicalop	({logical}{logical})|({logical})
relational	[!=<>]
relop		({relational}{relational})|({relational})
paren		[()]
curly		[{}]
inc			[+]
dec			[-]
increment	{inc}{inc}
decrement	{dec}{dec}
sign		({inc}{dec})
point		[.]
exp			[e]
number		{sign}*(({digit}+)|({digit}+{point}{digit}+)|({digit}+{point}{exp}{sign}{digit}+)|({digit}+{point}{exp}{digit}+))
col 		[:]
colon 		{col}
semcol		[;]
semicolon	{semcol}
com			[,]
comma		{com}
newline		{nl}
quote		["]
stringliteral {quote}+({digit}|{letter}|{delim})*{quote}+

%%
if			{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
else		{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
else" "if 	{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
switch		{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
case		{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
while		{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
for			{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
int			{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
break		{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
default		{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
main		{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
printf		{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
scanf		{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
exit   		{return 1;}
{number}	{printf("<NUMBER, %s> Line Num = %d\n", yytext, line_num);}
{assignop}  {printf("<ASSIGNOP, %s> Line Num = %d\n", yytext, line_num);}
{logicalop} {printf("<LOGICALOP, %s> Line Num = %d\n", yytext, line_num);}
{arithmaticop} {printf("<ARITHMATIC, %s> Line Num = %d\n", yytext, line_num);}
{relop} 	{printf("<RELOP, %s> Line Num = %d\n", yytext, line_num);}
{id}		{printf("<ID, %s> Line Num = %d\n", yytext, line_num); word_count++;}
{paren}		{printf("<PAREN, %s> Line Num = %d\n", yytext, line_num);}
{curly}		{printf("<CURL, %s> Line Num = %d\n", yytext, line_num);}
{increment}	{printf("<INC, %s> Line Num = %d\n", yytext, line_num);}
{decrement}	{printf("<DEC, %s> Line Num = %d\n", yytext, line_num);}
{colon}		{printf("<COLON, %s> Line Num = %d\n", yytext, line_num);}
{semicolon}	{printf("<SEMICOLON, %s> Line Num = %d\n", yytext, line_num);}
{comma}		{printf("<COMMA, %s> Line Num = %d\n", yytext, line_num);}
[/]{1}[/]{1}[a-zA-Z0-9]* {}
{newline} 	{line_num++;printf("\n\n\n");}
{stringliteral} {printf("<STRINGLITERAL, %s> Line Num = %d\n", yytext, line_num);}
{delim}+ 	{}
%%

int main(){


yylex();

fclose(yyin);
}