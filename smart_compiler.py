import subprocess
import sys
from error_analyzer import ErrorAnalyzer
import re

def get_code_context(filename, line_number, context_lines=2):
    """Get the code context around the error line"""
    try:
        with open(filename, 'r') as f:
            lines = f.readlines()
            start = max(0, line_number - context_lines - 1)
            end = min(len(lines), line_number + context_lines)
            return ''.join(lines[start:end])
    except:
        return ""

def main():
    if len(sys.argv) < 2:
        print("Usage: python smart_compiler.py <source_file.c>")
        sys.exit(1)

    source_file = sys.argv[1]
    # Run the compiler and capture errors
    result = subprocess.run([".\\compiler.exe", source_file], capture_output=True, text=True)
    error_lines = result.stderr.strip().split('\n') if result.stderr else []
    error_lines += [line for line in result.stdout.strip().split('\n') if line.startswith('Error at line')]

    if error_lines:
        print("=== Compilation Errors ===")
        analyzer = ErrorAnalyzer()
        for line in error_lines:
            # Parse error line: Error at line X: ...
            match = re.match(r"Error at line (\d+): (.+)", line)
            if match:
                line_number = int(match.group(1))
                message = match.group(2)
                code_context = get_code_context(source_file, line_number)
                analyzed = analyzer.analyze_error(message, line_number, code_context)

                print(f"Error at line {analyzed['line_number']}:")
                print(f"Message: {analyzed['message']}")
                print(f"Explanation: {analyzed['explanation']}")
                print(f"Suggestion: {analyzed['suggestion']}")
                print(f"Code context:\n{analyzed['code_context'].strip()}")
            else:
                print(line)
    else:
        print("Compilation successful. No errors found.")

if __name__ == "__main__":
    main() 