/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     REAL = 259,
     STRING = 260,
     ID = 261,
     REMARK_STRING = 262,
     PLUS = 263,
     MINUS = 264,
     MULT = 265,
     DIV = 266,
     POW = 267,
     LPAREN = 268,
     RPAREN = 269,
     DOIS_PONTOS = 270,
     PONTO_VIRGULA = 271,
     VIRGULA = 272,
     PONTO = 273,
     HASH = 274,
     NEWLINE = 275,
     NOT_EQUAL = 276,
     EQUAL = 277,
     MENOR_IGUAL = 278,
     MAIOR_IGUAL = 279,
     MENOR_QUE = 280,
     MAIOR_QUE = 281,
     REMARK = 282,
     PRINT = 283,
     LET = 284,
     IF = 285,
     THEN = 286,
     GOTO = 287,
     STOP = 288,
     RUN = 289,
     END = 290,
     DIM = 291,
     DATA = 292,
     CLOSE = 293,
     FOR = 294,
     TO = 295,
     STEP = 296,
     INPUT = 297,
     OUTPUT = 298,
     GOSUB = 299,
     NEXT = 300,
     OPEN = 301,
     AS = 302,
     POKE = 303,
     RETURN = 304,
     READ = 305,
     RESTORE = 306,
     SYS = 307,
     WAIT = 308,
     OR = 309,
     AND = 310,
     NOT = 311
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 25 "parser.y"

    int intval;          
    double realval;
    char* strval;
    struct ConstantNode* const_list;
    struct IntegerNode* int_list;
    struct PrintNode* print_list;
	struct IdNode* id_list;
	struct ValueNode* value_list;
    struct ExpressionNode* expr_list;
    struct StatementNode* statement;
    struct AccessTypeNode* access_type;
    struct LineNode* line;
    struct ProgramNode* program;
  


/* Line 1685 of yacc.c  */
#line 125 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


