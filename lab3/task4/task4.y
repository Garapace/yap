%code requires
    {
        #define YYSTYPE double
    }
%{
    #include <stdio.h>
%}

%token INTEGER FLOAT
%token PLUS MINUS MULTIPLY DEVIDE

%left PLUS MINUS
%left MULTIPLY DEVIDE

%%
exp:  number            {}
    | '(' exp ')'       {}
    | exp PLUS exp      {printf("+ ", $1);}
    | exp MINUS exp     {printf("- ", $1);}
    | exp MULTIPLY exp  {printf("* ", $1);}
    | exp DEVIDE exp    {printf("/ ", $1);}
    ;

number: INTEGER         {printf("%d ", $1);}
    |   FLOAT           {printf("%f ", $1);}
    ;
%%

  
int main()
{
        yyparse();
        return 1;
} 

void yyerror(const char *str)
{
        printf("Oшибка: %s\n",str);
        return 1;
} 