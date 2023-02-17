/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    PLUS = 259,
    MINUS = 260,
    MUL = 261,
    DIV = 262,
    END = 263,
    BEG = 264,
    READ = 265,
    WRITE = 266,
    ID = 267,
    SEMICOLON = 268,
    ASSIGN = 269,
    LT = 270,
    GT = 271,
    LE = 272,
    GE = 273,
    NE = 274,
    ET = 275,
    IF = 276,
    THEN = 277,
    ELSE = 278,
    ENDIF = 279,
    WHILE = 280,
    ENDWHILE = 281,
    DO = 282,
    BREAK = 283,
    CONTINUE = 284,
    REPEAT = 285,
    UNTIL = 286
  };
#endif
/* Tokens.  */
#define NUM 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define END 263
#define BEG 264
#define READ 265
#define WRITE 266
#define ID 267
#define SEMICOLON 268
#define ASSIGN 269
#define LT 270
#define GT 271
#define LE 272
#define GE 273
#define NE 274
#define ET 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ENDIF 279
#define WHILE 280
#define ENDWHILE 281
#define DO 282
#define BREAK 283
#define CONTINUE 284
#define REPEAT 285
#define UNTIL 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "exprtree.y"

    struct tnode *no; 

#line 123 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
