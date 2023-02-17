// #include <stdio.h>
// #include <string.h>
// #include "labelTranslator.h"

void addLabel(struct labelAddressTable* top, char* labelName, int address){

    /* add 0 to the end of string */
    int len = strlen(labelName);
    *(labelName+len-3) = '\0';

    // printf("%s %d\n",labelName,address);

    struct labelNode* node = (struct labelNode*)malloc(sizeof(struct labelNode));

    node->labelName = labelName;
    node->address = address;
    node->next = NULL;
 
    // Add the new node the head of linked list
    node->next = top->head;
    top->head = node;
    return;
}

// this will return the address of the corresponding label
int searchLabel(struct labelAddressTable* top, char* labelName){
    // Find and return the corresponding address
    int len = strlen(labelName);
    *(labelName+len-1) = '\0';

    struct labelNode* temp = top->head;
    while(temp){
        if(strcmp(temp->labelName,labelName) == 0){
            return temp->address;
        }
        temp = temp->next;
    }   
    return -1;
}

void printLabelAddressTable(struct labelAddressTable* top){
    printf("Printing all labels\n");
    struct labelNode* temp = top->head;
    while(temp){
        printf("%s %d\n",temp->labelName,temp->address);
        temp = temp->next;
    }
    printf("Finished\n");
}