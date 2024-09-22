%{
#include <stdio.h>
#include "y.tab.h"

void count();
%}

%option yylineno

D			[0-9]
L			[a-zA-Z_]

%%

"["             {count(); fprintf(lexer_log, "%d : Punctuation : Access Operator : [\n", yylineno); return '[';}
"]"             {count(); fprintf(lexer_log, "%d : Punctuation : Access Operator : ]\n", yylineno); return ']';}
"{"             {count(); fprintf(lexer_log, "%d : Punctuation : {\n", yylineno); return '{';}
"}"             {count(); fprintf(lexer_log, "%d : Punctuation : }\n", yylineno); return '}';}
"("             {count(); fprintf(lexer_log, "%d : Punctuation : (\n", yylineno); return '(';}
")"             {count(); fprintf(lexer_log, "%d : Punctuation : )\n", yylineno); return ')';}
":"             {count(); fprintf(lexer_log, "%d : Punctuation : :\n", yylineno); return ':';}
";"             {count(); fprintf(lexer_log, "%d : Punctuation : ;\n", yylineno); return ';';}
"<"             {count(); fprintf(lexer_log, "%d : Comparision Operator : Punctuation : <\n", yylineno); return '<';}
">"             {count(); fprintf(lexer_log, "%d : Comparision Operator : Punctuation : >\n", yylineno); return '>';}
"?"             {count(); fprintf(lexer_log, "%d : Punctuation : ?\n", yylineno); return '?';}
","             {count(); fprintf(lexer_log, "%d : Punctuation : ,\n", yylineno); return ',';}

"set"           {count(); fprintf(lexer_log, "%d : Reserved Word : set\n", yylineno); return SET;}
"else"          {count(); fprintf(lexer_log, "%d : Reserved Word : else\n", yylineno); return ELSE;}
"size"          {count(); fprintf(lexer_log, "%d : Reserved Word : size\n", yylineno); return SIZE;}
"loop"          {count(); fprintf(lexer_log, "%d : Reserved Word : loop\n", yylineno); return LOOP;}
"finally"       {count(); fprintf(lexer_log, "%d : Reserved Word : finally\n", yylineno); return FINALLY;}
"return"        {count(); fprintf(lexer_log, "%d : Reserved Word : return\n", yylineno); return RETURN;}
"func"          {count(); fprintf(lexer_log, "%d : Reserved Word : func\n", yylineno); return FUNC;}
"print"         {count(); fprintf(lexer_log, "%d : Reserved Word : print\n", yylineno); return PRINT;}

"int"           {count(); fprintf(lexer_log, "%d : Type : int\n", yylineno); return INT;}
"float"         {count(); fprintf(lexer_log, "%d : Type : float\n", yylineno); return FLOAT;}
"big"           {count(); fprintf(lexer_log, "%d : Type : big\n", yylineno); return BIG;}
"small"         {count(); fprintf(lexer_log, "%d : Type : small\n", yylineno); return SMALL;}
"constant"      {count(); fprintf(lexer_log, "%d : Type : constant\n", yylineno); return CONST;}
"void"          {count(); fprintf(lexer_log, "%d : Type : void\n", yylineno); return VOID;}

"->"            {count(); fprintf(lexer_log, "%d : Access Operator : ->\n", yylineno); return FORWARD_ACCESS;}
"<-"            {count(); fprintf(lexer_log, "%d : Access Operator : <-\n", yylineno); return BACKWARD_ACCESS;}

"+"             {count(); fprintf(lexer_log, "%d : Arithmetic Operator : +\n", yylineno); return '+';}
"-"             {count(); fprintf(lexer_log, "%d : Arithmetic Operator : -\n", yylineno); return '-';}
"*"             {count(); fprintf(lexer_log, "%d : Arithmetic Operator : *\n", yylineno); return '*';}
"/"             {count(); fprintf(lexer_log, "%d : Arithmetic Operator : /\n", yylineno); return '/';}
"%"             {count(); fprintf(lexer_log, "%d : Arithmetic Operator : %%\n", yylineno); return '%';}
"="             {count(); fprintf(lexer_log, "%d : Assignment Operator : =\n", yylineno); return '=';}

"|"             {count(); fprintf(lexer_log, "%d : Bitwise Operator : |\n", yylineno); return '|';}
"&"             {count(); fprintf(lexer_log, "%d : Bitwise Operator : &\n", yylineno); return '&';}
"^"             {count(); fprintf(lexer_log, "%d : Bitwise Operator : ^\n", yylineno); return '^';}
"~"             {count(); fprintf(lexer_log, "%d : Bitwise Operator : ~\n", yylineno); return '~';}

"or"            {count(); fprintf(lexer_log, "%d : Logical Operator : or\n", yylineno); return OR;}
"and"           {count(); fprintf(lexer_log, "%d : Logical Operator : and\n", yylineno); return AND;}
"not"           {count(); fprintf(lexer_log, "%d : Logical Operator : not\n", yylineno); return NOT;}

"<="            {count(); fprintf(lexer_log, "%d : Comparision Operator : <=\n", yylineno); return LE_OP;}
">="            {count(); fprintf(lexer_log, "%d : Comparision Operator : >=\n", yylineno);} return GE_OP; 
"<>"            {count(); fprintf(lexer_log, "%d : Comparision Operator : <>\n", yylineno); return NE_OP;}
"=="            {count(); fprintf(lexer_log, "%d : Comparision Operator : ==\n", yylineno); return EQ_OP;}
"!"             {count(); fprintf(lexer_log, "%d : Comparision Operator : !\n", yylineno); return '!'; }

{L}({D}|{L})*   {count(); fprintf(lexer_log, "%d : Identifier : %s\n", yylineno, yytext); return IDENTIFIER;}
{D}+            {count(); fprintf(lexer_log, "%d : Constant : %s\n", yylineno, yytext); return CONSTANT;}
{D}+\.{D}*      {count(); fprintf(lexer_log, "%d : Constant : %s\n", yylineno, yytext); return CONSTANT;}
{D}*\.{D}+      {count(); fprintf(lexer_log, "%d : Constant : %s\n", yylineno, yytext); return CONSTANT;}

#.*\n           ; {fprintf(lexer_log, "%d : Comment : %s", yylineno, yytext);}
[ \t\v\n\f]     {}
.               {/* Ignore bad characters */}


%%

void count() {
    // ECHO;
    yylval = yytext;
}