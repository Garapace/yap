%{
    #include <stdio.h>
%}

%token NUMBER

%%
start:exp '=' {printf("Answer = %d", $1);};

exp:  NUMBER         {$$ = $1;}
    | exp '+' exp    {$$ = $1 + $3;}
    | exp '-' exp    {$$ = $1 - $3;}
    ;
%%

  
int main()
{
        printf("Enter expression: ");
        yyparse();
        return 0;
} 

void yyerror(const char *str)
{
        printf("Oшибка: %s\n",str);
        return 1;
} 