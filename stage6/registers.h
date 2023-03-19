#include <stdio.h>

#define reg_index int
#define label_no int
int count = -1;
int label = -1;
int functionRetReg = 12;

int getReg();
void freeReg();
int getLabel();
int getAddressOfIdentifier(struct tnode* t, FILE* targetFile);
int codeGen(struct tnode* t, FILE* targetFile);
void makeHeader(FILE* targetFile);
void writeFunctionCall(FILE* targetFile, int reg);
void readFunctionCall(FILE* targetFile, int reg);
void exitFunctionCall(FILE* targetFile); 
void helperFunction(struct tnode* root);    

// Making an stack to support nesting loop constructs.
struct topOfStack{
    struct stackNode* top;
};
struct stackNode{
    int val; 
    struct stackNode* next;
};

int pushInStack(int val);
int popFromStack();
void printStack();
int isStackEmpty();

struct topOfStack* tos;