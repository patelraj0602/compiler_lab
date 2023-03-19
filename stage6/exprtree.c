// Comment the #include files before executing the code
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h> 
// #include "exprtree.h"

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
    if(operatorCheck(nodetype) && ((left->type != intType)||(right->type != intType)))
        yyerror("Integer type mismatch !!");
    else if((nodetype == assignNode) && (left->type != right->type))
        yyerror("type mismatch while assigning !!");   
    else if((nodetype == ifElseNode) && (exprVal->type != boolType))
        yyerror("Invalid expression for if/else condition !!");
    else if((nodetype == writeNode) && (left->type == boolType))
        yyerror("Invalid expression inside write system call !!");
    else if(((nodetype==whileNode)||(nodetype==doWhileNode)||(nodetype==repeatUntilNode)) && (exprVal->type != boolType))
        yyerror("Invalid expression inside looping construct !!");
    else if((nodetype == andNode || nodetype == orNode) && ((left->type != boolType)||(right->type != boolType)))
        yyerror("type mismatch !!");
    else if(nodetype == idNode){
        // id[a][b] (a and b cannot be of boolean type) AND (a and b must be within bound) 
        if((left)&&(left->type == boolType)) yyerror("Invalid expression inside identifier !!");
        if((right)&&(right->type == boolType)) yyerror("Invalid expression inside identifier !!");

        // if((!left)&&(!right)){
        //     if((gentry->shape[0])||(gentry->shape[1])) yyerror("The identifier not matching with declaration !!");
        // }
        // else if((left)&&(!right)){
        //     if((!gentry->shape[0])||(gentry->shape[1])) yyerror("The identifier not matching with declaration !!");
        //     if(left->val >= gentry->shape[0]) yyerror("Program trying to access out of the bound in an 1d array !!");
        // }
        // else if((left)&&(right)){
        //     if((!gentry->shape[0])||(!gentry->shape[1])) yyerror("The identifier not matching with declaration !!");
        //     if((left->val >= gentry->shape[0])||(right->val >= gentry->shape[1])) yyerror("Program trying to access out of bound in an 2d array !!");
        // }
    }
    else if((nodetype == pointerNode)&&((left->type != intPtrType)&&(left->type != strPtrType)))
        yyerror("Attempt to dereference a non-pointer variable !!");
    
}

struct tnode* createTree(int val, int type, char* c, int nodetype, struct tnode *left, struct tnode *right, 
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

    int type = (l->type == intPtrType) ? intType : strType;
    return createTree(noNumber,type,NULL,pointerNode,l,NULL,NULL,NULL,NULL,NULL);
}


// Making & node for expression like "& identifier"
struct tnode* createAddrNode(struct tnode* l){
    int type = (l->type == intType) ? intPtrType : strPtrType;
    return createTree(noNumber,type,NULL,addrNode,l,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createIdNode(char* name, struct tnode* left, struct tnode* right){
    struct lsymbol* lEntry = lLookup(name);
    struct gsymbol* gEntry = gLookup(name);
    if((!lEntry)&&(!gEntry)) yyerror("Identifier not found in global symbol table and local symbol table !!\n");

    // If the id is present in gst and not in lst
    if((!lEntry)&&(gEntry)) {
        validate(idNode,left,right,NULL,gEntry);
    }
    
    int type = lEntry ? lEntry->type : gEntry->type;
    return createTree(noNumber,type,name,idNode,left,right,NULL,gEntry,lEntry,NULL); 
}

struct tnode* createArgsNode(struct tnode* left){
    int type = left->type;
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
        if(pl->type != ag->type) yyerror("Type mismatch of the arguments between caller and calle function !!");
        pl = pl->next;
        ag = ag->arglist;
    }

    // The type of the caller node is return type of function
    return createTree(noNumber,gnode->type,name,callerNode,NULL,NULL,NULL,NULL,NULL,arglist);
}

struct tnode* createReturnNode(char* name, struct tnode* left){
    struct gsymbol* gnode = gLookup(name);
    // Validation
    if(gnode->type != left->type) yyerror("Return type is function is suppose to be %d but return expression is of type %d\n",gnode->type,left->type);
    return createTree(noNumber,voidType,name,returnNode,left,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createMainNode(char* name, struct tnode* left){
    return createTree(noNumber,voidType,name,mainNode,left,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createFunkNode(char* name, struct tnode* left){
    return createTree(noNumber,voidType,name,funkNode,left,NULL,NULL,NULL,NULL,NULL);
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

void gInstall(char* name, int type, int ispointer, int shape0, int shape1, struct paramList* plist){
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
        printf("name: %s, type: %d, size: %d, binding: %d, shape : %d %d, flabel : %d\n",top->name,top->type,top->size,top->binding,top->shape[0],top->shape[1],top->flabel);
        top = top->next;
    }
}


/* Functions related to local symbol table */
struct lsymbol* makeLSymbolNode(char* name, int type, int ispointer){
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
                printf("name: %s, type: %d\n", pl->name, pl->type);
                pl = pl->next;
            }
            
            struct lsymbol* lt = top->ltop;
            printf("Presenting local symbol table : \n");
            while(lt){
                printf("name: %s, type: %d\n", lt->name, lt->type);
                lt = lt->next;
            }
        }
        top = top->next;
    }
}

/* Functions related to paramlist */
struct paramList* makeParamNode(int type, char* name, int ispointer){
    struct paramList* newEntry = (struct paramList*) malloc(sizeof(struct paramList));
    if(ispointer) newEntry->type = (type == intType) ? intPtrType : strPtrType;
    else newEntry->type = type;
    newEntry->name = name;
    newEntry->next = NULL;
    return newEntry;
}


// To evaluate expression tree by recursion..
int evaluate(struct tnode *t){
    if(!t) return -1;
    int temp;

    switch(t->nodetype){

        case addNode : return evaluate(t->left) + evaluate(t->right);

        case subNode : return evaluate(t->left) - evaluate(t->right);

        case mulNode : return evaluate(t->left) * evaluate(t->right);

        case divNode : return evaluate(t->left) / evaluate(t->right);

        case lessNode : return (evaluate(t->left) < evaluate(t->right));

        case greaterNode : return (evaluate(t->left) > evaluate(t->right));

        case lessEqualNode : return (evaluate(t->left) <= evaluate(t->right));

        case greaterEqualNode : return (evaluate(t->left) >= evaluate(t->right));

        case notEqualNode : return (evaluate(t->left) != evaluate(t->right));

        case equalNode : return (evaluate(t->left) == evaluate(t->right));
            
        case assignNode:    temp = (*(t->left->varname))-'a'; 
                            varArr[temp] = evaluate(t->right);
                            break;

        case valNode :  return t->val;

        case idNode :   temp = *(t->varname);
                        return varArr[temp-'a'];

        case readNode : 
                        temp = *(t->left->varname);
                        printf("%c = ",temp);
                        scanf("%d",&varArr[temp-'a']);
                        break;

        case writeNode : 
                        printf("%d\n", evaluate(t->left));
                        break;

        case emptyNode :    
                        temp = evaluate(t->left);
                        temp = evaluate(t->right);
                        break;

        case ifElseNode : 
                        temp = (evaluate(t->exprVal)) ? evaluate(t->left) : evaluate(t->right);
                        break;

        case whileNode : 
                        while(evaluate(t->exprVal)){
                            evaluate(t->left);
                        }
                        break;

        case doWhileNode : 
                        do{
                            evaluate(t->left);
                        } while(evaluate(t->exprVal));
                        break;

        case repeatUntilNode :
                        do{
                            evaluate(t->left);
                        } while(!evaluate(t->exprVal));
                        break;
    }
    return -1;
}

// Printing nodetype values
void printInfix(struct tnode* t){
    if(!t) return;
    printInfix(t->left);
    printf("%d\n",t->nodetype);
    printInfix(t->right);
}

void printPostfix(struct tnode* t){
    if(!t) return;
    printPostfix(t->left);
    printPostfix(t->right);
    printf("%d\n",t->nodetype);
}

void printPrefix(struct tnode* t){
    if(!t) return;

    printf("%d\n",t->nodetype);
    if(t->nodetype == callerNode){
        struct tnode* temp = t->arglist;
        printf("printing args: ");
        while(temp) {
            printf("%d ,",temp->type);
            temp=temp->arglist;
        }
        printf("\n");
    }
    printPrefix(t->exprVal);
    printPrefix(t->left);
    printPrefix(t->right);
}
