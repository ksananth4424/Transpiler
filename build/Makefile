all: lexer parser gcc

lexer:
	lex ../src/lexer/main.l

parser:
	yacc ../src/parser/main.y -d

gcc:
	gcc -o main.o y.tab.c