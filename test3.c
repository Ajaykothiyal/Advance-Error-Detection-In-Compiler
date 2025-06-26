// Test file for advanced error detection
int main() {
    int a = 10;
    float b;
    char c;
    int d;
    
    // Type mismatch
    a = b; // Should generate type mismatch error
    
    // Undefined variable
    e = 5; // Should generate undefined variable error
    
    // Uninitialized variable
    int result = d + 2; // Should generate uninitialized variable error
    
    // Unused variable
    int unused_var;
    
    // Syntax error
    if (a > 5) {
        b = 3.14;
    // Missing closing brace for if statement
    
    return 0;
} 