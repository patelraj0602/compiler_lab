%{

#include <stdio.h>
#include <stdlib.h>

%}

%union{
    char c;
    int i;
}

%token CHARACTER NEWLINE
%type <c> CHARACTER
%type <i> NEWLINE

%left '+'
%left '*'

%%
start : expr NEWLINE  {printf("\nComplete\n");exit(1);}
 ;

expr:  expr '+' expr  {printf("+ ");}
 | expr '*' expr  {printf("* ");}
 | '(' expr ')'
 | CHARACTER   {printf("%c ",$1);}
 ;

%%

void yyerror(char const* s)
{
 printf("yyerror %s\n",s);
 return;
}

main()
{
 yyparse();
 return 1;
}