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
    MATCHER = 267,
    QUOTES = 268,
    ENVIRONMENTVARIABLE = 269,
    SLASH = 270,
    READFROM = 271,
    WRITETO = 272,
    PIPE = 273,
    AMPERSAND = 274,
    APPEND = 275,
    STANDARDERROR1 = 276,
    STANDARDERROR2 = 277,
    COMMANDNAME = 278
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
#define MATCHER 267
#define QUOTES 268
#define ENVIRONMENTVARIABLE 269
#define SLASH 270
#define READFROM 271
#define WRITETO 272
#define PIPE 273
#define AMPERSAND 274
#define APPEND 275
#define STANDARDERROR1 276
#define STANDARDERROR2 277
#define COMMANDNAME 278

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

#line 181 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   797

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  384
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  397

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    22,    22,    23,    24,    25,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    54,    59,    65,    70,    75,    82,    87,    92,    98,
     104,   108,   113,   118,   122,   126,   131,   136,   142,   148,
     153,   158,   163,   167,   172,   176,   181,   185,   190,   194,
     198,   202,   206,   210,   214,   218,   222,   226,   230,   234,
     238,   242,   246,   250,   254,   258,   262,   266,   270,   274,
     278,   282,   286,   290,   294,   298,   302,   306,   310,   314,
     318,   322,   326,   330,   334,   338,   342,   346,   350,   354,
     358,   362,   366,   370,   374,   378,   382,   386,   390,   394,
     398,   402,   406,   410,   414,   418,   422,   426,   430,   434,
     438,   442,   446,   450,   454,   458,   462,   466,   470,   474,
     478,   482,   486,   490,   494,   498,   502,   506,   510,   514,
     518,   522,   526,   530,   534,   538,   542,   546,   550,   554,
     558,   562,   566,   570,   574,   578,   582,   586,   590,   594,
     598,   602,   606,   610,   614,   618,   622,   626,   630,   634,
     638,   642,   646,   650,   654,   658,   662,   666,   670,   674,
     678,   682,   686,   690,   694,   698,   702,   706,   710,   714,
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
    1479,  1484,  1488,  1520,  1524
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CD", "PRINTENV", "UNSETENV", "SETENV",
  "NEWLINE", "ALIAS", "UNALIAS", "BYE", "WORD", "MATCHER", "QUOTES",
  "ENVIRONMENTVARIABLE", "SLASH", "READFROM", "WRITETO", "PIPE",
  "AMPERSAND", "APPEND", "STANDARDERROR1", "STANDARDERROR2", "COMMANDNAME",
  "$accept", "commands", "command", "cd_home_case", "cd_case",
  "printenv_case", "unsetenv_case", "setenv_case", "alias_list_case",
  "alias_case", "unalias_case", "bye_case", "slash_case",
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
     275,   276,   277,   278
};
# endif

#define YYPACT_NINF -50

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -50,   763,   -50,   -50,   153,   -50,   153,   153,   153,   153,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,    -3,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   153,   153,   -50,   -50,   153,   -13,   -50,
     -50,   -50,   -50,   153,   -50,   153,   -13,   -50,   -50,    -5,
     -50,   -50,   -50,   153,   153,   -50,   -50,   -50,   -50,   153,
     153,   153,   -50,   -50,   -50,   -50,   -50,   153,   153,   399,
     157,   363,   -50,   -12,   -12,   153,   157,   775,   363,   381,
     -50,   -50,   -50,   157,   -50,   -12,   -12,   157,   -50,   -12,
     -12,   399,   157,   -50,   -12,   -12,   157,   -50,   -50,   -50,
     -12,   -12,   399,   157,   363,   -50,   -12,   -12,   157,   363,
     399,   157,   -50,   -12,   -12,   157,   -50,   399,   157,   363,
     -50,   -12,   -12,   157,   363,   -50,   -12,   -12,   -50,   -50,
     -50,   -12,   -12,   -50,   -50,   157,   -50,   -12,   -12,   157,
     -50,   -12,   -12,   -50,   -50,   -50,   -12,   -12,   -50,   -50,
     157,   -50,   -12,   -12,   157,   -50,   -12,   -12,   399,   157,
     -50,   -12,   -12,   157,   -50,   -50,   -50,   -12,   -12,   399,
     157,   -50,   -12,   -12,   157,   157,   -50,   -12,   -12,   157,
     -50,   -12,   -12,   -50,   -50,   -50,   -12,   -12,   157,   -50,
     -12,   -12,   157,   -50,   -12,   -12,   399,   157,   -50,   -12,
     -12,   157,   -50,   -50,   -50,   -12,   -12,   399,   157,   -50,
     -12,   -12,   157,   -50,   -50,   -50,   -50,   -50,   -12,   -12,
     -50,   -50,   -50,   -12,   -12,   -50,   -50,   -50,   -50,   -50,
     -12,   -12,   -50,   -50,   -50,   -12,   -12,   -50,   -50,   157,
     -50,   -12,   -12,   157,   -50,   -12,   -12,   -50,   -50,   -50,
     -12,   -12,   -50,   -50,   157,   -50,   -12,   -12,   157,   -50,
     -12,   -12,   -50,   -50,   -50,   -12,   -12,   -50,   -12,   -12,
     -50,   -50,   -50,   -12,   -12,   -50,   -50,   -50,   -50,   -50,
     -12,   -12,   -50,   -50,   -50,   -12,   -12,   -50,   -50,   157,
     -50,   -12,   -12,   157,   -50,   -12,   -12,   -50,   -50,   -50,
     -12,   -12,   -50,   -50,   157,   -50,   -12,   -12,   157,   -50,
     -12,   -12,   -50,   -50,   -50,   -12,   -12,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -12,   -12,   -50,   -50,
     -50,   -12,   -12,   -50,   -50,   -50,   -50,   -50,   -12,   -12,
     -50,   -50,   -50,   -12,   -12,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -12,   -12,
     -50,   -50,   -50,   -12,   -12,   -50,   -50,   -50,   -50,   -50,
     -12,   -12,   -50,   -50,   -50,   -12,   -12,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,    51,    31,    33,     0,     0,    36,     0,
      39,   381,   383,   382,    40,    41,    42,    45,    48,    52,
      49,    50,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    28,    29,    16,    17,    26,    18,    19,
      21,    22,    23,    30,    20,    24,    25,    27,     4,     0,
       5,    32,    34,     0,     0,    38,     3,    43,    44,    46,
      47,     0,    56,    53,    55,    57,   384,     0,     0,   117,
     118,   303,   120,   119,   152,     0,   184,   115,   116,     0,
      35,    37,    54,   109,   111,   110,   149,   181,   113,   112,
     150,   299,   300,   302,   301,   319,   335,   114,   151,   183,
     182,   200,   101,   102,   298,   104,   103,   147,   179,   100,
     105,   106,   108,   107,   148,   180,   380,   228,   229,   359,
     231,   230,   247,   263,   227,    97,    96,   144,    98,   145,
     177,   176,   198,    99,   146,   292,   294,   293,   316,   332,
     296,   295,   317,   297,   318,   334,   333,   343,   178,   199,
      84,    86,    85,   138,   170,    88,    87,   139,   288,   289,
     291,   290,   315,   331,    89,   140,   172,   171,   196,    80,
      81,    83,    82,   137,   169,    90,    92,    91,   141,   173,
      94,    93,   142,    95,   143,   175,   174,   197,   221,   223,
     222,   244,   260,   225,   224,   245,   355,   356,   358,   357,
     367,   375,   226,   246,   262,   261,   271,   217,   218,   220,
     219,   243,   259,    79,   136,   168,   195,   285,   284,   312,
     286,   313,   329,   328,   341,   287,   314,   330,   342,    72,
      71,   130,    73,   131,   163,   162,   191,    74,   132,   278,
     280,   279,   309,   325,   282,   281,   310,   283,   311,   327,
     326,   340,   164,   192,    65,    67,    66,   127,   159,    69,
      68,   128,    70,   129,   161,   160,   190,    76,    75,   133,
      77,   134,   166,   165,   193,    78,   135,   167,   194,   214,
     213,   240,   215,   241,   257,   256,   269,   216,   242,   349,
     351,   350,   364,   372,   353,   352,   365,   354,   366,   374,
     373,   379,   258,   270,   207,   209,   208,   237,   253,   211,
     210,   238,   212,   239,   255,   254,   268,   277,   308,   324,
     339,    63,   125,   157,   188,   274,   273,   305,   275,   306,
     322,   321,   337,   276,   307,   323,   338,    60,    59,   122,
      61,   123,   155,   154,   186,    62,   124,   156,   187,    64,
     126,   158,   189,   206,   236,   252,   267,   346,   345,   361,
     347,   362,   370,   369,   377,   348,   363,   371,   378,   203,
     202,   233,   204,   234,   250,   249,   265,   205,   235,   251,
     266,   272,   304,   320,   336,    58,   121,   153,   185,   344,
     360,   368,   376,   201,   232,   248,   264
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,     9,    17,   192,   514,    18,   227,   -49,
     254,   407,   -50,    22,   558,     0,   -46,   -50,   -50,   680,
     -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    67,    68,    35,    36,    61,    62,    39,
      40,    41,    42,    75,    44,    59,    46,    47,    48,    64,
      50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      72,    45,    66,    78,    56,    17,    11,    18,    12,    13,
      33,    15,    16,    17,    18,    19,    20,    21,    34,    37,
      84,    88,    93,    43,    97,    98,     0,    99,   105,   112,
     120,   109,     0,   124,   125,     0,   128,   129,   130,     0,
     133,   134,   136,   140,     0,   143,   144,   145,     0,    77,
       0,   148,   149,   151,   155,   160,     0,   164,   165,   166,
     171,   176,   180,     0,   183,   184,   185,     0,   189,   193,
     198,     0,   202,   203,   204,   209,     0,   213,   214,     0,
       0,     0,   215,   216,     0,     0,   217,     0,   220,   221,
     222,     0,   225,   226,     0,     0,     0,   227,   228,     0,
       0,   229,     0,   232,   233,   234,     0,   237,   238,   240,
     244,     0,   247,   248,   249,     0,     0,     0,   252,   253,
     255,   259,     0,   262,   263,   264,   267,     0,   270,   271,
     272,     0,   275,   276,     0,     0,     0,   277,   278,   279,
       0,   282,   283,   284,     0,   287,   288,   290,   294,     0,
     297,   298,   299,     0,     0,     0,   302,   303,   305,   309,
       0,   312,   313,   314,    11,     0,    12,    13,     0,   317,
     318,     0,     0,     0,   319,   320,    18,     0,    20,    21,
       0,   321,   322,     0,     0,     0,   323,   324,     0,     0,
     325,     0,   328,   329,   330,     0,   333,   334,     0,     0,
       0,   335,   336,     0,     0,   337,     0,   340,   341,   342,
       0,   345,   346,     0,     0,     0,   347,   348,     0,   349,
     350,     0,     0,     0,   351,   352,     0,     0,    38,     0,
       0,   353,   354,     0,     0,     0,   355,   356,     0,     0,
     357,    69,   360,   361,   362,     0,   365,   366,     0,     0,
       0,   367,   368,     0,     0,   369,     0,   372,   373,   374,
       0,   377,   378,    91,     0,     0,   379,   380,     0,   102,
     110,   117,     0,    65,     0,     0,    71,   381,   382,     0,
       0,     0,   383,   384,     0,     0,     0,     0,     0,   385,
     386,     0,     0,     0,   387,   388,   158,     0,     0,     0,
       0,   169,     0,    73,   104,    65,   119,     0,     0,   389,
     390,   196,     0,     0,   391,   392,   207,     0,     0,     0,
       0,   393,   394,    85,    89,    94,   395,   396,     0,     0,
     100,   106,   113,   121,     0,     0,    65,   126,     0,     0,
       0,   131,     0,     0,     0,   137,   141,     0,     0,     0,
     146,    65,     0,     0,     0,     0,   152,   156,   161,     0,
       0,     0,   167,   172,   177,   181,     0,     0,     0,   186,
       0,   190,   194,   199,     0,     0,     0,   205,   210,    15,
      16,    17,    18,    19,    20,    21,     0,     0,   116,   218,
       0,     0,    11,   223,    12,    13,     0,    15,    16,    17,
      18,    19,    20,    21,   230,     0,     0,     0,   235,     0,
       0,     0,   241,   245,     0,     0,    16,   250,    18,    19,
      20,    21,     0,   256,   260,     0,     0,     0,   265,   268,
       0,     0,     0,   273,     0,     0,     0,     0,     0,     0,
       0,     0,   280,     0,     0,     0,   285,     0,     0,     0,
     291,   295,     0,     0,     0,   300,    74,     0,     0,     0,
       0,   306,   310,     0,     0,     0,   315,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    90,    95,     0,
       0,     0,     0,   101,   107,   114,   122,     0,     0,     0,
     127,     0,     0,   326,   132,     0,     0,   331,   138,   142,
       0,     0,     0,   147,     0,     0,     0,     0,   338,   153,
     157,   162,   343,     0,     0,   168,   173,   178,   182,     0,
       0,     0,   187,     0,   191,   195,   200,     0,     0,     0,
     206,   211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   358,     0,     0,   224,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   370,     0,
       0,   236,   375,    70,     0,   242,   246,     0,     0,     0,
     251,     0,     0,     0,     0,     0,   257,   261,     0,     0,
       0,   266,   269,    83,     0,    92,   274,     0,     0,     0,
       0,   103,   111,   118,     0,   281,     0,     0,     0,   286,
       0,     0,     0,   292,   296,   135,     0,    76,   301,     0,
       0,     0,     0,     0,   307,   311,   150,     0,   159,   316,
       0,     0,     0,   170,   175,     0,     0,    87,     0,    96,
       0,   188,     0,   197,     0,   108,   115,   123,   208,     0,
       0,     0,     0,     0,     0,     0,   327,     0,     0,   139,
     332,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   339,   163,     0,     0,   344,     0,   174,   179,     0,
       0,     0,   239,     0,     0,   192,     0,   201,     0,     0,
       0,    49,   212,   254,    51,     0,    52,    53,    54,    55,
       0,     0,     0,     0,     0,     0,   359,     0,     0,     0,
     364,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     289,   371,     0,    57,    58,   376,   243,    60,     0,     0,
       0,   304,     0,    63,     0,     0,     0,   258,     0,    79,
       0,     0,     0,    80,    81,     0,     0,     0,     0,     0,
      82,    60,     0,     0,     0,     0,     0,    57,    58,     0,
       0,     0,     0,     0,   293,    63,     0,     0,     0,    82,
       0,     0,     0,     2,     3,   308,     4,     5,     6,     7,
       0,     8,     9,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    11,     0,    12,    13,
       0,    15,    16,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      49,     1,     7,    49,     7,    18,    11,    19,    13,    14,
       1,    16,    17,    18,    19,    20,    21,    22,     1,     1,
      69,    70,    71,     1,    73,    74,    -1,    76,    77,    78,
      79,    77,    -1,    79,    83,    -1,    85,    86,    87,    -1,
      89,    90,    91,    92,    -1,    94,    95,    96,    -1,    49,
      -1,   100,   101,   102,   103,   104,    -1,   106,   107,   108,
     109,   110,   111,    -1,   113,   114,   115,    -1,   117,   118,
     119,    -1,   121,   122,   123,   124,    -1,   126,   127,    -1,
      -1,    -1,   131,   132,    -1,    -1,   135,    -1,   137,   138,
     139,    -1,   141,   142,    -1,    -1,    -1,   146,   147,    -1,
      -1,   150,    -1,   152,   153,   154,    -1,   156,   157,   158,
     159,    -1,   161,   162,   163,    -1,    -1,    -1,   167,   168,
     169,   170,    -1,   172,   173,   174,   175,    -1,   177,   178,
     179,    -1,   181,   182,    -1,    -1,    -1,   186,   187,   188,
      -1,   190,   191,   192,    -1,   194,   195,   196,   197,    -1,
     199,   200,   201,    -1,    -1,    -1,   205,   206,   207,   208,
      -1,   210,   211,   212,    11,    -1,    13,    14,    -1,   218,
     219,    -1,    -1,    -1,   223,   224,    19,    -1,    21,    22,
      -1,   230,   231,    -1,    -1,    -1,   235,   236,    -1,    -1,
     239,    -1,   241,   242,   243,    -1,   245,   246,    -1,    -1,
      -1,   250,   251,    -1,    -1,   254,    -1,   256,   257,   258,
      -1,   260,   261,    -1,    -1,    -1,   265,   266,    -1,   268,
     269,    -1,    -1,    -1,   273,   274,    -1,    -1,     1,    -1,
      -1,   280,   281,    -1,    -1,    -1,   285,   286,    -1,    -1,
     289,    49,   291,   292,   293,    -1,   295,   296,    -1,    -1,
      -1,   300,   301,    -1,    -1,   304,    -1,   306,   307,   308,
      -1,   310,   311,    71,    -1,    -1,   315,   316,    -1,    77,
      78,    79,    -1,    46,    -1,    -1,    49,   326,   327,    -1,
      -1,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,   338,
     339,    -1,    -1,    -1,   343,   344,   104,    -1,    -1,    -1,
      -1,   109,    -1,    49,    77,    78,    79,    -1,    -1,   358,
     359,   119,    -1,    -1,   363,   364,   124,    -1,    -1,    -1,
      -1,   370,   371,    69,    70,    71,   375,   376,    -1,    -1,
      76,    77,    78,    79,    -1,    -1,   109,    83,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    91,    92,    -1,    -1,    -1,
      96,   124,    -1,    -1,    -1,    -1,   102,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,    -1,    -1,    -1,   115,
      -1,   117,   118,   119,    -1,    -1,    -1,   123,   124,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,     7,   135,
      -1,    -1,    11,   139,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,   150,    -1,    -1,    -1,   154,    -1,
      -1,    -1,   158,   159,    -1,    -1,    17,   163,    19,    20,
      21,    22,    -1,   169,   170,    -1,    -1,    -1,   174,   175,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
     196,   197,    -1,    -1,    -1,   201,    49,    -1,    -1,    -1,
      -1,   207,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    -1,    -1,    -1,
      83,    -1,    -1,   239,    87,    -1,    -1,   243,    91,    92,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,   254,   102,
     103,   104,   258,    -1,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,   115,    -1,   117,   118,   119,    -1,    -1,    -1,
     123,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   289,    -1,    -1,   139,   293,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   304,    -1,
      -1,   154,   308,    49,    -1,   158,   159,    -1,    -1,    -1,
     163,    -1,    -1,    -1,    -1,    -1,   169,   170,    -1,    -1,
      -1,   174,   175,    69,    -1,    71,   179,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,   196,   197,    91,    -1,    49,   201,    -1,
      -1,    -1,    -1,    -1,   207,   208,   102,    -1,   104,   212,
      -1,    -1,    -1,   109,   110,    -1,    -1,    69,    -1,    71,
      -1,   117,    -1,   119,    -1,    77,    78,    79,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    91,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   254,   104,    -1,    -1,   258,    -1,   109,   110,    -1,
      -1,    -1,   158,    -1,    -1,   117,    -1,   119,    -1,    -1,
      -1,     1,   124,   169,     4,    -1,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,
     293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   304,    -1,    33,    34,   308,   158,    37,    -1,    -1,
      -1,   207,    -1,    43,    -1,    -1,    -1,   169,    -1,    49,
      -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,   196,    75,    -1,    -1,    -1,    79,
      -1,    -1,    -1,     0,     1,   207,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    11,    -1,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,     0,     1,     3,     4,     5,     6,     8,     9,
      10,    11,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    53,    53,    53,    53,    53,     7,    53,    53,    49,
      53,    41,    42,    53,    53,    42,     7,    37,    38,    39,
      40,    42,    43,    44,    45,    47,    48,    49,    50,    53,
      53,    53,    53,    40,    43,    44,    45,    48,    43,    44,
      45,    39,    40,    43,    44,    45,    48,    43,    43,    43,
      44,    45,    39,    40,    42,    43,    44,    45,    48,    50,
      39,    40,    43,    44,    45,    48,     7,    39,    40,    42,
      43,    44,    45,    48,    50,    43,    44,    45,    43,    43,
      43,    44,    45,    43,    43,    40,    43,    44,    45,    48,
      43,    44,    45,    43,    43,    43,    44,    45,    43,    43,
      40,    43,    44,    45,    48,    43,    44,    45,    39,    40,
      43,    44,    45,    48,    43,    43,    43,    44,    45,    39,
      40,    43,    44,    45,    48,    40,    43,    44,    45,    48,
      43,    44,    45,    43,    43,    43,    44,    45,    40,    43,
      44,    45,    48,    43,    44,    45,    39,    40,    43,    44,
      45,    48,    43,    43,    43,    44,    45,    39,    40,    43,
      44,    45,    48,    43,    43,    43,    43,    43,    44,    45,
      43,    43,    43,    44,    45,    43,    43,    43,    43,    43,
      44,    45,    43,    43,    43,    44,    45,    43,    43,    40,
      43,    44,    45,    48,    43,    44,    45,    43,    43,    43,
      44,    45,    43,    43,    40,    43,    44,    45,    48,    43,
      44,    45,    43,    43,    43,    44,    45,    43,    44,    45,
      43,    43,    43,    44,    45,    43,    43,    43,    43,    43,
      44,    45,    43,    43,    43,    44,    45,    43,    43,    40,
      43,    44,    45,    48,    43,    44,    45,    43,    43,    43,
      44,    45,    43,    43,    40,    43,    44,    45,    48,    43,
      44,    45,    43,    43,    43,    44,    45,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    44,    45,    43,    43,
      43,    44,    45,    43,    43,    43,    43,    43,    44,    45,
      43,    43,    43,    44,    45,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    44,    45,
      43,    43,    43,    44,    45,    43,    43,    43,    43,    43,
      44,    45,    43,    43,    43,    44,    45,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    25,    25,    25,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    42,    43,    44,
      45,    46,    47,    48,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      52,    53,    53,    53,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     3,     1,     3,     2,     1,
       1,     1,     1,     2,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     7,     6,
       6,     6,     6,     6,     6,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     7,     6,     6,     6,     6,     6,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     2,     7,     6,     6,     6,     6,     6,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       3,     3,     3,     3,     2,     7,     6,     6,     6,     6,
       5,     5,     5,     5,     5,     5,     4,     4,     4,     4,
       3,     7,     6,     6,     6,     6,     6,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     7,     6,     6,     6,     6,     5,     5,     5,
       5,     5,     5,     4,     4,     4,     4,     3,     7,     6,
       6,     6,     6,     5,     5,     5,     5,     5,     5,     4,
       4,     4,     4,     3,     7,     6,     6,     6,     5,     5,
       5,     4,     7,     6,     6,     6,     6,     6,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     3,
       3,     3,     3,     2,     7,     6,     6,     6,     6,     5,
       5,     5,     5,     5,     5,     4,     4,     4,     4,     3,
       7,     6,     6,     6,     6,     5,     5,     5,     5,     5,
       5,     4,     4,     4,     4,     3,     7,     6,     6,     6,
       5,     5,     5,     4,     7,     6,     6,     6,     6,     5,
       5,     5,     5,     5,     5,     4,     4,     4,     4,     3,
       7,     6,     6,     6,     5,     5,     5,     4,     7,     6,
       6,     6,     5,     5,     5,     4,     7,     6,     6,     5,
       3,     1,     1,     1,     2
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
        case 31:
#line 55 "shell.y" /* yacc.c:1646  */
    {
			cd_home_function();
		}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 60 "shell.y" /* yacc.c:1646  */
    {
			cd_function(textArray[getWords() - 1]);
		}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 66 "shell.y" /* yacc.c:1646  */
    {
			printenv_function();
		}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 71 "shell.y" /* yacc.c:1646  */
    {
			unsetenv_function(textArray[getWords() - 1], 1);
		}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 76 "shell.y" /* yacc.c:1646  */
    {
			setenv_function(textArray[getWords() - 2], textArray [getWords() - 1], 1);		
		}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 83 "shell.y" /* yacc.c:1646  */
    {
			alias_list_function();
		}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 88 "shell.y" /* yacc.c:1646  */
    {
			alias_function(textArray[getWords() - 2], textArray[getWords() - 1]);
		}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 93 "shell.y" /* yacc.c:1646  */
    {
			unalias_function(textArray[getWords() - 1]);
		}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 99 "shell.y" /* yacc.c:1646  */
    { 
			exit(0); //exit shell
		}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 105 "shell.y" /* yacc.c:1646  */
    {
							}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 109 "shell.y" /* yacc.c:1646  */
    {
								word_function("<");
							}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 114 "shell.y" /* yacc.c:1646  */
    {
								word_function(">");
							}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 119 "shell.y" /* yacc.c:1646  */
    {
							}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 123 "shell.y" /* yacc.c:1646  */
    {
							}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 127 "shell.y" /* yacc.c:1646  */
    {
								word_function("|");
							}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 132 "shell.y" /* yacc.c:1646  */
    {
								//printf("PIPE words\n");
								//pipe with a command name and more than one argument
							}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 137 "shell.y" /* yacc.c:1646  */
    {
								//printf("PIPE word_case\n");
								//pipe with a command name and no arguments
							}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 143 "shell.y" /* yacc.c:1646  */
    {
								word_function("&");
								printf ("Ampersand entered\n");
							}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 149 "shell.y" /* yacc.c:1646  */
    {
								word_function("2>&1");
							}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 154 "shell.y" /* yacc.c:1646  */
    {
								word_function(yytext);
							}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 159 "shell.y" /* yacc.c:1646  */
    {
								printf ("Syntax error.\n");
							}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 163 "shell.y" /* yacc.c:1646  */
    {
								word_function(">>");
							}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 168 "shell.y" /* yacc.c:1646  */
    {
								
							}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 173 "shell.y" /* yacc.c:1646  */
    {
								//printf("word_case word_case\n");
							}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 177 "shell.y" /* yacc.c:1646  */
    {
								//printf("words word_case\n");
							}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 182 "shell.y" /* yacc.c:1646  */
    {
								//printf("pipe_case pipe_case\n");
							}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 186 "shell.y" /* yacc.c:1646  */
    {
								//printf("pipes pipe_case\n");
							}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 191 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 195 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 199 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 203 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 207 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 211 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 215 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 219 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 223 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 227 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 231 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 235 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 239 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 243 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 247 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 251 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 255 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 259 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 263 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 267 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 271 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 275 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 279 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 283 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 287 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 291 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 295 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 299 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 303 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 307 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 311 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 315 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 319 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 323 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 327 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 331 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 335 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 339 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 343 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 347 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 351 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 355 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 359 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 363 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 367 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 371 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 375 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 379 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 383 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 387 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 391 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 395 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 399 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 403 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 407 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 411 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 415 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 419 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 423 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 427 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 431 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 435 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 439 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 443 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 447 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 451 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 455 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 459 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 463 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 467 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 471 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 475 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 479 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 483 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 487 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 491 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 495 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 499 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 503 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 507 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 511 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 515 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 519 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 523 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 527 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 531 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 535 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 539 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 543 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 547 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 551 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 555 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 559 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 563 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 567 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 571 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 575 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 579 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 583 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 587 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 591 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 595 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 599 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 603 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 607 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 611 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 615 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 619 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 623 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 627 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 631 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 635 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 639 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 643 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 647 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 651 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 655 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 659 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 663 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 667 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 671 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 675 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 679 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 683 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 687 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 691 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 695 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 699 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 703 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 707 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 711 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 715 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 719 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 723 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 727 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 731 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 735 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 739 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 743 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 747 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 751 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 2993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 755 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 759 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 763 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 767 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 771 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 775 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 779 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 783 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 787 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 791 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 795 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 799 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 803 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 807 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 811 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 815 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 819 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 823 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 827 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 831 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 835 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 839 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 843 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 847 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 851 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 855 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 859 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 863 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 867 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 871 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 875 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 879 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 883 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 887 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 891 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 895 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 899 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 903 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 907 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 911 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 915 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 919 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 923 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 927 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 931 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 935 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 939 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 943 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 947 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 951 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 955 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 959 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 963 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 967 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 971 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 975 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 979 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 983 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 987 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 991 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 995 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 999 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1003 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1007 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1011 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1015 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1019 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1023 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1027 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1031 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1035 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1039 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1043 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1047 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1051 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1055 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1059 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1063 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1067 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1071 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1075 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1079 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1083 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1087 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1091 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1095 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1099 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1103 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1107 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1111 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1115 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1119 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1123 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1127 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1131 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1135 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1139 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1143 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1147 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1151 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1155 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1159 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1163 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1167 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1171 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1175 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1179 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1183 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1187 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1191 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1195 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1199 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1203 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1207 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1211 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1215 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1219 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1223 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1227 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1231 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1235 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1239 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1243 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1247 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1251 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 3993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1255 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1259 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1263 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1267 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1271 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1275 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1279 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1283 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1287 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1291 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1295 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1299 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1303 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1307 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1311 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1315 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1319 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1323 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1327 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1331 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1335 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1339 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1343 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1347 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1351 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1355 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1359 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1363 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1367 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1371 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1375 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1379 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1383 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1387 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1391 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1395 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1399 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1403 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1407 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1411 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1415 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1419 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1423 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1427 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1431 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1435 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1439 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1443 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1447 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1451 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1455 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1459 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1463 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1467 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1471 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1475 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1480 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1485 "shell.y" /* yacc.c:1646  */
    {
								word2Function(yytext);
							}
#line 4457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1489 "shell.y" /* yacc.c:1646  */
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
#line 4493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1520 "shell.y" /* yacc.c:1646  */
    {
								quoteFunction(yytext);
							}
#line 4501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1525 "shell.y" /* yacc.c:1646  */
    {
			execute();
		}
#line 4509 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4513 "y.tab.c" /* yacc.c:1646  */
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
#line 1528 "shell.y" /* yacc.c:1906  */

