%{
#include <stdio.h>
#include "lex.yy.c"
%}

%token IDENTIFIER CONSTANT
%token OR AND NOT
%token LE_OP GE_OP NE_OP EQ_OP
%token FORWARD_ACCESS BACKWARD_ACCESS
%token INT FLOAT BIG SMALL CONST VOID
%token SET ELSE SIZE LOOP FINALLY RETURN FUNC PRINT

%start start_rule
%%

start_rule
    : set_up_section program_body {puts("success");}

program_body
    : statement_list
    |
    ;

set_up_section
    : 
    | set_up_section function_declaration
    | set_up_section set_statement
    ;

function_declaration
    : FUNC IDENTIFIER '(' parameter_list ';' declaration_specifier ')' compound_statement

parameter_list
    : parameter
    | parameter_list ',' parameter
    ;

parameter
    : declaration_specifier IDENTIFIER

set_statement 
    : SET INT SMALL ';'
    | SET INT BIG ';'
    | SET FLOAT SMALL ';'
    | SET FLOAT BIG ';'
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

argument_expression_list
    : expression
    | argument_expression_list ',' expression
    ;    

map_array
    : map_array '[' expression ']'
    | '[' expression ']'
    ;

postfix_expression 
    : IDENTIFIER map_array
    | function_call map_array
    | function_call
    | primary_expression
    ;

unary_expression 
    : NOT unary_expression
    | '~' unary_expression
    | '-' unary_expression
    | '+' unary_expression
    | SIZE '[' postfix_expression ']'
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

declaration_statement
    : declaration_specifier init_declarator_list ';'
    ;

declaration_specifier
    : type_specifier 
    | '[' declaration_specifier ']'
    | '{' declaration_specifier ':' declaration_specifier '}' 
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

/* push_pop_statement
    : IDENTIFIER map_array BACKWARD_ACCESS '[' expression ']'
    | '[' expression ']' FORWARD_ACCESS IDENTIFIER map_array
    | IDENTIFIER map_array FORWARD_ACCESS '[' IDENTIFIER ']'
    | IDENTIFIER map_array FORWARD_ACCESS '[' IDENTIFIER map_array ']'
    | '[' IDENTIFIER ']' BACKWARD_ACCESS IDENTIFIER map_array
    | '[' IDENTIFIER map_array ']' BACKWARD_ACCESS IDENTIFIER map_array
    | IDENTIFIER map_array FORWARD_ACCESS '[' ']'
    | '[' ']' BACKWARD_ACCESS IDENTIFIER map_array
    ;  */

push_pop_statement
    : IDENTIFIER BACKWARD_ACCESS '[' expression ']'
    | IDENTIFIER map_array BACKWARD_ACCESS '[' expression ']'
    | '[' expression ']' FORWARD_ACCESS IDENTIFIER
    | '[' expression ']' FORWARD_ACCESS IDENTIFIER map_array
    | IDENTIFIER FORWARD_ACCESS '[' expression ']'
    | IDENTIFIER map_array FORWARD_ACCESS '[' expression ']'
    | '[' expression ']' BACKWARD_ACCESS IDENTIFIER
    | '[' expression ']' BACKWARD_ACCESS IDENTIFIER map_array
    | IDENTIFIER FORWARD_ACCESS '[' ']'
    | IDENTIFIER map_array FORWARD_ACCESS '[' ']'
    | '[' ']' BACKWARD_ACCESS IDENTIFIER
    | '[' ']' BACKWARD_ACCESS IDENTIFIER map_array
    ; 

compound_statement
	: '<' '>'
	| '<' statement_list '>'
	;

expression_statement
	: ';'
	| expression ';'
	;

iteration_statement
    : LOOP '(' assignment_statement ';' expression_statement assignment_statement ')' ':' compound_statement
    | LOOP '(' assignment_statement ';' expression_statement assignment_statement ')' ':' compound_statement FINALLY ':' statement
    | LOOP '(' declaration_statement expression_statement assignment_statement ')' ':' compound_statement 
    | LOOP '(' declaration_statement expression_statement assignment_statement ')' ':' compound_statement FINALLY ':' statement 
    | LOOP '(' ';' expression_statement assignment_statement ')' ':' compound_statement FINALLY ':' statement 
    | LOOP '(' ';' expression_statement assignment_statement ')' ':' compound_statement
	;

jump_statement
	: RETURN VOID 
	| RETURN expression 
	;

print_statement
    : PRINT '(' expression ')'
    ;

chaining_if_else 
    : expression '?' statement_list chaining_if_else
    | expression '?' statement_list
    | expression '?' statement_list ELSE ':' statement_list
    ;

if_else_statement
    : '<' chaining_if_else '>'
    ;

statement
	: assignment_statement ';'
	| compound_statement
	| iteration_statement
	| jump_statement ';'
    | print_statement ';'
    | push_pop_statement ';'
    | if_else_statement
    | declaration_statement
	;

statement_list
	: statement
	| statement_list statement
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