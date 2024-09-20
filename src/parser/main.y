%token IDENTIFIER CONSTANT
%token OR AND NOT
%token LE_OP GE_OP NE_OP
%token FORWARD_ACCESS BACKWARD_ACCESS
%token INT FLOAT BIG SMALL CONST
%token SET IF ELSE SIZE LOOP FINALLY RETURN FUNC PRINT

%start set_statement
%%

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


expression 
    : additive_expression
    ;

additive_expression 
    : additive_expression '+' multiplicative_expression
    | additive_expression '-' multiplicative_expression
    | multiplicative_expression
    ;

unary_expression 
    : '!' unary_expression
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
                 
postfix_expression 
    : postfix_expression '[' expression ']'
    | postfix_expression '(' ')'
    | postfix_expression '(' argument_expression_list ')'
    | primary_expression
    ;

argument_expression_list : 


primary_expression : '(' expression ')'
    | IDENTIFIER
    | CONSTANT 
    ;

assignment_statement 
    : IDENTIFIER '=' expression ';'
    ;

%%
#include <stdio.h>
