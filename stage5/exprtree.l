%{
#include <stdlib.h>
#include <stdio.h> 
#include "y.tab.h"
#include "exprtree.h"

int number;

%} 

%%

"decl"                  {return DECL;}
"enddecl"               {return ENDDECL;}
"int"                   {return INT;}
"str"                   {return STR;}
"if"                    {return IF;}
"else"                  {return ELSE;}
"then"                  {return THEN;}
"endif"                 {return ENDIF;}
"while"                 {return WHILE;}
"do"                    {return DO;}
"endwhile"              {return ENDWHILE;}
"continue"              {return CONTINUE;}
"break"                 {return BREAK;}
"begin"                 {return BEG;}
"end"                   {return END;}
"read"                  {return READ;}
"write"                 {return WRITE;}  
"repeat"                {return REPEAT;}
"until"                 {return UNTIL;}
[0-9]+                  {number = atoi(yytext); yylval.no = createTree(number,intType,NULL,valNode,NULL,NULL,NULL,NULL); return NUM;}
[a-zA-Z][a-zA-Z0-9]*    {yylval.str = strdup(yytext); return ID;} 
["]([^"\n]|\\(.|\n))*["] {
                            char* temp = malloc(yyleng -1);
                            memcpy(temp, yytext + 1, yyleng - 2);
                            temp[yyleng - 2] = 0; 
                            yylval.no = createTree(noNumber,strType,temp,strNode,NULL,NULL,NULL,NULL);
                            return STRING; 
                        } 
"+"                     {return PLUS;}  
"-"                     {return MINUS;}  
"*"                     {return MUL;} 
"/"                     {return DIV;} 
";"                     {return SEMICOLON;} 
"="                     {return ASSIGN;} 
"<"                     {return LT;}
"<="                    {return LE;}
">"                     {return GT;}
">="                    {return GE;}
"!="                    {return NE;}
"=="                    {return ET;}
[ \t]                   {}
[()]                    {return *yytext;}
[,]                     {return *yytext;}
[\[\]]                  {return *yytext;}
[\n]                    {}
.                       {yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) { 
    return 1;
}