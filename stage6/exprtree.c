// Comment the #include files before executing the code
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "exprtree.h"

/*
/ assignNode : You can only do assignment if both side have same type. 
But notice an intresting edge case here => if(a=b) <== ;In this case my parser will make an node "=" in expression tree.
To avoid this from happening simpl remove assignNode from the below list.
*/
int operatorCheck(int nodeType){
    return (nodeType == addNode || nodeType == subNode || nodeType == mulNode   
    || nodeType == divNode || nodeType == greaterNode 
    || nodeType == lessNode || nodeType == greaterEqualNode || nodeType == lessEqualNode    
    || nodeType == equalNode || nodeType == notEqualNode);
}

void validate(int nodetype, struct tnode* left, struct tnode* right, struct tnode* exprVal,struct gsymbol* gentry){
    if(nodetype == equalNode || nodetype == notEqualNode){
        // For null node
        if(right->type == tLookup("null")){
            if((left->type == tLookup("int"))||(left->type == tLookup("str"))||(left->type == tLookup("bool"))||(left->type == tLookup("void")))
                yyerror("null is only compatible with pointer data types!!");
        }
        else if((left->type != tLookup("int"))||(right->type != tLookup("int")))
            yyerror("Integer type mismatch !!");
    }
    else if(operatorCheck(nodetype) && ((left->type != tLookup("int"))||(right->type != tLookup("int"))))
        yyerror("Integer type mismatch !!");
    else if(nodetype == assignNode){
        // For null node
        if(right->type == tLookup("null")){
            if((left->type == tLookup("int"))||(left->type == tLookup("str")))
                yyerror("null is only compatible with pointer data types!!");
        }
        else if(left->type != right->type)
            yyerror("type mismatch while assigning !!");   
    }
    else if((nodetype == ifElseNode) && (exprVal->type != tLookup("bool")))
        yyerror("Invalid expression for if/else condition !!");
    else if((nodetype == writeNode) && (left->type == tLookup("bool")))
        yyerror("Invalid expression inside write system call !!");
    else if(((nodetype==whileNode)||(nodetype==doWhileNode)||(nodetype==repeatUntilNode)) && (exprVal->type != tLookup("bool")))
        yyerror("Invalid expression inside looping construct !!");
    else if((nodetype == andNode || nodetype == orNode) && ((left->type != tLookup("bool"))||(right->type != tLookup("bool"))))
        yyerror("type mismatch !!");
    else if(nodetype == idNode){
        // id[a][b] (a and b cannot be of boolean type) AND (a and b must be within bound) 
        if((left)&&(left->type == tLookup("bool"))) yyerror("Invalid expression inside identifier !!");
        if((right)&&(right->type == tLookup("bool"))) yyerror("Invalid expression inside identifier !!");

        if((!left)&&(!right)){
            if((gentry->shape[0])||(gentry->shape[1])) yyerror("The identifier not matching with declaration !!");
        }
        else if((left)&&(!right)){
            if((!gentry->shape[0])||(gentry->shape[1])) yyerror("The identifier not matching with declaration !!");
            // if(left->val >= gentry->shape[0]) yyerror("Program trying to access out of the bound in an 1d array !!");
        }
        else if((left)&&(right)){
            if((!gentry->shape[0])||(!gentry->shape[1])) yyerror("The identifier not matching with declaration !!");
            // if((left->val >= gentry->shape[0])||(right->val >= gentry->shape[1])) yyerror("Program trying to access out of bound in an 2d array !!");
        }
    }
    else if((nodetype == pointerNode)&&((left->type != tLookup("intPtr"))&&(left->type != tLookup("strPtr"))))
        yyerror("Attempt to dereference a non-pointer variable !!");
    
}

struct tnode* createTree(int val, struct typeTable* type, char* c, int nodetype, struct tnode *left, struct tnode *right, 
    struct tnode* exprVal,struct gsymbol* gentry, struct lsymbol* lentry,struct tnode* arglist){

    if(nodetype != idNode){
        validate(nodetype,left,right,exprVal,gentry);    
    }

    struct tnode* temp =  (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->varname = c;
    temp->nodetype = nodetype;
    temp->left = left;  
    temp->right = right;
    temp->exprVal = exprVal;
    temp->gentry = gentry;
    temp->lentry = lentry;
    temp->arglist = arglist;

    return temp;
}

// Making and * node for "* ID" type of expressions 
struct tnode* createStarNode(struct tnode* l){
    validate(pointerNode,l,NULL,NULL,NULL);

    struct typeTable* type;
    if(l->type == tLookup("intPtr")) type = tLookup("int");
    else if(l->type == tLookup("strPtr")) type = tLookup("str");
    else yyerror("You can only dereference an intptr or strptr !!\n");

    return createTree(noNumber,type,NULL,pointerNode,l,NULL,NULL,NULL,NULL,NULL);
}


// Making & node for expression like "& identifier"
struct tnode* createAddrNode(struct tnode* l){

    struct typeTable* type;
    if(l->type == tLookup("int")) type = tLookup("intPtr");
    else if(l->type == tLookup("str")) type = tLookup("strPtr");
    else yyerror("Pointers are supported only for int and str !!\n");
    return createTree(noNumber,type,NULL,addrNode,l,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createIdNode(char* name, struct tnode* left, struct tnode* right){
    struct lsymbol* lEntry = lLookup(name);
    struct gsymbol* gEntry = gLookup(name);

    if((!lEntry)&&(!gEntry)) yyerror("Identifier not found in global symbol table and local symbol table !!\n");

    // If the id is present in lst
    if((lEntry)&&(left||right)) yyerror("The identifier is not of array type !!");
    // If the id is present in gst and not in lst
    if((!lEntry)&&(gEntry)) {
        validate(idNode,left,right,NULL,gEntry);
    }
    
    struct typeTable* type = lEntry ? lEntry->type : gEntry->type;
    return createTree(noNumber,type,name,idNode,left,right,NULL,gEntry,lEntry,NULL); 
}

struct tnode* createArgsNode(struct tnode* left){
    struct typeTable* type = left->type;
    return createTree(noNumber,type,NULL,argsNode,left,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createCallerNode(char* name, struct tnode* arglist){
    struct gsymbol* gnode = gLookup(name);
    struct paramList* pl = gnode->plist;
    struct tnode* ag = arglist;

    // To checkout the parameter and argument list
    // printf("Printing paramerters list\n");
    // while(pl){
    //     printf("%d ,", pl->type);
    //     pl = pl->next;
    // }
    // printf("\nPrinting Argument list list\n");
    // while(ag){
    //     printf("%d ,", ag->type);
    //     ag = ag->arglist;
    // }
    // printf("\n");

    while(pl || ag){
        if((!pl)||(!ag)) yyerror("No of arguments of caller and calle does not match !!");

        // Type Checking
        if(ag->type == tLookup("null")){
            if((pl->type)==tLookup("int")||(pl->type)==tLookup("str"))
                yyerror("Type mismatch of the arguments between caller and calle function !!");
        }
        else if(pl->type != ag->type) yyerror("Type mismatch of the arguments between caller and calle function !!");
        pl = pl->next;
        ag = ag->arglist;
    }

    // The type of the caller node is return type of function
    return createTree(noNumber,gnode->type,name,callerNode,NULL,NULL,NULL,NULL,NULL,arglist);
}

struct tnode* createReturnNode(char* name, struct tnode* left){
    struct gsymbol* gnode = gLookup(name);

    // Type Checking
    if(left->type == tLookup("null")){
        if((left->type)==tLookup("int")||(left->type)==tLookup("str"))
            yyerror("Return type of declaration does not match with initialization !!\n");
    }
    else if(gnode->type != left->type) yyerror("Return type of declaration does not match with initialization !!\n");
    return createTree(noNumber,tLookup("void"),name,returnNode,left,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createMainNode(char* name, struct tnode* left){
    return createTree(noNumber,tLookup("void"),name,mainNode,left,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createFunkNode(char* name, struct tnode* left){
    return createTree(noNumber,tLookup("void"),name,funkNode,left,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* makeDotOperatorNode1(char* n1, char* n2){
    struct lsymbol* lEntry = lLookup(n1);
    struct gsymbol* gEntry = gLookup(n1);

    if((lEntry==NULL)&&(gEntry==NULL)) yyerror("Identifier not declared!!");
    
    struct typeTable* type = lEntry ? lEntry->type : gEntry->type;
    struct fieldList* field = type->fields;
    while(field){
        if(strcmp(field->name,n2)==0){
            struct tnode* left;
            if(lEntry) left = createTree(noNumber,type,n1,idNode,NULL,NULL,NULL,NULL,lEntry,NULL);
            else left = createTree(noNumber,type,n1,idNode,NULL,NULL,NULL,gEntry,NULL,NULL);

            struct tnode* right = createTree(field->findex,field->type,n2,fieldNode,NULL,NULL,NULL,NULL,NULL,NULL);
            return createTree(noNumber,field->type,".",dotOperatorNode,left,right,NULL,NULL,NULL,NULL);
        }
        field = field->next;
    }
    yyerror("No matching field for the given identifier!!");
    return NULL;
}

struct tnode* makeDotOperatorNode2(struct tnode* left, char* r){
    struct typeTable* type = left->type;
    struct fieldList* field = type->fields;
    while(field){
        if(strcmp(field->name,r)==0){
            struct tnode* right = createTree(field->findex,field->type,r,fieldNode,NULL,NULL,NULL,NULL,NULL,NULL);
            return createTree(noNumber,field->type,".",dotOperatorNode,left,right,NULL,NULL,NULL,NULL);
        }
        field = field->next;
    }
    yyerror("No matching field for the given identifier!!");
    return NULL;
}

struct tnode* makeAllocNode(struct tnode* left){
    if((left->type == tLookup("int"))||(left->type == tLookup("intPtr"))||(left->type == tLookup("str"))||(left->type == tLookup("strPtr")))
        yyerror("Expected an user defined type for alloc !!");
    return createTree(noNumber,tLookup("void"),NULL,allocNode,left,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* makeMemInitNode(void){
    return createTree(noNumber,tLookup("void"),NULL,initNode,NULL,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* makeFreeNode(struct tnode* left){
    if((left->type == tLookup("int"))||(left->type == tLookup("intPtr"))||(left->type == tLookup("str"))||(left->type == tLookup("strPtr")))
        yyerror("Expected an user defined type for freeing identifier !!");
    return createTree(noNumber,tLookup("void"),NULL,freeNode,left,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* makeNullNode(){
    return createTree(0,tLookup("null"),NULL,nullNode,NULL,NULL,NULL,NULL,NULL,NULL);
}
// INITIALIZING FUNCTIONS.

/*Functions related to global symbol table */
// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise
struct gsymbol* gLookup(char* name){
    // Update : Variables and functions can have same identifier name ..
    struct gsymbol* top = gst->top;
    while(top){
        if(strcmp(top->name,name) == 0) return top;
        top = top->next; 
    }
    return NULL;
}

void gInstall(char* name, struct typeTable* type, int ispointer, int shape0, int shape1, struct paramList* plist){
    if(gLookup(name)!=NULL)
        yyerror("Multiple variables with same name found");

    struct gsymbol* newEnty = (struct gsymbol*) malloc(sizeof(struct gsymbol));  

    newEnty->name = name;
    newEnty->type = type;
    newEnty->ispointer = ispointer;
    newEnty->size = (shape0?shape0:1)*(shape1?shape1:1);
    newEnty->shape[0] = shape0;
    newEnty->shape[1] = shape1;
    newEnty->plist = plist;
    newEnty->ltop = NULL;
    newEnty->flabel = -1;
    newEnty->ltop = NULL;
    newEnty->next = NULL; 

    newEnty->next = gst->top;
    gst->top = newEnty;      
}

// To print the global symbol table
void printGlobalSymbolTable(void){
    printf("Presenting global symbol table \n");

    struct gsymbol* top = gst->top;
    while(top){
        printf("name: %s, type: %s, size: %d, binding: %d, shape : %d %d, flabel : %d\n",top->name,top->type->name,top->size,top->binding,top->shape[0],top->shape[1],top->flabel);
        top = top->next;
    }
}


/* Functions related to local symbol table */
struct lsymbol* makeLSymbolNode(char* name, struct typeTable* type, int ispointer){
    struct lsymbol* newEntry = (struct lsymbol*) malloc(sizeof(struct lsymbol));
    newEntry->name = name;
    newEntry->type = type;
    newEntry->ispointer = ispointer;
    newEntry->next = NULL;
    return newEntry;
}

struct lsymbol* lLookup(char* name){
    struct lsymbol* top = lst->top;
    while(top){
        if(strcmp(top->name,name) == 0) return top;
        top = top->next; 
    }
    return NULL;
}

void printLocalSymbolTable(void){
    struct gsymbol* top = gst->top;
    while(top){
        if(top->ltop){
            printf("\n");
            printf("Function %s\n",top->name);

            struct paramList* pl = top->plist;
            printf("Parameters list : \n");
            while(pl) {
                printf("name: %s, type: %s\n", pl->name, pl->type->name);
                pl = pl->next;
            }
            
            struct lsymbol* lt = top->ltop;
            printf("Presenting local symbol table : \n");
            while(lt){
                printf("name: %s, type: %s\n", lt->name, lt->type->name);
                lt = lt->next;
            }
        }
        top = top->next;
    }
}

/* Functions related to paramlist */
struct paramList* makeParamNode(struct typeTable* type, char* name, int ispointer){
    struct paramList* newEntry = (struct paramList*) malloc(sizeof(struct paramList));
    if(ispointer) newEntry->type = (type == tLookup("int")) ? tLookup("intPtr") : tLookup("strPtr");
    else newEntry->type = type;
    newEntry->name = name;
    newEntry->next = NULL;
    return newEntry;
}


/* Functions related to typeTable */
void createTypeTable(void){
    // Installing default data types
    tInstall("int", 1, NULL);
    tInstall("intPtr", 1, NULL);
    tInstall("str", 1, NULL);
    tInstall("strPtr", 1, NULL);

    // Installing special data types
    tInstall("bool", 1, NULL);
    tInstall("null", 1, NULL);
    tInstall("void", 1, NULL);
}                                

void tInstall(char* name, int size, struct fieldList* fields){
    struct typeTable* type = (struct typeTable*) malloc(sizeof(struct typeTable));
    type->name = name;
    type->size = size;
    type->fields = fields;
    type->next = NULL;

    // Initialize the findex attribute of each field present in fieldlist
    struct fieldList* temp = fields; int val=0;
    while(temp){
        temp->findex = val++;
        temp = temp->next;
    }

    // Installing the node to the top of type table
    type->next = ttt->top;
    ttt->top = type;
}                                                                  
struct typeTable* tLookup(char* name){
    struct typeTable* type = ttt->top;
    while(type){
        if(strcmp(type->name, name)==0) return type;
        type = type->next;
    }
    return NULL;
}                                                                                          
struct fieldList* fLookup(struct typeTable* type, char* name){
    struct fieldList* field = type->fields;
    while(field){
        if(strcmp(field->name, name)==0) return field;
        field = field->next;
    }
    return NULL;
}

// Assuming that the size attribute of typeTable has an valid size
int getSize(struct typeTable* type){
    return type->size;
}  

struct fieldList* makeFieldNode(char* name, struct typeTable* type){
    struct fieldList* field = (struct fieldList*) malloc(sizeof(struct fieldList));
    field->name = name;
    field->type = type;
    field->findex = undefined;
    field->next = NULL;

    return field;
}

void printTypeTable(void){
    struct typeTable* top = ttt->top;
    while(top){
        printf("Name: %s, size: %d\n",top->name,top->size);
        if(top->fields){
            printf("The fieldlist of %s is as follows:\n",top->name);
            struct fieldList* fl = top->fields;
            while(fl){
                printf("Name: %s, findex: %d, type: %s\n",fl->name,fl->findex,fl->type->name);
                fl = fl->next;
            }
            printf("\n");
        }
        top = top->next;
    }
    printf("\n");
}

// Printing nodetype values
void printPrefix(struct tnode* t){
    if(!t) return;

    printf("%d\n",t->nodetype);
    if(t->nodetype == callerNode){
        struct tnode* temp = t->arglist;
        printf("printing args: ");
        while(temp) {
            printf("%s ,",temp->type->name);
            temp=temp->arglist;
        }
        printf("\n");
    }
    printPrefix(t->exprVal);
    printPrefix(t->left);
    printPrefix(t->right);
}
