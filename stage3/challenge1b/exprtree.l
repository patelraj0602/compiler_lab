%{
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
#include "exprtree.h"

int number;

%} 

%%

[0-9]+      {number = atoi(yytext); yylval.no = createTree(number,intType,NULL,valNode,NULL,NULL,NULL); return NUM;}
[a-z]       {yylval.no = createTree(noNumber,intType,strdup(yytext),idNode,NULL,NULL,NULL); return ID;}  
"+"         {return PLUS;}  
"-"         {return MINUS;}  
"*"         {return MUL;}
"/"         {return DIV;} 
";"         {return SEMICOLON;}
"="         {return ASSIGN;} 
"<"         {return LT;}
"<="        {return LE;}
">"         {return GT;}
">="        {return GE;}
"!="        {return NE;}
"=="        {return ET;}
"if"        {return IF;}
"else"      {return ELSE;}
"then"      {return THEN;}
"endif"     {return ENDIF;}
"while"     {return WHILE;}
"do"        {return DO;}
"endwhile"  {return ENDWHILE;}
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