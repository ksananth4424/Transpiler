%{
#include <iostream>
#include <fstream>

FILE* lexer_log;
FILE* parser_log;

class stack_type {
public:
    std::string value;
    stack_type() {}
    stack_type(const stack_type& other) {
        this->value = other.value;
    }

    stack_type operator=(const stack_type& r) {
        stack_type res;
        res.value = this->value = r.value;
        return res;
    }

    stack_type operator=(const char* r) {
        stack_type res;
        res.value = this->value = r;
        return res;
    }

    stack_type operator=(const std::string& r) {
        stack_type res;
        res.value = this->value = r;
        return res;
    }
};

stack_type operator+(const stack_type& l, const stack_type& r) {
    stack_type res;
    res.value = l.value + r.value;
    return res;
}

stack_type operator+(const char* l, const stack_type& r) {
    stack_type res;
    res.value = l + r.value;
    return res;
}

stack_type operator+(const stack_type& l, const char* r) {
    stack_type res;
    res.value = l.value + r;
    return res;
}

std::ostream& operator<<(std::ostream& COUT, const stack_type& r) {
    COUT << r.value;
    return COUT;
}

#define YYSTYPE stack_type
#include "lex.yy.c"

extern int yywrap();
extern void yyerror(char*);
std::string int_type = "int";
std::string float_type = "float";


%}

%token IDENTIFIER CONSTANT
%token OR AND NOT
%token LE_OP GE_OP NE_OP EQ_OP
%token FORWARD_ACCESS BACKWARD_ACCESS
%token INT FLOAT BIG SMALL CONST VOID
%token SET ELSE SIZE LOOP FINALLY RETURN FUNC PRINT


%start start_rule
/* %type <n> start_rule */
/* %type <n> program_body */
/* %type <n> set_up_section */
/* %type <n> function_declaration */
/* %type <n> parameter_list */
/* %type <n> parameter */
/* %type <n> primary_expression */
/* %type <n> function_call */
/* %type <n> argument_expression_list */
/* %type <n> map_array */
/* %type <n> postfix_expression */
/* %type <n> unary_expression */
/* %type <n> multiplicative_expression */
/* %type <n> additive_expression */
/* %type <n> relational_expression */
/* %type <n> equality_expression */
/* %type <n> and_expression */
/* %type <n> exclusive_or_expression */
/* %type <n> inclusive_or_expression */
/* %type <n> logical_and_expression */
/* %type <n> logical_or_expression */
/* %type <n> expression */
/* %type <n> assignment_statement */
/* %type <n> declaration_statement */
/* %type <n> declaration_specifier */
/* %type <n> init_declarator_list */
/* %type <n> init_declarator */
/* %type <n> type_specifier */
/* %type <n> declarator */
/* %type <n> initializer */
/* %type <n> push_pop_statement */
/* %type <n> compound_statement */
/* %type <n> expression_statement */
/* %type <n> iteration_statement */
/* %type <n> return_statement */
/* %type <n> print_statement */
/* %type <n> chaining_if_else */
/* %type <n> if_else_statement */
/* %type <n> statement */
/* %type <n> statement_list */
%%

start_rule
    : set_up_section program_body {
        puts("\nsuccess");
        $$ = "#include<bits/stdc++.h>\n" + $1 + "\n" + $2;
        std::ofstream output("transpiled_cpp.cpp");
        if (output.is_open()) {
            // Write the content to the file
            output << $$;
            // Close the file
            output.close();
        } else {
            std::cerr << "Unable to open file for writing" << std::endl;
        }
    }

program_body
    : statement_list    {$$ = "\nint main() {\n" + $1 + "\n}";}
    |                   {$$ = "";}
    ;

set_up_section
    :                                       {$$ = "";}
    | set_up_section function_declaration   {$$ = $1 + "\n" + $2;}
    | set_up_section set_statement          {$$ = $1;}
    ;

function_declaration:
    {fprintf(parser_log, "%d : Function Delaration\n", yylineno);} FUNC IDENTIFIER '(' parameter_list ';' declaration_specifier ')' compound_statement   
    {$$ = $7 + " " + $3 + "(" + $5 + ") " + $9;}
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
    : '(' expression ')'    {$$ = "(" + $2 + ")";}
    | IDENTIFIER            {$$ = $1;}
    | CONSTANT              {$$ = $1;}
    ;

function_call
    : IDENTIFIER '(' ')'                            {$$ = $1 + "()";}
    | IDENTIFIER '(' argument_expression_list ')'   {$$ = $1 + "(" + $3 + ")";}
    ;

argument_expression_list
    : expression                                {$$ = $1;}
    | argument_expression_list ',' expression   {$$ = $1 + ", " + $3;}
    ;    

map_array
    : '[' expression ']'                        {$$ = "[" + $2 + "]";}
    | map_array '[' expression ']'              {$$ = $1 + "[" + $3 + "]";}
    ;

postfix_expression 
    : IDENTIFIER map_array                      {$$ = $1 + $2;}
    | function_call map_array                   {$$ = $1 + $2;}
    | function_call                             {$$ = $1;}  
    | primary_expression                        {$$ = $1;}
    ;

unary_expression 
    : NOT unary_expression                      {$$ = "!" + $2;}
    | '~' unary_expression                      {$$ = "~" + $2;}
    | '-' unary_expression                      {$$ = "-" + $2;}
    | '+' unary_expression                      {$$ = "+" + $2;}
    | SIZE '[' postfix_expression ']'           {$$ = $3 + ".size()";}
    |  postfix_expression                       {$$ = $1;}
    ;

multiplicative_expression 
    : unary_expression                                  {$$ = $1;}
    | multiplicative_expression '*' unary_expression    {$$ = $1 + " * " + $3;}
    | multiplicative_expression '/' unary_expression    {$$ = $1 + " / " + $3;}
    | multiplicative_expression '%' unary_expression    {$$ = $1 + " % " + $3;}
    ;

additive_expression 
    : multiplicative_expression                         {$$ = $1;}
    | additive_expression '-' multiplicative_expression {$$ = $1 + " - " + $3;}
    | additive_expression '+' multiplicative_expression {$$ = $1 + " + " + $3;}
    ;
    
relational_expression
	: additive_expression                               {$$ = $1;}   
	| relational_expression '<' additive_expression     {$$ = $1 + " < " + $3;}
	| relational_expression '>' additive_expression     {$$ = $1 + " > " + $3;}
	| relational_expression LE_OP additive_expression   {$$ = $1 + " <= " + $3;}
	| relational_expression GE_OP additive_expression   {$$ = $1 + " >= " + $3;}
	;

equality_expression
	: relational_expression                             {$$ = $1;}
	| equality_expression EQ_OP relational_expression   {$$ = $1 + " == " + $3;}
	| equality_expression NE_OP relational_expression   {$$ = $1 + " != " + $3;}
	;

and_expression
	: equality_expression                               {$$ = $1;}
	| and_expression '&' equality_expression            {$$ = $1 + " & " + $3;}
	;

exclusive_or_expression
	: and_expression                                    {$$ = $1;}
	| exclusive_or_expression '^' and_expression        {$$ = $1 + " ^ " + $3;}
	;

inclusive_or_expression
	: exclusive_or_expression                               {$$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression   {$$ = $1 + " | " + $3;}
	;

logical_and_expression
	: inclusive_or_expression                               {$$ = $1;}
	| logical_and_expression AND inclusive_or_expression    {$$ = $1 + " && " + $3;}
	;

logical_or_expression
	: logical_and_expression                                {$$ = $1;}
	| logical_or_expression OR logical_and_expression       {$$ = $1 + " || " + $3;}
	;

expression 
    : logical_or_expression                                 {$$ = $1;}
    ;

assignment_statement    
    : expression                                            {$$ = $1;}
    | IDENTIFIER map_array '=' expression                   {$$ = $1 + $2 + " = " + $4;}
    | IDENTIFIER '=' expression                             {$$ = $1 + " = " + $3;}
    ;

declaration_statement
    : declaration_specifier init_declarator_list ';'        {$$ = $1 + " " + $2 + ";";}
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
    : IDENTIFIER BACKWARD_ACCESS '[' expression ']'             {$$ = $1 + ".push_back(" + $4 + ")";}
    | IDENTIFIER map_array BACKWARD_ACCESS '[' expression ']'   {$$ = $1 + $2 + ".push_back(" + $5 + ")";}
    | '[' expression ']' FORWARD_ACCESS IDENTIFIER              {$$ = $5 + ".push_front(" + $2 + ")";}
    | '[' expression ']' FORWARD_ACCESS IDENTIFIER map_array    {$$ = $5 + $6 + ".push_front(" + $2 + ")";}
    | IDENTIFIER FORWARD_ACCESS '[' expression ']'              {$$ = $4 + " = " + $1 + ".back();\n" + $1 + ".pop_back()";}
    | IDENTIFIER map_array FORWARD_ACCESS '[' expression ']'    {$$ = $5 + " = " + $1 + $2 + ".back();\n" + $1 + $2 + ".pop_back()";}
    | '[' expression ']' BACKWARD_ACCESS IDENTIFIER             {$$ = $2 + " = " + $5 + ".front();\n" + $5 + ".pop_front()";}
    | '[' expression ']' BACKWARD_ACCESS IDENTIFIER map_array   {$$ = $2 + " = " + $5 + $6 + ".front();\n" + $5 + $6 + ".pop_front()";}
    | IDENTIFIER FORWARD_ACCESS '[' ']'                         {$$ = $1 + ".pop_back()";}
    | IDENTIFIER map_array FORWARD_ACCESS '[' ']'               {$$ = $1 + $2 + ".pop_back()";}
    | '[' ']' BACKWARD_ACCESS IDENTIFIER                        {$$ = $4 + ".pop_front()";}
    | '[' ']' BACKWARD_ACCESS IDENTIFIER map_array              {$$ = $4 + $5 + ".pop_front()";}
    ; 

compound_statement
	: '<' '>'                   {$$ = "{}";}
	| '<' statement_list '>'    {$$ = "{\n" + $2 + "\n}";}
	;

expression_statement
	: ';'                       {$$ = ";";}
	| expression ';'            {$$ = $1 + ";";}
	;

loop_statement:
    {fprintf(parser_log, "%d : Loop Statement\n", yylineno);} iteration_statement   {$$ = $2;}

iteration_statement
    : LOOP '(' assignment_statement ';' expression_statement assignment_statement ')' ':' compound_statement                            {$$ = "for(" + $3 + "; " + $5 + " " + $6 + ") " + $9;}
    | LOOP '(' assignment_statement ';' expression_statement assignment_statement ')' ':' compound_statement FINALLY ':' statement      {$$ = "for(" + $3 + "; " + $5 + " " + $6 + ") " + $9 + $12;}
    | LOOP '(' declaration_statement expression_statement assignment_statement ')' ':' compound_statement                               {$$ = "for(" + $3 + " " + $4 + " " + $5 + ") " + $8;}
    | LOOP '(' declaration_statement expression_statement assignment_statement ')' ':' compound_statement FINALLY ':' statement         {$$ = "for(" + $3 + " " + $4 + " " + $5 + ") " + $8 + $11;}
    | LOOP '(' ';' expression_statement assignment_statement ')' ':' compound_statement                                                 {$$ = "for( ;" + $4 + " " + $5 + ") " + $8;}
    | LOOP '(' ';' expression_statement assignment_statement ')' ':' compound_statement FINALLY ':' statement                           {$$ = "for( ;" + $4 + " " + $5 + ") " + $8 + $11;}
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
	| return_statement ';'      {$$ = $1 + ";"; std::cout << $1 << ' '; fprintf(parser_log, "%d : Return Statement\n", yylineno);}
    | print_statement ';'       {$$ = $1 + ";"; fprintf(parser_log, "%d : Print Statement\n", yylineno);}
    | push_pop_statement ';'    {$$ = $1 + ";"; fprintf(parser_log, "%d : Push Pop Statement\n", yylineno);}
    | if_else_statement         {$$ = $1; fprintf(parser_log, "%d : Conditional Statement\n", yylineno);}
    | declaration_statement     {$$ = $1; fprintf(parser_log, "%d : Variable Declaration\n", yylineno);}
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