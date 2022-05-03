/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "parser.y" /* yacc.c:339  */

   #include <stdio.h>
   #include <iostream>
   #include <vector>
   #include <string>
   using namespace std; 

   extern int yylex();
   extern int yylineno;
   extern char *yytext;
   void yyerror (const char *msg) {
     printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
   }

   #include "Codigo.hpp"
   #include "Exp.hpp"

   expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) ;
   expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) ;
   vector<int> *unir(vector<int> lis1, vector<int> lis2);
   vector<string> *unir2(vector<string> lis1, vector<string> lis2);
   sentenciastruct makecontinue();
   Codigo codigo;



#line 93 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    RPROGRAM = 258,
    RBEGIN = 259,
    RENDPROGRAM = 260,
    RDEF = 261,
    RMAIN = 262,
    RLET = 263,
    RIN = 264,
    RIF = 265,
    RELSE = 266,
    RWHILE = 267,
    RBREAK = 268,
    RFOREVER = 269,
    RCONTINUE = 270,
    RPRINTLN = 271,
    RREAD = 272,
    RINT = 273,
    RFLOAT = 274,
    RELSEIF = 275,
    RSWITCH = 276,
    RCASE = 277,
    RDEFAULT = 278,
    RFOR = 279,
    TABRIRLLAVE = 280,
    TCERRARLLAVE = 281,
    TABRIRPAREN = 282,
    TCERRARPAREN = 283,
    TEQ = 284,
    TDOSPT = 285,
    TSEMIC = 286,
    TAMP = 287,
    TCOMA = 288,
    TPTPT = 289,
    OMULT = 290,
    OSUM = 291,
    OREST = 292,
    ODIV = 293,
    CEQ = 294,
    CLT = 295,
    CGT = 296,
    CLE = 297,
    CGE = 298,
    CNE = 299,
    OOR = 300,
    ONOT = 301,
    OAND = 302,
    TIDENTIFIER = 303,
    TDOUBLE = 304,
    TINTEGER = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "parser.y" /* yacc.c:355  */

    string *str ;
    vector<string> *list ;
    expresionstruct *expr ;
    sentenciastruct *sent ;
    int number ;
    vector<int> *numlist;
    casestruct *cses;

#line 194 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 211 "parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    85,    92,    98,   106,   107,   110,   114,
     119,   123,   124,   128,   129,   132,   133,   136,   136,   140,
     141,   144,   144,   151,   152,   154,   155,   155,   162,   163,
     170,   177,   187,   186,   207,   218,   223,   230,   236,   242,
     250,   263,   263,   316,   324,   326,   329,   334,   337,   334,
     352,   354,   360,   363,   360,   380,   393,   399,   409,   412,
     418,   424,   430,   436,   442,   448,   457,   466,   474,   480,
     486,   492,   498,   499,   500,   501,   504,   507
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RPROGRAM", "RBEGIN", "RENDPROGRAM",
  "RDEF", "RMAIN", "RLET", "RIN", "RIF", "RELSE", "RWHILE", "RBREAK",
  "RFOREVER", "RCONTINUE", "RPRINTLN", "RREAD", "RINT", "RFLOAT",
  "RELSEIF", "RSWITCH", "RCASE", "RDEFAULT", "RFOR", "TABRIRLLAVE",
  "TCERRARLLAVE", "TABRIRPAREN", "TCERRARPAREN", "TEQ", "TDOSPT", "TSEMIC",
  "TAMP", "TCOMA", "TPTPT", "OMULT", "OSUM", "OREST", "ODIV", "CEQ", "CLT",
  "CGT", "CLE", "CGE", "CNE", "OOR", "ONOT", "OAND", "TIDENTIFIER",
  "TDOUBLE", "TINTEGER", "$accept", "programa", "$@1", "bloque_ppl",
  "bloque", "decl_bl", "declaraciones", "lista_de_ident", "resto_lista_id",
  "tipo", "decl_de_subprogs", "decl_de_subprograma", "$@2", "argumentos",
  "lista_de_param", "$@3", "clase_par", "resto_lis_de_param", "$@4",
  "lista_de_sentencias", "sentencia", "$@5", "$@6", "cte", "cases", "$@7",
  "$@8", "r_cases", "$@9", "$@10", "parte_else", "variable", "expresion",
  "M", "N", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-78)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    20,    50,   -90,   -90,    27,    28,    31,    54,    15,
     -90,    39,    32,    -1,    36,    62,    22,   -90,   -90,    15,
      -7,    23,    97,    62,    32,    42,   -90,   -90,   -90,   -90,
     -13,   -90,    -6,    46,    48,    53,    58,   -13,    29,   -90,
      55,    97,    59,   -90,   -90,    -7,    60,   -13,   -13,   -90,
     -90,   -90,   162,   -13,   -13,   -90,   -90,   -90,   -13,    29,
     178,    82,   -90,   -90,   -13,   -90,    15,    63,   128,   308,
     -90,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,   -90,   -90,   194,   282,    67,   146,    66,    71,   -13,
     241,    68,    69,    54,   -90,    67,   -90,   -28,   -28,   -90,
     318,   318,   318,   318,   318,   318,   -13,   -13,   -90,    72,
      97,   -90,    73,    74,    -3,   255,   -90,    76,   -90,   -90,
      -2,   295,   308,    67,   -90,    80,   -90,   -90,   -90,   -26,
      85,   -90,   -13,   -90,    -7,   -90,   -90,   -90,   -90,   -90,
     -90,    86,    97,   100,   269,   -90,    40,   -90,   -90,    98,
     -90,   -13,   101,   104,   -13,   -90,    88,   -90,   -90,   210,
      15,   -90,    67,   226,   -90,   106,    97,   -90,   107,   -90,
     -90,    67,   -90,   -90,    76,    67,   -90,   -90,    67,    -7,
      -2,   -90,   108,   -90,   -90,   -90,   -90,    30,   -90,   101,
      40,   -26,   110,   -90,   -90,   -90,   111,   -90,   -90,   -90,
      97,   -90,   116,    97,   -90,   -90,   -90,   117,    30,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     0,     0,     6,     0,
       3,     0,    11,     0,     0,    15,     0,    10,     7,     0,
       0,     0,    28,    15,    11,     0,    13,    14,     9,    17,
       0,    76,     0,     0,     0,     0,     0,     0,     0,    58,
       0,    28,     0,    16,    12,     0,    19,     0,     0,    72,
      74,    73,     0,     0,     0,    35,    76,    37,     0,     0,
       0,     0,     4,    29,     0,     8,     0,     0,     0,    67,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    76,     0,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     6,    75,     0,    70,    68,    69,    71,
      59,    61,    60,    63,    62,    64,     0,     0,    76,     0,
      28,    76,     0,     0,     0,     0,    30,    23,    20,    18,
      76,    65,    66,     0,    36,     0,    34,    39,    38,     0,
       0,    76,     0,    24,     0,    31,    76,    76,     5,    45,
      44,     0,    28,     0,     0,    21,     0,    32,    76,     0,
      43,     0,    25,     0,     0,    76,     0,    47,    46,     0,
       0,    22,     0,     0,    40,     0,    28,    41,     0,    56,
      76,     0,    48,    76,    23,     0,    76,    76,     0,     0,
      76,    33,     0,    76,    26,    57,    76,    50,    42,    25,
       0,     0,     0,    49,    27,    76,     0,    76,    55,    76,
      28,    52,     0,    28,    51,    53,    76,     0,    50,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,    35,   -89,   -90,   -90,   -17,   114,   -44,
     126,   -90,   -90,   -90,   -90,   -90,   -43,   -39,   -90,   -41,
     -90,   -90,   -90,   -40,   -90,   -90,   -90,   -56,   -90,   -90,
     -36,     0,   -32,   -53,   -25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    10,   111,    11,    13,    14,    17,    28,
      22,    23,    46,    67,    92,   152,   134,   161,   189,    40,
      41,   156,   173,   141,   131,   166,   177,   193,   203,   206,
     155,    42,    52,    53,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    65,    25,    85,    54,    60,   120,    71,    18,   -77,
      74,    26,    27,     1,    47,    68,    69,    95,   -77,   129,
     130,    83,    84,   139,   140,    55,    86,     3,   106,   107,
      19,   109,    90,    48,   137,    49,    50,    51,    61,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    91,
       4,   153,   191,   192,     6,   123,     7,   115,   126,    87,
     154,     8,     9,    12,    15,    16,    20,   135,    21,   125,
      24,    29,    45,   169,   121,   122,    56,    39,   143,    57,
      58,    62,   176,   146,   147,    59,   180,    66,    64,   183,
     145,    89,   110,    93,   113,   157,   114,   118,   117,   165,
     144,   149,   164,   124,   127,   128,   138,    30,   133,    31,
      32,    33,    34,    35,    36,   142,   148,   175,    37,   159,
     178,    38,   163,   181,   182,   172,   150,   185,   119,   158,
     188,   179,   160,   190,   162,   184,   171,   174,    44,   187,
     197,   199,   198,   168,   200,    39,   201,   204,   208,    43,
     194,   196,   209,   207,   195,   186,    94,     0,     0,   202,
       0,     0,   205,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   112,    82,     0,     0,     0,     0,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    70,    82,     0,     0,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    88,    82,
       0,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   108,    82,     0,     0,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
     167,    82,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   170,    82,     0,     0,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   116,    82,     0,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     0,    82,   132,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,    82,   151,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,    82,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,    82,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,     0,    82,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    71,    72,    73,    74,   -78,   -78,   -78,
     -78,   -78,   -78
};

static const yytype_int16 yycheck[] =
{
      41,    45,    19,    56,    10,    37,    95,    35,     9,    11,
      38,    18,    19,     6,    27,    47,    48,    70,    20,    22,
      23,    53,    54,    49,    50,    31,    58,     7,    81,    82,
      31,    84,    64,    46,   123,    48,    49,    50,    38,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    66,
       0,    11,    22,    23,    27,   108,    28,    89,   111,    59,
      20,    30,     8,    48,    25,    33,    30,   120,     6,   110,
      48,    48,    30,   162,   106,   107,    30,    48,   131,    31,
      27,    26,   171,   136,   137,    27,   175,    27,    29,   178,
     134,     9,    25,    30,    28,   148,    25,    28,    30,    11,
     132,   142,   155,    31,    31,    31,    26,    10,    32,    12,
      13,    14,    15,    16,    17,    30,    30,   170,    21,   151,
     173,    24,   154,   176,   177,   166,    26,   180,    93,    31,
     183,   174,    31,   186,    30,   179,    30,    30,    24,    31,
      30,    30,   195,   160,   197,    48,   199,    31,    31,    23,
     189,   191,   208,   206,   190,   180,    28,    -1,    -1,   200,
      -1,    -1,   203,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    28,    47,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    30,    47,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    30,    47,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    30,    47,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      30,    47,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    30,    47,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    31,    47,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    47,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    47,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    47,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    52,     7,     0,    53,    27,    28,    30,     8,
      54,    56,    48,    57,    58,    25,    33,    59,     9,    31,
      30,     6,    61,    62,    48,    58,    18,    19,    60,    48,
      10,    12,    13,    14,    15,    16,    17,    21,    24,    48,
      70,    71,    82,    61,    59,    30,    63,    27,    46,    48,
      49,    50,    83,    84,    10,    31,    30,    31,    27,    27,
      83,    82,    26,    70,    29,    60,    27,    64,    83,    83,
      30,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    47,    83,    83,    84,    83,    82,    30,     9,
      83,    58,    65,    30,    28,    84,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    30,    84,
      25,    55,    28,    28,    25,    83,    31,    30,    28,    54,
      55,    83,    83,    84,    31,    70,    84,    31,    31,    22,
      23,    75,    34,    32,    67,    84,    85,    55,    26,    49,
      50,    74,    30,    84,    83,    60,    84,    84,    30,    70,
      26,    34,    66,    11,    20,    81,    72,    84,    31,    83,
      31,    68,    30,    83,    84,    11,    76,    30,    58,    55,
      30,    30,    70,    73,    30,    84,    55,    77,    84,    67,
      55,    84,    84,    55,    60,    84,    85,    31,    84,    69,
      84,    22,    23,    78,    68,    81,    74,    30,    84,    30,
      84,    84,    70,    79,    31,    70,    80,    84,    31,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    53,    52,    54,    55,    56,    56,    57,    57,
      58,    59,    59,    60,    60,    61,    61,    63,    62,    64,
      64,    66,    65,    67,    67,    68,    69,    68,    70,    70,
      71,    71,    72,    71,    71,    71,    71,    71,    71,    71,
      71,    73,    71,    71,    74,    74,    75,    76,    77,    75,
      78,    78,    79,    80,    78,    81,    81,    81,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     5,     3,     0,     3,     5,     3,
       2,     0,     3,     1,     1,     0,     2,     0,     6,     0,
       3,     0,     6,     0,     1,     0,     0,     7,     0,     2,
       4,     6,     0,    12,     5,     2,     5,     2,     5,     5,
       9,     0,    13,     7,     1,     1,     4,     0,     0,    10,
       0,     5,     0,     0,    10,     9,     3,     6,     1,     3,
       3,     3,     3,     3,     3,     4,     4,     2,     3,     3,
       3,     3,     1,     1,     1,     3,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 85 "parser.y" /* yacc.c:1646  */
    { codigo.anadirInstruccion("proc main;"); }
#line 1457 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "parser.y" /* yacc.c:1646  */
    { codigo.anadirInstruccion("halt;" ) ;
             codigo.escribir();}
#line 1464 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 101 "parser.y" /* yacc.c:1646  */
    {
                (yyval.sent) = (yyvsp[-1].sent);
        }
#line 1472 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "parser.y" /* yacc.c:1646  */
    { codigo.anadirDeclaraciones(*(yyvsp[-2].list),*(yyvsp[0].str));
  delete (yyvsp[-2].list);
  delete (yyvsp[0].str);}
#line 1480 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "parser.y" /* yacc.c:1646  */
    { codigo.anadirDeclaraciones(*(yyvsp[-2].list),*(yyvsp[0].str));
                                       delete (yyvsp[-2].list);
                                       delete (yyvsp[0].str);}
#line 1488 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval.list) = (yyvsp[0].list);
                                             (yyval.list)->insert((yyval.list)->begin(),*(yyvsp[-1].str));}
#line 1495 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval.list) = new vector<string>;}
#line 1501 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.list) = (yyvsp[0].list);
                                            (yyval.list)->insert((yyval.list)->begin(),*(yyvsp[-1].str));}
#line 1508 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 128 "parser.y" /* yacc.c:1646  */
    {*(yyval.str) = "int";}
#line 1514 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 129 "parser.y" /* yacc.c:1646  */
    {*(yyval.str) = "real";}
#line 1520 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 136 "parser.y" /* yacc.c:1646  */
    { codigo.anadirInstruccion("proc " + *(yyvsp[0].str) + ";"); }
#line 1526 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 137 "parser.y" /* yacc.c:1646  */
    { codigo.anadirInstruccion("endproc " + *(yyvsp[-4].str) + ";"); }
#line 1532 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 144 "parser.y" /* yacc.c:1646  */
    {codigo.anadirParametros(*(yyvsp[-3].list),*(yyvsp[-1].str),*(yyvsp[0].str));
                                                       delete (yyvsp[-3].list);
                                                       delete (yyvsp[-1].str);
                                                       delete (yyvsp[0].str);}
#line 1541 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 151 "parser.y" /* yacc.c:1646  */
    {*(yyval.str) = "val";}
#line 1547 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "parser.y" /* yacc.c:1646  */
    {*(yyval.str) = "ref";}
#line 1553 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 155 "parser.y" /* yacc.c:1646  */
    {codigo.anadirParametros(*(yyvsp[-3].list),*(yyvsp[-1].str),*(yyvsp[0].str));
                                                       delete (yyvsp[-3].list);
                                                       delete (yyvsp[-1].str);
                                                       delete (yyvsp[0].str);}
#line 1562 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.sent) = new sentenciastruct;}
#line 1568 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval.sent) = new sentenciastruct;
                                        (yyval.sent)->exit = *unir((yyvsp[-1].sent)->exit,(yyvsp[0].sent)->exit);
                                        (yyval.sent)->conti = *unir((yyvsp[-1].sent)->conti,(yyvsp[0].sent)->conti);
                                        delete (yyvsp[-1].sent);
                                        delete (yyvsp[0].sent);}
#line 1578 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 171 "parser.y" /* yacc.c:1646  */
    {
        (yyval.sent) = new sentenciastruct; 
        codigo.anadirInstruccion(*(yyvsp[-3].str) + " := " + (yyvsp[-1].expr)->str + ";"); 
	delete (yyvsp[-1].expr);
        }
#line 1588 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 178 "parser.y" /* yacc.c:1646  */
    {
        (yyval.sent) = new sentenciastruct;
	(yyval.sent) = (yyvsp[-1].sent);
        codigo.completarInstrucciones((yyvsp[-4].expr)->trues,(yyvsp[-2].number));
        codigo.completarInstrucciones((yyvsp[-4].expr)->falses,(yyvsp[0].number));
	delete (yyvsp[-4].expr);
        }
#line 1600 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 187 "parser.y" /* yacc.c:1646  */
    {
        codigo.anadirInstruccion("goto");
        vector<int> *tmp1 = new vector<int>; 
	tmp1->push_back((yyvsp[0].number)) ;
    	codigo.completarInstrucciones(*tmp1, (yyvsp[-5].number)) ;
        }
#line 1611 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 194 "parser.y" /* yacc.c:1646  */
    {
        (yyval.sent) = new sentenciastruct;
        codigo.completarInstrucciones((yyvsp[-9].expr)->trues,(yyvsp[-7].number));
        codigo.completarInstrucciones((yyvsp[-9].expr)->falses,(yyvsp[-5].number) + 1);
        codigo.completarInstrucciones((yyvsp[-6].sent)->exit,(yyvsp[-5].number) + 1);
        codigo.completarInstrucciones((yyvsp[-6].sent)->conti,(yyvsp[-10].number));
        codigo.completarInstrucciones((yyvsp[-1].sent)->exit,(yyvsp[0].number));                  
        codigo.completarInstrucciones((yyvsp[-1].sent)->conti,(yyvsp[-10].number));
	delete (yyvsp[-9].expr);
	delete (yyvsp[-6].sent);
	delete (yyvsp[-1].sent);
        }
#line 1628 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 208 "parser.y" /* yacc.c:1646  */
    {
        (yyval.sent) = new sentenciastruct;
        codigo.anadirInstruccion("goto");
        vector<int> *tmp1 = new vector<int>; 
	tmp1->push_back((yyvsp[0].number)) ;
    	codigo.completarInstrucciones(*tmp1, (yyvsp[-2].number)) ;
        codigo.completarInstrucciones((yyvsp[-1].sent)->exit, (yyvsp[0].number) + 1);
        (yyval.sent)->conti = (yyvsp[-1].sent)->conti;
        }
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.sent) = new sentenciastruct;
	(yyval.sent)->exit.push_back(codigo.obtenRef());
	codigo.anadirInstruccion("goto");
	}
#line 1651 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 224 "parser.y" /* yacc.c:1646  */
    {
        (yyval.sent) = new sentenciastruct;
        codigo.completarInstrucciones((yyvsp[-2].expr)->falses, (yyvsp[-1].number));
        (yyval.sent)->exit = (yyvsp[-2].expr)->trues;
        }
#line 1661 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 231 "parser.y" /* yacc.c:1646  */
    {
        (yyval.sent) = new sentenciastruct;
	*(yyval.sent) = makecontinue();
        }
#line 1670 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 237 "parser.y" /* yacc.c:1646  */
    {
        (yyval.sent) = new sentenciastruct;
        codigo.anadirInstruccion("read " + *(yyvsp[-2].str) + ";");
        }
#line 1679 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 243 "parser.y" /* yacc.c:1646  */
    {
        (yyval.sent) = new sentenciastruct;
        codigo.anadirInstruccion( "write " + (yyvsp[-2].expr)->str + ";");
        codigo.anadirInstruccion( "writeln;");
	delete (yyvsp[-2].expr);
        }
#line 1690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 250 "parser.y" /* yacc.c:1646  */
    {
	(yyval.sent) = new sentenciastruct;
	(yyval.sent)->exit = *unir((yyvsp[-4].sent)->exit, (yyvsp[-1].sent)->exit);
	(yyval.sent)->conti = *unir((yyvsp[-4].sent)->conti, (yyvsp[-1].sent)->conti);
	codigo.completarInstrucciones(*(yyvsp[-3].numlist), (yyvsp[0].number));
	codigo.completarInstrucciones((yyvsp[-7].expr)->falses, (yyvsp[-2].number));
	codigo.completarInstrucciones((yyvsp[-7].expr)->trues, (yyvsp[-5].number));
	delete (yyvsp[-3].numlist);
	delete (yyvsp[-7].expr);
	delete (yyvsp[-4].sent);
	delete (yyvsp[-1].sent);
	}
#line 1707 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 263 "parser.y" /* yacc.c:1646  */
    {
	codigo.anadirInstruccion("int "+ *(yyvsp[-7].str) +";");
	codigo.anadirInstruccion(*(yyvsp[-7].str) +" := "+ (yyvsp[-5].expr)->str +";");

	stringstream refer;
	refer << "" << codigo.obtenRef() + 2;
	codigo.anadirInstruccion("if "+ (yyvsp[-1].expr)->str +" > 0 goto " + refer.str()+";");

	stringstream refer1;
	refer1 << "" << codigo.obtenRef() + 5;
	codigo.anadirInstruccion("goto " + refer1.str()+";");
	
	stringstream refer2;
	refer2 << "" << codigo.obtenRef() + 2;
	codigo.anadirInstruccion("if "+ *(yyvsp[-7].str) +" >= "+ (yyvsp[-5].expr)->str +" goto " + refer2.str()+";");
	codigo.anadirInstruccion("goto");

	stringstream refer3;
	refer3 << "" << codigo.obtenRef() + 6;
	codigo.anadirInstruccion("if "+ *(yyvsp[-7].str) +" <= "+ (yyvsp[-3].expr)->str +" goto " + refer3.str()+";");
	codigo.anadirInstruccion("goto");

	stringstream refer4;
	refer4 << "" << codigo.obtenRef() + 2;
	codigo.anadirInstruccion("if "+ *(yyvsp[-7].str) +" >= "+ (yyvsp[-3].expr)->str +" goto " + refer4.str()+";");
	codigo.anadirInstruccion("goto");

	stringstream refer5;
	refer5 << "" << codigo.obtenRef() + 2;
	codigo.anadirInstruccion("if "+ *(yyvsp[-7].str) +" <= "+ (yyvsp[-5].expr)->str +" goto " + refer5.str()+";");
	codigo.anadirInstruccion("goto");
	}
#line 1744 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 294 "parser.y" /* yacc.c:1646  */
    {
	(yyval.sent) = new sentenciastruct;

	stringstream eme;
	eme << "" << (yyvsp[-2].number) -11;
	codigo.anadirInstruccion(*(yyvsp[-11].str) +" := "+ *(yyvsp[-11].str) +" + " + (yyvsp[-5].expr)->str +";");
	codigo.anadirInstruccion("goto "+ eme.str() +";");
	codigo.completarInstrucciones((yyvsp[-1].sent)->conti, (yyvsp[0].number));
	codigo.completarInstrucciones((yyvsp[-1].sent)->exit, (yyvsp[0].number) + 2);
	vector<int> tmp;
	tmp.push_back((yyvsp[-2].number) -1);
	tmp.push_back((yyvsp[-2].number) -3);
	tmp.push_back((yyvsp[-2].number) -5);
	tmp.push_back((yyvsp[-2].number) -7);
	codigo.completarInstrucciones(tmp, (yyvsp[0].number) + 2);
	delete (yyvsp[-1].sent);
	delete (yyvsp[-11].str);
	delete (yyvsp[-9].expr);
	delete (yyvsp[-7].expr);
	delete (yyvsp[-5].expr);
	}
#line 1770 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 316 "parser.y" /* yacc.c:1646  */
    { (yyval.sent) = new sentenciastruct;
	codigo.completarInstrucciones((yyvsp[-2].cses)->exit, (yyvsp[-1].number));
	(yyval.sent)->conti = (yyvsp[-2].cses)->conti;
	codigo.completarSwitch((yyvsp[-2].cses)->gotos, (yyvsp[-5].expr)->str);
	}
#line 1780 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 324 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1786 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 326 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1792 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 329 "parser.y" /* yacc.c:1646  */
    { (yyval.cses) = new casestruct;
	(yyval.cses)->exit = (yyvsp[-1].sent)->exit;
	(yyval.cses)->conti = (yyvsp[-1].sent)->conti;
	}
#line 1801 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 334 "parser.y" /* yacc.c:1646  */
    {
	codigo.anadirInstruccion("if "+ *(yyvsp[-2].str) +" == ");
	codigo.anadirInstruccion("goto");
	}
#line 1810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 337 "parser.y" /* yacc.c:1646  */
    {
	codigo.anadirInstruccion("goto");
	}
#line 1818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 339 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cses) = new casestruct;
	(yyval.cses)->gotos = (yyvsp[0].cses)->gotos;
	(yyval.cses)->gotos.push_back((yyvsp[-6].number));
	vector<int> tmp; tmp.push_back((yyvsp[-6].number) + 1);
	codigo.completarInstrucciones(tmp, (yyvsp[-2].number));
	(yyval.cses)->exit = *unir((yyvsp[-4].sent)->exit, (yyvsp[0].cses)->exit);
	vector<int> tmp1; tmp1.push_back((yyvsp[-2].number) - 1);
	codigo.completarInstrucciones(tmp1, (yyvsp[0].cses)->ini);
	(yyval.cses)->conti = *unir((yyvsp[-4].sent)->conti, (yyvsp[0].cses)->conti);
	}
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 352 "parser.y" /* yacc.c:1646  */
    { (yyval.cses) = new casestruct; (yyval.cses)->ini = codigo.obtenRef();}
#line 1840 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval.cses) = new casestruct;
	(yyval.cses)->exit = (yyvsp[-1].sent)->exit;
	(yyval.cses)->conti = (yyvsp[-1].sent)->conti;
	(yyval.cses)->ini = (yyvsp[-2].number);
	}
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 360 "parser.y" /* yacc.c:1646  */
    {
	codigo.anadirInstruccion("if "+ *(yyvsp[-2].str) +" == ");
	codigo.anadirInstruccion("goto");
	}
#line 1859 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 363 "parser.y" /* yacc.c:1646  */
    {
	codigo.anadirInstruccion("goto");
	}
#line 1867 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 365 "parser.y" /* yacc.c:1646  */
    {
	(yyval.cses) = new casestruct;
	(yyval.cses)->ini = (yyvsp[-6].number) + 2;
	(yyval.cses)->gotos = (yyvsp[0].cses)->gotos;
	(yyval.cses)->gotos.push_back((yyvsp[-6].number));
	vector<int> tmp; tmp.push_back((yyvsp[-6].number) + 1);
	codigo.completarInstrucciones(tmp, (yyvsp[-2].number));
	(yyval.cses)->exit = *unir((yyvsp[-4].sent)->exit, (yyvsp[0].cses)->exit);
	vector<int> tmp1; tmp1.push_back((yyvsp[-2].number) - 1);
	codigo.completarInstrucciones(tmp1, (yyvsp[0].cses)->ini);
	(yyval.cses)->conti = *unir((yyvsp[-4].sent)->conti, (yyvsp[0].cses)->conti);
	}
#line 1884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 380 "parser.y" /* yacc.c:1646  */
    {
	(yyval.sent) = new sentenciastruct;
	(yyval.sent)->exit = *unir((yyvsp[-4].sent)->exit, (yyvsp[-1].sent)->exit);
	(yyval.sent)->conti = *unir((yyvsp[-4].sent)->conti, (yyvsp[-1].sent)->conti);
	codigo.completarInstrucciones(*(yyvsp[-3].numlist), (yyvsp[0].number));
	codigo.completarInstrucciones((yyvsp[-7].expr)->falses, (yyvsp[-2].number));
	codigo.completarInstrucciones((yyvsp[-7].expr)->trues, (yyvsp[-5].number));
	delete (yyvsp[-3].numlist);
	delete (yyvsp[-7].expr);
	delete (yyvsp[-4].sent);
	delete (yyvsp[-1].sent);
	}
#line 1901 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 393 "parser.y" /* yacc.c:1646  */
    {
	(yyval.sent) = new sentenciastruct;
	(yyval.sent)->exit = (yyvsp[0].sent)->exit;
	(yyval.sent)->conti = (yyvsp[0].sent)->conti;
	}
#line 1911 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 399 "parser.y" /* yacc.c:1646  */
    {
	(yyval.sent) = new sentenciastruct;
	(yyval.sent)->exit = (yyvsp[-1].sent)->exit;
	(yyval.sent)->conti = (yyvsp[-1].sent)->conti;
	codigo.completarInstrucciones((yyvsp[-4].expr)->falses, (yyvsp[-2].number));
	codigo.completarInstrucciones((yyvsp[-4].expr)->trues, (yyvsp[0].number));
	delete (yyvsp[-4].expr);
	}
#line 1924 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 409 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1930 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 413 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expr) = new expresionstruct;
	*(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
	delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
        }
#line 1940 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 419 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expr) = new expresionstruct;
	*(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
	delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
        }
#line 1950 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 425 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expr) = new expresionstruct;
	*(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
	delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
        }
#line 1960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 431 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expr) = new expresionstruct;
	*(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
	delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
        }
#line 1970 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 437 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expr) = new expresionstruct;
	*(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
	delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
        }
#line 1980 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 443 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.expr) = new expresionstruct;
	*(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
	delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
        }
#line 1990 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 449 "parser.y" /* yacc.c:1646  */
    {
	(yyval.expr) = new expresionstruct;
	expresionstruct tmp;
	codigo.completarInstrucciones((yyvsp[-3].expr)->falses, (yyvsp[-1].number));
	tmp.falses = (yyvsp[0].expr)->falses;
	tmp.trues = *unir((yyvsp[-3].expr)->trues,(yyvsp[0].expr)->trues);
	*(yyval.expr) = tmp;
	}
#line 2003 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 458 "parser.y" /* yacc.c:1646  */
    {
	(yyval.expr) = new expresionstruct;
	expresionstruct tmp;
	codigo.completarInstrucciones((yyvsp[-3].expr)->trues, (yyvsp[-1].number));
	tmp.trues = (yyvsp[0].expr)->trues;
	tmp.falses = *unir((yyvsp[-3].expr)->falses,(yyvsp[0].expr)->falses);
	*(yyval.expr) = tmp;
	}
#line 2016 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 467 "parser.y" /* yacc.c:1646  */
    {
	(yyval.expr) = new expresionstruct;
	expresionstruct tmp;
	tmp.trues = (yyvsp[0].expr)->falses;
	tmp.falses = (yyvsp[0].expr)->trues;
	*(yyval.expr) = tmp;
	}
#line 2028 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 475 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expr) = new expresionstruct;
	*(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
	delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
        }
#line 2038 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 481 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expr) = new expresionstruct;
	*(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
	delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
        }
#line 2048 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 487 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expr) = new expresionstruct;
	*(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
	delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
        }
#line 2058 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 493 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expr) = new expresionstruct;
	*(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
	delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
        }
#line 2068 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 498 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str); }
#line 2074 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 499 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str); }
#line 2080 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 500 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str); }
#line 2086 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 501 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[-1].expr);}
#line 2092 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 504 "parser.y" /* yacc.c:1646  */
    { (yyval.number) = codigo.obtenRef() ; }
#line 2098 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 507 "parser.y" /* yacc.c:1646  */
    { (yyval.numlist) = new vector<int>;
      (yyval.numlist)->push_back(codigo.obtenRef());
      codigo.anadirInstruccion("goto");}
#line 2106 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2110 "parser.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
  return yyresult;
}
#line 511 "parser.y" /* yacc.c:1906  */


expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 
  tmp.trues.push_back(codigo.obtenRef()) ;
  tmp.falses.push_back(codigo.obtenRef()+1) ;
  codigo.anadirInstruccion("if " + s1 + s2 + s3 + " goto") ;
  codigo.anadirInstruccion("goto") ;
  return tmp ;
}


expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 
  tmp.str = codigo.nuevoId() ;
  codigo.anadirInstruccion(tmp.str + ":=" + s1 + s2 + s3 + ";") ;     
  return tmp ;
}

sentenciastruct makecontinue() {
  sentenciastruct tmp ; 
  tmp.conti.push_back(codigo.obtenRef());
  codigo.anadirInstruccion("goto") ;     
  return tmp ;
}

vector<int> *unir(vector<int> lis1, vector<int> lis2){
        vector<int> *enteros = new vector<int>;

        for (auto it = lis1.begin(); it != lis1.end(); it++){
                enteros->push_back(*it);
        }

        for (auto it = lis2.begin(); it != lis2.end(); it++){
                enteros->push_back(*it);
        }
        return enteros;
}

vector<string> *unir2(vector<string> lis1, vector<string> lis2){
        vector<string> *strs = new vector<string>;

        for (auto it = lis1.begin(); it != lis1.end(); it++){
                strs->push_back(*it);
        }

        for (auto it = lis2.begin(); it != lis2.end(); it++){
                strs->push_back(*it);
        }
        return strs;
}