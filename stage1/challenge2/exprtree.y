%{
#include <stdlib.h>
#include <stdio.h>
#include "exprtree.h"
#include "exprtree.c"
#include "registers.h"
#include "codegen.c"
int yylex(void);
extern FILE* yyin;
%}

%union{
 struct tnode *no;
 
}
%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV
 
%%

program : expr END {
    $$ = $2;
    printf("Answer : %d\n",evaluate($1));
    helperFunction($1);
    exit(1);
   }
  ;

expr : expr PLUS expr  {$$ = makeOperatorNode('+',$1,$3);}
  | expr MINUS expr   {$$ = makeOperatorNode('-',$1,$3);}
  | expr MUL expr {$$ = makeOperatorNode('*',$1,$3);}
  | expr DIV expr {$$ = makeOperatorNode('/',$1,$3);}
  | '(' expr ')'  {$$ = $2;}
  | NUM   {$$ = $1;}
  ;

%%

yyerror(char const *s){
    printf("yyerror : %s\n",s);
    exit(0);
}


int main(int argc, char* argv[]) {

    FILE* filePointer;
    if(argc > 1){
        filePointer = fopen(argv[1], "r");
        if(filePointer) yyin = filePointer;
    }

    yyparse();
    fclose(filePointer);
    return 0;
}