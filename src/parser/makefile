BUILD_DIR = ../../build
LEX_FILE = ../lexer/lexer.l
YACC_FILE = parser.y
LEX_C = lex.yy.c
YACC_C = y.tab.c
YACC_H = y.tab.h
EXECUTABLE = $(BUILD_DIR)/main.o

all: main1 main2 main3

main1: $(LEX_FILE)
	lex $(LEX_FILE)

main2: $(YACC_FILE)
	yacc $(YACC_FILE) -d

main3: $(LEX_C) $(YACC_C)
	g++ -o $(EXECUTABLE) $(YACC_C)
	g++ -o main.o $(YACC_C)

clean:
	rm -f $(LEX_C) $(YACC_C) $(YACC_H) $(EXECUTABLE) main.o