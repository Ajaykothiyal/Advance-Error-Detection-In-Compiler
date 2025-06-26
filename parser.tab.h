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

/* Line 1685 of yacc.c  */
#line 83 "parser.y"

    int int_val;
    float float_val;
    char char_val;
    char* string_val;



/* Line 1685 of yacc.c  */
#line 117 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


