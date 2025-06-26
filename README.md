# Smart C Compiler with Error Analysis

This project is a smart C compiler front-end built using Flex (Lex) and Bison (Yacc) for lexical analysis and parsing, with additional Python-based error analysis using machine learning. It provides detailed error explanations and suggestions to help users debug their C code more effectively.

## Features

- **Lexical Analysis:** Tokenizes C source code using Flex (`lexer.l`).
- **Parsing:** Parses C code and builds an abstract syntax tree using Bison (`parser.y`).
- **Symbol Table:** Tracks variables, functions, and their usage.
- **Error Detection:** Detects syntax errors, uninitialized/unused variables, type mismatches, and more.
- **Smart Error Analysis:** Python script (`error_analyzer.py`) analyzes compiler errors and provides human-friendly explanations and suggestions using pattern matching and ML.
- **Integrated Workflow:** `smart_compiler.py` runs the compiler and invokes the error analyzer for enhanced feedback.

## Project Structure

- `lexer.l` - Flex specification for lexical analysis.
- `parser.y` - Bison grammar for parsing and semantic analysis.
- `lex.yy.c` - Generated C source from `lexer.l`.
- `parser.tab.c`, `parser.tab.h` - Generated C sources from `parser.y`.
- `compiler.exe` - Compiled C compiler executable.
- `error_analyzer.py` - Python script for advanced error analysis.
- `smart_compiler.py` - Python script to compile C code and analyze errors.
- `test.c`, `test2.c` - Sample C source files for testing.
- `Makefile` - Build instructions.
- `requirements.txt` - Python dependencies for error analysis.

## Requirements

- **C Compiler:** GCC (or compatible)
- **Flex:** For generating the lexer
- **Bison:** For generating the parser
- **Python 3.7+**
- Python packages: `numpy`, `scikit-learn`, `joblib` (see `requirements.txt`)

## Build Instructions

1. **Install dependencies:**
   ```sh
   pip install -r requirements.txt
   ```

2. **Build the compiler:**
   ```sh
   make
   ```

   This will generate `compiler.exe` from `lexer.l` and `parser.y`.

3. **Clean build files:**
   ```sh
   make clean
   ```

## Usage

### Compile and Analyze a C File

Run the smart compiler script with your C source file:

```sh
python smart_compiler.py test.c
```

- The script will compile the file using the generated compiler.
- If errors are found, they will be analyzed and explained by `error_analyzer.py`.

### Run Compiler Directly

You can also run the compiler directly:

```sh
./compiler.exe test.c
```

## Example Output

```
=== Compilation Errors ===
Error at line 10: Variable 'x' is uninitialized
Explanation: The variable 'x' is being used without being initialized first.
Suggestion: Initialize the variable before use: 'x = value;'
Context:     printf("%d", x);
```

## Extending Error Analysis

- Add new error patterns and explanations in [`error_analyzer.py`](c:/Users/rawat/Desktop/Compiler%20PBL/error_analyzer.py).
- The ML model can be retrained with more error samples for improved classification.

## License

This project is for educational purposes.

---

**Authors:**  
- Ajay Kumar Kothiyal , Ayush Rawat , Ajay Pratap Singh Negi , Ritesh Bamola
