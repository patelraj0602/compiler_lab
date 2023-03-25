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
"main"                  {return MAIN;}
"return"                {return RETURN;}
"type"                  {return TYPE;}
"endtype"               {return ENDTYPE;}
"alloc"                 {return ALLOC;} 
"initialize"            {return INITIALIZE;}
"free"                  {return FREE;}
"null"                  {return NULL_PTR;}
"int"                   {yylval.str = strdup(yytext); return INT;}
"str"                   {yylval.str = strdup(yytext); return STR;} 
[a-zA-Z][a-zA-Z0-9]*    {yylval.str = strdup(yytext); return ID;} 
[0-9]+                  {
                            number = atoi(yytext); 
                            yylval.no = createTree(number,tLookup("int"),NULL,valNode,NULL,NULL,NULL,NULL,NULL,NULL); 
                            return NUM;
                        }
["]([^"\n]|\\(.|\n))*["] {
                            char* temp = malloc(yyleng -1);
                            memcpy(temp, yytext + 1, yyleng - 2);
                            temp[yyleng - 2] = 0; 
                            yylval.no = createTree(noNumber,tLookup("str"),temp,strNode,NULL,NULL,NULL,NULL,NULL,NULL);
                            return STRING; 
                        } 
"+"                     {return PLUS;}  
"-"                     {return MINUS;}  
"*"                     {return STAR;} 
"/"                     {return DIV;} 
"&"                     {return ADDR;}
";"                     {return SEMICOLON;} 
"="                     {return ASSIGN;} 
"<"                     {return LT;}
"<="                    {return LE;}
">"                     {return GT;}
">="                    {return GE;}
"!="                    {return NE;}
"=="                    {return ET;}
"&&"                    {return AND;}
"||"                    {return OR;}       
[ \t]                   {}
[(){}]                  {return *yytext;}
[\[\]]                  {return *yytext;}
[,]                     {return *yytext;}
"."                     {return *yytext;}
[\n]                    {}
.                       {yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) { 
    return 1;
}