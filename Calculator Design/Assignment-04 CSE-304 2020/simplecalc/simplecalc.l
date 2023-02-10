%option noyywrap


%{

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "simplecalc.tab.h"


%}



WS [ \t]+

DIGIT [0-9]

NUMBER {DIGIT}+(\.{DIGIT}+)?


%%


{NUMBER}  {
 sscanf(yytext,"%lf", &yylval); return NUMBER; }


"+"  { return PLUS; }

"-"   { return MINUS; }

"/"   { return SLASH; }

"*"   { return ASTERISK; }

"("   { return LPAREN; }

")"   { return RPAREN; }

"\n"  { return NEWLINE; }

"%" {return MOD;}

"**" {return DOUBLEASTERISK;}

"++" {return INC;}

"--" {return DEC;}

"<<" {return LEFTSHIFT;}

">>" {return RIGHTSHIFT;}

{WS} { /* No action and no return */}

%%
void file_inp(){
	yyin=fopen("input.txt","r");
	fclose(yyin);
}

