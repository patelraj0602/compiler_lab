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
%type <num> type varList
%type <str> ID

%token NUM ID STRING
%token END BEG
%token READ WRITE
%token SEMICOLON ASSIGN
%token PLUS MINUS STAR DIV 
%token LT GT LE GE NE ET
%token IF THEN ELSE ENDIF 
%token WHILE ENDWHILE DO BREAK CONTINUE
%token REPEAT UNTIL
%token INT STR
%token DECL ENDDECL
%token ADDR

%left LT GT LE GE NE ET 
%left PLUS MINUS 
%left STAR DIV
%left ADDR
 
%%

program : declarations BEG slist END SEMICOLON{
        printf("success\n");
        // $$ = $2;
        // printPrefix($3);
        helperFunction($3);
        // evaluate($2);
   }
  | declarations BEG END SEMICOLON {exit(1);}
  | declarations {printf("Working ggod\n");}
  ;


// Static variables declarations
declarations : DECL declList ENDDECL {
      struct gsymbol* top = gst->top;
      while(top){
        top->binding = (gst->binding);
        gst->binding += top->size;
        top = top->next;
      }
      printGlobalSymbolTable();
    } 
  | DECL ENDDECL
  ;

declList : declList decl
  | decl 
  ;

decl : type varList SEMICOLON
  ;

type : INT  {$$ = intType;}
  | STR {$$ = strType;}
  ;

// Add STAR ID in below production rules.
varList : varList ',' ID {install($3,$<num>0,0,0);}
  | varList ',' ID '[' NUM ']' {install($3,$<num>0,$5->val,0);}
  | varList ',' ID '[' NUM ']' '[' NUM ']' {install($3,$<num>0,$5->val,$8->val);}
  | varList ',' STAR ID {
      if($<num>0 == intType) install($4,intPtrType,0,0);
      else install($4,strPtrType,0,0);
    }

  | ID {install($1,$<num>0,0,0);}
  | ID '[' NUM ']' {install($1,$<num>0,$3->val,0);}
  | ID '[' NUM ']' '[' NUM ']' {install($1,$<num>0,$3->val,$6->val);}
  | STAR ID {
      if($<num>0 == intType) install($2,intPtrType,0,0);
      else install($2,strPtrType,0,0);
    }
  ;

// Main Program
slist : slist stmt {$$ = createTree(noNumber,voidType,NULL,emptyNode,$1,$2,NULL,NULL);}
  | stmt {$$ = $1;}
  ;

stmt : inputStmt {$$ = $1;}
  | outputStmt {$$ = $1;}
  | assignStmt {$$ = $1;}
  | ifStmt {$$ = $1;}
  | whileStmt {$$ = $1;}
  | doWhileStmt {$$ = $1;}
  | repeatUntilStmt {$$ = $1;}
  | BREAK SEMICOLON {$$ = createTree(noNumber,voidType,NULL,breakNode,NULL,NULL,NULL,NULL);}
  | CONTINUE SEMICOLON {$$ = createTree(noNumber,voidType,NULL,continueNode,NULL,NULL,NULL,NULL);}
  ;

inputStmt : READ '(' identifier ')' SEMICOLON {$$ = createTree(noNumber,voidType,NULL,readNode,$3,NULL,NULL,NULL);}
  ;

outputStmt : WRITE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,voidType,NULL,writeNode,$3,NULL,NULL,NULL);}
  ;

assignStmt : identifier ASSIGN expr SEMICOLON {$$ = createTree(noNumber,voidType,NULL,assignNode,$1,$3,NULL,NULL);}
  | identifier ASSIGN ADDR identifier SEMICOLON {
      struct tnode* newAddrNode = createAddrNode($4);
      $$ = createTree(noNumber,voidType,NULL,assignNode,$1,newAddrNode,NULL,NULL);
    }
  ;

ifStmt : IF '(' expr ')' THEN slist ELSE slist ENDIF SEMICOLON {$$ = createTree(noNumber,voidType,NULL,ifElseNode,$6,$8,$3,NULL);}
  | IF '(' expr ')' THEN slist ENDIF SEMICOLON {$$ = createTree(noNumber,voidType,NULL,ifElseNode,$6,NULL,$3,NULL);}
  ;

whileStmt : WHILE '(' expr ')' DO slist ENDWHILE SEMICOLON  {$$ = createTree(noNumber,voidType,NULL,whileNode,$6,NULL,$3,NULL);}
  ;

doWhileStmt : DO slist WHILE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,voidType,NULL,doWhileNode,$2,NULL,$5,NULL);}
  ;

repeatUntilStmt : REPEAT slist UNTIL '(' expr ')' SEMICOLON {$$ = createTree(noNumber,voidType,NULL,repeatUntilNode,$2,NULL,$5,NULL);}
  ;

expr : expr PLUS expr  {$$ = createTree(noNumber,intType,NULL,addNode,$1,$3,NULL,NULL);}
  | expr MINUS expr   {$$ = createTree(noNumber,intType,NULL,subNode,$1,$3,NULL,NULL);}
  | expr STAR expr {$$ = createTree(noNumber,intType,NULL,mulNode,$1,$3,NULL,NULL);}
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


// Add STAR ID in this later.
identifier : ID {
        /* Make node for this */ 
        struct gsymbol* gTableEntry = lookup($1);
        if(gTableEntry == NULL) yyerror("Identifier not found in global symbol table!!\n");
        $$ = createTree(noNumber,gTableEntry->type,$1,idNode,NULL,NULL,NULL,gTableEntry); 
    }

  | ID '[' expr ']' {
        struct gsymbol* gTableEntry = lookup($1);
        if(gTableEntry == NULL) yyerror("Identifier not found in global symbol table!!\n");
        $$ = createTree(noNumber,gTableEntry->type,$1,idNode,$3,NULL,NULL,gTableEntry);
    }

  | ID '[' expr ']' '[' expr ']' {
        struct gsymbol* gTableEntry = lookup($1);
        if(gTableEntry == NULL) yyerror("Identifier not found in global symbol table!!\n");
        $$ = createTree(noNumber,gTableEntry->type,$1,idNode,$3,$6,NULL,gTableEntry); 
    }
  
  | STAR ID {
    struct gsymbol* gTableEntry = lookup($2);
    if(gTableEntry == NULL) yyerror("Identifier not found in global symbol table!!\n");

    struct tnode* newIdNode = createTree(noNumber,gTableEntry->type,$2,idNode,NULL,NULL,NULL,gTableEntry);
    $$ = createStarNode(newIdNode);
  }
  ;

%%

yyerror(char const *s){
    printf("yyerror : %s\n",s);
    printf("Last pattern matched by lex : %s.\n",yytext);
    exit(0);
}


int main(int argc, char* argv[]) {

    FILE* filePointer;
    if(argc > 1){
        filePointer = fopen(argv[1], "r");
        if(filePointer) yyin = filePointer;
    }

    // Initializing the pointer to the top of stack used for codegen part.
    tos = (struct topOfStack*)malloc(sizeof(struct topOfStack));
    tos->top = NULL;

    // Initializing the pointer to the top of global symbol table to null
    gst = (struct globalSymbolTable*) malloc(sizeof(struct globalSymbolTable));
    gst->top = NULL;
    gst->binding = 4096;

    yyparse();
    fclose(filePointer);
    return 0;
}