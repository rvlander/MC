
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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
#line 1 "mc.y"


#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

#include "tds.cpp"


struct ref_info{
    string id;
    bool is_simple;
    string ref_source; 
};



int yylex(void);
void yyerror (char const *s);
void writeJavaFile(const string &s);

typedef struct tagYYSTYPE{
  string source;	
  //for colon expression;
  string start;
  string stride;
  string stop;
  //for multiple assignement
  ref_info ri;
  vector<ref_info> varg;
} YYST;

#define YYSTYPE YYST






/* Line 189 of yacc.c  */
#line 119 "mc.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     END = 258,
     FUNCTION = 259,
     NBRE = 260,
     ID = 261,
     NEWLINE = 262,
     TIMES = 263,
     DIVIDE = 264,
     POWER = 265,
     FOR = 266,
     LD = 267,
     RD = 268,
     MOINSUNAIRE = 269
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 175 "mc.tab.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   269

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,    24,    17,    15,    21,    16,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    14,    22,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,     2,    26,    20,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    19
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    11,    13,    15,    17,
      20,    22,    25,    27,    29,    32,    35,    37,    40,    43,
      47,    49,    51,    53,    57,    61,    65,    69,    73,    77,
      81,    85,    89,    92,    94,    96,    98,   100,   102,   107,
     111,   115,   117,   119,   120,   122,   124,   128,   132,   133,
     135,   138,   142,   145,   149,   151,   153,   156,   159,   163,
     167,   174,   180,   189,   198,   202,   206,   208,   213,   221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      29,     0,    -1,    30,    -1,    31,    -1,    31,    36,    -1,
      -1,    32,    -1,    34,    -1,    35,    -1,    33,    35,    -1,
      34,    -1,    33,    34,    -1,    21,    -1,    22,    -1,    35,
      21,    -1,    35,    22,    -1,     7,    -1,    35,     7,    -1,
      37,    31,    -1,    37,    32,    36,    -1,    38,    -1,    48,
      -1,    51,    -1,    38,    15,    38,    -1,    38,    16,    38,
      -1,    38,    17,    38,    -1,    38,     8,    38,    -1,    38,
      18,    38,    -1,    38,     9,    38,    -1,    38,    20,    38,
      -1,    38,    10,    38,    -1,    23,    38,    24,    -1,    16,
      38,    -1,    39,    -1,    40,    -1,    44,    -1,     5,    -1,
       6,    -1,     6,    23,    42,    24,    -1,    38,    14,    38,
      -1,    39,    14,    38,    -1,    14,    -1,    38,    -1,    -1,
      43,    -1,    41,    -1,    41,    21,    43,    -1,    25,    45,
      26,    -1,    -1,    46,    -1,    45,    22,    -1,    45,    22,
      46,    -1,    45,     7,    -1,    45,     7,    46,    -1,    38,
      -1,    47,    -1,    47,    38,    -1,    38,    21,    -1,    47,
      38,    21,    -1,     6,    27,    38,    -1,     6,    23,    42,
      24,    27,    38,    -1,    12,     6,    13,    27,    38,    -1,
      12,     6,    23,    42,    24,    13,    27,    38,    -1,    12,
      49,    13,    27,     6,    23,    42,    24,    -1,    50,    21,
      50,    -1,    49,    21,    50,    -1,     6,    -1,     6,    23,
      42,    24,    -1,    11,     6,    27,    38,     7,    36,     3,
      -1,    11,     6,    27,    38,    36,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    73,    74,   105,   106,   109,   110,   111,
     113,   114,   116,   117,   118,   119,   121,   122,   125,   126,
     129,   130,   131,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   155,   170,
     177,   185,   186,   189,   190,   193,   194,   197,   200,   201,
     202,   203,   204,   205,   208,   209,   210,   213,   214,   217,
     229,   241,   253,   265,   303,   304,   312,   318,   327,   335
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "END", "FUNCTION", "NBRE", "ID",
  "NEWLINE", "TIMES", "DIVIDE", "POWER", "FOR", "LD", "RD", "':'", "'+'",
  "'-'", "'*'", "'/'", "MOINSUNAIRE", "'^'", "','", "';'", "'('", "')'",
  "'['", "']'", "'='", "$accept", "input", "scriptMFile", "opt_delimiter",
  "delimiter", "null_lines", "null_line", "empty_lines", "statement_list",
  "statement", "expr", "colon_expr", "colon_expr1", "ref_index",
  "ref_expr_list", "comma_ref_list", "matrix", "rows", "row",
  "row_with_commas", "assignement", "output_ref_list", "out_ref",
  "for_command", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    58,    43,    45,    42,    47,   269,
      94,    44,    59,    40,    41,    91,    93,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    31,    32,    32,    32,
      33,    33,    34,    34,    34,    34,    35,    35,    36,    36,
      37,    37,    37,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    39,
      40,    41,    41,    42,    42,    43,    43,    44,    45,    45,
      45,    45,    45,    45,    46,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    49,    49,    50,    50,    51,    51
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     1,     1,     1,     2,
       1,     2,     1,     1,     2,     2,     1,     2,     2,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     4,     3,
       3,     1,     1,     0,     1,     1,     3,     3,     0,     1,
       2,     3,     2,     3,     1,     1,     2,     2,     3,     3,
       6,     5,     8,     8,     3,     3,     1,     4,     7,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    16,    12,    13,     0,     2,     3,     6,     0,     7,
       8,     1,    36,    37,     0,     0,     0,     0,    48,     4,
       5,    20,    33,    34,    35,    21,    22,    11,     9,    17,
      14,    15,    43,     0,     0,    66,     0,     0,    37,    32,
       0,    54,     0,    49,    55,    18,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    42,    45,
       0,    44,    59,     0,     0,    43,     0,     0,     0,    43,
      31,    57,    52,    50,    47,    56,    19,    26,    28,    30,
      39,    23,    24,    25,    27,    29,    40,     0,    38,     0,
       0,     0,     0,    66,    65,    64,     0,    53,    51,    58,
      46,     0,     0,     0,     0,    61,    67,     0,    43,    38,
      60,     0,    24,    69,     0,    43,     0,    68,     0,     0,
      67,    62,    63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    10,    19,    20,
      58,    22,    23,    59,    60,    61,    24,    42,    43,    44,
      25,    36,    37,    26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
      -5,   -67,   -67,   -67,     3,   -67,    49,   -67,    -5,    86,
     110,   -67,   -67,   -22,     9,    12,    63,    63,    63,   -67,
      -5,   147,    19,   -67,   -67,   -67,   -67,   -67,   110,   -67,
     -67,   -67,    57,    63,    26,    -9,    68,    35,    47,    67,
     106,   119,    87,   -67,    63,   -67,    49,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,   -67,   147,    37,
      51,   -67,   147,    63,    71,    57,    74,    70,    70,    57,
     -67,   -67,    63,    63,   -67,   133,   -67,    67,    67,   -67,
     160,   164,   164,    67,    67,   -67,   160,    57,    78,    14,
      63,    54,   100,    88,   -67,   -67,    94,   -67,   -67,   -67,
     -67,    63,    49,    63,   107,   147,   112,    96,    57,   -67,
     147,   135,    82,   -67,   117,    57,   121,   -67,    63,   122,
     -67,   147,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   132,   138,   -67,   151,   152,   -38,   -67,
      -6,   -67,   -67,   -67,   -56,    79,   -67,   -67,   -66,   -67,
     -67,   -67,   -32,   -67
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -33
static const yytype_int8 yytable[] =
{
      21,    32,     1,    11,    64,    33,    97,    98,    76,    91,
      39,    40,    41,    96,    65,    34,     2,     3,    35,    12,
      13,   102,    47,    48,    49,    14,    15,    62,    50,    51,
     103,    53,    54,    56,    55,    94,    95,    17,    75,    18,
      21,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,   104,   116,    63,    12,    13,    68,    89,    87,   119,
      14,    15,    12,    38,   111,    16,    41,    41,    12,    38,
      69,    57,    17,    16,    18,    88,    93,    49,   106,    16,
      17,    66,    18,    21,   105,   -32,    17,    55,    18,    67,
     -32,   -32,    49,   -10,    72,   110,    21,   112,    90,   -32,
     -32,    92,    55,   -32,   -32,   101,   107,   -10,   -10,    73,
     113,   108,   121,    74,    47,    48,    49,    29,   109,   115,
      50,    51,    52,    53,    54,   114,    55,    47,    48,    49,
      70,    30,    31,    50,    51,    52,    53,    54,   117,    55,
      71,    47,    48,    49,   118,   120,   122,    50,    51,    52,
      53,    54,    45,    55,    99,    47,    48,    49,    46,    27,
      28,    50,    51,    52,    53,    54,   100,    55,    47,    48,
      49,     0,    47,    48,    49,    51,    52,    53,    54,     0,
      55,    53,    54,     0,    55
};

static const yytype_int8 yycheck[] =
{
       6,    23,     7,     0,    13,    27,    72,    73,    46,    65,
      16,    17,    18,    69,    23,     6,    21,    22,     6,     5,
       6,     7,     8,     9,    10,    11,    12,    33,    14,    15,
      16,    17,    18,    14,    20,    67,    68,    23,    44,    25,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    89,   108,    27,     5,     6,    21,    63,    21,   115,
      11,    12,     5,     6,   102,    16,    72,    73,     5,     6,
      23,    14,    23,    16,    25,    24,     6,    10,    24,    16,
      23,    13,    25,    89,    90,     3,    23,    20,    25,    21,
       8,     9,    10,     7,     7,   101,   102,   103,    27,    17,
      18,    27,    20,    21,    22,    27,     6,    21,    22,    22,
       3,    23,   118,    26,     8,     9,    10,     7,    24,    23,
      14,    15,    16,    17,    18,    13,    20,     8,     9,    10,
      24,    21,    22,    14,    15,    16,    17,    18,     3,    20,
      21,     8,     9,    10,    27,    24,    24,    14,    15,    16,
      17,    18,    20,    20,    21,     8,     9,    10,    20,     8,
       8,    14,    15,    16,    17,    18,    87,    20,     8,     9,
      10,    -1,     8,     9,    10,    15,    16,    17,    18,    -1,
      20,    17,    18,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    21,    22,    29,    30,    31,    32,    33,    34,
      35,     0,     5,     6,    11,    12,    16,    23,    25,    36,
      37,    38,    39,    40,    44,    48,    51,    34,    35,     7,
      21,    22,    23,    27,     6,     6,    49,    50,     6,    38,
      38,    38,    45,    46,    47,    31,    32,     8,     9,    10,
      14,    15,    16,    17,    18,    20,    14,    14,    38,    41,
      42,    43,    38,    27,    13,    23,    13,    21,    21,    23,
      24,    21,     7,    22,    26,    38,    36,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    21,    24,    38,
      27,    42,    27,     6,    50,    50,    42,    46,    46,    21,
      43,    27,     7,    16,    36,    38,    24,     6,    23,    24,
      38,    36,    38,     3,    13,    23,    42,     3,    27,    42,
      24,    38,    24
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

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
# if YYLTYPE_IS_TRIVIAL
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

/* Line 1455 of yacc.c  */
#line 66 "mc.y"
    {
cout << endl<< (yyvsp[(1) - (1)]).source << endl;
writeJavaFile((yyvsp[(1) - (1)]).source);
YYACCEPT;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 73 "mc.y"
    {(yyval).source = "";;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 74 "mc.y"
    {(yyval).source = (yyvsp[(2) - (2)]).source;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 125 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source;;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 126 "mc.y"
    {(yyval).source = (yyvsp[(1) - (3)]).source+(yyvsp[(3) - (3)]).source;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 129 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 130 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 131 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 135 "mc.y"
    {(yyval).source = "add("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 136 "mc.y"
    {(yyval).source = "minus("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 137 "mc.y"
    {(yyval).source = "mtimes("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 138 "mc.y"
    {(yyval).source = "times("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 139 "mc.y"
    {(yyval).source = "mdivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 140 "mc.y"
    {(yyval).source = "divide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 141 "mc.y"
    {(yyval).source = "mpower("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 142 "mc.y"
    {(yyval).source = "power("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 143 "mc.y"
    {(yyval).source = "("+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 144 "mc.y"
    { (yyval).source = "uminus("+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 145 "mc.y"
    {(yyval).source = "colon("+(yyvsp[(1) - (1)]).start+",matrixFromDouble(1),"+(yyvsp[(1) - (1)]).stop+")";;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 146 "mc.y"
    {(yyval).source = "colon("+(yyvsp[(1) - (1)]).start+","+(yyvsp[(1) - (1)]).stride+","+(yyvsp[(1) - (1)]).stop+")";;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 147 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 148 "mc.y"
    { (yyval).source = "matrixFromDouble("+(yyvsp[(1) - (1)]).source+")";;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 149 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source;
		symrec sr;
		if(!(TDSget((yyvsp[(1) - (1)]).source, &sr))){
			cerr << " Symbol "+(yyvsp[(1) - (1)]).source+" not declared" << endl;		
		}
		;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 155 "mc.y"
    {
          symrec sr;
		  if(!(TDSget((yyvsp[(1) - (4)]).source, &sr))){
			cerr << " Symbol "+(yyvsp[(1) - (4)]).source+" not declared" << endl;		
		  }
          if(sr.idtype == VAR) {
		  	(yyval).source = "subsref("+(yyvsp[(1) - (4)]).source+","+(yyvsp[(3) - (4)]).source+")";
          }else{
          	(yyval).source = (yyvsp[(1) - (4)]).source+"(null,"+(yyvsp[(3) - (4)]).source+")";
          }
		;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 170 "mc.y"
    {  
  (yyval).start = (yyvsp[(1) - (3)]).source;
  (yyval).stride = (yyvsp[(3) - (3)]).source;
  (yyval).stop = (yyvsp[(3) - (3)]).source;
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 177 "mc.y"
    {
(yyval).start = (yyvsp[(1) - (3)]).start;
(yyval).stride = (yyvsp[(1) - (3)]).stride;
(yyval).stop = (yyvsp[(3) - (3)]).source;
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 185 "mc.y"
    {(yyval).source = "null";;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 186 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 189 "mc.y"
    {(yyval).source = "null";;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 190 "mc.y"
    {(yyval).source = "new double[][][]{"+ (yyvsp[(1) - (1)]).source+"}";;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 193 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 194 "mc.y"
    {(yyval).source = (yyvsp[(1) - (3)]).source + "," + (yyvsp[(3) - (3)]).source;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 197 "mc.y"
    { (yyval).source = (yyvsp[(2) - (3)]).source ;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 200 "mc.y"
    {(yyval).source = "new double[0][0]";;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 201 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 202 "mc.y"
    { (yyval).source = (yyvsp[(1) - (2)]).source;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 203 "mc.y"
    { (yyval).source = "vertcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 205 "mc.y"
    { (yyval).source = "vertcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 208 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source ;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 209 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source ;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 210 "mc.y"
    { (yyval).source = "horzcat("+(yyvsp[(1) - (2)]).source+","+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 213 "mc.y"
    { (yyval).source = (yyvsp[(1) - (2)]).source ;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 214 "mc.y"
    { (yyval).source = "horzcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 217 "mc.y"
    {
(yyval).source = "";
symrec sr;
if(!TDSget((yyvsp[(1) - (3)]).source,&sr)){
 (yyval).source += "double[][] ";
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(1) - (3)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
(yyval).source += (yyvsp[(1) - (3)]).source + "=" + (yyvsp[(3) - (3)]).source;
;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 229 "mc.y"
    {
(yyval).source = "";
symrec sr;
if(!TDSget((yyvsp[(1) - (6)]).source,&sr)){
 (yyval).source += "double[][] " + (yyvsp[(1) - (6)]).source +" ;\n";
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(1) - (6)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
(yyval).source += (yyvsp[(1) - (6)]).source + " = subsasgn("+(yyvsp[(1) - (6)]).source + "," + (yyvsp[(3) - (6)]).source +","+(yyvsp[(6) - (6)]).source+")";
;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 241 "mc.y"
    {
(yyval).source = "";
symrec sr;
if(!TDSget((yyvsp[(2) - (5)]).source,&sr)){
 (yyval).source += "double[][] ";
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(2) - (5)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
(yyval).source += (yyvsp[(2) - (5)]).source + "=" + (yyvsp[(5) - (5)]).source;
;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 253 "mc.y"
    {
(yyval).source = "";
symrec sr;
if(!TDSget((yyvsp[(2) - (8)]).source,&sr)){
 (yyval).source += "double[][] " + (yyvsp[(2) - (8)]).source +" ;\n";
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(2) - (8)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
(yyval).source += (yyvsp[(2) - (8)]).source + " = subsasgn("+(yyvsp[(2) - (8)]).source + "," + (yyvsp[(4) - (8)]).source +","+(yyvsp[(8) - (8)]).source+")";
;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 265 "mc.y"
    {
   symrec sr;
   if(!TDSget((yyvsp[(5) - (8)]).source,&sr)){
	cerr << "symbol undefined" << endl; 
   } else if(sr.idtype != FUNC){
        cerr << "Too many output arguments : " + (yyvsp[(5) - (8)]).source + " is not a function !" << endl;
   }
   ostringstream oss;
   oss << "MCJOutputArg[] oa = new MCJOutputArg[" << (yyvsp[(2) - (8)]).varg.size() << "];\n";
   for(int i=0;i<(yyvsp[(2) - (8)]).varg.size();i++){
	ref_info ri = (yyvsp[(2) - (8)]).varg[i];	
	oss << "oa[" << i << "]= new MCJOutputArg();\n";	
	if(!ri.is_simple){
		oss << "double[][] " << ri.id << i << ";\n";
		oss << "oa[" << i << "].val=" << ri.id <<i<< ";\n";	
	} else {
	   oss << "oa[" << i << "].val=" << ri.id << ";\n";
        }
   	
	 
   }
   oss << (yyvsp[(5) - (8)]).source << "(oa," + (yyvsp[(7) - (8)]).source +")";
	
   for(int i=0;i<(yyvsp[(2) - (8)]).varg.size();i++){
	ref_info ri = (yyvsp[(2) - (8)]).varg[i];	
	if(!ri.is_simple){
		oss << ";\nsubsasgn(" <<ri.id <<"," << ri.ref_source <<"," << "oa[" << i <<"].val" << ")";
	}else{
		oss << ";\n"<< ri.id <<"=" << "oa[" << i <<"].val";	
	}
   }
	
   (yyval).source = oss.str();

;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 303 "mc.y"
    { (yyval).varg.push_back((yyvsp[(1) - (3)]).ri); (yyval).varg.push_back((yyvsp[(3) - (3)]).ri);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 304 "mc.y"
    { 
for(int i=0;i<(yyvsp[(1) - (3)]).varg.size();i++){
	(yyval).varg.push_back((yyvsp[(1) - (3)]).varg[i]);
}
(yyval).varg.push_back((yyvsp[(3) - (3)]).ri);
;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 312 "mc.y"
    { 
ref_info rinf;
rinf.id = (yyvsp[(1) - (1)]).source;
rinf.is_simple = true;
(yyval).ri = rinf	
;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 318 "mc.y"
    { 
ref_info rinf;
rinf.id = (yyvsp[(1) - (4)]).source;
rinf.is_simple = false;
rinf.ref_source = (yyvsp[(3) - (4)]).source;
(yyval).ri = rinf
;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 327 "mc.y"
    {
(yyval).source  = " double[][] fortemp =" + (yyvsp[(4) - (7)]).source +";\n";
(yyval).source += " for(int posdfo=0;posdfo<fortemp.length;posdfo++){ \n";
(yyval).source += " for(int sdfgsdfgdf=0;sdfgsdfgdf<fortemp[0].length;sdfgsdfgdf++){ \n";
(yyval).source += "double[][] "+ (yyvsp[(2) - (7)]).source + " = matrixFromDouble(fortemp[posdfo][sdfgsdfgdf]);\n";
(yyval).source += (yyvsp[(6) - (7)]).source;
(yyval).source += "}\n}\n";
;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 335 "mc.y"
    {
(yyval).source  = " double[][] fortemp =" + (yyvsp[(4) - (6)]).source +";\n";
(yyval).source += " for(int posdfo=0;posdfo<fortemp.length;posdfo++){ \n";
(yyval).source += " for(int sdfgsdfgdf=0;sdfgsdfgdf<fortemp[0].length;sdfgsdfgdf++){ \n";
(yyval).source += "double[][] "+ (yyvsp[(2) - (6)]).source + " = matrixFromDouble(fortemp[posdfo][sdfgsdfgdf]);\n";
(yyval).source += (yyvsp[(5) - (6)]).source;
(yyval).source += "}\n}\n";
;}
    break;



/* Line 1455 of yacc.c  */
#line 1996 "mc.tab.c"
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



/* Line 1675 of yacc.c  */
#line 346 "mc.y"

#include "lex.yy.c"

void yyerror (char const *s){
   printf("%s\n",s);
}

int main(int argc, const char ** argv){

symrec sri;
sri.idtype = FUNC;

TDSinsert("numel",sri);
 int externalfile=0;
 externalfile = argc>1;	
 FILE *fid;

 if(externalfile){
	fid = fopen(argv[1],"r");
 	yyrestart(fid);
}
 int res = yyparse();
 if(externalfile){
fclose(fid);
}

 return res;
}

void writeJavaFile(const string &source){
	ofstream outfile;
	outfile.open("MatCode.java",fstream::out);

	if (!outfile.is_open()){
		cerr << "can't open file" << endl;	
	}
 
	
	
	outfile << "import static org.mc.mcjavacore.MCJOperators.*;" << endl;
	outfile << "import static org.mc.mcfunctions.MCJFunctions.*;" << endl;
	outfile << "import org.mc.mcfunctions.MCJOutputArg;" << endl;
	outfile << "import static org.mc.mcjavautils.MCJUtils.*;" << endl;
	outfile << "import static org.mc.mcjavacore.MCJBaseFunctions.*;" << endl;
	outfile << "public class MatCode{" << endl;
	outfile << "public static void main(String args[]) throws Exception{" << endl;	
	outfile << source << endl;
	
	map<string,symrec>::iterator it;
	for (it = tds.begin(); it != tds.end(); it++){
		if ((it->second).idtype == VAR){		
			outfile << "System.out.println(\""+it->first+"=\");"+"\nprintMatrix("+it->first +");"<<endl;
			outfile << "System.out.println();" <<endl;
		}			
	}

    outfile << "}\n}" << endl;
	outfile.close();	
}

