%{
    #include<stdio.h>
    #include<stdlib.h>
    int flag = 0;
%}

%token NUMBER

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
ArithmeticExpression:
    E '\n' {
        printf("\nResult = %d\n", $1);
        return 0;
    }
    ;

E:
    E '+' E { $$ = $1 + $3; }
    | E '-' E { $$ = $1 - $3; }
    | E '*' E { $$ = $1 * $3; }
    | E '/' E {
        if ($3 == 0) {
            yyerror("Error: Division by zero");
            exit(1);
        }
        $$ = $1 / $3;
    }
    | E '%' E { $$ = $1 % $3; }
    | '(' E ')' { $$ = $2; }
    | NUMBER { $$ = $1; }
    ;

%%

int yyerror(char *s) {
    printf("\nEntered arithmetic expression is invalid.\n");
    flag = 1;
    return 0;
}

int main() {
    printf("\nEnter an arithmetic expression which can have addition, subtraction, multiplication, division, modulus, and round brackets:\n");
    yyparse();
    if (flag == 0)
        printf("\nEntered arithmetic expression is valid.\n\n");
    return 0;
}

