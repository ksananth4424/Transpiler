/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    SET = 274,                     /* SET  */
    IF = 275,                      /* IF  */
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
#define SET 274
#define IF 275
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
