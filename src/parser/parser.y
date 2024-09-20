%{
#include <stdio.h>
#include"lex.yy.c"
%}

%token IDENTIFIER CONSTANT
%token OR AND NOT
%token LE_OP GE_OP NE_OP EQ_OP
%token FORWARD_ACCESS BACKWARD_ACCESS
%token INT FLOAT BIG SMALL CONST
%token SET IF ELSE SIZE LOOP FINALLY RETURN FUNC PRINT

%start assignment_statement
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

primary_expression 
    : '(' expression ')'
    | IDENTIFIER
    | CONSTANT 
    ;

postfix_expression 
    : postfix_expression '[' expression ']'
    | postfix_expression '(' ')'
    | postfix_expression '(' argument_expression_list ')'
    | primary_expression
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

additive_expression 
    : additive_expression '+' multiplicative_expression
    | additive_expression '-' multiplicative_expression
    | multiplicative_expression
    ;
        
argument_expression_list
    : assignment_statement
    | argument_expression_list ',' assignment_statement
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

assignment_statement 
    : logical_or_expression
    | unary_expression '=' assignment_statement ';'
    ;

expression 
    : assignment_statement
    ;

%%

int yywrap(){
    return 1;
}

void yyerror(char* s) { 
    printf("%s\n",s);
}

int main() {
    yyparse(); 
}