%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "exprtree.h" 
#include "exprtree.c"
#include "registers.h"
#include "codegen.c"
int yylex(void);
extern FILE* yyin; 
extern char* yytext;

// Global variables.
int binding = 4095;                                     // Always points to the top of stack    
int curType = undefined;                                // Stores the current type(int,str) of the variables
int fLabel = -1;                                        // Stores function label
    
%} 

%union{ 
  int num;
  char* str;
  struct tnode* no; 
  struct gsymbol* gnode;
  struct lsymbol* lnode;
  struct paramList* pl;
} 

%type <no> identifier NUM STRING sList stmt inputStmt outputStmt assignStmt expr ifStmt whileStmt doWhileStmt repeatUntilStmt 
%type <no> argList mainBlock fDefBlock fDef program
%type <pl> param paramList
%type <lnode> lId lIdList lDeclList lDecl
%type <num> type
%type <str> ID identifierDecl fName mainHeader

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
%token MAIN RETURN
%token AND OR

%left LT GT LE GE NE ET AND OR
%left PLUS MINUS 
%left STAR DIV
%left ADDR
 
%%

// New stuff

// GLOBAL DECLARATION BLOCK : For declaring variables and functions.
program : gDeclBlock fDefBlock mainBlock {
      printGlobalSymbolTable();
      printLocalSymbolTable();

      // Printing expression tree
      // printf("\nPrinting function def block\n");
      // printPrefix($2);
      // printf("\nPrinting mainblock\n");
      // printPrefix($3);

      {$$ = createTree(noNumber,voidType,NULL,emptyNode,$2,$3,NULL,NULL,NULL,NULL);}

      // Call codegen
      helperFunction($$);
    }
  | gDeclBlock mainBlock {
      printGlobalSymbolTable();
      printLocalSymbolTable();
      printf("\n");
      // printPrefix($2);
      $$ = createTree(noNumber,voidType,NULL,emptyNode,$2,NULL,NULL,NULL,NULL,NULL);  

      // Call codegen
      helperFunction($$);
    }
  | mainBlock {
      $$ = createTree(noNumber,voidType,NULL,emptyNode,$1,NULL,NULL,NULL,NULL,NULL);
      // Call codegen
      helperFunction($$);  
    }
  ;

gDeclBlock : DECL gDeclList ENDDECL {
      // Binding of variables   
      struct gsymbol* top = gst->top;
      while(top){
        if(top->flabel == -1){
          top->binding = binding+1;
          binding += top->size;
        }
        top = top->next;
      }
    }
  | DECL ENDDECL
  ;

gDeclList : gDeclList gDecl
  | gDecl
  ;


gDecl : type gidList SEMICOLON {
      // Adding type of variables for the entries in global symbol table
      struct gsymbol* top = gst->top;
      while(top){
        if(top->type == undefined){
          if(top->ispointer)  top->type = ($1 == intType) ? intPtrType : strPtrType;
          else  top->type = $1;
        }
        top = top->next;
      }
    }
  ;

gidList : gidList ',' gid
  | gid
  ;

// Return type of function can only be an variable identifier(int,str)..
gid : identifierDecl
  | ID '(' paramList ')' {
      // Making an entry in gst for function and also assigning label for that function.
      gInstall($1,undefined,0,0,0,$3);
      struct gsymbol* node = gLookup($1);
      node->flabel = ++fLabel;
    }
  | 
  ;

// Only pointers, variables and 1d-2d array supported by language
identifierDecl : STAR identifierDecl  {
      struct gsymbol* node = gLookup($2);
      node->ispointer = 1;
    }
  | ID  {gInstall($1,undefined,0,0,0,NULL); $$ = $1;}
  | ID '[' expr ']' {gInstall($1,undefined,0,$3->val,0,NULL); $$ = $1;}
  | ID '[' expr ']' '[' expr ']' {gInstall($1,undefined,0,$3->val,$6->val,NULL); $$ = $1;}
  ;

// FUNCTION INITIALIZATION ..
fDefBlock : fDefBlock fDef {$$ = createTree(noNumber,voidType,NULL,emptyNode,$1,$2,NULL,NULL,NULL,NULL);}
  | fDef {$$ = $1;}
  ;

fDef : fName '{' lDeclBlock BEG sList END '}' {$$ = createFunkNode($1,$5);}
    | fName '{' lDeclBlock BEG END '}' {$$ = NULL;}
  ;

// CHANGES TO MAKE => Variables names of paramList must be unique.
fName : type ID '(' paramList ')' {
      // Finding the function entry from global symbol table
      struct gsymbol* node = gLookup($2);

      // Compare the function declaration with initialization to ensure that both of them are equal
      if(!node) yyerror("Make sure to initialize the function %s\n",$2);
      if(node->type != $1) yyerror("Return type mismatch between initialization and declaration of function %s\n",$2);
      
      // spl -- Stored param list
      // npl -- New param list
      // Both of the list should exactly match
      struct paramList* spl = node->plist;
      struct paramList* npl = $4;
      while(spl || npl){
        if((!spl)||(!npl)) yyerror("No of parameter of declaration and initialization does not match");
        if((strcmp(spl->name,npl->name)!=0)||(spl->type != npl->type))
          yyerror("parameters mismatch between declaration and initialization");
        spl = spl->next;
        npl = npl->next;
      }

      // Adding this list of parameters to the local symbol table of this function.
      struct paramList* pl = $4;
        while(pl){
          struct lsymbol* temp = makeLSymbolNode(pl->name, pl->type, -1);
          temp->next = node->ltop;
          node->ltop = temp;
          pl = pl->next;
        }

      // Return function name
      $$ = $2;      
    }
  ;

paramList : paramList ',' param {$3->next = $1; $$ = $3;}
  | param {$$ = $1;}
  ;

// only variables and pointers can be passed as arguments not arrays.
param : type ID {$$ = makeParamNode($1,$2,0);}
  | type STAR ID  {$$ = makeParamNode($1,$3,1);}
  ;

type : INT {$$ = intType;}
  | STR {$$ = strType;}
  ;


// MAINBLOCK
mainBlock : mainHeader '{' lDeclBlock BEG sList END '}' {
      // Make an connector node and return that node
      $$ = createMainNode($1,$5);
    }
  | mainHeader '{' lDeclBlock BEG END '}' {}
  ;

mainHeader : INT MAIN '(' ')' {
      char* temp = malloc(5);
      memcpy(temp, "main\0", 5);

      gInstall(temp,intType,0,0,0,NULL);
      struct gsymbol* node = gLookup(temp);
      node->ltop = NULL;
      node->flabel = ++fLabel;

      $$ = temp;
    }
  ;

// Adding the parameter of the functions to local decl block and also setting the (local symbol table variable)
lDeclBlock : DECL lDeclList ENDDECL {
      char* funkName = $<str>-1;

      // Joining this local symbol table to the (ltop field of gsymbol)
      struct gsymbol* gnode = gLookup(funkName);
      struct lsymbol* top = $2;

      while(top->next) top=top->next;
      top->next = gnode->ltop;
      gnode->ltop = $2;

      // initializing lst value to current local symbol table for making an expression tree
      lst->top = $2;
      lst->name = funkName;
    }
  | DECL ENDDECL {
      char* funkName = $<str>-1;
      struct gsymbol* gnode = gLookup(funkName);

      // initializing lst value to current local symbol table for making an expression tree
      lst->top = gnode->ltop;
      lst->name = funkName;
    }
  ;

lDeclList : lDeclList lDecl {
      // Both lDeclList and lDecl contains the pointer to head of the linked list of lsymbol node
      struct lsymbol* l1 = $1;
      struct lsymbol* l2 = $2;

      // Get the last node of list2
      while(l2->next) l2 = l2->next;
      l2->next = l1;
      $$ = $2;
    }
  | lDecl {$$ = $1;}
  ;

lDecl : type lIdList SEMICOLON {
      struct lsymbol* top = $2;
      while(top){
        if(top->type == undefined){
          if(top->ispointer) top->type = ($1 == intType) ? intPtrType : strPtrType;
          else top->type = $1;
        }
        top = top->next;
      }
      $$ = $2;
    }
  ;

lIdList : lIdList ',' lId {$3->next = $1; $$ = $3;}
  | lId {$$ = $1;}
  ;

// only variables and pointers are allowed
lId : ID {$$ = makeLSymbolNode($1,undefined,0);}
  | STAR ID {$$ = makeLSymbolNode($2,undefined,1);}
  ;


// Some more programming language constructs.
sList : sList stmt {$$ = createTree(noNumber,voidType,NULL,emptyNode,$1,$2,NULL,NULL,NULL,NULL);}
  | stmt {$$ = $1;}
  ;

stmt : inputStmt {$$ = $1;}
  | outputStmt {$$ = $1;}
  | assignStmt {$$ = $1;}
  | ifStmt {$$ = $1;}
  | whileStmt {$$ = $1;}
  | doWhileStmt {$$ = $1;}
  | repeatUntilStmt {$$ = $1;}
  | BREAK SEMICOLON {$$ = createTree(noNumber,voidType,NULL,breakNode,NULL,NULL,NULL,NULL,NULL,NULL);}
  | CONTINUE SEMICOLON {$$ = createTree(noNumber,voidType,NULL,continueNode,NULL,NULL,NULL,NULL,NULL,NULL);}
  | ID '(' ')' SEMICOLON {$$ = createCallerNode($1,NULL);}
  | ID '(' argList ')' SEMICOLON {$$ = createCallerNode($1,$3);}
  | RETURN expr SEMICOLON {$$ = createReturnNode(lst->name,$2);}
  ;

inputStmt : READ '(' identifier ')' SEMICOLON {$$ = createTree(noNumber,voidType,NULL,readNode,$3,NULL,NULL,NULL,NULL,NULL);}
  ;

outputStmt : WRITE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,voidType,NULL,writeNode,$3,NULL,NULL,NULL,NULL,NULL);}
  ;

assignStmt : identifier ASSIGN expr SEMICOLON {$$ = createTree(noNumber,voidType,NULL,assignNode,$1,$3,NULL,NULL,NULL,NULL);}
  | identifier ASSIGN ADDR identifier SEMICOLON {
      struct tnode* newAddrNode = createAddrNode($4);
      $$ = createTree(noNumber,voidType,NULL,assignNode,$1,newAddrNode,NULL,NULL,NULL,NULL);
    }
  ;

ifStmt : IF '(' expr ')' THEN sList ELSE sList ENDIF SEMICOLON {$$ = createTree(noNumber,voidType,NULL,ifElseNode,$6,$8,$3,NULL,NULL,NULL);}
  | IF '(' expr ')' THEN sList ENDIF SEMICOLON {$$ = createTree(noNumber,voidType,NULL,ifElseNode,$6,NULL,$3,NULL,NULL,NULL);}
  ;

whileStmt : WHILE '(' expr ')' DO sList ENDWHILE SEMICOLON  {$$ = createTree(noNumber,voidType,NULL,whileNode,$6,NULL,$3,NULL,NULL,NULL);}
  ;

doWhileStmt : DO sList WHILE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,voidType,NULL,doWhileNode,$2,NULL,$5,NULL,NULL,NULL);}
  ;

repeatUntilStmt : REPEAT sList UNTIL '(' expr ')' SEMICOLON {$$ = createTree(noNumber,voidType,NULL,repeatUntilNode,$2,NULL,$5,NULL,NULL,NULL);}
  ;

// Maybe add support for negative number too later.. 
expr : expr PLUS expr  {$$ = createTree(noNumber,intType,NULL,addNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr MINUS expr   {$$ = createTree(noNumber,intType,NULL,subNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr STAR expr {$$ = createTree(noNumber,intType,NULL,mulNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr DIV expr {$$ = createTree(noNumber,intType,NULL,divNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr LT expr {$$ = createTree(noNumber,boolType,NULL,lessNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr GT expr {$$ = createTree(noNumber,boolType,NULL,greaterNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr LE expr {$$ = createTree(noNumber,boolType,NULL,lessEqualNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr GE expr {$$ = createTree(noNumber,boolType,NULL,greaterEqualNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr NE expr {$$ = createTree(noNumber,boolType,NULL,notEqualNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr ET expr {$$ = createTree(noNumber,boolType,NULL,equalNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr AND expr {$$ = createTree(noNumber,boolType,NULL,andNode,$1,$3,NULL,NULL,NULL,NULL);}
  | expr OR expr {$$ = createTree(noNumber,boolType,NULL,orNode,$1,$3,NULL,NULL,NULL,NULL);}
  | '(' expr ')' {$$ = $2;}
  | NUM {$$ = $1;}
  | ADDR identifier {$$ = createAddrNode($2);}
  | identifier {$$ = $1;}
  | STRING {$$ = $1;}
  | ID '(' ')' {$$ = createCallerNode($1,NULL);}
  | ID '(' argList ')' {$$ = createCallerNode($1,$3);}
  ;

argList : argList ',' expr {
      struct tnode* temp = createArgsNode($3);
      temp->arglist = $1;
      $$ = temp;
    }
  | expr {$$ = createArgsNode($1);}
  ;

// Pointers are supported both for variables identifers and arrays
// Also you can dereference an expression.
identifier : STAR identifier {$$ = createStarNode($2);}
  | STAR '(' expr ')' {$$ = createStarNode($3);}
  | ID {$$ = createIdNode($1,NULL,NULL);}
  | ID '[' expr ']' {$$ = createIdNode($1,$3,NULL);}
  | ID '[' expr ']' '[' expr ']' {$$ = createIdNode($1,$3,$6);}


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

    // Intializing the pointer to the top of local symbol table for currently executing function.
    lst = (struct localSymbolTable*) malloc(sizeof(struct localSymbolTable));
    lst->top = NULL;
    lst->name = NULL;

    yyparse();
    fclose(filePointer);
    return 0;
}