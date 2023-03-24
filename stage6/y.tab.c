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
    NULL_PTR = 302
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

#line 245 "y.tab.c"

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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   825

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


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
      51,    52,     2,     2,    50,     2,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    74,    84,    95,    96,    99,   100,   103,
     118,   127,   135,   138,   152,   157,   161,   172,   175,   176,
     180,   198,   199,   203,   204,   210,   214,   218,   219,   220,
     224,   225,   228,   229,   233,   269,   270,   274,   275,   278,
     279,   280,   285,   289,   292,   307,   322,   332,   342,   345,
     364,   365,   369,   370,   375,   376,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   396,   399,   402,   403,   409,   410,   413,   416,   419,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     445,   450,   456,   457,   458,   459,   460,   461,   463,   464
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
  "ENDTYPE", "ALLOC", "INITIALIZE", "FREE", "NULL_PTR", "'{'", "'}'",
  "','", "'('", "')'", "'['", "']'", "'.'", "$accept", "program",
  "gTypeBlock", "gTypeList", "gType", "typeName", "gTypeDeclList",
  "gTypeDecl", "gTypeIdList", "gDeclBlock", "gDeclList", "gDecl",
  "gidList", "gid", "identifierDecl", "fDefBlock", "fDef", "fName",
  "paramList", "param", "type", "mainBlock", "mainHeader", "lDeclBlock",
  "lDeclList", "lDecl", "lIdList", "lId", "sList", "stmt", "inputStmt",
  "outputStmt", "assignStmt", "ifStmt", "whileStmt", "doWhileStmt",
  "repeatUntilStmt", "expr", "argList", "identifier", "field", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   123,   125,
      44,    40,    41,    91,    93,    46
};
# endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -28,     2,    21,    44,  -101,  -101,    24,  -101,     7,  -101,
       8,    82,    31,  -101,    14,  -101,  -101,    38,    15,  -101,
    -101,  -101,  -101,   154,  -101,    26,     8,    31,  -101,    36,
      46,  -101,    91,    -1,  -101,   105,    65,  -101,  -101,   -12,
      49,     1,  -101,  -101,  -101,  -101,    91,    79,   177,   130,
    -101,  -101,  -101,     6,  -101,    38,   129,    83,  -101,  -101,
      26,   134,    38,  -101,    54,   185,  -101,   198,  -101,   142,
      58,  -101,    71,  -101,    72,  -101,    -2,    74,  -101,   129,
     402,  -101,    95,  -101,   226,   104,  -101,   147,    10,  -101,
    -101,  -101,    89,   120,   106,   124,   132,   140,   422,   187,
     193,   422,   129,   157,   163,   254,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,   194,  -101,    38,  -101,  -101,   213,
      22,   129,   218,   107,   129,  -101,  -101,   548,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     172,   219,   182,   282,  -101,  -101,  -101,    54,    77,  -101,
      74,   129,   129,   129,   450,  -101,  -101,   310,   742,   181,
      74,   189,  -101,   108,  -101,  -101,  -101,   772,   115,   485,
    -101,   589,  -101,    80,    80,  -101,  -101,   802,   802,   802,
     802,   802,   802,   784,   784,   129,  -101,  -101,   190,  -101,
     231,   118,   184,   599,   640,   650,   191,   195,  -101,   235,
     197,  -101,    74,   196,   754,   129,  -101,   200,  -101,   495,
    -101,  -101,   240,   241,   249,   238,   236,   129,   129,  -101,
     256,   257,   217,  -101,   772,   129,  -101,  -101,  -101,  -101,
     422,   422,   691,   701,  -101,  -101,   260,   538,   170,   339,
      -6,   263,  -101,  -101,   422,   264,   265,  -101,  -101,   367,
    -101,  -101,   267,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    10,     6,     0,     8,     0,     1,
       0,     0,     0,     4,     0,     5,     7,     0,     0,    41,
      39,    40,    17,     0,    19,    25,    39,     0,    31,     0,
       0,     3,     0,     0,    12,     0,     0,    16,    18,    27,
       0,     0,    22,    23,    30,     2,     0,     0,     0,     0,
       9,    11,    15,     0,    44,     0,     0,    27,    26,    20,
      25,     0,     0,    46,     0,     0,    48,     0,    13,     0,
       0,    36,     0,    93,   104,    96,     0,     0,    99,     0,
       0,    95,   107,    21,     0,     0,    52,     0,     0,    51,
      45,    47,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    14,     0,    24,    37,     0,
       0,     0,     0,   104,     0,   102,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,    34,    53,    49,     0,     0,    43,
       0,     0,     0,     0,     0,    63,    64,     0,     0,     0,
       0,     0,    54,     0,    35,    38,    97,   101,     0,     0,
     109,     0,    92,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,   108,    33,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,    42,     0,     0,     0,     0,    98,   105,   103,     0,
      32,    65,     0,     0,     0,     0,     0,     0,     0,    69,
       0,    94,     0,    73,   100,     0,    29,    66,    71,    72,
       0,     0,     0,     0,    70,    74,     0,     0,     0,     0,
       0,     0,    68,   106,     0,     0,     0,    78,    79,     0,
      76,    77,     0,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,  -101,   272,  -101,  -101,   246,  -101,  -101,
    -101,   258,  -101,   227,   252,  -101,   262,  -101,   232,   179,
      -4,    25,  -101,   251,  -101,   233,  -101,   155,   -83,  -100,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,   -32,   153,   -67,
    -101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,     8,    33,    34,    53,    12,
      23,    24,    41,    42,    43,    27,    28,    29,    70,    71,
      72,    13,    14,    49,    65,    66,    88,    89,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   167,   168,    81,
      82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,   143,   123,    19,   247,   162,     4,    25,    30,   125,
     126,    59,    76,    35,     1,   154,    68,   114,   157,    25,
     146,     9,   231,    30,    80,    73,    74,    75,     4,    35,
      39,   114,    20,    21,   114,    19,    76,    31,   114,    55,
      40,    56,    19,   162,    64,     5,    18,   127,    50,   124,
      47,    60,    45,    57,   162,    17,    69,   162,    86,    77,
     147,    64,    32,    40,    26,    21,    36,    15,    87,    78,
     158,    20,    21,    79,   166,   118,   114,    10,   123,    11,
      73,    74,    75,   192,    46,   119,    19,   114,    76,   169,
     114,    76,   171,   200,   130,   131,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   116,    52,
     117,    73,    74,    75,    77,    20,    21,    54,    22,   193,
     194,   195,    76,   120,    78,   121,    48,   122,    79,   190,
      62,   204,    73,    74,    75,   221,    56,    67,   162,   162,
     148,    84,   121,    76,   122,   202,   115,   238,   239,   162,
     141,   145,   203,   209,   116,    78,   144,   150,    19,    79,
     121,   249,   122,   114,   114,   205,    77,   206,   205,   149,
     212,   114,   114,   224,    92,   151,    78,   114,    94,    95,
      79,    19,   114,   152,    76,   232,   233,    20,    21,    19,
      37,   153,    96,   237,   244,   245,    97,   155,    98,    99,
     100,   101,    92,   156,    93,   163,    94,    95,   159,   102,
      20,    21,    76,    63,   160,   103,   104,   165,    20,    21,
      96,    90,   170,   186,    97,   185,    98,    99,   100,   101,
      92,   187,   142,   199,    94,    95,   213,   102,   201,   210,
      76,   211,   217,   103,   104,   219,   218,   222,    96,   220,
     227,   228,    97,   225,    98,    99,   100,   101,    92,   229,
     161,   230,    94,    95,   231,   102,   234,   235,    76,   236,
     242,   103,   104,   248,   250,   251,    96,   253,    16,    51,
      97,    38,    98,    99,   100,   101,    92,    83,   188,    44,
      94,    95,    58,   102,    85,   164,    76,    61,    91,   103,
     104,   191,   189,     0,    96,     0,     0,     0,    97,     0,
      98,    99,   100,   101,    92,     0,     0,     0,    94,    95,
       0,   102,     0,     0,    76,     0,     0,   103,   104,     0,
       0,     0,    96,     0,     0,     0,    97,     0,    98,    99,
     100,   101,   197,    92,     0,     0,     0,    94,    95,   102,
       0,     0,     0,    76,     0,   103,   104,     0,     0,     0,
       0,    96,     0,     0,     0,    97,   246,    98,    99,   100,
     101,    92,     0,     0,     0,    94,    95,     0,   102,     0,
       0,    76,     0,     0,   103,   104,     0,     0,     0,    96,
       0,     0,   252,    97,     0,    98,    99,   100,   101,     0,
       0,     0,     0,     0,     0,     0,   102,     0,     0,     0,
       0,     0,   103,   104,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,    92,     0,     0,     0,
      94,    95,     0,     0,     0,     0,    76,     0,     0,     0,
       0,     0,   138,   139,    96,     0,     0,     0,    97,     0,
      98,    99,   100,   101,    92,     0,   140,     0,    94,    95,
       0,   102,     0,     0,    76,     0,     0,   103,   104,     0,
       0,     0,    96,     0,     0,     0,   196,     0,    98,    99,
     100,   101,     0,     0,     0,     0,     0,     0,     0,   102,
       0,     0,     0,     0,     0,   103,   104,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,     0,     0,   207,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
       0,     0,   243,     0,     0,     0,     0,     0,     0,     0,
     172,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   214,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   240,     0,     0,     0,     0,     0,     0,
       0,     0,   198,   241,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   223,     0,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,   138,   139,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,   138,   139,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      67,    84,     4,     4,    10,   105,     4,    11,    12,    76,
      77,    10,    14,    17,    42,    98,    10,    84,   101,    23,
      10,     0,    28,    27,    56,     3,     4,     5,     4,    33,
       4,    98,    33,    34,   101,     4,    14,    12,   105,    51,
      14,    53,     4,   143,    48,    43,    38,    79,    49,    51,
       4,    50,    27,     4,   154,    48,    50,   157,     4,    37,
      50,    65,    48,    14,    33,    34,    51,    43,    14,    47,
     102,    33,    34,    51,    52,     4,   143,    33,     4,    35,
       3,     4,     5,   150,    48,    14,     4,   154,    14,   121,
     157,    14,   124,   160,    14,    15,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    50,     4,
      52,     3,     4,     5,    37,    33,    34,    52,    36,   151,
     152,   153,    14,    51,    47,    53,    35,    55,    51,    52,
      51,   163,     3,     4,     5,   202,    53,     7,   238,   239,
      51,     7,    53,    14,    55,    37,     4,   230,   231,   249,
      55,     4,    44,   185,    50,    47,    52,    51,     4,    51,
      53,   244,    55,   230,   231,    50,    37,    52,    50,    49,
      52,   238,   239,   205,     4,    51,    47,   244,     8,     9,
      51,     4,   249,    51,    14,   217,   218,    33,    34,     4,
      36,    51,    22,   225,    24,    25,    26,    10,    28,    29,
      30,    31,     4,    10,     6,    11,     8,     9,    51,    39,
      33,    34,    14,    36,    51,    45,    46,     4,    33,    34,
      22,    36,     4,     4,    26,    53,    28,    29,    30,    31,
       4,    49,     6,    52,     8,     9,    52,    39,    49,    49,
      14,    10,    51,    45,    46,    10,    51,    51,    22,    52,
      10,    10,    26,    53,    28,    29,    30,    31,     4,    10,
       6,    23,     8,     9,    28,    39,    10,    10,    14,    52,
      10,    45,    46,    10,    10,    10,    22,    10,     6,    33,
      26,    23,    28,    29,    30,    31,     4,    60,     6,    27,
       8,     9,    40,    39,    62,   116,    14,    46,    65,    45,
      46,   148,   147,    -1,    22,    -1,    -1,    -1,    26,    -1,
      28,    29,    30,    31,     4,    -1,    -1,    -1,     8,     9,
      -1,    39,    -1,    -1,    14,    -1,    -1,    45,    46,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,    -1,    28,    29,
      30,    31,    32,     4,    -1,    -1,    -1,     8,     9,    39,
      -1,    -1,    -1,    14,    -1,    45,    46,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,     4,    -1,    -1,    -1,     8,     9,    -1,    39,    -1,
      -1,    14,    -1,    -1,    45,    46,    -1,    -1,    -1,    22,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,     4,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    40,    41,    22,    -1,    -1,    -1,    26,    -1,
      28,    29,    30,    31,     4,    -1,    54,    -1,     8,     9,
      -1,    39,    -1,    -1,    14,    -1,    -1,    45,    46,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    52,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    40,    41,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    57,    58,     4,    43,    59,    60,    61,     0,
      33,    35,    65,    77,    78,    43,    60,    48,    38,     4,
      33,    34,    36,    66,    67,    76,    33,    71,    72,    73,
      76,    77,    48,    62,    63,    76,    51,    36,    67,     4,
      14,    68,    69,    70,    72,    77,    48,     4,    35,    79,
      49,    63,     4,    64,    52,    51,    53,     4,    70,    10,
      50,    79,    51,    36,    76,    80,    81,     7,    10,    50,
      74,    75,    76,     3,     4,     5,    14,    37,    47,    51,
      93,    95,    96,    69,     7,    74,     4,    14,    82,    83,
      36,    81,     4,     6,     8,     9,    22,    26,    28,    29,
      30,    31,    39,    45,    46,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    95,     4,    50,    52,     4,    14,
      51,    53,    55,     4,    51,    95,    95,    93,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    40,    41,
      54,    55,     6,    84,    52,     4,    10,    50,    51,    49,
      51,    51,    51,    51,    84,    10,    10,    84,    93,    51,
      51,     6,    85,    11,    75,     4,    52,    93,    94,    93,
       4,    93,    52,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    53,     4,    49,     6,    83,
      52,    94,    95,    93,    93,    93,    26,    32,    10,    52,
      95,    49,    37,    44,    93,    50,    52,    54,    52,    93,
      49,    10,    52,    52,    52,    52,    52,    51,    51,    10,
      52,    95,    51,    10,    93,    53,    54,    10,    10,    10,
      23,    28,    93,    93,    10,    10,    52,    93,    84,    84,
      52,    52,    10,    54,    24,    25,    27,    10,    10,    84,
      10,    10,    25,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    62,    62,    63,    64,    64,    65,    65,    66,    66,
      67,    68,    68,    69,    69,    69,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    74,    74,    75,    75,    76,
      76,    76,    77,    77,    78,    79,    79,    80,    80,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    87,    88,    88,    89,    89,    90,    91,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    95,    95,    95,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     2,     1,     4,
       1,     2,     1,     3,     3,     1,     3,     2,     2,     1,
       3,     3,     1,     1,     4,     0,     2,     1,     4,     7,
       2,     1,     7,     6,     5,     3,     1,     2,     3,     1,
       1,     1,     7,     6,     4,     3,     2,     2,     1,     3,
       3,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     5,     3,     6,     4,
       5,     5,     5,     4,     5,    10,     8,     8,     7,     7,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     1,     1,     3,     4,     1,
       3,     1,     2,     4,     1,     4,     7,     1,     3,     3
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
#line 66 "exprtree.y"
                                                    {
      printTypeTable();
      printGlobalSymbolTable();
      printLocalSymbolTable();
      {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,emptyNode,(yyvsp[-1].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
      // Call codegen
      helperFunction((yyval.no));
    }
#line 1713 "y.tab.c"
    break;

  case 3:
#line 74 "exprtree.y"
                                    {
      printTypeTable();
      printGlobalSymbolTable();
      printLocalSymbolTable();
      printf("\n");
      // printPrefix($3);
      (yyval.no) = createTree(noNumber,tLookup("void"),NULL,emptyNode,(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL);  
      // Call codegen
      helperFunction((yyval.no));
    }
#line 1728 "y.tab.c"
    break;

  case 4:
#line 84 "exprtree.y"
                         {
      printTypeTable();
      (yyval.no) = createTree(noNumber,tLookup("void"),NULL,emptyNode,(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL);
      // Call codegen
      helperFunction((yyval.no));  
    }
#line 1739 "y.tab.c"
    break;

  case 5:
#line 95 "exprtree.y"
                                    {}
#line 1745 "y.tab.c"
    break;

  case 6:
#line 96 "exprtree.y"
                 {}
#line 1751 "y.tab.c"
    break;

  case 7:
#line 99 "exprtree.y"
                            {}
#line 1757 "y.tab.c"
    break;

  case 8:
#line 100 "exprtree.y"
          {}
#line 1763 "y.tab.c"
    break;

  case 9:
#line 103 "exprtree.y"
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
#line 1781 "y.tab.c"
    break;

  case 10:
#line 118 "exprtree.y"
              {
      struct typeTable* type = tLookup((yyvsp[0].str));
      if(type) yyerror("Multiple used defined data types with same name found !!");

      tInstall((yyvsp[0].str),undefined,NULL);
      (yyval.str) = (yyvsp[0].str);
    }
#line 1793 "y.tab.c"
    break;

  case 11:
#line 127 "exprtree.y"
                                        {
      struct fieldList* f1 = (yyvsp[-1].fl);
      struct fieldList* f2 = (yyvsp[0].fl);

      while(f2->next) f2 = f2->next;
      f2->next = f1;
      (yyval.fl) = (yyvsp[0].fl);
    }
#line 1806 "y.tab.c"
    break;

  case 12:
#line 135 "exprtree.y"
              {(yyval.fl) = (yyvsp[0].fl);}
#line 1812 "y.tab.c"
    break;

  case 13:
#line 138 "exprtree.y"
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
#line 1829 "y.tab.c"
    break;

  case 14:
#line 152 "exprtree.y"
                                 {
      struct fieldList* node = makeFieldNode((yyvsp[0].str),NULL);
      node->next = (yyvsp[-2].fl);
      (yyval.fl) = node;
    }
#line 1839 "y.tab.c"
    break;

  case 15:
#line 157 "exprtree.y"
       {(yyval.fl) = makeFieldNode((yyvsp[0].str),NULL);}
#line 1845 "y.tab.c"
    break;

  case 16:
#line 161 "exprtree.y"
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
#line 1861 "y.tab.c"
    break;

  case 20:
#line 180 "exprtree.y"
                               {
      // Adding type of variables for the entries in global symbol table
      struct gsymbol* top = gst->top;
      struct typeTable* type = tLookup((yyvsp[-2].str));
      while(top){
        if(top->type == NULL){
          if(top->ispointer){
            if(type == tLookup("int")) top->type = tLookup("intPtr");
            else if(type == tLookup("str")) top->type = tLookup("strPtr");
            else yyerror("Pointer is not supported for user defined data types");
          }
          else  top->type = type;
        }
        top = top->next;
      }
    }
#line 1882 "y.tab.c"
    break;

  case 24:
#line 204 "exprtree.y"
                         {
      // Making an entry in gst for function and also assigning label for that function.
      gInstall((yyvsp[-3].str),NULL,0,0,0,(yyvsp[-1].pl));
      struct gsymbol* node = gLookup((yyvsp[-3].str));
      node->flabel = ++fLabel;
    }
#line 1893 "y.tab.c"
    break;

  case 26:
#line 214 "exprtree.y"
                                      {
      struct gsymbol* node = gLookup((yyvsp[0].str));
      node->ispointer = 1;
    }
#line 1902 "y.tab.c"
    break;

  case 27:
#line 218 "exprtree.y"
        {gInstall((yyvsp[0].str),NULL,0,0,0,NULL); (yyval.str) = (yyvsp[0].str);}
#line 1908 "y.tab.c"
    break;

  case 28:
#line 219 "exprtree.y"
                    {gInstall((yyvsp[-3].str),NULL,0,(yyvsp[-1].no)->val,0,NULL); (yyval.str) = (yyvsp[-3].str);}
#line 1914 "y.tab.c"
    break;

  case 29:
#line 220 "exprtree.y"
                                 {gInstall((yyvsp[-6].str),NULL,0,(yyvsp[-4].no)->val,(yyvsp[-1].no)->val,NULL); (yyval.str) = (yyvsp[-6].str);}
#line 1920 "y.tab.c"
    break;

  case 30:
#line 224 "exprtree.y"
                           {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,emptyNode,(yyvsp[-1].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 1926 "y.tab.c"
    break;

  case 31:
#line 225 "exprtree.y"
         {(yyval.no) = (yyvsp[0].no);}
#line 1932 "y.tab.c"
    break;

  case 32:
#line 228 "exprtree.y"
                                              {(yyval.no) = createFunkNode((yyvsp[-6].str),(yyvsp[-2].no));}
#line 1938 "y.tab.c"
    break;

  case 33:
#line 229 "exprtree.y"
                                       {(yyval.no) = NULL;}
#line 1944 "y.tab.c"
    break;

  case 34:
#line 233 "exprtree.y"
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
#line 1983 "y.tab.c"
    break;

  case 35:
#line 269 "exprtree.y"
                                {(yyvsp[0].pl)->next = (yyvsp[-2].pl); (yyval.pl) = (yyvsp[0].pl);}
#line 1989 "y.tab.c"
    break;

  case 36:
#line 270 "exprtree.y"
          {(yyval.pl) = (yyvsp[0].pl);}
#line 1995 "y.tab.c"
    break;

  case 37:
#line 274 "exprtree.y"
                {(yyval.pl) = makeParamNode(tLookup((yyvsp[-1].str)),(yyvsp[0].str),0);}
#line 2001 "y.tab.c"
    break;

  case 38:
#line 275 "exprtree.y"
                 {(yyval.pl) = makeParamNode(tLookup((yyvsp[-2].str)),(yyvsp[0].str),1);}
#line 2007 "y.tab.c"
    break;

  case 39:
#line 278 "exprtree.y"
           {(yyval.str) = (yyvsp[0].str);}
#line 2013 "y.tab.c"
    break;

  case 40:
#line 279 "exprtree.y"
        {(yyval.str) = (yyvsp[0].str);}
#line 2019 "y.tab.c"
    break;

  case 41:
#line 280 "exprtree.y"
       {(yyval.str) = (yyvsp[0].str);}
#line 2025 "y.tab.c"
    break;

  case 42:
#line 285 "exprtree.y"
                                                        {
      // Make an connector node and return that node
      (yyval.no) = createMainNode((yyvsp[-6].str),(yyvsp[-2].no));
    }
#line 2034 "y.tab.c"
    break;

  case 43:
#line 289 "exprtree.y"
                                          {}
#line 2040 "y.tab.c"
    break;

  case 44:
#line 292 "exprtree.y"
                              {
      char* temp = malloc(5);
      memcpy(temp, "main\0", 5);

      gInstall(temp,tLookup("int"),0,0,0,NULL);
      struct gsymbol* node = gLookup(temp);
      node->ltop = NULL;
      node->flabel = ++fLabel;

      (yyval.str) = temp;
    }
#line 2056 "y.tab.c"
    break;

  case 45:
#line 307 "exprtree.y"
                                    {
      char* funkName = (yyvsp[(-1) - (3)].str);

      // Joining this local symbol table to the (ltop field of gsymbol)
      struct gsymbol* gnode = gLookup(funkName);
      struct lsymbol* top = (yyvsp[-1].lnode);

      while(top->next) top=top->next;
      top->next = gnode->ltop;
      gnode->ltop = (yyvsp[-1].lnode);

      // initializing lst value to current local symbol table for making an expression tree
      lst->top = (yyvsp[-1].lnode);
      lst->name = funkName;
    }
#line 2076 "y.tab.c"
    break;

  case 46:
#line 322 "exprtree.y"
                 {
      char* funkName = (yyvsp[(-1) - (2)].str);
      struct gsymbol* gnode = gLookup(funkName);

      // initializing lst value to current local symbol table for making an expression tree
      lst->top = gnode->ltop;
      lst->name = funkName;
    }
#line 2089 "y.tab.c"
    break;

  case 47:
#line 332 "exprtree.y"
                            {
      // Both lDeclList and lDecl contains the pointer to head of the linked list of lsymbol node
      struct lsymbol* l1 = (yyvsp[-1].lnode);
      struct lsymbol* l2 = (yyvsp[0].lnode);

      // Get the last node of list2
      while(l2->next) l2 = l2->next;
      l2->next = l1;
      (yyval.lnode) = (yyvsp[0].lnode);
    }
#line 2104 "y.tab.c"
    break;

  case 48:
#line 342 "exprtree.y"
          {(yyval.lnode) = (yyvsp[0].lnode);}
#line 2110 "y.tab.c"
    break;

  case 49:
#line 345 "exprtree.y"
                               {
      struct lsymbol* top = (yyvsp[-1].lnode);
      struct typeTable* type = tLookup((yyvsp[-2].str));

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
#line 2132 "y.tab.c"
    break;

  case 50:
#line 364 "exprtree.y"
                          {(yyvsp[0].lnode)->next = (yyvsp[-2].lnode); (yyval.lnode) = (yyvsp[0].lnode);}
#line 2138 "y.tab.c"
    break;

  case 51:
#line 365 "exprtree.y"
        {(yyval.lnode) = (yyvsp[0].lnode);}
#line 2144 "y.tab.c"
    break;

  case 52:
#line 369 "exprtree.y"
         {(yyval.lnode) = makeLSymbolNode((yyvsp[0].str),NULL,0);}
#line 2150 "y.tab.c"
    break;

  case 53:
#line 370 "exprtree.y"
            {(yyval.lnode) = makeLSymbolNode((yyvsp[0].str),NULL,1);}
#line 2156 "y.tab.c"
    break;

  case 54:
#line 375 "exprtree.y"
                   {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,emptyNode,(yyvsp[-1].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2162 "y.tab.c"
    break;

  case 55:
#line 376 "exprtree.y"
         {(yyval.no) = (yyvsp[0].no);}
#line 2168 "y.tab.c"
    break;

  case 56:
#line 379 "exprtree.y"
                 {(yyval.no) = (yyvsp[0].no);}
#line 2174 "y.tab.c"
    break;

  case 57:
#line 380 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 2180 "y.tab.c"
    break;

  case 58:
#line 381 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 2186 "y.tab.c"
    break;

  case 59:
#line 382 "exprtree.y"
           {(yyval.no) = (yyvsp[0].no);}
#line 2192 "y.tab.c"
    break;

  case 60:
#line 383 "exprtree.y"
              {(yyval.no) = (yyvsp[0].no);}
#line 2198 "y.tab.c"
    break;

  case 61:
#line 384 "exprtree.y"
                {(yyval.no) = (yyvsp[0].no);}
#line 2204 "y.tab.c"
    break;

  case 62:
#line 385 "exprtree.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 2210 "y.tab.c"
    break;

  case 63:
#line 386 "exprtree.y"
                    {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,breakNode,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2216 "y.tab.c"
    break;

  case 64:
#line 387 "exprtree.y"
                       {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,continueNode,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2222 "y.tab.c"
    break;

  case 65:
#line 388 "exprtree.y"
                         {(yyval.no) = createCallerNode((yyvsp[-3].str),NULL);}
#line 2228 "y.tab.c"
    break;

  case 66:
#line 389 "exprtree.y"
                                 {(yyval.no) = createCallerNode((yyvsp[-4].str),(yyvsp[-2].no));}
#line 2234 "y.tab.c"
    break;

  case 67:
#line 390 "exprtree.y"
                          {(yyval.no) = createReturnNode(lst->name,(yyvsp[-1].no));}
#line 2240 "y.tab.c"
    break;

  case 68:
#line 391 "exprtree.y"
                                                {(yyval.no) = makeAllocNode((yyvsp[-5].no));}
#line 2246 "y.tab.c"
    break;

  case 69:
#line 392 "exprtree.y"
                                       {(yyval.no) = makeMemInitNode();}
#line 2252 "y.tab.c"
    break;

  case 70:
#line 393 "exprtree.y"
                                            {(yyval.no) = makeFreeNode((yyvsp[-2].no));}
#line 2258 "y.tab.c"
    break;

  case 71:
#line 396 "exprtree.y"
                                              {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,readNode,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL);}
#line 2264 "y.tab.c"
    break;

  case 72:
#line 399 "exprtree.y"
                                          {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,writeNode,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL);}
#line 2270 "y.tab.c"
    break;

  case 73:
#line 402 "exprtree.y"
                                              {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,assignNode,(yyvsp[-3].no),(yyvsp[-1].no),NULL,NULL,NULL,NULL);}
#line 2276 "y.tab.c"
    break;

  case 74:
#line 403 "exprtree.y"
                                                {
      struct tnode* newAddrNode = createAddrNode((yyvsp[-1].no));
      (yyval.no) = createTree(noNumber,tLookup("void"),NULL,assignNode,(yyvsp[-4].no),newAddrNode,NULL,NULL,NULL,NULL);
    }
#line 2285 "y.tab.c"
    break;

  case 75:
#line 409 "exprtree.y"
                                                               {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,ifElseNode,(yyvsp[-4].no),(yyvsp[-2].no),(yyvsp[-7].no),NULL,NULL,NULL);}
#line 2291 "y.tab.c"
    break;

  case 76:
#line 410 "exprtree.y"
                                               {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,ifElseNode,(yyvsp[-2].no),NULL,(yyvsp[-5].no),NULL,NULL,NULL);}
#line 2297 "y.tab.c"
    break;

  case 77:
#line 413 "exprtree.y"
                                                            {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,whileNode,(yyvsp[-2].no),NULL,(yyvsp[-5].no),NULL,NULL,NULL);}
#line 2303 "y.tab.c"
    break;

  case 78:
#line 416 "exprtree.y"
                                                    {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,doWhileNode,(yyvsp[-5].no),NULL,(yyvsp[-2].no),NULL,NULL,NULL);}
#line 2309 "y.tab.c"
    break;

  case 79:
#line 419 "exprtree.y"
                                                            {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,repeatUntilNode,(yyvsp[-5].no),NULL,(yyvsp[-2].no),NULL,NULL,NULL);}
#line 2315 "y.tab.c"
    break;

  case 80:
#line 423 "exprtree.y"
                       {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,addNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2321 "y.tab.c"
    break;

  case 81:
#line 424 "exprtree.y"
                      {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,subNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2327 "y.tab.c"
    break;

  case 82:
#line 425 "exprtree.y"
                   {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,mulNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2333 "y.tab.c"
    break;

  case 83:
#line 426 "exprtree.y"
                  {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,divNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2339 "y.tab.c"
    break;

  case 84:
#line 427 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,lessNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2345 "y.tab.c"
    break;

  case 85:
#line 428 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,greaterNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2351 "y.tab.c"
    break;

  case 86:
#line 429 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,lessEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2357 "y.tab.c"
    break;

  case 87:
#line 430 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,greaterEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2363 "y.tab.c"
    break;

  case 88:
#line 431 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,notEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2369 "y.tab.c"
    break;

  case 89:
#line 432 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,equalNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2375 "y.tab.c"
    break;

  case 90:
#line 433 "exprtree.y"
                  {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,andNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2381 "y.tab.c"
    break;

  case 91:
#line 434 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,orNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2387 "y.tab.c"
    break;

  case 92:
#line 435 "exprtree.y"
                 {(yyval.no) = (yyvsp[-1].no);}
#line 2393 "y.tab.c"
    break;

  case 93:
#line 436 "exprtree.y"
        {(yyval.no) = (yyvsp[0].no);}
#line 2399 "y.tab.c"
    break;

  case 94:
#line 437 "exprtree.y"
                    {(yyval.no) = createAddrNode((yyvsp[0].no));}
#line 2405 "y.tab.c"
    break;

  case 95:
#line 438 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 2411 "y.tab.c"
    break;

  case 96:
#line 439 "exprtree.y"
           {(yyval.no) = (yyvsp[0].no);}
#line 2417 "y.tab.c"
    break;

  case 97:
#line 440 "exprtree.y"
               {(yyval.no) = createCallerNode((yyvsp[-2].str),NULL);}
#line 2423 "y.tab.c"
    break;

  case 98:
#line 441 "exprtree.y"
                       {(yyval.no) = createCallerNode((yyvsp[-3].str),(yyvsp[-1].no));}
#line 2429 "y.tab.c"
    break;

  case 99:
#line 442 "exprtree.y"
             {(yyval.no) = makeNullNode();}
#line 2435 "y.tab.c"
    break;

  case 100:
#line 445 "exprtree.y"
                           {
      struct tnode* temp = createArgsNode((yyvsp[0].no));
      temp->arglist = (yyvsp[-2].no);
      (yyval.no) = temp;
    }
#line 2445 "y.tab.c"
    break;

  case 101:
#line 450 "exprtree.y"
         {(yyval.no) = createArgsNode((yyvsp[0].no));}
#line 2451 "y.tab.c"
    break;

  case 102:
#line 456 "exprtree.y"
                             {(yyval.no) = createStarNode((yyvsp[0].no));}
#line 2457 "y.tab.c"
    break;

  case 103:
#line 457 "exprtree.y"
                      {(yyval.no) = createStarNode((yyvsp[-1].no));}
#line 2463 "y.tab.c"
    break;

  case 104:
#line 458 "exprtree.y"
       {(yyval.no) = createIdNode((yyvsp[0].str),NULL,NULL);}
#line 2469 "y.tab.c"
    break;

  case 105:
#line 459 "exprtree.y"
                    {(yyval.no) = createIdNode((yyvsp[-3].str),(yyvsp[-1].no),NULL);}
#line 2475 "y.tab.c"
    break;

  case 106:
#line 460 "exprtree.y"
                                 {(yyval.no) = createIdNode((yyvsp[-6].str),(yyvsp[-4].no),(yyvsp[-1].no));}
#line 2481 "y.tab.c"
    break;

  case 107:
#line 461 "exprtree.y"
          {(yyval.no) = (yyvsp[0].no);}
#line 2487 "y.tab.c"
    break;

  case 108:
#line 463 "exprtree.y"
                      {(yyval.no) = makeDotOperatorNode2((yyvsp[-2].no),(yyvsp[0].str));}
#line 2493 "y.tab.c"
    break;

  case 109:
#line 464 "exprtree.y"
              {(yyval.no) = makeDotOperatorNode1((yyvsp[-2].str),(yyvsp[0].str));}
#line 2499 "y.tab.c"
    break;


#line 2503 "y.tab.c"

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
#line 467 "exprtree.y"


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
    lst->name = NULL;

    // Initializing the pointer to the top of type table list
    ttt = (struct typeTableList*) malloc(sizeof(struct typeTableList));
    ttt->top = NULL;
    createTypeTable();                // Create type table with default and special entries.

    yyparse();
    fclose(filePointer);
    return 0;
}
