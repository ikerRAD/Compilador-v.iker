/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 33 "parser.y" /* yacc.c:1909  */

    string *str ;
    vector<string> *list ;
    expresionstruct *expr ;
    sentenciastruct *sent ;
    int number ;
    vector<int> *numlist;
    casestruct *cses;

#line 115 "parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
