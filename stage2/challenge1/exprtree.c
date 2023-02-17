// Comment the #include files before executing the code
#include <stdio.h>
#include <stdlib.h>
#include "exprtree.h"


struct tnode* createTree(int val, int type, char* c, int nodetype, struct tnode *left, struct tnode *right){
    struct tnode* temp =  (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->varname = c; 
    temp->nodetype = nodetype;
    temp->left = left; 
    temp->right = right;

    return temp;
}

int evaluate(struct tnode *t){
    if(!t) return -1;
    int temp;

    switch(t->nodetype){
        case addNode : return evaluate(t->left) + evaluate(t->right);
                       break;
        case subNode : return evaluate(t->left) - evaluate(t->right);
                       break;
        case mulNode : return evaluate(t->left) * evaluate(t->right);
                       break;
        case divNode : return evaluate(t->left) / evaluate(t->right);
                       break;
            
        case assignNode:    temp = (*(t->left->varname))-'a';
                            varArr[temp] = evaluate(t->right);
                            return -1;
                            break;

        case valNode :  return t->val;
                        break;

        case idNode :   temp = *(t->varname);
                        return varArr[temp-'a'];
                        break;

        case readNode : 
                        temp = *(t->left->varname);
                        printf("%c = ",temp);
                        scanf("%d",&varArr[temp-'a']);
                        return -1; 
                        break;

        case  writeNode : 
                        printf("%d\n", evaluate(t->left));
                        return -1;
                        break;

        case emptyNode :    temp = evaluate(t->left);
                            temp = evaluate(t->right);
                            return -1;
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
    printPrefix(t->left);
    printPrefix(t->right);
}