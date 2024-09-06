%{
    #include <stdio.h>
    #include "y.tab.h"
%}

%%
[0-9]+              {yylval=atoi(yytext);return NUMBER;}
"+"                 return *yytext;
"-"                 return *yytext;
"="                 return *yytext;
.                   {};
%%

int yywrap()
{
    return 1;
}