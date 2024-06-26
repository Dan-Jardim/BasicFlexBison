/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arvore.h"
#include "python.h"

extern FILE *yyin;

extern int yylex(void);
void yyerror(const char *s);
extern int yylineno;
extern char *yytext;
ProgramNode *root;

SymbolTable *symbol_table;
int error_occurred = 0;

#define YYDEBUG 1



/* Line 189 of yacc.c  */
#line 97 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     REAL = 259,
     STRING = 260,
     ID = 261,
     REMARK_STRING = 262,
     PLUS = 263,
     MINUS = 264,
     MULT = 265,
     DIV = 266,
     POW = 267,
     LPAREN = 268,
     RPAREN = 269,
     DOIS_PONTOS = 270,
     PONTO_VIRGULA = 271,
     VIRGULA = 272,
     PONTO = 273,
     HASH = 274,
     NEWLINE = 275,
     NOT_EQUAL = 276,
     EQUAL = 277,
     MENOR_IGUAL = 278,
     MAIOR_IGUAL = 279,
     MENOR_QUE = 280,
     MAIOR_QUE = 281,
     REMARK = 282,
     PRINT = 283,
     LET = 284,
     IF = 285,
     THEN = 286,
     GOTO = 287,
     STOP = 288,
     RUN = 289,
     END = 290,
     DIM = 291,
     DATA = 292,
     CLOSE = 293,
     FOR = 294,
     TO = 295,
     STEP = 296,
     INPUT = 297,
     OUTPUT = 298,
     GOSUB = 299,
     NEXT = 300,
     OPEN = 301,
     AS = 302,
     POKE = 303,
     RETURN = 304,
     READ = 305,
     RESTORE = 306,
     SYS = 307,
     WAIT = 308,
     OR = 309,
     AND = 310,
     NOT = 311
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "parser.y"

    int intval;          
    double realval;
    char* strval;
    struct ConstantNode* const_list;
    struct IntegerNode* int_list;
	struct IdNode* id_list;
    struct ExpressionNode* expr_list;
    struct StatementNode* statement;
    struct AccessTypeNode* access_type;
    struct LineNode* line;
    struct ProgramNode* program;
  


/* Line 214 of yacc.c  */
#line 205 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 217 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    10,    13,    17,    19,    23,    26,
      32,    34,    41,    50,    53,    56,    61,    64,    70,    75,
      78,    86,    89,    92,    98,   101,   103,   105,   107,   109,
     112,   115,   118,   122,   124,   128,   130,   134,   136,   140,
     142,   147,   149,   151,   153,   157,   159,   163,   165,   169,
     171,   175,   177,   178,   182,   184,   187,   189,   193,   197,
     201,   205,   209,   213,   215,   219,   223,   225,   229,   233,
     235,   238,   240,   244,   246,   248,   250,   252,   254
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,     3,    60,    20,    59,    -1,
       3,    60,    -1,    61,    15,    60,    -1,    61,    -1,    38,
      19,     3,    -1,    37,    62,    -1,    36,     6,    13,    63,
      14,    -1,    35,    -1,    39,     6,    22,    64,    40,    64,
      -1,    39,     6,    22,    64,    40,    64,    41,     3,    -1,
      32,    64,    -1,    44,    64,    -1,    30,    64,    31,    61,
      -1,    42,    67,    -1,    42,    19,     3,    17,    67,    -1,
      29,     6,    22,    64,    -1,    45,    67,    -1,    46,    65,
      39,    66,    47,    19,     3,    -1,    48,    69,    -1,    28,
      70,    -1,    28,    19,     3,    17,    70,    -1,    50,    67,
      -1,    49,    -1,    51,    -1,    34,    -1,    33,    -1,    52,
      65,    -1,    53,    69,    -1,    27,    79,    -1,    78,    17,
      62,    -1,    78,    -1,     3,    17,    63,    -1,     3,    -1,
      71,    54,    64,    -1,    71,    -1,    13,    64,    14,    -1,
       6,    -1,     6,    13,    68,    14,    -1,    78,    -1,    42,
      -1,    43,    -1,     6,    17,    67,    -1,     6,    -1,    64,
      17,    68,    -1,    64,    -1,    65,    17,    69,    -1,    65,
      -1,    64,    16,    70,    -1,    64,    -1,    -1,    72,    55,
      71,    -1,    72,    -1,    56,    73,    -1,    73,    -1,    74,
      22,    73,    -1,    74,    21,    73,    -1,    74,    26,    73,
      -1,    74,    24,    73,    -1,    74,    25,    73,    -1,    74,
      23,    73,    -1,    74,    -1,    75,     8,    74,    -1,    75,
       9,    74,    -1,    75,    -1,    76,    10,    75,    -1,    76,
      11,    75,    -1,    76,    -1,     9,    77,    -1,    77,    -1,
      77,    12,    65,    -1,    65,    -1,     3,    -1,     5,    -1,
       4,    -1,     7,    -1,    79,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    70,    71,    74,    75,    77,    78,    79,
      80,    81,    88,    94,    97,   100,   103,   106,   109,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   131,   132,   136,   137,   141,   144,   148,   149,
     152,   153,   157,   158,   162,   163,   167,   168,   172,   173,
     177,   179,   180,   184,   187,   191,   192,   196,   199,   202,
     205,   208,   211,   214,   221,   224,   227,   231,   234,   237,
     240,   241,   245,   248,   252,   253,   254,   258,   259
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "REAL", "STRING", "ID",
  "REMARK_STRING", "PLUS", "MINUS", "MULT", "DIV", "POW", "LPAREN",
  "RPAREN", "DOIS_PONTOS", "PONTO_VIRGULA", "VIRGULA", "PONTO", "HASH",
  "NEWLINE", "NOT_EQUAL", "EQUAL", "MENOR_IGUAL", "MAIOR_IGUAL",
  "MENOR_QUE", "MAIOR_QUE", "REMARK", "PRINT", "LET", "IF", "THEN", "GOTO",
  "STOP", "RUN", "END", "DIM", "DATA", "CLOSE", "FOR", "TO", "STEP",
  "INPUT", "OUTPUT", "GOSUB", "NEXT", "OPEN", "AS", "POKE", "RETURN",
  "READ", "RESTORE", "SYS", "WAIT", "OR", "AND", "NOT", "$accept",
  "program", "lines", "statements", "statement", "constant_list",
  "integer_list", "expression", "value", "access", "id_list",
  "expression_list", "value_list", "print_list", "and_exp", "not_exp",
  "compare_exp", "add_exp", "mult_exp", "negate_exp", "power_exp",
  "constant", "remark_text", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    75,
      76,    76,    77,    77,    78,    78,    78,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     2,     3,     1,     3,     2,     5,
       1,     6,     8,     2,     2,     4,     2,     5,     4,     2,
       7,     2,     2,     5,     2,     1,     1,     1,     1,     2,
       2,     2,     3,     1,     3,     1,     3,     1,     3,     1,
       4,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     0,     3,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,    52,     0,     0,     0,    28,
      27,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    26,     0,     0,     4,     6,     1,    77,
      31,    74,    76,    75,    39,     0,     0,     0,     0,    51,
      73,    22,    37,    54,    56,    63,    66,    69,    71,    41,
       0,     0,    13,     0,     8,    33,     0,     0,    45,     0,
      16,    14,    19,     0,    49,    21,    24,    29,    30,     0,
       0,    78,     0,    70,     0,     0,    55,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     3,     5,    47,     0,    38,    52,    50,    36,    53,
      58,    57,    62,    60,    61,    59,    64,    65,    67,    68,
      72,    18,    15,    35,     0,    32,     0,    44,     0,    42,
      43,     0,    48,     0,    40,    23,     0,     9,     0,    17,
       0,    46,    34,    11,     0,     0,    20,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    26,    27,    54,   124,    39,    40,   131,
      60,   104,    65,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -69
static const yytype_int16 yypact[] =
{
       8,    24,    19,   -69,    25,    11,    34,    30,    30,   -69,
     -69,   -69,    38,    18,    36,    58,    12,    30,    73,    98,
      98,   -69,    73,   -69,    98,    98,    67,    22,   -69,   -69,
      90,   -69,   -69,   -69,    85,    98,    30,    96,    87,    97,
     -69,   -69,    60,    61,   -69,    84,    17,    31,   103,   -69,
      95,    88,   -69,   105,   -69,   104,   117,   100,   106,   121,
     -69,   -69,   -69,    86,   110,   -69,   -69,   -69,   -69,     8,
      24,   -69,    30,   103,   114,   112,   -69,    30,    30,    30,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      98,    30,    24,   127,    18,   -69,    30,    73,   115,   -15,
      98,   -69,   -69,   116,   120,   -69,    30,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   118,   122,   -69,    99,   -69,    73,   -69,
     -69,    91,   -69,    30,   -69,   -69,   127,   -69,    30,   -69,
     123,   -69,   -69,   102,   134,   137,   -69,   -69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,    72,    74,    53,    52,    13,    -7,   -12,   -69,
     -16,    14,   -20,   -68,    69,   -69,   -35,    -4,     6,   -69,
     119,    -9,   -69
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      51,    52,    62,    76,    55,    68,    66,    63,    64,   107,
      61,     1,    67,    64,    31,    32,    33,    34,    58,    28,
      35,    31,    32,    33,    36,    86,    87,   129,   130,    74,
      37,    59,    29,    31,    32,    33,    34,    70,   135,    35,
      50,    88,    89,    36,    53,   110,   111,   112,   113,   114,
     115,     4,     5,     6,     7,    56,     8,     9,    10,    11,
      12,    13,    14,    15,    57,   103,    16,    38,    17,    18,
      19,   108,    20,    21,    22,    23,    24,    25,   120,    58,
     132,   127,   116,   117,   121,    55,    38,    69,    64,   126,
      31,    32,    33,    34,   118,   119,    35,    71,    72,    75,
      36,    31,    32,    33,    34,    80,    81,    82,    83,    84,
      85,    36,   139,    77,    78,    90,    79,    91,    93,    92,
      95,    94,    96,    97,    98,    99,   103,   100,   105,   106,
     123,   143,   128,   133,   134,   136,   137,   146,   140,   138,
     147,   101,   144,   145,   102,   122,   125,   141,   109,   142,
       0,     0,     0,     0,    73
};

static const yytype_int16 yycheck[] =
{
       7,     8,    18,    38,    13,    25,    22,    19,    20,    77,
      17,     3,    24,    25,     3,     4,     5,     6,     6,     0,
       9,     3,     4,     5,    13,     8,     9,    42,    43,    36,
      19,    19,     7,     3,     4,     5,     6,    15,   106,     9,
       6,    10,    11,    13,     6,    80,    81,    82,    83,    84,
      85,    27,    28,    29,    30,    19,    32,    33,    34,    35,
      36,    37,    38,    39,     6,    72,    42,    56,    44,    45,
      46,    78,    48,    49,    50,    51,    52,    53,    90,     6,
     100,    97,    86,    87,    91,    94,    56,    20,   100,    96,
       3,     4,     5,     6,    88,    89,     9,     7,    13,     3,
      13,     3,     4,     5,     6,    21,    22,    23,    24,    25,
      26,    13,   128,    16,    54,    12,    55,    22,    13,    31,
       3,    17,    22,    17,     3,    39,   133,    17,    14,    17,
       3,   138,    17,    17,    14,    17,    14,     3,    47,    40,
       3,    69,    19,    41,    70,    92,    94,   133,    79,   136,
      -1,    -1,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    58,    59,    27,    28,    29,    30,    32,    33,
      34,    35,    36,    37,    38,    39,    42,    44,    45,    46,
      48,    49,    50,    51,    52,    53,    60,    61,     0,     7,
      79,     3,     4,     5,     6,     9,    13,    19,    56,    64,
      65,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       6,    64,    64,     6,    62,    78,    19,     6,     6,    19,
      67,    64,    67,    65,    65,    69,    67,    65,    69,    20,
      15,     7,    13,    77,    64,     3,    73,    16,    54,    55,
      21,    22,    23,    24,    25,    26,     8,     9,    10,    11,
      12,    22,    31,    13,    17,     3,    22,    17,     3,    39,
      17,    59,    60,    64,    68,    14,    17,    70,    64,    71,
      73,    73,    73,    73,    73,    73,    74,    74,    75,    75,
      65,    64,    61,     3,    63,    62,    64,    67,    17,    42,
      43,    66,    69,    17,    14,    70,    17,    14,    40,    67,
      47,    68,    63,    64,    19,    41,     3,     3
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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

/* Line 1464 of yacc.c  */
#line 66 "parser.y"
    {root = create_program_node((yyvsp[(1) - (1)].line));;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 70 "parser.y"
    {(yyval.line) = create_line_node((yyvsp[(1) - (4)].intval), (yyvsp[(2) - (4)].statement), (yyvsp[(4) - (4)].line)); ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 71 "parser.y"
    {(yyval.line) = create_line_node((yyvsp[(1) - (2)].intval), (yyvsp[(2) - (2)].statement), NULL); ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 74 "parser.y"
    {(yyval.statement) = append_statement_node((yyvsp[(3) - (3)].statement), (yyvsp[(1) - (3)].statement)); ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 75 "parser.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement); ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 77 "parser.y"
    { (yyval.statement) = create_close_statement((yyvsp[(3) - (3)].intval), 0); ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 78 "parser.y"
    { (yyval.statement) = create_data_statement((yyvsp[(2) - (2)].const_list)); ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 79 "parser.y"
    { add_variable((yyvsp[(2) - (5)].strval), VAR_ARRAY, symbol_table);(yyval.statement) = create_dim_statement((yyvsp[(2) - (5)].strval), (yyvsp[(4) - (5)].int_list)); ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 80 "parser.y"
    { (yyval.statement) = create_end_statement(); ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 81 "parser.y"
    { add_variable((yyvsp[(2) - (6)].strval), VAR_INTEGER, symbol_table);
                                                    if(check_variable_type((yyvsp[(2) - (6)].strval), VAR_INTEGER, symbol_table)==0){
                                                        yyerror("Váriavel diferente de inteiro no FOR");
                                                    };if (get_expression_type((yyvsp[(4) - (6)].expr_list), symbol_table) != INTEGER_CONST || get_expression_type((yyvsp[(6) - (6)].expr_list), symbol_table) != INTEGER_CONST) {
            yyerror("Variável diferente de inteiro no FOR");
        }
                                                    (yyval.statement) = create_for_statement((yyvsp[(2) - (6)].strval), (yyvsp[(4) - (6)].expr_list), (yyvsp[(6) - (6)].expr_list), NULL); ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 88 "parser.y"
    {add_variable((yyvsp[(2) - (8)].strval), VAR_INTEGER, symbol_table);
                                                    if(check_variable_type((yyvsp[(2) - (8)].strval), VAR_INTEGER, symbol_table)==0){
                                                        yyerror("Váriavel diferente de inteiro no FOR");
                                                    };if (get_expression_type((yyvsp[(4) - (8)].expr_list), symbol_table) != INTEGER_CONST || get_expression_type((yyvsp[(6) - (8)].expr_list), symbol_table) != INTEGER_CONST) {
            yyerror("Variável diferente de inteiro no FOR");
        } (yyval.statement) = create_for_statement((yyvsp[(2) - (8)].strval), (yyvsp[(4) - (8)].expr_list), (yyvsp[(6) - (8)].expr_list), &((yyvsp[(8) - (8)].intval))); ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 94 "parser.y"
    { if (get_expression_type((yyvsp[(2) - (2)].expr_list), symbol_table) != INTEGER_CONST) {
            yyerror("Expressão diferente de inteiro");
        }(yyval.statement) = create_goto_statement((yyvsp[(2) - (2)].expr_list)); ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 97 "parser.y"
    { if (get_expression_type((yyvsp[(2) - (2)].expr_list), symbol_table) != INTEGER_CONST) {
            yyerror("Expressão diferente de inteiro");
        }(yyval.statement) = create_gosub_statement((yyvsp[(2) - (2)].expr_list)); ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 100 "parser.y"
    {if (get_expression_type((yyvsp[(2) - (4)].expr_list), symbol_table) == STRING_CONST) {
            yyerror("Expressão inválida para IF");
        }(yyval.statement) = create_if_statement((yyvsp[(2) - (4)].expr_list), (yyvsp[(4) - (4)].statement)); ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 103 "parser.y"
    { for (IdNode *id = (yyvsp[(2) - (2)].id_list); id != NULL; id = id->next) {
                                add_variable(id->id, VAR_INTEGER, symbol_table);
                            }(yyval.statement) = create_input_statement((yyvsp[(2) - (2)].id_list)); ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 106 "parser.y"
    { for (IdNode *id = (yyvsp[(5) - (5)].id_list); id != NULL; id = id->next) {
                                add_variable(id->id, VAR_INTEGER, symbol_table);
                            }(yyval.statement) = create_input_hash_statement((yyvsp[(3) - (5)].intval), (yyvsp[(5) - (5)].id_list)); ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 109 "parser.y"
    {   if (find_symbol((yyvsp[(2) - (4)].strval), symbol_table) == NULL) {
                                            add_variable((yyvsp[(2) - (4)].strval), get_expression_type((yyvsp[(4) - (4)].expr_list), symbol_table), symbol_table);
                                        } else {
                                            check_variable_type((yyvsp[(2) - (4)].strval), get_expression_type((yyvsp[(4) - (4)].expr_list), symbol_table), symbol_table);
                                        }
                                        (yyval.statement) = create_let_statement((yyvsp[(2) - (4)].strval), (yyvsp[(4) - (4)].expr_list)); ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 115 "parser.y"
    { (yyval.statement) = create_next_statement((yyvsp[(2) - (2)].id_list)); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 116 "parser.y"
    { (yyval.statement) = create_open_statement((yyvsp[(2) - (7)].expr_list), (yyvsp[(4) - (7)].access_type), (yyvsp[(7) - (7)].intval)); ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 117 "parser.y"
    { (yyval.statement) = create_poke_statement((yyvsp[(2) - (2)].expr_list)); ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 118 "parser.y"
    { (yyval.statement) = create_print_statement((yyvsp[(2) - (2)].expr_list)); ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 119 "parser.y"
    { (yyval.statement) = create_print_hash_statement((yyvsp[(3) - (5)].intval), (yyvsp[(5) - (5)].expr_list)); ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 120 "parser.y"
    { (yyval.statement) = create_read_statement((yyvsp[(2) - (2)].id_list)); ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 121 "parser.y"
    { (yyval.statement) = create_return_statement(); ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 122 "parser.y"
    { (yyval.statement) = create_restore_statement(); ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 123 "parser.y"
    { (yyval.statement) = create_run_statement(); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 124 "parser.y"
    { (yyval.statement) = create_stop_statement(); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 125 "parser.y"
    { (yyval.statement) = create_sys_statement((yyvsp[(2) - (2)].expr_list)); ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 126 "parser.y"
    { (yyval.statement) = create_wait_statement((yyvsp[(2) - (2)].expr_list)); ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 127 "parser.y"
    { (yyval.statement) = create_remark_statement((yyvsp[(2) - (2)].strval)); ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 131 "parser.y"
    {(yyval.const_list) = append_const_node((yyvsp[(3) - (3)].const_list), (yyvsp[(1) - (3)].const_list)); ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 132 "parser.y"
    { (yyval.const_list) = (yyvsp[(1) - (1)].const_list); ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 136 "parser.y"
    { (yyval.int_list) = append_int_node((yyvsp[(3) - (3)].int_list), create_integer_node((yyvsp[(1) - (3)].intval))); ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 137 "parser.y"
    { (yyval.int_list) = create_integer_node((yyvsp[(1) - (1)].intval)); ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 141 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para disjunção.");}
                            (yyval.expr_list) = create_expression_node_binary_op(OP_OR, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 144 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 148 "parser.y"
    { (yyval.expr_list) = (yyvsp[(2) - (3)].expr_list); ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 149 "parser.y"
    { if (find_symbol((yyvsp[(1) - (1)].strval), symbol_table) == NULL) {
                                            add_variable((yyvsp[(1) - (1)].strval), VAR_INTEGER, symbol_table);
                                        } (yyval.expr_list) = create_expression_node_variable(create_id_node((yyvsp[(1) - (1)].strval))); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 152 "parser.y"
    { (yyval.expr_list) = 0; ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 153 "parser.y"
    { (yyval.expr_list) = create_expression_node_constant((yyvsp[(1) - (1)].const_list)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 157 "parser.y"
    { (yyval.access_type) = create_access_node(ACCESS_INPUT); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 158 "parser.y"
    { (yyval.access_type) = create_access_node(ACCESS_OUTPUT); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 162 "parser.y"
    { (yyval.id_list) = append_id_node((yyvsp[(3) - (3)].id_list), create_id_node((yyvsp[(1) - (3)].strval))); ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 163 "parser.y"
    { (yyval.id_list) = create_id_node((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 167 "parser.y"
    { (yyval.expr_list) = append_expression_node((yyvsp[(3) - (3)].expr_list), (yyvsp[(1) - (3)].expr_list)); ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 168 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 172 "parser.y"
    { (yyval.expr_list) = append_expression_node((yyvsp[(3) - (3)].expr_list), (yyvsp[(1) - (3)].expr_list)); ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 173 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 177 "parser.y"
    {
        (yyval.expr_list) = append_expression_node((yyvsp[(3) - (3)].expr_list), (yyvsp[(1) - (3)].expr_list)); ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 179 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 180 "parser.y"
    { (yyval.expr_list) = NULL; ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 184 "parser.y"
    {if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para conjunção.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_AND, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 187 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 191 "parser.y"
    {(yyval.expr_list) = create_expression_node_binary_op(OP_NOT, NULL, (yyvsp[(2) - (2)].expr_list));;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 192 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 196 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para comparação.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_EQUAL, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 199 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para comparação.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_NOT_EQUAL, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 202 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para comparação.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_GREATER_THAN, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 205 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para comparação.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_GREATER_EQUAL, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 208 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para comparação.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_LESS_THAN, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 211 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para comparação.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_LESS_EQUAL, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 214 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 221 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para adição.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_ADD, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 224 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para subtração.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_SUB, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 227 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 231 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para multiplicação.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_MUL, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 234 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para divisão.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_DIV, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 237 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 240 "parser.y"
    { (yyval.expr_list) = create_expression_node_binary_op(OP_NEGATE, NULL, (yyvsp[(2) - (2)].expr_list)); ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 241 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 245 "parser.y"
    { if (get_expression_type((yyvsp[(1) - (3)].expr_list), symbol_table) != get_expression_type((yyvsp[(3) - (3)].expr_list), symbol_table)) {
                                yyerror("Tipos incompatíveis para potenciação.");
                            }(yyval.expr_list) = create_expression_node_binary_op(OP_POW, (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr_list)); ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 248 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (1)].expr_list); ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 252 "parser.y"
    { (yyval.const_list) = create_constant_node(INTEGER_CONST, &((yyvsp[(1) - (1)].intval))); ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 253 "parser.y"
    { (yyval.const_list) = create_constant_node(STRING_CONST, (yyvsp[(1) - (1)].strval)); ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 254 "parser.y"
    { (yyval.const_list) = create_constant_node(REAL_CONST, &((yyvsp[(1) - (1)].realval))); ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 258 "parser.y"
    { (yyval.strval) = strdup((yyvsp[(1) - (1)].strval)); ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 259 "parser.y"
    { (yyval.strval) = concat_strings((yyvsp[(1) - (2)].strval), (yyvsp[(2) - (2)].strval)); ;}
    break;



/* Line 1464 of yacc.c  */
#line 2148 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 262 "parser.y"



void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d, token '%s'\n", s, yylineno, yytext);
    error_occurred = 1;
}



int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Não é possível abrir o arquivo");
            return 1;
        }
    } else {
        fprintf(stderr, "Uso: %s <arquivo.bas>\n", argv[0]);
        return 1;
    }

    
    //yydebug = 1;
    symbol_table = create_symbol_table();


    if (yyparse() == 0 && !error_occurred) {
        printf("Análise sintática concluída com sucesso.\n");
        generate_python_code(root);
        print_program_node(root);
    } else {
        printf("Erro na análise sintática.\n");
    }
    free_symbol_table(symbol_table);

    fclose(yyin);

    return 0;
}
