%{
/* 
Do Infix to postfix conversion where lexemes are either operators or single characters instead of numbers.
Sample input: a+b*c
Sample output: abc*+
*/    
#include <stdio.h>
#include "y.tab.h"
%}

%%

[a-z A-Z]+ {
        // yytext is expected to contain a character. 
        yylval.s = yytext;
        return STRING;
    }

[-|+|*|/] {
    yylval.c = *yytext;
    return OP;
}
[()]    return *yytext;
[\n]    return NEWLINE;

%%

yywrap()
{
 return 1;
}