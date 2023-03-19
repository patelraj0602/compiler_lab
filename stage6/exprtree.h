#define idNode 0
#define readNode 1
#define emptyNode 2
#define assignNode 3 
#define addNode 4
#define mulNode 5
#define subNode 6
#define divNode 7
#define writeNode 8 
#define valNode 9  
#define noNumber 10 

#define voidType 11 
#define intType 12
#define boolType 13
#define strType 14
#define intPtrType 15 
#define strPtrType 16
#define undefined 17

#define whileNode 18
#define lessNode 19
#define greaterNode 20
#define lessEqualNode 21
#define greaterEqualNode 22
#define notEqualNode 23
#define equalNode 24
#define continueNode 25
#define breakNode 26
#define doWhileNode 27
#define repeatUntilNode 28
#define strNode 29
#define pointerNode 30
#define addrNode 31
#define ifElseNode 32
#define argsNode 33
#define callerNode 34
#define returnNode 35
#define mainNode 36
#define funkNode 37
#define andNode 38
#define orNode 39

int varArr[26];

struct paramList{
    char* name;                 // name of parameter
    int type;                   // type of parameter
    struct paramList* next;
};

struct gsymbol {
    char* name;                 // name of the variable
    int type;                   // type of the variable
    int ispointer;              // Tells whether the type data type is pointer or not
    int size;                   // size of the type of the variable
    int binding;                // stores the static memory address allocated to the variable
    int shape[2];               // Stores the maximum size of dimensions in 2d array
    struct paramList* plist;    // Points to the list of parameters of the function
    struct lsymbol* ltop;       // Points to the top of local symbol table for any particular function.
    int flabel;                 // Label number of the function
    struct gsymbol *next;
};

struct lsymbol {
    char* name;                 // name of the variable
    int type;                   // type of variable
    int ispointer;              // whether the type is pointer-type or not
    int binding;                // Address binding for this variable(At runtime)
    struct lsymbol* next;       
};

typedef struct tnode { 
    int val;                    // value of a number for NUM nodes.
    int type;                   // type of variable
    char* varname;              // name of a variable for ID nodes or strings if it is of nodetype strNode
    int nodetype;               // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*right;  // left and right branches
    struct tnode* exprVal;      // To compute the expression value for if/else condition
    struct gsymbol* gentry; 
    struct lsymbol* lentry;
    struct tnode* arglist;
}tnode; 


// Pointer to the top of global symbol table
struct globalSymbolTable{
    struct gsymbol* top;
};

// Pointer to the top of local symbol table
struct localSymbolTable{
    struct lsymbol* top;
    char* name;
};

struct globalSymbolTable* gst;                          // Pointer to the top of global symbol table
struct localSymbolTable* lst;                           // Pointer to the top of local symbol table for curring running function
/* Global variables */                                           
int binding;                                                
int curType;                                            
int fLabel; 

// Functions for paramlist
struct paramList* makeParamNode(int type, char* name, int isPointer);

//  Functions for global symbol table.
struct gsymbol* gLookup(char* name);                                                                                             // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise
void gInstall(char* name, int type, int isPointer, int shape0, int shape1, struct paramList* plist);                            // Creates a symbol table entry.
void printGlobalSymbolTable(void);                                                                                              // To print the global symbol table.

// Functions for local symbol table.
void printLocalSymbolTable(void);
struct lsymbol* makeLSymbolNode(char* name, int type, int ispointer);
struct lsymbol* lLookup(char* name);

/*Create a node tnode*/
void validate(int nodetype, struct tnode* left, struct tnode* right, struct tnode* exprVal,struct gsymbol* gentry);
struct tnode* createTree(int val, int type, char* c, int nodetype, struct tnode *l, struct tnode *r, struct tnode* exprVal,struct gsymbol* gentry, struct lsymbol* lentry, struct tnode* arglist);
struct tnode* createStarNode(struct tnode* l);                                                                                                              
struct tnode* createAddrNode(struct tnode* l);
struct tnode* createIdNode(char* name, struct tnode* left, struct tnode* right);
struct tnode* createArgsNode(struct tnode* left);
struct tnode* createCallerNode(char* name, struct tnode* arglist);
struct tnode* createReturnNode(char* name, struct tnode* left);
struct tnode* createMainNode(char* name, struct tnode* left);
struct tnode* createFunkNode(char* name, struct tnode* left);
int operatorCheck(int nodeType);
  
/*To evaluate an expression tree*/ 
// int evaluate(struct tnode *t);

void printPrefix(struct tnode* t);
void printInfix(struct tnode* t);
void printPostfix(struct tnode* t);