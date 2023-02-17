// Comment the #include files before executing the code
#include <stdio.h>
#include <stdlib.h>
#include "exprtree.h"

struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n; 
    temp->left = NULL;
    temp->right = NULL;
    return temp; 
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

int evaluate(struct tnode *t){
    if(t->op == NULL)
    {
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}

void printInfix(struct tnode* t){
    if(!t) return;
    printInfix(t->left);

    if((t->left)||(t->right)) printf("%c ",*(t->op));
    else printf("%d ",t->val);

    printInfix(t->right);
}

void printPostfix(struct tnode* t){
    if(!t) return;
    printInfix(t->left);
    printInfix(t->right);

    if((t->left)||(t->right)) printf("%c ",*(t->op));
    else printf("%d ",t->val);
}

void printPrefix(struct tnode* t){
    if(!t) return;

    if((t->left)||(t->right)) printf("%c ",*(t->op));
    else printf("%d ",t->val);

    printInfix(t->left);
    printInfix(t->right);
}