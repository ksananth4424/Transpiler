SRC_DIR = ../src/parser
INPUT_DIR = ../test/input
INCORRECT_INPUT_DIR = ../test/incorrect_input
OUTPUT_DIR = ../test/output
PRINTED_DIR = ../test/printed
TOKENS_DIR = ../test/tokens
PARSED_DIR = ../test/parsed
OBJECT_FILE = $(SRC_DIR)/main.o
EXECUTABLE = ./main.o

INCORRECT_TEST_FILES = $(wildcard $(INCORRECT_INPUT_DIR)/*.txt)
TEST_FILES = $(wildcard $(INPUT_DIR)/*.txt)
OUTPUT_FILES = $(patsubst $(INPUT_DIR)/%.txt, $(OUTPUT_DIR)/output%.cpp, $(TEST_FILES))

all: build run

build:
	@echo "Building the parser..."
	$(MAKE) -C $(SRC_DIR)

run: $(OBJECT_FILE) $(OUTPUT_FILES) incorrect_inputs

$(OUTPUT_DIR)/output%.cpp: $(OBJECT_FILE) $(INPUT_DIR)/%.txt
	@while [ ! -f $(OBJECT_FILE) ]; do sleep 1; done

	@echo "\e[33m\nTesting correct input$(shell echo $* | sed 's/[^0-9]//g')\e[0m"

	@$(EXECUTABLE) $(INPUT_DIR)/$*.txt > transpiled_cpp.cpp 

	@mv transpiled_cpp.cpp $(OUTPUT_DIR)/output$(shell echo $* | sed 's/[^0-9]//g').cpp
	@mv lexer_log.txt $(TOKENS_DIR)/tokens$(shell echo $* | sed 's/[^0-9]//g').txt
	@mv parser_log.txt $(PARSED_DIR)/parsed$(shell echo $* | sed 's/[^0-9]//g').txt

	@g++ -o temp_binary $(OUTPUT_DIR)/output$(shell echo $* | sed 's/[^0-9]//g').cpp 
	@./temp_binary > $(PRINTED_DIR)/printed$(shell echo $* | sed 's/[^0-9]//g').txt
	@rm temp_binary
	@echo "\e[32mPASSED\e[0m"

incorrect_inputs: $(INCORRECT_TEST_FILES)
	@for file in $^; do \
        NUMBER=$$(echo $$file | sed 's/[^0-9]//g'); \
        echo "\e[33m\nTesting incorrect input$$NUMBER\e[0m"; \
        echo -n "\e[31m"; \
        $(EXECUTABLE) $$file; \
        echo -n "\e[0m"; \
    done
	
	@rm parser_log.txt lexer_log.txt

clean:
	rm -f $(OUTPUT_DIR)/*.cpp $(PRINTED_DIR)/*.txt $(TOKENS_DIR)/*.txt $(PARSED_DIR)/*.txt
	$(MAKE) -C $(SRC_DIR) clean

.PHONY: all build run clean
