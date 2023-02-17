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

// int evaluate(struct tnode *t){
//     if(t->op == NULL)
//     {
//         return t->val;
//     }
//     else{
//         switch(*(t->op)){
//             case '+' : return evaluate(t->left) + evaluate(t->right);
//                        break;
//             case '-' : return evaluate(t->left) - evaluate(t->right);
//                        break;
//             case '*' : return evaluate(t->left) * evaluate(t->right);
//                        break;
//             case '/' : return evaluate(t->left) / evaluate(t->right);
//                        break;
//         }
//     }
// }

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