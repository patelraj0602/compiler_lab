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

%type <no> NUM ID program slist stmt inputStmt outputStmt assignStmt expr ifStmt whileStmt
%token NUM PLUS MINUS MUL DIV END BEG READ WRITE ID SEMICOLON ASSIGN 
%token LT GT LE GE NE ET
%token IF THEN ELSE ENDIF WHILE ENDWHILE DO

%left LT GT LE GE NE ET
%left PLUS MINUS 
%left MUL DIV
 
%%

program : BEG slist END SEMICOLON{
        $$ = $2;

        // printPrefix($2);
        // evaluate($2);
        helperFunction($2);
   }
  | BEG END SEMICOLON {exit(1);}
  ;

slist : slist stmt {$$ = createTree(noNumber,noType,NULL,emptyNode,$1,$2,NULL);} 
  | stmt {$$ = $1;}
  ;

stmt : inputStmt {$$ = $1;}
  | outputStmt {$$ = $1;}
  | assignStmt {$$ = $1;}
  | ifStmt {$$ = $1;}
  | whileStmt {$$ = $1;}
  ;

inputStmt : READ '(' ID ')' SEMICOLON {$$ = createTree(noNumber,noType,NULL,readNode,$3,NULL,NULL);}
  ;

outputStmt : WRITE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,noType,NULL,writeNode,$3,NULL,NULL);}
  ;

assignStmt : ID ASSIGN expr SEMICOLON {$$ = createTree(noNumber,noType,NULL,assignNode,$1,$3,NULL);}
  ;

expr : expr PLUS expr  {$$ = createTree(noNumber,intType,NULL,addNode,$1,$3,NULL);}
  | expr MINUS expr   {$$ = createTree(noNumber,intType,NULL,subNode,$1,$3,NULL);}
  | expr MUL expr {$$ = createTree(noNumber,intType,NULL,mulNode,$1,$3,NULL);}
  | expr DIV expr {$$ = createTree(noNumber,intType,NULL,divNode,$1,$3,NULL);}
  | '(' expr ')' {printf("fck");$$ = $2;}
  | NUM {$$ = $1;}
  | ID {$$ = $1;}
  ;

ifStmt : IF '(' expr ')' THEN slist ELSE slist ENDIF SEMICOLON {$$ = createTree(noNumber,noType,NULL,ifElseNode,$6,$8,$3);}
  | IF '(' expr ')' THEN slist ENDIF SEMICOLON {$$ = createTree(noNumber,noType,NULL,ifElseNode,$6,NULL,$3);}
  ;

whileStmt : WHILE '(' expr ')' DO slist ENDWHILE SEMICOLON  {}
  ;

expr : expr LT expr {$$ = createTree(noNumber,boolType,NULL,lessNode,$1,$3,NULL);}
  | expr GT expr {$$ = createTree(noNumber,boolType,NULL,greaterNode,$1,$3,NULL);}
  | expr LE expr {$$ = createTree(noNumber,boolType,NULL,lessEqualNode,$1,$3,NULL);}
  | expr GE expr {$$ = createTree(noNumber,boolType,NULL,greaterEqualNode,$1,$3,NULL);}
  | expr NE expr {$$ = createTree(noNumber,boolType,NULL,notEqualNode,$1,$3,NULL);}
  | expr ET expr {$$ = createTree(noNumber,boolType,NULL,equalNode,$1,$3,NULL);}

%%

yyerror(char const *s){
    printf("yyerror : %s\n",yytext);
    exit(0);
}



/*
PROBLEM: TARGET LANGUAGE
begin
    read(a);
    read(b);
    read(c);
    if (a < b) then
      if (b < c) then Write(c); else Write(b); endif;
    else
      if (a < c) then Write(c); else Write(a); endif;
    endif;
end;

Issuees:
1) how to preven if(a+b)
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