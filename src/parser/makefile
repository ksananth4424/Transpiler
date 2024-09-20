all: main1 main2 main3

main1: lexer.l
	lex lexer.l

main2: parser.y
	yacc parser.y -d

main3:
	gcc -o main.o y.tab.c

clean:
	rm main.o lex.yy.c y.tab.c y.tab.h