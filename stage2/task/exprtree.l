%{
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
#include "exprtree.h"

int number;
 
%}

%%

[0-9]+      {number = atoi(yytext); yylval.no = createTree(number,noType,NULL,valNode,NULL,NULL); return NUM;}
[a-z]       {yylval.no = createTree(noNumber,intType,strdup(yytext),idNode,NULL,NULL); return ID;}
"+"         {return PLUS;} 
"-"         {return MINUS;}  
"*"         {return MUL;}
"/"         {return DIV;}
";"         {return SEMICOLON;}
"="         {return ASSIGN;}    
"begin"     {return BEG;}
"end"       {return END;}
"read"      {return READ;}
"write"     {return WRITE;}   
[\n \t]     {}
[()]        {return *yytext;}
.           {yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
    return 1;
}