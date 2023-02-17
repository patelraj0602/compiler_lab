// Comment the #include files before executing the code
#include <stdio.h>
#include <stdlib.h>
#include "exprtree.h"
#include "registers.h"

int getReg(void){
    count++;
    if(count < 15) return count;
    else{
        printf("Error: Ran out of registers\n");
        exit(1);
    } 
}

void freeReg(void){
    count--;
}

int codeGen(struct tnode* t, FILE* targetFile){
    reg_index returnReg;

    if(t->op == NULL){
        // Leaf node
        reg_index reg = getReg();
        fprintf(targetFile, "MOV R%d, %d\n", reg, t->val);
        returnReg = reg;
    }
    else{
        reg_index leftReg = codeGen(t->left, targetFile);
        reg_index rightReg = codeGen(t->right, targetFile);

        switch(*(t->op)){
            case '+' : fprintf(targetFile, "ADD R%d, R%d\n", leftReg, rightReg);
                       break;
            case '-' : fprintf(targetFile, "SUB R%d, R%d\n", leftReg, rightReg);
                       break;
            case '*' : fprintf(targetFile, "MUL R%d, R%d\n", leftReg, rightReg);
                       break;
            case '/' : fprintf(targetFile, "DIV R%d, R%d\n", leftReg, rightReg);
                       break;
        }
        returnReg = leftReg;
        freeReg();  
    }
    return returnReg;
}

void makeHeader(FILE* targetFile){
    fprintf(targetFile ,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
}

void writeFunctionCall(FILE* targetFile, int reg){
    reg_index fr = getReg();

    fprintf(targetFile, "MOV R%d, \"Write\"\n",fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "MOV R%d, -2\n",fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "MOV R%d, R%d\n",fr,reg);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "CALL 0\n");
    fprintf(targetFile, "POP R%d\n", fr);
    fprintf(targetFile, "POP R%d\n", fr);
    fprintf(targetFile, "POP R%d\n", fr);
    fprintf(targetFile, "POP R%d\n", fr);
    fprintf(targetFile, "POP R%d\n", fr);

    freeReg(); 
}

void exitFunctionCall(FILE* targetFile){
    reg_index fr = getReg();

    fprintf(targetFile, "MOV R%d, \"Exit\"\n", fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "CALL 0");

    freeReg();
}

void helperFunction(struct tnode* root){
    FILE* targetFile = fopen("output.xsm","w");

    makeHeader(targetFile);
    int outputReg = codeGen(root, targetFile);
    writeFunctionCall(targetFile, outputReg);
    exitFunctionCall(targetFile);
    fclose(targetFile);
}