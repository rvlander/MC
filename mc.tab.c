
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
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <map>
#include <fstream>
#include <vector>

#include <dirent.h>

using namespace std;

#include "tds.cpp"


struct ref_info{
    string id;
    bool is_simple;
    string ref_source; 
};



int yylex(void);
void yyerror (char const *s);
void writeJavaFile(const string &s, bool);
int searchFunction(const string &id);

typedef struct tagYYSTYPE{
  //type of programm
  bool ismain;
  string source;	
  //for colon expression;
  string start;
  string stride;
  string stop;
  //for multiple assignement
  ref_info ri;
  vector<ref_info> varg;
  vector<ref_info> ivarg;
} YYST;

#define YYSTYPE YYST

ofstream outfile;

vector<string> to_compile;

int in_matrix =0;




/* Line 189 of yacc.c  */
#line 130 "mc.tab.c"

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
     TEXT = 258,
     END = 259,
     FUNCTION = 260,
     FOR = 261,
     IF = 262,
     ELSEIF = 263,
     ELSE = 264,
     WHILE = 265,
     NBRE = 266,
     ID = 267,
     NEWLINE = 268,
     TIMES = 269,
     DIVIDE = 270,
     LDIVIDE = 271,
     POWER = 272,
     TRANSPOSE = 273,
     CTRANSPOSE = 274,
     EQ = 275,
     NE = 276,
     LE = 277,
     LOR = 278,
     LAND = 279,
     LD = 280,
     RD = 281,
     MSPACE = 282,
     VARARGIN = 283,
     GE = 284,
     PLUSUNAIRE = 285,
     MOINSUNAIRE = 286
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
#line 203 "mc.tab.c"

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNRULES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    30,     2,
      45,    46,    37,    35,    47,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    48,
      31,    44,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,    39,    50,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    29,     2,    40,     2,     2,     2,
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
      25,    26,    27,    28,    33,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      21,    25,    28,    29,    32,    35,    39,    45,    48,    52,
      54,    58,    61,    65,    67,    69,    73,    76,    79,    81,
      82,    84,    86,    88,    91,    93,    96,    98,   100,   103,
     106,   108,   111,   114,   118,   120,   122,   124,   126,   128,
     132,   136,   140,   144,   148,   152,   156,   160,   164,   168,
     172,   176,   180,   184,   188,   192,   196,   200,   204,   208,
     211,   214,   218,   221,   224,   227,   229,   231,   233,   235,
     237,   239,   244,   248,   252,   254,   256,   257,   259,   261,
     263,   267,   268,   273,   274,   276,   279,   283,   286,   290,
     292,   294,   297,   300,   303,   307,   311,   315,   322,   328,
     337,   346,   350,   354,   356,   358,   363,   364,   373,   378,
     383,   384,   387,   392,   393,   397
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    54,    -1,    53,    54,    -1,
      55,    -1,    56,    -1,    57,    -1,    66,    -1,    66,    71,
      -1,    70,    59,    58,    -1,    59,    58,    -1,    -1,     4,
      66,    -1,    60,    65,    -1,     5,    12,    61,    -1,     5,
      63,    44,    12,    61,    -1,    45,    46,    -1,    45,    62,
      46,    -1,    12,    -1,    62,    47,    12,    -1,    25,    26,
      -1,    25,    64,    26,    -1,    12,    -1,    12,    -1,    64,
      47,    12,    -1,    64,    12,    -1,    67,    71,    -1,    66,
      -1,    -1,    67,    -1,    68,    -1,    70,    -1,    68,    70,
      -1,    69,    -1,    68,    69,    -1,    47,    -1,    48,    -1,
      70,    47,    -1,    70,    48,    -1,    13,    -1,    70,    13,
      -1,    72,    66,    -1,    72,    67,    71,    -1,    73,    -1,
      84,    -1,    87,    -1,    89,    -1,    94,    -1,    73,    35,
      73,    -1,    73,    36,    73,    -1,    73,    37,    73,    -1,
      73,    14,    73,    -1,    73,    38,    73,    -1,    73,    39,
      73,    -1,    73,    15,    73,    -1,    73,    16,    73,    -1,
      73,    43,    73,    -1,    73,    17,    73,    -1,    73,    20,
      73,    -1,    73,    21,    73,    -1,    73,    31,    73,    -1,
      73,    32,    73,    -1,    73,    22,    73,    -1,    73,    33,
      73,    -1,    73,    29,    73,    -1,    73,    30,    73,    -1,
      73,    23,    73,    -1,    73,    24,    73,    -1,    73,    18,
      -1,    73,    19,    -1,    45,    73,    46,    -1,    36,    73,
      -1,    35,    73,    -1,    40,    73,    -1,    74,    -1,    75,
      -1,    79,    -1,    11,    -1,     3,    -1,    12,    -1,    12,
      45,    77,    46,    -1,    73,    34,    73,    -1,    74,    34,
      73,    -1,    34,    -1,    73,    -1,    -1,    78,    -1,    28,
      -1,    76,    -1,    76,    47,    78,    -1,    -1,    49,    80,
      81,    50,    -1,    -1,    82,    -1,    81,    48,    -1,    81,
      48,    82,    -1,    81,    13,    -1,    81,    13,    82,    -1,
      73,    -1,    83,    -1,    83,    73,    -1,    73,    47,    -1,
      73,    27,    -1,    83,    73,    47,    -1,    83,    73,    27,
      -1,    12,    44,    73,    -1,    12,    45,    77,    46,    44,
      73,    -1,    25,    12,    26,    44,    73,    -1,    25,    12,
      45,    77,    46,    26,    44,    73,    -1,    25,    85,    26,
      44,    12,    45,    77,    46,    -1,    86,    47,    86,    -1,
      85,    47,    86,    -1,    12,    -1,    40,    -1,    12,    45,
      77,    46,    -1,    -1,     6,    12,    88,    44,    73,    66,
      71,     4,    -1,    90,    91,    93,     4,    -1,     7,    73,
      66,    71,    -1,    -1,    92,    91,    -1,     8,    73,    66,
      71,    -1,    -1,     9,    66,    71,    -1,    10,    73,    66,
      71,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   106,   107,   109,   114,   115,   118,   119,
     122,   123,   125,   126,   129,   154,   155,   161,   162,   164,
     176,   191,   192,   193,   207,   220,   244,   266,   267,   270,
     271,   274,   275,   276,   278,   279,   281,   282,   283,   284,
     286,   287,   290,   291,   294,   295,   296,   297,   298,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     339,   345,   369,   376,   384,   385,   388,   389,   390,   393,
     394,   397,   397,   400,   401,   402,   403,   404,   405,   408,
     409,   410,   413,   414,   415,   416,   419,   431,   443,   455,
     467,   522,   523,   531,   537,   543,   552,   552,   571,   574,
     577,   578,   581,   584,   585,   588
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TEXT", "END", "FUNCTION", "FOR", "IF",
  "ELSEIF", "ELSE", "WHILE", "NBRE", "ID", "NEWLINE", "TIMES", "DIVIDE",
  "LDIVIDE", "POWER", "TRANSPOSE", "CTRANSPOSE", "EQ", "NE", "LE", "LOR",
  "LAND", "LD", "RD", "MSPACE", "VARARGIN", "'|'", "'&'", "'<'", "'>'",
  "GE", "':'", "'+'", "'-'", "'*'", "'/'", "'\\\\'", "'~'", "PLUSUNAIRE",
  "MOINSUNAIRE", "'^'", "'='", "'('", "')'", "','", "';'", "'['", "']'",
  "$accept", "prog", "input_list", "S", "input", "scriptMFile",
  "functionMFile", "opt_end", "f_all", "f_def_line", "f_input",
  "f_in_arg_list", "f_output", "f_out_arg_list", "f_body", "opt_delimiter",
  "delimiter", "null_lines", "null_line", "empty_lines", "statement_list",
  "statement", "expr", "colon_expr", "colon_expr1", "ref_index",
  "ref_expr_list", "comma_ref_list", "matrix", "$@1", "rows", "row",
  "row_with_commas", "assignement", "output_ref_list", "out_ref",
  "for_command", "$@2", "if_command", "if_block", "else_if_list",
  "elseif_block", "else_block", "while_command", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   124,
      38,    60,    62,   284,    58,    43,    45,    42,    47,    92,
     126,   285,   286,    94,    61,    40,    41,    44,    59,    91,
      93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    64,    64,    64,    65,    65,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    75,    76,    76,    77,    77,    77,    78,
      78,    80,    79,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    88,    87,    89,    90,
      91,    91,    92,    93,    93,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       3,     2,     0,     2,     2,     3,     5,     2,     3,     1,
       3,     2,     3,     1,     1,     3,     2,     2,     1,     0,
       1,     1,     1,     2,     1,     2,     1,     1,     2,     2,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     4,     3,     3,     1,     1,     0,     1,     1,     1,
       3,     0,     4,     0,     1,     2,     3,     2,     3,     1,
       1,     2,     2,     2,     3,     3,     3,     6,     5,     8,
       8,     3,     3,     1,     1,     4,     0,     8,     4,     4,
       0,     2,     4,     0,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      29,     0,    40,    36,    37,     0,    29,     3,     5,     6,
       7,    12,    29,     8,    30,    31,    34,    32,    23,     0,
       0,     1,     4,    29,    11,    14,    28,    30,    32,    79,
       0,     0,     0,    78,    80,     0,     0,     0,     0,     0,
      91,     9,    29,    44,    75,    76,    77,    45,    46,    47,
     120,    48,    35,    33,    41,    38,    39,    12,     0,    15,
      24,    21,     0,     0,    13,    27,   116,    80,    29,    29,
       0,    86,   113,   114,     0,     0,    73,    72,    74,     0,
      93,    42,    30,     0,     0,     0,     0,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   120,
      10,    19,    17,     0,    26,    22,     0,     0,     0,    86,
       0,     0,   106,    88,    84,    85,    89,     0,    87,     0,
      86,     0,     0,     0,    71,    99,     0,    94,   100,    43,
      52,    55,    56,    58,    59,    60,    63,    67,    68,    65,
      66,    61,    62,    64,    82,    49,    50,    51,    53,    54,
      57,    83,    29,    29,     0,   121,    18,     0,    25,    16,
       0,     0,   119,     0,     0,    81,     0,     0,     0,   113,
     112,   111,   103,   102,    97,    95,    92,   101,     0,     0,
     118,    20,    29,    81,   125,    90,     0,   108,   115,     0,
      86,    98,    96,   105,   104,   122,   124,     0,   107,     0,
      86,     0,     0,     0,     0,   115,   117,   109,   110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    10,    24,    11,    12,
      59,   113,    20,    62,    25,    13,    14,    15,    16,    28,
      41,    42,    43,    44,    45,   126,   127,   128,    46,    80,
     136,   137,   138,    47,    74,    75,    48,   118,    49,    50,
     108,   109,   164,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -118
static const yytype_int16 yypact[] =
{
      82,    11,  -118,  -118,  -118,    16,    33,  -118,  -118,  -118,
    -118,    18,    -4,    79,  -118,    -4,  -118,    93,   -25,     3,
       4,  -118,  -118,    -4,  -118,  -118,  -118,    79,    88,  -118,
      13,   178,   178,  -118,   -26,     2,   178,   178,   178,   178,
    -118,  -118,    -4,   351,    22,  -118,  -118,  -118,  -118,  -118,
      76,  -118,  -118,    88,  -118,  -118,  -118,    18,    -9,  -118,
    -118,  -118,     0,    98,  -118,  -118,  -118,    60,   215,   215,
     178,    97,   -15,  -118,   -16,    64,   104,   104,   104,   318,
     178,  -118,    79,   178,   178,   178,   178,  -118,  -118,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   103,    76,
    -118,  -118,  -118,   -19,  -118,  -118,   101,   -25,    72,    97,
      79,    79,   351,  -118,  -118,   351,    73,    80,  -118,    83,
      97,    90,     5,     5,  -118,   250,    44,  -118,   178,  -118,
     104,   104,   104,  -118,   481,   481,   481,   381,   411,   441,
     471,   481,   481,   481,   511,   518,   518,   104,   104,   104,
    -118,   511,   215,    -4,   134,  -118,  -118,   132,  -118,  -118,
     178,   102,  -118,   145,   163,   106,   178,   105,   140,   110,
    -118,  -118,  -118,  -118,   178,   178,  -118,   284,    79,    79,
    -118,  -118,   215,  -118,  -118,  -118,   178,   351,   130,   112,
      97,  -118,  -118,  -118,  -118,  -118,  -118,    79,   351,   114,
      97,   113,   156,   178,   115,  -118,  -118,   351,  -118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,   157,  -118,  -118,  -118,   107,   150,  -118,
      45,  -118,  -118,  -118,  -118,     9,    -8,  -118,   153,    35,
      -3,  -118,   -31,  -118,  -118,  -118,  -117,    -1,  -118,  -118,
    -118,   -88,  -118,  -118,  -118,   -30,  -118,  -118,  -118,  -118,
      61,  -118,  -118,  -118
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      68,    69,   171,   111,    27,    76,    77,    78,    79,     2,
     131,   129,   114,   177,    72,    60,    21,   179,    70,    71,
      58,    26,    23,    18,    65,    66,   115,   166,   167,    61,
     130,   132,    64,    -2,    82,    17,    19,   112,     1,   122,
     125,    17,    73,     3,     4,    73,     2,   116,    63,   135,
      53,    81,   140,   141,   142,   143,   106,   184,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   120,   121,   139,
       3,     4,    29,   211,   107,    30,    31,     1,   125,    32,
      33,    34,   185,   214,   186,     2,   201,   202,     1,   125,
      29,    54,   180,   181,    35,   119,    54,   187,    33,    67,
     117,   133,   163,   168,    36,    37,   170,   172,   173,    38,
     174,    86,    87,    88,    39,   123,   175,   176,    40,     3,
       4,   124,    36,    37,   178,    55,    56,    38,   190,   192,
      55,    56,    39,   125,   191,   197,    40,   105,   193,   194,
     196,   198,   199,   135,   135,   200,   209,   210,   213,   215,
     216,   218,   169,    22,   110,   208,    29,    57,    52,   125,
     165,   188,   189,   195,    33,    67,     0,     0,     0,   125,
       0,    29,   217,     0,     0,   205,   206,     0,     0,    33,
      67,     0,     0,     0,     0,     0,     0,   124,    36,    37,
       0,   207,     0,    38,   212,     0,     0,     0,    39,     0,
       0,     0,    40,    36,    37,     0,     0,     0,    38,     0,
       0,     0,     0,    39,     0,     0,     0,    40,     2,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,   105,     0,
       0,     0,     3,     4,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,     0,     0,   182,     0,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,   105,     0,     0,     0,   183,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
       0,   203,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,   105,     0,     0,
       0,   204,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,     0,     0,     0,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,   105,     0,     0,   134,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    93,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    83,    84,    85,    86,    87,
      88,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,    83,    84,    85,    86,    87,
      88,     0,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,     0,     0,     0,   105,   102,   103,   104,     0,     0,
       0,   105
};

static const yytype_int16 yycheck[] =
{
      31,    32,   119,    12,    12,    36,    37,    38,    39,    13,
      26,    26,    12,   130,    12,    12,     0,    12,    44,    45,
      45,    12,     4,    12,    27,    12,    26,    46,    47,    26,
      45,    47,    23,     0,    42,     0,    25,    46,     5,    70,
      71,     6,    40,    47,    48,    40,    13,    47,    44,    80,
      15,    42,    83,    84,    85,    86,    34,    13,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    68,    69,    82,
      47,    48,     3,   200,     8,     6,     7,     5,   119,    10,
      11,    12,    48,   210,    50,    13,   184,   185,     5,   130,
       3,    13,   132,   133,    25,    45,    13,   138,    11,    12,
      12,    47,     9,    12,    35,    36,    44,   120,   121,    40,
      47,    17,    18,    19,    45,    28,    46,    44,    49,    47,
      48,    34,    35,    36,    44,    47,    48,    40,     4,   170,
      47,    48,    45,   174,    12,   176,    49,    43,    46,     4,
      44,    46,    12,   184,   185,    45,    26,    45,    44,    46,
       4,    46,   117,     6,    57,   196,     3,    17,    15,   200,
     109,   162,   163,   174,    11,    12,    -1,    -1,    -1,   210,
      -1,     3,   213,    -1,    -1,   188,   189,    -1,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      -1,   192,    -1,    40,   207,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    49,    35,    36,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    47,    48,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    47,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    47,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    43,    -1,    -1,    46,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    14,    15,    16,    17,    18,
      19,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    14,    15,    16,    17,    18,
      19,    -1,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    37,    38,    39,    -1,    -1,
      -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    13,    47,    48,    52,    53,    54,    55,    56,
      57,    59,    60,    66,    67,    68,    69,    70,    12,    25,
      63,     0,    54,     4,    58,    65,    66,    67,    70,     3,
       6,     7,    10,    11,    12,    25,    35,    36,    40,    45,
      49,    71,    72,    73,    74,    75,    79,    84,    87,    89,
      90,    94,    69,    70,    13,    47,    48,    59,    45,    61,
      12,    26,    64,    44,    66,    71,    12,    12,    73,    73,
      44,    45,    12,    40,    85,    86,    73,    73,    73,    73,
      80,    66,    67,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    43,    34,     8,    91,    92,
      58,    12,    46,    62,    12,    26,    47,    12,    88,    45,
      66,    66,    73,    28,    34,    73,    76,    77,    78,    26,
      45,    26,    47,    47,    46,    73,    81,    82,    83,    71,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,     9,    93,    91,    46,    47,    12,    61,
      44,    77,    71,    71,    47,    46,    44,    77,    44,    12,
      86,    86,    27,    47,    13,    48,    50,    73,    66,    66,
       4,    12,    73,    46,     4,    78,    44,    73,    46,    12,
      45,    82,    82,    27,    47,    71,    71,    66,    73,    26,
      45,    77,    71,    44,    77,    46,     4,    73,    46
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
#line 104 "mc.y"
    {YYACCEPT;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 109 "mc.y"
    {
//cout << endl<< $1.source << endl;
writeJavaFile((yyvsp[(1) - (1)]).source,(yyval).ismain);
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 114 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;(yyval).ismain= true;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 115 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;(yyval).ismain=false;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 118 "mc.y"
    {(yyval).source = "";;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 119 "mc.y"
    {(yyval).source = (yyvsp[(2) - (2)]).source;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 122 "mc.y"
    {(yyval).source = (yyvsp[(2) - (3)]).source;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 123 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 129 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source+" throws Exception{\n";

(yyval).source += "double[][] nargin = matrixFromDouble(iargs.length);\n";

for(int i=0;i<(yyvsp[(1) - (2)]).ivarg.size();i++){
ostringstream oss;
oss << i;
string li = oss.str();
(yyval).source += "double[][] " + (yyvsp[(1) - (2)]).ivarg[i].id +"= new double[0][0];\nif(nargin[0][0]>"+li+")"+(yyvsp[(1) - (2)]).ivarg[i].id+ "= iargs["+oss.str()+"];\n";
}

for(int i=0;i<(yyvsp[(1) - (2)]).varg.size();i++){
(yyval).source += "double[][] " + (yyvsp[(1) - (2)]).varg[i].id +"= new double[0][0];\n";
}
(yyval).source += (yyvsp[(2) - (2)]).source+"\n";
(yyval).source += "if(oargs !=null){\n";
for(int i=0;i<(yyvsp[(1) - (2)]).varg.size();i++){
ostringstream oss;
oss << i;
(yyval).source += "if(oargs.length>"+oss.str()+")"+ (yyvsp[(1) - (2)]).varg[i].ref_source +"=" + (yyvsp[(1) - (2)]).varg[i].id+";\n";
}
(yyval).source += "}\n";
(yyval).source +=  "return "+(yyvsp[(1) - (2)]).varg[0].id+";\n}\n";;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 154 "mc.y"
    {(yyval).source = "double[][] "+(yyvsp[(2) - (3)]).source + (yyvsp[(3) - (3)]).source;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 155 "mc.y"
    {(yyval).source = "public static double[][] "+(yyvsp[(4) - (5)]).source+(yyvsp[(5) - (5)]).source;
(yyval).varg=(yyvsp[(2) - (5)]).varg;
(yyval).ivarg=(yyvsp[(5) - (5)]).ivarg;
;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 161 "mc.y"
    {(yyval).source = "(MCJOutputArg[] oargs,double[][][] iargs)";;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 162 "mc.y"
    {(yyval).source = "(MCJOutputArg[] oargs,double[][][] iargs)";(yyval).ivarg = (yyvsp[(2) - (3)]).ivarg;;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 164 "mc.y"
    {(yyval).source = "double[][] "+(yyvsp[(1) - (1)]).source;
symrec sr;
if(!TDSget((yyvsp[(1) - (1)]).source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(1) - (1)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
ref_info ri;
ri.id = (yyvsp[(1) - (1)]).source;
(yyval).ivarg.push_back(ri);
;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 176 "mc.y"
    {
symrec sr;
if(!TDSget((yyvsp[(3) - (3)]).source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(3) - (3)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
(yyval).source = (yyvsp[(1) - (3)]).source +", double[][] "+(yyvsp[(3) - (3)]).source;
ref_info ri;
ri.id = (yyvsp[(3) - (3)]).source;
(yyval).ivarg.push_back(ri);
;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 191 "mc.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 192 "mc.y"
    {(yyval).varg = (yyvsp[(2) - (3)]).varg;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 193 "mc.y"
    {
symrec sr;
if(!TDSget((yyvsp[(1) - (1)]).source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(1) - (1)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
ref_info rinf;
rinf.id = (yyvsp[(1) - (1)]).source;	
rinf.ref_source = "oargs[0].val";
(yyval).varg.push_back(rinf);
;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 207 "mc.y"
    {
symrec sr;
if(!TDSget((yyvsp[(1) - (1)]).source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(1) - (1)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
ref_info rinf;
rinf.id = (yyvsp[(1) - (1)]).source;	
rinf.ref_source = "oargs[0].val";
(yyval).varg.push_back(rinf);
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 220 "mc.y"
    { 
symrec sr;
if(!TDSget((yyvsp[(3) - (3)]).source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(3) - (3)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
int n = (yyvsp[(1) - (3)]).varg.size();
//cerr << &$$ << " " << &$1 << endl;
//cerr << "nb o args"<< $$.varg[0].id << endl;
/*for(int i=0;i<n;i++){
cerr << "i = "<< i << endl;
	$$.varg.push_back($1.varg[i]);
}*/
//cerr << "nb o args "<< $$.varg.size() << endl;
ostringstream oss;
oss << "oargs[" << n <<"].val";
(yyvsp[(3) - (3)]).ri.ref_source = oss.str();
(yyvsp[(3) - (3)]).ri.id= (yyvsp[(3) - (3)]).source;
(yyval).varg.push_back((yyvsp[(3) - (3)]).ri);
//cerr << "nb o args "<< $$.varg.size() << endl;

;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 244 "mc.y"
    {

symrec sr;
if(!TDSget((yyvsp[(2) - (2)]).source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(2) - (2)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}

int n = (yyvsp[(1) - (2)]).varg.size(); 
/*for(int i=0;i<n;i++){
	$$.varg.push_back($1.varg[i]);
}*/
ostringstream oss;
oss << "oargs[" << n <<"].val";
(yyvsp[(2) - (2)]).ri.ref_source = oss.str();
(yyvsp[(2) - (2)]).ri.id= (yyvsp[(2) - (2)]).source;
(yyval).varg.push_back((yyvsp[(2) - (2)]).ri);
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 266 "mc.y"
    {(yyval).source = (yyvsp[(2) - (2)]).source;;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 267 "mc.y"
    {(yyval).source = "";;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 290 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 291 "mc.y"
    {(yyval).source = (yyvsp[(1) - (3)]).source+(yyvsp[(3) - (3)]).source;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 294 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 295 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 296 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 297 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 298 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 303 "mc.y"
    {(yyval).source = "add("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 304 "mc.y"
    {(yyval).source = "minus("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 305 "mc.y"
    {(yyval).source = "mtimes("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 306 "mc.y"
    {(yyval).source = "times("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 307 "mc.y"
    {(yyval).source = "mrdivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 308 "mc.y"
    {(yyval).source = "mldivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 309 "mc.y"
    {(yyval).source = "rdivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 310 "mc.y"
    {(yyval).source = "ldivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 311 "mc.y"
    {(yyval).source = "mpower("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 312 "mc.y"
    {(yyval).source = "power("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 313 "mc.y"
    {(yyval).source = "eq("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 314 "mc.y"
    {(yyval).source = "ne("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 315 "mc.y"
    {(yyval).source = "lt("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 316 "mc.y"
    {(yyval).source = "gt("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 317 "mc.y"
    {(yyval).source = "le("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 318 "mc.y"
    {(yyval).source = "ge("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 319 "mc.y"
    {(yyval).source = "or("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 320 "mc.y"
    {(yyval).source = "and("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 321 "mc.y"
    {(yyval).source = "lor("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 322 "mc.y"
    {(yyval).source = "land("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 323 "mc.y"
    {(yyval).source = "transpose("+(yyvsp[(1) - (2)]).source+")";;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 324 "mc.y"
    {(yyval).source = "ctranspose("+(yyvsp[(1) - (2)]).source+")";;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 325 "mc.y"
    {(yyval).source = "("+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 326 "mc.y"
    { (yyval).source = "uminus("+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 327 "mc.y"
    { (yyval).source = (yyvsp[(2) - (2)]).source;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 328 "mc.y"
    { (yyval).source = "not("+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 329 "mc.y"
    {(yyval).source = "colon("+(yyvsp[(1) - (1)]).start+",matrixFromDouble(1),"+(yyvsp[(1) - (1)]).stop+")";;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 330 "mc.y"
    {(yyval).source = "colon("+(yyvsp[(1) - (1)]).start+","+(yyvsp[(1) - (1)]).stride+","+(yyvsp[(1) - (1)]).stop+")";;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 331 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 332 "mc.y"
    { (yyval).source = "matrixFromDouble("+(yyvsp[(1) - (1)]).source+")";;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 333 "mc.y"
    {
int tn = (yyvsp[(1) - (1)]).source.size();
(yyvsp[(1) - (1)]).source[0] = '"';
(yyvsp[(1) - (1)]).source[tn-1] = '"'; 
(yyval).source = "matrixFromText("+(yyvsp[(1) - (1)]).source+")" 
;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 339 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source;
		symrec sr;
		if(!(TDSget((yyvsp[(1) - (1)]).source, &sr))){
			cerr << " Symbol "+(yyvsp[(1) - (1)]).source+" not declared" << endl;		
		}
		;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 345 "mc.y"
    {
          symrec sr;
		  if(!(TDSget((yyvsp[(1) - (4)]).source, &sr))){
			int t = searchFunction((yyvsp[(1) - (4)]).source);
			if(t != false) {
				sr.idtype = FUNC;
                              if(!TDSinsert((yyvsp[(1) - (4)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
			}else {
			cerr << " Symbol "+(yyvsp[(1) - (4)]).source+" not declared" << endl;
				//YYERROR;                         
			}		
		  }
          if(sr.idtype == VAR) {
		  	(yyval).source = "subsref("+(yyvsp[(1) - (4)]).source+","+(yyvsp[(3) - (4)]).source+")";
          }else{
          	(yyval).source = (yyvsp[(1) - (4)]).source+"(null,"+(yyvsp[(3) - (4)]).source+")";
          }
		;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 369 "mc.y"
    {  
  (yyval).start = (yyvsp[(1) - (3)]).source;
  (yyval).stride = (yyvsp[(3) - (3)]).source;
  (yyval).stop = (yyvsp[(3) - (3)]).source;
;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 376 "mc.y"
    {
(yyval).start = (yyvsp[(1) - (3)]).start;
(yyval).stride = (yyvsp[(1) - (3)]).stride;
(yyval).stop = (yyvsp[(3) - (3)]).source;
;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 384 "mc.y"
    {(yyval).source = "null";;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 385 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 388 "mc.y"
    {(yyval).source = "null";;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 389 "mc.y"
    {(yyval).source = "new double[][][]{"+ (yyvsp[(1) - (1)]).source+"}";;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 390 "mc.y"
    {(yyval).source = "iargs";;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 393 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 394 "mc.y"
    {(yyval).source = (yyvsp[(1) - (3)]).source + "," + (yyvsp[(3) - (3)]).source;;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 397 "mc.y"
    {in_matrix++;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 397 "mc.y"
    {in_matrix--; (yyval).source = (yyvsp[(3) - (4)]).source ;;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 400 "mc.y"
    {(yyval).source = "new double[0][0]";;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 401 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 402 "mc.y"
    { (yyval).source = (yyvsp[(1) - (2)]).source;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 403 "mc.y"
    { (yyval).source = "vertcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 405 "mc.y"
    { (yyval).source = "vertcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 408 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source ;;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 409 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source ;;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 410 "mc.y"
    { (yyval).source = "horzcat("+(yyvsp[(1) - (2)]).source+","+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 413 "mc.y"
    { (yyval).source = (yyvsp[(1) - (2)]).source ;;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 414 "mc.y"
    { (yyval).source = (yyvsp[(1) - (2)]).source ;;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 415 "mc.y"
    { (yyval).source = "horzcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 416 "mc.y"
    { (yyval).source = "horzcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 419 "mc.y"
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

  case 107:

/* Line 1455 of yacc.c  */
#line 431 "mc.y"
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

  case 108:

/* Line 1455 of yacc.c  */
#line 443 "mc.y"
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

  case 109:

/* Line 1455 of yacc.c  */
#line 455 "mc.y"
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

  case 110:

/* Line 1455 of yacc.c  */
#line 467 "mc.y"
    {
   symrec sr;
   if(!TDSget((yyvsp[(5) - (8)]).source,&sr)){
	int t = searchFunction((yyvsp[(5) - (8)]).source);
			if(t != false) {
				sr.idtype = FUNC;
                              if(!TDSinsert((yyvsp[(5) - (8)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
			}else {
			cerr << " Symbol "+(yyvsp[(5) - (8)]).source+" not declared" << endl;
				//YYERROR;                         
			}	 
   } else if(sr.idtype != FUNC){
        cerr << "Too many output arguments : " + (yyvsp[(5) - (8)]).source + " is not a function !" << endl;
   }
   ostringstream oss;
   oss << "MCJOutputArg[] oa = new MCJOutputArg[" << (yyvsp[(2) - (8)]).varg.size() << "];\n";
   for(int i=0;i<(yyvsp[(2) - (8)]).varg.size();i++){
	ref_info ri = (yyvsp[(2) - (8)]).varg[i];	
	oss << "oa[" << i << "]= new MCJOutputArg();\n";	
	/*if(!ri.is_simple){
		oss << "double[][] " << ri.id << i << ";\n";
		oss << "oa[" << i << "].val=" << ri.id <<i<< ";\n";	
	} else {
	   oss << "oa[" << i << "].val=" << ri.id << ";\n";
        }*/
	symrec sr;
	if(!TDSget(ri.id,&sr)){
 	oss << "double[][] " << ri.id <<";"<< endl;
 	sr.idtype = VAR;
 	if(!TDSinsert(ri.id,sr)){
  		cerr << "pas possible assignement" << endl;
 	}
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

  case 111:

/* Line 1455 of yacc.c  */
#line 522 "mc.y"
    { (yyval).varg.push_back((yyvsp[(1) - (3)]).ri); (yyval).varg.push_back((yyvsp[(3) - (3)]).ri);;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 523 "mc.y"
    { 
for(int i=0;i<(yyvsp[(1) - (3)]).varg.size();i++){
	(yyval).varg.push_back((yyvsp[(1) - (3)]).varg[i]);
}
(yyval).varg.push_back((yyvsp[(3) - (3)]).ri);
;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 531 "mc.y"
    { 
ref_info rinf;
rinf.id = (yyvsp[(1) - (1)]).source;
rinf.is_simple = true;
(yyval).ri = rinf	
;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 537 "mc.y"
    { 
ref_info rinf;
rinf.id = "ignored_arg";
rinf.is_simple = true;
(yyval).ri = rinf	
;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 543 "mc.y"
    { 
ref_info rinf;
rinf.id = (yyvsp[(1) - (4)]).source;
rinf.is_simple = false;
rinf.ref_source = (yyvsp[(3) - (4)]).source;
(yyval).ri = rinf
;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 552 "mc.y"
    {

symrec sr;
if(!TDSget((yyvsp[(2) - (2)]).source,&sr)){
 
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(2) - (2)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
};}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 562 "mc.y"
    {
(yyval).source  = " double[][] fortemp =" + (yyvsp[(5) - (8)]).source +";\n";
(yyval).source += " for(int posdfo=0;posdfo<fortemp.length;posdfo++){ \n";
(yyval).source += " for(int sdfgsdfgdf=0;sdfgsdfgdf<fortemp[0].length;sdfgsdfgdf++){ \n";
(yyval).source += "double[][] "+ (yyvsp[(2) - (8)]).source + " = matrixFromDouble(fortemp[posdfo][sdfgsdfgdf]);\n";
(yyval).source += (yyvsp[(7) - (8)]).source;
(yyval).source += "}\n}\n";
;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 571 "mc.y"
    {(yyval).source =(yyvsp[(1) - (4)]).source+(yyvsp[(2) - (4)]).source+(yyvsp[(3) - (4)]).source;;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 574 "mc.y"
    {(yyval).source = "if(any("+(yyvsp[(2) - (4)]).source+")){"+(yyvsp[(4) - (4)]).source+"}";;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 577 "mc.y"
    {(yyval).source ="";;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 578 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source + (yyvsp[(2) - (2)]).source;;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 581 "mc.y"
    {(yyval).source = "else if(all("+(yyvsp[(2) - (4)]).source+")){"+(yyvsp[(4) - (4)]).source+"}";;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 584 "mc.y"
    {(yyval).source ="";;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 585 "mc.y"
    {(yyval).source = "else{"+(yyvsp[(3) - (3)]).source+"}";;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 589 "mc.y"
    {(yyval).source = "while(any("+(yyvsp[(2) - (5)]).source+")){"+(yyvsp[(4) - (5)]).source+"}";;}
    break;



/* Line 1455 of yacc.c  */
#line 2700 "mc.tab.c"
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
#line 594 "mc.y"

#include "lex.yy.c"

void yyerror (char const *s){
   printf("%s\n",s);
}


void writeJavaFileHeader(const string &classname){
outfile << "import static org.mc.mcjavacore.MCJOperators.*;" << endl;
	outfile << "import static org.mc.mcfunctions.MCJFunctions.*;" << endl;
	outfile << "import org.mc.mcfunctions.MCJOutputArg;" << endl;
	outfile << "import static org.mc.mcjavautils.MCJUtils.*;" << endl;
	outfile << "import static org.mc.mcjavacore.MCJBaseFunctions.*;" << endl;
	outfile << "public class "<<classname<<"{" << endl;
	outfile << "static final double[][] pi = matrixFromDouble(Math.PI);" << endl;

}

void writeJavaFile(const string &source, bool ismain){
	
 
	
	
	if(ismain) outfile << "public static void main(String args[]) throws Exception{" << endl;	
	outfile << source << endl;
	
	if(ismain){
	map<string,symrec>::iterator it;
	for (it = tds.begin(); it != tds.end(); it++){
		if ((it->second).idtype == VAR){		
			outfile << "System.out.println(\""+it->first+"=\");"+"\nprintMatrix("+it->first +");"<<endl;
			outfile << "System.out.println();" <<endl;
		}			
	}
	outfile << "}" << endl;
	}
}
void writeJavaFileFooter(){
    	outfile << "}" << endl;	
}


/******************/
vector<string> les_path;

bool isBuiltin(string path){
     ifstream fp(path.c_str());

     char ligne[1024];

     int res = false;

     while(fp.getline(ligne,1024)&& !res){
	string ll(ligne);
        int r = ll.find("Built-in");   
	//cout << "find result  : " << r << endl;  
	if(r!=-1){
		cout << "Built-in function "<< path <<endl;	
		res = true;
	} 

     } 
	return res;
}

int searchFunction(const string &id){
	int res =0;
	DIR * pdir;
	struct dirent *pdirent;

	string target = id+".m";

	int n = les_path.size();
	int i=0;	
	
	while (res ==0 && i<n){

	string lepath = les_path[i];
	pdir = opendir(lepath.c_str());

 	if(pdir == NULL){
		cerr << "Le répertoire " << lepath << " n'a pu être ouvert!" << endl;	
	}

	while(res==0 && (pdirent = readdir(pdir)) != NULL){
		if(target.compare(pdirent->d_name)==0){
			res =1;	
			string path = lepath+ "/" + target;
			if(!isBuiltin(path)){
				cout << path << " not built-in "<< endl;
				to_compile.push_back(path);
			
			}	
		}	
	}
	i++;
	}

	return res;
}

void readPathFile(string path_file){
     ifstream fp(path_file.c_str());

     char ligne[1024];

     while(fp.getline(ligne,1024)){
	string ll(ligne);
        // cout << "added :" << ll << endl;
        les_path.push_back(ligne);     

     } 
}

void readFunctionFile(string func_file){
     ifstream fp(func_file.c_str());

     char ligne[1024];

     while(fp.getline(ligne,1024)){
	string ll(ligne);
        symrec sri;
	sri.idtype = FUNC;
	TDSinsert(ll,sri);   

     } 
}

void readGlobalsFile(string globals_file){
     ifstream fp(globals_file.c_str());

     char ligne[1024];

     while(fp.getline(ligne,1024)){
	string ll(ligne);
        symrec sri;
	sri.idtype = VAR;
	TDSinsert(ll,sri);   

     } 
}



int main(int argc, const char ** argv){


 int externalfile=0;
 externalfile = argc>1;	
 FILE *fid;

 to_compile.push_back(argv[1]);
 
	readPathFile("path_file");
	readFunctionFile("func_file");
readFunctionFile("globals_file");



	outfile.open("MatCode.java",fstream::out);

	if (!outfile.is_open()){
		cerr << "can't open file" << endl;	
	}

writeJavaFileHeader("MatCode");


cout << "Begin compiling ..." << endl;

 
while(!to_compile.empty()){
	string comp = to_compile.back();
	to_compile.pop_back();
	cout << "Compiling " << comp << endl;
	fid = fopen(comp.c_str(),"r");
	cout << "File opened" << endl; 	
	yyrestart(fid);
 	yyparse();
cout << "File parsed" << endl;
	fclose(fid);
cout << "File closed" << endl;
}
writeJavaFileFooter();
outfile.close();

 return 0;
}


