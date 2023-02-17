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

void makeHeader(FILE* targetFile){
    fprintf(targetFile ,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
    fprintf(targetFile, "MOV SP, %d\n", 4122);
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

void readFunctionCall(FILE* targetFile, int reg){
    reg_index fr = getReg();

    fprintf(targetFile, "MOV R%d, \"Read\"\n",fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "MOV R%d, -1\n",fr);
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

int codeGen(struct tnode* t, FILE* targetFile){
    if(!t) return -1;

    reg_index leftReg = codeGen(t->left, targetFile);
    reg_index rightReg = codeGen(t->right, targetFile);
    int tempValue;
    reg_index fr;

    switch(t->nodetype){
        case addNode :  
                        fprintf(targetFile, "ADD R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;
                        break;

        case subNode :  
                        fprintf(targetFile, "SUB R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;
                        break;

        case mulNode :
                        fprintf(targetFile, "MUL R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;
                        break;

        case divNode :  
                        fprintf(targetFile, "DIV R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;
                        break;

        case writeNode: 
                        writeFunctionCall(targetFile, leftReg); 
                        freeReg();
                        return -1;
                        break; 

        case readNode : 
                        tempValue = *(t->left->varname);
                        fr = getReg();
                        fprintf(targetFile, "MOV R%d, %d\n",fr,4096+tempValue-97);
                        readFunctionCall(targetFile, fr);
                        freeReg();
                        freeReg();
                        return -1;
                        break;

        case assignNode :   
                        tempValue = *(t->left->varname);
                        fprintf(targetFile, "MOV [%d], R%d\n", 4096+tempValue-97, rightReg);
                        freeReg();
                        return -1;
                        break;

        case idNode :   
                        fr = getReg();
                        tempValue = *(t->varname);
                        fprintf(targetFile, "MOV R%d, %d\n", fr, 4096+tempValue-97);
                        fprintf(targetFile, "MOV R%d, [R%d]\n", fr, fr);
                        return fr;
                        break;

        case valNode : 
                        fr = getReg();
                        fprintf(targetFile, "MOV R%d, %d\n",fr, t->val);
                        return fr;
                        break;
                    

    }

    return -1;
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
    int garbage = codeGen(root, targetFile);
    exitFunctionCall(targetFile);
    fclose(targetFile);
}