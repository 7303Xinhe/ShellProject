/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "shell.y" /* yacc.c:339  */

  #include "shell.h"
  extern char *yytext;
  void yyerror(const char *str)
  {
	fprintf(stderr,"error: %s\n", str);
  }
  int yywrap()
  {
	return 1;
  }
  main()
  {
	shell_init();
	yyparse();
  }

#line 84 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    CD = 258,
    PRINTENV = 259,
    UNSETENV = 260,
    SETENV = 261,
    NEWLINE = 262,
    ALIAS = 263,
    UNALIAS = 264,
    BYE = 265,
    WORD = 266,
    QUOTES = 267,
    ENVIRONMENTVARIABLE = 268,
    READFROM = 269,
    WRITETO = 270,
    PIPE = 271,
    AMPERSAND = 272,
    APPEND = 273,
    STANDARDERROR1 = 274,
    STANDARDERROR2 = 275
  };
#endif
/* Tokens.  */
#define CD 258
#define PRINTENV 259
#define UNSETENV 260
#define SETENV 261
#define NEWLINE 262
#define ALIAS 263
#define UNALIAS 264
#define BYE 265
#define WORD 266
#define QUOTES 267
#define ENVIRONMENTVARIABLE 268
#define READFROM 269
#define WRITETO 270
#define PIPE 271
#define AMPERSAND 272
#define APPEND 273
#define STANDARDERROR1 274
#define STANDARDERROR2 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 175 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   778

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  382
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  395

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    20,    20,    21,    22,    23,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      50,    56,    62,    68,    74,    80,    86,    92,    98,   104,
     110,   116,   121,   126,   132,   138,   145,   151,   157,   163,
     169,   174,   179,   184,   190,   195,   201,   206,   211,   216,
     221,   226,   231,   236,   241,   246,   251,   256,   261,   266,
     271,   276,   281,   286,   291,   296,   301,   306,   311,   316,
     321,   326,   331,   336,   341,   346,   351,   356,   361,   366,
     371,   376,   381,   386,   391,   396,   401,   406,   411,   416,
     421,   426,   431,   436,   441,   446,   451,   456,   461,   466,
     471,   476,   481,   486,   491,   496,   501,   506,   511,   516,
     521,   526,   531,   536,   541,   546,   551,   556,   561,   566,
     571,   576,   581,   586,   591,   596,   601,   606,   611,   616,
     621,   626,   631,   636,   641,   646,   651,   656,   661,   666,
     671,   676,   681,   686,   691,   696,   701,   706,   710,   714,
     718,   722,   726,   730,   734,   738,   742,   746,   750,   754,
     758,   762,   766,   770,   774,   778,   782,   786,   790,   794,
     798,   802,   806,   810,   814,   818,   822,   826,   830,   834,
     838,   842,   846,   850,   854,   858,   862,   866,   870,   874,
     878,   882,   886,   890,   894,   898,   902,   906,   910,   914,
     918,   922,   926,   930,   934,   938,   942,   946,   950,   954,
     958,   962,   966,   970,   974,   978,   982,   986,   990,   994,
     998,  1002,  1006,  1010,  1014,  1018,  1022,  1026,  1030,  1034,
    1038,  1042,  1046,  1050,  1054,  1058,  1062,  1066,  1070,  1074,
    1078,  1082,  1086,  1090,  1094,  1098,  1102,  1106,  1110,  1114,
    1118,  1122,  1126,  1130,  1134,  1138,  1142,  1146,  1150,  1154,
    1158,  1162,  1166,  1170,  1174,  1178,  1182,  1186,  1190,  1194,
    1198,  1202,  1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,
    1238,  1242,  1246,  1250,  1254,  1258,  1262,  1266,  1270,  1274,
    1278,  1282,  1286,  1290,  1294,  1298,  1302,  1306,  1310,  1314,
    1318,  1322,  1326,  1330,  1334,  1338,  1342,  1346,  1350,  1354,
    1358,  1362,  1366,  1370,  1374,  1378,  1382,  1386,  1390,  1394,
    1398,  1402,  1406,  1410,  1414,  1418,  1422,  1426,  1430,  1434,
    1438,  1442,  1446,  1450,  1454,  1458,  1462,  1466,  1470,  1474,
    1478,  1482,  1486,  1490,  1494,  1498,  1502,  1506,  1510,  1514,
    1518,  1522,  1526,  1530,  1534,  1538,  1542,  1546,  1550,  1554,
    1558,  1562,  1566,  1570,  1574,  1578,  1582,  1586,  1591,  1596,
    1600,  1632,  1636
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CD", "PRINTENV", "UNSETENV", "SETENV",
  "NEWLINE", "ALIAS", "UNALIAS", "BYE", "WORD", "QUOTES",
  "ENVIRONMENTVARIABLE", "READFROM", "WRITETO", "PIPE", "AMPERSAND",
  "APPEND", "STANDARDERROR1", "STANDARDERROR2", "$accept", "commands",
  "command", "cd2_case", "cd_case", "printenv_case", "unsetenv_case",
  "setenv_case", "alias2_case", "alias_case", "unalias_case", "bye_case",
  "read_from_case2", "write_to_case2", "read_from_case", "write_to_case",
  "pipe2_case", "pipe_case", "ampersand_case",
  "standard_error_redirect_case", "standard_error_redirect_case2",
  "error_case", "append_case2", "append_case", "words", "pipes",
  "command2", "command3", "word_case", "command4", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -48,   758,   -48,   -48,    68,   -48,    68,    68,    68,    68,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,    -3,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,    68,    68,   -48,   -48,    68,     0,   -48,   -48,   -48,
     -48,    68,   -48,    68,     0,   -48,   -48,    -6,   -48,   -48,
     -48,    68,    68,   -48,   -48,   -48,   -48,    68,    68,    68,
     -48,   -48,   -48,   -48,   -48,    68,    68,   334,    -2,   368,
     -48,     2,     2,    68,    -2,   521,   368,   383,   -48,   -48,
     -48,    -2,   -48,     2,     2,    -2,   -48,     2,     2,   334,
      -2,   -48,     2,     2,    -2,   -48,   -48,   -48,     2,     2,
     334,    -2,   368,   -48,     2,     2,    -2,   368,   334,    -2,
     -48,     2,     2,    -2,   -48,   334,    -2,   368,   -48,     2,
       2,    -2,   368,   -48,     2,     2,   -48,   -48,   -48,     2,
       2,   -48,   -48,    -2,   -48,     2,     2,    -2,   -48,     2,
       2,   -48,   -48,   -48,     2,     2,   -48,   -48,    -2,   -48,
       2,     2,    -2,   -48,     2,     2,   334,    -2,   -48,     2,
       2,    -2,   -48,   -48,   -48,     2,     2,   334,    -2,   -48,
       2,     2,    -2,    -2,   -48,     2,     2,    -2,   -48,     2,
       2,   -48,   -48,   -48,     2,     2,    -2,   -48,     2,     2,
      -2,   -48,     2,     2,   334,    -2,   -48,     2,     2,    -2,
     -48,   -48,   -48,     2,     2,   334,    -2,   -48,     2,     2,
      -2,   -48,   -48,   -48,   -48,   -48,     2,     2,   -48,   -48,
     -48,     2,     2,   -48,   -48,   -48,   -48,   -48,     2,     2,
     -48,   -48,   -48,     2,     2,   -48,   -48,    -2,   -48,     2,
       2,    -2,   -48,     2,     2,   -48,   -48,   -48,     2,     2,
     -48,   -48,    -2,   -48,     2,     2,    -2,   -48,     2,     2,
     -48,   -48,   -48,     2,     2,   -48,     2,     2,   -48,   -48,
     -48,     2,     2,   -48,   -48,   -48,   -48,   -48,     2,     2,
     -48,   -48,   -48,     2,     2,   -48,   -48,    -2,   -48,     2,
       2,    -2,   -48,     2,     2,   -48,   -48,   -48,     2,     2,
     -48,   -48,    -2,   -48,     2,     2,    -2,   -48,     2,     2,
     -48,   -48,   -48,     2,     2,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,     2,     2,   -48,   -48,   -48,     2,
       2,   -48,   -48,   -48,   -48,   -48,     2,     2,   -48,   -48,
     -48,     2,     2,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,     2,     2,   -48,   -48,
     -48,     2,     2,   -48,   -48,   -48,   -48,   -48,     2,     2,
     -48,   -48,   -48,     2,     2,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,    49,    30,    32,     0,     0,    35,     0,
      38,   379,   381,   380,    39,    40,    43,    46,    50,    47,
      48,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    27,    28,    15,    16,    25,    17,    18,    20,    21,
      22,    29,    19,    23,    24,    26,     4,     0,     5,    31,
      33,     0,     0,    37,     3,    41,    42,    44,    45,     0,
      54,    51,    53,    55,   382,     0,     0,   115,   116,   301,
     118,   117,   150,     0,   182,   113,   114,     0,    34,    36,
      52,   107,   109,   108,   147,   179,   111,   110,   148,   297,
     298,   300,   299,   317,   333,   112,   149,   181,   180,   198,
      99,   100,   296,   102,   101,   145,   177,    98,   103,   104,
     106,   105,   146,   178,   378,   226,   227,   357,   229,   228,
     245,   261,   225,    95,    94,   142,    96,   143,   175,   174,
     196,    97,   144,   290,   292,   291,   314,   330,   294,   293,
     315,   295,   316,   332,   331,   341,   176,   197,    82,    84,
      83,   136,   168,    86,    85,   137,   286,   287,   289,   288,
     313,   329,    87,   138,   170,   169,   194,    78,    79,    81,
      80,   135,   167,    88,    90,    89,   139,   171,    92,    91,
     140,    93,   141,   173,   172,   195,   219,   221,   220,   242,
     258,   223,   222,   243,   353,   354,   356,   355,   365,   373,
     224,   244,   260,   259,   269,   215,   216,   218,   217,   241,
     257,    77,   134,   166,   193,   283,   282,   310,   284,   311,
     327,   326,   339,   285,   312,   328,   340,    70,    69,   128,
      71,   129,   161,   160,   189,    72,   130,   276,   278,   277,
     307,   323,   280,   279,   308,   281,   309,   325,   324,   338,
     162,   190,    63,    65,    64,   125,   157,    67,    66,   126,
      68,   127,   159,   158,   188,    74,    73,   131,    75,   132,
     164,   163,   191,    76,   133,   165,   192,   212,   211,   238,
     213,   239,   255,   254,   267,   214,   240,   347,   349,   348,
     362,   370,   351,   350,   363,   352,   364,   372,   371,   377,
     256,   268,   205,   207,   206,   235,   251,   209,   208,   236,
     210,   237,   253,   252,   266,   275,   306,   322,   337,    61,
     123,   155,   186,   272,   271,   303,   273,   304,   320,   319,
     335,   274,   305,   321,   336,    58,    57,   120,    59,   121,
     153,   152,   184,    60,   122,   154,   185,    62,   124,   156,
     187,   204,   234,   250,   265,   344,   343,   359,   345,   360,
     368,   367,   375,   346,   361,   369,   376,   201,   200,   231,
     202,   232,   248,   247,   263,   203,   233,   249,   264,   270,
     302,   318,   334,    56,   119,   151,   183,   342,   358,   366,
     374,   199,   230,   246,   262
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,    22,    25,   259,   516,    31,   194,   -47,   256,
     409,   -48,    34,   560,     1,   -44,   -48,   -48,   672,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    65,    66,    33,    34,    59,    60,    37,    38,
      39,    40,    73,    42,    57,    44,    45,    46,    62,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      70,    64,    43,    76,    54,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    17,    16,    19,    20,    17,
      82,    86,    91,    31,    95,    96,    32,    97,   103,   110,
     118,   107,    35,   122,   123,    41,   126,   127,   128,     0,
     131,   132,   134,   138,     0,   141,   142,   143,    75,     0,
       0,   146,   147,   149,   153,   158,     0,   162,   163,   164,
     169,   174,   178,     0,   181,   182,   183,     0,   187,   191,
     196,     0,   200,   201,   202,   207,     0,   211,   212,    11,
      12,    13,   213,   214,     0,     0,   215,     0,   218,   219,
     220,     0,   223,   224,     0,     0,     0,   225,   226,     0,
       0,   227,     0,   230,   231,   232,     0,   235,   236,   238,
     242,     0,   245,   246,   247,     0,     0,     0,   250,   251,
     253,   257,     0,   260,   261,   262,   265,     0,   268,   269,
     270,     0,   273,   274,     0,     0,     0,   275,   276,   277,
       0,   280,   281,   282,     0,   285,   286,   288,   292,     0,
     295,   296,   297,     0,     0,     0,   300,   301,   303,   307,
       0,   310,   311,   312,     0,     0,     0,     0,     0,   315,
     316,     0,     0,     0,   317,   318,     0,     0,     0,     0,
       0,   319,   320,     0,     0,     0,   321,   322,     0,     0,
     323,     0,   326,   327,   328,    36,   331,   332,     0,     0,
       0,   333,   334,     0,     0,   335,     0,   338,   339,   340,
       0,   343,   344,     0,     0,     0,   345,   346,     0,   347,
     348,     0,     0,     0,   349,   350,     0,     0,     0,     0,
       0,   351,   352,     0,     0,     0,   353,   354,    63,     0,
     355,    69,   358,   359,   360,     0,   363,   364,     0,     0,
       0,   365,   366,     0,     0,   367,     0,   370,   371,   372,
       0,   375,   376,     0,     0,     0,   377,   378,     0,   102,
      63,   117,     0,     0,     0,     0,     0,   379,   380,     0,
       0,     0,   381,   382,     0,     0,     0,     0,     0,   383,
     384,     0,     0,     0,   385,   386,     0,     0,     0,     0,
       0,    63,     0,    71,     0,     0,    67,     0,     0,   387,
     388,     0,     0,     0,   389,   390,    63,     0,     0,     0,
       0,   391,   392,    83,    87,    92,   393,   394,    89,     0,
      98,   104,   111,   119,   100,   108,   115,   124,     0,     0,
       0,   129,     0,     0,     0,   135,   139,     0,     0,    15,
     144,    17,    18,    19,    20,     0,   150,   154,   159,     0,
       0,   156,   165,   170,   175,   179,   167,     0,     0,   184,
       0,   188,   192,   197,     0,     0,   194,   203,   208,     0,
       0,   205,    14,    15,    16,    17,    18,    19,    20,   216,
     114,     0,     0,   221,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   228,     0,     0,     0,   233,     0,
       0,     0,   239,   243,     0,     0,     0,   248,     0,     0,
       0,     0,     0,   254,   258,     0,     0,     0,   263,   266,
       0,     0,     0,   271,     0,     0,     0,     0,     0,     0,
       0,     0,   278,     0,     0,     0,   283,     0,     0,     0,
     289,   293,     0,     0,     0,   298,    72,     0,     0,     0,
       0,   304,   308,     0,     0,     0,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    88,    93,     0,
       0,     0,     0,    99,   105,   112,   120,     0,     0,     0,
     125,     0,     0,   324,   130,     0,     0,   329,   136,   140,
       0,     0,     0,   145,     0,     0,     0,     0,   336,   151,
     155,   160,   341,     0,     0,   166,   171,   176,   180,     0,
       0,     0,   185,     0,   189,   193,   198,     0,     0,     0,
     204,   209,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   217,   356,     0,     0,   222,   361,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   229,   368,     0,
       0,   234,   373,    68,     0,   240,   244,     0,     0,     0,
     249,     0,     0,     0,     0,     0,   255,   259,     0,     0,
       0,   264,   267,    81,     0,    90,   272,     0,     0,     0,
       0,   101,   109,   116,     0,   279,     0,     0,     0,   284,
       0,     0,     0,   290,   294,   133,     0,    74,   299,     0,
       0,     0,     0,     0,   305,   309,   148,     0,   157,   314,
       0,     0,     0,   168,   173,     0,     0,    85,     0,    94,
       0,   186,     0,   195,     0,   106,   113,   121,   206,     0,
       0,     0,     0,     0,     0,     0,   325,     0,     0,   137,
     330,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     152,   337,   161,     0,     0,   342,     0,   172,   177,     0,
       0,     0,   237,    47,     0,   190,    49,   199,    50,    51,
      52,    53,   210,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   357,     0,     0,     0,
     362,     0,     0,    55,    56,     0,     0,    58,     0,     0,
     287,   369,     0,    61,     0,   374,   241,     0,     0,    77,
       0,   302,     0,    78,    79,     0,     0,   256,     0,     0,
      80,    58,     0,     0,     0,     0,     0,    55,    56,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,    80,
       0,     0,     0,     0,   291,     0,     0,     0,     2,     3,
       0,     4,     5,     6,     7,   306,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
      47,     7,     1,    47,     7,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    17,    16,    19,    20,    17,
      67,    68,    69,     1,    71,    72,     1,    74,    75,    76,
      77,    75,     1,    77,    81,     1,    83,    84,    85,    -1,
      87,    88,    89,    90,    -1,    92,    93,    94,    47,    -1,
      -1,    98,    99,   100,   101,   102,    -1,   104,   105,   106,
     107,   108,   109,    -1,   111,   112,   113,    -1,   115,   116,
     117,    -1,   119,   120,   121,   122,    -1,   124,   125,    11,
      12,    13,   129,   130,    -1,    -1,   133,    -1,   135,   136,
     137,    -1,   139,   140,    -1,    -1,    -1,   144,   145,    -1,
      -1,   148,    -1,   150,   151,   152,    -1,   154,   155,   156,
     157,    -1,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,    -1,   170,   171,   172,   173,    -1,   175,   176,
     177,    -1,   179,   180,    -1,    -1,    -1,   184,   185,   186,
      -1,   188,   189,   190,    -1,   192,   193,   194,   195,    -1,
     197,   198,   199,    -1,    -1,    -1,   203,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,   233,   234,    -1,    -1,
     237,    -1,   239,   240,   241,     1,   243,   244,    -1,    -1,
      -1,   248,   249,    -1,    -1,   252,    -1,   254,   255,   256,
      -1,   258,   259,    -1,    -1,    -1,   263,   264,    -1,   266,
     267,    -1,    -1,    -1,   271,   272,    -1,    -1,    -1,    -1,
      -1,   278,   279,    -1,    -1,    -1,   283,   284,    44,    -1,
     287,    47,   289,   290,   291,    -1,   293,   294,    -1,    -1,
      -1,   298,   299,    -1,    -1,   302,    -1,   304,   305,   306,
      -1,   308,   309,    -1,    -1,    -1,   313,   314,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,   324,   325,    -1,
      -1,    -1,   329,   330,    -1,    -1,    -1,    -1,    -1,   336,
     337,    -1,    -1,    -1,   341,   342,    -1,    -1,    -1,    -1,
      -1,   107,    -1,    47,    -1,    -1,    47,    -1,    -1,   356,
     357,    -1,    -1,    -1,   361,   362,   122,    -1,    -1,    -1,
      -1,   368,   369,    67,    68,    69,   373,   374,    69,    -1,
      74,    75,    76,    77,    75,    76,    77,    81,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    89,    90,    -1,    -1,    15,
      94,    17,    18,    19,    20,    -1,   100,   101,   102,    -1,
      -1,   102,   106,   107,   108,   109,   107,    -1,    -1,   113,
      -1,   115,   116,   117,    -1,    -1,   117,   121,   122,    -1,
      -1,   122,    14,    15,    16,    17,    18,    19,    20,   133,
       7,    -1,    -1,   137,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   148,    -1,    -1,    -1,   152,    -1,
      -1,    -1,   156,   157,    -1,    -1,    -1,   161,    -1,    -1,
      -1,    -1,    -1,   167,   168,    -1,    -1,    -1,   172,   173,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,   190,    -1,    -1,    -1,
     194,   195,    -1,    -1,    -1,   199,    47,    -1,    -1,    -1,
      -1,   205,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      81,    -1,    -1,   237,    85,    -1,    -1,   241,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,   252,   100,
     101,   102,   256,    -1,    -1,   106,   107,   108,   109,    -1,
      -1,    -1,   113,    -1,   115,   116,   117,    -1,    -1,    -1,
     121,   122,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   133,   287,    -1,    -1,   137,   291,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   302,    -1,
      -1,   152,   306,    47,    -1,   156,   157,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    -1,    -1,   167,   168,    -1,    -1,
      -1,   172,   173,    67,    -1,    69,   177,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,   186,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   195,    89,    -1,    47,   199,    -1,
      -1,    -1,    -1,    -1,   205,   206,   100,    -1,   102,   210,
      -1,    -1,    -1,   107,   108,    -1,    -1,    67,    -1,    69,
      -1,   115,    -1,   117,    -1,    75,    76,    77,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,    -1,    -1,    89,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   252,   102,    -1,    -1,   256,    -1,   107,   108,    -1,
      -1,    -1,   156,     1,    -1,   115,     4,   117,     6,     7,
       8,     9,   122,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,
     291,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,    -1,
     194,   302,    -1,    41,    -1,   306,   156,    -1,    -1,    47,
      -1,   205,    -1,    51,    52,    -1,    -1,   167,    -1,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,     0,     1,
      -1,     3,     4,     5,     6,   205,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,     0,     1,     3,     4,     5,     6,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    49,
      49,    49,    49,    49,     7,    49,    49,    45,    49,    37,
      38,    49,    49,    38,     7,    33,    34,    35,    36,    38,
      39,    40,    41,    43,    44,    45,    46,    49,    49,    49,
      49,    36,    39,    40,    41,    44,    39,    40,    41,    35,
      36,    39,    40,    41,    44,    39,    39,    39,    40,    41,
      35,    36,    38,    39,    40,    41,    44,    46,    35,    36,
      39,    40,    41,    44,     7,    35,    36,    38,    39,    40,
      41,    44,    46,    39,    40,    41,    39,    39,    39,    40,
      41,    39,    39,    36,    39,    40,    41,    44,    39,    40,
      41,    39,    39,    39,    40,    41,    39,    39,    36,    39,
      40,    41,    44,    39,    40,    41,    35,    36,    39,    40,
      41,    44,    39,    39,    39,    40,    41,    35,    36,    39,
      40,    41,    44,    36,    39,    40,    41,    44,    39,    40,
      41,    39,    39,    39,    40,    41,    36,    39,    40,    41,
      44,    39,    40,    41,    35,    36,    39,    40,    41,    44,
      39,    39,    39,    40,    41,    35,    36,    39,    40,    41,
      44,    39,    39,    39,    39,    39,    40,    41,    39,    39,
      39,    40,    41,    39,    39,    39,    39,    39,    40,    41,
      39,    39,    39,    40,    41,    39,    39,    36,    39,    40,
      41,    44,    39,    40,    41,    39,    39,    39,    40,    41,
      39,    39,    36,    39,    40,    41,    44,    39,    40,    41,
      39,    39,    39,    40,    41,    39,    40,    41,    39,    39,
      39,    40,    41,    39,    39,    39,    39,    39,    40,    41,
      39,    39,    39,    40,    41,    39,    39,    36,    39,    40,
      41,    44,    39,    40,    41,    39,    39,    39,    40,    41,
      39,    39,    36,    39,    40,    41,    44,    39,    40,    41,
      39,    39,    39,    40,    41,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    40,    41,    39,    39,    39,    40,
      41,    39,    39,    39,    39,    39,    40,    41,    39,    39,
      39,    40,    41,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    40,    41,    39,    39,
      39,    40,    41,    39,    39,    39,    39,    39,    40,    41,
      39,    39,    39,    40,    41,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    21,    22,    22,    22,    22,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    38,    39,    40,    41,    42,
      43,    44,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    48,    49,
      49,    49,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     3,     1,     3,     2,     1,     1,
       1,     2,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     7,     6,     6,     6,
       6,     6,     6,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     7,
       6,     6,     6,     6,     6,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     3,     3,     3,     3,
       2,     7,     6,     6,     6,     6,     6,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     2,     7,     6,     6,     6,     6,     5,     5,
       5,     5,     5,     5,     4,     4,     4,     4,     3,     7,
       6,     6,     6,     6,     6,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     3,     3,     3,     3,
       7,     6,     6,     6,     6,     5,     5,     5,     5,     5,
       5,     4,     4,     4,     4,     3,     7,     6,     6,     6,
       6,     5,     5,     5,     5,     5,     5,     4,     4,     4,
       4,     3,     7,     6,     6,     6,     5,     5,     5,     4,
       7,     6,     6,     6,     6,     6,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     3,     3,     3,
       3,     2,     7,     6,     6,     6,     6,     5,     5,     5,
       5,     5,     5,     4,     4,     4,     4,     3,     7,     6,
       6,     6,     6,     5,     5,     5,     5,     5,     5,     4,
       4,     4,     4,     3,     7,     6,     6,     6,     5,     5,
       5,     4,     7,     6,     6,     6,     6,     5,     5,     5,
       5,     5,     5,     4,     4,     4,     4,     3,     7,     6,
       6,     6,     5,     5,     5,     4,     7,     6,     6,     6,
       5,     5,     5,     4,     7,     6,     6,     5,     3,     1,
       1,     1,     2
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
        case 30:
#line 51 "shell.y" /* yacc.c:1646  */
    {
								cd_home_function();
								lineHeaderPath();
							}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 57 "shell.y" /* yacc.c:1646  */
    {
								cd_function(textArray[getWords() - 1]);
								lineHeaderPath();
							}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 63 "shell.y" /* yacc.c:1646  */
    {
								printenv_function();
								lineHeaderPath();
							}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 69 "shell.y" /* yacc.c:1646  */
    {
								unsetenv_function(textArray[getWords() - 1], 1);
								lineHeaderPath();
							}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 75 "shell.y" /* yacc.c:1646  */
    {
								setenv_function(textArray[getWords() - 2], textArray [getWords() - 1], 1);	
								lineHeaderPath();	
							}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 81 "shell.y" /* yacc.c:1646  */
    {
								alias_function2();
								lineHeaderPath();
							}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 87 "shell.y" /* yacc.c:1646  */
    {
								alias_function(textArray[getWords() - 2], textArray[getWords() - 1]);
								lineHeaderPath();
							}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 93 "shell.y" /* yacc.c:1646  */
    {
								unalias_function(textArray[getWords() - 1], 1);  
								lineHeaderPath();                            
							}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 99 "shell.y" /* yacc.c:1646  */
    { 
								printf("\n**********************  SHELL ENDS HERE  **********************\n\n");
								exit(0); //exit shell
							}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 105 "shell.y" /* yacc.c:1646  */
    {
								word_function("<");
								lineHeaderPath();
							}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 111 "shell.y" /* yacc.c:1646  */
    {
								word_function(">");
								lineHeaderPath();
							}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 117 "shell.y" /* yacc.c:1646  */
    {
								lineHeaderPath();
							}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 122 "shell.y" /* yacc.c:1646  */
    {
								lineHeaderPath();
							}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 127 "shell.y" /* yacc.c:1646  */
    {
								word_function("|");
								lineHeaderPath();
							}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 133 "shell.y" /* yacc.c:1646  */
    {
								//printf("PIPE words\n");
								//pipe with a command name and more than one argument
								lineHeaderPath();
							}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 139 "shell.y" /* yacc.c:1646  */
    {
								//printf("PIPE word_case\n");
								//pipe with a command name and no arguments
								lineHeaderPath();
							}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 146 "shell.y" /* yacc.c:1646  */
    {
								word_function("&");
								lineHeaderPath();
							}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 152 "shell.y" /* yacc.c:1646  */
    {
								word_function("2>&1");
								lineHeaderPath();
							}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 158 "shell.y" /* yacc.c:1646  */
    {
								word_function(yytext);
								lineHeaderPath();
							}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 164 "shell.y" /* yacc.c:1646  */
    {
								printf ("Syntax error.\n");
								lineHeaderPath();
							}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 169 "shell.y" /* yacc.c:1646  */
    {
								word_function(">>");
								lineHeaderPath();
							}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 175 "shell.y" /* yacc.c:1646  */
    {
								lineHeaderPath();
							}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 180 "shell.y" /* yacc.c:1646  */
    {
								//printf("word_case word_case\n");
								lineHeaderPath();
							}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 185 "shell.y" /* yacc.c:1646  */
    {
								//printf("words word_case\n");
								lineHeaderPath();
							}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 191 "shell.y" /* yacc.c:1646  */
    {
								//printf("pipe_case pipe_case\n");
								lineHeaderPath();
							}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 196 "shell.y" /* yacc.c:1646  */
    {
								//printf("pipes pipe_case\n");
								lineHeaderPath();
							}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 202 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 207 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 212 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 217 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 222 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 227 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 232 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 237 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 242 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 247 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 252 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 257 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 262 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 267 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 272 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 277 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 282 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 287 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 292 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 297 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 302 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 307 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 312 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 317 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 322 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 327 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 332 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 337 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 342 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 347 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 352 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 357 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 362 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 367 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 372 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 377 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 382 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 387 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 392 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 397 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 402 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 407 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 412 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 417 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 422 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 427 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 432 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 437 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 442 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 447 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 452 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 457 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 462 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 467 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 472 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 477 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 482 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 487 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 492 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 497 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 502 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 507 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 512 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 517 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 522 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 527 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 532 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 537 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 542 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 547 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 552 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 557 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 562 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 567 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 572 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 577 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 582 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 587 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 592 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 597 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 602 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 607 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 612 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 617 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 622 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 627 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 632 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 637 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 642 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 647 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 652 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 657 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 662 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 667 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 672 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 677 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 682 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 687 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 692 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 697 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 702 "shell.y" /* yacc.c:1646  */
    {
			execute();
			lineHeaderPath();
		}
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 707 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 711 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 715 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 719 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 723 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 727 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 731 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 735 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 739 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 743 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 747 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 751 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 755 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 759 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 763 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 767 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 771 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 775 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 779 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 783 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 787 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 791 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 795 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 799 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 803 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 807 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 811 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 2994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 815 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 819 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 823 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 827 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 831 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 835 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 839 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 843 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 847 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 851 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 855 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 859 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 863 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 867 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 871 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 875 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 879 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 883 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 887 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 891 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 895 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 899 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 903 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 907 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 911 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 915 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 919 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 923 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 927 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 931 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 935 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 939 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 943 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 947 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 951 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 955 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 959 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 963 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 967 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 971 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 975 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 979 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 983 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 987 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 991 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 995 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 999 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1003 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1007 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1011 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1015 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1019 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1023 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1027 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1031 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1035 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1039 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1043 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1047 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1051 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1055 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1059 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1063 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1067 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1071 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1075 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1079 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1083 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1087 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1091 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1095 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1099 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1103 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1107 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1111 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1115 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1119 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1123 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1127 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1131 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1135 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1139 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1143 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1147 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1151 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1155 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1159 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1163 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1167 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1171 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1175 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1179 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1183 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1187 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1191 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1195 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1199 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1203 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1207 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1211 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1215 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1219 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1223 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1227 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1231 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1235 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1239 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1243 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1247 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1251 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1255 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1259 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1263 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1267 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1271 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1275 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1279 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1283 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1287 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1291 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1295 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1299 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1303 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1307 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1311 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 3994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1315 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1319 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1323 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1327 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1331 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1335 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1339 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1343 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1347 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1351 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1355 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1359 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1363 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1367 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1371 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1375 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1379 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1383 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1387 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1391 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1395 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1399 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1403 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1407 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1411 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1415 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1419 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1423 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1427 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1431 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1435 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1439 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1443 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1447 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1451 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1455 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1459 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1463 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1467 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1471 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1475 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1479 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1483 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1487 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1491 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1495 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1499 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1503 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1507 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1511 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1515 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1519 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1523 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1527 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1531 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1535 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1539 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1543 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1547 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1551 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1555 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1559 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1563 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1567 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1571 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1575 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1579 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1583 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1587 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1592 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1597 "shell.y" /* yacc.c:1646  */
    {
								word2Function(yytext);
							}
#line 4562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1601 "shell.y" /* yacc.c:1646  */
    {
								char* actualText = malloc(300 * sizeof(char));
								if(actualText == (char*) NULL) //error
								{
										perror ("Error with memory allocation.");
										printf ("Error at line %d\n", __LINE__);
								}
								else
								{
									strncpy(actualText, &yytext[2], strlen(yytext) - 3); //take everything between ${ and }
									char* result = malloc(300 * sizeof(char));
									if(result == (char*) NULL) //error
									{
										perror ("Error with memory allocation.");
										printf ("Error at line %d\n", __LINE__);
									}
									else
									{
										if(getenv(actualText) == NULL) //invalid environment variable
										{
											perror ("Entered an invalid environment variable.");
											printf ("Error at line %d\n", __LINE__);
										}
										else
										{
											strcpy(result, getenv(actualText)); //get value, if any
											word_function(result);
										}
									}
								}		
							}
#line 4598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1632 "shell.y" /* yacc.c:1646  */
    {
								quoteFunction(yytext);
							}
#line 4606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1637 "shell.y" /* yacc.c:1646  */
    {
			execute(); lineHeaderPath();
		}
#line 4614 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4618 "y.tab.c" /* yacc.c:1646  */
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
#line 1640 "shell.y" /* yacc.c:1906  */

