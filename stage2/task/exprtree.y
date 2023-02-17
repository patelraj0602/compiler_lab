%{

#include <stdlib.h>
#include <stdio.h>
#include "exprtree.h"
#include "exprtree.c"
#include "registers.h"
#include "codegen.c"
int yylex(void);
extern FILE* yyin; 
extern char* yytext;
%}

%union{
    struct tnode *no; 
} 

%type <no> NUM ID program slist stmt inputStmt outputStmt assignStmt expr
%token NUM PLUS MINUS MUL DIV END BEG READ WRITE ID SEMICOLON ASSIGN
%left PLUS MINUS
%left MUL DIV
 
%%

program : BEG slist END SEMICOLON{
        $$ = $2;

        // printPrefix($2);
        helperFunction($2);
   }
  | BEG END SEMICOLON {exit(1);}
  ;

slist : slist stmt {$$ = createTree(noNumber,noType,NULL,emptyNode,$1,$2);}
  | stmt {$$ = $1;}
  ;

stmt : inputStmt {$$ = $1;}
  | outputStmt {$$ = $1;}
  | assignStmt {$$ = $1;}
  ;

inputStmt : READ '(' ID ')' SEMICOLON {$$ = createTree(noNumber,noType,NULL,readNode,$3,NULL);}
  ;

outputStmt : WRITE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,noType,NULL,writeNode,$3,NULL);}
  ;

assignStmt : ID ASSIGN expr SEMICOLON {$$ = createTree(noNumber,noType,NULL,assignNode,$1,$3);}
  ;

expr : expr PLUS expr  {$$ = createTree(noNumber,noType,NULL,addNode,$1,$3);}
  | expr MINUS expr   {$$ = createTree(noNumber,noType,NULL,subNode,$1,$3);}
  | expr MUL expr {$$ = createTree(noNumber,noType,NULL,mulNode,$1,$3);}
  | expr DIV expr {$$ = createTree(noNumber,noType,NULL,divNode,$1,$3);}
  | '(' expr ')' {$$ = $2;}
  | NUM {$$ = $1;}
  | ID {$$ = $1;}
  ;

%%

yyerror(char const *s){
    printf("yyerror : %s\n",yytext);
    exit(0);
}



/*
PROBLEM: TARGET LANGUAGE
begin
    read (a);
    read (b);
    d = a + 2 * b;
    write (a+d);
end;
*/

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