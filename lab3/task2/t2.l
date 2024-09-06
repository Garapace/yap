%{
#include <stdio.h>
#include <stdlib.h> 
char op = '+';
int num = 0, m = 0;
%}

%option main
%option yylineno

%%

[0-9]+      {
            int tm = atoi(yytext);// trans from char to int
            m=0;
            switch (op){
                case '+': num += tm; break;
                case '/': num /= tm; break; 
                case '-': num -= tm; break; 
                case '*': num *= tm; break; 
                
            }
            op=0;
            } 
            

[-*/+]      {
            if (op) {
                if (*yytext == '-') {
                    m = 1;
                } else {
                    fprintf(stderr, "Неизвестный оператор %d\n", yylineno);
                    exit(1);
                }
            } else {
                op = *yytext;
            }
            }

=        {
            if (op) {
                fprintf(stderr, "Unexpected semicolon in line %d\n", yylineno);
                exit(1);
            }
            printf("%d\n", num);
            num = 0;
            op = '+';
            }

%%