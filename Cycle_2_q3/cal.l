%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
%}

%%

[0-9]+ {
    yylval = atoi(yytext);
    return NUMBER;
}

[\t] ;  // Ignore tabs
[\n] return '\n';  // Handle newline
. return yytext[0];  // Return all other characters

%%

int yywrap() {
    return 1;
}

