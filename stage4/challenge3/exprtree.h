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

#define ifElseNode 17
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


int varArr[26];
struct globalSymbolTable* gst;

typedef struct tnode { 
    int val;                    // value of a number for NUM nodes.
    int type;                   // type of variable
    char* varname;              // name of a variable for ID nodes or strings if it is of nodetype strNode
    int nodetype;               // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*right;  // left and right branches
    struct tnode* exprVal;      // To compute the expression value for if/else condition
    struct gsymbol* gentry; 
}tnode; 

struct gsymbol {
    char* name;             // name of the variable
    int type;               // type of the variable
    int size;               // size of the type of the variable
    int binding;            // stores the static memory address allocated to the variable
    int shape[2];           // Stores the maximum size of dimensions in 2d array
    struct gsymbol *next;
};

// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise
struct gsymbol* lookup(char* name);

// Creates a symbol table entry.
void install(char* name, int type, int shape0, int shape1);

// Pointer to the top of global symbol table
struct globalSymbolTable{
    struct gsymbol* top;
    int binding;
};

// To print the global symbol table
void printGlobalSymbolTable(void);

/*Create a node tnode*/
void validate(int nodetype, struct tnode* left, struct tnode* right, struct tnode* exprVal,struct gsymbol* gentry);
struct tnode* createTree(int val, int type, char* c, int nodetype, struct tnode *l, struct tnode *r, struct tnode* exprVal,struct gsymbol* gentry);
struct tnode* createStarNode(struct tnode* l);
struct tnode* createAddrNode(struct tnode* l);
int operatorCheck(int nodeType);
  
/*To evaluate an expression tree*/ 
// int evaluate(struct tnode *t);

void printPrefix(struct tnode* t);
void printInfix(struct tnode* t);
void printPostfix(struct tnode* t);