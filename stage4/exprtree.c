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

struct tnode* createTree(int val, int type, char* c, int nodetype, struct tnode *left, struct tnode *right, struct tnode* exprVal,struct gsymbol* gentry){
    if(operatorCheck(nodetype) && ((left->type != intType)||(right->type != intType)))
        yyerror("Integer type mismatch");
    else if((nodetype == assignNode) && (left->type != right->type))
        yyerror("string type mismatch");

    // While should accept boolean expession only
    // Same goes with write
    // int, bool, string, void
    
    struct tnode* temp =  (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->varname = c;
    temp->nodetype = nodetype;
    temp->left = left;  
    temp->right = right;
    temp->exprVal = exprVal;
    temp->gentry = gentry;

    return temp;
}

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
    printPrefix(t->exprVal);
    printPrefix(t->left);
    printPrefix(t->right);
}

/******* Functions related to global symbol table ***********/


// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise
struct gsymbol* lookup(char* name){
    struct gsymbol* top = gst->top;
    while(top){
        if(strcmp(top->name,name) == 0) return top;
        top = top->next; 
    }
    return NULL;
}

// Creates a symbol table entry.
void install(char* name, int type, int size, int shape){
    if(lookup(name)!=NULL)
        yyerror("Multiple variables with same name found");

    struct gsymbol* newEnty = (struct gsymbol*) malloc(sizeof(struct gsymbol));
    newEnty->name = name;
    newEnty->type = type;
    newEnty->size = size;
    newEnty->shape = shape;
    newEnty->next = NULL; 

    newEnty->next = gst->top;
    gst->top = newEnty;
}

// To print the global symbol table
void printGlobalSymbolTable(void){
    printf("Presenting global symbol table \n");

    struct gsymbol* top = gst->top;
    while(top){
        printf("name: %s, type: %d, size: %d, binding: %d\n",top->name,top->type,top->size,top->binding);
        top = top->next;
    }
}

