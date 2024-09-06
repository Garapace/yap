%{
#include <stdio.h>
%}

%%
[0-9]+  {printf("number");}
[a-zA-Zа-яА-Я]+ {printf("word");}
[\+\-\*\/]+ {printf("operator");}
[a-zA-Zа-яА-Я][a-zA-Zа-яА-Я0-9]* {printf("word with number");}
%%
int yywrap() {return 1;} 