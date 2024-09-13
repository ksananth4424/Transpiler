%{
#include <stdio.h>
#include "y.tab.h"

void count();
%}

D			[0-9]
L			[a-zA-Z_]

%%

{L}[{D}{L}]*    {return IDENTIFIER;}

"constant"      {return "CONSTANT";}
"constant"      {return "CONSTANT"}

"["             {return '[';}
"]"             {return ']';}
"{"             {return '{';}
"}"             {return '}';}
"("             {return '(';}
")"             {return ')';}
":"             {return ':';}
";"             {return ';';}
"<"             {return '<';}
">"             {return '>';}
"?"             {return '?';}

"set"           {return SET;}
"if"            {return IF;}
"else"          {return ELSE;}
"size"          {return SIZE;}
"loop"          {return LOOP;}
"finally"       {return FINALLY;}
"return"        {return RETURN;}
"func"          {return FUNC;}
"print"         {return PRINT;}

"int"           {return INT;}
"float"         {return FLOAT;}
"big"           {return BIG;}
"small"         {return SMALL;}

"->"            {return FORWARD_ACCESS;}
"<-"            {return BACKWARD_ACCESS;}

"+"             {return '+';}
"-"             {return '-';}
"*"             {return '*';}
"/"             {return '/';}
"%"             {return '%';}

"|"             {return '|';}
"&"             {return '&';}
"^"             {return '^';}
"~"             {return '~';}

"or"            {return OR;}
"and"           {return AND;}
"not"           {return NOT;}

"<="            {return LE_OP;}
">="            {return GE_OP;}
"<>"            {return NE_OP;}
"!"             {return '!';}

#.*\n           ; /* comment */
.               {/* Ignore bad characters */}