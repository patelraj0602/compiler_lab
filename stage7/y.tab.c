/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "exprtree.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "exprtree.h" 
#include "exprtree.c"
#include "registers.h"
#include "codegen.c"
int yylex(void);
extern FILE* yyin;  
extern char* yytext;

// Global variables.
int binding = 4095;                                     // Always points to the top of stack    
int curType = undefined;                                // Stores the current type(int,str) of the variables
int fLabel = -1;                                        // Stores function label
char* curClass = NULL;                                  // Store the class name of the current class

#line 89 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    ID = 259,
    STRING = 260,
    END = 261,
    BEG = 262,
    READ = 263,
    WRITE = 264,
    SEMICOLON = 265,
    ASSIGN = 266,
    PLUS = 267,
    MINUS = 268,
    STAR = 269,
    DIV = 270,
    LT = 271,
    GT = 272,
    LE = 273,
    GE = 274,
    NE = 275,
    ET = 276,
    IF = 277,
    THEN = 278,
    ELSE = 279,
    ENDIF = 280,
    WHILE = 281,
    ENDWHILE = 282,
    DO = 283,
    BREAK = 284,
    CONTINUE = 285,
    REPEAT = 286,
    UNTIL = 287,
    INT = 288,
    STR = 289,
    DECL = 290,
    ENDDECL = 291,
    ADDR = 292,
    MAIN = 293,
    RETURN = 294,
    AND = 295,
    OR = 296,
    TYPE = 297,
    ENDTYPE = 298,
    ALLOC = 299,
    INITIALIZE = 300,
    FREE = 301,
    NULL_PTR = 302,
    CLASS = 303,
    ENDCLASS = 304,
    NEW = 305,
    DELETE = 306,
    SELF = 307
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define STRING 260
#define END 261
#define BEG 262
#define READ 263
#define WRITE 264
#define SEMICOLON 265
#define ASSIGN 266
#define PLUS 267
#define MINUS 268
#define STAR 269
#define DIV 270
#define LT 271
#define GT 272
#define LE 273
#define GE 274
#define NE 275
#define ET 276
#define IF 277
#define THEN 278
#define ELSE 279
#define ENDIF 280
#define WHILE 281
#define ENDWHILE 282
#define DO 283
#define BREAK 284
#define CONTINUE 285
#define REPEAT 286
#define UNTIL 287
#define INT 288
#define STR 289
#define DECL 290
#define ENDDECL 291
#define ADDR 292
#define MAIN 293
#define RETURN 294
#define AND 295
#define OR 296
#define TYPE 297
#define ENDTYPE 298
#define ALLOC 299
#define INITIALIZE 300
#define FREE 301
#define NULL_PTR 302
#define CLASS 303
#define ENDCLASS 304
#define NEW 305
#define DELETE 306
#define SELF 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "exprtree.y"
 
  int num;
  char* str;
  struct tnode* no; 
  struct gsymbol* gnode;
  struct lsymbol* lnode;
  struct paramList* pl;
  struct fieldList* fl;

#line 255 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1045

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  345

#define YYUNDEFTOK  2
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      56,    57,     2,     2,    55,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    73,    78,    89,   100,   109,   113,   117,
     124,   128,   131,   132,   135,   136,   139,   145,   167,   168,
     169,   172,   173,   176,   180,   181,   184,   185,   188,   192,
     198,   199,   202,   203,   206,   230,   272,   273,   276,   277,
     280,   295,   304,   312,   315,   329,   334,   338,   349,   352,
     353,   357,   382,   383,   387,   388,   397,   401,   402,   403,
     407,   408,   411,   412,   416,   452,   453,   454,   458,   459,
     462,   463,   464,   469,   470,   473,   487,   514,   515,   518,
     528,   531,   554,   555,   559,   560,   565,   566,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   589,   592,   595,   596,   602,   603,
     606,   609,   612,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636,   639,   644,   650,   651,   652,   653,
     654,   655,   658,   659,   660,   663,   664,   665,   666,   667,
     668
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "STRING", "END", "BEG",
  "READ", "WRITE", "SEMICOLON", "ASSIGN", "PLUS", "MINUS", "STAR", "DIV",
  "LT", "GT", "LE", "GE", "NE", "ET", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "ENDWHILE", "DO", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "INT",
  "STR", "DECL", "ENDDECL", "ADDR", "MAIN", "RETURN", "AND", "OR", "TYPE",
  "ENDTYPE", "ALLOC", "INITIALIZE", "FREE", "NULL_PTR", "CLASS",
  "ENDCLASS", "NEW", "DELETE", "SELF", "'{'", "'}'", "','", "'('", "')'",
  "'['", "']'", "'.'", "$accept", "program", "gClassBlock", "gClassList",
  "gClass", "className", "gClassDeclBlockSeg", "gClassDeclBlock",
  "gClassAttrDeclList", "gClassAttrDecl", "gClassIdList",
  "gClassFuncDeclList", "gClassFuncDecl", "gClassFuncName",
  "gClassFuncDefBlock", "gClassFuncDef", "lDeclBlockMemFunction", "mName",
  "gTypeBlock", "gTypeList", "gType", "typeName", "gTypeDeclList",
  "gTypeDecl", "gTypeIdList", "gDeclBlock", "gDeclList", "gDecl",
  "gidList", "gid", "identifierDecl", "fDefBlock", "fDef", "fName",
  "paramList", "param", "type", "mainBlock", "mainHeader",
  "lDeclBlockGlobalFunction", "lDeclBlock", "lDeclList", "lDecl",
  "lIdList", "lId", "sList", "stmt", "inputStmt", "outputStmt",
  "assignStmt", "ifStmt", "whileStmt", "doWhileStmt", "repeatUntilStmt",
  "expr", "argList", "identifier", "field", "fieldFunction", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   123,   125,    44,    40,    41,    91,    93,
      46
};
# endif

#define YYPACT_NINF (-207)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     280,   151,     0,    20,    12,    -9,    99,   142,  -207,  -207,
    -207,  -207,   170,  -207,    91,  -207,  -207,    11,  -207,   -26,
    -207,  -207,    37,  -207,   -15,  -207,    48,    55,    -9,    48,
    -207,    41,   146,  -207,    45,    98,  -207,  -207,   130,   126,
      35,  -207,  -207,  -207,  -207,   142,  -207,  -207,    87,  -207,
      80,   146,  -207,   114,    55,  -207,  -207,   114,   108,   142,
     256,   113,  -207,  -207,    91,    14,  -207,   168,   142,    16,
    -207,   132,   146,  -207,   177,   198,  -207,   210,   142,   -23,
    -207,   134,  -207,   228,  -207,     3,    21,  -207,   158,   256,
     660,  -207,   167,  -207,  -207,  -207,  -207,  -207,    66,   189,
    -207,   244,  -207,   190,  -207,    33,  -207,   178,   231,  -207,
    -207,  -207,   137,   258,  -207,   338,   366,   214,   142,  -207,
    -207,   236,     5,   256,   237,   239,   193,   256,  -207,   194,
    -207,   245,   776,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   206,   261,  -207,   264,  -207,
    -207,   262,  -207,  -207,   271,   220,    68,   291,  -207,  -207,
     114,   223,  -207,   303,    74,  -207,  -207,  -207,   229,   257,
     267,   270,   274,   281,   591,   307,   344,   591,   256,   305,
     309,   394,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
     347,   353,   266,   422,  -207,  -207,  -207,  -207,   974,   247,
     670,   315,   369,   372,   786,   374,   323,  -207,     7,     7,
    -207,  -207,  1020,  1020,  1020,  1020,  1020,  1020,  1004,  1004,
     256,   325,  -207,  -207,   220,   142,  -207,   378,  -207,   379,
    -207,   142,  -207,  -207,   137,   121,  -207,    21,   256,   256,
     256,   619,  -207,  -207,   450,   956,   328,    21,   333,  -207,
     269,  -207,  -207,   335,   256,  -207,   341,   187,  -207,  -207,
    -207,  -207,   195,   718,   253,   272,  -207,   479,   276,  -207,
     381,   288,   336,   832,   842,   888,   345,   348,  -207,   396,
     350,  -207,    21,   354,   990,  -207,   974,   256,  -207,   293,
    -207,   296,  -207,  -207,   302,  -207,   355,   507,  -207,  -207,
     403,   404,   405,   398,   389,   256,   256,  -207,   409,   417,
     375,  -207,   728,  -207,  -207,  -207,  -207,   380,  -207,  -207,
    -207,   591,   591,   898,   944,  -207,  -207,   419,  -207,  -207,
     310,   535,    18,   425,  -207,   591,   427,   428,  -207,  -207,
     563,  -207,  -207,   431,  -207
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     0,    72,    70,
      71,    48,     0,    50,     0,    41,    37,     0,    39,     0,
      16,    11,     0,    13,     0,     1,     0,     0,     3,     0,
       8,     0,     0,    61,     0,     0,    47,    49,    57,     0,
       0,    53,    54,    36,    38,     0,    10,    12,     0,     4,
       0,     0,     7,     0,    70,    60,     9,     0,     0,    67,
       0,    57,    56,    51,     0,     0,    43,     0,     0,     0,
      17,     0,     0,     5,     0,     0,    76,     0,    67,     0,
      66,     0,   126,   138,   129,     0,     0,   132,     0,     0,
       0,   128,   141,   133,    52,    40,    42,    46,     0,     0,
      22,     0,    27,     0,    15,     0,    31,     0,     0,    75,
       6,    78,     0,     0,    80,     0,     0,     0,     0,    55,
      68,     0,     0,     0,     0,   138,     0,     0,   136,   141,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,     0,    44,     0,    20,
      21,     0,    19,    26,     0,    25,     0,     0,    14,    30,
       0,     0,    84,     0,     0,    83,    77,    79,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,    64,    65,    69,   130,   135,     0,
       0,   143,     0,     0,     0,     0,   144,   125,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   142,    45,    18,     0,    67,    23,     0,    28,     0,
      34,    67,    85,    81,     0,     0,    74,     0,     0,     0,
       0,     0,    95,    96,     0,     0,     0,     0,     0,    86,
       0,   103,    63,     0,     0,   131,   139,     0,   143,   144,
     137,   142,     0,     0,     0,     0,    24,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
       0,    73,     0,     0,     0,    62,   134,     0,   148,     0,
     146,     0,    59,   150,     0,    29,     0,     0,    35,    97,
       0,     0,     0,     0,     0,     0,     0,   101,     0,   127,
       0,   106,     0,   147,   145,   149,    33,     0,    98,   104,
     105,     0,     0,     0,     0,   102,   107,     0,   140,    32,
       0,     0,     0,     0,   100,     0,     0,     0,   111,   112,
       0,   109,   110,     0,   108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,   436,  -207,   421,  -207,  -207,  -207,  -207,   346,
    -207,   356,   -98,  -207,  -207,   342,  -207,  -207,  -207,  -207,
     432,  -207,  -207,   391,  -207,   138,  -207,   445,  -207,   399,
     423,   414,     8,  -207,   -62,   351,    32,    56,  -207,   413,
     300,  -207,   358,  -207,   232,  -114,  -170,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,   -24,  -206,   -85,   -80,  -102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    22,    23,    24,    69,    70,    99,   100,
     156,   101,   102,   157,   105,   106,   229,   107,     6,    17,
      18,    19,    65,    66,    98,     7,    12,    13,    40,    41,
      42,    32,    33,    34,    79,    80,    81,    30,    31,    75,
      76,   113,   114,   164,   165,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   198,   199,    91,    92,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     128,   130,   193,   153,    15,   129,   129,   125,    82,    83,
      84,   249,    25,   191,   191,    15,   117,    85,     8,    85,
       8,   135,   136,   249,    20,   125,     1,    45,   338,   271,
     190,   190,   118,    14,   119,    85,    90,     8,    48,    35,
      55,    20,    86,    16,    14,    63,   322,     9,    10,     9,
      10,   289,    87,   153,    43,   126,   291,    88,   294,   127,
     241,    89,   197,   244,    35,   132,     9,    10,    95,    21,
     104,   249,   191,   126,   249,   191,   147,    67,   226,   191,
      55,    27,    49,    35,   233,    52,    46,   158,    56,   190,
      64,   191,   190,    50,    53,    38,   190,    67,    57,   200,
     103,   108,    58,   204,    35,    39,   112,    73,   190,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   148,    68,   227,    82,    83,    84,   249,   110,   234,
      61,   103,    27,   154,     1,    85,    71,   108,   120,   191,
      39,   162,   191,    26,    29,   112,     8,     3,   121,    74,
       8,   163,   272,   297,   245,     8,   190,   129,    86,   190,
     249,   249,   280,   265,    78,   191,    51,   129,    87,   268,
     249,    60,    97,    88,     8,     9,    10,    89,   270,    54,
      10,     8,   190,   154,     9,    10,    59,    11,    60,   109,
      82,    83,    84,     8,   155,   191,   263,   309,    82,    83,
      84,    85,   129,     9,    10,   115,    36,   330,   331,    85,
       9,    10,   190,   111,   273,   274,   275,   116,   131,   191,
     191,   340,     9,    10,    86,   149,   284,   146,   191,   191,
     286,   160,    86,   191,    87,   161,   190,   190,   191,    88,
     196,   201,    87,    89,   288,   190,   190,    88,     8,   206,
     190,    89,   290,   203,   205,   190,    82,    83,    84,    82,
      83,    84,     8,   312,   220,   221,     8,    85,   222,   118,
      85,   194,    82,    83,    84,   224,   225,     9,    10,   231,
     152,   323,   324,    85,   122,   235,   123,   123,   124,   124,
      86,     9,    10,    86,   166,     9,    10,   123,   223,   202,
      87,   228,   254,    87,   255,    88,   282,   232,    88,    89,
     293,   236,    89,   283,   168,     1,    87,   242,   170,   171,
     252,    88,     2,   237,    85,    89,   238,   118,     3,   295,
     239,   118,   172,   298,   335,   336,   173,   240,   174,   175,
     176,   177,   168,   254,   169,   300,   170,   171,   254,   178,
     313,   254,    85,   314,   243,   179,   180,   254,   250,   315,
     172,   246,    88,   251,   173,   247,   174,   175,   176,   177,
     168,   257,   192,   258,   170,   171,   259,   178,   261,   262,
      85,   264,   266,   179,   180,   279,   267,   281,   172,   285,
      88,   299,   173,   301,   174,   175,   176,   177,   168,   287,
     248,   305,   170,   171,   306,   178,   307,   308,    85,   316,
     310,   179,   180,   318,   319,   320,   172,   322,    88,   325,
     173,   321,   174,   175,   176,   177,   168,   326,   253,   334,
     170,   171,   327,   178,   329,   339,    85,   341,   342,   179,
     180,   344,    28,    47,   172,   150,    88,   159,   173,    44,
     174,   175,   176,   177,   168,   151,    96,    37,   170,   171,
     230,   178,    62,    94,    85,    72,   269,   179,   180,   195,
      77,   167,   172,     0,    88,     0,   173,     0,   174,   175,
     176,   177,   277,   168,     0,   296,     0,   170,   171,   178,
       0,     0,     0,    85,     0,   179,   180,     0,     0,     0,
       0,   172,    88,     0,     0,   173,     0,   174,   175,   176,
     177,   168,     0,   317,     0,   170,   171,     0,   178,     0,
       0,    85,     0,     0,   179,   180,     0,     0,     0,   172,
       0,    88,     0,   173,     0,   174,   175,   176,   177,   168,
       0,     0,     0,   170,   171,     0,   178,     0,     0,    85,
       0,     0,   179,   180,     0,     0,     0,   172,     0,    88,
       0,   173,   337,   174,   175,   176,   177,   168,     0,     0,
       0,   170,   171,     0,   178,     0,     0,    85,     0,     0,
     179,   180,     0,     0,     0,   172,     0,    88,   343,   173,
       0,   174,   175,   176,   177,   168,     0,     0,     0,   170,
     171,     0,   178,     0,     0,    85,     0,     0,   179,   180,
       0,     0,     0,   172,     0,    88,     0,   173,     0,   174,
     175,   176,   177,   168,     0,     0,     0,   170,   171,     0,
     178,     0,     0,    85,     0,     0,   179,   180,     0,     0,
       0,   172,     0,    88,     0,   276,     0,   174,   175,   176,
     177,     0,     0,     0,     0,     0,     0,     0,   178,     0,
       0,     0,     0,     0,   179,   180,     0,     0,     0,     0,
       0,    88,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,     0,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
       0,     0,     0,     0,     0,     0,     0,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   328,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,     0,     0,
       0,     0,     0,   207,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   260,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,     0,     0,     0,     0,     0,   302,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   303,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
       0,     0,     0,     0,     0,   304,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   332,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   278,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
       0,     0,     0,     0,   143,   144,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
     311,   333,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,     0,     0,
     143,   144,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     0,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      85,    86,   116,   101,     4,    85,    86,     4,     3,     4,
       5,   181,     0,   115,   116,     4,    78,    14,     4,    14,
       4,    14,    15,   193,     4,     4,    35,    53,    10,   235,
     115,   116,    55,     1,    57,    14,    60,     4,    53,     7,
      32,     4,    37,    43,    12,    10,    28,    33,    34,    33,
      34,   257,    47,   151,    43,    52,   262,    52,   264,    56,
     174,    56,    57,   177,    32,    89,    33,    34,    54,    49,
      54,   241,   174,    52,   244,   177,    10,    45,    10,   181,
      72,    33,    26,    51,    10,    29,    49,    54,    32,   174,
      55,   193,   177,    38,    53,     4,   181,    65,    53,   123,
      68,    69,     4,   127,    72,    14,    74,    51,   193,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    55,    35,    55,     3,     4,     5,   297,    72,    55,
       4,    99,    33,   101,    35,    14,    56,   105,     4,   241,
      14,     4,   244,     5,     6,   113,     4,    48,    14,    35,
       4,    14,   237,   267,   178,     4,   241,   237,    37,   244,
     330,   331,   247,   225,    56,   267,    28,   247,    47,   231,
     340,    58,     4,    52,     4,    33,    34,    56,    57,    33,
      34,     4,   267,   151,    33,    34,    56,    36,    58,    57,
       3,     4,     5,     4,     4,   297,   220,   282,     3,     4,
       5,    14,   282,    33,    34,     7,    36,   321,   322,    14,
      33,    34,   297,    36,   238,   239,   240,     7,    60,   321,
     322,   335,    33,    34,    37,    36,   250,    60,   330,   331,
     254,    53,    37,   335,    47,     4,   321,   322,   340,    52,
       4,     4,    47,    56,    57,   330,   331,    52,     4,     4,
     335,    56,    57,    60,    60,   340,     3,     4,     5,     3,
       4,     5,     4,   287,    58,     4,     4,    14,     4,    55,
      14,    57,     3,     4,     5,     4,    56,    33,    34,    56,
      36,   305,   306,    14,    56,    56,    58,    58,    60,    60,
      37,    33,    34,    37,    36,    33,    34,    58,    36,    60,
      47,    10,    55,    47,    57,    52,    37,     4,    52,    56,
      57,    54,    56,    44,     4,    35,    47,    10,     8,     9,
      54,    52,    42,    56,    14,    56,    56,    55,    48,    57,
      56,    55,    22,    57,    24,    25,    26,    56,    28,    29,
      30,    31,     4,    55,     6,    57,     8,     9,    55,    39,
      57,    55,    14,    57,    10,    45,    46,    55,    11,    57,
      22,    56,    52,    10,    26,    56,    28,    29,    30,    31,
       4,    56,     6,     4,     8,     9,     4,    39,     4,    56,
      14,    56,     4,    45,    46,    57,     7,    54,    22,    54,
      52,    10,    26,    57,    28,    29,    30,    31,     4,    58,
       6,    56,     8,     9,    56,    39,    10,    57,    14,    54,
      56,    45,    46,    10,    10,    10,    22,    28,    52,    10,
      26,    23,    28,    29,    30,    31,     4,    10,     6,    10,
       8,     9,    57,    39,    54,    10,    14,    10,    10,    45,
      46,    10,     6,    22,    22,    99,    52,   105,    26,    17,
      28,    29,    30,    31,     4,    99,    65,    12,     8,     9,
     160,    39,    39,    64,    14,    51,   234,    45,    46,   118,
      57,   113,    22,    -1,    52,    -1,    26,    -1,    28,    29,
      30,    31,    32,     4,    -1,     6,    -1,     8,     9,    39,
      -1,    -1,    -1,    14,    -1,    45,    46,    -1,    -1,    -1,
      -1,    22,    52,    -1,    -1,    26,    -1,    28,    29,    30,
      31,     4,    -1,     6,    -1,     8,     9,    -1,    39,    -1,
      -1,    14,    -1,    -1,    45,    46,    -1,    -1,    -1,    22,
      -1,    52,    -1,    26,    -1,    28,    29,    30,    31,     4,
      -1,    -1,    -1,     8,     9,    -1,    39,    -1,    -1,    14,
      -1,    -1,    45,    46,    -1,    -1,    -1,    22,    -1,    52,
      -1,    26,    27,    28,    29,    30,    31,     4,    -1,    -1,
      -1,     8,     9,    -1,    39,    -1,    -1,    14,    -1,    -1,
      45,    46,    -1,    -1,    -1,    22,    -1,    52,    25,    26,
      -1,    28,    29,    30,    31,     4,    -1,    -1,    -1,     8,
       9,    -1,    39,    -1,    -1,    14,    -1,    -1,    45,    46,
      -1,    -1,    -1,    22,    -1,    52,    -1,    26,    -1,    28,
      29,    30,    31,     4,    -1,    -1,    -1,     8,     9,    -1,
      39,    -1,    -1,    14,    -1,    -1,    45,    46,    -1,    -1,
      -1,    22,    -1,    52,    -1,    26,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    40,    41,    -1,    -1,
      10,    57,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    40,    41,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      40,    41,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    42,    48,    62,    63,    79,    86,     4,    33,
      34,    36,    87,    88,    97,     4,    43,    80,    81,    82,
       4,    49,    64,    65,    66,     0,    86,    33,    63,    86,
      98,    99,    92,    93,    94,    97,    36,    88,     4,    14,
      89,    90,    91,    43,    81,    53,    49,    65,    53,    98,
      38,    86,    98,    53,    33,    93,    98,    53,     4,    56,
      58,     4,    91,    10,    55,    83,    84,    97,    35,    67,
      68,    56,    92,    98,    35,   100,   101,   100,    56,    95,
      96,    97,     3,     4,     5,    14,    37,    47,    52,    56,
     115,   117,   118,   119,    90,    54,    84,     4,    85,    69,
      70,    72,    73,    97,    54,    75,    76,    78,    97,    57,
      98,    36,    97,   102,   103,     7,     7,    95,    55,    57,
       4,    14,    56,    58,    60,     4,    52,    56,   117,   118,
     117,    60,   115,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    40,    41,    59,    60,    10,    55,    36,
      70,    72,    36,    73,    97,     4,    71,    74,    54,    76,
      53,     4,     4,    14,   104,   105,    36,   103,     4,     6,
       8,     9,    22,    26,    28,    29,    30,    31,    39,    45,
      46,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     117,   119,     6,   106,    57,    96,     4,    57,   115,   116,
     115,     4,    60,    60,   115,    60,     4,    57,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
      58,     4,     4,    36,     4,    56,    10,    55,    10,    77,
     101,    56,     4,    10,    55,    56,    54,    56,    56,    56,
      56,   106,    10,    10,   106,   115,    56,    56,     6,   107,
      11,    10,    54,     6,    55,    57,    59,    56,     4,     4,
      57,     4,    56,   115,    56,    95,     4,     7,    95,   105,
      57,   116,   117,   115,   115,   115,    26,    32,    10,    57,
     117,    54,    37,    44,   115,    54,   115,    58,    57,   116,
      57,   116,    59,    57,   116,    57,     6,   106,    57,    10,
      57,    57,    57,    57,    57,    56,    56,    10,    57,   117,
      56,    10,   115,    57,    57,    57,    54,     6,    10,    10,
      10,    23,    28,   115,   115,    10,    10,    57,    59,    54,
     106,   106,    57,    57,    10,    24,    25,    27,    10,    10,
     106,    10,    10,    25,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    65,    65,    66,    67,    68,    68,
      68,    69,    69,    70,    71,    71,    72,    72,    73,    74,
      75,    75,    76,    76,    77,    78,    79,    79,    80,    80,
      81,    82,    83,    83,    84,    85,    85,    86,    86,    87,
      87,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      92,    92,    93,    93,    94,    95,    95,    95,    96,    96,
      97,    97,    97,    98,    98,    99,   100,   101,   101,   102,
     102,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   108,   109,   110,   110,   111,   111,
     112,   113,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   117,   117,
     117,   117,   118,   118,   118,   119,   119,   119,   119,   119,
     119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     4,     5,     3,     2,     3,
       3,     2,     2,     1,     5,     4,     1,     1,     4,     3,
       3,     2,     1,     3,     3,     1,     2,     1,     3,     4,
       2,     1,     7,     6,     1,     5,     3,     2,     2,     1,
       4,     1,     2,     1,     3,     3,     1,     3,     2,     2,
       1,     3,     3,     1,     1,     4,     2,     1,     4,     7,
       2,     1,     7,     6,     5,     3,     1,     0,     2,     3,
       1,     1,     1,     7,     6,     4,     1,     3,     2,     2,
       1,     3,     3,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     4,     5,     3,
       6,     4,     5,     2,     5,     5,     4,     5,    10,     8,
       8,     7,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     2,     1,     1,
       3,     4,     1,     1,     3,     1,     2,     4,     1,     4,
       7,     1,     3,     3,     3,     6,     5,     6,     5,     6,
       5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 69 "exprtree.y"
                      {
        printPrefix((yyvsp[0].no));
        helperFunction((yyvsp[0].no));
      }
#line 1814 "y.tab.c"
    break;

  case 3:
#line 73 "exprtree.y"
                             {
        printf("hurray!!\n");
        printPrefix((yyvsp[0].no));
        helperFunction((yyvsp[0].no));
      }
#line 1824 "y.tab.c"
    break;

  case 4:
#line 78 "exprtree.y"
                                       {
        printTypeTable();
        printf("Presenting the class table: \n"); printClassTable();
        printGlobalSymbolTable();
        printLocalSymbolTable();

        // Print prefix tree
        (yyval.no) = makeConnectorNode((yyvsp[-2].no),(yyvsp[0].no));
        // printPrefix($$);
        helperFunction((yyval.no));
      }
#line 1840 "y.tab.c"
    break;

  case 5:
#line 89 "exprtree.y"
                                                  {
        printTypeTable();
        printf("Presenting the class table: \n"); printClassTable();
        printGlobalSymbolTable();
        printLocalSymbolTable();

        // Print prefix tree
        (yyval.no) = makeConnectorNode((yyvsp[-2].no),(yyvsp[0].no));
        // printPrefix($$);
        helperFunction((yyval.no));
      }
#line 1856 "y.tab.c"
    break;

  case 6:
#line 100 "exprtree.y"
                                                            {
      printTypeTable();
      printf("Presenting the class table: \n"); printClassTable();
      printGlobalSymbolTable();
      printLocalSymbolTable();
      (yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));
      // Call codegen
      helperFunction((yyval.no));
    }
#line 1870 "y.tab.c"
    break;

  case 7:
#line 109 "exprtree.y"
                                    {
      (yyval.no) = makeConnectorNode((yyvsp[0].no),NULL);  
      helperFunction((yyval.no));
    }
#line 1879 "y.tab.c"
    break;

  case 8:
#line 113 "exprtree.y"
                         {
      (yyval.no) = makeConnectorNode((yyvsp[0].no),NULL);
      helperFunction((yyval.no));  
    }
#line 1888 "y.tab.c"
    break;

  case 9:
#line 117 "exprtree.y"
                                   {
      (yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));
      helperFunction((yyval.no));
    }
#line 1897 "y.tab.c"
    break;

  case 10:
#line 124 "exprtree.y"
                                        {
      curClass = NULL;
      (yyval.no) = (yyvsp[-1].no);  
    }
#line 1906 "y.tab.c"
    break;

  case 11:
#line 128 "exprtree.y"
                   {(yyval.no) = NULL;}
#line 1912 "y.tab.c"
    break;

  case 12:
#line 131 "exprtree.y"
                               {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 1918 "y.tab.c"
    break;

  case 13:
#line 132 "exprtree.y"
           {(yyval.no) = (yyvsp[0].no);}
#line 1924 "y.tab.c"
    break;

  case 14:
#line 135 "exprtree.y"
                                                                 {(yyval.no) = (yyvsp[-1].no);}
#line 1930 "y.tab.c"
    break;

  case 15:
#line 136 "exprtree.y"
                                         {(yyval.no) = NULL;}
#line 1936 "y.tab.c"
    break;

  case 16:
#line 139 "exprtree.y"
                {
      cInstall((yyvsp[0].str),NULL);                            // Make an entry in class table
      curClass = (yyvsp[0].str);
    }
#line 1945 "y.tab.c"
    break;

  case 17:
#line 145 "exprtree.y"
                                     {
      // Initialize the value of attribute count and method count
      struct classTable* ctype = cLookup(curClass);
      struct attrList* alist = ctype->memfield;
      struct memberFuncList* memlist = ctype->vfuncptr;

      int count=0;
      while(alist){
        alist->findex = count++;
        alist = alist->next;
      }
      ctype->attrcount = count;

      count=0;
      while(memlist){
        memlist->funcpos = count++;
        memlist = memlist->next;
      }
      ctype->methodcount = count;
    }
#line 1970 "y.tab.c"
    break;

  case 18:
#line 167 "exprtree.y"
                                                                     {}
#line 1976 "y.tab.c"
    break;

  case 19:
#line 168 "exprtree.y"
                                    {}
#line 1982 "y.tab.c"
    break;

  case 20:
#line 169 "exprtree.y"
                                    {}
#line 1988 "y.tab.c"
    break;

  case 21:
#line 172 "exprtree.y"
                                                       {}
#line 1994 "y.tab.c"
    break;

  case 22:
#line 173 "exprtree.y"
                   {}
#line 2000 "y.tab.c"
    break;

  case 23:
#line 176 "exprtree.y"
                                             {}
#line 2006 "y.tab.c"
    break;

  case 24:
#line 180 "exprtree.y"
                                   {classAttrInstall(curClass,(yyvsp[-3].str),(yyvsp[0].str));}
#line 2012 "y.tab.c"
    break;

  case 25:
#line 181 "exprtree.y"
       {classAttrInstall(curClass,(yyvsp[-1].str),(yyvsp[0].str));}
#line 2018 "y.tab.c"
    break;

  case 26:
#line 184 "exprtree.y"
                                                       {}
#line 2024 "y.tab.c"
    break;

  case 27:
#line 185 "exprtree.y"
                   {}
#line 2030 "y.tab.c"
    break;

  case 28:
#line 188 "exprtree.y"
                                               {}
#line 2036 "y.tab.c"
    break;

  case 29:
#line 192 "exprtree.y"
                                      {
      if(cLookup((yyvsp[-4].str))) yyerror("Return type of methods cannot be class variables !!\n");
      classMemInstall(curClass,(yyvsp[-3].str),(yyvsp[-4].str),(yyvsp[-1].pl));
    }
#line 2045 "y.tab.c"
    break;

  case 30:
#line 198 "exprtree.y"
                                                      {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2051 "y.tab.c"
    break;

  case 31:
#line 199 "exprtree.y"
                  {(yyval.no) = (yyvsp[0].no);}
#line 2057 "y.tab.c"
    break;

  case 32:
#line 202 "exprtree.y"
                                                                  {(yyval.no) = createMethodFunkNode((yyvsp[-6].str),(yyvsp[-2].no));}
#line 2063 "y.tab.c"
    break;

  case 33:
#line 203 "exprtree.y"
                                                {(yyval.no) = NULL;}
#line 2069 "y.tab.c"
    break;

  case 34:
#line 206 "exprtree.y"
                                   {
      char* methodName = (yyvsp[(-1) - (1)].str);
      struct memberFuncList* node = classMemLookup(curClass,methodName);
      struct lsymbol* top = (yyvsp[0].lnode);

      if(top == NULL){
        lst->top = node->ltop;
        lst->type = node->type;
        lst->name = methodName;
      }
      else{
        while(top->next) top=top->next;
        top->next = node->ltop;
        node->ltop = (yyvsp[0].lnode);

        // Setting the value of lst which aids in making expression tree.
        lst->top = (yyvsp[0].lnode);
        lst->type = node->type;
        lst->name = methodName;
      }
    }
#line 2095 "y.tab.c"
    break;

  case 35:
#line 230 "exprtree.y"
                                  {
      struct memberFuncList* node = classMemLookup(curClass,(yyvsp[-3].str));
      
      // No need to search in cLookup as return type of methods cannot be class variables.
      struct typeTable* type = tLookup((yyvsp[-4].str));

      if(!node) yyerror("Method not declared for the class !!\n");
      if(node->type !=  type) yyerror("Return type mismatch between declaration and intialization in an method of the class !!\n");
    
      // spl -- Stored param list
      // npl -- New param list
      // Both of the list should exactly match
      struct paramList* spl = node->plist;
      struct paramList* npl = (yyvsp[-1].pl);
      while(spl || npl){
        if((!spl)||(!npl)) yyerror("No of parameter of declaration and initialization does not match");
        if((strcmp(spl->name,npl->name)!=0)||(spl->type != npl->type))
          yyerror("parameters mismatch between declaration and initialization of method");
        spl = spl->next;
        npl = npl->next;
      }

      // Adding the list of parameters to the local symbol table
      struct paramList* pl = (yyvsp[-1].pl);
      while(pl){
        struct lsymbol* temp = makeLSymbolNode(pl->name,pl->type,-1);
        temp->next = node->ltop;
        node->ltop = temp;
        pl = pl->next;
      }

      // Set the pointer to the parameter list attribute of memFuncList
      node->plist = (yyvsp[-1].pl);

      // Return the function name
      (yyval.str) = (yyvsp[-3].str);
    }
#line 2137 "y.tab.c"
    break;

  case 36:
#line 272 "exprtree.y"
                                    {}
#line 2143 "y.tab.c"
    break;

  case 37:
#line 273 "exprtree.y"
                 {}
#line 2149 "y.tab.c"
    break;

  case 38:
#line 276 "exprtree.y"
                            {}
#line 2155 "y.tab.c"
    break;

  case 39:
#line 277 "exprtree.y"
          {}
#line 2161 "y.tab.c"
    break;

  case 40:
#line 280 "exprtree.y"
                                       {
      struct typeTable* type = tLookup((yyvsp[-3].str));
      
      // finding the size of the user defined data type and initialzing findex attribute of fields
      struct fieldList* fl = (yyvsp[-1].fl); int count = 0;
      while(fl){
        fl->findex = count++;
        fl = fl->next;
      }
      if(count>8) yyerror("Maximum fields in an user defined data type is limited to 8 !!");
      type->size = count;
      type->fields = (yyvsp[-1].fl);
    }
#line 2179 "y.tab.c"
    break;

  case 41:
#line 295 "exprtree.y"
              {
      struct typeTable* type = tLookup((yyvsp[0].str));
      if(type) yyerror("Multiple used defined data types with same name found !!");

      tInstall((yyvsp[0].str),undefined,NULL);
      (yyval.str) = (yyvsp[0].str);
    }
#line 2191 "y.tab.c"
    break;

  case 42:
#line 304 "exprtree.y"
                                        {
      struct fieldList* f1 = (yyvsp[-1].fl);
      struct fieldList* f2 = (yyvsp[0].fl);

      while(f2->next) f2 = f2->next;
      f2->next = f1;
      (yyval.fl) = (yyvsp[0].fl);
    }
#line 2204 "y.tab.c"
    break;

  case 43:
#line 312 "exprtree.y"
              {(yyval.fl) = (yyvsp[0].fl);}
#line 2210 "y.tab.c"
    break;

  case 44:
#line 315 "exprtree.y"
                                       {
      struct typeTable* type = tLookup((yyvsp[-2].str));
      if(!type) yyerror("This user defined type is not yet declared !!");

      struct fieldList* field = (yyvsp[-1].fl);
      while(field){
        if(field->type == NULL) field->type = type;
        field = field->next;
      }

      (yyval.fl) = (yyvsp[-1].fl);
    }
#line 2227 "y.tab.c"
    break;

  case 45:
#line 329 "exprtree.y"
                                 {
      struct fieldList* node = makeFieldNode((yyvsp[0].str),NULL);
      node->next = (yyvsp[-2].fl);
      (yyval.fl) = node;
    }
#line 2237 "y.tab.c"
    break;

  case 46:
#line 334 "exprtree.y"
       {(yyval.fl) = makeFieldNode((yyvsp[0].str),NULL);}
#line 2243 "y.tab.c"
    break;

  case 47:
#line 338 "exprtree.y"
                                    {
      // Binding of variables   
      struct gsymbol* top = gst->top;
      while(top){
        if(top->flabel == -1){
          top->binding = binding+1;
          binding += top->size;
        }
        top = top->next;
      }
    }
#line 2259 "y.tab.c"
    break;

  case 51:
#line 357 "exprtree.y"
                               {
      // Adding type of variables for the entries in global symbol table
      struct gsymbol* top = gst->top;
      struct typeTable* type = tLookup((yyvsp[-2].str));
      struct classTable* ctype = cLookup((yyvsp[-2].str));

      while(top){
        if(top->status == undefined){
          // For type
          if(top->ispointer){
            if(type == tLookup("int")) top->type = tLookup("intPtr");
            else if(type == tLookup("str")) top->type = tLookup("strPtr");
            else yyerror("Pointer is not supported for user defined data types");
          }
          else top->type = type;
          
          // For ctype
          top->ctype = cLookup((yyvsp[-2].str));
          top->status = definedDone;
        }
        top = top->next;
      }
    }
#line 2287 "y.tab.c"
    break;

  case 55:
#line 388 "exprtree.y"
                         {
      // Making an entry in gst for function and also assigning label for that function.
      gInstall((yyvsp[-3].str),NULL,0,0,0,(yyvsp[-1].pl));
      struct gsymbol* node = gLookup((yyvsp[-3].str));
      node->flabel = ++fLabel;
    }
#line 2298 "y.tab.c"
    break;

  case 56:
#line 397 "exprtree.y"
                                      {
      struct gsymbol* node = gLookup((yyvsp[0].str));
      node->ispointer = 1;
    }
#line 2307 "y.tab.c"
    break;

  case 57:
#line 401 "exprtree.y"
        {gInstall((yyvsp[0].str),NULL,0,0,0,NULL); (yyval.str) = (yyvsp[0].str);}
#line 2313 "y.tab.c"
    break;

  case 58:
#line 402 "exprtree.y"
                    {gInstall((yyvsp[-3].str),NULL,0,(yyvsp[-1].no)->val,0,NULL); (yyval.str) = (yyvsp[-3].str);}
#line 2319 "y.tab.c"
    break;

  case 59:
#line 403 "exprtree.y"
                                 {gInstall((yyvsp[-6].str),NULL,0,(yyvsp[-4].no)->val,(yyvsp[-1].no)->val,NULL); (yyval.str) = (yyvsp[-6].str);}
#line 2325 "y.tab.c"
    break;

  case 60:
#line 407 "exprtree.y"
                           {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2331 "y.tab.c"
    break;

  case 61:
#line 408 "exprtree.y"
         {(yyval.no) = (yyvsp[0].no);}
#line 2337 "y.tab.c"
    break;

  case 62:
#line 411 "exprtree.y"
                                                            {(yyval.no) = createFunkNode((yyvsp[-6].str),(yyvsp[-2].no));}
#line 2343 "y.tab.c"
    break;

  case 63:
#line 412 "exprtree.y"
                                                     {(yyval.no) = NULL;}
#line 2349 "y.tab.c"
    break;

  case 64:
#line 416 "exprtree.y"
                                  {
      // Finding the function entry from global symbol table
      struct gsymbol* node = gLookup((yyvsp[-3].str));
      struct typeTable* type = tLookup((yyvsp[-4].str));

      // Compare the function declaration with initialization to ensure that both of them are equal
      if(!node) yyerror("Make sure to initialize the function %s\n",(yyvsp[-3].str));
      if(node->type != type) yyerror("Return type mismatch between initialization and declaration of function %s\n",(yyvsp[-3].str));
      
      // spl -- Stored param list
      // npl -- New param list
      // Both of the list should exactly match
      struct paramList* spl = node->plist;
      struct paramList* npl = (yyvsp[-1].pl);
      while(spl || npl){
        if((!spl)||(!npl)) yyerror("No of parameter of declaration and initialization does not match");
        if((strcmp(spl->name,npl->name)!=0)||(spl->type != npl->type))
          yyerror("parameters mismatch between declaration and initialization");
        spl = spl->next;
        npl = npl->next;
      }

      // Adding this list of parameters to the local symbol table of this function.
      struct paramList* pl = (yyvsp[-1].pl);
        while(pl){
          struct lsymbol* temp = makeLSymbolNode(pl->name, pl->type, -1);
          temp->next = node->ltop;
          node->ltop = temp;
          pl = pl->next;
        }

      // Return function name
      (yyval.str) = (yyvsp[-3].str);      
    }
#line 2388 "y.tab.c"
    break;

  case 65:
#line 452 "exprtree.y"
                                {(yyvsp[0].pl)->next = (yyvsp[-2].pl); (yyval.pl) = (yyvsp[0].pl);}
#line 2394 "y.tab.c"
    break;

  case 66:
#line 453 "exprtree.y"
          {(yyval.pl) = (yyvsp[0].pl);}
#line 2400 "y.tab.c"
    break;

  case 67:
#line 454 "exprtree.y"
    {(yyval.pl) = NULL;}
#line 2406 "y.tab.c"
    break;

  case 68:
#line 458 "exprtree.y"
                {(yyval.pl) = makeParamNode(tLookup((yyvsp[-1].str)),(yyvsp[0].str),0);}
#line 2412 "y.tab.c"
    break;

  case 69:
#line 459 "exprtree.y"
                 {(yyval.pl) = makeParamNode(tLookup((yyvsp[-2].str)),(yyvsp[0].str),1);}
#line 2418 "y.tab.c"
    break;

  case 70:
#line 462 "exprtree.y"
           {(yyval.str) = (yyvsp[0].str);}
#line 2424 "y.tab.c"
    break;

  case 71:
#line 463 "exprtree.y"
        {(yyval.str) = (yyvsp[0].str);}
#line 2430 "y.tab.c"
    break;

  case 72:
#line 464 "exprtree.y"
       {(yyval.str) = (yyvsp[0].str);}
#line 2436 "y.tab.c"
    break;

  case 73:
#line 469 "exprtree.y"
                                                                      {(yyval.no) = createMainNode((yyvsp[-6].str),(yyvsp[-2].no));}
#line 2442 "y.tab.c"
    break;

  case 74:
#line 470 "exprtree.y"
                                                        {}
#line 2448 "y.tab.c"
    break;

  case 75:
#line 473 "exprtree.y"
                              {
      char* temp = malloc(5);
      memcpy(temp, "main\0", 5);

      gInstall(temp,tLookup("int"),0,0,0,NULL);
      struct gsymbol* node = gLookup(temp);
      node->ltop = NULL;
      node->flabel = ++fLabel;

      (yyval.str) = temp;
    }
#line 2464 "y.tab.c"
    break;

  case 76:
#line 487 "exprtree.y"
                                      {
      char* funkName = (yyvsp[(-1) - (1)].str);

      // Joining this local symbol table to the (ltop field of gsymbol)
      struct gsymbol* gnode = gLookup(funkName);
      struct lsymbol* top = (yyvsp[0].lnode);

      if(top == NULL){
        lst->top = gnode->ltop;
        lst->type = gnode->type;
        lst->name = funkName;
      }
      else{
        while(top->next) top=top->next;
        top->next = gnode->ltop;
        gnode->ltop = (yyvsp[0].lnode);

        // initializing lst value to current local symbol table for making an expression tree
        lst->top = (yyvsp[0].lnode);
        lst->type = gnode->type;
        lst->name = funkName;
      }
    }
#line 2492 "y.tab.c"
    break;

  case 77:
#line 514 "exprtree.y"
                                    {(yyval.lnode) = (yyvsp[-1].lnode);}
#line 2498 "y.tab.c"
    break;

  case 78:
#line 515 "exprtree.y"
                 {(yyval.lnode) = NULL;}
#line 2504 "y.tab.c"
    break;

  case 79:
#line 518 "exprtree.y"
                            {
      // Both lDeclList and lDecl contains the pointer to head of the linked list of lsymbol node
      struct lsymbol* l1 = (yyvsp[-1].lnode);
      struct lsymbol* l2 = (yyvsp[0].lnode);

      // Get the last node of list2
      while(l2->next) l2 = l2->next;
      l2->next = l1;
      (yyval.lnode) = (yyvsp[0].lnode);
    }
#line 2519 "y.tab.c"
    break;

  case 80:
#line 528 "exprtree.y"
          {(yyval.lnode) = (yyvsp[0].lnode);}
#line 2525 "y.tab.c"
    break;

  case 81:
#line 531 "exprtree.y"
                               {
      struct lsymbol* top = (yyvsp[-1].lnode);
      struct typeTable* type = tLookup((yyvsp[-2].str));
      
      // Class variables are only allowed globally 
      if(type == NULL) 
        yyerror("Type not found. class variables are only allowed globally !!\n");

      while(top){
        if(top->type == NULL){
          if(top->ispointer){
            if(type == tLookup("int")) top->type = tLookup("intPtr");
            else if(type == tLookup("str")) top->type = tLookup("strPtr");
            else yyerror("Pointer is not supported for user defined data types");
          }
          else top->type = type;
        }
        top = top->next;
      }
      (yyval.lnode) = (yyvsp[-1].lnode);
    }
#line 2551 "y.tab.c"
    break;

  case 82:
#line 554 "exprtree.y"
                          {(yyvsp[0].lnode)->next = (yyvsp[-2].lnode); (yyval.lnode) = (yyvsp[0].lnode);}
#line 2557 "y.tab.c"
    break;

  case 83:
#line 555 "exprtree.y"
        {(yyval.lnode) = (yyvsp[0].lnode);}
#line 2563 "y.tab.c"
    break;

  case 84:
#line 559 "exprtree.y"
         {(yyval.lnode) = makeLSymbolNode((yyvsp[0].str),NULL,0);}
#line 2569 "y.tab.c"
    break;

  case 85:
#line 560 "exprtree.y"
            {(yyval.lnode) = makeLSymbolNode((yyvsp[0].str),NULL,1);}
#line 2575 "y.tab.c"
    break;

  case 86:
#line 565 "exprtree.y"
                   {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2581 "y.tab.c"
    break;

  case 87:
#line 566 "exprtree.y"
         {(yyval.no) = (yyvsp[0].no);}
#line 2587 "y.tab.c"
    break;

  case 88:
#line 569 "exprtree.y"
                 {(yyval.no) = (yyvsp[0].no);}
#line 2593 "y.tab.c"
    break;

  case 89:
#line 570 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 2599 "y.tab.c"
    break;

  case 90:
#line 571 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 2605 "y.tab.c"
    break;

  case 91:
#line 572 "exprtree.y"
           {(yyval.no) = (yyvsp[0].no);}
#line 2611 "y.tab.c"
    break;

  case 92:
#line 573 "exprtree.y"
              {(yyval.no) = (yyvsp[0].no);}
#line 2617 "y.tab.c"
    break;

  case 93:
#line 574 "exprtree.y"
                {(yyval.no) = (yyvsp[0].no);}
#line 2623 "y.tab.c"
    break;

  case 94:
#line 575 "exprtree.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 2629 "y.tab.c"
    break;

  case 95:
#line 576 "exprtree.y"
                    {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,breakNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2635 "y.tab.c"
    break;

  case 96:
#line 577 "exprtree.y"
                       {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,continueNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2641 "y.tab.c"
    break;

  case 97:
#line 578 "exprtree.y"
                         {(yyval.no) = createCallerNode((yyvsp[-3].str),NULL);}
#line 2647 "y.tab.c"
    break;

  case 98:
#line 579 "exprtree.y"
                                 {(yyval.no) = createCallerNode((yyvsp[-4].str),(yyvsp[-2].no));}
#line 2653 "y.tab.c"
    break;

  case 99:
#line 580 "exprtree.y"
                          {(yyval.no) = createReturnNode(lst->type,(yyvsp[-1].no),lst->name);}
#line 2659 "y.tab.c"
    break;

  case 100:
#line 581 "exprtree.y"
                                                {(yyval.no) = makeAllocNode((yyvsp[-5].no));}
#line 2665 "y.tab.c"
    break;

  case 101:
#line 582 "exprtree.y"
                                       {(yyval.no) = makeMemInitNode();}
#line 2671 "y.tab.c"
    break;

  case 102:
#line 583 "exprtree.y"
                                            {(yyval.no) = makeFreeNode((yyvsp[-2].no));}
#line 2677 "y.tab.c"
    break;

  case 103:
#line 584 "exprtree.y"
                            {(yyval.no) = (yyvsp[-1].no);}
#line 2683 "y.tab.c"
    break;

  case 104:
#line 589 "exprtree.y"
                                              {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,readNode,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2689 "y.tab.c"
    break;

  case 105:
#line 592 "exprtree.y"
                                          {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,writeNode,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2695 "y.tab.c"
    break;

  case 106:
#line 595 "exprtree.y"
                                              {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,assignNode,(yyvsp[-3].no),(yyvsp[-1].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2701 "y.tab.c"
    break;

  case 107:
#line 596 "exprtree.y"
                                                {
      struct tnode* newAddrNode = createAddrNode((yyvsp[-1].no));
      (yyval.no) = createTree(noNumber,tLookup("void"),NULL,assignNode,(yyvsp[-4].no),newAddrNode,NULL,NULL,NULL,NULL,NULL,NULL);
    }
#line 2710 "y.tab.c"
    break;

  case 108:
#line 602 "exprtree.y"
                                                               {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,ifElseNode,(yyvsp[-4].no),(yyvsp[-2].no),(yyvsp[-7].no),NULL,NULL,NULL,NULL,NULL);}
#line 2716 "y.tab.c"
    break;

  case 109:
#line 603 "exprtree.y"
                                               {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,ifElseNode,(yyvsp[-2].no),NULL,(yyvsp[-5].no),NULL,NULL,NULL,NULL,NULL);}
#line 2722 "y.tab.c"
    break;

  case 110:
#line 606 "exprtree.y"
                                                            {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,whileNode,(yyvsp[-2].no),NULL,(yyvsp[-5].no),NULL,NULL,NULL,NULL,NULL);}
#line 2728 "y.tab.c"
    break;

  case 111:
#line 609 "exprtree.y"
                                                    {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,doWhileNode,(yyvsp[-5].no),NULL,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL);}
#line 2734 "y.tab.c"
    break;

  case 112:
#line 612 "exprtree.y"
                                                            {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,repeatUntilNode,(yyvsp[-5].no),NULL,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL);}
#line 2740 "y.tab.c"
    break;

  case 113:
#line 616 "exprtree.y"
                       {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,addNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2746 "y.tab.c"
    break;

  case 114:
#line 617 "exprtree.y"
                      {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,subNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2752 "y.tab.c"
    break;

  case 115:
#line 618 "exprtree.y"
                   {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,mulNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2758 "y.tab.c"
    break;

  case 116:
#line 619 "exprtree.y"
                  {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,divNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2764 "y.tab.c"
    break;

  case 117:
#line 620 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,lessNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2770 "y.tab.c"
    break;

  case 118:
#line 621 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,greaterNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2776 "y.tab.c"
    break;

  case 119:
#line 622 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,lessEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2782 "y.tab.c"
    break;

  case 120:
#line 623 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,greaterEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2788 "y.tab.c"
    break;

  case 121:
#line 624 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,notEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2794 "y.tab.c"
    break;

  case 122:
#line 625 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,equalNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2800 "y.tab.c"
    break;

  case 123:
#line 626 "exprtree.y"
                  {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,andNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2806 "y.tab.c"
    break;

  case 124:
#line 627 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,orNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2812 "y.tab.c"
    break;

  case 125:
#line 628 "exprtree.y"
                 {(yyval.no) = (yyvsp[-1].no);}
#line 2818 "y.tab.c"
    break;

  case 126:
#line 629 "exprtree.y"
        {(yyval.no) = (yyvsp[0].no);}
#line 2824 "y.tab.c"
    break;

  case 127:
#line 630 "exprtree.y"
                    {(yyval.no) = createAddrNode((yyvsp[0].no));}
#line 2830 "y.tab.c"
    break;

  case 128:
#line 631 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 2836 "y.tab.c"
    break;

  case 129:
#line 632 "exprtree.y"
           {(yyval.no) = (yyvsp[0].no);}
#line 2842 "y.tab.c"
    break;

  case 130:
#line 633 "exprtree.y"
               {(yyval.no) = createCallerNode((yyvsp[-2].str),NULL);}
#line 2848 "y.tab.c"
    break;

  case 131:
#line 634 "exprtree.y"
                       {(yyval.no) = createCallerNode((yyvsp[-3].str),(yyvsp[-1].no));}
#line 2854 "y.tab.c"
    break;

  case 132:
#line 635 "exprtree.y"
             {(yyval.no) = makeNullNode();}
#line 2860 "y.tab.c"
    break;

  case 133:
#line 636 "exprtree.y"
                  {(yyval.no) = (yyvsp[0].no);}
#line 2866 "y.tab.c"
    break;

  case 134:
#line 639 "exprtree.y"
                           {
      struct tnode* temp = createArgsNode((yyvsp[0].no));
      temp->arglist = (yyvsp[-2].no);
      (yyval.no) = temp;
    }
#line 2876 "y.tab.c"
    break;

  case 135:
#line 644 "exprtree.y"
         {(yyval.no) = createArgsNode((yyvsp[0].no));}
#line 2882 "y.tab.c"
    break;

  case 136:
#line 650 "exprtree.y"
                             {(yyval.no) = createStarNode((yyvsp[0].no));}
#line 2888 "y.tab.c"
    break;

  case 137:
#line 651 "exprtree.y"
                      {(yyval.no) = createStarNode((yyvsp[-1].no));}
#line 2894 "y.tab.c"
    break;

  case 138:
#line 652 "exprtree.y"
       {(yyval.no) = createIdNode((yyvsp[0].str),NULL,NULL);}
#line 2900 "y.tab.c"
    break;

  case 139:
#line 653 "exprtree.y"
                    {(yyval.no) = createIdNode((yyvsp[-3].str),(yyvsp[-1].no),NULL);}
#line 2906 "y.tab.c"
    break;

  case 140:
#line 654 "exprtree.y"
                                 {(yyval.no) = createIdNode((yyvsp[-6].str),(yyvsp[-4].no),(yyvsp[-1].no));}
#line 2912 "y.tab.c"
    break;

  case 141:
#line 655 "exprtree.y"
          {(yyval.no) = (yyvsp[0].no);}
#line 2918 "y.tab.c"
    break;

  case 142:
#line 658 "exprtree.y"
                      {(yyval.no) = makeDotOperatorNode2((yyvsp[-2].no),(yyvsp[0].str));}
#line 2924 "y.tab.c"
    break;

  case 143:
#line 659 "exprtree.y"
              {(yyval.no) = makeDotOperatorNode1((yyvsp[-2].str),(yyvsp[0].str));}
#line 2930 "y.tab.c"
    break;

  case 144:
#line 660 "exprtree.y"
                {(yyval.no) = makeDotOperatorNode3((yyvsp[0].str));}
#line 2936 "y.tab.c"
    break;

  case 145:
#line 663 "exprtree.y"
                                            {(yyval.no) = makeMethodNode1((yyvsp[-3].str),(yyvsp[-1].no));}
#line 2942 "y.tab.c"
    break;

  case 146:
#line 664 "exprtree.y"
                        {(yyval.no) = makeMethodNode1((yyvsp[-2].str),NULL);}
#line 2948 "y.tab.c"
    break;

  case 147:
#line 665 "exprtree.y"
                              {(yyval.no) = makeMethodNode2((yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[-1].no));}
#line 2954 "y.tab.c"
    break;

  case 148:
#line 666 "exprtree.y"
                      {(yyval.no) = makeMethodNode2((yyvsp[-4].str),(yyvsp[-2].str),NULL);}
#line 2960 "y.tab.c"
    break;

  case 149:
#line 667 "exprtree.y"
                                 {(yyval.no) = makeMethodNode3((yyvsp[-5].no),(yyvsp[-3].str),(yyvsp[-1].no));}
#line 2966 "y.tab.c"
    break;

  case 150:
#line 668 "exprtree.y"
                         {(yyval.no) = makeMethodNode3((yyvsp[-4].no),(yyvsp[-2].str),NULL);}
#line 2972 "y.tab.c"
    break;


#line 2976 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 671 "exprtree.y"


yyerror(char const *s){
    printf("yyerror : %s\n",s);
    printf("Last pattern matched by lex : %s.\n",yytext);
    exit(0);
}


int main(int argc, char* argv[]) {

    FILE* filePointer;
    if(argc > 1){
        filePointer = fopen(argv[1], "r");
        if(filePointer) yyin = filePointer;
    }

    // Initializing the pointer to the top of stack used for codegen part.
    tos = (struct topOfStack*)malloc(sizeof(struct topOfStack));
    tos->top = NULL;

    // Initializing the pointer to the top of global symbol table to null
    gst = (struct globalSymbolTable*) malloc(sizeof(struct globalSymbolTable));
    gst->top = NULL;

    // Intializing the pointer to the top of local symbol table for currently executing function.
    lst = (struct localSymbolTable*) malloc(sizeof(struct localSymbolTable));
    lst->top = NULL;
    lst->type = NULL;
    lst->name = NULL;

    // Initializing the pointer to the top of type table list
    ttt = (struct typeTableList*) malloc(sizeof(struct typeTableList));
    ttt->top = NULL;
    createTypeTable();                // Create type table with default and special entries.

    // Initializing the pointer to the top of class table
    ctt = (struct classTableList*) malloc(sizeof(struct classTableList));
    ctt->top = NULL;

    yyparse();
    fclose(filePointer);
    return 0;
}
