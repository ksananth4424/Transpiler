%{
#include <stdio.h>
#include "lex.yy.c"
%}

%token IDENTIFIER CONSTANT
%token OR AND NOT
%token LE_OP GE_OP NE_OP EQ_OP
%token FORWARD_ACCESS BACKWARD_ACCESS
%token INT FLOAT BIG SMALL CONST
%token SET IF ELSE SIZE LOOP FINALLY RETURN FUNC PRINT

%start start_rule
%%

start_rule
    : assignment_statement ';' {puts("success");}

set_statement 
    : SET INT SMALL ';'
    | SET INT BIG ';'
    | SET FLOAT SMALL ';'
    | SET FLOAT BIG ';'
    ;

set_statement_list 
    : set_statement_list set_statement
    | set_statement
    ;

primary_expression 
    : '(' expression ')'
    | IDENTIFIER
    | CONSTANT 
    ;

function_call
    : IDENTIFIER '(' ')'
    | IDENTIFIER '(' argument_expression_list ')'
    ;

map_array
    : map_array '[' expression ']'
    | '[' expression ']'
    ;

postfix_expression 
    : IDENTIFIER map_array
    | function_call map_array
    | primary_expression
    ;

unary_expression 
    : NOT unary_expression
    | '~' unary_expression
    | '-' unary_expression
    | '+' unary_expression
    |  postfix_expression
    ;

multiplicative_expression 
    : multiplicative_expression '*' unary_expression
    | multiplicative_expression '/' unary_expression
    | multiplicative_expression '%' unary_expression
    | unary_expression
    ;

additive_expression 
    : additive_expression '+' multiplicative_expression
    | additive_expression '-' multiplicative_expression
    | multiplicative_expression
    ;
        
argument_expression_list
    : expression
    | argument_expression_list ',' expression
    ;
    
relational_expression
	: additive_expression
	| relational_expression '<' additive_expression
	| relational_expression '>' additive_expression
	| relational_expression LE_OP additive_expression
	| relational_expression GE_OP additive_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR logical_and_expression
	;

expression 
    : logical_or_expression
    ;

assignment_statement 
    : expression
    | IDENTIFIER map_array '=' expression 
    | IDENTIFIER '=' expression 
    ;

declaration
    : declaration_specifiers ';'
    | declaration_specifiers init_declarator_list ';'
    ;

declaration_specifiers
    : type_specifier 
    | type_specifier declaration_specifiers
    | '[' declaration_specifiers ']'
    | '{' declaration_specifiers ':' declaration_specifiers '}' 
    ;

init_declarator_list
    : init_declarator
    | init_declarator_list ',' init_declarator
    ;

init_declarator
    : declarator
    | declarator '=' initializer
    ;

type_specifier
    : INT
    | FLOAT
    | INT CONST
    | FLOAT CONST
    ;

declarator
    : IDENTIFIER
    ;

initializer
    : assignment_statement
    ;

push_pop_statement
    : accessed_name BACKWARD_ACCESS '[' expression ']'
    | '[' expression ']' FORWARD_ACCESS accessed_name
    | accessed_name FORWARD_ACCESS '[' accessed_name ']'
    | '[' accessed_name ']' BACKWARD_ACCESS accessed_name
    | accessed_name FORWARD_ACCESS '[' ']'
    | '[' ']' BACKWARD_ACCESS accessed_name
    ;

accessed_name
    : IDENTIFIER
    | accessed_name '[' expression ']'
    ;

%%

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