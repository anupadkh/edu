/* A Bison parser, made by GNU Bison 3.7.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>

	void yyerror(char *s);


	int label_count=0;                 /* Used for the creation of unique labels */
	int parameter_count;	           /* Used to track number of parameters of function read */
	int function_table_count=0;	   /* Holds the size of the function table */
	int function_table_index;	   /* Used for finding the index of a fucntion in table */
	int macro_table_count=0;	   /* Similar to functions for macros */
	int macro_table_index;	           /* Similar to Functions used for macros */		 

	char buffer[300];		   /* Temporary buffer to hold intermediate code  (written to file)*/


	void installid(char s[],int n);    /* Enter symbol and corresponding value to  the symbol table */
	int getid(char s[]);		   /* Get the value associated with  an identifier */
	void dis();			   /* Display the Symbol Table */
	int relop(int a, int b, int c);	   /* Performs relational operation and returns result */

	void installfunction(char str[],int x,int y);	/* Install function in the function table */
	int search_function(char str[]);		/* Search for a function in function table */ 
	void installmacro(char str[],int x);		/* Similar to functions */
	int search_macro(char str[]);			/* Similar to functions */




	 
	char reg[7][10]={"t1","t2","t3","t4","t5","t6"};   /* Temporaries for holding values for IR Code */


	extern FILE *yyout;  		/* Pointer to the output file */
	extern char *yylex();


	/* The Symbol Table containing name and value */
	struct table
	{
		char name[10];
		int val;
	} symbol[53];



	/* Function Table for storing info of fucntions like name , return type number of parameters */
	struct function
	{
		char name[30];
		int parameter_count;
		int returns;
	} function_table[53];

	
	/* Macro table for holding macros */
	struct macro_tab
	{
		char name[30];
		int parameter_count;

	} macro_table[53];




#line 140 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_id = 3,                         /* id  */
  YYSYMBOL_num = 4,                        /* num  */
  YYSYMBOL_print = 5,                      /* print  */
  YYSYMBOL_EXIT = 6,                       /* EXIT  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_ptable = 9,                     /* ptable  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_DEF = 11,                       /* DEF  */
  YYSYMBOL_comma = 12,                     /* comma  */
  YYSYMBOL_HASHDEF = 13,                   /* HASHDEF  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_and = 16,                       /* and  */
  YYSYMBOL_or = 17,                        /* or  */
  YYSYMBOL_18_ = 18,                       /* '>'  */
  YYSYMBOL_19_ = 19,                       /* '<'  */
  YYSYMBOL_eq = 20,                        /* eq  */
  YYSYMBOL_ne = 21,                        /* ne  */
  YYSYMBOL_ge = 22,                        /* ge  */
  YYSYMBOL_le = 23,                        /* le  */
  YYSYMBOL_24_ = 24,                       /* '?'  */
  YYSYMBOL_25_ = 25,                       /* ':'  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '%'  */
  YYSYMBOL_29_ = 29,                       /* '*'  */
  YYSYMBOL_30_ = 30,                       /* '/'  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* '='  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_start = 38,                     /* start  */
  YYSYMBOL_do_while = 39,                  /* do_while  */
  YYSYMBOL_condexp = 40,                   /* condexp  */
  YYSYMBOL_function_def = 41,              /* function_def  */
  YYSYMBOL_function_call = 42,             /* function_call  */
  YYSYMBOL_params = 43,                    /* params  */
  YYSYMBOL_while_statement = 44,           /* while_statement  */
  YYSYMBOL_condn = 45,                     /* condn  */
  YYSYMBOL_macro = 46,                     /* macro  */
  YYSYMBOL_macro_def = 47,                 /* macro_def  */
  YYSYMBOL_macro_call = 48,                /* macro_call  */
  YYSYMBOL_statement = 49,                 /* statement  */
  YYSYMBOL_print_statement = 50,           /* print_statement  */
  YYSYMBOL_assignment = 51,                /* assignment  */
  YYSYMBOL_exp = 52,                       /* exp  */
  YYSYMBOL_term = 53,                      /* term  */
  YYSYMBOL_procid = 54                     /* procid  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   439

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    28,     2,     2,
      35,    36,    29,    26,     2,    27,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,    31,
      19,    32,    18,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   199,   199,   200,   207,   215,   225,   234,   238,   241,
     245,   248,   251,   255,   259,   263,   266,   269,   272,   275,
     278,   281,   285,   288,   291,   294,   297,   300,   314,   322,
     347,   378,   397,   417,   441,   472,   477,   484,   493,   508,
     517,   535,   548,   568,   590,   595,   596,   597,   598,   599,
     600,   607,   611,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   634,   635,
     639
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "id", "num", "print",
  "EXIT", "IF", "ELSE", "ptable", "WHILE", "DEF", "comma", "HASHDEF",
  "RETURN", "DO", "and", "or", "'>'", "'<'", "eq", "ne", "ge", "le", "'?'",
  "':'", "'+'", "'-'", "'%'", "'*'", "'/'", "';'", "'='", "'{'", "'}'",
  "'('", "')'", "$accept", "start", "do_while", "condexp", "function_def",
  "function_call", "params", "while_statement", "condn", "macro",
  "macro_def", "macro_call", "statement", "print_statement", "assignment",
  "exp", "term", "procid", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    62,    60,
     273,   274,   275,   276,    63,    58,    43,    45,    37,    42,
      47,    59,    61,   123,   125,    40,    41
};
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-71)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      81,   -22,     5,   -14,    -6,     1,     9,    33,    61,    40,
       5,    28,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -17,    10,   -80,   -80,     5,   299,   -80,   -80,     5,
     -80,     5,   -80,    31,    70,    46,    62,    91,   -80,    53,
       5,    58,    64,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,    94,    94,    63,   315,    65,   131,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,   -80,   152,   173,    94,   -80,    94,    67,     5,   -80,
      62,    69,    62,    62,    77,    10,   331,   -80,   -80,    92,
      71,    79,   -80,    94,   -80,   409,   409,    50,    50,    50,
      50,    50,    50,    42,    42,    42,   -80,   -80,    73,    89,
      87,    88,     5,   347,   -80,   115,   -80,   -80,    93,   363,
     -80,    94,    95,    98,    96,    62,    62,    97,   101,   379,
     -80,   102,    21,   -80,   -80,   -80,   -80,   100,   104,   105,
      62,    62,   -80,     5,   108,     5,   -80,   128,   -80,    -7,
     107,   194,     5,   215,   110,     5,   -80,   -80,   113,   236,
     121,    62,   395,   -80,   130,   127,   122,   142,   129,   160,
     -80,   -80,   174,     5,   151,   257,     5,   153,   278,   -80,
     154,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    17,    11,    16,     9,     7,    21,    23,
      25,     0,     0,    69,    68,     0,     0,    53,     2,     0,
      13,     0,    70,     0,    70,     0,     0,     0,     1,    70,
       0,     0,     0,    20,    18,    12,    15,    10,     8,    22,
      24,    26,    35,    35,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,    35,    41,    35,     0,     0,    50,
      49,     0,    47,    46,     0,     0,     0,    27,    14,    37,
       0,     0,     5,    35,    65,    66,    67,    59,    60,    61,
      62,    63,    64,    54,    55,    58,    56,    57,     0,     0,
       0,     0,     0,     0,    48,     0,    45,    44,     0,     0,
       4,    35,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     6,    36,    43,    33,     0,     0,     0,
       0,     0,    52,     0,     0,     0,    34,    39,    38,     0,
       0,     0,     0,     0,     0,     0,    31,    42,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
      40,    32,     0,     0,     0,     0,     0,     0,     0,    30,
       0,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   175,   176,   186,   187,   -51,   193,    11,   195,
     196,   197,   -79,   -80,   -80,   -10,   -80,    -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    90,    16,    80,    18,
      19,    20,    81,    82,    83,    26,    27,    21
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,   114,    91,   116,   117,    33,    35,   155,    23,    24,
      22,    17,    55,    54,    24,    57,    52,    28,    53,    72,
      56,    73,    48,   110,   144,   111,   145,   156,    38,    29,
      86,    39,    30,    40,    41,     4,    32,    42,     6,     7,
      25,     8,   124,     9,    31,    25,   138,   139,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   149,   150,    10,    34,    77,    74,    78,   113,     4,
     134,    69,    70,    36,    75,   119,    66,    67,    68,    69,
      70,    76,   166,    56,     1,    85,     2,     3,     4,    87,
       5,     6,     7,    79,     8,    88,     9,    89,   -70,   112,
      93,   118,   129,   115,   121,   122,   125,    58,    59,    60,
      61,    62,    63,    64,    65,   123,    10,    66,    67,    68,
      69,    70,   126,   127,   128,   131,   135,    84,   132,   136,
     140,   146,   137,   151,   141,   153,   154,   143,   147,   148,
     152,   157,   159,   161,   163,   162,   165,    58,    59,    60,
      61,    62,    63,    64,    65,   168,   170,    66,    67,    68,
      69,    70,   169,   175,   172,   173,   178,    94,    58,    59,
      60,    61,    62,    63,    64,    65,   171,   174,    66,    67,
      68,    69,    70,   176,   179,   181,    43,    44,   108,    58,
      59,    60,    61,    62,    63,    64,    65,    45,    46,    66,
      67,    68,    69,    70,    47,     0,    49,    50,    51,   109,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
      66,    67,    68,    69,    70,     0,     0,     0,     0,     0,
     158,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,     0,
       0,   160,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,    66,    67,    68,    69,    70,     0,     0,     0,
       0,     0,   164,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,     0,     0,   177,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,    66,    67,    68,    69,    70,     0,
       0,     0,     0,     0,   180,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,    66,    67,    68,    69,    70,
      71,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    66,    67,    68,    69,    70,    92,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,    66,    67,    68,
      69,    70,   120,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,    66,    67,    68,    69,    70,   130,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,    66,
      67,    68,    69,    70,   133,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,    66,    67,    68,    69,    70,
     142,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    66,    67,    68,    69,    70,   167,    60,    61,    62,
      63,    64,    65,     0,     0,    66,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
      10,    80,    53,    82,    83,     7,     8,    14,     3,     4,
      32,     0,    22,     3,     4,    25,    33,    31,    35,    29,
      22,    31,    11,    74,     3,    76,     5,    34,     0,    35,
      40,     3,    31,     5,     6,     7,     3,     9,    10,    11,
      35,    13,    93,    15,    35,    35,   125,   126,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,   140,   141,    35,     3,     3,    35,     5,    78,     7,
     121,    29,    30,    33,     4,    85,    26,    27,    28,    29,
      30,    35,   161,    85,     3,    32,     5,     6,     7,    31,
       9,    10,    11,    31,    13,    31,    15,     3,    35,    32,
      35,    24,   112,    34,    12,    34,    33,    16,    17,    18,
      19,    20,    21,    22,    23,    36,    35,    26,    27,    28,
      29,    30,    33,    36,    36,    10,    31,    36,    35,    31,
      33,    31,    36,   143,    33,   145,     8,    35,    34,    34,
      32,    34,   152,    33,    31,   155,    25,    16,    17,    18,
      19,    20,    21,    22,    23,    25,    34,    26,    27,    28,
      29,    30,    35,   173,    35,     5,   176,    36,    16,    17,
      18,    19,    20,    21,    22,    23,    34,     3,    26,    27,
      28,    29,    30,    32,    31,    31,    11,    11,    36,    16,
      17,    18,    19,    20,    21,    22,    23,    11,    11,    26,
      27,    28,    29,    30,    11,    -1,    11,    11,    11,    36,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      36,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    36,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    36,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    36,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    36,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    27,    28,    29,    30,
      31,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    26,    27,    28,    29,    30,    31,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,    27,    28,
      29,    30,    31,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    30,    31,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    26,
      27,    28,    29,    30,    31,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    27,    28,    29,    30,
      31,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    26,    27,    28,    29,    30,    31,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    27,    28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     9,    10,    11,    13,    15,
      35,    38,    39,    40,    41,    42,    44,    45,    46,    47,
      48,    54,    32,     3,     4,    35,    52,    53,    31,    35,
      31,    35,     3,    54,     3,    54,    33,    52,     0,     3,
       5,     6,     9,    39,    40,    41,    42,    44,    45,    46,
      47,    48,    33,    35,     3,    52,    54,    52,    16,    17,
      18,    19,    20,    21,    22,    23,    26,    27,    28,    29,
      30,    31,    52,    52,    35,     4,    35,     3,     5,    31,
      45,    49,    50,    51,    36,    32,    52,    31,    31,     3,
      43,    43,    31,    35,    36,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    36,    36,
      43,    43,    32,    52,    49,    34,    49,    49,    24,    52,
      31,    12,    34,    36,    43,    33,    33,    36,    36,    52,
      31,    10,    35,    31,    43,    31,    31,    36,    49,    49,
      33,    33,    31,    35,     3,     5,    31,    34,    34,    49,
      49,    52,    32,    52,     8,    14,    34,    34,    36,    52,
      36,    33,    52,    31,    36,    25,    49,    31,    25,    35,
      34,    34,    35,     5,     3,    52,    32,    36,    52,    31,
      36,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    39,    40,
      40,    41,    41,    42,    42,    43,    43,    43,    44,    45,
      45,    46,    47,    48,    49,    49,    49,    49,    49,    49,
      49,    50,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     4,     4,     5,     1,     2,     1,
       2,     1,     2,     2,     3,     2,     1,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     3,     9,    16,
      14,     8,    11,     5,     7,     0,     3,     1,     7,     7,
      11,     3,     8,     5,     2,     2,     1,     1,     2,     1,
       1,     3,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* start: EXIT ';'  */
#line 199 "parser.y"
                                {	exit(0);	}
#line 1336 "parser.tab.c"
    break;

  case 3: /* start: print exp ';'  */
#line 200 "parser.y"
                                { 
					printf("Printing: %d\n",(yyvsp[-1].no));
					sprintf(buffer,"%s := %d;"
						       "\nprint %s;\n" ,
						reg[0],(yyvsp[-1].no),reg[0]);
					fprintf(yyout,"%s\n" , buffer);
				}
#line 1348 "parser.tab.c"
    break;

  case 4: /* start: start print exp ';'  */
#line 207 "parser.y"
                                { 
					printf("Printing: %d\n",(yyvsp[-1].no)); 
					sprintf(buffer,"%s := %d;"
						       "\nprint %s;\n" ,
						reg[0],(yyvsp[-1].no),reg[0]);

					fprintf(yyout,"%s\n" , buffer); 
				}
#line 1361 "parser.tab.c"
    break;

  case 5: /* start: id '=' exp ';'  */
#line 215 "parser.y"
                                { 
					 {installid((yyvsp[-3].var),(yyvsp[-1].no));}
					
					 sprintf(buffer,"%s := %d;"
							"\n %s := %s;\n" ,
							reg[0],(yyvsp[-1].no),(yyvsp[-3].var),reg[0]);

					 fprintf(yyout,"%s\n" , buffer); 
				}
#line 1375 "parser.tab.c"
    break;

  case 6: /* start: start id '=' exp ';'  */
#line 225 "parser.y"
                                { 
					 {installid((yyvsp[-3].var),(yyvsp[-1].no));} 
					 sprintf(buffer,"%s := %d;"
							"\n %s := %s;\n" ,
							reg[0],(yyvsp[-1].no),(yyvsp[-3].var),reg[0]);

					 fprintf(yyout,"%s\n" , buffer);
				}
#line 1388 "parser.tab.c"
    break;

  case 7: /* start: condn  */
#line 234 "parser.y"
                                { 
					 fprintf(yyout,"%s\n" , (yyvsp[0].code)); 
				}
#line 1396 "parser.tab.c"
    break;

  case 8: /* start: start condn  */
#line 238 "parser.y"
                                { 
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1404 "parser.tab.c"
    break;

  case 9: /* start: while_statement  */
#line 241 "parser.y"
                                { 
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1412 "parser.tab.c"
    break;

  case 10: /* start: start while_statement  */
#line 245 "parser.y"
                                { 	 
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1420 "parser.tab.c"
    break;

  case 11: /* start: function_def  */
#line 248 "parser.y"
                                {  
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1428 "parser.tab.c"
    break;

  case 12: /* start: start function_def  */
#line 251 "parser.y"
                                {
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1436 "parser.tab.c"
    break;

  case 13: /* start: ptable ';'  */
#line 255 "parser.y"
                                { 		
					 dis();
				}
#line 1444 "parser.tab.c"
    break;

  case 14: /* start: start ptable ';'  */
#line 259 "parser.y"
                                { 
					 dis();
				}
#line 1452 "parser.tab.c"
    break;

  case 15: /* start: start function_call  */
#line 263 "parser.y"
                                {
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1460 "parser.tab.c"
    break;

  case 16: /* start: function_call  */
#line 266 "parser.y"
                                { 
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1468 "parser.tab.c"
    break;

  case 17: /* start: condexp  */
#line 269 "parser.y"
                                {
					;
				}
#line 1476 "parser.tab.c"
    break;

  case 18: /* start: start condexp  */
#line 272 "parser.y"
                                {
					;
				}
#line 1484 "parser.tab.c"
    break;

  case 19: /* start: do_while  */
#line 275 "parser.y"
                                {
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1492 "parser.tab.c"
    break;

  case 20: /* start: start do_while  */
#line 278 "parser.y"
                                {
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1500 "parser.tab.c"
    break;

  case 21: /* start: macro  */
#line 281 "parser.y"
                                { 
					 fprintf(yyout,"%s\n" , (yyvsp[0].code)); 

				}
#line 1509 "parser.tab.c"
    break;

  case 22: /* start: start macro  */
#line 285 "parser.y"
                                { 
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1517 "parser.tab.c"
    break;

  case 23: /* start: macro_def  */
#line 288 "parser.y"
                                {  
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
			        }
#line 1525 "parser.tab.c"
    break;

  case 24: /* start: start macro_def  */
#line 291 "parser.y"
                                {
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1533 "parser.tab.c"
    break;

  case 25: /* start: macro_call  */
#line 294 "parser.y"
                                {  
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
			        }
#line 1541 "parser.tab.c"
    break;

  case 26: /* start: start macro_call  */
#line 297 "parser.y"
                                { 
					 fprintf(yyout,"%s\n" , (yyvsp[0].code));
				}
#line 1549 "parser.tab.c"
    break;

  case 27: /* start: start EXIT ';'  */
#line 300 "parser.y"
                                {

			
					 exit(EXIT_SUCCESS);
		
		
				}
#line 1561 "parser.tab.c"
    break;

  case 28: /* do_while: DO '{' statement '}' WHILE '(' exp ')' ';'  */
#line 315 "parser.y"
                                {	

					  sprintf(buffer, "\n%d_LABEL:\n%s\n if nz goto %d_LABEL\n",label_count,(yyvsp[-6].code),label_count);
					  label_count+=1;
					  strcpy((yyval.code),buffer);
				}
#line 1572 "parser.tab.c"
    break;

  case 29: /* condexp: '(' exp ')' '?' '(' id '=' exp ')' ':' '(' id '=' exp ')' ';'  */
#line 323 "parser.y"
                                {
       					  if((yyvsp[-14].no)>0)
					  {
						installid((yyvsp[-10].var),(yyvsp[-8].no));
					  }
					  else
					  { 
						installid((yyvsp[-4].var),(yyvsp[-2].no));
					  } 
					  fprintf(yyout,"if z %s goto %d_LABEL:;" 
							"\n%s := %d;"
							"\n%s := %s;"
							"\n goto %d_LABEL:"
							"\n %d_LABEL :"
							"\n %s := %d;"
							"\n%s := %s;"
							"\n%d_LABEL:\n" ,
						reg[0],label_count,reg[1],
						(yyvsp[-8].no),(yyvsp[-10].var),reg[1],(label_count+1),label_count,reg[2],
						(yyvsp[-2].no),(yyvsp[-4].var),reg[2],(label_count+1)); ; 

					 label_count+=2; 
				}
#line 1600 "parser.tab.c"
    break;

  case 30: /* condexp: '(' exp ')' '?' '(' print exp ')' ':' '(' print exp ')' ';'  */
#line 348 "parser.y"
                                { 
					 if((yyvsp[-12].no)>0)
					 {
						printf("Printing: %d\n",(yyvsp[-7].no));
					 }
					 else
					 {
						printf("Printing: %d\n",(yyvsp[-2].no));
					 }    
					 fprintf(yyout,"if z %s goto %d_LABEL:"
							"\n%s := %d;"
							"\nprint %s;"
							"\ngoto %d_LABEL: "
							"\n%d_LABEL : "
							"\n%s := %d;"
							"\nprint %s;"
							"\n%d_LABEL:\n" ,
						 reg[0],label_count,reg[1],(yyvsp[-7].no),
						 reg[1],(label_count+1),label_count,
						 reg[2],(yyvsp[-2].no),reg[2],(label_count+1));;
					 label_count+=2;
				 }
#line 1627 "parser.tab.c"
    break;

  case 31: /* function_def: DEF procid '(' params ')' '{' statement '}'  */
#line 379 "parser.y"
                                {
	
					 if(search_function((yyvsp[-6].var))!=-1) 
					 { 
						printf("Error Duplicate Function\n");
						exit(0);
					 } 
	  

					sprintf(buffer,"PROCEDURE %s  %s"
						       " \n %s "
						       "\n ENDP",

						       (yyvsp[-6].var),(yyvsp[-4].code),(yyvsp[-1].code));
	  			        strcpy((yyval.code),buffer);
					installfunction((yyvsp[-6].var),parameter_count,0);
		
	 		        }
#line 1650 "parser.tab.c"
    break;

  case 32: /* function_def: DEF procid '(' params ')' '{' statement RETURN exp ';' '}'  */
#line 398 "parser.y"
                                {
	
	 				if(search_function((yyvsp[-9].var))!=-1) 
					{
						 printf("Error Duplicate Function\n");
						 exit(0);
					 } 
	  
					sprintf(buffer,"PROCEDURE %s  %s \n %s \n ENDP",(yyvsp[-9].var),(yyvsp[-7].code),(yyvsp[-4].code));
	 				strcpy((yyval.code),buffer);
	  				installfunction((yyvsp[-9].var),parameter_count,1);
	 			 }
#line 1667 "parser.tab.c"
    break;

  case 33: /* function_call: procid '(' params ')' ';'  */
#line 418 "parser.y"
                                {

					function_table_index = search_function((yyvsp[-4].var));
					if(function_table_index==-1)
					{
						printf("Error Function not defined");
						exit(0);
					}
					if(function_table[function_table_index].parameter_count!=parameter_count)
					{
						printf("Insufficient number of arguments for function : %s\n",(yyvsp[-4].var));
						exit(0);
					}
					if(function_table[function_table_index].returns==1)
					{
						printf("\n Function %s does has  a return type\n",(yyvsp[-4].var));
						exit(0);
					}

					sprintf(buffer," %s(%s)",(yyvsp[-4].var),(yyvsp[-2].code));
					strcpy((yyval.code),buffer);
				}
#line 1694 "parser.tab.c"
    break;

  case 34: /* function_call: id '=' procid '(' params ')' ';'  */
#line 442 "parser.y"
                                {


					function_table_index = search_function((yyvsp[-4].var));
					if(function_table_index==-1)
					{
					        printf("Error Function not defined");
						exit(0);
					}
					if(function_table[function_table_index].parameter_count!=parameter_count)
					{
						printf("Insufficient number of arguments for function : %s\n",(yyvsp[-4].var));
						exit(0);
					}
					if(function_table[function_table_index].returns==0)
					{
						printf("\n Function %s does not have  a return type\n",(yyvsp[-4].var));
						exit(0);
					}

					sprintf(buffer,"%s :=  %s(%s)",(yyvsp[-6].var),(yyvsp[-4].var),(yyvsp[-2].code));
					strcpy((yyval.code),buffer);
				}
#line 1722 "parser.tab.c"
    break;

  case 35: /* params: %empty  */
#line 472 "parser.y"
                                { 
       					strcpy((yyval.code)," ");
					parameter_count=0;
				}
#line 1731 "parser.tab.c"
    break;

  case 36: /* params: id comma params  */
#line 477 "parser.y"
                                {
					 strcat((yyvsp[-2].var),",");
					 strcat((yyvsp[-2].var),(yyvsp[0].code));
					 strcpy((yyval.code),(yyvsp[-2].var));
					 parameter_count+=1;
				}
#line 1742 "parser.tab.c"
    break;

  case 37: /* params: id  */
#line 484 "parser.y"
                                {
					 strcpy((yyval.code),(yyvsp[0].var)); 
					 parameter_count=1;
				}
#line 1751 "parser.tab.c"
    break;

  case 38: /* while_statement: WHILE '(' exp ')' '{' statement '}'  */
#line 494 "parser.y"
                                { 
					 sprintf(buffer,"%d_LABEL : IF NZ GOTO %d_LABEL"
							"\n %s\n JMP %d_LABEL"
							"\n %d_LABEL:\n" ,
					
							label_count,(label_count+1) ,(yyvsp[-1].code),
							label_count,(label_count+1));
					 strcpy((yyval.code),buffer);
					 ++label_count;
					 ++label_count;
				}
#line 1767 "parser.tab.c"
    break;

  case 39: /* condn: IF '(' exp ')' '{' statement '}'  */
#line 509 "parser.y"
                                { 
					sprintf(buffer,"IF NZ GO TO %dLABEL:"
						       "\n%s%dLABEL:" ,
			
						       label_count,(yyvsp[-1].code) , label_count);
					 strcpy((yyval.code),buffer); 
					 ++label_count;
				}
#line 1780 "parser.tab.c"
    break;

  case 40: /* condn: IF '(' exp ')' '{' statement '}' ELSE '{' statement '}'  */
#line 518 "parser.y"
                                { 
				        sprintf(buffer,"IF NZ GO TO %d_LABEL:"
						       "\n %s "
						       "\n JMP %d_LABEL "
						       "\n %d_LABEL:%s"
						       "\n%d_LABEL" ,
						  label_count,(yyvsp[-5].code) , (label_count+1) ,
						  label_count,(yyvsp[-1].code),(label_count+1));
					 strcpy((yyval.code),buffer);
					 ++label_count; 
					 ++label_count;
				}
#line 1797 "parser.tab.c"
    break;

  case 41: /* macro: HASHDEF id num  */
#line 536 "parser.y"
                                { 
      				         {installid((yyvsp[-1].var),(yyvsp[0].no));} 
					 sprintf(buffer,"%s := %d;"
							"\n%s := %s;\n" ,
						
							reg[0],(yyvsp[0].no),(yyvsp[-1].var),reg[0]  );

					 strcpy((yyval.code),buffer);
				 }
#line 1811 "parser.tab.c"
    break;

  case 42: /* macro_def: HASHDEF procid '(' params ')' '{' statement '}'  */
#line 549 "parser.y"
                                 {
	
	 				 if(search_macro((yyvsp[-6].var))!=-1)
					 {
						 printf("Error Duplicate Macro\n");
						 exit(0);
					 } 
	  

					sprintf(buffer,"MACRO %s  %s"
						       " \n %s"
						       "\nMEND" ,
						      (yyvsp[-6].var),(yyvsp[-4].code),(yyvsp[-1].code));
	 				strcpy((yyval.code),buffer);
					installmacro((yyvsp[-6].var),parameter_count);
		
	 			 }
#line 1833 "parser.tab.c"
    break;

  case 43: /* macro_call: procid '{' params '}' ';'  */
#line 569 "parser.y"
                                 {

					macro_table_index = search_macro((yyvsp[-4].var));
					if(macro_table_index==-1)
					{
						printf("Error Macro not defined");
						exit(0);
					}
					if(macro_table[macro_table_index].parameter_count!=parameter_count)
					{
						printf("Insufficient number of arguments for macro : %s\n",(yyvsp[-4].var));
						exit(0);
					}

					sprintf(buffer," %s(%s)",(yyvsp[-4].var),(yyvsp[-2].code));
					strcpy((yyval.code),buffer);
				}
#line 1855 "parser.tab.c"
    break;

  case 44: /* statement: assignment statement  */
#line 591 "parser.y"
                                { 
					 strcat((yyvsp[-1].code),(yyvsp[0].code));
					 strcpy((yyval.code),(yyvsp[-1].code));
			        }
#line 1864 "parser.tab.c"
    break;

  case 45: /* statement: print_statement statement  */
#line 595 "parser.y"
                                                    {  strcat((yyvsp[-1].code),(yyvsp[0].code));  strcpy((yyval.code),(yyvsp[-1].code)); }
#line 1870 "parser.tab.c"
    break;

  case 46: /* statement: assignment  */
#line 596 "parser.y"
                                                        { { strcpy((yyval.code),(yyvsp[0].code)); } }
#line 1876 "parser.tab.c"
    break;

  case 47: /* statement: print_statement  */
#line 597 "parser.y"
                                          { {strcpy((yyval.code),(yyvsp[0].code));} }
#line 1882 "parser.tab.c"
    break;

  case 48: /* statement: condn statement  */
#line 598 "parser.y"
                                          {  strcat((yyvsp[-1].code),(yyvsp[0].code)); strcpy((yyval.code),(yyvsp[-1].code)); }
#line 1888 "parser.tab.c"
    break;

  case 49: /* statement: condn  */
#line 599 "parser.y"
                                                { { strcpy((yyval.code),(yyvsp[0].code)); } }
#line 1894 "parser.tab.c"
    break;

  case 50: /* statement: ';'  */
#line 600 "parser.y"
                             { strcpy((yyval.code),"");	}
#line 1900 "parser.tab.c"
    break;

  case 51: /* print_statement: print exp ';'  */
#line 607 "parser.y"
                                {  sprintf(buffer,"%s := %d;\nprint %s;\n",reg[0],(yyvsp[-1].no),reg[0]); strcpy((yyval.code),buffer);  }
#line 1906 "parser.tab.c"
    break;

  case 52: /* assignment: id '=' exp ';'  */
#line 611 "parser.y"
                            { {installid((yyvsp[-3].var),(yyvsp[-1].no));} sprintf(buffer,"%s := %d;\n%s := %s;\n",reg[0],(yyvsp[-1].no),(yyvsp[-3].var),reg[0]); strcpy((yyval.code),buffer); }
#line 1912 "parser.tab.c"
    break;

  case 53: /* exp: term  */
#line 615 "parser.y"
                               { {(yyval.no) = (yyvsp[0].no);}                    /*fprintf(yyout,"%s := %d;\n ",reg[0],$1);*/ ; }
#line 1918 "parser.tab.c"
    break;

  case 54: /* exp: exp '+' exp  */
#line 616 "parser.y"
                               { {(yyval.no) = (yyvsp[-2].no) + (yyvsp[0].no);}               /*fprintf(yyout,"%s := %d + %d;\n ",reg[0],$1,$3);*/ ; }
#line 1924 "parser.tab.c"
    break;

  case 55: /* exp: exp '-' exp  */
#line 617 "parser.y"
                               { {(yyval.no) = (yyvsp[-2].no) - (yyvsp[0].no);}               /*fprintf(yyout,"%s := %d - %d;\n ",reg[0],$1,$3);*/ ; }
#line 1930 "parser.tab.c"
    break;

  case 56: /* exp: exp '*' exp  */
#line 618 "parser.y"
                               { {(yyval.no) = (yyvsp[-2].no) * (yyvsp[0].no);}               /*fprintf(yyout,"%s := %d * %d;\n ",reg[0],$1,$3);*/ ; }
#line 1936 "parser.tab.c"
    break;

  case 57: /* exp: exp '/' exp  */
#line 619 "parser.y"
                               { {(yyval.no) = (yyvsp[-2].no) / (yyvsp[0].no);}               /*fprintf(yyout,"%s := %d / %d;\n ",reg[0],$1,$3);*/ ; }
#line 1942 "parser.tab.c"
    break;

  case 58: /* exp: exp '%' exp  */
#line 620 "parser.y"
                                { {(yyval.no)= (yyvsp[-2].no) % (yyvsp[0].no);}}
#line 1948 "parser.tab.c"
    break;

  case 59: /* exp: exp '>' exp  */
#line 621 "parser.y"
                                { {(yyval.no) =relop((yyvsp[-2].no),(yyvsp[0].no),1);}        /*fprintf(yyout,"%s := %c > %d;\n ",reg[0],$1,$3); */; }
#line 1954 "parser.tab.c"
    break;

  case 60: /* exp: exp '<' exp  */
#line 622 "parser.y"
                                { {(yyval.no) =relop((yyvsp[-2].no),(yyvsp[0].no),2);}        /*fprintf(yyout,"%s := %c < %d;\n ",reg[0],$1,$3); */; }
#line 1960 "parser.tab.c"
    break;

  case 61: /* exp: exp eq exp  */
#line 623 "parser.y"
                                { {(yyval.no) =relop((yyvsp[-2].no),(yyvsp[0].no),3);}        /*fprintf(yyout,"%s := %c eq %d;\n ",reg[0],$1,$3); */;}
#line 1966 "parser.tab.c"
    break;

  case 62: /* exp: exp ne exp  */
#line 624 "parser.y"
                                { {(yyval.no) =relop((yyvsp[-2].no),(yyvsp[0].no),4);}	       /*fprintf(yyout,"%s := %c neq %d;\n ",reg[0],$1,$3); */;}
#line 1972 "parser.tab.c"
    break;

  case 63: /* exp: exp ge exp  */
#line 625 "parser.y"
                                { {(yyval.no) =relop((yyvsp[-2].no),(yyvsp[0].no),5);}	       /*fprintf(yyout,"%s := %c ge %d;\n ",reg[0],$1,$3); */;}
#line 1978 "parser.tab.c"
    break;

  case 64: /* exp: exp le exp  */
#line 626 "parser.y"
                                { {(yyval.no) =relop((yyvsp[-2].no),(yyvsp[0].no),6);}        /*fprintf(yyout,"%s := %c le %d;\n ",reg[0],$1,$3); */;}
#line 1984 "parser.tab.c"
    break;

  case 65: /* exp: '(' exp ')'  */
#line 627 "parser.y"
                                { {(yyval.no) = (yyvsp[-1].no);}                   /*fprintf(yyout,"%s := %d;\n ",reg[0],$2); */;}
#line 1990 "parser.tab.c"
    break;

  case 66: /* exp: exp and exp  */
#line 628 "parser.y"
                                { {(yyval.no) =relop((yyvsp[-2].no),(yyvsp[0].no),7);}        /*fprintf(yyout,"%s := %c and %d;\n ",reg[0],$1,$3);*/ ;}
#line 1996 "parser.tab.c"
    break;

  case 67: /* exp: exp or exp  */
#line 629 "parser.y"
                                { {(yyval.no) =relop((yyvsp[-2].no),(yyvsp[0].no),8);}        /*fprintf(yyout,"%s := %c or %d;\n ",reg[0],$1,$3);*/ ;}
#line 2002 "parser.tab.c"
    break;

  case 68: /* term: num  */
#line 634 "parser.y"
                             {(yyval.no) = (yyvsp[0].no);}
#line 2008 "parser.tab.c"
    break;

  case 69: /* term: id  */
#line 635 "parser.y"
                                {(yyval.no)=getid((yyvsp[0].var));}
#line 2014 "parser.tab.c"
    break;

  case 70: /* procid: id  */
#line 640 "parser.y"
         {
      		 strcpy((yyval.var),(yyvsp[0].var));
	 }
#line 2022 "parser.tab.c"
    break;


#line 2026 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 644 "parser.y"



			/*         END OF RULES SECTION		 */





	/*  FOR PERFORMING RELATIONAL OPERATIONS */

int relop(int a , int b ,int op)
{
	switch(op)
	{
		case 1:if(a>b){return 1;} else{return 0;} break;
		case 2:if(a<b){return 1;} else{return 0;} break;
		case 3:if(a==b){return 1;} else{return 0;} break;
		case 4:if(a!=b){return 1;} else{return 0;} break;
		case 5:if(a>=b){return 1;} else{return 0;} break;
		case 6:if(a<=b){return 1;} else{return 0;} break;
		case 7:if(a>0 && b>0 ){return 1;}else{return 0;}break;
		case 8:if(a>0 || b>0 ){return 1;}else{return 0;}break;
	}
}


	/* FOR DISPLAYING THE SYMBOL TABLE */

void dis()
{
	int i;
	printf("index\tvar\tval\n");
	for(i=0;i<53;i++)
	{
 		if(symbol[i].val!=-101)
 			printf("%d\t%s\t%d\n",i,symbol[i].name,symbol[i].val);
	}
}




	/* INSTALLING FUCNTION IN THE FUNCTION TABLE */


void installfunction(char str[],int x,int y)
{
	strcpy(function_table[function_table_count].name , str);
	function_table[function_table_count].parameter_count=x;
	function_table[function_table_count].returns=y;
	++function_table_count;	
}



	/* FOR SEARCHING IN THE FUNCTION TABLE */


int search_function(char str[])
{
	for(int i=0;i<function_table_count;++i)
	{
		if(strcmp(function_table[i].name,str)==0)
		{
			return i;
		}
		
	}
	return -1;
}


	/* FOR INSERTING INTO THE MACRO TABLE */

void installmacro(char str[],int x)
{
	strcpy(macro_table[macro_table_count].name , str);
	macro_table[macro_table_count].parameter_count=x;
	++macro_table_count;	
}



	/* FOR SEARCHING THE MACRO IN THE MACRO TABLE */ 

int search_macro(char str[])
{
	for(int i=0;i<macro_table_count;++i)
	{
		if(strcmp(macro_table[i].name,str)==0)
		{
			return i;
		}
		
	}
	return -1;
}




	/*  FOR INSERTING VALUE INTO THE SYMBOL TABLE   */
void installid(char str[],int n)
{
	int index,i;
	index=str[0]%53;
	i=index;
	if(strcmp(str,symbol[i].name)==0||symbol[i].val==-101)
	{
		symbol[index].val=n;
		strcpy(symbol[index].name,str);
	}
	else
	{
		i=(i+1)%53;
 		while(i!=index)
		{
			if(strcmp(str,symbol[i].name)==0||symbol[i].val==-101)
			{
				symbol[i].val=n;
				strcpy(symbol[i].name,str);
				break;
			}
			i=(i+1)%53;
		}
	}

}


	/*  For Obtaining the values from identifiers */ 
int getid(char str[])
{
	int index,i;
	index=str[0]%53;
	i=index;
	if(strcmp(str,symbol[index].name)==0)
	{
		return(symbol[index].val);
	}
	else
	{
		i=(i+1)%53;
 		while(i!=index)
		{
			if(strcmp(str,symbol[i].name)==0)
			{
				return (symbol[i].val);
				break;
			}
			i=(i+1)%53;
		}
		if(i==index)
		{
			printf("not initialised.");
		}
	}

}



	/*  	Error  		*/

void yyerror (char *s) 
{
	fprintf (stdout, "%s\n", s);
} 


int main()
{

	int i;


	/*  Initialising the Symbol Table */

 	for(i=0;i<53;i++)
	{
		symbol[i].val=-101;
		strcpy(function_table[i].name,"");
	}

	yyout = fopen("output.txt","a");
	
	/* if(yyout==NULL)
	{
		printf("error!!");
	}
	else
	{
		printf("file opened");
	} */


	//fprintf(yyout,"%s",reg[0]);
	//fprintf("\n%s",ftell(yyout));


 	return yyparse();

}
