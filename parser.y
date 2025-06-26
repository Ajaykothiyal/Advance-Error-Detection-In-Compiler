%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void yyerror(const char* s);
int yylex(void);
extern int yylineno;
extern FILE *yyin;

// Helper function to convert type code to string
const char* type_to_string(int type) {
    switch(type) {
        case 1: return "int";
        case 2: return "char";
        case 3: return "void";
        case 4: return "float";
        default: return "unknown";
    }
}

// Symbol table structure
typedef struct {
    char* name;
    int type;
    int scope;
    int is_initialized;
    int is_used;
    int is_function;
    int is_parameter;
} Symbol;

#define MAX_SYMBOLS 1000
Symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

// Error tracking
int error_count = 0;
void report_error(const char* msg, int line, int col);

// Function to add symbol to table
void add_symbol(char* name, int type, int scope, int is_function) {
    if (symbol_count >= MAX_SYMBOLS) {
        report_error("Symbol table overflow", 0, 0);
        return;
    }
    symbol_table[symbol_count] = (Symbol){
        .name = strdup(name),
        .type = type,
        .scope = scope,
        .is_initialized = 0,
        .is_used = 0,
        .is_function = is_function,
        .is_parameter = 0
    };
    symbol_count++;
}

// Function to find symbol
Symbol* find_symbol(char* name, int scope) {
    for (int i = symbol_count - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].name, name) == 0 && 
            (symbol_table[i].scope == scope || symbol_table[i].scope < scope)) {
            return &symbol_table[i];
        }
    }
    return NULL;
}

// Function to check for unused variables (but not functions or parameters)
void check_unused_symbols() {
    for (int i = 0; i < symbol_count; i++) {
        if (!symbol_table[i].is_function && !symbol_table[i].is_parameter && !symbol_table[i].is_used) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "Unused variable '%s'", symbol_table[i].name);
            report_error(error_msg, yylineno, 0);
        }
    }
}
%}

%union {
    int int_val;
    float float_val;
    char char_val;
    char* string_val;
}

%token <string_val> IDENTIFIER
%token <int_val> INTEGER_LITERAL
%token <float_val> FLOAT_LITERAL
%token <char_val> CHAR_LITERAL
%token <string_val> STRING_LITERAL

%token INT CHAR VOID FLOAT_TYPE
%token IF ELSE WHILE FOR RETURN
%token STRUCT TYPEDEF CONST STATIC EXTERN SIZEOF
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token ASSIGN EQUAL NOT_EQUAL
%token LESS LESS_EQUAL GREATER GREATER_EQUAL
%token AND OR NOT
%token BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_NOT
%token LEFT_SHIFT RIGHT_SHIFT
%token INCREMENT DECREMENT
%token ARROW DOT
%token SEMICOLON COMMA
%token LEFT_PAREN RIGHT_PAREN
%token LEFT_BRACE RIGHT_BRACE
%token LEFT_BRACKET RIGHT_BRACKET
%token COLON QUESTION

%type <int_val> type_specifier
%type <int_val> expression
%type <int_val> statement
%type <int_val> compound_statement
%type <int_val> declaration
%type <int_val> function_definition
%type <int_val> external_declaration
%type <int_val> program
%type <int_val> declaration_list
%type <int_val> statement_list
%type <int_val> expression_statement
%type <int_val> selection_statement
%type <int_val> iteration_statement
%type <int_val> jump_statement
%type <int_val> assignment_expression
%type <int_val> logical_or_expression
%type <int_val> logical_and_expression
%type <int_val> equality_expression
%type <int_val> relational_expression
%type <int_val> additive_expression
%type <int_val> multiplicative_expression
%type <int_val> unary_expression
%type <int_val> postfix_expression
%type <int_val> primary_expression
%type <int_val> parameter_list
%type <int_val> parameter_declaration
%type <int_val> argument_expression_list

%start program

%%

program
    : external_declaration { $$ = $1; }
    | program external_declaration { $$ = $2; }
    ;

external_declaration
    : function_definition { $$ = $1; }
    | declaration { $$ = $1; }
    ;

function_definition
    : type_specifier IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN compound_statement
    {
        // Check for function redefinition
        Symbol* sym = find_symbol($2, 0);
        if (sym != NULL) {
            report_error("Function redefinition", yylineno, 0);
        } else {
            add_symbol($2, $1, 0, 1);  // Mark as function
        }
        $$ = $1;
    }
    ;

parameter_list
    : parameter_declaration { $$ = $1; }
    | parameter_list COMMA parameter_declaration { $$ = $3; }
    | /* empty */ { $$ = 0; }
    ;

parameter_declaration
    : type_specifier IDENTIFIER
    {
        // Add parameter to symbol table and mark it as initialized
        Symbol* sym = find_symbol($2, 1);
        if (sym != NULL) {
            report_error("Parameter redefinition", yylineno, 0);
        } else {
            add_symbol($2, $1, 1, 0);  // Add parameter to symbol table
            symbol_table[symbol_count-1].is_initialized = 1;  // Mark as initialized
            symbol_table[symbol_count-1].is_parameter = 1;    // Mark as parameter
            symbol_table[symbol_count-1].is_used = 1;         // Mark as used
        }
        $$ = $1;
    }
    ;

type_specifier
    : INT     { $$ = 1; }
    | CHAR    { $$ = 2; }
    | VOID    { $$ = 3; }
    | FLOAT_TYPE { $$ = 4; }
    ;

declaration
    : type_specifier IDENTIFIER SEMICOLON
    {
        // Check for variable redefinition
        Symbol* sym = find_symbol($2, 0);
        if (sym != NULL) {
            report_error("Variable redefinition", yylineno, 0);
        } else {
            add_symbol($2, $1, 0, 0);  // Mark as variable
        }
        $$ = $1;
    }
    | type_specifier IDENTIFIER { 
        // Add variable to symbol table before parsing the assignment expression
        Symbol* sym = find_symbol($2, 0);
        if (sym != NULL) {
            report_error("Variable redefinition", yylineno, 0);
        } else {
            add_symbol($2, $1, 0, 0);
        }
    } ASSIGN expression SEMICOLON
    {
        // Now check type compatibility and mark as initialized/used
        Symbol* sym = find_symbol($2, 0);
        if (sym) {
            if (sym->type != $5) {
                char error_msg[256];
                snprintf(error_msg, sizeof(error_msg), "Type mismatch in assignment: expected %s, got %s", type_to_string(sym->type), type_to_string($5));
                report_error(error_msg, yylineno, 0);
            }
            sym->is_initialized = 1;
            sym->is_used = 1;
        }
        $$ = $1;
    }
    ;

compound_statement
    : LEFT_BRACE declaration_list statement_list RIGHT_BRACE { $$ = 0; }
    ;

declaration_list
    : declaration { $$ = $1; }
    | declaration_list declaration { $$ = $2; }
    | /* empty */ { $$ = 0; }
    ;

statement_list
    : statement { $$ = $1; }
    | statement_list statement { $$ = $2; }
    | /* empty */ { $$ = 0; }
    ;

statement
    : expression_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | jump_statement { $$ = $1; }
    ;

expression_statement
    : expression SEMICOLON { $$ = $1; }
    | SEMICOLON { $$ = 0; }
    ;

selection_statement
    : IF LEFT_PAREN expression RIGHT_PAREN statement { $$ = $3; }
    | IF LEFT_PAREN expression RIGHT_PAREN statement ELSE statement { $$ = $3; }
    ;

iteration_statement
    : WHILE LEFT_PAREN expression RIGHT_PAREN statement { $$ = $3; }
    | FOR LEFT_PAREN expression_statement expression_statement RIGHT_PAREN statement { $$ = 0; }
    | FOR LEFT_PAREN expression_statement expression_statement expression RIGHT_PAREN statement { $$ = $5; }
    ;

jump_statement
    : RETURN expression SEMICOLON { $$ = $2; }
    | RETURN SEMICOLON { $$ = 0; }
    ;

expression
    : assignment_expression { $$ = $1; }
    | expression COMMA assignment_expression { $$ = $3; }
    ;

assignment_expression
    : logical_or_expression { $$ = $1; }
    | IDENTIFIER ASSIGN assignment_expression
    {
        // Check if variable is declared and initialized
        Symbol* sym = find_symbol($1, 0);
        if (sym == NULL) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "Undefined variable '%s'", $1);
            report_error(error_msg, yylineno, 0);
        } else {
            // Type check
            if (sym->type != $3) {
                char error_msg[256];
                snprintf(error_msg, sizeof(error_msg), "Type mismatch in assignment: expected %s, got %s", type_to_string(sym->type), type_to_string($3));
                report_error(error_msg, yylineno, 0);
            }
            sym->is_initialized = 1;
            sym->is_used = 1; // Mark as used
        }
        $$ = $3;
    }
    ;

logical_or_expression
    : logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression { $$ = $1; }
    ;

logical_and_expression
    : equality_expression { $$ = $1; }
    | logical_and_expression AND equality_expression { $$ = $1; }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQUAL relational_expression { $$ = $1; }
    | equality_expression NOT_EQUAL relational_expression { $$ = $1; }
    ;

relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression LESS additive_expression { $$ = $1; }
    | relational_expression GREATER additive_expression { $$ = $1; }
    | relational_expression LESS_EQUAL additive_expression { $$ = $1; }
    | relational_expression GREATER_EQUAL additive_expression { $$ = $1; }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression PLUS multiplicative_expression { $$ = $1; }
    | additive_expression MINUS multiplicative_expression { $$ = $1; }
    ;

multiplicative_expression
    : unary_expression { $$ = $1; }
    | multiplicative_expression MULTIPLY unary_expression { $$ = $1; }
    | multiplicative_expression DIVIDE unary_expression { $$ = $1; }
    | multiplicative_expression MODULO unary_expression { $$ = $1; }
    ;

unary_expression
    : postfix_expression { $$ = $1; }
    | PLUS unary_expression { $$ = $2; }
    | MINUS unary_expression { $$ = $2; }
    | NOT unary_expression { $$ = $2; }
    | BITWISE_NOT unary_expression { $$ = $2; }
    ;

postfix_expression
    : primary_expression { $$ = $1; }
    | postfix_expression LEFT_BRACKET expression RIGHT_BRACKET { $$ = $1; }
    | postfix_expression LEFT_PAREN argument_expression_list RIGHT_PAREN { $$ = $1; }
    | postfix_expression DOT IDENTIFIER { $$ = $1; }
    | postfix_expression ARROW IDENTIFIER { $$ = $1; }
    | postfix_expression INCREMENT { $$ = $1; }
    | postfix_expression DECREMENT { $$ = $1; }
    ;

primary_expression
    : IDENTIFIER
    {
        // Check if variable is declared
        Symbol* sym = find_symbol($1, 1);  // First check in current scope (1)
        if (sym == NULL) {
            sym = find_symbol($1, 0);      // Then check in global scope (0)
        }
        if (sym == NULL) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "Undefined variable '%s'", $1);
            report_error(error_msg, yylineno, 0);
        } else {
            // Only check initialization and usage for non-function and non-parameter symbols
            if (!sym->is_function && !sym->is_parameter) {
                sym->is_used = 1;
                if (!sym->is_initialized) {
                    char error_msg[256];
                    snprintf(error_msg, sizeof(error_msg), "Uninitialized variable '%s'", $1);
                    report_error(error_msg, yylineno, 0);
                }
            }
        }
        $$ = sym ? sym->type : 0;
    }
    | INTEGER_LITERAL { $$ = 1; }  // INT type
    | FLOAT_LITERAL { $$ = 4; }    // FLOAT type
    | CHAR_LITERAL { $$ = 2; }     // CHAR type
    | STRING_LITERAL { $$ = 2; }   // CHAR* type
    | LEFT_PAREN expression RIGHT_PAREN { $$ = $2; }
    ;

argument_expression_list
    : assignment_expression { $$ = $1; }
    | argument_expression_list COMMA assignment_expression { $$ = $3; }
    | /* empty */ { $$ = 0; }
    ;

%%

void report_error(const char* msg, int line, int col) {
    (void)col;  // Explicitly acknowledge unused parameter
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
    error_count++;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
    error_count++;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    
    yyparse();
    
    // Report unused variables
    check_unused_symbols();
    
    return error_count;
} 
