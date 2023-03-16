// Comment the #include files before executing the code
// #include <stdio.h> 
// #include <stdlib.h>
// #include "exprtree.h" 
// #include "registers.h"


// Implementation of stack used for continue and break statements.
int pushInStack(int val){
    struct stackNode* newNode = (struct stackNode*)malloc(sizeof(struct stackNode));
    newNode->val=val;

    newNode->next = tos->top;
    tos->top = newNode; 
    return 1;
}
int popFromStack(void){
    if(tos->top == NULL) return 0;

    int val = tos->top->val;
    tos->top = tos->top->next;
    return val;
}
void printStack(void){
    struct stackNode* temp = tos->top;
    while(temp){
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}
int isStackEmpty(){
    if(tos->top) return 0;
    return 1;
}


// Function for acquire and release registers
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


// To get an free label
int getLabel(void){
    ++label;
    return label;
}


// Function foor making header
// Updated
void makeHeader(FILE* targetFile){
    fprintf(targetFile ,"0\nmain\n0\n0\n0\n0\n0\n0\nBRKP\n");
}



// Implementing system calls
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

int getAddressOfIdentifier(struct tnode* t, FILE* targetFile){
    reg_index r1,r2;
    struct gsymbol* gstValue;
    struct lsymbol* lstValue;
    int tempValue;

    r1 = getReg();

    // Used while assignNode: Support for 1-2d arrays are yet to added for this pointerNode
    // Also that variable should be an global variable
    if(t->left->nodetype == pointerNode){
        gstValue = t->left->left->gentry;             
        fprintf(targetFile, "MOV R%d, %d\n", r1, gstValue->binding);
        fprintf(targetFile, "MOV R%d, [R%d]\n",r1,r1);
    }
    else{
        gstValue = t->left->gentry;
        lstValue = t->left->lentry;
        tempValue = (lstValue) ? lstValue->binding : gstValue->binding;

        if(lstValue){
            fprintf(targetFile, "MOV R%d, BP\n", r1);
            fprintf(targetFile, "ADD R%d, %d\n",r1,tempValue);
        }
        else{
            fprintf(targetFile, "MOV R%d, %d\n",r1,tempValue);
            if((t->left->left != NULL)&&(t->left->right == NULL)) {
                r2 = codeGen(t->left->left,targetFile);
                fprintf(targetFile, "ADD R%d, R%d\n",r1,r2);
                freeReg();
            }
            else if((t->left->left)&&(t->left->right)) {
                r2 = codeGen(t->left->left,targetFile);

                tempValue = gstValue->shape[1];
                fprintf(targetFile, "MUL R%d, %d\n", r2, tempValue);
                fprintf(targetFile, "ADD R%d, R%d\n", r1, r2);
                freeReg();
                r2 = codeGen(t->left->right,targetFile);
                fprintf(targetFile, "ADD R%d, R%d\n", r1, r2);
                freeReg();
            }
        }
    }
    return r1;
}

// Main function for generating the target language code.
int codeGen(struct tnode* t, FILE* targetFile){
    if(!t) return -1;
    
    int tempValue,i,len1,len2;
    char* stringVal;
    struct gsymbol* gstValue;
    struct lsymbol* lstValue;
    struct tnode* argNode;
    struct paramList* pl;

    reg_index fr;
    label_no lb0, lb1;

    reg_index leftReg;
    reg_index rightReg;
    reg_index retReg;

    reg_index r1,r2,r3;

    switch(t->nodetype){

        // No change
        case addNode :  
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "ADD R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        // No change
        case subNode :  
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "SUB R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        // No change
        case mulNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "MUL R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;
        // No change
        case divNode :
                        leftReg = codeGen(t->left, targetFile); 
                        rightReg = codeGen(t->right, targetFile);  
                        fprintf(targetFile, "DIV R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        // No change
        case writeNode:
                        leftReg = codeGen(t->left, targetFile);
                        writeFunctionCall(targetFile, leftReg); 
                        freeReg();
                        break; 

        // No change
        case readNode :
                        leftReg = getAddressOfIdentifier(t,targetFile);
                        readFunctionCall(targetFile, leftReg);
                        freeReg();                                   // This register was acquired in "getAddressOfIdentifier" function
                        break;

        // No change
        case assignNode :
                        leftReg = getAddressOfIdentifier(t,targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "MOV [R%d], R%d\n", leftReg, rightReg);
                        freeReg();                                                      // This register was acquired in "getAddressOfIdentifier" function
                        freeReg();                                                      // Register from right recursive function call.
                        break;

        // Updated
        case idNode :
                        leftReg = codeGen(t->left, targetFile); 
                        rightReg = codeGen(t->right, targetFile);
                        fr = getReg();

                        gstValue = t->gentry;
                        lstValue = t->lentry;

                        if(lstValue){
                            fprintf(targetFile, "MOV R%d, BP\n", fr);
                            fprintf(targetFile, "ADD R%d, %d\n",fr,lstValue->binding);
                            retReg = fr;
                        }
                        else{
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
                                fprintf(targetFile, "MUL R%d, %d\n", leftReg, gstValue->shape[1]);
                                fprintf(targetFile, "ADD R%d, R%d\n", leftReg, rightReg);
                                fprintf(targetFile, "ADD R%d, R%d\n", leftReg, fr);
                                freeReg();
                                freeReg();
                                retReg = leftReg;
                            }
                        }

                        fprintf(targetFile, "MOV R%d, [R%d]\n",retReg,retReg);
                        return retReg;

        // Updated
        case pointerNode :
                        retReg = getAddressOfIdentifier(t,targetFile);
                        fprintf(targetFile, "MOV R%d, [R%d]\n",retReg,retReg);
                        fprintf(targetFile, "MOV R%d, [R%d]\n",retReg,retReg);
                        return retReg;

        // No change
        case addrNode : 
                        // change the argument to t->left for generalizing later..
                        retReg = getAddressOfIdentifier(t,targetFile);
                        return retReg;

        // No change
        case valNode :
                        fr = getReg();
                        fprintf(targetFile, "MOV R%d, %d\n",fr, t->val);
                        return fr;

        // No change
        case strNode :  
                        fr = getReg();
                        fprintf(targetFile, "MOV R%d, \"%s\"\n",fr, t->varname);
                        return fr;
                    
        // No change
        case lessNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "LT R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        // No change
        case greaterNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "GT R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        // No change
        case lessEqualNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "LE R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        // No change
        case greaterEqualNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "GE R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        // No change
        case notEqualNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "NE R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        // No change
        case equalNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        fprintf(targetFile, "EQ R%d, R%d\n", leftReg, rightReg);
                        freeReg();
                        return leftReg;

        // No change
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

        // No change
        case whileNode :
                        lb0 = getLabel();
                        lb1 = getLabel();

                        pushInStack(lb0);                   // Continue Label
                        pushInStack(lb1);                   // Break Label

                        fprintf(targetFile, "L%d :\n",lb0);
                        fr = codeGen(t->exprVal, targetFile);
                        fprintf(targetFile, "JZ R%d, L%d\n",fr,lb1);
                        freeReg();

                        leftReg = codeGen(t->left,targetFile);
                        rightReg = codeGen(t->right,targetFile);
                        fprintf(targetFile, "JMP L%d\n",lb0);
                        fprintf(targetFile, "L%d :\n",lb1);

                        popFromStack();                     // Break Label
                        popFromStack();                     // Continue Label

                        break;

        // No change
        case doWhileNode : 
                        lb0 = getLabel();
                        lb1 = getLabel();

                        pushInStack(lb0);                   // Continue Label
                        pushInStack(lb1);                   // Break Label

                        fprintf(targetFile, "L%d :\n",lb0);
                        leftReg = codeGen(t->left,targetFile);
                        rightReg = codeGen(t->right,targetFile);

                        fr = codeGen(t->exprVal, targetFile);
                        fprintf(targetFile, "JZ R%d, L%d\n",fr,lb1);
                        fprintf(targetFile, "JMP L%d\n",lb0);
                        freeReg();
                        fprintf(targetFile, "L%d :\n",lb1);

                        popFromStack();                     // Break Label
                        popFromStack();                     // Continue Label
                        
                        break;

        // No change
        case repeatUntilNode :
                        lb0 = getLabel();
                        lb1 = getLabel();

                        pushInStack(lb0);                   // Continue Label
                        pushInStack(lb1);                   // Break Label

                        fprintf(targetFile, "L%d :\n",lb0);
                        leftReg = codeGen(t->left,targetFile);
                        rightReg = codeGen(t->right,targetFile);

                        fr = codeGen(t->exprVal, targetFile);
                        fprintf(targetFile, "JNZ R%d, L%d\n",fr,lb1);
                        fprintf(targetFile, "JMP L%d\n",lb0);
                        freeReg();
                        fprintf(targetFile, "L%d :\n",lb1);

                        popFromStack();                     // Break Label
                        popFromStack();                     // Continue Label
                        
                        break;
        
        // Newly added
        case funkNode :
                        gstValue = gLookup(t->varname);
                        lst->top = gstValue->ltop;
                        lst->name = gstValue->name;
                        len1=0; len2=0;

                        // Add label for the function.
                        fprintf(targetFile, "F%d :\n",gstValue->flabel);
                        
                        //Save base pointer
                        fprintf(targetFile, "PUSH BP\n");
                        fprintf(targetFile, "MOV BP, SP\n");

                        // Address binding for local variables and parameters
                        lstValue = gstValue->ltop; i=0;
                        while(lstValue){
                            lstValue->binding = ++i;
                            len1++;
                            lstValue = lstValue->next;
                        }
                        fprintf(targetFile, "ADD SP, %d\n",len1);

                        // Finding the no of parameters
                        pl = gstValue->plist;
                        while(pl){
                            len2++;
                            pl = pl->next;
                        }

                        // Assigning values to the argument passed by the caller
                        fr = getReg();
                        pl = gstValue->plist;

                        fprintf(targetFile, "MOV R%d, BP\n", fr);
                        fprintf(targetFile, "SUB R%d, %d\n", fr,len2+2);

                        for(i=0; i<len2; i++){
                            lstValue = lLookup(pl->name);
                            r1 = getReg();
                            fprintf(targetFile, "MOV R%d, BP\n",r1);
                            fprintf(targetFile, "ADD R%d, %d\n",r1,lstValue->binding);
                            fprintf(targetFile, "MOV [R%d], [R%d]\n",r1,fr);
                            fprintf(targetFile, "INR R%d\n", fr);
                            freeReg();
                            pl = pl->next;
                        }

                        freeReg();

                        // Call left 
                        leftReg = codeGen(t->left, targetFile);
                        break;

        // Newly added
        case callerNode :
                        // Pushing registers
                        for(i=0; i<=count; i++)
                            fprintf(targetFile, "PUSH R%d\n", i);
                        pushInStack(count);                         // Pushing count

                        // Pushing arguments to program stack
                        argNode = t->arglist;
                        while(argNode){
                            fr = codeGen(argNode->left, targetFile);
                            fprintf(targetFile, "PUSH R%d\n", fr);
                            freeReg();
                            argNode = argNode->arglist;
                        }

                        // Pusing empty space for return value and calling function
                        fprintf(targetFile, "PUSH R%d\n", 0);

                        count = -1;
                        gstValue = gLookup(t->varname);
                        lb0 = gstValue->flabel;
                        fprintf(targetFile, "CALL F%d\n", lb0);

                        // Getting the return value from the function
                        fprintf(targetFile, "POP R%d\n", functionRetReg);

                        // Poping the arguments from the program stack
                        argNode = t->arglist;
                        while(argNode){
                            fprintf(targetFile, "POP R%d\n", 0);
                            argNode = argNode->arglist;
                        }

                        // Restoring the value of count
                        count = popFromStack();                     // Popping count

                        // Poping registers
                        for(i=count; i>=0; i--)
                            fprintf(targetFile, "POP R%d\n", i);
                        retReg = getReg();
                        fprintf(targetFile, "MOV R%d, R%d\n", retReg,functionRetReg);
                        
                        return retReg;

        // Newly added
        case returnNode : 
                        if(strcmp(t->varname,"main") == 0) 
                            exitFunctionCall(targetFile);
                        
                        else{
                            fr = codeGen(t->left, targetFile);
                            r1 = getReg();

                            fprintf(targetFile, "MOV SP, BP\n");
                            fprintf(targetFile, "MOV R%d, BP\n", r1);
                            fprintf(targetFile, "SUB R%d, %d\n", r1,2);
                            fprintf(targetFile, "MOV [R%d], R%d\n",r1,fr);
                            fprintf(targetFile, "MOV BP, [BP]\n");
                            fprintf(targetFile, "POP R%d\n",0);
                            fprintf(targetFile, "RET\n");

                            freeReg();    
                            freeReg();       
                        }             
                        break;

        // Newly added
        case mainNode :
                        // Function label for main
                        fprintf(targetFile, "main :\n");

                        // Setting SP and activation record of main
                        fprintf(targetFile, "PUSH BP\n"); 
                        binding++;
                        fprintf(targetFile, "MOV BP, %d\n", binding);
                        fprintf(targetFile, "MOV SP, %d\n", binding);

                        // Find gstValue and setting lst for later use
                        gstValue = gLookup(t->varname);
                        lst->top = gstValue->ltop;
                        lst->name = gstValue->name;

                        // Address binding for local variables and parameters
                        lstValue = gstValue->ltop; len1=0; i=0;
                        while(lstValue){
                            lstValue->binding = ++i;
                            ++len1;
                            lstValue = lstValue->next;
                        }
                        fprintf(targetFile, "ADD SP, %d\n",len1);

                        // Call left 
                        leftReg = codeGen(t->left, targetFile);
                        break;


        case breakNode :
                        tempValue = tos->top->val;
                        fprintf(targetFile, "JMP L%d\n",tempValue);
                        break;

        case continueNode :
                        tempValue = tos->top->next->val;
                        fprintf(targetFile, "JMP L%d\n",tempValue);
                        break;

        case emptyNode :
                        leftReg = codeGen(t->left, targetFile);
                        rightReg = codeGen(t->right, targetFile);
                        break;

    }

    return -1;
}


// Exit function call code generation
void exitFunctionCall(FILE* targetFile){
    reg_index fr = getReg();

    fprintf(targetFile, "MOV R%d, \"Exit\"\n", fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "PUSH R%d\n", fr);
    fprintf(targetFile, "CALL 0");

    freeReg();
}


// This metafunction :) this function calls all the above function and generates and assemble level code and save it in intermediate_output.xsm file.
void helperFunction(struct tnode* root){
    printf("Bravo!!\n");
    FILE* targetFile = fopen("intermediate_output.xsm","w");

    makeHeader(targetFile);
    int garbage = codeGen(root, targetFile);
    fclose(targetFile);
}