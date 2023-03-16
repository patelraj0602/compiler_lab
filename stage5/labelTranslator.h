struct labelNode{
    char* labelName;
    int address;
    struct labelNode* next;
};

struct labelAddressTable{
    struct labelNode* head;
};

void addLabel(struct labelAddressTable* top, char* labelName, int address);
int searchLabel(struct labelAddressTable* top, char* labelName); 
void printLabelAddressTable(struct labelAddressTable* top);  