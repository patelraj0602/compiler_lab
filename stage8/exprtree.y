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
char* curClass = NULL;                                  // Store the class name of the current class
%} 

%union{ 
  int num;
  char* str;
  struct tnode* no; 
  struct gsymbol* gnode;
  struct lsymbol* lnode;
  struct paramList* pl;
  struct fieldList* fl;
} 

%type <no> identifier NUM STRING sList stmt inputStmt outputStmt assignStmt expr ifStmt whileStmt doWhileStmt repeatUntilStmt 
%type <no> argList mainBlock fDefBlock fDef program field fieldFunction
%type <no> gClassFuncDefBlock gClassFuncDef gClass gClassList gClassBlock
%type <pl> param paramList
%type <lnode> lId lIdList lDeclList lDecl lDeclBlock
%type <str> ID identifierDecl fName mainHeader
%type <str> INT STR type typeName mName
%type <fl> gTypeIdList gTypeDecl gTypeDeclList

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
%token TYPE ENDTYPE
%token ALLOC INITIALIZE FREE NULL_PTR
%token CLASS ENDCLASS
%token NEW DELETE SELF EXTENDS

%nonassoc AND OR
%nonassoc LT GT LE GE NE ET
%left PLUS MINUS 
%left STAR DIV
%right ADDR
 
%%

// New stuff

// GLOBAL DECLARATION BLOCK : For declaring variables and functions.
program : gClassBlock {
        printf("Presenting the class table: \n"); printClassTable();
        // printPrefix($1);
        // helperFunction($1);
      }
    | gClassBlock gDeclBlock {
        printf("Presenting the class table: \n"); printClassTable();
        printGlobalSymbolTable();
      }
    | gTypeBlock gClassBlock {
        printf("hurray!!\n");
        printTypeTable();
        printf("Presenting the class table: \n"); printClassTable();
        
        // Backend part
        // printPrefix($2);
        // helperFunction($2);
      } 
    | gClassBlock gDeclBlock mainBlock {
        printf("Presenting the class table: \n"); printClassTable();
        printGlobalSymbolTable();
        printLocalSymbolTable();

        // Print prefix tree
        $$ = makeConnectorNode($1,$3);
        // printPrefix($$);
        helperFunction($$);
      }
    | gTypeBlock gClassBlock gDeclBlock mainBlock {
        printTypeTable();
        printf("Presenting the class table: \n"); printClassTable();
        printGlobalSymbolTable();
        printLocalSymbolTable();

        // Print prefix tree
        $$ = makeConnectorNode($2,$4);
        // printPrefix($$);
        helperFunction($$);
      }
    | gTypeBlock gClassBlock gDeclBlock fDefBlock mainBlock {
      printTypeTable();
      printf("Presenting the class table: \n"); printClassTable();
      printGlobalSymbolTable();
      printLocalSymbolTable();
      $$ = makeConnectorNode($4,$5);
      // Call codegen
      helperFunction($$);
    }
  | gTypeBlock gDeclBlock mainBlock {
      $$ = makeConnectorNode($3,NULL);  
      helperFunction($$);
    }
  | gTypeBlock mainBlock {
      $$ = makeConnectorNode($2,NULL);
      helperFunction($$);  
    }
  | gDeclBlock fDefBlock mainBlock {
      $$ = makeConnectorNode($2,$3);
      helperFunction($$);
    }
  ;

// Grammer to make the language object oriented
gClassBlock : CLASS gClassList ENDCLASS {
      curClass = NULL;
      $$ = $2;  
    }
  | CLASS ENDCLASS {$$ = NULL;}
  ;

gClassList : gClassList gClass {$$ = makeConnectorNode($1,$2);}
  | gClass {$$ = $1;}
  ;

gClass : className '{' gClassDeclBlockSeg gClassFuncDefBlock '}' {$$ = $4;}
  | className '{' gClassDeclBlockSeg '}' {$$ = NULL;}
  ;

className : ID  {
      cInstall($1,NULL);                            // Make an entry in class table
      curClass = $1;
    }
  | ID EXTENDS ID {
      cInstall($1,$3);
      curClass = $1;
    } 
  ;

gClassDeclBlockSeg : gClassDeclBlock {}
  ;

gClassDeclBlock : DECL gClassAttrDeclList gClassFuncDeclList ENDDECL {}
  | DECL gClassFuncDeclList ENDDECL {}
  | DECL gClassAttrDeclList ENDDECL {}
  ;

gClassAttrDeclList : gClassAttrDeclList gClassAttrDecl {}
  | gClassAttrDecl {}
  ;

gClassAttrDecl : type gClassIdList SEMICOLON {}
  ;

// Attributes of class does not support pointers and array data types
gClassIdList : gClassIdList ',' ID {classAttrInstall(curClass,$<str>0,$3);}
  | ID {classAttrInstall(curClass,$<str>0,$1);}
  ;

gClassFuncDeclList : gClassFuncDeclList gClassFuncDecl {}
  | gClassFuncDecl {}
  ;

gClassFuncDecl : type gClassFuncName SEMICOLON {}
  ;

// Install the parameter list for this particular method
gClassFuncName : ID '(' paramList ')' {
      if(cLookup($<str>0)) yyerror("Return type of methods cannot be class variables !!\n");
      classMemInstall(curClass,$1,$<str>0,$3);
    }
  ;

gClassFuncDefBlock : gClassFuncDefBlock gClassFuncDef {$$ = makeConnectorNode($1,$2);}
  | gClassFuncDef {$$ = $1;}
  ;

gClassFuncDef : mName '{' lDeclBlockMemFunction BEG sList END '}' {$$ = createMethodFunkNode($1,$5);}
  | mName '{' lDeclBlockMemFunction BEG END '}' {$$ = NULL;}
  ;    

lDeclBlockMemFunction : lDeclBlock {
      char* methodName = $<str>-1;
      struct memberFuncList* node = classMemLookup(curClass,methodName);
      struct lsymbol* top = $1;

      if(top == NULL){
        lst->top = node->ltop;
        lst->type = node->type;
        lst->name = methodName;
      }
      else{
        while(top->next) top=top->next;
        top->next = node->ltop;
        node->ltop = $1;

        // Setting the value of lst which aids in making expression tree.
        lst->top = $1;
        lst->type = node->type;
        lst->name = methodName;
      }
    }
  ;

// CHANGES: Local variables and parameter list should not have same variables name.
mName : type ID '(' paramList ')' {
      struct memberFuncList* node = classMemLookup(curClass,$2);
      
      // No need to search in cLookup as return type of methods cannot be class variables.
      struct typeTable* type = tLookup($1);

      if(!node) yyerror("Method not declared for the class !!\n");
      if(node->type !=  type) yyerror("Return type mismatch between declaration and intialization in an method of the class !!\n");
    
      // spl -- Stored param list
      // npl -- New param list
      // Both of the list should exactly match
      struct paramList* spl = node->plist;
      struct paramList* npl = $4;
      while(spl || npl){
        if((!spl)||(!npl)) yyerror("No of parameter of declaration and initialization does not match");
        if((strcmp(spl->name,npl->name)!=0)||(spl->type != npl->type))
          yyerror("parameters mismatch between declaration and initialization of method");
        spl = spl->next;
        npl = npl->next;
      }

      // Adding the list of parameters to the local symbol table
      struct paramList* pl = $4;
      while(pl){
        struct lsymbol* temp = makeLSymbolNode(pl->name,pl->type,-1);
        temp->next = node->ltop;
        node->ltop = temp;
        pl = pl->next;
      }

      // Set the pointer to the parameter list attribute of memFuncList
      node->plist = $4;

      // Return the function name
      $$ = $2;
    }
  ;

// Grammer for supporting user defined types
// Does not support pointer data types
// CHANGES TO MAKE => Variables names of fieldList must be unique.
gTypeBlock : TYPE gTypeList ENDTYPE {}
  | TYPE ENDTYPE {}
  ;

gTypeList : gTypeList gType {}
  | gType {}
  ;

gType : typeName '{' gTypeDeclList '}' {
      struct typeTable* type = tLookup($1);
      
      // finding the size of the user defined data type and initialzing findex attribute of fields
      struct fieldList* fl = $3; int count = 0;
      while(fl){
        fl->findex = count++;
        fl = fl->next;
      }
      if(count>8) yyerror("Maximum fields in an user defined data type is limited to 8 !!");
      type->size = count;
      type->fields = $3;
    }
  ;

typeName : ID {
      struct typeTable* type = tLookup($1);
      if(type) yyerror("Multiple used defined data types with same name found !!");

      tInstall($1,undefined,NULL);
      $$ = $1;
    }
  ;

gTypeDeclList : gTypeDeclList gTypeDecl {
      struct fieldList* f1 = $1;
      struct fieldList* f2 = $2;

      while(f2->next) f2 = f2->next;
      f2->next = f1;
      $$ = $2;
    }
  | gTypeDecl {$$ = $1;}
  ;

gTypeDecl : type gTypeIdList SEMICOLON {
      struct typeTable* type = tLookup($1);
      if(!type) yyerror("This user defined type is not yet declared !!");

      struct fieldList* field = $2;
      while(field){
        if(field->type == NULL) field->type = type;
        field = field->next;
      }

      $$ = $2;
    }
  ;

gTypeIdList : gTypeIdList ',' ID {
      struct fieldList* node = makeFieldNode($3,NULL);
      node->next = $1;
      $$ = node;
    }
  | ID {$$ = makeFieldNode($1,NULL);}
  ;

// For declaring global variables.
gDeclBlock : DECL gDeclList ENDDECL {
      // Binding of variables   
      struct gsymbol* top = gst->top;
      binding += 8*getClassTableSize();

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
      struct typeTable* type = tLookup($1);
      struct classTable* ctype = cLookup($1);

      while(top){
        if(top->status == undefined){
          // For type
          if(top->ispointer){
            if(type == tLookup("int")) top->type = tLookup("intPtr");
            else if(type == tLookup("str")) top->type = tLookup("strPtr");
            else yyerror("Pointer is not supported for user defined data types");
          }
          else top->type = type;
          
          // For ctype
          top->ctype = cLookup($1);
          top->status = definedDone;

          // Also setting size of class variables to 2
          if(top->ctype) top->size = 2;
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
      gInstall($1,NULL,0,0,0,$3);
      struct gsymbol* node = gLookup($1);
      node->flabel = ++fLabel;
    }
  ;

// Only pointers, variables and 1d-2d array supported by language
identifierDecl : STAR identifierDecl  {
      struct gsymbol* node = gLookup($2);
      node->ispointer = 1;
    }
  | ID  {gInstall($1,NULL,0,0,0,NULL); $$ = $1;}
  | ID '[' expr ']' {gInstall($1,NULL,0,$3->val,0,NULL); $$ = $1;}
  | ID '[' expr ']' '[' expr ']' {gInstall($1,NULL,0,$3->val,$6->val,NULL); $$ = $1;}
  ;

// FUNCTION INITIALIZATION ..
fDefBlock : fDefBlock fDef {$$ = makeConnectorNode($1,$2);}
  | fDef {$$ = $1;}
  ;

fDef : fName '{' lDeclBlockGlobalFunction BEG sList END '}' {$$ = createFunkNode($1,$5);}
    | fName '{' lDeclBlockGlobalFunction BEG END '}' {$$ = NULL;}
  ;

// CHANGES TO MAKE => Variables names of paramList must be unique.
fName : type ID '(' paramList ')' {
      // Finding the function entry from global symbol table
      struct gsymbol* node = gLookup($2);
      struct typeTable* type = tLookup($1);

      // Compare the function declaration with initialization to ensure that both of them are equal
      if(!node) yyerror("Make sure to initialize the function %s\n",$2);
      if(node->type != type) yyerror("Return type mismatch between initialization and declaration of function %s\n",$2);
      
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
  | {$$ = NULL;}
  ;

// only variables and pointers can be passed as arguments not arrays.
param : type ID {$$ = makeParamNode(tLookup($1),$2,0);}
  | type STAR ID {$$ = makeParamNode(tLookup($1),$3,1);}
  ;

type : INT {$$ = $1;}
  | STR {$$ = $1;}
  | ID {$$ = $1;}
  ;


// MAINBLOCK
mainBlock : mainHeader '{' lDeclBlockGlobalFunction BEG sList END '}' {$$ = createMainNode($1,$5);}
  | mainHeader '{' lDeclBlockGlobalFunction BEG END '}' {}
  ;

mainHeader : INT MAIN '(' ')' {
      char* temp = malloc(5);
      memcpy(temp, "main\0", 5);

      gInstall(temp,tLookup("int"),0,0,0,NULL);
      struct gsymbol* node = gLookup(temp);
      node->ltop = NULL;
      node->flabel = ++fLabel;

      $$ = temp;
    }
  ;

// CHANGES: Local variables and parameter list should not have same variables name.
lDeclBlockGlobalFunction : lDeclBlock {
      char* funkName = $<str>-1;

      // Joining this local symbol table to the (ltop field of gsymbol)
      struct gsymbol* gnode = gLookup(funkName);
      struct lsymbol* top = $1;

      if(top == NULL){
        lst->top = gnode->ltop;
        lst->type = gnode->type;
        lst->name = funkName;
      }
      else{
        while(top->next) top=top->next;
        top->next = gnode->ltop;
        gnode->ltop = $1;

        // initializing lst value to current local symbol table for making an expression tree
        lst->top = $1;
        lst->type = gnode->type;
        lst->name = funkName;
      }
    }
  ;

// CHANGES TO MAKE => Variables names of local symbol table must be unique.
// Adding the parameter of the functions to local decl block and also setting the (local symbol table variable)
lDeclBlock : DECL lDeclList ENDDECL {$$ = $2;}
  | DECL ENDDECL {$$ = NULL;}
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
      struct typeTable* type = tLookup($1);
      
      // Class variables are only allowed globally 
      if(type == NULL) 
        yyerror("Type not found. class variables are only allowed globally !!\n");

      while(top){
        if(top->type == NULL){
          if(top->ispointer){
            if(type == tLookup("int")) top->type = tLookup("intPtr");
            else if(type == tLookup("str")) top->type = tLookup("strPtr");
            else yyerror("Pointer is not supported for user defined data types");
          }
          else top->type = type;
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
lId : ID {$$ = makeLSymbolNode($1,NULL,0);}
  | STAR ID {$$ = makeLSymbolNode($2,NULL,1);}
  ;


// Some more programming language constructs.
sList : sList stmt {$$ = makeConnectorNode($1,$2);}
  | stmt {$$ = $1;}
  ;

stmt : inputStmt {$$ = $1;}
  | outputStmt {$$ = $1;}
  | assignStmt {$$ = $1;}
  | ifStmt {$$ = $1;}
  | whileStmt {$$ = $1;}
  | doWhileStmt {$$ = $1;}
  | repeatUntilStmt {$$ = $1;}
  | BREAK SEMICOLON {$$ = createTree(noNumber,tLookup("void"),NULL,breakNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
  | CONTINUE SEMICOLON {$$ = createTree(noNumber,tLookup("void"),NULL,continueNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
  | ID '(' ')' SEMICOLON {$$ = createCallerNode($1,NULL);}
  | ID '(' argList ')' SEMICOLON {$$ = createCallerNode($1,$3);}
  | RETURN expr SEMICOLON {$$ = createReturnNode(lst->type,$2,lst->name);}
  | identifier ASSIGN ALLOC '(' ')' SEMICOLON	{$$ = makeAllocNode($1);}
	| INITIALIZE '(' ')' SEMICOLON {$$ = makeMemInitNode();}
	| FREE '(' identifier ')' SEMICOLON {$$ = makeFreeNode($3);}
  | fieldFunction SEMICOLON {$$ = $1;}
  | identifier ASSIGN NEW '(' ID ')' SEMICOLON {$$ = makeNewNode($1,$5);}
  ;
  // Make delete node later here

inputStmt : READ '(' identifier ')' SEMICOLON {$$ = createTree(noNumber,tLookup("void"),NULL,readNode,$3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
  ;

outputStmt : WRITE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,tLookup("void"),NULL,writeNode,$3,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
  ;

// Add support for assignment of class objects. To test use (https://silcnitc.github.io/expl-docs/oexpltestprograms/test5/)
assignStmt : identifier ASSIGN expr SEMICOLON {$$ = createTree(noNumber,tLookup("void"),NULL,assignNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | identifier ASSIGN ADDR identifier SEMICOLON {
      struct tnode* newAddrNode = createAddrNode($4);
      $$ = createTree(noNumber,tLookup("void"),NULL,assignNode,$1,newAddrNode,NULL,NULL,NULL,NULL,NULL,NULL);
    }
  ;

ifStmt : IF '(' expr ')' THEN sList ELSE sList ENDIF SEMICOLON {$$ = createTree(noNumber,tLookup("void"),NULL,ifElseNode,$6,$8,$3,NULL,NULL,NULL,NULL,NULL);}
  | IF '(' expr ')' THEN sList ENDIF SEMICOLON {$$ = createTree(noNumber,tLookup("void"),NULL,ifElseNode,$6,NULL,$3,NULL,NULL,NULL,NULL,NULL);}
  ;

whileStmt : WHILE '(' expr ')' DO sList ENDWHILE SEMICOLON  {$$ = createTree(noNumber,tLookup("void"),NULL,whileNode,$6,NULL,$3,NULL,NULL,NULL,NULL,NULL);}
  ;

doWhileStmt : DO sList WHILE '(' expr ')' SEMICOLON {$$ = createTree(noNumber,tLookup("void"),NULL,doWhileNode,$2,NULL,$5,NULL,NULL,NULL,NULL,NULL);}
  ;

repeatUntilStmt : REPEAT sList UNTIL '(' expr ')' SEMICOLON {$$ = createTree(noNumber,tLookup("void"),NULL,repeatUntilNode,$2,NULL,$5,NULL,NULL,NULL,NULL,NULL);}
  ;

// Maybe add support for negative number too later.. 
expr : expr PLUS expr  {$$ = createTree(noNumber,tLookup("int"),NULL,addNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr MINUS expr   {$$ = createTree(noNumber,tLookup("int"),NULL,subNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr STAR expr {$$ = createTree(noNumber,tLookup("int"),NULL,mulNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr DIV expr {$$ = createTree(noNumber,tLookup("int"),NULL,divNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr LT expr {$$ = createTree(noNumber,tLookup("bool"),NULL,lessNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr GT expr {$$ = createTree(noNumber,tLookup("bool"),NULL,greaterNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr LE expr {$$ = createTree(noNumber,tLookup("bool"),NULL,lessEqualNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr GE expr {$$ = createTree(noNumber,tLookup("bool"),NULL,greaterEqualNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr NE expr {$$ = createTree(noNumber,tLookup("bool"),NULL,notEqualNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr ET expr {$$ = createTree(noNumber,tLookup("bool"),NULL,equalNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr AND expr {$$ = createTree(noNumber,tLookup("bool"),NULL,andNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | expr OR expr {$$ = createTree(noNumber,tLookup("bool"),NULL,orNode,$1,$3,NULL,NULL,NULL,NULL,NULL,NULL);}
  | '(' expr ')' {$$ = $2;}
  | NUM {$$ = $1;}
  | ADDR identifier {$$ = createAddrNode($2);}          // Somehow this is causing shift/reduce conflict
  | identifier {$$ = $1;}
  | STRING {$$ = $1;}
  | ID '(' ')' {$$ = createCallerNode($1,NULL);}
  | ID '(' argList ')' {$$ = createCallerNode($1,$3);}
  | NULL_PTR {$$ = makeNullNode();}
  | fieldFunction {$$ = $1;}
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
// NOTE: No array of user defined type
identifier : STAR identifier {$$ = createStarNode($2);}
  | STAR '(' expr ')' {$$ = createStarNode($3);}
  | ID {$$ = createIdNode($1,NULL,NULL);}
  | ID '[' expr ']' {$$ = createIdNode($1,$3,NULL);}
  | ID '[' expr ']' '[' expr ']' {$$ = createIdNode($1,$3,$6);}
  | field {$$ = $1;}
  ;

field : field '.' ID  {$$ = makeDotOperatorNode2($1,$3);}
  | ID '.' ID {$$ = makeDotOperatorNode1($1,$3);}
  | SELF '.' ID {$$ = makeDotOperatorNode3($3);}
  ;

fieldFunction : SELF '.' ID '(' argList ')' {$$ = makeMethodNode1($3,$5);}
  | SELF '.' ID '(' ')' {$$ = makeMethodNode1($3,NULL);}
  | ID '.' ID '(' argList ')' {$$ = makeMethodNode2($1,$3,$5);}
  | ID '.' ID '(' ')' {$$ = makeMethodNode2($1,$3,NULL);}
  | field '.' ID '(' argList ')' {$$ = makeMethodNode3($1,$3,$5);}
  | field '.' ID '(' ')' {$$ = makeMethodNode3($1,$3,NULL);}
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

    // Intializing the pointer to the top of local symbol table for currently executing function.
    lst = (struct localSymbolTable*) malloc(sizeof(struct localSymbolTable));
    lst->top = NULL;
    lst->type = NULL;
    lst->name = NULL;

    // Initializing the pointer to the top of type table list
    ttt = (struct typeTableList*) malloc(sizeof(struct typeTableList));
    ttt->top = NULL;
    createTypeTable();                // Create type table with default and special entries.

    // Initializing the pointer to the top of class table
    ctt = (struct classTableList*) malloc(sizeof(struct classTableList));
    ctt->top = NULL;

    yyparse();
    fclose(filePointer);
    return 0;
}