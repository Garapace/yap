%{
#include <stdio.h>
#include "y.tab.h"
void Errors();
%}

%option noyywrap
%%
[0-9]+(\.[0-9]+)? { yylval.number = atof(yytext); return NUMBER; }
[-+*/(){}] { return yytext[0]; }
\n { return EOL; }
[ \t] { /* ignore whitespace */ }
. { Errors(); }
%%
void Errors(){
printf("NADA PISAT CHEREZ POINT'?");
}