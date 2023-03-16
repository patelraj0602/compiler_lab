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
    RETURN = 294
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

#line 228 "y.tab.c"

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   653

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

#define YYUNDEFTOK  2
#define YYMAXUTOK   294


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
      41,    42,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    75,    85,    92,   103,   106,   107,   111,
     124,   125,   129,   130,   136,   140,   144,   145,   146,   150,
     151,   154,   155,   159,   194,   195,   199,   200,   203,   204,
     209,   213,   216,   230,   245,   253,   263,   266,   279,   280,
     284,   285,   290,   291,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   308,   311,   314,   315,
     321,   322,   325,   328,   331,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   353,   358,   363,   364,   365,   366,   367
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
  "STR", "DECL", "ENDDECL", "ADDR", "MAIN", "RETURN", "','", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "$accept", "program", "gDeclBlock",
  "gDeclList", "gDecl", "gidList", "gid", "identifierDecl", "fDefBlock",
  "fDef", "fName", "paramList", "param", "type", "mainBlock", "mainHeader",
  "lDeclBlock", "lDeclList", "lDecl", "lIdList", "lId", "sList", "stmt",
  "inputStmt", "outputStmt", "assignStmt", "ifStmt", "whileStmt",
  "doWhileStmt", "repeatUntilStmt", "expr", "argList", "identifier", YY_NULLPTR
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
      44,    40,    41,    91,    93,   123,   125
};
# endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -33,    68,    25,    89,   -79,   -17,     9,   -79,   -79,
     -79,    73,   -79,    26,   -79,   -33,    89,   -79,    19,    65,
     -79,    37,    55,   -79,   -79,    78,    29,     4,   -79,   -79,
     -79,   -79,    37,    71,    77,   121,   -79,   108,    48,   107,
     -79,   -79,    26,   125,   108,   -79,    54,    84,   -79,   171,
      63,   -79,    57,   -79,    83,   -79,    -3,    48,   424,   -79,
     -79,   199,    91,   -79,   149,    27,   -79,   -79,   -79,    93,
     112,   118,   120,   122,   123,   368,   152,   156,   368,    48,
     227,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   159,
     108,   -79,   -79,   172,     5,    48,   135,    48,   -79,   487,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
     138,   137,   255,   -79,   -79,   -79,    54,    18,   -79,    62,
      48,    48,    48,   396,   -79,   -79,   283,   620,   140,   -79,
      51,   -79,   -79,   -79,   599,    95,   434,   497,   -79,    76,
      76,   -79,   -79,    81,    81,    81,    81,    81,    81,    48,
     -79,   141,   -79,   174,   106,   146,   528,   538,   548,   148,
     150,   -79,   -79,    62,   632,    48,   -79,   147,   -79,   444,
     -79,   -79,   182,   184,   185,   173,   170,    48,    48,   194,
     -79,   599,    48,   -79,   -79,   -79,   -79,   368,   368,   579,
     589,   -79,   477,   143,   312,    14,   196,   -79,   368,   201,
     202,   -79,   -79,   340,   -79,   -79,   204,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,     0,    28,    29,
       6,     0,     8,    14,     1,    28,     0,    20,     0,     0,
       3,     0,     0,     5,     7,    16,     0,     0,    11,    12,
      19,     2,     0,     0,     0,     0,    32,     0,     0,    16,
      15,     9,    14,     0,     0,    34,     0,     0,    36,     0,
       0,    25,     0,    76,    85,    78,     0,     0,     0,    77,
      10,     0,     0,    40,     0,     0,    39,    33,    35,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    44,    45,    46,    47,    48,    49,    50,     0,
       0,    13,    26,     0,     0,     0,    85,     0,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,    23,    41,    37,     0,     0,    31,     0,
       0,     0,     0,     0,    51,    52,     0,     0,     0,    42,
       0,    24,    27,    79,    82,     0,     0,     0,    75,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
      22,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    30,     0,     0,     0,    80,    86,    84,     0,
      21,    53,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    81,     0,    18,    54,    56,    57,     0,     0,     0,
       0,    59,     0,     0,     0,     0,     0,    87,     0,     0,
       0,    63,    64,     0,    61,    62,     0,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   -79,   198,   -79,   175,   189,   -79,   200,
     -79,   176,   128,     2,    11,   -79,   187,   -79,   177,   -79,
     110,   -58,   -78,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -22,   105,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    11,    12,    27,    28,    29,    16,    17,
      18,    50,    51,    52,     5,     6,    35,    47,    48,    65,
      66,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     134,   135,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      89,    96,   129,   112,    13,     7,    19,    98,    53,    54,
      55,    56,    89,    13,    41,    20,    58,   123,    19,    56,
     126,    53,    54,    55,   201,    14,    89,    31,    21,    89,
      25,    89,    56,    39,   129,    99,    46,   115,    97,     1,
      26,     2,   188,    26,    42,   129,    57,   133,   129,    46,
      22,    53,    54,    55,    53,    54,    55,   127,    63,    57,
     153,    92,    56,    89,    32,    56,    96,   116,    64,    33,
     155,    93,    34,   136,    89,   137,    56,    89,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   163,    57,
     102,   103,    57,   100,   101,   102,   103,    36,   156,   157,
     158,     8,     9,    90,    10,    91,     8,     9,   164,    23,
       8,     9,    44,    45,   179,   129,   129,     8,     9,    37,
      67,    38,    15,     9,    94,   129,    95,   169,    49,   193,
     194,    90,    61,   113,   117,   165,    95,   166,    89,    89,
     203,     8,     9,   181,    89,    89,   165,    69,   172,    89,
      38,    71,    72,   114,    89,   189,   190,    56,   118,   119,
     192,   120,   124,   121,   122,    73,   125,   198,   199,    74,
     130,    75,    76,    77,    78,    69,   132,    70,    95,    71,
      72,   149,    79,   150,   171,    56,   162,   170,   173,   177,
     182,   178,   184,    73,   185,   186,   187,    74,   188,    75,
      76,    77,    78,    69,   191,   111,   202,    71,    72,    24,
      79,   204,   205,    56,   207,    40,    30,    60,   131,    43,
      62,    73,   154,     0,    68,    74,   152,    75,    76,    77,
      78,    69,     0,   128,     0,    71,    72,     0,    79,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,    74,     0,    75,    76,    77,    78,    69,
       0,   151,     0,    71,    72,     0,    79,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,    74,     0,    75,    76,    77,    78,    69,     0,     0,
       0,    71,    72,     0,    79,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,     0,    74,
       0,    75,    76,    77,    78,   160,    69,     0,     0,     0,
      71,    72,    79,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,     0,    74,   200,
      75,    76,    77,    78,    69,     0,     0,     0,    71,    72,
       0,    79,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,    73,     0,     0,   206,    74,     0,    75,    76,
      77,    78,    69,     0,     0,     0,    71,    72,     0,    79,
       0,     0,    56,     0,     0,     0,     0,     0,     0,     0,
      73,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      69,     0,     0,     0,    71,    72,     0,    79,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,   159,     0,    75,    76,    77,    78,     0,     0,
       0,     0,     0,     0,     0,    79,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,   197,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   195,     0,     0,     0,     0,     0,     0,     0,     0,
     161,   196,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   180,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109
};

static const yytype_int16 yycheck[] =
{
      49,     4,    80,    61,     2,    38,     4,    56,     3,     4,
       5,    14,    61,    11,    10,     4,    38,    75,    16,    14,
      78,     3,     4,     5,    10,     0,    75,    16,    45,    78,
       4,    80,    14,     4,   112,    57,    34,    10,    41,    33,
      14,    35,    28,    14,    40,   123,    41,    42,   126,    47,
      41,     3,     4,     5,     3,     4,     5,    79,     4,    41,
      42,     4,    14,   112,    45,    14,     4,    40,    14,     4,
     119,    14,    35,    95,   123,    97,    14,   126,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    37,    41,
      14,    15,    41,    12,    13,    14,    15,    42,   120,   121,
     122,    33,    34,    40,    36,    42,    33,    34,   130,    36,
      33,    34,    41,    36,   163,   193,   194,    33,    34,    41,
      36,    43,    33,    34,    41,   203,    43,   149,     7,   187,
     188,    40,     7,    42,    41,    40,    43,    42,   187,   188,
     198,    33,    34,   165,   193,   194,    40,     4,    42,   198,
      43,     8,     9,     4,   203,   177,   178,    14,    46,    41,
     182,    41,    10,    41,    41,    22,    10,    24,    25,    26,
      11,    28,    29,    30,    31,     4,     4,     6,    43,     8,
       9,    43,    39,    46,    10,    14,    46,    46,    42,    41,
      43,    41,    10,    22,    10,    10,    23,    26,    28,    28,
      29,    30,    31,     4,    10,     6,    10,     8,     9,    11,
      39,    10,    10,    14,    10,    26,    16,    42,    90,    32,
      44,    22,   117,    -1,    47,    26,   116,    28,    29,    30,
      31,     4,    -1,     6,    -1,     8,     9,    -1,    39,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    26,    -1,    28,    29,    30,    31,     4,
      -1,     6,    -1,     8,     9,    -1,    39,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    26,    -1,    28,    29,    30,    31,     4,    -1,    -1,
      -1,     8,     9,    -1,    39,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    26,
      -1,    28,    29,    30,    31,    32,     4,    -1,    -1,    -1,
       8,     9,    39,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,     4,    -1,    -1,    -1,     8,     9,
      -1,    39,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,     4,    -1,    -1,    -1,     8,     9,    -1,    39,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    26,    -1,    28,    29,    30,    31,
       4,    -1,    -1,    -1,     8,     9,    -1,    39,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    26,    -1,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    42,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    35,    48,    49,    61,    62,    38,    33,    34,
      36,    50,    51,    60,     0,    33,    55,    56,    57,    60,
      61,    45,    41,    36,    51,     4,    14,    52,    53,    54,
      56,    61,    45,     4,    35,    63,    42,    41,    43,     4,
      54,    10,    40,    63,    41,    36,    60,    64,    65,     7,
      58,    59,    60,     3,     4,     5,    14,    41,    77,    79,
      53,     7,    58,     4,    14,    66,    67,    36,    65,     4,
       6,     8,     9,    22,    26,    28,    29,    30,    31,    39,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    79,
      40,    42,     4,    14,    41,    43,     4,    41,    79,    77,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      44,     6,    68,    42,     4,    10,    40,    41,    46,    41,
      41,    41,    41,    68,    10,    10,    68,    77,     6,    69,
      11,    59,     4,    42,    77,    78,    77,    77,    42,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    43,
      46,     6,    67,    42,    78,    79,    77,    77,    77,    26,
      32,    10,    46,    37,    77,    40,    42,    44,    42,    77,
      46,    10,    42,    42,    42,    42,    42,    41,    41,    79,
      10,    77,    43,    44,    10,    10,    10,    23,    28,    77,
      77,    10,    77,    68,    68,    42,    42,    44,    24,    25,
      27,    10,    10,    68,    10,    10,    25,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    48,    49,    49,    50,    50,    51,
      52,    52,    53,    53,    53,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    63,    63,    64,    64,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    71,    72,    72,
      73,    73,    74,    75,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    79,    79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     4,     0,     2,     1,     4,     7,     2,
       1,     7,     6,     5,     3,     1,     2,     3,     1,     1,
       7,     6,     4,     3,     2,     2,     1,     3,     3,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     4,     5,     3,     5,     5,     4,     5,
      10,     8,     8,     7,     7,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       4,     3,     1,     2,     4,     1,     4,     7
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
#line 60 "exprtree.y"
                                         {
      printGlobalSymbolTable();
      printLocalSymbolTable();

      // Printing expression tree
      // printf("\nPrinting function def block\n");
      // printPrefix($2);
      // printf("\nPrinting mainblock\n");
      // printPrefix($3);

      {(yyval.no) = createTree(noNumber,voidType,NULL,emptyNode,(yyvsp[-1].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}

      // Call codegen
      helperFunction((yyval.no));
    }
#line 1641 "y.tab.c"
    break;

  case 3:
#line 75 "exprtree.y"
                         {
      printGlobalSymbolTable();
      printLocalSymbolTable();
      printf("\n");
      // printPrefix($2);
      (yyval.no) = createTree(noNumber,voidType,NULL,emptyNode,(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL);  

      // Call codegen
      helperFunction((yyval.no));
    }
#line 1656 "y.tab.c"
    break;

  case 4:
#line 85 "exprtree.y"
              {
      (yyval.no) = createTree(noNumber,voidType,NULL,emptyNode,(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL);
      // Call codegen
      helperFunction((yyval.no));  
    }
#line 1666 "y.tab.c"
    break;

  case 5:
#line 92 "exprtree.y"
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
#line 1682 "y.tab.c"
    break;

  case 9:
#line 111 "exprtree.y"
                               {
      // Adding type of variables for the entries in global symbol table
      struct gsymbol* top = gst->top;
      while(top){
        if(top->type == undefined){
          if(top->ispointer)  top->type = ((yyvsp[-2].num) == intType) ? intPtrType : strPtrType;
          else  top->type = (yyvsp[-2].num);
        }
        top = top->next;
      }
    }
#line 1698 "y.tab.c"
    break;

  case 13:
#line 130 "exprtree.y"
                         {
      // Making an entry in gst for function and also assigning label for that function.
      gInstall((yyvsp[-3].str),undefined,0,0,0,(yyvsp[-1].pl));
      struct gsymbol* node = gLookup((yyvsp[-3].str));
      node->flabel = ++fLabel;
    }
#line 1709 "y.tab.c"
    break;

  case 15:
#line 140 "exprtree.y"
                                      {
      struct gsymbol* node = gLookup((yyvsp[0].str));
      node->ispointer = 1;
    }
#line 1718 "y.tab.c"
    break;

  case 16:
#line 144 "exprtree.y"
        {gInstall((yyvsp[0].str),undefined,0,0,0,NULL); (yyval.str) = (yyvsp[0].str);}
#line 1724 "y.tab.c"
    break;

  case 17:
#line 145 "exprtree.y"
                    {gInstall((yyvsp[-3].str),undefined,0,(yyvsp[-1].no)->val,0,NULL); (yyval.str) = (yyvsp[-3].str);}
#line 1730 "y.tab.c"
    break;

  case 18:
#line 146 "exprtree.y"
                                 {gInstall((yyvsp[-6].str),undefined,0,(yyvsp[-4].no)->val,(yyvsp[-1].no)->val,NULL); (yyval.str) = (yyvsp[-6].str);}
#line 1736 "y.tab.c"
    break;

  case 19:
#line 150 "exprtree.y"
                           {(yyval.no) = createTree(noNumber,voidType,NULL,emptyNode,(yyvsp[-1].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 1742 "y.tab.c"
    break;

  case 20:
#line 151 "exprtree.y"
         {(yyval.no) = (yyvsp[0].no);}
#line 1748 "y.tab.c"
    break;

  case 21:
#line 154 "exprtree.y"
                                              {(yyval.no) = createFunkNode((yyvsp[-6].str),(yyvsp[-2].no));}
#line 1754 "y.tab.c"
    break;

  case 22:
#line 155 "exprtree.y"
                                       {(yyval.no) = NULL;}
#line 1760 "y.tab.c"
    break;

  case 23:
#line 159 "exprtree.y"
                                  {
      // Finding the function entry from global symbol table
      struct gsymbol* node = gLookup((yyvsp[-3].str));

      // Compare the function declaration with initialization to ensure that both of them are equal
      if(!node) yyerror("Make sure to initialize the function %s\n",(yyvsp[-3].str));
      if(node->type != (yyvsp[-4].num)) yyerror("Return type mismatch between initialization and declaration of function %s\n",(yyvsp[-3].str));
      
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
#line 1798 "y.tab.c"
    break;

  case 24:
#line 194 "exprtree.y"
                                {(yyvsp[0].pl)->next = (yyvsp[-2].pl); (yyval.pl) = (yyvsp[0].pl);}
#line 1804 "y.tab.c"
    break;

  case 25:
#line 195 "exprtree.y"
          {(yyval.pl) = (yyvsp[0].pl);}
#line 1810 "y.tab.c"
    break;

  case 26:
#line 199 "exprtree.y"
                {(yyval.pl) = makeParamNode((yyvsp[-1].num),(yyvsp[0].str),0);}
#line 1816 "y.tab.c"
    break;

  case 27:
#line 200 "exprtree.y"
                  {(yyval.pl) = makeParamNode((yyvsp[-2].num),(yyvsp[0].str),1);}
#line 1822 "y.tab.c"
    break;

  case 28:
#line 203 "exprtree.y"
           {(yyval.num) = intType;}
#line 1828 "y.tab.c"
    break;

  case 29:
#line 204 "exprtree.y"
        {(yyval.num) = strType;}
#line 1834 "y.tab.c"
    break;

  case 30:
#line 209 "exprtree.y"
                                                        {
      // Make an connector node and return that node
      (yyval.no) = createMainNode((yyvsp[-6].str),(yyvsp[-2].no));
    }
#line 1843 "y.tab.c"
    break;

  case 31:
#line 213 "exprtree.y"
                                          {}
#line 1849 "y.tab.c"
    break;

  case 32:
#line 216 "exprtree.y"
                              {
      char* temp = malloc(5);
      memcpy(temp, "main\0", 5);

      gInstall(temp,intType,0,0,0,NULL);
      struct gsymbol* node = gLookup(temp);
      node->ltop = NULL;
      node->flabel = ++fLabel;

      (yyval.str) = temp;
    }
#line 1865 "y.tab.c"
    break;

  case 33:
#line 230 "exprtree.y"
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
#line 1885 "y.tab.c"
    break;

  case 34:
#line 245 "exprtree.y"
                 {
      char* funkName = (yyvsp[(-1) - (2)].str);
      struct gsymbol* gnode = gLookup(funkName);
      lst->top = gnode->ltop;
      lst->name = funkName;
    }
#line 1896 "y.tab.c"
    break;

  case 35:
#line 253 "exprtree.y"
                            {
      // Both lDeclList and lDecl contains the pointer to head of the linked list of lsymbol node
      struct lsymbol* l1 = (yyvsp[-1].lnode);
      struct lsymbol* l2 = (yyvsp[0].lnode);

      // Get the last node of list2
      while(l2->next) l2 = l2->next;
      l2->next = l1;
      (yyval.lnode) = (yyvsp[0].lnode);
    }
#line 1911 "y.tab.c"
    break;

  case 36:
#line 263 "exprtree.y"
          {(yyval.lnode) = (yyvsp[0].lnode);}
#line 1917 "y.tab.c"
    break;

  case 37:
#line 266 "exprtree.y"
                               {
      struct lsymbol* top = (yyvsp[-1].lnode);
      while(top){
        if(top->type == undefined){
          if(top->ispointer) top->type = ((yyvsp[-2].num) == intType) ? intPtrType : strPtrType;
          else top->type = (yyvsp[-2].num);
        }
        top = top->next;
      }
      (yyval.lnode) = (yyvsp[-1].lnode);
    }
#line 1933 "y.tab.c"
    break;

  case 38:
#line 279 "exprtree.y"
                          {(yyvsp[0].lnode)->next = (yyvsp[-2].lnode); (yyval.lnode) = (yyvsp[0].lnode);}
#line 1939 "y.tab.c"
    break;

  case 39:
#line 280 "exprtree.y"
        {(yyval.lnode) = (yyvsp[0].lnode);}
#line 1945 "y.tab.c"
    break;

  case 40:
#line 284 "exprtree.y"
         {(yyval.lnode) = makeLSymbolNode((yyvsp[0].str),undefined,0);}
#line 1951 "y.tab.c"
    break;

  case 41:
#line 285 "exprtree.y"
            {(yyval.lnode) = makeLSymbolNode((yyvsp[0].str),undefined,1);}
#line 1957 "y.tab.c"
    break;

  case 42:
#line 290 "exprtree.y"
                   {(yyval.no) = createTree(noNumber,voidType,NULL,emptyNode,(yyvsp[-1].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 1963 "y.tab.c"
    break;

  case 43:
#line 291 "exprtree.y"
         {(yyval.no) = (yyvsp[0].no);}
#line 1969 "y.tab.c"
    break;

  case 44:
#line 294 "exprtree.y"
                 {(yyval.no) = (yyvsp[0].no);}
#line 1975 "y.tab.c"
    break;

  case 45:
#line 295 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 1981 "y.tab.c"
    break;

  case 46:
#line 296 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 1987 "y.tab.c"
    break;

  case 47:
#line 297 "exprtree.y"
           {(yyval.no) = (yyvsp[0].no);}
#line 1993 "y.tab.c"
    break;

  case 48:
#line 298 "exprtree.y"
              {(yyval.no) = (yyvsp[0].no);}
#line 1999 "y.tab.c"
    break;

  case 49:
#line 299 "exprtree.y"
                {(yyval.no) = (yyvsp[0].no);}
#line 2005 "y.tab.c"
    break;

  case 50:
#line 300 "exprtree.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 2011 "y.tab.c"
    break;

  case 51:
#line 301 "exprtree.y"
                    {(yyval.no) = createTree(noNumber,voidType,NULL,breakNode,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2017 "y.tab.c"
    break;

  case 52:
#line 302 "exprtree.y"
                       {(yyval.no) = createTree(noNumber,voidType,NULL,continueNode,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2023 "y.tab.c"
    break;

  case 53:
#line 303 "exprtree.y"
                         {(yyval.no) = createCallerNode((yyvsp[-3].str),NULL);}
#line 2029 "y.tab.c"
    break;

  case 54:
#line 304 "exprtree.y"
                                 {(yyval.no) = createCallerNode((yyvsp[-4].str),(yyvsp[-2].no));}
#line 2035 "y.tab.c"
    break;

  case 55:
#line 305 "exprtree.y"
                          {(yyval.no) = createReturnNode(lst->name,(yyvsp[-1].no));}
#line 2041 "y.tab.c"
    break;

  case 56:
#line 308 "exprtree.y"
                                              {(yyval.no) = createTree(noNumber,voidType,NULL,readNode,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL);}
#line 2047 "y.tab.c"
    break;

  case 57:
#line 311 "exprtree.y"
                                          {(yyval.no) = createTree(noNumber,voidType,NULL,writeNode,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL);}
#line 2053 "y.tab.c"
    break;

  case 58:
#line 314 "exprtree.y"
                                              {(yyval.no) = createTree(noNumber,voidType,NULL,assignNode,(yyvsp[-3].no),(yyvsp[-1].no),NULL,NULL,NULL,NULL);}
#line 2059 "y.tab.c"
    break;

  case 59:
#line 315 "exprtree.y"
                                                {
      struct tnode* newAddrNode = createAddrNode((yyvsp[-1].no));
      (yyval.no) = createTree(noNumber,voidType,NULL,assignNode,(yyvsp[-4].no),newAddrNode,NULL,NULL,NULL,NULL);
    }
#line 2068 "y.tab.c"
    break;

  case 60:
#line 321 "exprtree.y"
                                                               {(yyval.no) = createTree(noNumber,voidType,NULL,ifElseNode,(yyvsp[-4].no),(yyvsp[-2].no),(yyvsp[-7].no),NULL,NULL,NULL);}
#line 2074 "y.tab.c"
    break;

  case 61:
#line 322 "exprtree.y"
                                               {(yyval.no) = createTree(noNumber,voidType,NULL,ifElseNode,(yyvsp[-2].no),NULL,(yyvsp[-5].no),NULL,NULL,NULL);}
#line 2080 "y.tab.c"
    break;

  case 62:
#line 325 "exprtree.y"
                                                            {(yyval.no) = createTree(noNumber,voidType,NULL,whileNode,(yyvsp[-2].no),NULL,(yyvsp[-5].no),NULL,NULL,NULL);}
#line 2086 "y.tab.c"
    break;

  case 63:
#line 328 "exprtree.y"
                                                    {(yyval.no) = createTree(noNumber,voidType,NULL,doWhileNode,(yyvsp[-5].no),NULL,(yyvsp[-2].no),NULL,NULL,NULL);}
#line 2092 "y.tab.c"
    break;

  case 64:
#line 331 "exprtree.y"
                                                            {(yyval.no) = createTree(noNumber,voidType,NULL,repeatUntilNode,(yyvsp[-5].no),NULL,(yyvsp[-2].no),NULL,NULL,NULL);}
#line 2098 "y.tab.c"
    break;

  case 65:
#line 335 "exprtree.y"
                       {(yyval.no) = createTree(noNumber,intType,NULL,addNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2104 "y.tab.c"
    break;

  case 66:
#line 336 "exprtree.y"
                      {(yyval.no) = createTree(noNumber,intType,NULL,subNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2110 "y.tab.c"
    break;

  case 67:
#line 337 "exprtree.y"
                   {(yyval.no) = createTree(noNumber,intType,NULL,mulNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2116 "y.tab.c"
    break;

  case 68:
#line 338 "exprtree.y"
                  {(yyval.no) = createTree(noNumber,intType,NULL,divNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2122 "y.tab.c"
    break;

  case 69:
#line 339 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,boolType,NULL,lessNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2128 "y.tab.c"
    break;

  case 70:
#line 340 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,boolType,NULL,greaterNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2134 "y.tab.c"
    break;

  case 71:
#line 341 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,boolType,NULL,lessEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2140 "y.tab.c"
    break;

  case 72:
#line 342 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,boolType,NULL,greaterEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2146 "y.tab.c"
    break;

  case 73:
#line 343 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,boolType,NULL,notEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2152 "y.tab.c"
    break;

  case 74:
#line 344 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,boolType,NULL,equalNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL);}
#line 2158 "y.tab.c"
    break;

  case 75:
#line 345 "exprtree.y"
                 {(yyval.no) = (yyvsp[-1].no);}
#line 2164 "y.tab.c"
    break;

  case 76:
#line 346 "exprtree.y"
        {(yyval.no) = (yyvsp[0].no);}
#line 2170 "y.tab.c"
    break;

  case 77:
#line 347 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 2176 "y.tab.c"
    break;

  case 78:
#line 348 "exprtree.y"
           {(yyval.no) = (yyvsp[0].no);}
#line 2182 "y.tab.c"
    break;

  case 79:
#line 349 "exprtree.y"
               {(yyval.no) = createCallerNode((yyvsp[-2].str),NULL);}
#line 2188 "y.tab.c"
    break;

  case 80:
#line 350 "exprtree.y"
                       {(yyval.no) = createCallerNode((yyvsp[-3].str),(yyvsp[-1].no));}
#line 2194 "y.tab.c"
    break;

  case 81:
#line 353 "exprtree.y"
                           {
      struct tnode* temp = createArgsNode((yyvsp[0].no));
      temp->arglist = (yyvsp[-2].no);
      (yyval.no) = temp;
    }
#line 2204 "y.tab.c"
    break;

  case 82:
#line 358 "exprtree.y"
         {(yyval.no) = createArgsNode((yyvsp[0].no));}
#line 2210 "y.tab.c"
    break;

  case 83:
#line 363 "exprtree.y"
                             {(yyval.no) = createStarNode((yyvsp[0].no));}
#line 2216 "y.tab.c"
    break;

  case 84:
#line 364 "exprtree.y"
                      {(yyval.no) = createStarNode((yyvsp[-1].no));}
#line 2222 "y.tab.c"
    break;

  case 85:
#line 365 "exprtree.y"
       {(yyval.no) = createIdNode((yyvsp[0].str),NULL,NULL);}
#line 2228 "y.tab.c"
    break;

  case 86:
#line 366 "exprtree.y"
                    {(yyval.no) = createIdNode((yyvsp[-3].str),(yyvsp[-1].no),NULL);}
#line 2234 "y.tab.c"
    break;

  case 87:
#line 367 "exprtree.y"
                                 {(yyval.no) = createIdNode((yyvsp[-6].str),(yyvsp[-4].no),(yyvsp[-1].no));}
#line 2240 "y.tab.c"
    break;


#line 2244 "y.tab.c"

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
#line 398 "exprtree.y"


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

    yyparse();
    fclose(filePointer);
    return 0;
}
