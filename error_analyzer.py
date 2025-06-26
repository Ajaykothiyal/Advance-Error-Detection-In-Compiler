import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
import joblib
import re

class ErrorAnalyzer:
    def __init__(self):
        # Initialize the vectorizer and classifier
        self.vectorizer = TfidfVectorizer()
        self.classifier = MultinomialNB()
        
        # Common error patterns and their explanations
        self.error_patterns = {
            'undefined_variable': {
                'pattern': r"identifier \"(\w+)\" is undefined|Undefined variable|'(\w+)' is undefined", 
                'explanation': "The variable '{var}' is being used before it is declared. Variables must be declared before use.",
                'fix': "Declare the variable before using it: 'int {var};' or 'float {var};' etc."
            },
            'type_mismatch': {
                'pattern': r"Type mismatch in assignment: expected (\w+), got (\w+)|cannot convert from '(\w+)' to '(\w+)'|Type mismatch",
                'explanation': "Type mismatch: trying to assign a {got_type} value to a {expected_type} variable.",
                'fix': "Use explicit type casting or convert the value to the correct type. For example: 'x = ({expected_type})y;'"
            },
            'uninitialized_variable': {
                'pattern': r"variable '(\w+)' is uninitialized|Uninitialized variable|'(\w+)' is uninitialized",
                'explanation': "The variable '{var}' is being used without being initialized first.",
                'fix': "Initialize the variable before use: '{var} = value;'"
            },
            'unused_variable': {
                'pattern': r"Unused variable '(\w+)'",
                'explanation': "The variable '{var}' is declared but never used in the code.",
                'fix': "Either use the variable in your code or remove its declaration if it's not needed."
            },
            'syntax_error': {
                'pattern': r"syntax error",
                'explanation': "There is a syntax error in your code. This could be due to missing semicolons, mismatched brackets, or invalid expressions.",
                'fix': "Check for missing semicolons, mismatched brackets, or invalid expressions in the code context."
            }
        }
        
        # Training data for common errors
        self.training_data = [
            ("undefined variable x", "undefined_variable"),
            ("type mismatch int to float", "type_mismatch"),
            ("uninitialized variable y", "uninitialized_variable"),
            ("cannot convert from float to int", "type_mismatch"),
            ("variable z is not declared", "undefined_variable")
        ]
        
        # Train the model
        self._train_model()
    
    def _train_model(self):
        """Train the ML model with the training data"""
        texts, labels = zip(*self.training_data)
        X = self.vectorizer.fit_transform(texts)
        self.classifier.fit(X, labels)
    
    def analyze_error(self, error_message, line_number, code_context):
        """Analyze an error and provide detailed explanation and fix"""
        # Extract error type using pattern matching
        error_type = None
        error_details = ()
        var_name = ''
        from_type = ''
        to_type = ''

        for err_type, pattern_info in self.error_patterns.items():
            match = re.search(pattern_info['pattern'], error_message)
            if match:
                error_type = err_type
                error_details = match.groups()
                break

        # Always try to extract variable name in single quotes from the message
        var_match = re.search(r"'([a-zA-Z_][a-zA-Z0-9_]*)'", error_message)
        if var_match:
            var_name = var_match.group(1)
        # Try to extract variable name after 'variable' or 'Undefined variable'
        elif 'variable' in error_message:
            var_match2 = re.search(r"variable ([a-zA-Z_][a-zA-Z0-9_]*)", error_message)
            if var_match2:
                var_name = var_match2.group(1)
        # Try to extract type names for type mismatch
        if error_type == 'type_mismatch':
            type_match = re.search(r"'(\w+)'", error_message)
            if type_match:
                from_type = type_match.group(1)
            type_match2 = re.search(r"to '(\w+)'", error_message)
            if type_match2:
                to_type = type_match2.group(1)
        # If error_details is empty or first element is empty, use var_name
        if not error_details or not error_details[0]:
            error_details = (var_name or from_type, to_type)

        # If no pattern match, use ML to classify
        if not error_type:
            X = self.vectorizer.transform([error_message])
            error_type = self.classifier.predict(X)[0]

        # Generate detailed explanation, pass fallback var_name
        explanation = self._generate_explanation(error_type, error_details, code_context, fallback_var=var_name)

        return {
            'error_type': error_type,
            'line_number': line_number,
            'message': error_message,
            'explanation': explanation['explanation'],
            'suggestion': explanation['suggestion'],
            'code_context': code_context
        }
    
    def _generate_explanation(self, error_type, error_details, code_context, fallback_var=None):
        """Generate detailed explanation and fix suggestion"""
        if error_type in self.error_patterns:
            pattern_info = self.error_patterns[error_type]
            # For type mismatch, handle expected/got types
            if error_type == 'type_mismatch':
                expected_type = ''
                got_type = ''
                if error_details and len(error_details) >= 2:
                    # Try to get from new pattern first
                    if error_details[0] and error_details[1]:
                        expected_type = error_details[0]
                        got_type = error_details[1]
                    # Fallback for old pattern
                    elif len(error_details) > 2 and error_details[2] and error_details[3]:
                        got_type = error_details[2]
                        expected_type = error_details[3]
                explanation = pattern_info['explanation'].format(
                    expected_type=expected_type,
                    got_type=got_type
                )
                suggestion = pattern_info['fix'].format(
                    expected_type=expected_type
                )
                return {
                    'explanation': explanation,
                    'suggestion': suggestion
                }
            # Use fallback_var if error_details[0] is empty
            var = error_details[0] if error_details and error_details[0] else fallback_var or ''
            from_type = error_details[0] if len(error_details) > 0 and error_details[0] else ''
            to_type = error_details[1] if len(error_details) > 1 and error_details[1] else ''
            explanation = pattern_info['explanation'].format(
                var=var,
                from_type=from_type,
                to_type=to_type
            )
            suggestion = pattern_info['fix'].format(
                var=var
            )
        else:
            explanation = "An error occurred in your code."
            suggestion = "Review the code for potential issues."
        return {
            'explanation': explanation,
            'suggestion': suggestion
        }

# Example usage
if __name__ == "__main__":
    analyzer = ErrorAnalyzer()
    
    # Test with some example errors
    test_errors = [
        ("identifier \"x\" is undefined", 10, "x = 5;"),
        ("cannot convert from 'float' to 'int'", 15, "int x = 3.14;"),
        ("variable 'y' is uninitialized", 20, "int y; int z = y + 5;")
    ]
    
    for error_msg, line, context in test_errors:
        result = analyzer.analyze_error(error_msg, line, context)
        print(f"\nError at line {result['line_number']}:")
        print(f"Message: {result['message']}")
        print(f"Explanation: {result['explanation']}")
        print(f"Suggestion: {result['suggestion']}")
        print(f"Context: {result['code_context']}") 