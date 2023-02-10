%option noyywrap
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "threeAdd.tab.h"

void yyerror(char*);
extern YYSTYPE yylval;
%}
NAME	[a-zA-Z]
DIGITS  [0-9]+
DOUBLE	{DIGITS}(\.{DIGITS})?
WS      [ \t]+
%%
[ \t]+ 	 { }
{DOUBLE} {
			strcpy(yylval.ivar,yytext);
			return DOUBLE;
		 }
[-+*/=%]  {
		    return *yytext;
	     }
"(" 	 {
			return *yytext;
		 }
")" 	 {
			return *yytext;
		 }
{NAME} 	 {
			// Write your code here.
			strcpy(yylval.ivar,yytext);
			return NAME;
		 }
\n 	     {
			return *yytext;
		 }
"++" {return INC;}

"--" {return DEC;}

"<<" {return LEFTSHIFT;}

">>"   {return RIGHTSHIFT;}
"**"   {return DOUBLEASTERISK;}
"+{WS}-" {return PM;}
"-{WS}+"  {return MP;}
"-{WS}-"  {return MM;}
"+{WS}+"  {return PP;}
exit     {
			return 0;
		 }
.        {
			char msg[25];
			sprintf(msg," <%s>","invalid character",yytext);
			yyerror(msg);
		 }
%%