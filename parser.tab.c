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

// Function declarations
void yyerror(const char* s);
int yylex(void);
extern int yylineno;
extern FILE *yyin;

// Helper function to convert type code to string
const char* type_to_string(int type) {
    switch(type) {
        case 1: return "int";
        case 2: return "char";
        case 3: return "void";
        case 4: return "float";
        default: return "unknown";
    }
}

// Symbol table structure
typedef struct {
    char* name;
    int type;
    int scope;
    int is_initialized;
    int is_used;
    int is_function;
    int is_parameter;
} Symbol;

#define MAX_SYMBOLS 1000
Symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

// Error tracking
int error_count = 0;
void report_error(const char* msg, int line, int col);

// Function to add symbol to table
void add_symbol(char* name, int type, int scope, int is_function) {
    if (symbol_count >= MAX_SYMBOLS) {
        report_error("Symbol table overflow", 0, 0);
        return;
    }
    symbol_table[symbol_count] = (Symbol){
        .name = strdup(name),
        .type = type,
        .scope = scope,
        .is_initialized = 0,
        .is_used = 0,
        .is_function = is_function,
        .is_parameter = 0
    };
    symbol_count++;
}

// Function to find symbol
Symbol* find_symbol(char* name, int scope) {
    for (int i = symbol_count - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].name, name) == 0 && 
            (symbol_table[i].scope == scope || symbol_table[i].scope < scope)) {
            return &symbol_table[i];
        }
    }
    return NULL;
}

// Function to check for unused variables (but not functions or parameters)
void check_unused_symbols() {
    for (int i = 0; i < symbol_count; i++) {
        if (!symbol_table[i].is_function && !symbol_table[i].is_parameter && !symbol_table[i].is_used) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "Unused variable '%s'", symbol_table[i].name);
            report_error(error_msg, yylineno, 0);
        }
    }
}


/* Line 189 of yacc.c  */
#line 155 "parser.tab.c"

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
     IDENTIFIER = 258,
     INTEGER_LITERAL = 259,
     FLOAT_LITERAL = 260,
     CHAR_LITERAL = 261,
     STRING_LITERAL = 262,
     INT = 263,
     CHAR = 264,
     VOID = 265,
     FLOAT_TYPE = 266,
     IF = 267,
     ELSE = 268,
     WHILE = 269,
     FOR = 270,
     RETURN = 271,
     STRUCT = 272,
     TYPEDEF = 273,
     CONST = 274,
     STATIC = 275,
     EXTERN = 276,
     SIZEOF = 277,
     PLUS = 278,
     MINUS = 279,
     MULTIPLY = 280,
     DIVIDE = 281,
     MODULO = 282,
     ASSIGN = 283,
     EQUAL = 284,
     NOT_EQUAL = 285,
     LESS = 286,
     LESS_EQUAL = 287,
     GREATER = 288,
     GREATER_EQUAL = 289,
     AND = 290,
     OR = 291,
     NOT = 292,
     BITWISE_AND = 293,
     BITWISE_OR = 294,
     BITWISE_XOR = 295,
     BITWISE_NOT = 296,
     LEFT_SHIFT = 297,
     RIGHT_SHIFT = 298,
     INCREMENT = 299,
     DECREMENT = 300,
     ARROW = 301,
     DOT = 302,
     SEMICOLON = 303,
     COMMA = 304,
     LEFT_PAREN = 305,
     RIGHT_PAREN = 306,
     LEFT_BRACE = 307,
     RIGHT_BRACE = 308,
     LEFT_BRACKET = 309,
     RIGHT_BRACKET = 310,
     COLON = 311,
     QUESTION = 312
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 83 "parser.y"

    int int_val;
    float float_val;
    char char_val;
    char* string_val;



/* Line 214 of yacc.c  */
#line 257 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 269 "parser.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    19,    21,    25,
      26,    29,    31,    33,    35,    37,    41,    42,    49,    54,
      56,    59,    60,    62,    65,    66,    68,    70,    72,    74,
      76,    79,    81,    87,    95,   101,   108,   116,   120,   123,
     125,   129,   131,   135,   137,   141,   143,   147,   149,   153,
     157,   159,   163,   167,   171,   175,   177,   181,   185,   187,
     191,   195,   199,   201,   204,   207,   210,   213,   215,   220,
     225,   229,   233,   236,   239,   241,   243,   245,   247,   249,
     253,   255,   259
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,    59,    60,    -1,    61,    -1,
      65,    -1,    64,     3,    50,    62,    51,    67,    -1,    63,
      -1,    62,    49,    63,    -1,    -1,    64,     3,    -1,     8,
      -1,     9,    -1,    10,    -1,    11,    -1,    64,     3,    48,
      -1,    -1,    64,     3,    66,    28,    75,    48,    -1,    52,
      68,    69,    53,    -1,    65,    -1,    68,    65,    -1,    -1,
      70,    -1,    69,    70,    -1,    -1,    71,    -1,    67,    -1,
      72,    -1,    73,    -1,    74,    -1,    75,    48,    -1,    48,
      -1,    12,    50,    75,    51,    70,    -1,    12,    50,    75,
      51,    70,    13,    70,    -1,    14,    50,    75,    51,    70,
      -1,    15,    50,    71,    71,    51,    70,    -1,    15,    50,
      71,    71,    75,    51,    70,    -1,    16,    75,    48,    -1,
      16,    48,    -1,    76,    -1,    75,    49,    76,    -1,    77,
      -1,     3,    28,    76,    -1,    78,    -1,    77,    36,    78,
      -1,    79,    -1,    78,    35,    79,    -1,    80,    -1,    79,
      29,    80,    -1,    79,    30,    80,    -1,    81,    -1,    80,
      31,    81,    -1,    80,    33,    81,    -1,    80,    32,    81,
      -1,    80,    34,    81,    -1,    82,    -1,    81,    23,    82,
      -1,    81,    24,    82,    -1,    83,    -1,    82,    25,    83,
      -1,    82,    26,    83,    -1,    82,    27,    83,    -1,    84,
      -1,    23,    83,    -1,    24,    83,    -1,    37,    83,    -1,
      41,    83,    -1,    85,    -1,    84,    54,    75,    55,    -1,
      84,    50,    86,    51,    -1,    84,    47,     3,    -1,    84,
      46,     3,    -1,    84,    44,    -1,    84,    45,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,    50,
      75,    51,    -1,    76,    -1,    86,    49,    76,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   146,   146,   147,   151,   152,   156,   170,   171,   172,
     176,   193,   194,   195,   196,   200,   211,   211,   237,   241,
     242,   243,   247,   248,   249,   253,   254,   255,   256,   257,
     261,   262,   266,   267,   271,   272,   273,   277,   278,   282,
     283,   287,   288,   311,   312,   316,   317,   321,   322,   323,
     327,   328,   329,   330,   331,   335,   336,   337,   341,   342,
     343,   344,   348,   349,   350,   351,   352,   356,   357,   358,
     359,   360,   361,   362,   366,   390,   391,   392,   393,   394,
     398,   399,   400
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER_LITERAL",
  "FLOAT_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", "INT", "CHAR", "VOID",
  "FLOAT_TYPE", "IF", "ELSE", "WHILE", "FOR", "RETURN", "STRUCT",
  "TYPEDEF", "CONST", "STATIC", "EXTERN", "SIZEOF", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "ASSIGN", "EQUAL", "NOT_EQUAL", "LESS",
  "LESS_EQUAL", "GREATER", "GREATER_EQUAL", "AND", "OR", "NOT",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT", "LEFT_SHIFT",
  "RIGHT_SHIFT", "INCREMENT", "DECREMENT", "ARROW", "DOT", "SEMICOLON",
  "COMMA", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACE", "RIGHT_BRACE",
  "LEFT_BRACKET", "RIGHT_BRACKET", "COLON", "QUESTION", "$accept",
  "program", "external_declaration", "function_definition",
  "parameter_list", "parameter_declaration", "type_specifier",
  "declaration", "$@1", "compound_statement", "declaration_list",
  "statement_list", "statement", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "expression", "assignment_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "primary_expression", "argument_expression_list", 0
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
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    62,    62,    62,
      63,    64,    64,    64,    64,    65,    66,    65,    67,    68,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    79,
      80,    80,    80,    80,    80,    81,    81,    81,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    84,    84,    84,
      84,    84,    84,    84,    85,    85,    85,    85,    85,    85,
      86,    86,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     6,     1,     3,     0,
       2,     1,     1,     1,     1,     3,     0,     6,     4,     1,
       2,     0,     1,     2,     0,     1,     1,     1,     1,     1,
       2,     1,     5,     7,     5,     6,     7,     3,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     2,     1,     4,     4,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     3,
       1,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,    12,    13,    14,     0,     2,     4,     0,     5,
       1,     3,    16,    15,     9,     0,     0,     7,     0,     0,
       0,     0,    10,    74,    75,    76,    77,    78,     0,     0,
       0,     0,     0,     0,    39,    41,    43,    45,    47,    50,
      55,    58,    62,    67,     8,    21,     6,     0,    74,    63,
      64,    65,    66,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,     0,     0,    82,     0,     0,    19,    24,    42,    79,
      40,    44,    46,    48,    49,    51,    53,    52,    54,    56,
      57,    59,    60,    61,    71,    70,    80,     0,     0,    16,
       0,     0,     0,     0,    31,    20,    26,     0,    22,    25,
      27,    28,    29,     0,     0,    69,    68,     0,     0,     0,
      38,     0,    18,    23,    30,    81,     0,     0,     0,    37,
       0,     0,     0,    32,    34,     0,     0,     0,    35,     0,
      33,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    16,    17,     8,     9,    15,   106,
      77,   107,   108,   109,   110,   111,   112,   113,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
     114,  -103,  -103,  -103,  -103,    35,  -103,  -103,     8,  -103,
    -103,  -103,    -1,  -103,   114,    -6,    10,  -103,    22,   178,
     114,   -20,  -103,    23,  -103,  -103,  -103,  -103,   206,   206,
     206,   206,   178,    -9,  -103,    52,     1,    37,   104,    73,
      75,  -103,   -16,  -103,  -103,   114,  -103,   178,  -103,  -103,
    -103,  -103,  -103,    13,  -103,   178,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,  -103,
    -103,    76,   102,   178,   178,   112,  -103,    66,  -103,  -103,
    -103,     1,    37,   104,   104,    73,    73,    73,    73,    75,
      75,  -103,  -103,  -103,  -103,  -103,  -103,    34,     5,    92,
      99,   106,   108,   156,  -103,  -103,  -103,     0,  -103,  -103,
    -103,  -103,  -103,    78,   178,  -103,  -103,   178,   178,   166,
    -103,    95,  -103,  -103,  -103,  -103,    43,    55,   166,  -103,
     105,   105,   127,   132,  -103,   105,    90,   105,  -103,   105,
    -103,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,   147,  -103,  -103,   134,   -12,   -35,  -103,   146,
    -103,  -103,   -44,  -102,  -103,  -103,  -103,   -19,   -46,  -103,
     118,   119,    89,   160,   101,   -10,  -103,  -103,  -103
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,    78,    18,    23,    24,    25,    26,    27,    18,    80,
      76,    12,   100,    53,   101,   102,   103,   128,    49,    50,
      51,    52,    19,    28,    29,    22,   132,    96,    69,    70,
      71,    72,    45,    75,    73,    10,    57,    30,    74,    54,
      55,    31,   105,     1,     2,     3,     4,    13,   104,    14,
      32,    47,    45,   122,    55,    98,    91,    92,    93,    20,
     116,    21,    55,   123,    79,    75,    58,    59,   125,    23,
      24,    25,    26,    27,     1,     2,     3,     4,   100,    94,
     101,   102,   103,   114,   121,   115,   133,   134,    56,    28,
      29,   138,    55,   140,   130,   141,    64,    65,   126,   127,
      66,    67,    68,    30,    55,    95,   131,    31,    23,    24,
      25,    26,    27,   136,   104,    99,    32,   100,    45,   101,
     102,   103,     1,     2,     3,     4,   124,    55,    28,    29,
      23,    24,    25,    26,    27,    60,    61,    62,    63,    55,
      13,   139,    30,   129,    55,   137,    31,    83,    84,   117,
      28,    29,    11,   104,    44,    32,   118,    45,   119,    23,
      24,    25,    26,    27,    30,    89,    90,    46,    31,    23,
      24,    25,    26,    27,    81,     0,    82,    32,   135,    28,
      29,    23,    24,    25,    26,    27,     0,     0,     0,    28,
      29,     0,     0,    30,     0,     0,     0,    31,     0,     0,
       0,    28,    29,    30,   120,     0,    32,    31,     0,    48,
      24,    25,    26,    27,   104,    30,    32,     0,     0,    31,
      85,    86,    87,    88,     0,     0,     0,     0,    32,    28,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    32
};

static const yytype_int16 yycheck[] =
{
      19,    47,    14,     3,     4,     5,     6,     7,    20,    55,
      45,     3,    12,    32,    14,    15,    16,   119,    28,    29,
      30,    31,    28,    23,    24,     3,   128,    73,    44,    45,
      46,    47,    52,    45,    50,     0,    35,    37,    54,    48,
      49,    41,    77,     8,     9,    10,    11,    48,    48,    50,
      50,    28,    52,    53,    49,    74,    66,    67,    68,    49,
      55,    51,    49,   107,    51,    77,    29,    30,   114,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     3,
      14,    15,    16,    49,   103,    51,   130,   131,    36,    23,
      24,   135,    49,   137,    51,   139,    23,    24,   117,   118,
      25,    26,    27,    37,    49,     3,    51,    41,     3,     4,
       5,     6,     7,   132,    48,     3,    50,    12,    52,    14,
      15,    16,     8,     9,    10,    11,    48,    49,    23,    24,
       3,     4,     5,     6,     7,    31,    32,    33,    34,    49,
      48,    51,    37,    48,    49,    13,    41,    58,    59,    50,
      23,    24,     5,    48,    20,    50,    50,    52,    50,     3,
       4,     5,     6,     7,    37,    64,    65,    21,    41,     3,
       4,     5,     6,     7,    56,    -1,    57,    50,    51,    23,
      24,     3,     4,     5,     6,     7,    -1,    -1,    -1,    23,
      24,    -1,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    23,    24,    37,    48,    -1,    50,    41,    -1,     3,
       4,     5,     6,     7,    48,    37,    50,    -1,    -1,    41,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    50,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    59,    60,    61,    64,    65,
       0,    60,     3,    48,    50,    66,    62,    63,    64,    28,
      49,    51,     3,     3,     4,     5,     6,     7,    23,    24,
      37,    41,    50,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    63,    52,    67,    28,     3,    83,
      83,    83,    83,    75,    48,    49,    36,    35,    29,    30,
      31,    32,    33,    34,    23,    24,    25,    26,    27,    44,
      45,    46,    47,    50,    54,    64,    65,    68,    76,    51,
      76,    78,    79,    80,    80,    81,    81,    81,    81,    82,
      82,    83,    83,    83,     3,     3,    76,    86,    75,     3,
      12,    14,    15,    16,    48,    65,    67,    69,    70,    71,
      72,    73,    74,    75,    49,    51,    55,    50,    50,    50,
      48,    75,    53,    70,    48,    76,    75,    75,    71,    48,
      51,    51,    71,    70,    70,    51,    75,    13,    70,    51,
      70,    70
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
#line 146 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 147 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (2)].int_val); ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 151 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 152 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 157 "parser.y"
    {
        // Check for function redefinition
        Symbol* sym = find_symbol((yyvsp[(2) - (6)].string_val), 0);
        if (sym != NULL) {
            report_error("Function redefinition", yylineno, 0);
        } else {
            add_symbol((yyvsp[(2) - (6)].string_val), (yyvsp[(1) - (6)].int_val), 0, 1);  // Mark as function
        }
        (yyval.int_val) = (yyvsp[(1) - (6)].int_val);
    ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 170 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 171 "parser.y"
    { (yyval.int_val) = (yyvsp[(3) - (3)].int_val); ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 172 "parser.y"
    { (yyval.int_val) = 0; ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 177 "parser.y"
    {
        // Add parameter to symbol table and mark it as initialized
        Symbol* sym = find_symbol((yyvsp[(2) - (2)].string_val), 1);
        if (sym != NULL) {
            report_error("Parameter redefinition", yylineno, 0);
        } else {
            add_symbol((yyvsp[(2) - (2)].string_val), (yyvsp[(1) - (2)].int_val), 1, 0);  // Add parameter to symbol table
            symbol_table[symbol_count-1].is_initialized = 1;  // Mark as initialized
            symbol_table[symbol_count-1].is_parameter = 1;    // Mark as parameter
            symbol_table[symbol_count-1].is_used = 1;         // Mark as used
        }
        (yyval.int_val) = (yyvsp[(1) - (2)].int_val);
    ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 193 "parser.y"
    { (yyval.int_val) = 1; ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 194 "parser.y"
    { (yyval.int_val) = 2; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 195 "parser.y"
    { (yyval.int_val) = 3; ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 196 "parser.y"
    { (yyval.int_val) = 4; ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 201 "parser.y"
    {
        // Check for variable redefinition
        Symbol* sym = find_symbol((yyvsp[(2) - (3)].string_val), 0);
        if (sym != NULL) {
            report_error("Variable redefinition", yylineno, 0);
        } else {
            add_symbol((yyvsp[(2) - (3)].string_val), (yyvsp[(1) - (3)].int_val), 0, 0);  // Mark as variable
        }
        (yyval.int_val) = (yyvsp[(1) - (3)].int_val);
    ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 211 "parser.y"
    { 
        // Add variable to symbol table before parsing the assignment expression
        Symbol* sym = find_symbol((yyvsp[(2) - (2)].string_val), 0);
        if (sym != NULL) {
            report_error("Variable redefinition", yylineno, 0);
        } else {
            add_symbol((yyvsp[(2) - (2)].string_val), (yyvsp[(1) - (2)].int_val), 0, 0);
        }
    ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 220 "parser.y"
    {
        // Now check type compatibility and mark as initialized/used
        Symbol* sym = find_symbol((yyvsp[(2) - (6)].string_val), 0);
        if (sym) {
            if (sym->type != (yyvsp[(5) - (6)].int_val)) {
                char error_msg[256];
                snprintf(error_msg, sizeof(error_msg), "Type mismatch in assignment: expected %s, got %s", type_to_string(sym->type), type_to_string((yyvsp[(5) - (6)].int_val)));
                report_error(error_msg, yylineno, 0);
            }
            sym->is_initialized = 1;
            sym->is_used = 1;
        }
        (yyval.int_val) = (yyvsp[(1) - (6)].int_val);
    ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 237 "parser.y"
    { (yyval.int_val) = 0; ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 241 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 242 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (2)].int_val); ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 243 "parser.y"
    { (yyval.int_val) = 0; ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 247 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 248 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (2)].int_val); ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 249 "parser.y"
    { (yyval.int_val) = 0; ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 253 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 254 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 255 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 256 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 257 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 261 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (2)].int_val); ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 262 "parser.y"
    { (yyval.int_val) = 0; ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 266 "parser.y"
    { (yyval.int_val) = (yyvsp[(3) - (5)].int_val); ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 267 "parser.y"
    { (yyval.int_val) = (yyvsp[(3) - (7)].int_val); ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 271 "parser.y"
    { (yyval.int_val) = (yyvsp[(3) - (5)].int_val); ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 272 "parser.y"
    { (yyval.int_val) = 0; ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 273 "parser.y"
    { (yyval.int_val) = (yyvsp[(5) - (7)].int_val); ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 277 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (3)].int_val); ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 278 "parser.y"
    { (yyval.int_val) = 0; ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 282 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 283 "parser.y"
    { (yyval.int_val) = (yyvsp[(3) - (3)].int_val); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 287 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 289 "parser.y"
    {
        // Check if variable is declared and initialized
        Symbol* sym = find_symbol((yyvsp[(1) - (3)].string_val), 0);
        if (sym == NULL) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "Undefined variable '%s'", (yyvsp[(1) - (3)].string_val));
            report_error(error_msg, yylineno, 0);
        } else {
            // Type check
            if (sym->type != (yyvsp[(3) - (3)].int_val)) {
                char error_msg[256];
                snprintf(error_msg, sizeof(error_msg), "Type mismatch in assignment: expected %s, got %s", type_to_string(sym->type), type_to_string((yyvsp[(3) - (3)].int_val)));
                report_error(error_msg, yylineno, 0);
            }
            sym->is_initialized = 1;
            sym->is_used = 1; // Mark as used
        }
        (yyval.int_val) = (yyvsp[(3) - (3)].int_val);
    ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 311 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 312 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 316 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 317 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 321 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 322 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 323 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 327 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 328 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 329 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 330 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 331 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 335 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 336 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 337 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 341 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 342 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 343 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 344 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 348 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 349 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (2)].int_val); ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 350 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (2)].int_val); ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 351 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (2)].int_val); ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 352 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (2)].int_val); ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 356 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 357 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (4)].int_val); ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 358 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (4)].int_val); ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 359 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 360 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (3)].int_val); ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 361 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (2)].int_val); ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 362 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (2)].int_val); ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 367 "parser.y"
    {
        // Check if variable is declared
        Symbol* sym = find_symbol((yyvsp[(1) - (1)].string_val), 1);  // First check in current scope (1)
        if (sym == NULL) {
            sym = find_symbol((yyvsp[(1) - (1)].string_val), 0);      // Then check in global scope (0)
        }
        if (sym == NULL) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "Undefined variable '%s'", (yyvsp[(1) - (1)].string_val));
            report_error(error_msg, yylineno, 0);
        } else {
            // Only check initialization and usage for non-function and non-parameter symbols
            if (!sym->is_function && !sym->is_parameter) {
                sym->is_used = 1;
                if (!sym->is_initialized) {
                    char error_msg[256];
                    snprintf(error_msg, sizeof(error_msg), "Uninitialized variable '%s'", (yyvsp[(1) - (1)].string_val));
                    report_error(error_msg, yylineno, 0);
                }
            }
        }
        (yyval.int_val) = sym ? sym->type : 0;
    ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 390 "parser.y"
    { (yyval.int_val) = 1; ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 391 "parser.y"
    { (yyval.int_val) = 4; ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 392 "parser.y"
    { (yyval.int_val) = 2; ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 393 "parser.y"
    { (yyval.int_val) = 2; ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 394 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (3)].int_val); ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 398 "parser.y"
    { (yyval.int_val) = (yyvsp[(1) - (1)].int_val); ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 399 "parser.y"
    { (yyval.int_val) = (yyvsp[(3) - (3)].int_val); ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 400 "parser.y"
    { (yyval.int_val) = 0; ;}
    break;



/* Line 1464 of yacc.c  */
#line 2294 "parser.tab.c"
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
#line 403 "parser.y"


void report_error(const char* msg, int line, int col) {
    (void)col;  // Explicitly acknowledge unused parameter
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
    error_count++;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    error_count++;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    
    yyparse();
    
    // Report unused variables
    check_unused_symbols();
    
    return error_count;
} 

