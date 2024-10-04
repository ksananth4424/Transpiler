%{
#include <iostream>
#include <fstream>
#include <regex>

FILE* lexer_log;
FILE* parser_log;

#define YYSTYPE std::string
#include "lex.yy.c"

extern int yywrap();
extern void yyerror(char*);
std::string int_type = "int";
std::string float_type = "float";

int contains_return(const std::string& code) {
    std::regex re("(^|[^a-zA-Z0-9_])return([^a-zA-Z0-9_]|$)");
    if (std::regex_search(code, re)) {
        return 1;
    }
    return 0;
}
%}

%token IDENTIFIER CONSTANT
%token OR AND NOT
%token LE_OP GE_OP NE_OP EQ_OP
%token FORWARD_ACCESS BACKWARD_ACCESS
%token INT FLOAT BIG SMALL CONST VOID
%token SET ELSE SIZE LOOP FINALLY RETURN FUNC PRINT

%left '*' '/' '%'
%left '+' '-'
%left '<' '>' LE_OP GE_OP
%left EQ_OP NE_OP
%left '&'
%left '^'
%left '|'
%left AND
%left OR

%start start_rule
%%

start_rule
    : set_up_section program_body {
        puts("successfully parsed!");
        $$ = "#include<bits/stdc++.h>\n" + $1 + "\n" + $2;
        std::ofstream output("transpiled_cpp.cpp");
        if (output.is_open()) {
            // Write the content to the file
            output << $$;
            // Close the file
            output.close();
        } else {
            std::cout << "Unable to open file for writing" << std::endl;
        }
    }

program_body
    : statement_list    {$$ = "\nint main() {\n" + $1 + "\n}";}
    /* |                   {$$ = "";} */
    ;

set_up_section
    :                                       {$$ = "";}
    | set_up_section function_declaration   {$$ = $1 + "\n" + $2;}
    | set_up_section set_statement          {$$ = $1;}
    ;

function_declaration:
    {fprintf(parser_log, "%d : Function Delaration\n", yylineno);} FUNC IDENTIFIER '(' parameter_list ';' declaration_specifier ')' compound_statement   
    {
        $$ = $7 + " " + $3 + "(" + $5 + ") " + $9;
        if (!contains_return($9)) {
            printf("syntax error: No return statement");
            exit(0);
        }
    }
    ;

parameter_list
    : parameter                         {$$ = $1;}
    | parameter_list ',' parameter      {$$ = $1 + ", " + $3;}
    ;

parameter
    : declaration_specifier IDENTIFIER  {$$ = $1 + " " + $2;}

set_statement 
    : SET INT SMALL ';'     {int_type = "int"; fprintf(parser_log, "%d : Set Statement\n", yylineno);}
    | SET INT BIG ';'       {int_type = "long long"; fprintf(parser_log, "%d : Set Statement\n", yylineno);}
    | SET FLOAT SMALL ';'   {float_type = "float"; fprintf(parser_log, "%d : Set Statement\n", yylineno);}
    | SET FLOAT BIG ';'     {float_type = "double"; fprintf(parser_log, "%d : Set Statement\n", yylineno);}
    ;

primary_expression 
    : '(' assignment_statement ')'    {$$ = "(" + $2 + ")";}
    | CONSTANT              {$$ = $1;}
    ;

function_call
    : IDENTIFIER '(' ')'                            {$$ = $1 + "()";}
    | IDENTIFIER '(' argument_expression_list ')'   {$$ = $1 + "(" + $3 + ")";}
    ;

argument_expression_list
    : assignment_statement                                {$$ = $1;}
    | argument_expression_list ',' assignment_statement   {$$ = $1 + ", " + $3;}
    ;    

map_array
    : '[' assignment_statement ']'                        {$$ = "[" + $2 + "]";}
    | map_array '[' assignment_statement ']'              {$$ = $1 + "[" + $3 + "]";}
    ;

postfix_expression 
    : lhs_expression                            {$$ = $1;}
    | function_call map_array                   {$$ = $1 + $2;}
    | function_call                             {$$ = $1;}  
    | primary_expression                        {$$ = $1;}
    ;

unary_expression_2
    : NOT unary_expression                      {$$ = "!" + $2;}
    | '~' unary_expression                      {$$ = "~" + $2;}
    | SIZE '[' lhs_expression ']'               {$$ = $3 + ".size()";}
    | postfix_expression                        {$$ = $1;}
    ;

unary_expression 
    : NOT unary_expression                      {$$ = "!" + $2;}
    | '~' unary_expression                      {$$ = "~" + $2;}
    | '-' unary_expression_2                      {$$ = "-" + $2;}
    | '+' unary_expression_2                      {$$ = "+" + $2;}
    | SIZE '[' lhs_expression ']'               {$$ = $3 + ".size()";}
    | postfix_expression                        {$$ = $1;}
    ;

expression 
    : unary_expression                                      {$$ = $1;}
    | expression '*' expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression '/' expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression '%' expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression '+' expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression '-' expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression '<' expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression '>' expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression LE_OP expression                           {$$ = $1 + " " + $2 + " " + $3;}
    | expression GE_OP expression                           {$$ = $1 + " " + $2 + " " + $3;}
    | expression EQ_OP expression                           {$$ = $1 + " " + $2 + " " + $3;}
    | expression NE_OP expression                           {$$ = $1 + " " + "!=" + " " + $3;}
    | expression '&' expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression '^' expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression '|' expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression AND expression                             {$$ = $1 + " " + $2 + " " + $3;}
    | expression OR expression                              {$$ = $1 + " " + $2 + " " + $3;}
    ;

assignment_statement    
    : expression                                            {$$ = $1;}
    | lhs_expression '=' assignment_statement               {$$ = $1 + " = " + $3;}
    ;

lhs_expression
    : IDENTIFIER                                            {$$ = $1;}
    | IDENTIFIER map_array                                  {$$ = $1 + $2;}
    ;

declaration_statement
    : declaration_specifier init_declarator_list       {$$ = $1 + " " + $2;}
    ;

declaration_specifier
    : type_specifier                                            {$$ = $1;}
    | '[' declaration_specifier ']'                             {$$ = "std::deque<" + $2 + ">";} 
    | '{' declaration_specifier ':' declaration_specifier '}'   {$$ = "std::map<" + $2 + ">";} 
    ;

init_declarator_list
    : init_declarator                               {$$ = $1;}
    | init_declarator_list ',' init_declarator      {$$ = $1 + ", " + $3;}
    ;

init_declarator
    : declarator                    {$$ = $1;}
    | declarator '=' initializer    {$$ = $1 + " = " + $3;}
    ;

type_specifier
    : INT           {$$ = int_type;}
    | FLOAT         {$$ = float_type;}
    | INT CONST     {$$ = "const " + int_type;}
    | FLOAT CONST   {$$ = "const " + float_type;}
    ;

declarator
    : IDENTIFIER    {$$ = $1;}
    ;

initializer
    : assignment_statement  {$$ = $1;}
    ;

push_pop_statement
    : lhs_expression BACKWARD_ACCESS '[' expression ']'             {$$ = $1 + ".push_back(" + $4 + ")";}
    | '[' expression ']' FORWARD_ACCESS lhs_expression              {$$ = $5 + ".push_front(" + $2 + ")";}
    | lhs_expression FORWARD_ACCESS '[' lhs_expression ']'          {$$ = $4 + " = " + $1 + ".back();\n" + $1 + ".pop_back()";}
    | '[' expression ']' BACKWARD_ACCESS lhs_expression             
    {
        $$ = $2 + " = " + $5 + ".front();\n" + $5 + ".pop_front()";
        std::regex re{R"~([a-zA-Z_]([a-zA-Z_]|[0-9])*(\[.*\])*)~"};
        if (!std::regex_match($2, re)) {
            std::cout << "syntax error\n" << $2 << ' ';
            exit(0);
        }
    }
    | lhs_expression FORWARD_ACCESS '[' ']'                         {$$ = $1 + ".pop_back()";}
    | '[' ']' BACKWARD_ACCESS lhs_expression                        {$$ = $4 + ".pop_front()";}
    ; 

compound_statement
	: '<' '>'                   {$$ = "{}";}
	| '<' statement_list '>'    {$$ = "{\n" + $2 + "\n}";}
	;

optional_expression
	:                           {$$ = "";}
	| expression                {$$ = $1;}
	;

loop_statement:
    {fprintf(parser_log, "%d : Loop Statement\n", yylineno);} iteration_statement   {$$ = $2;}

iteration_statement
    : LOOP '(' assignment_statement ';' optional_expression ';' optional_assignment ')' ':' compound_statement optional_finally      {$$ = "for(" + $3 + ";" + $5 + ";) " + $10.substr(0, $10.size() - 1) + $7 + ";" + ($11.size() == 0 ? "\n}" : "\nif (!(" + $5 + ")) " + $11 + "\n}");}
    | LOOP '(' declaration_statement ';' optional_expression ';' optional_assignment ')' ':' compound_statement optional_finally     {$$ = "for(" + $3 + ";" + $5 + ";) " + $10.substr(0, $10.size() - 1) + $7 + ";" + ($11.size() == 0 ? "\n}" : "\nif (!(" + $5 + ")) " + $11 + "\n}");}
    | LOOP '(' ';' optional_expression ';' optional_assignment ')' ':' compound_statement optional_finally                           {$$ = "for(;" + $4 + ";) " + $10.substr(0, $9.size() - 1) + $6 + ";" + ($10.size() == 0 ? "\n}" : "\nif (!(" + $4 + ")) " + $10 + "\n}");}
	;

optional_finally
    :                                      {$$ = "";} 
    | FINALLY ':' compound_statement     {$$ = $3;}
    ;

optional_assignment
    :                       {$$ = "";}
    | assignment_statement  {$$ = $1;}
    ;

return_statement
	: RETURN VOID           {$$ = $1;}
	| RETURN expression     {$$ = $1 + " " + $2;}
	;

print_statement
    : PRINT '(' expression ')'  {$$ = "std::cout << " + $3 + " << '\\n'";}
    ;

chaining_if_else 
    : expression '?' statement_list                             {$$ = "if (" + $1 + ") {\n " + $3 + "\n}";}
    | expression '?' statement_list ELSE ':' statement_list     {$$ = "if (" + $1 + ") {\n " + $3 + "\n} else {\n" + $6 + "\n}";}
    | expression '?' statement_list chaining_if_else            {$$ = "if (" + $1 + ") {\n " + $3 + "\n} else " + $4;}
    ;

if_else_statement
    : '<' chaining_if_else '>'  {$$ = $2;}
    ;

statement
	: assignment_statement ';'  {$$ = $1 + ";"; fprintf(parser_log, "%d : Assignment Statement\n", yylineno);}
	| compound_statement        {$$ = $1;}
	| loop_statement            {$$ = $1;}
	| return_statement ';'      {$$ = $1 + ";"; fprintf(parser_log, "%d : Return Statement\n", yylineno);}
    | print_statement ';'       {$$ = $1 + ";"; fprintf(parser_log, "%d : Print Statement\n", yylineno);}
    | push_pop_statement ';'    {$$ = $1 + ";"; fprintf(parser_log, "%d : Push Pop Statement\n", yylineno);}
    | if_else_statement         {$$ = $1; fprintf(parser_log, "%d : Conditional Statement\n", yylineno);}
    | declaration_statement ';' {$$ = $1 + ";"; fprintf(parser_log, "%d : Variable Declaration\n", yylineno);}
    | ';'                       {$$ = $1;}
    ;

statement_list
	: statement                 {$$ = $1;}
	| statement_list statement  {$$ = $1 + "\n" + $2;}
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
    lexer_log = fopen("lexer_log.txt", "w");
    parser_log = fopen("parser_log.txt", "w");
    yyparse(); 
}