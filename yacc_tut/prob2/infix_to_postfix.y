%{

#include <stdio.h>
#include <stdlib.h>

int yyerror();
%}

%union{
    char* s;
    char c;
    int i;
}

%token STRING NEWLINE OP
%type <s> STRING
%type <c> OP
%type <i> NEWLINE

%left '+' '-'
%left '*' '/'

%%
start : expr NEWLINE  {printf("\nComplete\n");exit(1);}
 ;

expr:  expr OP expr  {printf("%c ",$<c>2);}
 | '(' expr ')'
 | STRING   {printf("%s ",$1);}
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