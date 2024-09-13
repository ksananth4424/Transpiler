%{
#include <stdio.h>
#include "y.tab.h"

void count();
%}

D			[0-9]
L			[a-zA-Z_]

%%

{L}[{D}{L}]*    {return IDENTIFIER;}

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

"int"           {return INT;}
"float"         {return FLOAT;}
"big"           {return BIG;}
"small"         {return SMALL;}

"+"             {return '+';}
"-"             {return '-';}
"*"             {return '*';}
"/"             {return '/';}
"%"             {return '%';}

"or"            {return OR;}
"and"           {return AND;}
"not"           {return NOT;}

#.*\n           ;
.               {}