// Comment the #include files before executing the code
// #include <stdio.h> 
// #include <stdlib.h>
// #include "exprtree.h" 
// #include "registers.h"

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

int getLabel(void){
    ++label;
    return label;
}

void makeHeader(FILE* targetFile){
    fprintf(targetFile ,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
    fprintf(targetFile, "MOV SP, %d\n", gst->binding);
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
    
    int tempValue;
    char* stringVal;
    struct gsymbol* gstValue;

    reg_index fr;
    label_no lb0;
    label_no lb1;

    reg_index leftReg;
    reg_index rightReg;
    reg_index retReg;

    reg_index r1,r2,r3;

    switch(t->nodetype){
        case addNode :  
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "ADD R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        case subNode :  
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "SUB R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        case mulNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "MUL R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        case divNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);  
                        fprintf(targetFile, "DIV R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        case writeNode:
                        leftReg = codeGen(t->left, targetFile);
                        writeFunctionCall(targetFile, leftReg); 
                        freeReg();
                        break; 

        case readNode :
                        r1 = getReg();

                        gstValue = lookup(t->left->varname);
                        tempValue = gstValue->binding;
                        fprintf(targetFile, "MOV R%d, %d\n",r1,tempValue);

                        if((t->left->left != NULL)&&(t->left->right == NULL)) {
                            r2 = codeGen(t->left->left,targetFile);
                            fprintf(targetFile, "ADD R%d, R%d\n",r1,r2);
                            freeReg();
                        }
                        else if((t->left->left)&&(t->left->right)) {
                            r2 = codeGen(t->left->left,targetFile);

                            tempValue = gstValue->shape;
                            fprintf(targetFile, "MUL R%d, %d\n", r2, tempValue);
                            fprintf(targetFile, "ADD R%d, R%d\n", r1, r2);
                            freeReg();
                            r2 = codeGen(t->left->right,targetFile);
                            fprintf(targetFile, "ADD R%d, R%d\n", r1, r2);
                            freeReg(); 
                        }
                        readFunctionCall(targetFile, r1);
                        freeReg();
                        break;

        case assignNode :
                        r1 = getReg();

                        gstValue = lookup(t->left->varname);
                        tempValue = gstValue->binding;
                        fprintf(targetFile, "MOV R%d, %d\n",r1,tempValue);

                        if((t->left->left != NULL)&&(t->left->right == NULL)) {
                            r2 = codeGen(t->left->left,targetFile);
                            fprintf(targetFile, "ADD R%d, R%d\n",r1,r2);
                            freeReg();
                        }
                        else if((t->left->left)&&(t->left->right)) {
                            r2 = codeGen(t->left->left,targetFile);

                            tempValue = gstValue->shape;
                            fprintf(targetFile, "MUL R%d, %d\n", r2, tempValue);
                            fprintf(targetFile, "ADD R%d, R%d\n", r1, r2);
                            freeReg();
                            r2 = codeGen(t->left->right,targetFile);
                            fprintf(targetFile, "ADD R%d, R%d\n", r1, r2);
                            freeReg();
                        }

                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "MOV [R%d], R%d\n", r1, rightReg);
                        freeReg();
                        freeReg();
                        break;

        case idNode :
                        leftReg = codeGen(t->left, targetFile); 
                        rightReg = codeGen(t->right, targetFile);
                        fr = getReg();
                        gstValue = lookup(t->varname);

                        fprintf(targetFile, "MOV R%d, %d\n", fr, gstValue->binding);
                        if(leftReg == -1){
                            retReg = fr;
                        }
                        else if((leftReg!=-1)&&(rightReg==-1)){
                            fprintf(targetFile, "ADD R%d, R%d\n", leftReg, fr);
                            freeReg();
                            retReg = leftReg;
                        }
                        else if((leftReg!=-1)&&(rightReg!=-1)){
                            fprintf(targetFile, "MUL R%d, %d\n", leftReg, gstValue->shape);
                            fprintf(targetFile, "ADD R%d, R%d\n", leftReg, rightReg);
                            fprintf(targetFile, "ADD R%d, R%d\n", leftReg, fr);
                            freeReg();
                            freeReg();
                            retReg = leftReg;
                        }

                        fprintf(targetFile, "MOV R%d, [R%d]\n",retReg,retReg);
                        return retReg;

        case valNode :
                        fr = getReg();
                        fprintf(targetFile, "MOV R%d, %d\n",fr, t->val);
                        return fr;

        case strNode :  
                        fr = getReg();
                        fprintf(targetFile, "MOV R%d, \"%s\"\n",fr, t->varname);
                        return fr;
                    
        case lessNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "LT R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        case greaterNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "GT R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        case lessEqualNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "LE R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        case greaterEqualNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "GE R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        case notEqualNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "NE R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        case equalNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "EQ R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        case ifElseNode :
                        fr = codeGen(t->exprVal, targetFile);
                        lb0 = getLabel();
                        lb1 = getLabel(); 

                        // based for the comparision done decide whether to jump or not
                        fprintf(targetFile, "JZ R%d, L%d\n", fr, lb0);
                        freeReg(); 

                        leftReg = codeGen(t->left, targetFile);
                        fprintf(targetFile, "JMP L%d\n",lb1);
                        fprintf(targetFile, "L%d :\n",lb0);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "L%d :\n",lb1);
                        break;

        case whileNode :
                        lb0 = getLabel();
                        lb1 = getLabel();

                        globalLabelContinue = lb0;
                        globalLabelBreak = lb1;

                        fprintf(targetFile, "L%d :\n",lb0);
                        fr = codeGen(t->exprVal, targetFile);
                        fprintf(targetFile, "JZ R%d, L%d\n",fr,lb1);
                        freeReg();

                        leftReg = codeGen(t->left,targetFile);
                        rightReg = codeGen(t->right,targetFile);
                        fprintf(targetFile, "JMP L%d\n",lb0);
                        fprintf(targetFile, "L%d :\n",lb1);

                        globalLabelContinue = -1;
                        globalLabelBreak = -1;

                        break;

        case doWhileNode : 
                        lb0 = getLabel();
                        lb1 = getLabel();

                        globalLabelContinue = lb0;
                        globalLabelBreak = lb1;

                        fprintf(targetFile, "L%d :\n",lb0);
                        leftReg = codeGen(t->left,targetFile);
                        rightReg = codeGen(t->right,targetFile);

                        fr = codeGen(t->exprVal, targetFile);
                        fprintf(targetFile, "JZ R%d, L%d\n",fr,lb1);
                        fprintf(targetFile, "JMP L%d\n",lb0);
                        freeReg();
                        fprintf(targetFile, "L%d :\n",lb1);

                        globalLabelContinue = -1;
                        globalLabelBreak = -1;
                        
                        break;

        case repeatUntilNode :
                        lb0 = getLabel();
                        lb1 = getLabel();

                        globalLabelContinue = lb0;
                        globalLabelBreak = lb1;

                        fprintf(targetFile, "L%d :\n",lb0);
                        leftReg = codeGen(t->left,targetFile);
                        rightReg = codeGen(t->right,targetFile);

                        fr = codeGen(t->exprVal, targetFile);
                        fprintf(targetFile, "JNZ R%d, L%d\n",fr,lb1);
                        fprintf(targetFile, "JMP L%d\n",lb0);
                        freeReg();
                        fprintf(targetFile, "L%d :\n",lb1);

                        globalLabelContinue = -1;
                        globalLabelBreak = -1;
                        
                        break;
                        

        case breakNode :
                        fprintf(targetFile, "JMP L%d\n",globalLabelBreak);
                        break;

        case continueNode :
                        fprintf(targetFile, "JMP L%d\n",globalLabelContinue);
                        break;

        case emptyNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
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
    printf("Bravo!!\n");
    FILE* targetFile = fopen("intermediate_output.xsm","w");

    makeHeader(targetFile);
    int garbage = codeGen(root, targetFile);
    exitFunctionCall(targetFile);
    fclose(targetFile);
}