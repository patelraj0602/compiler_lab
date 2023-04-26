// Comment the #include files before executing the code
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h> 
// #include "exprtree.h"

/*
/ assignNode : You can only do assignment if both side have same type. 
But notice an intresting edge case here => if(a=b) <== ;In this case my parser will make an node "=" in expression tree.
To avoid this from happening simpl remove assignNode from the below list.
*/
int operatorCheck(int nodeType){
    return (nodeType == addNode || nodeType == subNode || nodeType == mulNode   
    || nodeType == divNode || nodeType == greaterNode 
    || nodeType == lessNode || nodeType == greaterEqualNode || nodeType == lessEqualNode    
    || nodeType == equalNode || nodeType == notEqualNode);
}

void validate(int nodetype, struct tnode* left, struct tnode* right, struct tnode* exprVal,struct gsymbol* gentry){
    if(nodetype == equalNode || nodetype == notEqualNode){
        // For null node
        if(right->type == tLookup("null")){
            if((left->type == tLookup("int"))||(left->type == tLookup("str"))||(left->type == tLookup("bool"))||(left->type == tLookup("void")))
                yyerror("null is only compatible with pointer data types!!");
        }
        else if((left->type != tLookup("int"))||(right->type != tLookup("int")))
            yyerror("Integer type mismatch !!");
    }
    else if(operatorCheck(nodetype) && ((left->type != tLookup("int"))||(right->type != tLookup("int"))))
        yyerror("Integer type mismatch !!");
    else if(nodetype == assignNode){
        // For null node
        if(right->type == tLookup("null")){
            if((left->type == tLookup("int"))||(left->type == tLookup("str")))
                yyerror("null is only compatible with pointer data types!!");
        }
        else if(left->type != right->type)
            yyerror("type mismatch while assigning !!");   
    }
    else if((nodetype == ifElseNode) && (exprVal->type != tLookup("bool")))
        yyerror("Invalid expression for if/else condition !!");
    else if((nodetype == writeNode) && (left->type == tLookup("bool")))
        yyerror("Invalid expression inside write system call !!");
    else if(((nodetype==whileNode)||(nodetype==doWhileNode)||(nodetype==repeatUntilNode)) && (exprVal->type != tLookup("bool")))
        yyerror("Invalid expression inside looping construct !!");
    else if((nodetype == andNode || nodetype == orNode) && ((left->type != tLookup("bool"))||(right->type != tLookup("bool"))))
        yyerror("type mismatch !!");
    else if(nodetype == idNode){
        // id[a][b] (a and b cannot be of boolean type) AND (a and b must be within bound) 
        if((left)&&(left->type == tLookup("bool"))) yyerror("Invalid expression inside identifier !!");
        if((right)&&(right->type == tLookup("bool"))) yyerror("Invalid expression inside identifier !!");

        if((!left)&&(!right)){
            if((gentry->shape[0])||(gentry->shape[1])) yyerror("The identifier not matching with declaration !!");
        }
        else if((left)&&(!right)){
            if((!gentry->shape[0])||(gentry->shape[1])) yyerror("The identifier not matching with declaration !!");
            // The below check must be done at runtime
            // if(left->val >= gentry->shape[0]) yyerror("Program trying to access out of the bound in an 1d array !!");
        }
        else if((left)&&(right)){
            if((!gentry->shape[0])||(!gentry->shape[1])) yyerror("The identifier not matching with declaration !!");
            // The below check must be done at runtime
            // if((left->val >= gentry->shape[0])||(right->val >= gentry->shape[1])) yyerror("Program trying to access out of bound in an 2d array !!");
        }
    }
    else if((nodetype == pointerNode)&&((left->type != tLookup("intPtr"))&&(left->type != tLookup("strPtr"))))
        yyerror("Attempt to dereference a non-pointer variable !!");
    
}

struct tnode* createTree(int val, struct typeTable* type, char* c, int nodetype, struct tnode *left, struct tnode *right, 
    struct tnode* exprVal,struct gsymbol* gentry, struct lsymbol* lentry,struct tnode* arglist, struct classTable* ctype,
    struct paramList* plist){

    if(nodetype != idNode){
        validate(nodetype,left,right,exprVal,gentry);    
    }

    struct tnode* temp =  (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->varname = c;
    temp->nodetype = nodetype;
    temp->left = left;  
    temp->right = right;
    temp->exprVal = exprVal;
    temp->gentry = gentry;
    temp->lentry = lentry;
    temp->arglist = arglist;
    temp->ctype = ctype;
    temp->plist = plist;
    return temp;
}

// Making and * node for "* ID" type of expressions 
struct tnode* createStarNode(struct tnode* l){
    validate(pointerNode,l,NULL,NULL,NULL);

    struct typeTable* type;
    if(l->type == tLookup("intPtr")) type = tLookup("int");
    else if(l->type == tLookup("strPtr")) type = tLookup("str");
    else yyerror("You can only dereference an intptr or strptr !!\n");

    return createTree(noNumber,type,NULL,pointerNode,l,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}


// Making & node for expression like "& identifier"
struct tnode* createAddrNode(struct tnode* l){

    struct typeTable* type;
    if(l->type == tLookup("int")) type = tLookup("intPtr");
    else if(l->type == tLookup("str")) type = tLookup("strPtr");
    else yyerror("Pointers are supported only for int and str !!\n");
    return createTree(noNumber,type,NULL,addrNode,l,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createIdNode(char* name, struct tnode* left, struct tnode* right){
    struct lsymbol* lEntry = lLookup(name);
    struct gsymbol* gEntry = gLookup(name);

    if((!lEntry)&&(!gEntry)) yyerror("Identifier not found in global symbol table and local symbol table !!\n");

    // If the id is present in lst
    if((lEntry)&&(left||right)) yyerror("The identifier is not of array type !!");
    // If the id is present in gst and not in lst
    if((!lEntry)&&(gEntry)) {
        validate(idNode,left,right,NULL,gEntry);
    }
    
    struct typeTable* type;
    struct classTable* ctype;
    if(lEntry){
        type = lEntry->type;
        ctype = NULL;
    }else{
        type = gEntry->type;
        ctype = gEntry->ctype;
    }
    return createTree(noNumber,type,name,idNode,left,right,NULL,gEntry,lEntry,NULL,ctype,NULL);
    // struct typeTable* type = lEntry ? lEntry->type : gEntry->type;
    // return createTree(noNumber,type,name,idNode,left,right,NULL,gEntry,lEntry,NULL,NULL,NULL); 
}

struct tnode* createArgsNode(struct tnode* left){
    // According to language specification the function cannot have object as return type
    struct typeTable* type = left->type;
    return createTree(noNumber,type,NULL,argsNode,left,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createCallerNode(char* name, struct tnode* arglist){
    struct gsymbol* gnode = gLookup(name);
    if(!gnode) yyerror("The caller function not found in global symbol table");

    struct paramList* pl = gnode->plist;
    struct tnode* ag = arglist;

    while(pl || ag){
        if((!pl)||(!ag)) yyerror("No of arguments of caller and calle does not match !!");

        // Type Checking
        if(ag->type == tLookup("null")){
            if((pl->type)==tLookup("int")||(pl->type)==tLookup("str"))
                yyerror("Type mismatch of the arguments between caller and calle function !!");
        }
        else if(pl->type != ag->type) yyerror("Type mismatch of the arguments between caller and calle function !!");
        pl = pl->next;
        ag = ag->arglist;
    }

    // The type of the caller node is return type of function
    return createTree(gnode->flabel,gnode->type,name,callerNode,NULL,NULL,NULL,NULL,gnode->ltop,arglist,NULL,NULL);
}

struct tnode* createReturnNode(struct typeTable* type, struct tnode* left, char* name){
    // Type Checking
    if(left->type == tLookup("null")){
        if(type==tLookup("int")||type==tLookup("str"))
            yyerror("Return type of declaration does not match with initialization !!\n");
    }
    else if(type != left->type) yyerror("Return type of declaration does not match with initialization !!\n");
    return createTree(noNumber,tLookup("void"),name,returnNode,left,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createMainNode(char* name, struct tnode* left){
    struct gsymbol* gnode = gLookup(name);
    return createTree(noNumber,tLookup("void"),name,mainNode,left,NULL,NULL,NULL,gnode->ltop,NULL,NULL,NULL);
}

struct tnode* createFunkNode(char* name, struct tnode* left){
    struct gsymbol* gnode = gLookup(name);
    return createTree(gnode->flabel,tLookup("void"),name,funkNode,left,NULL,NULL,NULL,gnode->ltop,NULL,NULL,gnode->plist);
}

struct tnode* createMethodFunkNode(char* fname, struct tnode* left){
    struct memberFuncList* mem = classMemLookup(curClass, fname);
    return createTree(mem->flabel,tLookup("void"),fname,funkNode,left,NULL,NULL,NULL,mem->ltop,NULL,NULL,mem->plist);
}

struct tnode* makeDotOperatorNode1(char* n1, char* n2){
    struct lsymbol* lEntry = lLookup(n1);
    struct gsymbol* gEntry = gLookup(n1);

    if((lEntry==NULL)&&(gEntry==NULL)) yyerror("Identifier not declared!!");
    
    if((gEntry)&&(gEntry->ctype))
        yyerror("The attribute of the class cannot be accessed from outside of the class !!\n");

    // Identified an user defined data type
    struct typeTable* type = lEntry ? lEntry->type : gEntry->type;
    struct fieldList* field = type->fields;
    while(field){
        if(strcmp(field->name,n2)==0){
            struct tnode* left;
            if(lEntry) left = createTree(noNumber,type,n1,idNode,NULL,NULL,NULL,NULL,lEntry,NULL,NULL,NULL);
            else left = createTree(noNumber,type,n1,idNode,NULL,NULL,NULL,gEntry,NULL,NULL,NULL,NULL);

            struct tnode* right = createTree(field->findex,field->type,n2,fieldNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
            return createTree(noNumber,field->type,".",dotOperatorNode,left,right,NULL,NULL,NULL,NULL,NULL,NULL);
        }
        field = field->next;
    }
    yyerror("No matching field for the given identifier!!");
    return NULL;
}

/* NOTE: Change this to support concatination of classes attributes too */
/* Simply need to give attribute->ctype with an attribute name: therefore changing ctype and name fields*/
/* Probably do the above things for right tnode also. */
struct tnode* makeDotOperatorNode2(struct tnode* left, char* r){
    // For supporting concatination of class fields
    if(left->ctype){
        struct classTable* ctype = left->ctype;
        struct attrList* attribute = classAttrLookup(ctype->name, r);
        if(!attribute) 
            yyerror("attribute not present in field list of class !!\n");
        
        struct tnode* right = createTree(attribute->findex,attribute->type,NULL,fieldNode,NULL,NULL,NULL,NULL,NULL,NULL,attribute->ctype,NULL);
        return createTree(noNumber,attribute->type,NULL,dotOperatorNode,left,right,NULL,NULL,NULL,NULL,attribute->ctype,NULL);
    }
    // To support concatination of user defined types
    else{
        struct typeTable* type = left->type;
        struct fieldList* field = type->fields;
        while(field){
            if(strcmp(field->name,r)==0){
                struct tnode* right = createTree(field->findex,field->type,r,fieldNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
                return createTree(noNumber,field->type,".",dotOperatorNode,left,right,NULL,NULL,NULL,NULL,NULL,NULL);
            }
            field = field->next;
        }
        yyerror("No matching field for the given identifier!!");
        return NULL;
    }
}

/* NOTE: Change this to support concatination of classes attributes too */
/* Simply need to give attribute->ctype with an attribute name: therefore changing ctype and name fields*/
/* Probably do the above things for right tnode also. */
struct tnode* makeDotOperatorNode3(char* attr){
    struct attrList* attribute = classAttrLookup(curClass,attr);
    if(!attribute) 
        yyerror("attribute not present in field list of class !!\n");

    struct tnode* left = createTree(noNumber,tLookup("void"),NULL,selfNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct tnode* right = createTree(attribute->findex,attribute->type,NULL,fieldNode,NULL,NULL,NULL,NULL,NULL,NULL,attribute->ctype,NULL);
    return createTree(noNumber,attribute->type,NULL,dotOperatorNode,left,right,NULL,NULL,NULL,NULL,attribute->ctype,NULL);
}

struct tnode* makeAllocNode(struct tnode* left){
    if((left->type == tLookup("int"))||(left->type == tLookup("intPtr"))||(left->type == tLookup("str"))||(left->type == tLookup("strPtr")))
        yyerror("Expected an user defined type for alloc !!");
    return createTree(noNumber,tLookup("void"),NULL,allocNode,left,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* makeMemInitNode(void){
    return createTree(noNumber,tLookup("void"),NULL,initNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* makeFreeNode(struct tnode* left){
    if((left->type == tLookup("int"))||(left->type == tLookup("intPtr"))||(left->type == tLookup("str"))||(left->type == tLookup("strPtr")))
        yyerror("Expected an user defined type for freeing identifier !!");
    return createTree(noNumber,tLookup("void"),NULL,freeNode,left,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* makeConnectorNode(struct tnode* left, struct tnode* right){
    return createTree(noNumber,tLookup("void"),NULL,emptyNode,left,right,NULL,NULL,NULL,NULL,NULL,NULL);
}

struct tnode* makeNullNode(){
    return createTree(0,tLookup("null"),NULL,nullNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}

// Some hardcoding is present in this 3 different method node function: Change it later.
struct tnode* makeMethodNode1(char* fname, struct tnode* arglist){
    struct memberFuncList* mnode = classMemLookup(curClass,fname);
    if(!mnode) yyerror("Method not found for the specified class\n");

    struct paramList* pl = mnode->plist;
    struct tnode* ag = arglist;

    while(pl||ag){
        if((!pl)||(!ag)) 
            yyerror("No of argument mismatch between declaration and initialization of method of an class !!\n");
        //Type Checking
        if(ag->type == tLookup("null")){
            if((pl->type)==tLookup("int")||(pl->type)==tLookup("str"))
                yyerror("Type mismatch of the arguments between caller and calle of the method of an class!!\n");
        }
        else if(pl->type != ag->type)
            yyerror("Type mismatch of the arguments between caller and calle of the method of an class!!\n");
        pl = pl->next;
        ag = ag->arglist;
    }

    struct tnode* left = createTree(noNumber,tLookup("void"),NULL,selfNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

    // Adding function position number in the number field to utilize it later.
    return createTree(mnode->funcpos,mnode->type,mnode->name,callerNode,left,NULL,NULL,NULL,mnode->ltop,arglist,NULL,mnode->plist);
}

struct tnode* makeMethodNode2(char* objname, char* fname, struct tnode* arglist){
    // Extracting the class name for the object
    struct gsymbol* gnode = gLookup(objname);
    char* cname = gnode->ctype->name;
    struct memberFuncList* mnode = classMemLookup(cname,fname);

    if(!mnode) yyerror("Method not found for the specified class\n");

    struct paramList* pl = mnode->plist;
    struct tnode* ag = arglist;

    while(pl||ag){
        if((!pl)||(!ag)) 
            yyerror("No of argument mismatch between declaration and initialization of method of an class !!\n");
        //Type Checking
        if(ag->type == tLookup("null")){
            if((pl->type)==tLookup("int")||(pl->type)==tLookup("str"))
                yyerror("Type mismatch of the arguments between caller and calle of the method of an class!!\n");
        }
        else if(pl->type != ag->type)
            yyerror("Type mismatch of the arguments between caller and calle of the method of an class!!\n");
        pl = pl->next;
        ag = ag->arglist;
    }

    struct tnode* left = createTree(noNumber,NULL,NULL,idNode,NULL,NULL,NULL,gLookup(objname),NULL,NULL,NULL,NULL);
    
    // Adding function position number in the number field to utilize it later.
    return createTree(mnode->funcpos,mnode->type,mnode->name,callerNode,left,NULL,NULL,NULL,mnode->ltop,arglist,NULL,mnode->plist);
}

struct tnode* makeMethodNode3(struct tnode* left, char* fname, struct tnode* arglist){
    char* cname = left->ctype->name;
    struct memberFuncList* mnode = classMemLookup(cname,fname);

    if(!mnode) yyerror("Method not found for specified class\n");
    struct paramList* pl = mnode->plist;
    struct tnode* ag = arglist;

    while(pl||ag){
        if((!pl)||(!ag)) 
            yyerror("No of argument mismatch between declaration and initialization of method of an class !!\n");
        //Type Checking
        if(ag->type == tLookup("null")){
            if((pl->type)==tLookup("int")||(pl->type)==tLookup("str"))
                yyerror("Type mismatch of the arguments between caller and calle of the method of an class!!\n");
        }
        else if(pl->type != ag->type)
            yyerror("Type mismatch of the arguments between caller and calle of the method of an class!!\n");
        pl = pl->next;
        ag = ag->arglist;
    }
    
    // Adding function position number in the number field to utilize it later.
    return createTree(mnode->funcpos,mnode->type,mnode->name,callerNode,left,NULL,NULL,NULL,mnode->ltop,arglist,NULL,mnode->plist);
}

// Only parent variable can refer child object
int isParent(char* parent, char* child){
    struct classTable* cc = cLookup(child);
    while(cc){
        if(strcmp(cc->name, parent)==0) return 1;
        cc = cc->parentptr;
    }
    return 0;
}

// Harcoding so that it works only for new statements in main.
struct tnode* makeNewNode(struct tnode* left, char* cname){
    struct classTable* cEntry = left->ctype;
    if(!cLookup(cname)) yyerror("Dynamic allocation using new keyword can only be used for classes !!\n");
    if(!cEntry) yyerror("identifier is not an object of class. New key cannot be used !!\n");
    if(!isParent(cEntry->name, cname)) yyerror("Child object can only be referred by its parent!!\n");

    struct classTable* ctype = cLookup(cname);
    int virFunTableAddr = 4096+(ctype->classindex)*8;

    return createTree(virFunTableAddr,tLookup("void"),NULL,newKeyWordNode,left,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}

// INITIALIZING FUNCTIONS.


/* Functions related to class table, member functions and attribute list */
struct classTable* cLookup(char* name){
    if(name == NULL) return NULL;                           // Small fix
    struct classTable* top = ctt->top;
    while(top){
        if(strcmp(top->name,name)==0) return top;
        top = top->next;
    }
    return NULL;
} 

void cInstall(char* name, char* parentName){
    if(cLookup(name)) yyerror("Multiple class with same name !!\n");
    else if(tLookup(name)) yyerror("Class name conflicting already declared user defined type !!\n");

    struct classTable* newEntry = (struct classTable*) malloc(sizeof(struct classTable));
    struct classTable* ptnode = cLookup(parentName);

    newEntry->name = name;
    newEntry->parentptr = ptnode;
    newEntry->attrcount = ptnode ? ptnode->attrcount : 0;
    newEntry->methodcount = ptnode ? ptnode->methodcount : 0;
    newEntry->next = NULL;

    // copy the memfield of parent class to the current class
    struct attrList* alist = ptnode ? ptnode->memfield : NULL;
    struct attrList* pre = NULL; struct attrList* top = NULL;
    while(alist){
        struct attrList* newattr = (struct attrList*) malloc(sizeof(struct attrList));
        memcpy(newattr,alist,sizeof(*newattr));
        if(!pre) {
            pre = newattr;
            top = newattr;
        }else{
            pre->next = newattr;
            pre = pre->next;
        }
        alist = alist->next;
    }
    newEntry->memfield = top;

    // copy methods of parent class to current class
    struct memberFuncList* mlist = ptnode ? ptnode->vfuncptr : NULL;
    struct memberFuncList* pre1 = NULL; struct memberFuncList* top1 = NULL;
    while(mlist){
        struct memberFuncList* newmethod = (struct memberFuncList*) malloc(sizeof(struct memberFuncList));
        memcpy(newmethod,mlist,sizeof(*newmethod));
        if(!pre1) {
            pre1 = newmethod;
            top1 = newmethod;
        }else{
            pre1->next = newmethod;
            pre1 = pre1->next;
        }
        mlist = mlist->next;
    }
    newEntry->vfuncptr = top1;

    // Adding the newly formed class node at the end of list
    struct classTable* temp = ctt->top;
    int classindex = 1;
    if(!temp) {
        newEntry->classindex = 0;
        ctt->top = newEntry;
    }else{
        while(temp->next) {
            temp=temp->next;
            classindex += 1;
        }
        newEntry->classindex = classindex;
        temp->next = newEntry;
    }
}

struct attrList* classAttrLookup(char* cname, char* aname){
    struct classTable* ctype = cLookup(cname);
    if(!ctype) yyerror("No such class name found; error while executing classAttrLookup function");
 
    struct attrList* alist = ctype->memfield;
    while(alist){
        if(strcmp(alist->name,aname)==0) return alist;
        alist = alist->next;
    }
    return NULL;
}

void classAttrInstall(char* cname, char* typename, char* aname){
    if(classAttrLookup(cname,aname))
        yyerror("Attribute of the parent class cannot be overwritten");

    // Else add the attribute to the attribute list at the end of list
    struct attrList* newEntry = (struct attrList*) malloc(sizeof(struct attrList));
    newEntry->name = aname;
    newEntry->findex = undefined;
    newEntry->type = tLookup(typename);
    newEntry->ctype = cLookup(typename);
    newEntry->next = NULL;

    struct classTable* ctype = cLookup(cname);
    struct attrList* alist = ctype->memfield;
    
    // If attribute list is empty, then
    if(!alist){
        newEntry->findex = 0;
        ctype->memfield = newEntry;
    }
    else{
        int ind=1;
        while(alist->next){
            alist=alist->next;
            ind += 1;
        }
        newEntry->findex = alist->ctype ? alist->findex + 2 : alist->findex + 1;
        alist->next = newEntry;
    }
    ctype->attrcount += 1;

    if(newEntry->findex >= 8) 
        yyerror("Too many field for the given class!! Only 1 block of heap is allocated per class!!\n");
}

struct memberFuncList* classMemLookup(char* cname, char* fname){
    struct classTable* ctype = cLookup(cname);
    if(!ctype) yyerror("No such class name found; error while executing classMemLookup function");

    struct memberFuncList* memList = ctype->vfuncptr;
    while(memList){
        if(strcmp(memList->name,fname)==0) return memList;
        memList = memList->next;
    }
    return NULL;
}

// Assuming that the same class won't have multiple functions with same name
void classMemInstall(char* cname, char* fname, char* type, struct paramList* plist){
    struct memberFuncList* mlist = classMemLookup(cname, fname);
    if(mlist){
        // overridden function
        mlist->name = fname;
        mlist->type = tLookup(type);
        mlist->plist = plist;
        mlist->ltop = NULL;
        mlist->flabel = ++fLabel;
    }
    else{
        // Join the new method to the end of list now.
        struct memberFuncList* newEntry = (struct memberFuncList*) malloc(sizeof(struct memberFuncList));
        newEntry->name = fname;
        newEntry->type = tLookup(type);
        newEntry->plist = plist;
        newEntry->ltop = NULL;
        newEntry->flabel = ++fLabel;
        newEntry->next = NULL;

        struct classTable* ctype = cLookup(cname);
        struct memberFuncList* mtop = ctype->vfuncptr;
        
        // If member function list is empty
        if(!mtop){
            newEntry->funcpos = 0;
            ctype->vfuncptr = newEntry;
        }
        else{
            int ind=1;
            while(mtop->next){
                mtop = mtop->next;
                ind += 1;
            }
            newEntry->funcpos = ind;
            mtop->next = newEntry;
        }
        ctype->methodcount += 1;
    }
}

int getClassTableSize(){
    struct classTable* tp = ctt->top;
    int size = 0;
    while(tp){
        size++;
        tp = tp->next;
    }
    return size;
}

void printClassTable(void){
    struct classTable* top = ctt->top;
    while(top){
        printf("Class: %s, index: %d\n", top->name, top->classindex);

        printf("\nField list: %d\n", top->attrcount);
        struct attrList* alist = top->memfield;
        while(alist){
            printf("Name: %s, findex: %d, ",alist->name, alist->findex);
            alist->type ? printf("type: %s, ",alist->type->name) : printf("type: null, ");
            alist->ctype ? printf("ctype: %s, \n",alist->ctype->name) : printf("ctype: null\n");
            alist = alist->next;
        }
        
        printf("\nMethod list: %d\n", top->methodcount);
        struct memberFuncList* mlist = top->vfuncptr;
        while(mlist){
            printf("Name: %s, flabel: %d, type: %s, funcpos: %d\n",mlist->name, mlist->flabel,mlist->type->name,mlist->funcpos);

            printf("=>Local symbol table for the method\n");
            struct lsymbol* ls = mlist->ltop;
            while(ls){
                printf("Name: %s, type: %s\n",ls->name,ls->type->name);
                ls = ls->next;
            }

            printf("=>Parameter list for the method\n");
            struct paramList* plist = mlist->plist;
            while(plist){
                printf("Name: %s, type: %s\n",plist->name,plist->type->name);
                plist = plist->next;
            }
            printf("\n");


            mlist = mlist->next;
        }
        printf("\n\n");
        top = top->next;
    }
}



/*Functions related to global symbol table */
// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise
struct gsymbol* gLookup(char* name){
    // Update : Variables and functions can have same identifier name ..
    struct gsymbol* top = gst->top;
    while(top){
        if(strcmp(top->name,name) == 0) return top;
        top = top->next; 
    }
    return NULL;
}

void gInstall(char* name, struct typeTable* type, int ispointer, int shape0, int shape1, struct paramList* plist){
    if(gLookup(name)!=NULL)
        yyerror("Multiple variables with same name found");

    struct gsymbol* newEnty = (struct gsymbol*) malloc(sizeof(struct gsymbol));  

    newEnty->name = name;
    newEnty->type = type;
    newEnty->ctype = NULL;
    newEnty->ispointer = ispointer;
    newEnty->size = (shape0?shape0:1)*(shape1?shape1:1);
    newEnty->shape[0] = shape0;
    newEnty->shape[1] = shape1;
    newEnty->plist = plist;
    newEnty->ltop = NULL;
    newEnty->flabel = -1;
    newEnty->ltop = NULL;
    newEnty->next = NULL; 
    newEnty->status = undefined;

    newEnty->next = gst->top;
    gst->top = newEnty;      
}

// To print the global symbol table
void printGlobalSymbolTable(void){
    printf("Presenting global symbol table \n");

    struct gsymbol* top = gst->top;
    while(top){
        printf("name: %s, size: %d, binding: %d, shape : %d %d, flabel : %d,",top->name,top->size,top->binding,top->shape[0],top->shape[1],top->flabel);
        top->ctype ? printf(" ctype: %s,",top->ctype->name) : printf(" ctype: null,");
        top->type ? printf(" type: %s\n",top->type->name) : printf(" type: null\n");
        top = top->next;
    }
}


/* Functions related to local symbol table */
struct lsymbol* makeLSymbolNode(char* name, struct typeTable* type, int ispointer){
    struct lsymbol* newEntry = (struct lsymbol*) malloc(sizeof(struct lsymbol));
    newEntry->name = name;
    newEntry->type = type;
    newEntry->ispointer = ispointer;
    newEntry->binding = undefined;
    newEntry->next = NULL;
    return newEntry;
}

struct lsymbol* lLookup(char* name){
    struct lsymbol* top = lst->top;
    while(top){
        if(strcmp(top->name,name) == 0) return top;
        top = top->next; 
    }
    return NULL;
}

void printLocalSymbolTable(void){
    struct gsymbol* top = gst->top;
    while(top){
        if(top->ltop){
            printf("\n");
            printf("Function %s\n",top->name);

            struct paramList* pl = top->plist;
            printf("Parameters list : \n");
            while(pl) {
                printf("name: %s, type: %s\n", pl->name, pl->type->name);
                pl = pl->next;
            }
            
            struct lsymbol* lt = top->ltop;
            printf("Presenting local symbol table : \n");
            while(lt){
                printf("name: %s, type: %s\n", lt->name, lt->type->name);
                lt = lt->next;
            }
        }
        top = top->next;
    }
}

/* Functions related to paramlist */
struct paramList* makeParamNode(struct typeTable* type, char* name, int ispointer){
    struct paramList* newEntry = (struct paramList*) malloc(sizeof(struct paramList));
    if(ispointer) newEntry->type = (type == tLookup("int")) ? tLookup("intPtr") : tLookup("strPtr");
    else newEntry->type = type;
    newEntry->name = name;
    newEntry->next = NULL;
    return newEntry;
}


/* Functions related to typeTable */
void createTypeTable(void){
    // Installing default data types
    tInstall("int", 1, NULL);
    tInstall("intPtr", 1, NULL);
    tInstall("str", 1, NULL);
    tInstall("strPtr", 1, NULL);

    // Installing special data types
    tInstall("bool", 1, NULL);
    tInstall("null", 1, NULL);
    tInstall("void", 1, NULL);
}                                

void tInstall(char* name, int size, struct fieldList* fields){
    struct typeTable* type = (struct typeTable*) malloc(sizeof(struct typeTable));
    type->name = name;
    type->size = size;
    type->fields = fields;
    type->next = NULL;

    // Initialize the findex attribute of each field present in fieldlist
    struct fieldList* temp = fields; int val=0;
    while(temp){
        temp->findex = val++;
        temp = temp->next;
    }

    // Installing the node to the top of type table
    type->next = ttt->top;
    ttt->top = type;
}                                                                  
struct typeTable* tLookup(char* name){
    struct typeTable* type = ttt->top;
    while(type){
        if(strcmp(type->name, name)==0) return type;
        type = type->next;
    }
    return NULL;
}                                                                                          
struct fieldList* fLookup(struct typeTable* type, char* name){
    struct fieldList* field = type->fields;
    while(field){
        if(strcmp(field->name, name)==0) return field;
        field = field->next;
    }
    return NULL;
}

// Assuming that the size attribute of typeTable has an valid size
int getSize(struct typeTable* type){
    return type->size;
}  

struct fieldList* makeFieldNode(char* name, struct typeTable* type){
    struct fieldList* field = (struct fieldList*) malloc(sizeof(struct fieldList));
    field->name = name;
    field->type = type;
    field->findex = undefined;
    field->next = NULL;

    return field;
}

void printTypeTable(void){
    struct typeTable* top = ttt->top;
    while(top){
        printf("Name: %s, size: %d\n",top->name,top->size);
        if(top->fields){
            printf("The fieldlist of %s is as follows:\n",top->name);
            struct fieldList* fl = top->fields;
            while(fl){
                printf("Name: %s, findex: %d, type: %s\n",fl->name,fl->findex,fl->type->name);
                fl = fl->next;
            }
            printf("\n");
        }
        top = top->next;
    }
    printf("\n");
}

// Printing nodetype values
void printPrefix(struct tnode* t){
    if(!t) return;

    printf("%d\n",t->nodetype);
    if(t->nodetype == callerNode){
        struct tnode* temp = t->arglist;
        printf("printing args: ");
        while(temp) {
            printf("%s ,",temp->type->name);
            temp=temp->arglist;
        }
        printf("\n");
    }
    printPrefix(t->exprVal);
    printPrefix(t->left);
    printPrefix(t->right);
}
