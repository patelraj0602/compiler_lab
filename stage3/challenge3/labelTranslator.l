%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "labelTranslator.h"
    #include "labelTranslator.c"
    #define first 1
    #define second 2

    int pass = first;
    int addressNumber = -7;
    struct labelAddressTable *top;

    FILE* outFile;
    FILE* filePointer;
%}

%%

[L][0-9]+[ ]:\n {
    if(pass==first)
        addLabel(top,strdup(yytext),2056+2*(addressNumber-1));
}

[L][0-9]+\n {
    if(pass==second){
        int jumpAddr = searchLabel(top,strdup(yytext));
        if(jumpAddr == -1){
            printf("Label %s not found", yytext);
            exit(1);
        }
        fprintf(outFile,"%d\n",jumpAddr);
    }
    else addressNumber++;
}

"\n" {
    if(pass==first) ++addressNumber; 
    else fprintf(outFile,"\n");
}

. {
    if(pass==second) 
        fprintf(outFile,"%s",yytext);
}

%%

int yyerror(char *s) {
    printf("yyerror: %s\n", s);
    exit(1);
}

int yywrap(void) { 
    // printLabelAddressTable(top);
    if(pass == first){
        fseek(filePointer, 0, SEEK_SET);
        pass = second;
        return 0;
    }
    return 1;
}

int main(){

	top = (struct labelAddressTable*)malloc(sizeof(struct labelAddressTable));
    top->head = NULL;
	
	filePointer = fopen("intermediate_output.xsm","r");
    if(filePointer) yyin = filePointer;
	
	outFile = fopen("final_output.xsm","w");
	
	yylex();
	
	fclose(filePointer);
	fclose(outFile);
	return 0;

}