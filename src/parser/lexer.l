%{
#include <stdio.h>
#include "y.tab.h"

void count();
%}

D			[0-9]
L			[a-zA-Z_]

%%

"["             {count(); return '[';}
"]"             {count(); return ']';}
"{"             {count(); return '{';}
"}"             {count(); return '}';}
"("             {count(); return '(';}
")"             {count(); return ')';}
":"             {count(); return ':';}
";"             {count(); return ';';}
"<"             {count(); return '<';}
">"             {count(); return '>';}
"?"             {count(); return '?';}
","             {count(); return ',';}

"set"           {count(); return SET;}
"if"            {count(); return IF;}
"else"          {count(); return ELSE;}
"size"          {count(); return SIZE;}
"loop"          {count(); return LOOP;}
"finally"       {count(); return FINALLY;}
"return"        {count(); return RETURN;}
"func"          {count(); return FUNC;}
"print"         {count(); return PRINT;}

"int"           {count(); return INT;}
"float"         {count(); return FLOAT;}
"big"           {count(); return BIG;}
"small"         {count(); return SMALL;}
"constant"      {count(); return CONST;}

"->"            {count(); return FORWARD_ACCESS;}
"<-"            {count(); return BACKWARD_ACCESS;}

"+"             {count(); return '+';}
"-"             {count(); return '-';}
"*"             {count(); return '*';}
"/"             {count(); return '/';}
"%"             {count(); return '%';}
"="             {count(); return '=';}

"|"             {count(); return '|';}
"&"             {count(); return '&';}
"^"             {count(); return '^';}
"~"             {count(); return '~';}

"or"            {count(); return OR;}
"and"           {count(); return AND;}
"not"           {count(); return NOT;}

"<="            {count(); return LE_OP;}
">="            {count(); return GE_OP;}
"<>"            {count(); return NE_OP;}
"=="            {count(); return EQ_OP;}
"!"             {count(); return '!';}

{L}({D}|{L})*    {count(); return IDENTIFIER;}
{D}+            {count(); return CONSTANT;}
{D}+\.{D}*      {count(); return CONSTANT;}
{D}*\.{D}+      {count(); return CONSTANT;}

#.*\n           ; /* comment */
[ \t\v\n\f]     {}
.               {/* Ignore bad characters */}


%%

void count() {
    // ECHO;
}