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
    SELF = 307,
    EXTENDS = 308
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
#define EXTENDS 308

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

#line 257 "y.tab.c"

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
#define YYLAST   1017

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  352

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


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
      57,    58,     2,     2,    56,     2,    61,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    74,    78,    87,    97,   108,   117,   121,
     125,   132,   136,   139,   140,   143,   144,   147,   151,   157,
     160,   161,   162,   165,   166,   169,   173,   174,   177,   178,
     181,   185,   191,   192,   195,   196,   199,   223,   265,   266,
     269,   270,   273,   288,   297,   305,   308,   322,   327,   331,
     344,   347,   348,   352,   380,   381,   385,   386,   395,   399,
     400,   401,   405,   406,   409,   410,   414,   450,   451,   452,
     456,   457,   460,   461,   462,   467,   468,   471,   485,   512,
     513,   516,   526,   529,   552,   553,   557,   558,   563,   564,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   587,   590,   594,
     595,   601,   602,   605,   608,   611,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   638,   643,   649,
     650,   651,   652,   653,   654,   657,   658,   659,   662,   663,
     664,   665,   666,   667
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
  "ENDCLASS", "NEW", "DELETE", "SELF", "EXTENDS", "'{'", "'}'", "','",
  "'('", "')'", "'['", "']'", "'.'", "$accept", "program", "gClassBlock",
  "gClassList", "gClass", "className", "gClassDeclBlockSeg",
  "gClassDeclBlock", "gClassAttrDeclList", "gClassAttrDecl",
  "gClassIdList", "gClassFuncDeclList", "gClassFuncDecl", "gClassFuncName",
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
     305,   306,   307,   308,   123,   125,    44,    40,    41,    91,
      93,    46
};
# endif

#define YYPACT_NINF (-170)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     236,   143,    21,    30,    13,   -11,   208,   194,  -170,  -170,
    -170,  -170,   168,  -170,   129,  -170,  -170,    80,  -170,   -17,
     -25,  -170,    49,  -170,     0,  -170,    16,    22,   -11,    16,
    -170,    70,   203,  -170,    71,    81,  -170,  -170,   112,   181,
      -4,  -170,  -170,  -170,  -170,   194,    82,  -170,  -170,    94,
    -170,    73,   203,  -170,   113,    22,  -170,  -170,   113,    96,
     194,   263,   115,  -170,  -170,   129,    11,  -170,   182,  -170,
     194,    36,  -170,   133,   203,  -170,   225,   180,  -170,   185,
     194,   147,  -170,   265,  -170,   379,  -170,    -2,    15,  -170,
     145,   263,   627,  -170,   150,  -170,  -170,  -170,  -170,  -170,
      17,   292,  -170,   320,  -170,   227,  -170,   102,  -170,   166,
     240,  -170,  -170,  -170,   276,   348,  -170,   305,   333,   189,
     194,  -170,  -170,   246,     4,   263,   269,   192,   233,   263,
    -170,   243,  -170,   284,   745,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   238,   288,  -170,
     294,  -170,  -170,   376,  -170,  -170,   308,   260,    32,   311,
    -170,  -170,   113,   261,  -170,   345,    48,  -170,  -170,  -170,
     400,   303,   309,   314,   316,   317,   558,   350,   358,   558,
     263,   319,   329,   361,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,   366,   378,   339,   389,  -170,  -170,  -170,  -170,
     946,   216,   637,   342,   392,   397,   755,   398,   347,  -170,
       6,     6,  -170,  -170,   993,   993,   993,   993,   993,   993,
     976,   976,   263,   351,  -170,  -170,   260,   194,  -170,   401,
    -170,   407,  -170,   194,  -170,  -170,   276,   123,  -170,    15,
     263,   263,   263,   586,  -170,  -170,   417,   928,   364,    15,
     368,  -170,    43,  -170,  -170,   369,   263,  -170,   357,   136,
    -170,  -170,  -170,  -170,   205,   686,   218,   231,  -170,   446,
     237,  -170,   419,   274,   372,   802,   812,   859,   370,   375,
    -170,   423,   384,  -170,    15,   380,   387,   963,  -170,   946,
     263,  -170,   282,  -170,   287,  -170,  -170,   290,  -170,   396,
     474,  -170,  -170,   443,   448,   454,   442,   438,   263,   263,
    -170,   457,   460,   413,   469,  -170,   696,  -170,  -170,  -170,
    -170,   424,  -170,  -170,  -170,   558,   558,   869,   916,  -170,
    -170,   471,   426,  -170,  -170,   277,   502,    -5,   476,  -170,
     477,   558,   479,   480,  -170,  -170,  -170,   530,  -170,  -170,
     483,  -170
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     0,    74,    72,
      73,    50,     0,    52,     0,    43,    39,     0,    41,     0,
      17,    12,     0,    14,     0,     1,     3,     0,     4,     0,
       9,     0,     0,    63,     0,     0,    49,    51,    59,     0,
       0,    55,    56,    38,    40,     0,     0,    11,    13,     0,
       5,     0,     0,     8,     0,    72,    62,    10,     0,     0,
      69,     0,    59,    58,    53,     0,     0,    45,     0,    18,
       0,     0,    19,     0,     0,     6,     0,     0,    78,     0,
      69,     0,    68,     0,   129,   141,   132,     0,     0,   135,
       0,     0,     0,   131,   144,   136,    54,    42,    44,    48,
       0,     0,    24,     0,    29,     0,    16,     0,    33,     0,
       0,    77,     7,    80,     0,     0,    82,     0,     0,     0,
       0,    57,    70,     0,     0,     0,     0,   141,     0,     0,
     139,   144,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,     0,    46,
       0,    22,    23,     0,    21,    28,     0,    27,     0,     0,
      15,    32,     0,     0,    86,     0,     0,    85,    79,    81,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,    93,    94,
      95,    96,     0,     0,     0,     0,    66,    67,    71,   133,
     138,     0,     0,   146,     0,     0,     0,     0,   147,   128,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,   145,    47,    20,     0,    69,    25,     0,
      30,     0,    36,    69,    87,    83,     0,     0,    76,     0,
       0,     0,     0,     0,    97,    98,     0,     0,     0,     0,
       0,    88,     0,   105,    65,     0,     0,   134,   142,     0,
     146,   147,   140,   145,     0,     0,     0,     0,    26,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,    75,     0,     0,     0,     0,    64,   137,
       0,   151,     0,   149,     0,    61,   153,     0,    31,     0,
       0,    37,    99,     0,     0,     0,     0,     0,     0,     0,
     103,     0,   130,     0,     0,   109,     0,   150,   148,   152,
      35,     0,   100,   107,   108,     0,     0,     0,     0,   104,
     110,     0,     0,   143,    34,     0,     0,     0,     0,   102,
       0,     0,     0,     0,   114,   115,   106,     0,   112,   113,
       0,   111
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,   488,  -170,   473,  -170,  -170,  -170,  -170,   406,
    -170,   408,   -81,  -170,  -170,   390,  -170,  -170,  -170,  -170,
     482,  -170,  -170,   435,  -170,   184,  -170,   496,  -170,   447,
     475,   463,    89,  -170,   -69,   402,    31,     7,  -170,   459,
     356,  -170,   410,  -170,   285,  -108,  -169,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,   -26,  -115,   -87,   -84,  -101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    22,    23,    24,    71,    72,   101,   102,
     158,   103,   104,   159,   107,   108,   231,   109,     6,    17,
      18,    19,    66,    67,   100,     7,    12,    13,    40,    41,
      42,    32,    33,    34,    81,    82,    83,    30,    31,    77,
      78,   115,   116,   166,   167,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   200,   201,    93,    94,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     130,   132,   127,   131,   131,   344,    64,    84,    85,    86,
     195,   119,    87,    25,   251,     8,   193,   193,    87,   127,
     137,   138,   155,   326,     1,    15,   251,   149,    46,    87,
     192,   192,    14,    50,    20,    92,    53,    45,    35,    57,
       8,    88,   228,    14,     9,    10,    84,    85,    86,    27,
     128,    89,    65,    20,    49,   129,    90,    87,   235,    75,
      51,    91,   199,    35,    16,   134,    97,   128,   243,     9,
      10,   246,   155,   150,   251,   193,    68,   251,   193,    21,
     284,   112,   193,    35,    15,    59,    69,   285,   229,   192,
      89,   106,   192,   286,   193,    90,   192,    68,    47,   202,
      91,   105,   110,   206,   236,    35,     8,   114,   192,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    56,   273,    43,    54,    58,    84,    85,    86,    70,
      73,   251,   105,    38,   156,     9,    10,    87,   110,    84,
      85,    86,   193,    39,   292,   193,   114,     8,    76,   294,
      87,   297,   274,    80,   247,   131,   192,   160,   267,   192,
      88,   300,   282,    56,   270,   131,   251,   251,   193,    60,
      89,    61,     8,    88,    61,    90,     9,    10,   251,    11,
      91,   272,   192,    89,   156,    62,    99,   117,    90,    26,
      29,   111,   118,    91,   291,    39,   265,   312,     8,   193,
     131,     9,    10,   120,    36,   121,   133,     8,    84,    85,
      86,   148,    52,   192,   275,   276,   277,   335,   336,    87,
     162,    84,    85,    86,   193,   193,   287,     9,    10,     8,
     289,   157,    87,   347,   193,   193,    55,    10,   192,   192,
     193,    27,    88,     1,   163,   120,   193,   196,   192,   192,
     198,   125,    89,   204,   192,    88,     3,    90,     9,    10,
     192,   113,    91,   293,   316,    89,    84,    85,    86,   122,
      90,     1,   256,   203,   257,    91,   296,    87,     2,   123,
     164,   170,   327,   328,     3,   172,   173,   120,   208,   298,
     165,    87,   223,   120,   205,   301,     8,   222,   224,   174,
      88,   341,   342,   175,   207,   176,   177,   178,   179,   170,
      89,   171,   226,   172,   173,    90,   180,   227,   233,    87,
      91,   230,   181,   182,     8,     9,    10,   174,   151,    90,
     256,   175,   303,   176,   177,   178,   179,   170,   256,   194,
     317,   172,   173,   256,   180,   318,   256,    87,   319,   234,
     181,   182,     8,     9,    10,   174,   154,    90,   238,   175,
     244,   176,   177,   178,   179,   170,   239,   250,   245,   172,
     173,   240,   180,   241,   242,    87,   248,   252,   181,   182,
       8,     9,    10,   174,   168,    90,   249,   175,   253,   176,
     177,   178,   179,   170,   254,   255,   260,   172,   173,   259,
     180,   261,   263,    87,   264,   268,   181,   182,   266,     9,
      10,   174,   225,    90,   269,   175,   290,   176,   177,   178,
     179,   170,   281,   283,   288,   172,   173,   308,   180,   302,
     304,    87,   309,   310,   181,   182,   124,   313,   125,   174,
     126,    90,   311,   175,   314,   176,   177,   178,   179,   279,
     170,   320,   299,   322,   172,   173,   180,   237,   323,   125,
      87,   126,   181,   182,   324,   325,   326,   329,   174,    90,
     330,   331,   175,   332,   176,   177,   178,   179,   170,   334,
     321,   339,   172,   173,   340,   180,   345,   346,    87,   348,
     349,   181,   182,   351,    28,    48,   174,   161,    90,    44,
     175,    98,   176,   177,   178,   179,   170,   152,    37,   153,
     172,   173,    96,   180,    63,    74,    87,    79,   232,   181,
     182,   271,   197,     0,   174,   169,    90,     0,   175,   343,
     176,   177,   178,   179,   170,     0,     0,     0,   172,   173,
       0,   180,     0,     0,    87,     0,     0,   181,   182,     0,
       0,     0,   174,     0,    90,   350,   175,     0,   176,   177,
     178,   179,   170,     0,     0,     0,   172,   173,     0,   180,
       0,     0,    87,     0,     0,   181,   182,     0,     0,     0,
     174,     0,    90,     0,   175,     0,   176,   177,   178,   179,
     170,     0,     0,     0,   172,   173,     0,   180,     0,     0,
      87,     0,     0,   181,   182,     0,     0,     0,   174,     0,
      90,     0,   278,     0,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,   180,     0,     0,     0,     0,
       0,   181,   182,     0,     0,     0,     0,     0,    90,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   333,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   146,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   146,     0,     0,     0,
       0,     0,     0,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,     0,     0,     0,     0,     0,     0,   307,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   337,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   280,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,     0,     0,     0,     0,   145,   146,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,   315,   338,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,   145,   146,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
       0,     0,     0,   145,   146,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      87,    88,     4,    87,    88,    10,    10,     3,     4,     5,
     118,    80,    14,     0,   183,     4,   117,   118,    14,     4,
      14,    15,   103,    28,    35,     4,   195,    10,    53,    14,
     117,   118,     1,    26,     4,    61,    29,    54,     7,    32,
       4,    37,    10,    12,    33,    34,     3,     4,     5,    33,
      52,    47,    56,     4,    54,    57,    52,    14,    10,    52,
      38,    57,    58,    32,    43,    91,    55,    52,   176,    33,
      34,   179,   153,    56,   243,   176,    45,   246,   179,    49,
      37,    74,   183,    52,     4,     4,     4,    44,    56,   176,
      47,    55,   179,    50,   195,    52,   183,    66,    49,   125,
      57,    70,    71,   129,    56,    74,     4,    76,   195,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    32,   237,    43,    54,    54,     3,     4,     5,    35,
      57,   300,   101,     4,   103,    33,    34,    14,   107,     3,
       4,     5,   243,    14,   259,   246,   115,     4,    35,   264,
      14,   266,   239,    57,   180,   239,   243,    55,   227,   246,
      37,   269,   249,    74,   233,   249,   335,   336,   269,    57,
      47,    59,     4,    37,    59,    52,    33,    34,   347,    36,
      57,    58,   269,    47,   153,     4,     4,     7,    52,     5,
       6,    58,     7,    57,    58,    14,   222,   284,     4,   300,
     284,    33,    34,    56,    36,    58,    61,     4,     3,     4,
       5,    61,    28,   300,   240,   241,   242,   325,   326,    14,
      54,     3,     4,     5,   325,   326,   252,    33,    34,     4,
     256,     4,    14,   341,   335,   336,    33,    34,   325,   326,
     341,    33,    37,    35,     4,    56,   347,    58,   335,   336,
       4,    59,    47,    61,   341,    37,    48,    52,    33,    34,
     347,    36,    57,    58,   290,    47,     3,     4,     5,     4,
      52,    35,    56,     4,    58,    57,    58,    14,    42,    14,
       4,     4,   308,   309,    48,     8,     9,    56,     4,    58,
      14,    14,     4,    56,    61,    58,     4,    59,     4,    22,
      37,    24,    25,    26,    61,    28,    29,    30,    31,     4,
      47,     6,     4,     8,     9,    52,    39,    57,    57,    14,
      57,    10,    45,    46,     4,    33,    34,    22,    36,    52,
      56,    26,    58,    28,    29,    30,    31,     4,    56,     6,
      58,     8,     9,    56,    39,    58,    56,    14,    58,     4,
      45,    46,     4,    33,    34,    22,    36,    52,    55,    26,
      10,    28,    29,    30,    31,     4,    57,     6,    10,     8,
       9,    57,    39,    57,    57,    14,    57,    11,    45,    46,
       4,    33,    34,    22,    36,    52,    57,    26,    10,    28,
      29,    30,    31,     4,    55,     6,     4,     8,     9,    57,
      39,     4,     4,    14,    57,     4,    45,    46,    57,    33,
      34,    22,    36,    52,     7,    26,    59,    28,    29,    30,
      31,     4,    58,    55,    55,     8,     9,    57,    39,    10,
      58,    14,    57,    10,    45,    46,    57,    57,    59,    22,
      61,    52,    58,    26,    57,    28,    29,    30,    31,    32,
       4,    55,     6,    10,     8,     9,    39,    57,    10,    59,
      14,    61,    45,    46,    10,    23,    28,    10,    22,    52,
      10,    58,    26,     4,    28,    29,    30,    31,     4,    55,
       6,    10,     8,     9,    58,    39,    10,    10,    14,    10,
      10,    45,    46,    10,     6,    22,    22,   107,    52,    17,
      26,    66,    28,    29,    30,    31,     4,   101,    12,   101,
       8,     9,    65,    39,    39,    52,    14,    58,   162,    45,
      46,   236,   120,    -1,    22,   115,    52,    -1,    26,    27,
      28,    29,    30,    31,     4,    -1,    -1,    -1,     8,     9,
      -1,    39,    -1,    -1,    14,    -1,    -1,    45,    46,    -1,
      -1,    -1,    22,    -1,    52,    25,    26,    -1,    28,    29,
      30,    31,     4,    -1,    -1,    -1,     8,     9,    -1,    39,
      -1,    -1,    14,    -1,    -1,    45,    46,    -1,    -1,    -1,
      22,    -1,    52,    -1,    26,    -1,    28,    29,    30,    31,
       4,    -1,    -1,    -1,     8,     9,    -1,    39,    -1,    -1,
      14,    -1,    -1,    45,    46,    -1,    -1,    -1,    22,    -1,
      52,    -1,    26,    -1,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    40,    41,
      -1,    -1,    -1,    10,    58,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    40,    41,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    40,    41,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    42,    48,    63,    64,    80,    87,     4,    33,
      34,    36,    88,    89,    98,     4,    43,    81,    82,    83,
       4,    49,    65,    66,    67,     0,    87,    33,    64,    87,
      99,   100,    93,    94,    95,    98,    36,    89,     4,    14,
      90,    91,    92,    43,    82,    54,    53,    49,    66,    54,
      99,    38,    87,    99,    54,    33,    94,    99,    54,     4,
      57,    59,     4,    92,    10,    56,    84,    85,    98,     4,
      35,    68,    69,    57,    93,    99,    35,   101,   102,   101,
      57,    96,    97,    98,     3,     4,     5,    14,    37,    47,
      52,    57,   116,   118,   119,   120,    91,    55,    85,     4,
      86,    70,    71,    73,    74,    98,    55,    76,    77,    79,
      98,    58,    99,    36,    98,   103,   104,     7,     7,    96,
      56,    58,     4,    14,    57,    59,    61,     4,    52,    57,
     118,   119,   118,    61,   116,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    40,    41,    60,    61,    10,
      56,    36,    71,    73,    36,    74,    98,     4,    72,    75,
      55,    77,    54,     4,     4,    14,   105,   106,    36,   104,
       4,     6,     8,     9,    22,    26,    28,    29,    30,    31,
      39,    45,    46,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   118,   120,     6,   107,    58,    97,     4,    58,
     116,   117,   116,     4,    61,    61,   116,    61,     4,    58,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,    59,     4,     4,    36,     4,    57,    10,    56,
      10,    78,   102,    57,     4,    10,    56,    57,    55,    57,
      57,    57,    57,   107,    10,    10,   107,   116,    57,    57,
       6,   108,    11,    10,    55,     6,    56,    58,    60,    57,
       4,     4,    58,     4,    57,   116,    57,    96,     4,     7,
      96,   106,    58,   117,   118,   116,   116,   116,    26,    32,
      10,    58,   118,    55,    37,    44,    50,   116,    55,   116,
      59,    58,   117,    58,   117,    60,    58,   117,    58,     6,
     107,    58,    10,    58,    58,    58,    58,    58,    57,    57,
      10,    58,   118,    57,    57,    10,   116,    58,    58,    58,
      55,     6,    10,    10,    10,    23,    28,   116,   116,    10,
      10,    58,     4,    60,    55,   107,   107,    58,    58,    10,
      58,    24,    25,    27,    10,    10,    10,   107,    10,    10,
      25,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      69,    69,    69,    70,    70,    71,    72,    72,    73,    73,
      74,    75,    76,    76,    77,    77,    78,    79,    80,    80,
      81,    81,    82,    83,    84,    84,    85,    86,    86,    87,
      87,    88,    88,    89,    90,    90,    91,    91,    92,    92,
      92,    92,    93,    93,    94,    94,    95,    96,    96,    96,
      97,    97,    98,    98,    98,    99,    99,   100,   101,   102,
     102,   103,   103,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   110,   111,
     111,   112,   112,   113,   114,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   117,   117,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   120,   120,
     120,   120,   120,   120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     3,     4,     5,     3,     2,
       3,     3,     2,     2,     1,     5,     4,     1,     3,     1,
       4,     3,     3,     2,     1,     3,     3,     1,     2,     1,
       3,     4,     2,     1,     7,     6,     1,     5,     3,     2,
       2,     1,     4,     1,     2,     1,     3,     3,     1,     3,
       2,     2,     1,     3,     3,     1,     1,     4,     2,     1,
       4,     7,     2,     1,     7,     6,     5,     3,     1,     0,
       2,     3,     1,     1,     1,     7,     6,     4,     1,     3,
       2,     2,     1,     3,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     4,
       5,     3,     6,     4,     5,     2,     7,     5,     5,     4,
       5,    10,     8,     8,     7,     7,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     1,     1,     3,     4,     1,     1,     3,     1,     2,
       4,     1,     4,     7,     1,     3,     3,     3,     6,     5,
       6,     5,     6,     5
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
        printf("Presenting the class table: \n"); printClassTable();
        // printPrefix($1);
        // helperFunction($1);
      }
#line 1814 "y.tab.c"
    break;

  case 3:
#line 74 "exprtree.y"
                             {
        printf("Presenting the class table: \n"); printClassTable();
        printGlobalSymbolTable();
      }
#line 1823 "y.tab.c"
    break;

  case 4:
#line 78 "exprtree.y"
                             {
        printf("hurray!!\n");
        printTypeTable();
        printf("Presenting the class table: \n"); printClassTable();
        
        // Backend part
        // printPrefix($2);
        // helperFunction($2);
      }
#line 1837 "y.tab.c"
    break;

  case 5:
#line 87 "exprtree.y"
                                       {
        printf("Presenting the class table: \n"); printClassTable();
        printGlobalSymbolTable();
        printLocalSymbolTable();

        // Print prefix tree
        (yyval.no) = makeConnectorNode((yyvsp[-2].no),(yyvsp[0].no));
        // printPrefix($$);
        helperFunction((yyval.no));
      }
#line 1852 "y.tab.c"
    break;

  case 6:
#line 97 "exprtree.y"
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
#line 1868 "y.tab.c"
    break;

  case 7:
#line 108 "exprtree.y"
                                                            {
      printTypeTable();
      printf("Presenting the class table: \n"); printClassTable();
      printGlobalSymbolTable();
      printLocalSymbolTable();
      (yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));
      // Call codegen
      helperFunction((yyval.no));
    }
#line 1882 "y.tab.c"
    break;

  case 8:
#line 117 "exprtree.y"
                                    {
      (yyval.no) = makeConnectorNode((yyvsp[0].no),NULL);  
      helperFunction((yyval.no));
    }
#line 1891 "y.tab.c"
    break;

  case 9:
#line 121 "exprtree.y"
                         {
      (yyval.no) = makeConnectorNode((yyvsp[0].no),NULL);
      helperFunction((yyval.no));  
    }
#line 1900 "y.tab.c"
    break;

  case 10:
#line 125 "exprtree.y"
                                   {
      (yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));
      helperFunction((yyval.no));
    }
#line 1909 "y.tab.c"
    break;

  case 11:
#line 132 "exprtree.y"
                                        {
      curClass = NULL;
      (yyval.no) = (yyvsp[-1].no);  
    }
#line 1918 "y.tab.c"
    break;

  case 12:
#line 136 "exprtree.y"
                   {(yyval.no) = NULL;}
#line 1924 "y.tab.c"
    break;

  case 13:
#line 139 "exprtree.y"
                               {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 1930 "y.tab.c"
    break;

  case 14:
#line 140 "exprtree.y"
           {(yyval.no) = (yyvsp[0].no);}
#line 1936 "y.tab.c"
    break;

  case 15:
#line 143 "exprtree.y"
                                                                 {(yyval.no) = (yyvsp[-1].no);}
#line 1942 "y.tab.c"
    break;

  case 16:
#line 144 "exprtree.y"
                                         {(yyval.no) = NULL;}
#line 1948 "y.tab.c"
    break;

  case 17:
#line 147 "exprtree.y"
                {
      cInstall((yyvsp[0].str),NULL);                            // Make an entry in class table
      curClass = (yyvsp[0].str);
    }
#line 1957 "y.tab.c"
    break;

  case 18:
#line 151 "exprtree.y"
                  {
      cInstall((yyvsp[-2].str),(yyvsp[0].str));
      curClass = (yyvsp[-2].str);
    }
#line 1966 "y.tab.c"
    break;

  case 19:
#line 157 "exprtree.y"
                                     {}
#line 1972 "y.tab.c"
    break;

  case 20:
#line 160 "exprtree.y"
                                                                     {}
#line 1978 "y.tab.c"
    break;

  case 21:
#line 161 "exprtree.y"
                                    {}
#line 1984 "y.tab.c"
    break;

  case 22:
#line 162 "exprtree.y"
                                    {}
#line 1990 "y.tab.c"
    break;

  case 23:
#line 165 "exprtree.y"
                                                       {}
#line 1996 "y.tab.c"
    break;

  case 24:
#line 166 "exprtree.y"
                   {}
#line 2002 "y.tab.c"
    break;

  case 25:
#line 169 "exprtree.y"
                                             {}
#line 2008 "y.tab.c"
    break;

  case 26:
#line 173 "exprtree.y"
                                   {classAttrInstall(curClass,(yyvsp[-3].str),(yyvsp[0].str));}
#line 2014 "y.tab.c"
    break;

  case 27:
#line 174 "exprtree.y"
       {classAttrInstall(curClass,(yyvsp[-1].str),(yyvsp[0].str));}
#line 2020 "y.tab.c"
    break;

  case 28:
#line 177 "exprtree.y"
                                                       {}
#line 2026 "y.tab.c"
    break;

  case 29:
#line 178 "exprtree.y"
                   {}
#line 2032 "y.tab.c"
    break;

  case 30:
#line 181 "exprtree.y"
                                               {}
#line 2038 "y.tab.c"
    break;

  case 31:
#line 185 "exprtree.y"
                                      {
      if(cLookup((yyvsp[-4].str))) yyerror("Return type of methods cannot be class variables !!\n");
      classMemInstall(curClass,(yyvsp[-3].str),(yyvsp[-4].str),(yyvsp[-1].pl));
    }
#line 2047 "y.tab.c"
    break;

  case 32:
#line 191 "exprtree.y"
                                                      {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2053 "y.tab.c"
    break;

  case 33:
#line 192 "exprtree.y"
                  {(yyval.no) = (yyvsp[0].no);}
#line 2059 "y.tab.c"
    break;

  case 34:
#line 195 "exprtree.y"
                                                                  {(yyval.no) = createMethodFunkNode((yyvsp[-6].str),(yyvsp[-2].no));}
#line 2065 "y.tab.c"
    break;

  case 35:
#line 196 "exprtree.y"
                                                {(yyval.no) = NULL;}
#line 2071 "y.tab.c"
    break;

  case 36:
#line 199 "exprtree.y"
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
#line 2097 "y.tab.c"
    break;

  case 37:
#line 223 "exprtree.y"
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
#line 2139 "y.tab.c"
    break;

  case 38:
#line 265 "exprtree.y"
                                    {}
#line 2145 "y.tab.c"
    break;

  case 39:
#line 266 "exprtree.y"
                 {}
#line 2151 "y.tab.c"
    break;

  case 40:
#line 269 "exprtree.y"
                            {}
#line 2157 "y.tab.c"
    break;

  case 41:
#line 270 "exprtree.y"
          {}
#line 2163 "y.tab.c"
    break;

  case 42:
#line 273 "exprtree.y"
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
#line 2181 "y.tab.c"
    break;

  case 43:
#line 288 "exprtree.y"
              {
      struct typeTable* type = tLookup((yyvsp[0].str));
      if(type) yyerror("Multiple used defined data types with same name found !!");

      tInstall((yyvsp[0].str),undefined,NULL);
      (yyval.str) = (yyvsp[0].str);
    }
#line 2193 "y.tab.c"
    break;

  case 44:
#line 297 "exprtree.y"
                                        {
      struct fieldList* f1 = (yyvsp[-1].fl);
      struct fieldList* f2 = (yyvsp[0].fl);

      while(f2->next) f2 = f2->next;
      f2->next = f1;
      (yyval.fl) = (yyvsp[0].fl);
    }
#line 2206 "y.tab.c"
    break;

  case 45:
#line 305 "exprtree.y"
              {(yyval.fl) = (yyvsp[0].fl);}
#line 2212 "y.tab.c"
    break;

  case 46:
#line 308 "exprtree.y"
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
#line 2229 "y.tab.c"
    break;

  case 47:
#line 322 "exprtree.y"
                                 {
      struct fieldList* node = makeFieldNode((yyvsp[0].str),NULL);
      node->next = (yyvsp[-2].fl);
      (yyval.fl) = node;
    }
#line 2239 "y.tab.c"
    break;

  case 48:
#line 327 "exprtree.y"
       {(yyval.fl) = makeFieldNode((yyvsp[0].str),NULL);}
#line 2245 "y.tab.c"
    break;

  case 49:
#line 331 "exprtree.y"
                                    {
      // Binding of variables   
      struct gsymbol* top = gst->top;
      binding += 8*getClassTableSize();

      while(top){
        if(top->flabel == -1){
          top->binding = binding+1;
          binding += top->size;
        }
        top = top->next;
      }
    }
#line 2263 "y.tab.c"
    break;

  case 53:
#line 352 "exprtree.y"
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

          // Also setting size of class variables to 2
          if(top->ctype) top->size = 2;
        }
        top = top->next;
      }
    }
#line 2294 "y.tab.c"
    break;

  case 57:
#line 386 "exprtree.y"
                         {
      // Making an entry in gst for function and also assigning label for that function.
      gInstall((yyvsp[-3].str),NULL,0,0,0,(yyvsp[-1].pl));
      struct gsymbol* node = gLookup((yyvsp[-3].str));
      node->flabel = ++fLabel;
    }
#line 2305 "y.tab.c"
    break;

  case 58:
#line 395 "exprtree.y"
                                      {
      struct gsymbol* node = gLookup((yyvsp[0].str));
      node->ispointer = 1;
    }
#line 2314 "y.tab.c"
    break;

  case 59:
#line 399 "exprtree.y"
        {gInstall((yyvsp[0].str),NULL,0,0,0,NULL); (yyval.str) = (yyvsp[0].str);}
#line 2320 "y.tab.c"
    break;

  case 60:
#line 400 "exprtree.y"
                    {gInstall((yyvsp[-3].str),NULL,0,(yyvsp[-1].no)->val,0,NULL); (yyval.str) = (yyvsp[-3].str);}
#line 2326 "y.tab.c"
    break;

  case 61:
#line 401 "exprtree.y"
                                 {gInstall((yyvsp[-6].str),NULL,0,(yyvsp[-4].no)->val,(yyvsp[-1].no)->val,NULL); (yyval.str) = (yyvsp[-6].str);}
#line 2332 "y.tab.c"
    break;

  case 62:
#line 405 "exprtree.y"
                           {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2338 "y.tab.c"
    break;

  case 63:
#line 406 "exprtree.y"
         {(yyval.no) = (yyvsp[0].no);}
#line 2344 "y.tab.c"
    break;

  case 64:
#line 409 "exprtree.y"
                                                            {(yyval.no) = createFunkNode((yyvsp[-6].str),(yyvsp[-2].no));}
#line 2350 "y.tab.c"
    break;

  case 65:
#line 410 "exprtree.y"
                                                     {(yyval.no) = NULL;}
#line 2356 "y.tab.c"
    break;

  case 66:
#line 414 "exprtree.y"
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
#line 2395 "y.tab.c"
    break;

  case 67:
#line 450 "exprtree.y"
                                {(yyvsp[0].pl)->next = (yyvsp[-2].pl); (yyval.pl) = (yyvsp[0].pl);}
#line 2401 "y.tab.c"
    break;

  case 68:
#line 451 "exprtree.y"
          {(yyval.pl) = (yyvsp[0].pl);}
#line 2407 "y.tab.c"
    break;

  case 69:
#line 452 "exprtree.y"
    {(yyval.pl) = NULL;}
#line 2413 "y.tab.c"
    break;

  case 70:
#line 456 "exprtree.y"
                {(yyval.pl) = makeParamNode(tLookup((yyvsp[-1].str)),(yyvsp[0].str),0);}
#line 2419 "y.tab.c"
    break;

  case 71:
#line 457 "exprtree.y"
                 {(yyval.pl) = makeParamNode(tLookup((yyvsp[-2].str)),(yyvsp[0].str),1);}
#line 2425 "y.tab.c"
    break;

  case 72:
#line 460 "exprtree.y"
           {(yyval.str) = (yyvsp[0].str);}
#line 2431 "y.tab.c"
    break;

  case 73:
#line 461 "exprtree.y"
        {(yyval.str) = (yyvsp[0].str);}
#line 2437 "y.tab.c"
    break;

  case 74:
#line 462 "exprtree.y"
       {(yyval.str) = (yyvsp[0].str);}
#line 2443 "y.tab.c"
    break;

  case 75:
#line 467 "exprtree.y"
                                                                      {(yyval.no) = createMainNode((yyvsp[-6].str),(yyvsp[-2].no));}
#line 2449 "y.tab.c"
    break;

  case 76:
#line 468 "exprtree.y"
                                                        {}
#line 2455 "y.tab.c"
    break;

  case 77:
#line 471 "exprtree.y"
                              {
      char* temp = malloc(5);
      memcpy(temp, "main\0", 5);

      gInstall(temp,tLookup("int"),0,0,0,NULL);
      struct gsymbol* node = gLookup(temp);
      node->ltop = NULL;
      node->flabel = ++fLabel;

      (yyval.str) = temp;
    }
#line 2471 "y.tab.c"
    break;

  case 78:
#line 485 "exprtree.y"
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
#line 2499 "y.tab.c"
    break;

  case 79:
#line 512 "exprtree.y"
                                    {(yyval.lnode) = (yyvsp[-1].lnode);}
#line 2505 "y.tab.c"
    break;

  case 80:
#line 513 "exprtree.y"
                 {(yyval.lnode) = NULL;}
#line 2511 "y.tab.c"
    break;

  case 81:
#line 516 "exprtree.y"
                            {
      // Both lDeclList and lDecl contains the pointer to head of the linked list of lsymbol node
      struct lsymbol* l1 = (yyvsp[-1].lnode);
      struct lsymbol* l2 = (yyvsp[0].lnode);

      // Get the last node of list2
      while(l2->next) l2 = l2->next;
      l2->next = l1;
      (yyval.lnode) = (yyvsp[0].lnode);
    }
#line 2526 "y.tab.c"
    break;

  case 82:
#line 526 "exprtree.y"
          {(yyval.lnode) = (yyvsp[0].lnode);}
#line 2532 "y.tab.c"
    break;

  case 83:
#line 529 "exprtree.y"
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
#line 2558 "y.tab.c"
    break;

  case 84:
#line 552 "exprtree.y"
                          {(yyvsp[0].lnode)->next = (yyvsp[-2].lnode); (yyval.lnode) = (yyvsp[0].lnode);}
#line 2564 "y.tab.c"
    break;

  case 85:
#line 553 "exprtree.y"
        {(yyval.lnode) = (yyvsp[0].lnode);}
#line 2570 "y.tab.c"
    break;

  case 86:
#line 557 "exprtree.y"
         {(yyval.lnode) = makeLSymbolNode((yyvsp[0].str),NULL,0);}
#line 2576 "y.tab.c"
    break;

  case 87:
#line 558 "exprtree.y"
            {(yyval.lnode) = makeLSymbolNode((yyvsp[0].str),NULL,1);}
#line 2582 "y.tab.c"
    break;

  case 88:
#line 563 "exprtree.y"
                   {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2588 "y.tab.c"
    break;

  case 89:
#line 564 "exprtree.y"
         {(yyval.no) = (yyvsp[0].no);}
#line 2594 "y.tab.c"
    break;

  case 90:
#line 567 "exprtree.y"
                 {(yyval.no) = (yyvsp[0].no);}
#line 2600 "y.tab.c"
    break;

  case 91:
#line 568 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 2606 "y.tab.c"
    break;

  case 92:
#line 569 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 2612 "y.tab.c"
    break;

  case 93:
#line 570 "exprtree.y"
           {(yyval.no) = (yyvsp[0].no);}
#line 2618 "y.tab.c"
    break;

  case 94:
#line 571 "exprtree.y"
              {(yyval.no) = (yyvsp[0].no);}
#line 2624 "y.tab.c"
    break;

  case 95:
#line 572 "exprtree.y"
                {(yyval.no) = (yyvsp[0].no);}
#line 2630 "y.tab.c"
    break;

  case 96:
#line 573 "exprtree.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 2636 "y.tab.c"
    break;

  case 97:
#line 574 "exprtree.y"
                    {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,breakNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2642 "y.tab.c"
    break;

  case 98:
#line 575 "exprtree.y"
                       {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,continueNode,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2648 "y.tab.c"
    break;

  case 99:
#line 576 "exprtree.y"
                         {(yyval.no) = createCallerNode((yyvsp[-3].str),NULL);}
#line 2654 "y.tab.c"
    break;

  case 100:
#line 577 "exprtree.y"
                                 {(yyval.no) = createCallerNode((yyvsp[-4].str),(yyvsp[-2].no));}
#line 2660 "y.tab.c"
    break;

  case 101:
#line 578 "exprtree.y"
                          {(yyval.no) = createReturnNode(lst->type,(yyvsp[-1].no),lst->name);}
#line 2666 "y.tab.c"
    break;

  case 102:
#line 579 "exprtree.y"
                                                {(yyval.no) = makeAllocNode((yyvsp[-5].no));}
#line 2672 "y.tab.c"
    break;

  case 103:
#line 580 "exprtree.y"
                                       {(yyval.no) = makeMemInitNode();}
#line 2678 "y.tab.c"
    break;

  case 104:
#line 581 "exprtree.y"
                                            {(yyval.no) = makeFreeNode((yyvsp[-2].no));}
#line 2684 "y.tab.c"
    break;

  case 105:
#line 582 "exprtree.y"
                            {(yyval.no) = (yyvsp[-1].no);}
#line 2690 "y.tab.c"
    break;

  case 106:
#line 583 "exprtree.y"
                                               {(yyval.no) = makeNewNode((yyvsp[-6].no),(yyvsp[-2].str));}
#line 2696 "y.tab.c"
    break;

  case 107:
#line 587 "exprtree.y"
                                              {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,readNode,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2702 "y.tab.c"
    break;

  case 108:
#line 590 "exprtree.y"
                                          {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,writeNode,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2708 "y.tab.c"
    break;

  case 109:
#line 594 "exprtree.y"
                                              {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,assignNode,(yyvsp[-3].no),(yyvsp[-1].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2714 "y.tab.c"
    break;

  case 110:
#line 595 "exprtree.y"
                                                {
      struct tnode* newAddrNode = createAddrNode((yyvsp[-1].no));
      (yyval.no) = createTree(noNumber,tLookup("void"),NULL,assignNode,(yyvsp[-4].no),newAddrNode,NULL,NULL,NULL,NULL,NULL,NULL);
    }
#line 2723 "y.tab.c"
    break;

  case 111:
#line 601 "exprtree.y"
                                                               {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,ifElseNode,(yyvsp[-4].no),(yyvsp[-2].no),(yyvsp[-7].no),NULL,NULL,NULL,NULL,NULL);}
#line 2729 "y.tab.c"
    break;

  case 112:
#line 602 "exprtree.y"
                                               {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,ifElseNode,(yyvsp[-2].no),NULL,(yyvsp[-5].no),NULL,NULL,NULL,NULL,NULL);}
#line 2735 "y.tab.c"
    break;

  case 113:
#line 605 "exprtree.y"
                                                            {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,whileNode,(yyvsp[-2].no),NULL,(yyvsp[-5].no),NULL,NULL,NULL,NULL,NULL);}
#line 2741 "y.tab.c"
    break;

  case 114:
#line 608 "exprtree.y"
                                                    {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,doWhileNode,(yyvsp[-5].no),NULL,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL);}
#line 2747 "y.tab.c"
    break;

  case 115:
#line 611 "exprtree.y"
                                                            {(yyval.no) = createTree(noNumber,tLookup("void"),NULL,repeatUntilNode,(yyvsp[-5].no),NULL,(yyvsp[-2].no),NULL,NULL,NULL,NULL,NULL);}
#line 2753 "y.tab.c"
    break;

  case 116:
#line 615 "exprtree.y"
                       {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,addNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2759 "y.tab.c"
    break;

  case 117:
#line 616 "exprtree.y"
                      {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,subNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2765 "y.tab.c"
    break;

  case 118:
#line 617 "exprtree.y"
                   {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,mulNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2771 "y.tab.c"
    break;

  case 119:
#line 618 "exprtree.y"
                  {(yyval.no) = createTree(noNumber,tLookup("int"),NULL,divNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2777 "y.tab.c"
    break;

  case 120:
#line 619 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,lessNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2783 "y.tab.c"
    break;

  case 121:
#line 620 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,greaterNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2789 "y.tab.c"
    break;

  case 122:
#line 621 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,lessEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2795 "y.tab.c"
    break;

  case 123:
#line 622 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,greaterEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2801 "y.tab.c"
    break;

  case 124:
#line 623 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,notEqualNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2807 "y.tab.c"
    break;

  case 125:
#line 624 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,equalNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2813 "y.tab.c"
    break;

  case 126:
#line 625 "exprtree.y"
                  {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,andNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2819 "y.tab.c"
    break;

  case 127:
#line 626 "exprtree.y"
                 {(yyval.no) = createTree(noNumber,tLookup("bool"),NULL,orNode,(yyvsp[-2].no),(yyvsp[0].no),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2825 "y.tab.c"
    break;

  case 128:
#line 627 "exprtree.y"
                 {(yyval.no) = (yyvsp[-1].no);}
#line 2831 "y.tab.c"
    break;

  case 129:
#line 628 "exprtree.y"
        {(yyval.no) = (yyvsp[0].no);}
#line 2837 "y.tab.c"
    break;

  case 130:
#line 629 "exprtree.y"
                    {(yyval.no) = createAddrNode((yyvsp[0].no));}
#line 2843 "y.tab.c"
    break;

  case 131:
#line 630 "exprtree.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 2849 "y.tab.c"
    break;

  case 132:
#line 631 "exprtree.y"
           {(yyval.no) = (yyvsp[0].no);}
#line 2855 "y.tab.c"
    break;

  case 133:
#line 632 "exprtree.y"
               {(yyval.no) = createCallerNode((yyvsp[-2].str),NULL);}
#line 2861 "y.tab.c"
    break;

  case 134:
#line 633 "exprtree.y"
                       {(yyval.no) = createCallerNode((yyvsp[-3].str),(yyvsp[-1].no));}
#line 2867 "y.tab.c"
    break;

  case 135:
#line 634 "exprtree.y"
             {(yyval.no) = makeNullNode();}
#line 2873 "y.tab.c"
    break;

  case 136:
#line 635 "exprtree.y"
                  {(yyval.no) = (yyvsp[0].no);}
#line 2879 "y.tab.c"
    break;

  case 137:
#line 638 "exprtree.y"
                           {
      struct tnode* temp = createArgsNode((yyvsp[0].no));
      temp->arglist = (yyvsp[-2].no);
      (yyval.no) = temp;
    }
#line 2889 "y.tab.c"
    break;

  case 138:
#line 643 "exprtree.y"
         {(yyval.no) = createArgsNode((yyvsp[0].no));}
#line 2895 "y.tab.c"
    break;

  case 139:
#line 649 "exprtree.y"
                             {(yyval.no) = createStarNode((yyvsp[0].no));}
#line 2901 "y.tab.c"
    break;

  case 140:
#line 650 "exprtree.y"
                      {(yyval.no) = createStarNode((yyvsp[-1].no));}
#line 2907 "y.tab.c"
    break;

  case 141:
#line 651 "exprtree.y"
       {(yyval.no) = createIdNode((yyvsp[0].str),NULL,NULL);}
#line 2913 "y.tab.c"
    break;

  case 142:
#line 652 "exprtree.y"
                    {(yyval.no) = createIdNode((yyvsp[-3].str),(yyvsp[-1].no),NULL);}
#line 2919 "y.tab.c"
    break;

  case 143:
#line 653 "exprtree.y"
                                 {(yyval.no) = createIdNode((yyvsp[-6].str),(yyvsp[-4].no),(yyvsp[-1].no));}
#line 2925 "y.tab.c"
    break;

  case 144:
#line 654 "exprtree.y"
          {(yyval.no) = (yyvsp[0].no);}
#line 2931 "y.tab.c"
    break;

  case 145:
#line 657 "exprtree.y"
                      {(yyval.no) = makeDotOperatorNode2((yyvsp[-2].no),(yyvsp[0].str));}
#line 2937 "y.tab.c"
    break;

  case 146:
#line 658 "exprtree.y"
              {(yyval.no) = makeDotOperatorNode1((yyvsp[-2].str),(yyvsp[0].str));}
#line 2943 "y.tab.c"
    break;

  case 147:
#line 659 "exprtree.y"
                {(yyval.no) = makeDotOperatorNode3((yyvsp[0].str));}
#line 2949 "y.tab.c"
    break;

  case 148:
#line 662 "exprtree.y"
                                            {(yyval.no) = makeMethodNode1((yyvsp[-3].str),(yyvsp[-1].no));}
#line 2955 "y.tab.c"
    break;

  case 149:
#line 663 "exprtree.y"
                        {(yyval.no) = makeMethodNode1((yyvsp[-2].str),NULL);}
#line 2961 "y.tab.c"
    break;

  case 150:
#line 664 "exprtree.y"
                              {(yyval.no) = makeMethodNode2((yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[-1].no));}
#line 2967 "y.tab.c"
    break;

  case 151:
#line 665 "exprtree.y"
                      {(yyval.no) = makeMethodNode2((yyvsp[-4].str),(yyvsp[-2].str),NULL);}
#line 2973 "y.tab.c"
    break;

  case 152:
#line 666 "exprtree.y"
                                 {(yyval.no) = makeMethodNode3((yyvsp[-5].no),(yyvsp[-3].str),(yyvsp[-1].no));}
#line 2979 "y.tab.c"
    break;

  case 153:
#line 667 "exprtree.y"
                         {(yyval.no) = makeMethodNode3((yyvsp[-4].no),(yyvsp[-2].str),NULL);}
#line 2985 "y.tab.c"
    break;


#line 2989 "y.tab.c"

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
#line 670 "exprtree.y"


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
