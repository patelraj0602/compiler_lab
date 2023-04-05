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

// #define voidType 11 
// #define intType 12
// #define boolType 13
// #define strType 14
// #define intPtrType 15 
// #define strPtrType 16
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
#define fieldNode 40              // User defined datatype node
#define dotOperatorNode 41
#define allocNode 42
#define initNode 43
#define freeNode 44
#define nullNode 45
#define selfNode 46
#define definedDone 47

int varArr[26];

// attribute list for class
struct attrList{
    char* name;                         // name of the field
    int findex;                         // position of the field
    struct typeTable* type;             // pointer to the type table
    struct classTable* ctype;           // pointer to the class containing the field
    struct attrList* next;              // pointer to next fieldlist entry;
};

// member function list for class
struct memberFuncList{
    char* name;                         // name of the member function in the class
    struct typeTable* type;             // This is return type of member function
    struct paramList* plist;            // pointer to the head of the formal parmeter list
    struct lsymbol* ltop;               // pointer to the top of local symbol table.
    int funcpos;                        // position of the function in the class table
    int flabel;                         // a label for identifying the starting address of the function's code in the memory
    struct memberFuncList* next;        // Pointer to the next memberfunclist entry
};

// For class table: For storing used defined classes
struct classTable{
    char* name;                         // name of the class
    struct attrList* memfield;          // Pointer to fieldList
    struct memberFuncList* vfuncptr;    // Pointer to the member func list
    struct classTable* parentptr;       // Pointer to the parent's class table
    int classindex;                     // Position of the class in the virtual function table
    int attrcount;                      // count of fields
    int methodcount;                    // count of methods
    struct classTable* next;            // Pointer to the next class entry
};


// For type table: It basically stores basic types and user defined types
struct typeTable{
    char* name;                 // Name of the type
    int size;                   // Size of the type
    struct fieldList* fields;   // Pointer to the head of fields list
    struct typeTable* next;     // Pointer to the next type table entry;
};

struct typeTableList{
    struct typeTable* top;
};

// For fieldList of an user-defined type(struct)
struct fieldList{
  char *name;                   //name of the field
  int findex;                   //the position of the field in the field list
  struct typeTable *type;       //pointer to type table entry of the field's type
  struct fieldList *next;       //pointer to the next field
};

// paramList for function arguments
struct paramList{
    char* name;                 // name of parameter
    struct typeTable* type;     // type of parameter
    struct paramList* next;
};

// To change: add pointer the the class table attribute in this
// global symbol table
struct gsymbol {
    char* name;                 // name of the variable
    struct typeTable* type;     // type of the variable
    struct classTable* ctype;   // pointer to the entry in class table i.e. name of class
    int ispointer;              // Tells whether the type data type is pointer or not
    int size;                   // size of the type of the variable
    int binding;                // stores the static memory address allocated to the variable
    int shape[2];               // Stores the maximum size of dimensions in 2d array
    struct paramList* plist;    // Points to the list of parameters of the function
    struct lsymbol* ltop;       // Points to the top of local symbol table for any particular function.
    int flabel;                 // Label number of the function
    int status;                 // helper to determined wheter the type and ctype are defined or undefined
    struct gsymbol *next;
};

// local symbol table
struct lsymbol {
    char* name;                 // name of the variable
    struct typeTable* type;     // type of variable
    int ispointer;              // whether the type is pointer-type or not
    int binding;                // Address binding for this variable(At runtime)
    struct lsymbol* next;       
};

// tree node
typedef struct tnode { 
    int val;                    // value of a number for NUM nodes.
    struct typeTable* type;     // type of variable
    char* varname;              // name of a variable for ID nodes or strings if it is of nodetype strNode
    int nodetype;               // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*right;  // left and right branches
    struct tnode* exprVal;      // To compute the expression value for if/else condition
    struct gsymbol* gentry; 
    struct lsymbol* lentry;
    struct tnode* arglist;

    // Few data structures to support class
    struct classTable* ctype;
    struct paramList* plist;
    struct methodFuncList* mlist;
}tnode; 


// Pointer to the top of global symbol table
struct globalSymbolTable{
    struct gsymbol* top;
};

// Pointer to the top of local symbol table
struct localSymbolTable{
    struct lsymbol* top;
    struct typeTable* type;
    char* name;
};

// Pointer to the top of class table
struct classTableList{
    struct classTable* top;
};

struct globalSymbolTable* gst;                          // Pointer to the top of global symbol table
struct localSymbolTable* lst;                           // Pointer to the top of local symbol table for curring running function
struct typeTableList* ttt;                              // Pointer to the top of type table list
struct classTableList* ctt;                             // Pointer to the top of class table

/* Global variables */                                           
int binding;                                                
int curType;                                            
int fLabel; 
char* curClass;

// Associated methods of class table
void cInstall(char* name, char* parentName);
struct classTable* cLookup(char* name);
void classAttrInstall(char* cname, char* typename, char* fieldname);
void classMemInstall(char* cname, char* fname, char* type, struct paramList* plist);
struct memberFuncList* classMemLookup(char* cname, char* fname);
struct attrList* classAttrLookup(char* cname, char* aname);

// Functions for paramlist
struct paramList* makeParamNode(struct typeTable* type, char* name, int isPointer);

//  Functions for global symbol table.
struct gsymbol* gLookup(char* name);                                                                                             // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise
void gInstall(char* name, struct typeTable* type, int isPointer, int shape0, int shape1, struct paramList* plist);                            // Creates a symbol table entry.

// Functions for local symbol table.
struct lsymbol* makeLSymbolNode(char* name, struct typeTable* type, int ispointer);
struct lsymbol* lLookup(char* name);

// Function for type table and fieldList
void createTypeTable(void);                                                                                                     // Initializes the type table with default and special data types
struct typeTable* tLookup(char* name);                                                                                          // Find the type table entry corresponding to any particular name of data type.
void tInstall(char* name, int size, struct fieldList* fields);                                                                  // Installs an new entry into type table
struct fieldList* fLookup(struct typeTable* type, char* name);                                                                         // Searches for a field of give name in the fieldlist of the user-defined type
int getSize(struct typeTable* type);                                                                                                   // Return the amount of memory words required to store a variable of the given type.  
struct fieldList* makeFieldNode(char* name, struct typeTable* type);

/*Create a node tnode*/
void validate(int nodetype, struct tnode* left, struct tnode* right, struct tnode* exprVal,struct gsymbol* gentry);
struct tnode* createTree(int val, struct typeTable* type, char* c, int nodetype, struct tnode *l, struct tnode *r, 
struct tnode* exprVal,struct gsymbol* gentry, struct lsymbol* lentry, struct tnode* arglist, struct classTable* ctype,struct paramList* plist);
struct tnode* createStarNode(struct tnode* l);                                                                                                              
struct tnode* createAddrNode(struct tnode* l);
struct tnode* createIdNode(char* name, struct tnode* left, struct tnode* right);
struct tnode* createArgsNode(struct tnode* left);
struct tnode* createCallerNode(char* name, struct tnode* arglist);
struct tnode* createReturnNode(struct typeTable* type, struct tnode* left, char* name);
struct tnode* createMainNode(char* name, struct tnode* left);
struct tnode* createFunkNode(char* name, struct tnode* left);
struct tnode* createMethodFunkNode(char* fname, struct tnode* left);
struct tnode* makeDotOperatorNode1(char* n1, char* n2);
struct tnode* makeDotOperatorNode2(struct tnode* left, char* r);
struct tnode* makeAllocNode(struct tnode* left);
struct tnode* makeMemInitNode(void);
struct tnode* makeFreeNode(struct tnode* left);
struct tnode* makeNullNode();
struct tnode* makeMethodNode1(char* fname, struct tnode* arglist);
struct tnode* makeMethodNode2(char* objname, char* fname, struct tnode* arglist);
struct tnode* makeMethodNode3(struct tnode* left, char* fname, struct tnode* arglist);
struct tnode* makeConnectorNode(struct tnode* left, struct tnode* right);
int operatorCheck(int nodeType);
  
// Printing different datastructures
void printGlobalSymbolTable(void);                                                                                              // To print the global symbol table.
void printLocalSymbolTable(void);
void printTypeTable(void);
void printClassTable(void);

/*To evaluate an expression tree*/ 
// int evaluate(struct tnode *t);

void printPrefix(struct tnode* t);
void printInfix(struct tnode* t);
void printPostfix(struct tnode* t);