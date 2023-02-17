/*
Write a lex file
To count the number of integers and floating point numbers appearing in the input.
*/
/*        After inputting press ctrl+d         */

/* DESCRIPTION/DEFINITION SECTION */
%{
#include<stdio.h>
int decimal=0, floating=0;
%}
 
/* Regular Definition */
numbers [0-9]*
symbol [.]

/* RULE SECTION */

%%
({numbers})({symbol})({numbers}) {floating++; printf("floating");}
{numbers}  {decimal++; printf("decimal");}
%%
 
int yywrap() {return 1;}
 
// MAIN FUNCTION
int main(){
    printf("Please enter bunch of numbers : ");
    yylex();
    printf("Number of decimal and floating point numbers are : %d %d\n",decimal,floating);     
    return 0;
}