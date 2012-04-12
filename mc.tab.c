
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
} YYST;

#define YYSTYPE YYST

ofstream outfile;

vector<string> to_compile;




/* Line 189 of yacc.c  */
#line 126 "mc.tab.c"

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
     GE = 282,
     PLUSUNAIRE = 283,
     MOINSUNAIRE = 284
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
#line 197 "mc.tab.c"

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   519

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNRULES -- Number of states.  */
#define YYNSTATES  206

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    28,     2,
      43,    44,    35,    33,    45,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    46,
      29,    42,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,    37,    48,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    27,     2,    38,     2,     2,     2,
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
      25,    26,    31,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    14,    17,    19,
      22,    26,    32,    35,    39,    41,    45,    48,    52,    54,
      58,    61,    64,    66,    67,    69,    71,    73,    76,    78,
      81,    83,    85,    88,    91,    93,    96,    99,   103,   105,
     107,   109,   111,   113,   117,   121,   125,   129,   133,   137,
     141,   145,   149,   153,   157,   161,   165,   169,   173,   177,
     181,   185,   189,   193,   196,   199,   203,   206,   209,   212,
     214,   216,   218,   220,   222,   224,   229,   233,   237,   239,
     241,   242,   244,   246,   250,   254,   255,   257,   260,   264,
     267,   271,   273,   275,   278,   281,   285,   289,   296,   302,
     311,   320,   324,   328,   330,   335,   343,   348,   353,   354,
     357,   362,   363,   367
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    52,    -1,    53,    -1,    61,
      -1,    61,    66,    -1,    65,    54,    -1,    54,    -1,    55,
      60,    -1,     5,    12,    56,    -1,     5,    58,    42,    12,
      56,    -1,    43,    44,    -1,    43,    57,    44,    -1,    12,
      -1,    12,    45,    57,    -1,    25,    26,    -1,    25,    59,
      26,    -1,    12,    -1,    59,    45,    12,    -1,    59,    12,
      -1,    62,    66,    -1,    61,    -1,    -1,    62,    -1,    63,
      -1,    65,    -1,    63,    65,    -1,    64,    -1,    63,    64,
      -1,    45,    -1,    46,    -1,    65,    45,    -1,    65,    46,
      -1,    13,    -1,    65,    13,    -1,    67,    61,    -1,    67,
      62,    66,    -1,    68,    -1,    78,    -1,    81,    -1,    82,
      -1,    87,    -1,    68,    33,    68,    -1,    68,    34,    68,
      -1,    68,    35,    68,    -1,    68,    14,    68,    -1,    68,
      36,    68,    -1,    68,    37,    68,    -1,    68,    15,    68,
      -1,    68,    16,    68,    -1,    68,    41,    68,    -1,    68,
      17,    68,    -1,    68,    20,    68,    -1,    68,    21,    68,
      -1,    68,    29,    68,    -1,    68,    30,    68,    -1,    68,
      22,    68,    -1,    68,    31,    68,    -1,    68,    27,    68,
      -1,    68,    28,    68,    -1,    68,    23,    68,    -1,    68,
      24,    68,    -1,    68,    18,    -1,    68,    19,    -1,    43,
      68,    44,    -1,    34,    68,    -1,    33,    68,    -1,    38,
      68,    -1,    69,    -1,    70,    -1,    74,    -1,    11,    -1,
       3,    -1,    12,    -1,    12,    43,    72,    44,    -1,    68,
      32,    68,    -1,    69,    32,    68,    -1,    32,    -1,    68,
      -1,    -1,    73,    -1,    71,    -1,    71,    45,    73,    -1,
      47,    75,    48,    -1,    -1,    76,    -1,    75,    46,    -1,
      75,    46,    76,    -1,    75,    13,    -1,    75,    13,    76,
      -1,    68,    -1,    77,    -1,    77,    68,    -1,    68,    45,
      -1,    77,    68,    45,    -1,    12,    42,    68,    -1,    12,
      43,    72,    44,    42,    68,    -1,    25,    12,    26,    42,
      68,    -1,    25,    12,    43,    72,    44,    26,    42,    68,
      -1,    25,    79,    26,    42,    12,    43,    72,    44,    -1,
      80,    45,    80,    -1,    79,    45,    80,    -1,    12,    -1,
      12,    43,    72,    44,    -1,     6,    12,    42,    68,    61,
      66,     4,    -1,    83,    84,    86,     4,    -1,     7,    68,
      61,    66,    -1,    -1,    85,    84,    -1,     8,    68,    61,
      66,    -1,    -1,     9,    61,    66,    -1,    10,    68,    61,
      66,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   101,   102,   105,   106,   109,   110,   113,
     128,   129,   132,   133,   135,   143,   154,   155,   157,   170,
     194,   216,   217,   220,   221,   224,   225,   226,   228,   229,
     231,   232,   233,   234,   236,   237,   240,   241,   244,   245,
     246,   247,   248,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   290,   314,   321,   329,   330,
     333,   334,   337,   338,   341,   344,   345,   346,   347,   348,
     349,   352,   353,   354,   357,   358,   361,   373,   385,   397,
     409,   455,   456,   464,   470,   479,   488,   491,   494,   495,
     498,   501,   502,   505
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
  "LAND", "LD", "RD", "'|'", "'&'", "'<'", "'>'", "GE", "':'", "'+'",
  "'-'", "'*'", "'/'", "'\\\\'", "'~'", "PLUSUNAIRE", "MOINSUNAIRE", "'^'",
  "'='", "'('", "')'", "','", "';'", "'['", "']'", "$accept", "S", "input",
  "scriptMFile", "functionMFile", "f_all", "f_def_line", "f_input",
  "f_in_arg_list", "f_output", "f_out_arg_list", "f_body", "opt_delimiter",
  "delimiter", "null_lines", "null_line", "empty_lines", "statement_list",
  "statement", "expr", "colon_expr", "colon_expr1", "ref_index",
  "ref_expr_list", "comma_ref_list", "matrix", "rows", "row",
  "row_with_commas", "assignement", "output_ref_list", "out_ref",
  "for_command", "if_command", "if_block", "else_if_list", "elseif_block",
  "else_block", "while_command", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   124,    38,    60,
      62,   282,    58,    43,    45,    42,    47,    92,   126,   283,
     284,    94,    61,    40,    41,    44,    59,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    70,    71,    71,
      72,    72,    73,    73,    74,    75,    75,    75,    75,    75,
      75,    76,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    82,    83,    84,    84,
      85,    86,    86,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     1,     2,
       3,     5,     2,     3,     1,     3,     2,     3,     1,     3,
       2,     2,     1,     0,     1,     1,     1,     2,     1,     2,
       1,     1,     2,     2,     1,     2,     2,     3,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     1,     1,
       0,     1,     1,     3,     3,     0,     1,     2,     3,     2,
       3,     1,     1,     2,     2,     3,     3,     6,     5,     8,
       8,     3,     3,     1,     4,     7,     4,     4,     0,     2,
       4,     0,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      23,     0,    34,    30,    31,     0,     2,     3,     4,     8,
      23,     5,    24,    25,    28,    26,     0,     0,     0,     1,
       9,    22,    24,    26,    73,     0,     0,     0,    72,    74,
       0,     0,     0,     0,     0,    85,     6,    23,    38,    69,
      70,    71,    39,    40,    41,   108,    42,    29,    27,    35,
      32,    33,     7,     0,    10,    18,    16,     0,     0,    21,
       0,    74,    23,    23,     0,    80,   103,     0,     0,    67,
      66,    68,     0,    91,     0,    86,    92,    36,    24,     0,
       0,     0,     0,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   108,    14,    12,     0,    20,
      17,     0,     0,     0,    80,     0,     0,    96,    78,    79,
      82,     0,    81,     0,    80,     0,     0,     0,    65,    94,
      89,    87,    84,    93,    37,    46,    49,    50,    52,    53,
      54,    57,    61,    62,    59,    60,    55,    56,    58,    76,
      43,    44,    45,    47,    48,    51,    77,    23,    23,     0,
     109,     0,    13,    19,    11,    23,     0,   107,     0,     0,
      75,     0,     0,     0,   103,   102,   101,    90,    88,    95,
       0,     0,   106,    15,     0,    75,   113,    83,     0,    98,
     104,     0,    80,   110,   112,     0,    97,     0,    80,     0,
     105,     0,     0,   104,    99,   100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    10,    54,   108,    18,
      57,    20,    11,    12,    13,    14,    23,    36,    37,    38,
      39,    40,   120,   121,   122,    41,    74,    75,    76,    42,
      67,    68,    43,    44,    45,   104,   105,   159,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -102
static const yytype_int16 yypact[] =
{
      -2,    16,  -102,  -102,  -102,    17,  -102,  -102,  -102,  -102,
      -9,   103,  -102,    -9,  -102,    35,   -23,     9,   -18,  -102,
    -102,  -102,   103,     6,  -102,    10,   136,   136,  -102,    42,
      22,   136,   136,   136,   136,   136,  -102,    -9,   301,     0,
    -102,  -102,  -102,  -102,  -102,    71,  -102,  -102,     6,  -102,
    -102,  -102,  -102,     2,  -102,  -102,  -102,    66,    74,  -102,
      51,    58,   173,   173,   136,    91,   -10,   -16,    62,     8,
       8,     8,   270,   206,    -1,  -102,   136,  -102,   103,   136,
     136,   136,   136,  -102,  -102,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,    99,    71,    67,  -102,    72,  -102,
    -102,   105,   -23,   136,    91,   103,   103,   301,  -102,   301,
      73,    75,  -102,    78,    91,    79,   110,   110,  -102,  -102,
     136,   136,  -102,   238,  -102,     8,     8,     8,  -102,   441,
     441,   441,   329,   357,   385,   413,   441,   441,   441,   450,
     478,   478,     8,     8,     8,  -102,   450,   173,    -9,   122,
    -102,   115,  -102,  -102,  -102,   173,    86,  -102,   127,    91,
      90,   136,    89,   123,    97,  -102,  -102,  -102,  -102,  -102,
     103,   103,  -102,  -102,   103,  -102,  -102,  -102,   136,   301,
     116,   101,    91,  -102,  -102,   145,   301,   109,    91,   108,
    -102,   136,   111,  -102,   301,  -102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,  -102,  -102,  -102,   138,  -102,    44,    -7,  -102,
    -102,  -102,    20,     5,  -102,   144,    18,   -20,  -102,   -26,
    -102,  -102,  -102,  -101,   -11,  -102,  -102,   -41,  -102,  -102,
    -102,   -27,  -102,  -102,  -102,    54,  -102,  -102,  -102
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      62,    63,    59,     1,     2,    69,    70,    71,    72,    73,
     125,     2,   130,   166,   106,    22,   123,    19,    15,    49,
      53,    55,    60,   172,    58,    82,    83,    84,    16,   126,
      21,    48,   102,   124,    66,    56,     3,     4,   117,   119,
       1,    17,    78,     3,     4,   131,   107,   132,    49,   101,
     133,    50,    51,   135,   136,   137,   138,    77,   134,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   109,   103,
      50,    51,   115,   116,    64,    65,   112,   165,   119,   177,
     178,   199,   110,   113,    24,   167,   168,   202,   119,   175,
     176,   114,    28,    61,    73,    73,    24,   127,   158,    25,
      26,   111,   161,    27,    28,    29,   162,   163,   169,   170,
     171,   173,   174,   118,    31,    32,   182,   106,    30,    33,
     185,   186,   188,   190,    34,   191,    31,    32,    35,    24,
     192,    33,   197,   119,   198,   189,    34,    28,    61,   200,
      35,   201,   203,    52,   183,   205,   164,    47,   187,   160,
     193,   194,   196,     0,   195,     0,   119,     0,     0,    31,
      32,     0,   119,     0,    33,   204,     0,   180,   181,    34,
       0,     0,     0,    35,     0,   184,     2,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,   101,     0,     0,     0,     3,     4,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     0,     0,     0,   101,     0,     0,
       0,   129,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,   101,
       0,     0,     0,   179,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,     0,     0,
       0,   101,     0,     0,   128,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
       0,     0,   101,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,    89,     0,     0,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
     101,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,   101,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,   101,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,   101,    79,    80,    81,    82,    83,
      84,     0,     0,     0,    79,    80,    81,    82,    83,    84,
       0,     0,     0,    95,    96,    97,    98,    99,   100,     0,
       0,     0,   101,    96,    97,    98,    99,   100,     0,     0,
       0,   101,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,     0,     0,   101
};

static const yytype_int16 yycheck[] =
{
      26,    27,    22,     5,    13,    31,    32,    33,    34,    35,
      26,    13,    13,   114,    12,    10,    26,     0,     0,    13,
      43,    12,    12,   124,    42,    17,    18,    19,    12,    45,
      10,    13,    32,    43,    12,    26,    45,    46,    64,    65,
       5,    25,    37,    45,    46,    46,    44,    48,    13,    41,
      76,    45,    46,    79,    80,    81,    82,    37,    78,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    12,     8,
      45,    46,    62,    63,    42,    43,    12,   113,   114,   130,
     131,   192,    26,    42,     3,   115,   116,   198,   124,   126,
     127,    43,    11,    12,   130,   131,     3,    45,     9,     6,
       7,    45,    45,    10,    11,    12,    44,    12,    45,    44,
      42,    42,    12,    32,    33,    34,     4,    12,    25,    38,
      44,     4,    42,    44,    43,    12,    33,    34,    47,     3,
      43,    38,    26,   169,    43,   171,    43,    11,    12,     4,
      47,    42,    44,    15,   161,    44,   112,    13,   169,   105,
     180,   181,   188,    -1,   184,    -1,   192,    -1,    -1,    33,
      34,    -1,   198,    -1,    38,   201,    -1,   157,   158,    43,
      -1,    -1,    -1,    47,    -1,   165,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    45,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    41,    -1,    -1,    44,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    41,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    41,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    41,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    13,    45,    46,    50,    51,    52,    53,    54,
      55,    61,    62,    63,    64,    65,    12,    25,    58,     0,
      60,    61,    62,    65,     3,     6,     7,    10,    11,    12,
      25,    33,    34,    38,    43,    47,    66,    67,    68,    69,
      70,    74,    78,    81,    82,    83,    87,    64,    65,    13,
      45,    46,    54,    43,    56,    12,    26,    59,    42,    66,
      12,    12,    68,    68,    42,    43,    12,    79,    80,    68,
      68,    68,    68,    68,    75,    76,    77,    61,    62,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    41,    32,     8,    84,    85,    12,    44,    57,    12,
      26,    45,    12,    42,    43,    61,    61,    68,    32,    68,
      71,    72,    73,    26,    43,    26,    45,    45,    44,    45,
      13,    46,    48,    68,    66,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,     9,    86,
      84,    45,    44,    12,    56,    68,    72,    66,    66,    45,
      44,    42,    72,    42,    12,    80,    80,    76,    76,    45,
      61,    61,     4,    57,    61,    44,     4,    73,    42,    68,
      44,    12,    43,    66,    66,    66,    68,    26,    43,    72,
       4,    42,    72,    44,    68,    44
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
#line 96 "mc.y"
    {
cout << endl<< (yyvsp[(1) - (1)]).source << endl;
writeJavaFile((yyvsp[(1) - (1)]).source,(yyval).ismain);
YYACCEPT;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 101 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;(yyval).ismain= true;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 102 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;(yyval).ismain=false;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 105 "mc.y"
    {(yyval).source = "";;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 106 "mc.y"
    {(yyval).source = (yyvsp[(2) - (2)]).source;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 109 "mc.y"
    {(yyval).source = (yyvsp[(2) - (2)]).source;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 110 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 113 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source+"{\n";
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

  case 10:

/* Line 1455 of yacc.c  */
#line 128 "mc.y"
    {(yyval).source = "double[][] "+(yyvsp[(2) - (3)]).source + (yyvsp[(3) - (3)]).source;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 129 "mc.y"
    {(yyval).source = "public static double[][] "+(yyvsp[(4) - (5)]).source+(yyvsp[(5) - (5)]).source;(yyval).varg=(yyvsp[(2) - (5)]).varg;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 132 "mc.y"
    {(yyval).source = "(MCJOutArgput[] oargs)";;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 133 "mc.y"
    {(yyval).source = "(MCJOutputArg[] oargs,"+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 135 "mc.y"
    {(yyval).source = "double[][] "+(yyvsp[(1) - (1)]).source;
symrec sr;
if(!TDSget((yyvsp[(1) - (1)]).source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(1) - (1)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
};}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 143 "mc.y"
    {
symrec sr;
if(!TDSget((yyvsp[(1) - (3)]).source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert((yyvsp[(1) - (3)]).source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
(yyval).source = "double[][] "+(yyvsp[(1) - (3)]).source +","+(yyvsp[(3) - (3)]).source;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 154 "mc.y"
    {;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 155 "mc.y"
    {(yyval).varg = (yyvsp[(2) - (3)]).varg;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 157 "mc.y"
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

  case 19:

/* Line 1455 of yacc.c  */
#line 170 "mc.y"
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

  case 20:

/* Line 1455 of yacc.c  */
#line 194 "mc.y"
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

  case 21:

/* Line 1455 of yacc.c  */
#line 216 "mc.y"
    {(yyval).source = (yyvsp[(2) - (2)]).source;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 217 "mc.y"
    {(yyval).source = "";;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 240 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 241 "mc.y"
    {(yyval).source = (yyvsp[(1) - (3)]).source+(yyvsp[(3) - (3)]).source;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 244 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 245 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 246 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 247 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 248 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source+";\n";;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 253 "mc.y"
    {(yyval).source = "add("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 254 "mc.y"
    {(yyval).source = "minus("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 255 "mc.y"
    {(yyval).source = "mtimes("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 256 "mc.y"
    {(yyval).source = "times("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 257 "mc.y"
    {(yyval).source = "mrdivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 258 "mc.y"
    {(yyval).source = "mldivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 259 "mc.y"
    {(yyval).source = "rdivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 260 "mc.y"
    {(yyval).source = "ldivide("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 261 "mc.y"
    {(yyval).source = "mpower("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 262 "mc.y"
    {(yyval).source = "power("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 263 "mc.y"
    {(yyval).source = "eq("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 264 "mc.y"
    {(yyval).source = "ne("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 265 "mc.y"
    {(yyval).source = "lt("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 266 "mc.y"
    {(yyval).source = "gt("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 267 "mc.y"
    {(yyval).source = "le("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 268 "mc.y"
    {(yyval).source = "ge("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 269 "mc.y"
    {(yyval).source = "or("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 270 "mc.y"
    {(yyval).source = "and("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 271 "mc.y"
    {(yyval).source = "lor("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 272 "mc.y"
    {(yyval).source = "land("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 273 "mc.y"
    {(yyval).source = "transpose("+(yyvsp[(1) - (2)]).source+")";;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 274 "mc.y"
    {(yyval).source = "ctranspose("+(yyvsp[(1) - (2)]).source+")";;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 275 "mc.y"
    {(yyval).source = "("+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 276 "mc.y"
    { (yyval).source = "uminus("+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 277 "mc.y"
    { (yyval).source = (yyvsp[(2) - (2)]).source;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 278 "mc.y"
    { (yyval).source = "not("+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 279 "mc.y"
    {(yyval).source = "colon("+(yyvsp[(1) - (1)]).start+",matrixFromDouble(1),"+(yyvsp[(1) - (1)]).stop+")";;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 280 "mc.y"
    {(yyval).source = "colon("+(yyvsp[(1) - (1)]).start+","+(yyvsp[(1) - (1)]).stride+","+(yyvsp[(1) - (1)]).stop+")";;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 281 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 282 "mc.y"
    { (yyval).source = "matrixFromDouble("+(yyvsp[(1) - (1)]).source+")";;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 283 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 284 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source;
		symrec sr;
		if(!(TDSget((yyvsp[(1) - (1)]).source, &sr))){
			cerr << " Symbol "+(yyvsp[(1) - (1)]).source+" not declared" << endl;		
		}
		;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 290 "mc.y"
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
				YYERROR;                         
			}		
		  }
          if(sr.idtype == VAR) {
		  	(yyval).source = "subsref("+(yyvsp[(1) - (4)]).source+","+(yyvsp[(3) - (4)]).source+")";
          }else{
          	(yyval).source = (yyvsp[(1) - (4)]).source+"(null,"+(yyvsp[(3) - (4)]).source+")";
          }
		;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 314 "mc.y"
    {  
  (yyval).start = (yyvsp[(1) - (3)]).source;
  (yyval).stride = (yyvsp[(3) - (3)]).source;
  (yyval).stop = (yyvsp[(3) - (3)]).source;
;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 321 "mc.y"
    {
(yyval).start = (yyvsp[(1) - (3)]).start;
(yyval).stride = (yyvsp[(1) - (3)]).stride;
(yyval).stop = (yyvsp[(3) - (3)]).source;
;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 329 "mc.y"
    {(yyval).source = "null";;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 330 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 333 "mc.y"
    {(yyval).source = "null";;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 334 "mc.y"
    {(yyval).source = "new double[][][]{"+ (yyvsp[(1) - (1)]).source+"}";;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 337 "mc.y"
    {(yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 338 "mc.y"
    {(yyval).source = (yyvsp[(1) - (3)]).source + "," + (yyvsp[(3) - (3)]).source;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 341 "mc.y"
    { (yyval).source = (yyvsp[(2) - (3)]).source ;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 344 "mc.y"
    {(yyval).source = "new double[0][0]";;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 345 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 346 "mc.y"
    { (yyval).source = (yyvsp[(1) - (2)]).source;;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 347 "mc.y"
    { (yyval).source = "vertcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 349 "mc.y"
    { (yyval).source = "vertcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(3) - (3)]).source+")";}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 352 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source ;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 353 "mc.y"
    { (yyval).source = (yyvsp[(1) - (1)]).source ;;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 354 "mc.y"
    { (yyval).source = "horzcat("+(yyvsp[(1) - (2)]).source+","+(yyvsp[(2) - (2)]).source+")";;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 357 "mc.y"
    { (yyval).source = (yyvsp[(1) - (2)]).source ;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 358 "mc.y"
    { (yyval).source = "horzcat("+(yyvsp[(1) - (3)]).source+","+(yyvsp[(2) - (3)]).source+")";;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 361 "mc.y"
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

  case 97:

/* Line 1455 of yacc.c  */
#line 373 "mc.y"
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

  case 98:

/* Line 1455 of yacc.c  */
#line 385 "mc.y"
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

  case 99:

/* Line 1455 of yacc.c  */
#line 397 "mc.y"
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

  case 100:

/* Line 1455 of yacc.c  */
#line 409 "mc.y"
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

  case 101:

/* Line 1455 of yacc.c  */
#line 455 "mc.y"
    { (yyval).varg.push_back((yyvsp[(1) - (3)]).ri); (yyval).varg.push_back((yyvsp[(3) - (3)]).ri);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 456 "mc.y"
    { 
for(int i=0;i<(yyvsp[(1) - (3)]).varg.size();i++){
	(yyval).varg.push_back((yyvsp[(1) - (3)]).varg[i]);
}
(yyval).varg.push_back((yyvsp[(3) - (3)]).ri);
;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 464 "mc.y"
    { 
ref_info rinf;
rinf.id = (yyvsp[(1) - (1)]).source;
rinf.is_simple = true;
(yyval).ri = rinf	
;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 470 "mc.y"
    { 
ref_info rinf;
rinf.id = (yyvsp[(1) - (4)]).source;
rinf.is_simple = false;
rinf.ref_source = (yyvsp[(3) - (4)]).source;
(yyval).ri = rinf
;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 479 "mc.y"
    {
(yyval).source  = " double[][] fortemp =" + (yyvsp[(4) - (7)]).source +";\n";
(yyval).source += " for(int posdfo=0;posdfo<fortemp.length;posdfo++){ \n";
(yyval).source += " for(int sdfgsdfgdf=0;sdfgsdfgdf<fortemp[0].length;sdfgsdfgdf++){ \n";
(yyval).source += "double[][] "+ (yyvsp[(2) - (7)]).source + " = matrixFromDouble(fortemp[posdfo][sdfgsdfgdf]);\n";
(yyval).source += (yyvsp[(6) - (7)]).source;
(yyval).source += "}\n}\n";
;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 488 "mc.y"
    {(yyval).source =(yyvsp[(1) - (4)]).source+(yyvsp[(2) - (4)]).source+(yyvsp[(3) - (4)]).source;;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 491 "mc.y"
    {(yyval).source = "if(any("+(yyvsp[(2) - (4)]).source+")){"+(yyvsp[(4) - (4)]).source+"}";;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 494 "mc.y"
    {(yyval).source ="";;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 495 "mc.y"
    {(yyval).source = (yyvsp[(1) - (2)]).source + (yyvsp[(2) - (2)]).source;;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 498 "mc.y"
    {(yyval).source = "else if(any("+(yyvsp[(2) - (4)]).source+")){"+(yyvsp[(4) - (4)]).source+"}";;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 501 "mc.y"
    {(yyval).source ="";;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 502 "mc.y"
    {(yyval).source = "else{"+(yyvsp[(3) - (3)]).source+"}";;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 506 "mc.y"
    {(yyval).source = "while(any("+(yyvsp[(2) - (5)]).source+")){"+(yyvsp[(4) - (5)]).source+"}";;}
    break;



/* Line 1455 of yacc.c  */
#line 2553 "mc.tab.c"
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
#line 511 "mc.y"

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


int searchFunction(const string &id){
	int res =0;
	DIR * pdir;
	struct dirent *pdirent;

	string target = id+".m";

	pdir = opendir("./exemples/");

 	if(pdir == NULL){
		cerr << "Le rértoire courant n'a pu être ouvert!" << endl;	
	}

	while((pdirent = readdir(pdir)) != NULL){
		if(target.compare(pdirent->d_name)==0){
			res =1;	
			string path = "./exemples/" + target;
			to_compile.push_back(path);	
		}	
	}

	return res;
}


int main(int argc, const char ** argv){

symrec sri;
sri.idtype = FUNC;

TDSinsert("numel",sri);
 int externalfile=0;
 externalfile = argc>1;	
 FILE *fid;

 to_compile.push_back(argv[1]);



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


