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

%type <no> NUM ID program slist stmt inputStmt outputStmt assignStmt expr ifStmt whileStmt doWhileStmt repeatUntilStmt
%token NUM PLUS MINUS MUL DIV END BEG READ WRITE ID SEMICOLON ASSIGN
%token LT GT LE GE NE ET
%token IF THEN ELSE ENDIF 
%token WHILE ENDWHILE DO BREAK CONTINUE
%token REPEAT UNTIL

%left LT GT LE GE NE ET  
%left PLUS MINUS 
%left MUL DIV
 
%%

program : BEG slist END SEMICOLON{
        $$ = $2;

        helperFunction($2);
        // printPrefix($2);
        // evaluate($2);
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
  | doWhileStmt {$$ = $1;}
  | repeatUntilStmt {$$ = $1;}
  | BREAK SEMICOLON {$$ = createTree(noNumber,noType,NULL,breakNode,NULL,NULL,NULL);}
  | CONTINUE SEMICOLON {$$ = createTree(noNumber,noType,NULL,continueNode,NULL,NULL,NULL);}
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

whileStmt : WHILE '(' expr ')' DO slist ENDWHILE SEMICOLON  {$$ = createTree(noNumber,noType,NULL,whileNode,$6,NULL,$3);}
  ;

doWhileStmt : DO slist WHILE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,noType,NULL,doWhileNode,$2,NULL,$5);}

repeatUntilStmt : REPEAT slist UNTIL '(' expr ')' SEMICOLON {$$ = createTree(noNumber,noType,NULL,repeatUntilNode,$2,NULL,$5);}

expr : expr LT expr {$$ = createTree(noNumber,boolType,NULL,lessNode,$1,$3,NULL);}
  | expr GT expr {$$ = createTree(noNumber,boolType,NULL,greaterNode,$1,$3,NULL);}
  | expr LE expr {$$ = createTree(noNumber,boolType,NULL,lessEqualNode,$1,$3,NULL);}
  | expr GE expr {$$ = createTree(noNumber,boolType,NULL,greaterEqualNode,$1,$3,NULL);}
  | expr NE expr {$$ = createTree(noNumber,boolType,NULL,notEqualNode,$1,$3,NULL);}
  | expr ET expr {$$ = createTree(noNumber,boolType,NULL,equalNode,$1,$3,NULL);}

%%

yyerror(char const *s){
    printf("yyerror : %s\n",s);
    printf("The last pattern matched was %s\n",yytext);
    exit(0);
}



/*
begin
read(a);
read(b);
read(c);
if (a > b) then
    if ( a > c) then
        d = a;
    else
        d = c;
    endif;
else
    if (b > c) then
        d = b;
    else
        d = c;
    endif;
endif;
while ( d  < 10) do
    d = d + 1;
endwhile;
write(d);
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