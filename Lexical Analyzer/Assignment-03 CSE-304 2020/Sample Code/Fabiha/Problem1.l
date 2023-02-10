%option noyywrap

%{
#include <stdio.h>
int word_count = 0;
int line_num = 0;
%}

digit		[0-9]
letter		[A-Za-z\_]
assignment	[=]
assignop	{assignment}
arithmaticop	[+\-*/%]
logical		[&|!]
inc			[+]
dec			[-]
sign		({inc}{dec})
point		[.]
exp			[e]
number		{sign}*(({digit}+)|({digit}+{point}{digit}+)|({digit}+{point}{exp}{sign}{digit}+)|({digit}+{point}{exp}{digit}+))

%%
double			{printf("<KEYWORD, %s> Line Num = %d\n", yytext, line_num);}
exit   		{return 1;}
{number}	{printf("<NUMBER, %s> Line Num = %d\n", yytext, line_num);}
{assignop}  {printf("<ASSIGNOP, %s> Line Num = %d\n", yytext, line_num);}
{arithmaticop} {printf("<ARITHMATIC, %s> Line Num = %d\n", yytext, line_num);}
%%

int main(){


yylex();

fclose(yyin);
}