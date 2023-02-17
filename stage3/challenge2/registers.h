#include <stdio.h>

#define reg_index int
#define label_no int
int count = -1;
int label = -1;

int getReg();
void freeReg();
int getLabel();
int codeGen(struct tnode* t, FILE* targetFile);
void makeHeader(FILE* targetFile);
void writeFunctionCall(FILE* targetFile, int reg);
void readFunctionCall(FILE* targetFile, int reg);
void exitFunctionCall(FILE* targetFile);
void helperFunction(struct tnode* root);  