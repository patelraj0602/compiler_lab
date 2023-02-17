#! /usr/bin/bash
yacc -d infix_to_prefix.y
lex infix_to_prefix.l
gcc lex.yy.c y.tab.c -o a.exe