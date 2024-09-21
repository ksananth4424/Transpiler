/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

#include <stdio.h>
#include "lex.yy.c"

#line 76 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    CONSTANT = 259,                /* CONSTANT  */
    OR = 260,                      /* OR  */
    AND = 261,                     /* AND  */
    NOT = 262,                     /* NOT  */
    LE_OP = 263,                   /* LE_OP  */
    GE_OP = 264,                   /* GE_OP  */
    NE_OP = 265,                   /* NE_OP  */
    EQ_OP = 266,                   /* EQ_OP  */
    FORWARD_ACCESS = 267,          /* FORWARD_ACCESS  */
    BACKWARD_ACCESS = 268,         /* BACKWARD_ACCESS  */
    INT = 269,                     /* INT  */
    FLOAT = 270,                   /* FLOAT  */
    BIG = 271,                     /* BIG  */
    SMALL = 272,                   /* SMALL  */
    CONST = 273,                   /* CONST  */
    VOID = 274,                    /* VOID  */
    SET = 275,                     /* SET  */
    ELSE = 276,                    /* ELSE  */
    SIZE = 277,                    /* SIZE  */
    LOOP = 278,                    /* LOOP  */
    FINALLY = 279,                 /* FINALLY  */
    RETURN = 280,                  /* RETURN  */
    FUNC = 281,                    /* FUNC  */
    PRINT = 282                    /* PRINT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define CONSTANT 259
#define OR 260
#define AND 261
#define NOT 262
#define LE_OP 263
#define GE_OP 264
#define NE_OP 265
#define EQ_OP 266
#define FORWARD_ACCESS 267
#define BACKWARD_ACCESS 268
#define INT 269
#define FLOAT 270
#define BIG 271
#define SMALL 272
#define CONST 273
#define VOID 274
#define SET 275
#define ELSE 276
#define SIZE 277
#define LOOP 278
#define FINALLY 279
#define RETURN 280
#define FUNC 281
#define PRINT 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_OR = 5,                         /* OR  */
  YYSYMBOL_AND = 6,                        /* AND  */
  YYSYMBOL_NOT = 7,                        /* NOT  */
  YYSYMBOL_LE_OP = 8,                      /* LE_OP  */
  YYSYMBOL_GE_OP = 9,                      /* GE_OP  */
  YYSYMBOL_NE_OP = 10,                     /* NE_OP  */
  YYSYMBOL_EQ_OP = 11,                     /* EQ_OP  */
  YYSYMBOL_FORWARD_ACCESS = 12,            /* FORWARD_ACCESS  */
  YYSYMBOL_BACKWARD_ACCESS = 13,           /* BACKWARD_ACCESS  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_FLOAT = 15,                     /* FLOAT  */
  YYSYMBOL_BIG = 16,                       /* BIG  */
  YYSYMBOL_SMALL = 17,                     /* SMALL  */
  YYSYMBOL_CONST = 18,                     /* CONST  */
  YYSYMBOL_VOID = 19,                      /* VOID  */
  YYSYMBOL_SET = 20,                       /* SET  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_SIZE = 22,                      /* SIZE  */
  YYSYMBOL_LOOP = 23,                      /* LOOP  */
  YYSYMBOL_FINALLY = 24,                   /* FINALLY  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_FUNC = 26,                      /* FUNC  */
  YYSYMBOL_PRINT = 27,                     /* PRINT  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* ','  */
  YYSYMBOL_32_ = 32,                       /* '['  */
  YYSYMBOL_33_ = 33,                       /* ']'  */
  YYSYMBOL_34_ = 34,                       /* '~'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '%'  */
  YYSYMBOL_40_ = 40,                       /* '<'  */
  YYSYMBOL_41_ = 41,                       /* '>'  */
  YYSYMBOL_42_ = 42,                       /* '&'  */
  YYSYMBOL_43_ = 43,                       /* '^'  */
  YYSYMBOL_44_ = 44,                       /* '|'  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* '?'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_start_rule = 51,                /* start_rule  */
  YYSYMBOL_program_body = 52,              /* program_body  */
  YYSYMBOL_set_up_section = 53,            /* set_up_section  */
  YYSYMBOL_function_declaration = 54,      /* function_declaration  */
  YYSYMBOL_parameter_list = 55,            /* parameter_list  */
  YYSYMBOL_parameter = 56,                 /* parameter  */
  YYSYMBOL_set_statement = 57,             /* set_statement  */
  YYSYMBOL_primary_expression = 58,        /* primary_expression  */
  YYSYMBOL_function_call = 59,             /* function_call  */
  YYSYMBOL_argument_expression_list = 60,  /* argument_expression_list  */
  YYSYMBOL_map_array = 61,                 /* map_array  */
  YYSYMBOL_postfix_expression = 62,        /* postfix_expression  */
  YYSYMBOL_unary_expression = 63,          /* unary_expression  */
  YYSYMBOL_multiplicative_expression = 64, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 65,       /* additive_expression  */
  YYSYMBOL_relational_expression = 66,     /* relational_expression  */
  YYSYMBOL_equality_expression = 67,       /* equality_expression  */
  YYSYMBOL_and_expression = 68,            /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 69,   /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 70,   /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 71,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 72,     /* logical_or_expression  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_assignment_statement = 74,      /* assignment_statement  */
  YYSYMBOL_declaration_statement = 75,     /* declaration_statement  */
  YYSYMBOL_declaration_specifier = 76,     /* declaration_specifier  */
  YYSYMBOL_init_declarator_list = 77,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 78,           /* init_declarator  */
  YYSYMBOL_type_specifier = 79,            /* type_specifier  */
  YYSYMBOL_declarator = 80,                /* declarator  */
  YYSYMBOL_initializer = 81,               /* initializer  */
  YYSYMBOL_push_pop_statement = 82,        /* push_pop_statement  */
  YYSYMBOL_compound_statement = 83,        /* compound_statement  */
  YYSYMBOL_expression_statement = 84,      /* expression_statement  */
  YYSYMBOL_iteration_statement = 85,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 86,            /* jump_statement  */
  YYSYMBOL_print_statement = 87,           /* print_statement  */
  YYSYMBOL_chaining_if_else = 88,          /* chaining_if_else  */
  YYSYMBOL_if_else_statement = 89,         /* if_else_statement  */
  YYSYMBOL_statement = 90,                 /* statement  */
  YYSYMBOL_statement_list = 91             /* statement_list  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   415

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,     2,     2,     2,     2,    39,    42,     2,
      28,    30,    37,    36,    31,    35,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    29,
      40,    45,    41,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,    44,    48,    34,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    17,    17,    20,    21,    25,    26,    27,    31,    34,
      35,    39,    42,    43,    44,    45,    49,    50,    51,    55,
      56,    60,    61,    65,    66,    70,    71,    72,    73,    77,
      78,    79,    80,    81,    82,    86,    87,    88,    89,    93,
      94,    95,    99,   100,   101,   102,   103,   107,   108,   109,
     113,   114,   118,   119,   123,   124,   128,   129,   133,   134,
     138,   142,   143,   144,   148,   152,   153,   154,   158,   159,
     163,   164,   168,   169,   170,   171,   175,   179,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     209,   210,   214,   215,   219,   220,   221,   222,   223,   224,
     228,   229,   233,   237,   238,   239,   243,   247,   248,   249,
     250,   251,   252,   253,   254,   258,   259
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONSTANT", "OR", "AND", "NOT", "LE_OP", "GE_OP", "NE_OP", "EQ_OP",
  "FORWARD_ACCESS", "BACKWARD_ACCESS", "INT", "FLOAT", "BIG", "SMALL",
  "CONST", "VOID", "SET", "ELSE", "SIZE", "LOOP", "FINALLY", "RETURN",
  "FUNC", "PRINT", "'('", "';'", "')'", "','", "'['", "']'", "'~'", "'-'",
  "'+'", "'*'", "'/'", "'%'", "'<'", "'>'", "'&'", "'^'", "'|'", "'='",
  "'{'", "':'", "'}'", "'?'", "$accept", "start_rule", "program_body",
  "set_up_section", "function_declaration", "parameter_list", "parameter",
  "set_statement", "primary_expression", "function_call",
  "argument_expression_list", "map_array", "postfix_expression",
  "unary_expression", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression", "expression",
  "assignment_statement", "declaration_statement", "declaration_specifier",
  "init_declarator_list", "init_declarator", "type_specifier",
  "declarator", "initializer", "push_pop_statement", "compound_statement",
  "expression_statement", "iteration_statement", "jump_statement",
  "print_statement", "chaining_if_else", "if_else_statement", "statement",
  "statement_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -126,    13,    39,  -126,    64,  -126,   198,     3,     9,    -9,
      31,    53,    80,    97,    90,   198,   327,   198,   198,   198,
     189,     5,  -126,  -126,  -126,  -126,    89,  -126,  -126,    56,
      -6,     7,    34,    83,    98,   101,   143,   147,  -126,   124,
    -126,   151,  -126,   126,  -126,  -126,   127,   129,  -126,  -126,
     293,   128,   130,     4,   198,   198,    37,    40,  -126,  -126,
    -126,    81,    96,    32,   343,  -126,  -126,   133,   198,   142,
       5,   152,   140,   141,  -126,  -126,  -126,  -126,   132,   134,
     224,   137,   145,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,  -126,
    -126,    49,  -126,   149,  -126,  -126,  -126,  -126,   135,   198,
    -126,   104,  -126,   153,  -126,   146,   148,   198,   198,   145,
     166,   168,   169,   170,   167,    95,   363,   177,   363,     5,
     178,  -126,   204,   131,  -126,   293,  -126,  -126,     5,  -126,
    -126,  -126,    56,    56,    -6,    -6,    -6,    -6,     7,     7,
      34,    83,    98,   101,   143,  -126,   151,   233,  -126,   176,
     180,  -126,   198,  -126,   379,   198,   182,  -126,  -126,  -126,
    -126,  -126,  -126,    -4,  -126,   181,   233,   363,   233,    57,
    -126,   216,  -126,    89,   219,   238,   259,   194,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,   210,   211,  -126,  -126,   215,
     233,   218,     5,     5,  -126,   145,    89,    89,   203,  -126,
    -126,  -126,  -126,   206,   227,   207,   241,  -126,   145,   145,
     293,   232,   228,   232,   232,   293,   189,   252,   232,   253,
    -126,   231,   255,   236,   293,   242,   293,  -126,   293,  -126,
    -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     4,     1,    17,    18,     0,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     6,     7,    28,    27,    34,    38,    41,
      42,    47,    50,    52,    54,    56,    58,    60,    61,     0,
     114,     0,    65,     0,   108,   109,     0,     0,   113,   115,
       3,     0,     0,     0,     0,     0,    25,    17,    29,    74,
      75,     0,     0,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,    30,    31,    32,    90,    61,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
      76,     0,    68,    70,   112,   110,   111,   116,     0,     0,
      19,     0,    21,     0,    63,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,    16,     0,     0,    66,     0,   106,    91,     0,    35,
      36,    37,    40,    39,    45,    46,    43,    44,    49,    48,
      51,    53,    55,    57,    59,    64,     0,     0,    86,     0,
       0,    20,     0,    24,     0,     0,     0,    62,    13,    12,
      15,    14,    33,    25,    92,     0,     0,     0,     0,     0,
       9,     0,   102,    88,     0,     0,   104,     0,    69,    77,
      71,    82,    78,    22,    87,     0,     0,    23,    93,     0,
       0,     0,     0,     0,    11,    89,    80,    84,     0,   103,
      67,    83,    79,     0,     0,     0,     0,    10,    81,    85,
       0,     0,     0,     0,     0,   105,     0,    99,     0,    96,
       8,     0,    94,     0,     0,     0,     0,    98,     0,    97,
      95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,  -126,  -126,  -126,    82,  -126,  -126,  -126,
    -126,   -24,   225,     6,    61,    16,    58,   196,   197,   202,
     205,   208,  -126,     2,   -54,   237,   -12,  -126,   154,  -126,
    -126,  -126,  -126,   -92,  -125,  -126,  -126,  -126,   117,  -126,
     -49,    -2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    22,     2,    23,   179,   180,    24,    25,    26,
     111,    56,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   101,   102,    42,
     103,   190,    43,    44,   176,    45,    46,    47,    79,    48,
      49,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,   107,    82,   178,    73,    61,    62,    57,     5,    81,
     127,     6,    58,     3,    66,    88,    89,    69,    72,     7,
       8,    59,    78,    74,    75,    76,    10,    60,   117,    86,
      87,   107,    15,   119,   110,    57,     5,    70,    17,    18,
      19,   118,     4,     5,    92,    93,     6,    90,    91,   115,
     116,    21,   200,     7,     8,   112,   113,   114,    73,     9,
      15,    10,    11,    63,    12,    13,    14,    15,    53,   117,
     130,    16,    54,    17,    18,    19,    51,    52,   155,    20,
     156,    64,   118,    57,     5,    21,   202,     6,   203,   139,
     140,   141,    53,    83,    84,    85,    54,   120,   121,    65,
      67,   173,    10,   189,   144,   145,   146,   147,    15,    55,
     159,   160,   122,   123,    17,    18,    19,   181,    68,   166,
     167,    54,   199,    53,   201,    94,   187,    54,   175,   227,
     175,   229,   230,   186,   161,   162,   232,   107,    57,     5,
      55,    95,     6,   184,   185,    96,   214,   142,   143,    97,
     148,   149,    98,    99,   100,   104,   105,    10,   106,   205,
     108,   129,   109,    15,   193,   132,   195,   196,   158,    17,
      18,    19,   131,   133,   134,   136,   107,   117,   164,   175,
     165,   135,   218,   219,   138,   237,   163,   239,    78,   240,
     216,   181,     4,     5,   157,   168,     6,   169,   170,   171,
     172,    57,     5,     7,     8,     6,   177,   183,   182,   191,
     198,    10,    11,   192,    12,   197,    14,    15,   225,   204,
      10,    16,   206,    17,    18,    19,    15,     4,     5,    20,
      77,     6,    17,    18,    19,    21,   125,     5,     7,     8,
       6,   207,   210,   211,   212,   213,    10,    11,   215,    12,
     220,    14,    15,   221,   223,    10,    16,   222,    17,    18,
      19,    15,     4,     5,    20,   137,     6,    17,    18,    19,
      21,   224,   226,     7,     8,   228,   231,   233,   234,   235,
     208,    10,    11,   236,    12,   217,    14,    15,   124,   238,
     150,    16,   151,    17,    18,    19,     4,     5,   152,    20,
       6,   128,   153,   209,     0,    21,   154,     7,     8,     0,
     188,     0,     0,     0,     0,    10,    11,     0,    12,     0,
      14,    15,     0,     0,     0,    16,     0,    17,    18,    19,
      57,     5,     0,    20,     6,     0,     0,     0,     0,    21,
       0,     7,     8,     0,     0,     0,   125,     5,     0,    10,
       6,     0,     0,     0,     0,    15,     0,     7,     8,    70,
      71,    17,    18,    19,     0,    10,    57,     5,     0,     0,
       6,    15,   126,    21,     0,    70,     0,    17,    18,    19,
       0,     0,    57,     5,     0,    10,     6,     0,     0,    21,
       0,    15,   174,     0,     0,     0,     0,    17,    18,    19,
       0,    10,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,   194,    17,    18,    19
};

static const yytype_int16 yycheck[] =
{
       2,    50,    26,   128,    16,    14,    15,     3,     4,    21,
      64,     7,     6,     0,    12,     8,     9,    15,    16,    14,
      15,    18,    20,    17,    18,    19,    22,    18,    32,    35,
      36,    80,    28,    57,    30,     3,     4,    32,    34,    35,
      36,    45,     3,     4,    10,    11,     7,    40,    41,    12,
      13,    46,   177,    14,    15,    53,    54,    55,    70,    20,
      28,    22,    23,    32,    25,    26,    27,    28,    28,    32,
      68,    32,    32,    34,    35,    36,    12,    13,    29,    40,
      31,    28,    45,     3,     4,    46,    29,     7,    31,    83,
      84,    85,    28,    37,    38,    39,    32,    16,    17,    19,
       3,   125,    22,   157,    88,    89,    90,    91,    28,    45,
     108,   109,    16,    17,    34,    35,    36,   129,    28,   117,
     118,    32,   176,    28,   178,    42,   138,    32,   126,   221,
     128,   223,   224,   135,    30,    31,   228,   186,     3,     4,
      45,    43,     7,    12,    13,    44,   200,    86,    87,     6,
      92,    93,     5,    29,     3,    29,    29,    22,    29,   183,
      32,    28,    32,    28,   162,    13,   164,   165,    33,    34,
      35,    36,    30,    33,    33,    41,   225,    32,    32,   177,
      32,    49,   206,   207,    47,   234,    33,   236,   186,   238,
     202,   203,     3,     4,    45,    29,     7,    29,    29,    29,
      33,     3,     4,    14,    15,     7,    29,     3,    30,    33,
      29,    22,    23,    33,    25,    33,    27,    28,   220,     3,
      22,    32,     3,    34,    35,    36,    28,     3,     4,    40,
      41,     7,    34,    35,    36,    46,     3,     4,    14,    15,
       7,     3,    48,    33,    33,    30,    22,    23,    30,    25,
      47,    27,    28,    47,    47,    22,    32,    30,    34,    35,
      36,    28,     3,     4,    40,    41,     7,    34,    35,    36,
      46,    30,    40,    14,    15,    47,    24,    24,    47,    24,
      21,    22,    23,    47,    25,   203,    27,    28,    63,    47,
      94,    32,    95,    34,    35,    36,     3,     4,    96,    40,
       7,    64,    97,   186,    -1,    46,    98,    14,    15,    -1,
     156,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,
      27,    28,    -1,    -1,    -1,    32,    -1,    34,    35,    36,
       3,     4,    -1,    40,     7,    -1,    -1,    -1,    -1,    46,
      -1,    14,    15,    -1,    -1,    -1,     3,     4,    -1,    22,
       7,    -1,    -1,    -1,    -1,    28,    -1,    14,    15,    32,
      33,    34,    35,    36,    -1,    22,     3,     4,    -1,    -1,
       7,    28,    29,    46,    -1,    32,    -1,    34,    35,    36,
      -1,    -1,     3,     4,    -1,    22,     7,    -1,    -1,    46,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    53,     0,     3,     4,     7,    14,    15,    20,
      22,    23,    25,    26,    27,    28,    32,    34,    35,    36,
      40,    46,    52,    54,    57,    58,    59,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    79,    82,    83,    85,    86,    87,    89,    90,
      91,    12,    13,    28,    32,    45,    61,     3,    63,    18,
      18,    14,    15,    32,    28,    19,    73,     3,    28,    73,
      32,    33,    73,    76,    63,    63,    63,    41,    73,    88,
      91,    76,    61,    37,    38,    39,    35,    36,     8,     9,
      40,    41,    10,    11,    42,    43,    44,     6,     5,    29,
       3,    77,    78,    80,    29,    29,    29,    90,    32,    32,
      30,    60,    73,    73,    73,    12,    13,    32,    45,    61,
      16,    17,    16,    17,    62,     3,    29,    74,    75,    28,
      73,    30,    13,    33,    33,    49,    41,    41,    47,    63,
      63,    63,    64,    64,    65,    65,    65,    65,    66,    66,
      67,    68,    69,    70,    71,    29,    31,    45,    33,    73,
      73,    30,    31,    33,    32,    32,    73,    73,    29,    29,
      29,    29,    33,    61,    29,    73,    84,    29,    84,    55,
      56,    76,    30,     3,    12,    13,    91,    76,    78,    74,
      81,    33,    33,    73,    33,    73,    73,    33,    29,    74,
      84,    74,    29,    31,     3,    61,     3,     3,    21,    88,
      48,    33,    33,    30,    74,    30,    76,    56,    61,    61,
      47,    47,    30,    47,    30,    91,    40,    83,    47,    83,
      83,    24,    83,    24,    47,    24,    47,    90,    47,    90,
      90
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    54,    55,
      55,    56,    57,    57,    57,    57,    58,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    64,    64,    64,    64,    65,
      65,    65,    66,    66,    66,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    74,    74,    74,    75,    76,    76,    76,    77,    77,
      78,    78,    79,    79,    79,    79,    80,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    88,    88,    88,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     0,     2,     2,     8,     1,
       3,     2,     4,     4,     4,     4,     3,     1,     1,     3,
       4,     1,     3,     4,     3,     2,     2,     1,     1,     2,
       2,     2,     2,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     4,     3,     3,     1,     3,     5,     1,     3,
       1,     3,     1,     1,     2,     2,     1,     1,     5,     6,
       5,     6,     5,     6,     5,     6,     4,     5,     4,     5,
       2,     3,     1,     2,     9,    12,     8,    11,    11,     8,
       2,     2,     4,     4,     3,     6,     3,     2,     1,     1,
       2,     2,     2,     1,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* start_rule: set_up_section program_body  */
#line 17 "parser.y"
                                  {puts("success");}
#line 1450 "y.tab.c"
    break;


#line 1454 "y.tab.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 262 "parser.y"


int yywrap(){
    return 1;
}

void yyerror(char* s) { 
    printf("%s\n",s);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        puts("error: usage ./a.out <input_file>");
        return 0;
    }
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        puts("error: couldn't open the file");
        return 0;
    }
    yyparse(); 
}