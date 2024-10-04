# Transpiler

This is a project to convert a language as given in the problem statement and transpile it to C++ code.

## File Structure

The file structure of the Transpiler is shown below:

```plaintext
Transpiler
├── build
│   └── Makefile
├── README
├── src
│   ├── lexer
│   │   └── lexer.l
│   ├── parser
│   │   ├── makefile
│   │   └── parser.y
├── test
│   ├── input
│   ├── output
│   ├── parsed
│   ├── printed
│   ├── tokens
│   └── incorrect_input
```

## Build and Run

In order to build and run this project, follow the commands listed below:

    $ cd build
    $ make

This will create all the required files according to the input files in the ./test/input directory. It produces the following outputs:

-> Transpiled C++ code in the ./test/output directory \
-> Result of the compiled and executed file in the ./test/printed directory \
-> Tokens log file in the ./test/tokens directory \
-> Parser log file in the ./test/parsed directory for the corresponding input file

Additionally, it runs the incorrect test cases present in the ./test/incorrect_input directory and provides syntax errors accordingly.

## Cleaning the Project

To clean the project, run the following command:

    $ make clean

This command will remove all the files created by the Makefile in the build directory.

## Notes:

-> The main.o object file after build will be present in both the build folder and the ./src/parser directory, as our build process works that way. \
-> Testing of files happens in lexicographical order. \
-> Please ignore any warnings that might pop up. The project works end-to-end perfectly.
