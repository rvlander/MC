
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
     GE = 283,
     PLUSUNAIRE = 284,
     MOINSUNAIRE = 285
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
#line 202 "mc.tab.c"

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
#define YYLAST   517

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNRULES -- Number of states.  */
#define YYNSTATES  217

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,     2,
      44,    45,    36,    34,    46,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    47,
      30,    43,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,    38,    49,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,    39,     2,     2,     2,
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
      25,    26,    27,    32,    40,    41
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
     265,   266,   271,   272,   274,   277,   281,   284,   288,   290,
     292,   295,   298,   301,   305,   309,   313,   320,   326,   335,
     344,   348,   352,   354,   356,   361,   369,   374,   379,   380,
     383,   388,   389,   393
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    -1,    53,    -1,    52,    53,    -1,
      54,    -1,    55,    -1,    56,    -1,    65,    -1,    65,    70,
      -1,    69,    58,    57,    -1,    58,    57,    -1,    -1,     4,
      65,    -1,    59,    64,    -1,     5,    12,    60,    -1,     5,
      62,    43,    12,    60,    -1,    44,    45,    -1,    44,    61,
      45,    -1,    12,    -1,    61,    46,    12,    -1,    25,    26,
      -1,    25,    63,    26,    -1,    12,    -1,    12,    -1,    63,
      46,    12,    -1,    63,    12,    -1,    66,    70,    -1,    65,
      -1,    -1,    66,    -1,    67,    -1,    69,    -1,    67,    69,
      -1,    68,    -1,    67,    68,    -1,    46,    -1,    47,    -1,
      69,    46,    -1,    69,    47,    -1,    13,    -1,    69,    13,
      -1,    71,    65,    -1,    71,    66,    70,    -1,    72,    -1,
      83,    -1,    86,    -1,    87,    -1,    92,    -1,    72,    34,
      72,    -1,    72,    35,    72,    -1,    72,    36,    72,    -1,
      72,    14,    72,    -1,    72,    37,    72,    -1,    72,    38,
      72,    -1,    72,    15,    72,    -1,    72,    16,    72,    -1,
      72,    42,    72,    -1,    72,    17,    72,    -1,    72,    20,
      72,    -1,    72,    21,    72,    -1,    72,    30,    72,    -1,
      72,    31,    72,    -1,    72,    22,    72,    -1,    72,    32,
      72,    -1,    72,    28,    72,    -1,    72,    29,    72,    -1,
      72,    23,    72,    -1,    72,    24,    72,    -1,    72,    18,
      -1,    72,    19,    -1,    44,    72,    45,    -1,    35,    72,
      -1,    34,    72,    -1,    39,    72,    -1,    73,    -1,    74,
      -1,    78,    -1,    11,    -1,     3,    -1,    12,    -1,    12,
      44,    76,    45,    -1,    72,    33,    72,    -1,    73,    33,
      72,    -1,    33,    -1,    72,    -1,    -1,    77,    -1,    75,
      -1,    75,    46,    77,    -1,    -1,    48,    79,    80,    49,
      -1,    -1,    81,    -1,    80,    47,    -1,    80,    47,    81,
      -1,    80,    13,    -1,    80,    13,    81,    -1,    72,    -1,
      82,    -1,    82,    72,    -1,    72,    46,    -1,    72,    27,
      -1,    82,    72,    46,    -1,    82,    72,    27,    -1,    12,
      43,    72,    -1,    12,    44,    76,    45,    43,    72,    -1,
      25,    12,    26,    43,    72,    -1,    25,    12,    44,    76,
      45,    26,    43,    72,    -1,    25,    84,    26,    43,    12,
      44,    76,    45,    -1,    85,    46,    85,    -1,    84,    46,
      85,    -1,    12,    -1,    39,    -1,    12,    44,    76,    45,
      -1,     6,    12,    43,    72,    65,    70,     4,    -1,    88,
      89,    91,     4,    -1,     7,    72,    65,    70,    -1,    -1,
      90,    89,    -1,     8,    72,    65,    70,    -1,    -1,     9,
      65,    70,    -1,    10,    72,    65,    70,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   102,   103,   105,   110,   111,   114,   115,
     118,   119,   121,   122,   125,   150,   151,   157,   158,   160,
     172,   187,   188,   189,   203,   216,   240,   262,   263,   266,
     267,   270,   271,   272,   274,   275,   277,   278,   279,   280,
     282,   283,   286,   287,   290,   291,   292,   293,   294,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   336,   360,   367,   375,   376,   379,   380,   383,   384,
     387,   387,   390,   391,   392,   393,   394,   395,   398,   399,
     400,   403,   404,   405,   406,   409,   421,   433,   445,   457,
     503,   504,   512,   518,   524,   533,   542,   545,   548,   549,
     552,   555,   556,   559
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
  "LAND", "LD", "RD", "MSPACE", "'|'", "'&'", "'<'", "'>'", "GE", "':'",
  "'+'", "'-'", "'*'", "'/'", "'\\\\'", "'~'", "PLUSUNAIRE", "MOINSUNAIRE",
  "'^'", "'='", "'('", "')'", "','", "';'", "'['", "']'", "$accept",
  "prog", "input_list", "S", "input", "scriptMFile", "functionMFile",
  "opt_end", "f_all", "f_def_line", "f_input", "f_in_arg_list", "f_output",
  "f_out_arg_list", "f_body", "opt_delimiter", "delimiter", "null_lines",
  "null_line", "empty_lines", "statement_list", "statement", "expr",
  "colon_expr", "colon_expr1", "ref_index", "ref_expr_list",
  "comma_ref_list", "matrix", "$@1", "rows", "row", "row_with_commas",
  "assignement", "output_ref_list", "out_ref", "for_command", "if_command",
  "if_block", "else_if_list", "elseif_block", "else_block",
  "while_command", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   124,    38,
      60,    62,   283,    58,    43,    45,    42,    47,    92,   126,
     284,   285,    94,    61,    40,    41,    44,    59,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    74,    75,    75,    76,    76,    77,    77,
      79,    78,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      84,    84,    85,    85,    85,    86,    87,    88,    89,    89,
      90,    91,    91,    92
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
       1,     4,     3,     3,     1,     1,     0,     1,     1,     3,
       0,     4,     0,     1,     2,     3,     2,     3,     1,     1,
       2,     2,     2,     3,     3,     3,     6,     5,     8,     8,
       3,     3,     1,     1,     4,     7,     4,     4,     0,     2,
       4,     0,     3,     5
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
      90,     9,    29,    44,    75,    76,    77,    45,    46,    47,
     118,    48,    35,    33,    41,    38,    39,    12,     0,    15,
      24,    21,     0,     0,    13,    27,     0,    80,    29,    29,
       0,    86,   112,   113,     0,     0,    73,    72,    74,     0,
      92,    42,    30,     0,     0,     0,     0,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,   118,
      10,    19,    17,     0,    26,    22,     0,     0,     0,    86,
       0,     0,   105,    84,    85,    88,     0,    87,     0,    86,
       0,     0,     0,    71,    98,     0,    93,    99,    43,    52,
      55,    56,    58,    59,    60,    63,    67,    68,    65,    66,
      61,    62,    64,    82,    49,    50,    51,    53,    54,    57,
      83,    29,    29,     0,   119,    18,     0,    25,    16,    29,
       0,   117,     0,     0,    81,     0,     0,     0,   112,   111,
     110,   102,   101,    96,    94,    91,   100,     0,     0,   116,
      20,     0,    81,   123,    89,     0,   107,   114,     0,    86,
      97,    95,   104,   103,   120,   122,     0,   106,     0,    86,
       0,   115,     0,     0,   114,   108,   109
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    10,    24,    11,    12,
      59,   113,    20,    62,    25,    13,    14,    15,    16,    28,
      41,    42,    43,    44,    45,   125,   126,   127,    46,    80,
     135,   136,   137,    47,    74,    75,    48,    49,    50,   108,
     109,   163,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -143
static const yytype_int16 yypact[] =
{
       4,     0,  -143,  -143,  -143,    13,    31,  -143,  -143,  -143,
    -143,    20,    68,    97,  -143,    68,  -143,    33,   -15,     9,
     -11,  -143,  -143,    68,  -143,  -143,  -143,    97,    72,  -143,
      74,   145,   145,  -143,   -21,    77,   145,   145,   145,   145,
    -143,  -143,    68,   313,    64,  -143,  -143,  -143,  -143,  -143,
     102,  -143,  -143,    72,  -143,  -143,  -143,    20,     3,  -143,
    -143,  -143,    87,   100,  -143,  -143,    83,    84,   181,   181,
     145,    90,   -10,  -143,   -16,    75,     1,     1,     1,   281,
     145,  -143,    97,   145,   145,   145,   145,  -143,  -143,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   118,   102,
    -143,  -143,  -143,   -18,  -143,  -143,   123,   -15,   145,    90,
      97,    97,   313,  -143,   313,    91,    85,  -143,    96,    90,
     103,    78,    78,  -143,   215,    -2,  -143,   145,  -143,     1,
       1,     1,  -143,   439,   439,   439,   342,   371,   400,   429,
     439,   439,   439,   468,   475,   475,     1,     1,     1,  -143,
     468,   181,    68,   136,  -143,  -143,   131,  -143,  -143,   181,
     104,  -143,   143,    90,   107,   145,   106,   142,   111,  -143,
    -143,  -143,  -143,   145,   145,  -143,   248,    97,    97,  -143,
    -143,    97,  -143,  -143,  -143,   145,   313,   132,   115,    90,
    -143,  -143,  -143,  -143,  -143,  -143,   156,   313,   122,    90,
     116,  -143,   145,   124,  -143,   313,  -143
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,   161,  -143,  -143,  -143,   113,   154,  -143,
      55,  -143,  -143,  -143,  -143,    14,    -9,  -143,   158,   105,
     -25,  -143,   -31,  -143,  -143,  -143,  -115,    12,  -143,  -143,
    -143,  -142,  -143,  -143,  -143,   -40,  -143,  -143,  -143,    65,
    -143,  -143,  -143
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      68,    69,    65,    27,   170,    76,    77,    78,    79,     1,
     130,   183,    18,    21,   176,   111,   128,     2,    86,    87,
      88,    60,    70,    71,    23,    19,    26,   165,   166,    58,
     131,    -2,    63,    82,   129,    61,     1,    64,     1,   122,
     124,   200,   201,   105,     2,   184,    54,   185,   112,   134,
       3,     4,   139,   140,   141,   142,    81,   138,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     3,     4,    55,
      56,     2,   120,   121,   210,    54,    66,   169,   124,    72,
     178,   179,   180,    29,   213,   171,   172,   106,   124,   114,
      29,    33,    67,    30,    31,    17,   186,    32,    33,    34,
     107,    17,   117,   115,     3,     4,    73,    73,    55,    56,
      53,   132,    35,   123,    36,    37,   118,   162,   119,    38,
     174,    36,    37,   116,    39,   167,    38,   173,    40,   175,
     189,    39,   124,   190,   196,    40,   177,   193,    29,   192,
     195,   197,   134,   134,   198,   199,    33,    67,   208,   209,
     211,   214,   204,   205,   207,   212,   206,    22,   124,   216,
     110,    57,   168,    52,   164,   187,   188,     0,   124,    36,
      37,   215,     0,   191,    38,   194,     0,     0,     0,    39,
       0,     0,     0,    40,     2,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,   105,     0,     0,     0,     3,     4,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,   181,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,   105,     0,     0,
       0,   182,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,     0,   202,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
     105,     0,     0,     0,   203,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,   105,     0,     0,   133,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,   105,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    93,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,   105,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,   105,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    83,    84,    85,    86,    87,    88,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,   105,    99,   100,   101,   102,   103,   104,     0,     0,
       0,   105,    83,    84,    85,    86,    87,    88,     0,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,     0,     0,     0,
     105,   102,   103,   104,     0,     0,     0,   105
};

static const yytype_int16 yycheck[] =
{
      31,    32,    27,    12,   119,    36,    37,    38,    39,     5,
      26,    13,    12,     0,   129,    12,    26,    13,    17,    18,
      19,    12,    43,    44,     4,    25,    12,    45,    46,    44,
      46,     0,    43,    42,    44,    26,     5,    23,     5,    70,
      71,   183,   184,    42,    13,    47,    13,    49,    45,    80,
      46,    47,    83,    84,    85,    86,    42,    82,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    46,    47,    46,
      47,    13,    68,    69,   199,    13,    12,   118,   119,    12,
      12,   131,   132,     3,   209,   120,   121,    33,   129,    12,
       3,    11,    12,     6,     7,     0,   137,    10,    11,    12,
       8,     6,    12,    26,    46,    47,    39,    39,    46,    47,
      15,    46,    25,    33,    34,    35,    43,     9,    44,    39,
      45,    34,    35,    46,    44,    12,    39,    46,    48,    43,
       4,    44,   173,    12,   175,    48,    43,     4,     3,    45,
      43,    45,   183,   184,    12,    44,    11,    12,    26,    44,
       4,    45,   187,   188,   195,    43,   191,     6,   199,    45,
      57,    17,   117,    15,   109,   161,   162,    -1,   209,    34,
      35,   212,    -1,   169,    39,   173,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    48,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    -1,    -1,    45,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    42,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    42,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    14,    15,    16,    17,    18,    19,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    42,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    42,    14,    15,    16,    17,    18,    19,    -1,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      42,    36,    37,    38,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    13,    46,    47,    51,    52,    53,    54,    55,
      56,    58,    59,    65,    66,    67,    68,    69,    12,    25,
      62,     0,    53,     4,    57,    64,    65,    66,    69,     3,
       6,     7,    10,    11,    12,    25,    34,    35,    39,    44,
      48,    70,    71,    72,    73,    74,    78,    83,    86,    87,
      88,    92,    68,    69,    13,    46,    47,    58,    44,    60,
      12,    26,    63,    43,    65,    70,    12,    12,    72,    72,
      43,    44,    12,    39,    84,    85,    72,    72,    72,    72,
      79,    65,    66,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    42,    33,     8,    89,    90,
      57,    12,    45,    61,    12,    26,    46,    12,    43,    44,
      65,    65,    72,    33,    72,    75,    76,    77,    26,    44,
      26,    46,    46,    45,    72,    80,    81,    82,    70,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,     9,    91,    89,    45,    46,    12,    60,    72,
      76,    70,    70,    46,    45,    43,    76,    43,    12,    85,
      85,    27,    46,    13,    47,    49,    72,    65,    65,     4,
      12,    65,    45,     4,    77,    43,    72,    45,    12,    44,
      81,    81,    27,    46,    70,    70,    70,    72,    26,    44,
      76,     4,    43,    76,    45,    72,    45
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
#line 100 "mc.y"
    {YYACCEPT;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 105 "mc.y"
    {
//cout << endl<< $1.source << endl;
writeJavaFile((yyvsp[(1) - (1)]).source,(yyval).ismain);
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 110 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;(yyval).ismain= true;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 111 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;(yyval).ismain=false;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 114 "mc.y"
    {(yyval).source = "";;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 115 "mc.y"
    {(yyval).source = (yyvsp[(2) - (2)]).source;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 118 "mc.y"
    {(yyval).source = (yyvsp[(2) - (3)]).source;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 119 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 125 "mc.y"
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
#line 150 "mc.y"
    {(yyval).source = "double[][] "+(yyvsp[(2) - (3)]).source + (yyvsp[(3) - (3)]).source;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 151 "mc.y"
    {(yyval).source = "public static double[][] "+(yyvsp[(4) - (5)]).source+(yyvsp[(5) - (5)]).source;
(yyval).varg=(yyvsp[(2) - (5)]).varg;
(yyval).ivarg=(yyvsp[(5) - (5)]).ivarg;
;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 157 "mc.y"
    {(yyval).source = "(MCJOutputArg[] oargs,double[][][] iargs)";;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 158 "mc.y"
    {(yyval).source = "(MCJOutputArg[] oargs,double[][][] iargs)";(yyval).ivarg = (yyvsp[(2) - (3)]).ivarg;;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 160 "mc.y"
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
#line 172 "mc.y"
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
#line 187 "mc.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 188 "mc.y"
    {(yyval).varg = (yyvsp[(2) - (3)]).varg;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 189 "mc.y"
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
#line 203 "mc.y"
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
#line 216 "mc.y"
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
#line 240 "mc.y"
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
#line 262 "mc.y"
    {(yyval).source = (yyvsp[(2) - (2)]).source;;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 263 "mc.y"
    {(yyval).source = "";;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 286 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 287 "mc.y"
    {(yyval).source = (yyvsp[(1) - (3)]).source+(yyvsp[(3) - (3)]).source;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 290 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 291 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 292 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 293 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 294 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 299 "mc.y"
    {(yyval).source = "add("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 300 "mc.y"
    {(yyval).source = "minus("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 301 "mc.y"
    {(yyval).source = "mtimes("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 302 "mc.y"
    {(yyval).source = "times("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 303 "mc.y"
    {(yyval).source = "mrdivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 304 "mc.y"
    {(yyval).source = "mldivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 305 "mc.y"
    {(yyval).source = "rdivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 306 "mc.y"
    {(yyval).source = "ldivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 307 "mc.y"
    {(yyval).source = "mpower("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 308 "mc.y"
    {(yyval).source = "power("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 309 "mc.y"
    {(yyval).source = "eq("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 310 "mc.y"
    {(yyval).source = "ne("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 311 "mc.y"
    {(yyval).source = "lt("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 312 "mc.y"
    {(yyval).source = "gt("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 313 "mc.y"
    {(yyval).source = "le("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 314 "mc.y"
    {(yyval).source = "ge("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 315 "mc.y"
    {(yyval).source = "or("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 316 "mc.y"
    {(yyval).source = "and("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 317 "mc.y"
    {(yyval).source = "lor("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 318 "mc.y"
    {(yyval).source = "land("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 319 "mc.y"
    {(yyval).source = "transpose("+(yyvsp[(1) - (2)]).source+")";;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 320 "mc.y"
    {(yyval).source = "ctranspose("+(yyvsp[(1) - (2)]).source+")";;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 321 "mc.y"
    {(yyval).source = "("+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 322 "mc.y"
    { (yyval).source = "uminus("+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 323 "mc.y"
    { (yyval).source = (yyvsp[(2) - (2)]).source;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 324 "mc.y"
    { (yyval).source = "not("+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 325 "mc.y"
    {(yyval).source = "colon("+(yyvsp[(1) - (1)]).start+",matrixFromDouble(1),"+(yyvsp[(1) - (1)]).stop+")";;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 326 "mc.y"
    {(yyval).source = "colon("+(yyvsp[(1) - (1)]).start+","+(yyvsp[(1) - (1)]).stride+","+(yyvsp[(1) - (1)]).stop+")";;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 327 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 328 "mc.y"
    { (yyval).source = "matrixFromDouble("+(yyvsp[(1) - (1)]).source+")";;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 329 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 330 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source;
		symrec sr;
		if(!(TDSget((yyvsp[(1) - (1)]).source, &sr))){
			cerr << " Symbol "+(yyvsp[(1) - (1)]).source+" not declared" << endl;		
		}
		;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 336 "mc.y"
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
#line 360 "mc.y"
    {  
  (yyval).start = (yyvsp[(1) - (3)]).source;
  (yyval).stride = (yyvsp[(3) - (3)]).source;
  (yyval).stop = (yyvsp[(3) - (3)]).source;
;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 367 "mc.y"
    {
(yyval).start = (yyvsp[(1) - (3)]).start;
(yyval).stride = (yyvsp[(1) - (3)]).stride;
(yyval).stop = (yyvsp[(3) - (3)]).source;
;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 375 "mc.y"
    {(yyval).source = "null";;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 376 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 379 "mc.y"
    {(yyval).source = "null";;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 380 "mc.y"
    {(yyval).source = "new double[][][]{"+ (yyvsp[(1) - (1)]).source+"}";;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 383 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 384 "mc.y"
    {(yyval).source = (yyvsp[(1) - (3)]).source + "," + (yyvsp[(3) - (3)]).source;;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 387 "mc.y"
    {in_matrix++;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 387 "mc.y"
    {in_matrix--; (yyval).source = (yyvsp[(3) - (4)]).source ;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 390 "mc.y"
    {(yyval).source = "new double[0][0]";;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 391 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 392 "mc.y"
    { (yyval).source = (yyvsp[(1) - (2)]).source;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 393 "mc.y"
    { (yyval).source = "vertcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 395 "mc.y"
    { (yyval).source = "vertcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 398 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source ;;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 399 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source ;;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 400 "mc.y"
    { (yyval).source = "horzcat("+(yyvsp[(1) - (2)]).source+","+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 403 "mc.y"
    { (yyval).source = (yyvsp[(1) - (2)]).source ;;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 404 "mc.y"
    { (yyval).source = (yyvsp[(1) - (2)]).source ;;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 405 "mc.y"
    { (yyval).source = "horzcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 406 "mc.y"
    { (yyval).source = "horzcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 409 "mc.y"
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

  case 106:

/* Line 1455 of yacc.c  */
#line 421 "mc.y"
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

  case 107:

/* Line 1455 of yacc.c  */
#line 433 "mc.y"
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

  case 108:

/* Line 1455 of yacc.c  */
#line 445 "mc.y"
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

  case 109:

/* Line 1455 of yacc.c  */
#line 457 "mc.y"
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

  case 110:

/* Line 1455 of yacc.c  */
#line 503 "mc.y"
    { (yyval).varg.push_back((yyvsp[(1) - (3)]).ri); (yyval).varg.push_back((yyvsp[(3) - (3)]).ri);;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 504 "mc.y"
    { 
for(int i=0;i<(yyvsp[(1) - (3)]).varg.size();i++){
	(yyval).varg.push_back((yyvsp[(1) - (3)]).varg[i]);
}
(yyval).varg.push_back((yyvsp[(3) - (3)]).ri);
;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 512 "mc.y"
    { 
ref_info rinf;
rinf.id = (yyvsp[(1) - (1)]).source;
rinf.is_simple = true;
(yyval).ri = rinf	
;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 518 "mc.y"
    { 
ref_info rinf;
rinf.id = "ignored_arg";
rinf.is_simple = true;
(yyval).ri = rinf	
;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 524 "mc.y"
    { 
ref_info rinf;
rinf.id = (yyvsp[(1) - (4)]).source;
rinf.is_simple = false;
rinf.ref_source = (yyvsp[(3) - (4)]).source;
(yyval).ri = rinf
;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 533 "mc.y"
    {
(yyval).source  = " double[][] fortemp =" + (yyvsp[(4) - (7)]).source +";\n";
(yyval).source += " for(int posdfo=0;posdfo<fortemp.length;posdfo++){ \n";
(yyval).source += " for(int sdfgsdfgdf=0;sdfgsdfgdf<fortemp[0].length;sdfgsdfgdf++){ \n";
(yyval).source += "double[][] "+ (yyvsp[(2) - (7)]).source + " = matrixFromDouble(fortemp[posdfo][sdfgsdfgdf]);\n";
(yyval).source += (yyvsp[(6) - (7)]).source;
(yyval).source += "}\n}\n";
;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 542 "mc.y"
    {(yyval).source =(yyvsp[(1) - (4)]).source+(yyvsp[(2) - (4)]).source+(yyvsp[(3) - (4)]).source;;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 545 "mc.y"
    {(yyval).source = "if(any("+(yyvsp[(2) - (4)]).source+")){"+(yyvsp[(4) - (4)]).source+"}";;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 548 "mc.y"
    {(yyval).source ="";;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 549 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source + (yyvsp[(2) - (2)]).source;;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 552 "mc.y"
    {(yyval).source = "else if(any("+(yyvsp[(2) - (4)]).source+")){"+(yyvsp[(4) - (4)]).source+"}";;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 555 "mc.y"
    {(yyval).source ="";;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 556 "mc.y"
    {(yyval).source = "else{"+(yyvsp[(3) - (3)]).source+"}";;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 560 "mc.y"
    {(yyval).source = "while(any("+(yyvsp[(2) - (5)]).source+")){"+(yyvsp[(4) - (5)]).source+"}";;}
    break;



/* Line 1455 of yacc.c  */
#line 2650 "mc.tab.c"
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
#line 565 "mc.y"

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
			to_compile.push_back(path);	
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


int main(int argc, const char ** argv){

symrec sri;
sri.idtype = FUNC;

TDSinsert("size",sri);
 int externalfile=0;
 externalfile = argc>1;	
 FILE *fid;

 to_compile.push_back(argv[1]);
 
	readPathFile("path_file");



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


