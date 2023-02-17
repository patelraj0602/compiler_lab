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
  int num;
  char* str;
  struct tnode *no; 
  struct gsymbol *gnode; 
} 

%type <no> identifier NUM STRING program slist stmt inputStmt outputStmt assignStmt expr ifStmt whileStmt doWhileStmt repeatUntilStmt 
%type <gnode> declarations declList decl varList
%type <num> type
%type <str> ID idDecl

%token NUM ID STRING
%token END BEG
%token READ WRITE
%token SEMICOLON ASSIGN
%token PLUS MINUS MUL DIV 
%token LT GT LE GE NE ET
%token IF THEN ELSE ENDIF 
%token WHILE ENDWHILE DO BREAK CONTINUE
%token REPEAT UNTIL
%token INT STR
%token DECL ENDDECL

%left LT GT LE GE NE ET 
%left PLUS MINUS 
%left MUL DIV
 
%%

program : declarations BEG slist END SEMICOLON{
        printf("success\n");
        // $$ = $2;
        helperFunction($3);
        printPrefix($3);
        // evaluate($2);
   }
  | declarations BEG END SEMICOLON {exit(1);}
  | declarations {printf("Working ggod\n");}
  ;


declarations : DECL declList ENDDECL {
      struct gsymbol* top = gst->top;
      while(top){
        top->binding = (gst->binding);
        gst->binding += top->size;
        top = top->next;
      }
      printGlobalSymbolTable();
    } 
  | DECL ENDDECL {}
  ;

declList : declList decl {}
  | decl {}
  ;

decl : type varList SEMICOLON {
    struct gsymbol* top = gst->top;
    while((top)&&(top->type == -1)){
      top->type = $1;
      top=top->next;
    }
  }
  ;

type : INT  {$$ = intType;}
  | STR {$$ = strType;}
  ;

varList : varList ',' idDecl {install($3,-1,1,0);}
  | varList ',' idDecl '[' NUM ']' {install($3,-1,$5->val,0);}
  | varList ',' idDecl '[' NUM ']' '[' NUM ']' {
      int val1 =  ($5->val); int val2 = ($8->val);
      int size = val1*val2;
      install($3,-1,size,$8->val);
    }
  | idDecl {install($1,-1,1,0);}
  | idDecl '[' NUM ']' {install($1,-1,$3->val,0);}
  | idDecl '[' NUM ']' '[' NUM ']' {
      int val1 =  ($3->val); int val2 = ($6->val);
      int size = val1*val2;
      install($1,-1,size,$6->val);
    }
  ;

idDecl : ID {
      $$ = $1;
    }
  ;




slist : slist stmt {$$ = createTree(noNumber,noType,NULL,emptyNode,$1,$2,NULL,NULL);}
  | stmt {$$ = $1;}
  ;

stmt : inputStmt {$$ = $1;}
  | outputStmt {$$ = $1;}
  | assignStmt {$$ = $1;}
  | ifStmt {$$ = $1;}
  | whileStmt {$$ = $1;}
  | doWhileStmt {$$ = $1;}
  | repeatUntilStmt {$$ = $1;}
  | BREAK SEMICOLON {$$ = createTree(noNumber,noType,NULL,breakNode,NULL,NULL,NULL,NULL);}
  | CONTINUE SEMICOLON {$$ = createTree(noNumber,noType,NULL,continueNode,NULL,NULL,NULL,NULL);}
  ;

inputStmt : READ '(' identifier ')' SEMICOLON {$$ = createTree(noNumber,noType,NULL,readNode,$3,NULL,NULL,NULL);}
  ;

outputStmt : WRITE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,noType,NULL,writeNode,$3,NULL,NULL,NULL);}
  ;

assignStmt : identifier ASSIGN expr SEMICOLON {$$ = createTree(noNumber,noType,NULL,assignNode,$1,$3,NULL,NULL);}
  ;

ifStmt : IF '(' expr ')' THEN slist ELSE slist ENDIF SEMICOLON {$$ = createTree(noNumber,noType,NULL,ifElseNode,$6,$8,$3,NULL);}
  | IF '(' expr ')' THEN slist ENDIF SEMICOLON {$$ = createTree(noNumber,noType,NULL,ifElseNode,$6,NULL,$3,NULL);}
  ;

whileStmt : WHILE '(' expr ')' DO slist ENDWHILE SEMICOLON  {$$ = createTree(noNumber,noType,NULL,whileNode,$6,NULL,$3,NULL);}
  ;

doWhileStmt : DO slist WHILE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,noType,NULL,doWhileNode,$2,NULL,$5,NULL);}
  ;

repeatUntilStmt : REPEAT slist UNTIL '(' expr ')' SEMICOLON {$$ = createTree(noNumber,noType,NULL,repeatUntilNode,$2,NULL,$5,NULL);}
  ;

expr : expr PLUS expr  {$$ = createTree(noNumber,intType,NULL,addNode,$1,$3,NULL,NULL);}
  | expr MINUS expr   {$$ = createTree(noNumber,intType,NULL,subNode,$1,$3,NULL,NULL);}
  | expr MUL expr {$$ = createTree(noNumber,intType,NULL,mulNode,$1,$3,NULL,NULL);}
  | expr DIV expr {$$ = createTree(noNumber,intType,NULL,divNode,$1,$3,NULL,NULL);}
  | expr LT expr {$$ = createTree(noNumber,boolType,NULL,lessNode,$1,$3,NULL,NULL);}
  | expr GT expr {$$ = createTree(noNumber,boolType,NULL,greaterNode,$1,$3,NULL,NULL);}
  | expr LE expr {$$ = createTree(noNumber,boolType,NULL,lessEqualNode,$1,$3,NULL,NULL);}
  | expr GE expr {$$ = createTree(noNumber,boolType,NULL,greaterEqualNode,$1,$3,NULL,NULL);}
  | expr NE expr {$$ = createTree(noNumber,boolType,NULL,notEqualNode,$1,$3,NULL,NULL);}
  | expr ET expr {$$ = createTree(noNumber,boolType,NULL,equalNode,$1,$3,NULL,NULL);}
  | '(' expr ')' {$$ = $2;}
  | NUM {$$ = $1;}
  | identifier {$$ = $1;}
  | STRING {$$ = $1;}
  ;

identifier : ID {
        /* Make node for this */ 
        struct gsymbol* temp = lookup($1);
        if(temp == NULL) yyerror("Identifier not found in global symbol table!!\n");

        if(temp->type == intType)
          $$ = createTree(noNumber,intType,$1,idNode,NULL,NULL,NULL,temp);
        else if(temp->type == strType)
           $$ = createTree(noNumber,strType,$1,idNode,NULL,NULL,NULL,temp);
        else yyerror("No matching variable type!!\n");
    }

  | ID '[' expr ']' {
      struct gsymbol* temp = lookup($1);
        if(temp == NULL) yyerror("Identifier not found in global symbol table!!\n");

        if(temp->type == intType)
          $$ = createTree(noNumber,intType,$1,idNode,$3,NULL,NULL,temp);
        else if(temp->type == strType)
           $$ = createTree(noNumber,strType,$1,idNode,$3,NULL,NULL,temp);
        else yyerror("No matching variable type!!\n");
    }

  | ID '[' expr ']' '[' expr ']' {
      struct gsymbol* temp = lookup($1);
        if(temp == NULL) yyerror("Identifier not found in global symbol table!!\n");

        if(temp->type == intType)
          $$ = createTree(noNumber,intType,$1,idNode,$3,$6,NULL,temp);
        else if(temp->type == strType)
           $$ = createTree(noNumber,strType,$1,idNode,$3,$6,NULL,temp);
        else yyerror("No matching variable type!!\n");
    }
  ;

%%

yyerror(char const *s){
    printf("yyerror : %s\n",s);
    printf("Last pattern matched by lex : %s.\n",yytext);
    exit(0);
}



/*
Task1+Task2 Completed
*/
int main(int argc, char* argv[]) {

    FILE* filePointer;
    if(argc > 1){
        filePointer = fopen(argv[1], "r");
        if(filePointer) yyin = filePointer;
    }

    // Initializing the pointer to the top of global symbol table to null
    gst = (struct globalSymbolTable*) malloc(sizeof(struct globalSymbolTable));
    gst->top = NULL;
    gst->binding = 4096;

    yyparse();
    fclose(filePointer);
    return 0;
}