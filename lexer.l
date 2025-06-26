%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

// For tracking columns only
int column_num = 1;

// Function to update column number only
void update_position(char* text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            column_num = 1;
        } else {
            column_num++;
        }
    }
}

// Error handling
void lexer_error(const char* msg) {
    fprintf(stderr, "Error at line %d, column %d: %s\n", yylineno, column_num, msg);
}
%}

%option noyywrap
%option yylineno

/* Regular definitions */
DIGIT       [0-9]
LETTER      [a-zA-Z]
ID          {LETTER}({LETTER}|{DIGIT}|_)*
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+
WHITESPACE  [ \t]
NEWLINE     \n
COMMENT     "//".*|"/*"([^*]|"*"+[^*/])*"*"+"/"

%%

{WHITESPACE}    { column_num += yyleng; }
{NEWLINE}       { column_num = 1; }
{COMMENT}       { update_position(yytext); }

"int"           { return INT; }
"char"          { return CHAR; }
"void"          { return VOID; }
"float"         { return FLOAT_TYPE; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"return"        { return RETURN; }
"struct"        { return STRUCT; }
"typedef"       { return TYPEDEF; }
"const"         { return CONST; }
"static"        { return STATIC; }
"extern"        { return EXTERN; }
"sizeof"        { return SIZEOF; }

{ID}            { 
    yylval.string_val = strdup(yytext);
    return IDENTIFIER;
}

{INTEGER}       {
    yylval.int_val = atoi(yytext);
    return INTEGER_LITERAL;
}

{FLOAT}         {
    yylval.float_val = atof(yytext);
    return FLOAT_LITERAL;
}

\"([^\\\"]|\\.)*\" {
    // Handle string literals
    char* str = strdup(yytext);
    str[strlen(str)-1] = '\0';  // Remove closing quote
    str++;                      // Remove opening quote
    yylval.string_val = str;
    return STRING_LITERAL;
}

\'([^\\\']|\\.)\' {
    // Handle character literals
    char* str = strdup(yytext);
    str[strlen(str)-1] = '\0';  // Remove closing quote
    str++;                      // Remove opening quote
    yylval.char_val = str[0];
    return CHAR_LITERAL;
}

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
"%"             { return MODULO; }
"="             { return ASSIGN; }
"=="            { return EQUAL; }
"!="            { return NOT_EQUAL; }
"<"             { return LESS; }
"<="            { return LESS_EQUAL; }
">"             { return GREATER; }
">="            { return GREATER_EQUAL; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }
"&"             { return BITWISE_AND; }
"|"             { return BITWISE_OR; }
"^"             { return BITWISE_XOR; }
"~"             { return BITWISE_NOT; }
"<<"            { return LEFT_SHIFT; }
">>"            { return RIGHT_SHIFT; }
"++"            { return INCREMENT; }
"--"            { return DECREMENT; }
"->"            { return ARROW; }
"."             { return DOT; }

";"             { return SEMICOLON; }
","             { return COMMA; }
"("             { return LEFT_PAREN; }
")"             { return RIGHT_PAREN; }
"{"             { return LEFT_BRACE; }
"}"             { return RIGHT_BRACE; }
"["             { return LEFT_BRACKET; }
"]"             { return RIGHT_BRACKET; }
":"             { return COLON; }
"?"             { return QUESTION; }

.               {
    char msg[100];
    sprintf(msg, "Unexpected character: %s", yytext);
    lexer_error(msg);
}

%%