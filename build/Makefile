SRC_DIR = ../src/parser
INPUT_DIR = ../test/input
OUTPUT_DIR = ../test/output
PRINTED_DIR = ../test/printed
TOKENS_DIR = ../test/tokens
PARSED_DIR = ../test/parsed
OBJECT_FILE = $(SRC_DIR)/main.o
EXECUTABLE = ./main.o

TEST_FILES = $(wildcard $(INPUT_DIR)/*.txt)
OUTPUT_FILES = $(patsubst $(INPUT_DIR)/%.txt, $(OUTPUT_DIR)/output%.cpp, $(TEST_FILES))
PRINTED_FILES = $(patsubst $(INPUT_DIR)/%.txt, $(PRINTED_DIR)/printed%.txt, $(TEST_FILES))

all: build run

build:
	@echo "Building the parser..."
	$(MAKE) -C $(SRC_DIR)

run: $(OBJECT_FILE) $(OUTPUT_FILES)

$(OUTPUT_DIR)/output%.cpp: $(OBJECT_FILE) $(INPUT_DIR)/%.txt
	# wait for the object file to be generated
	@while [ ! -f $(OBJECT_FILE) ]; do sleep 1; done

	# supress the output
	$(EXECUTABLE) $(INPUT_DIR)/$*.txt > /dev/null
	mv transpiled_cpp.cpp $(OUTPUT_DIR)/output$*.cpp 
	mv lexer_log.txt $(TOKENS_DIR)/tokens$*.txt
	mv parser_log.txt $(PARSED_DIR)/parsed$*.txt

	# run the generated C++ code and print the output
	g++ -o temp_binary $(OUTPUT_DIR)/output$*.cpp 
	./temp_binary > $(PRINTED_DIR)/printed$*.txt
	rm temp_binary

clean:
	rm -f $(OUTPUT_DIR)/*.cpp $(PRINTED_DIR)/*.txt temp_binary
	$(MAKE) -C $(SRC_DIR) clean

.PHONY: all build run clean
