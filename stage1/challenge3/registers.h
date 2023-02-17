#include <stdio.h>

#define reg_index int
int count = -1;

int getReg();
void freeReg();
int codeGen(struct tnode* t, FILE* targetFile);
void makeHeader(FILE* targetFile);
void writeFunctionCall(FILE* targetFile, int reg);
void exitFunctionCall(FILE* targetFile);