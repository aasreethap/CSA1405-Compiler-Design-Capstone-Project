#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_INPUT_LENGTH 100
void parseExpression(const char *input) {
    int i = 0;
    int errorDetected = 0;
    printf("Parsing expression: %s\n", input);
    while (input[i] != '\0') {
        if (isdigit(input[i])) {
            printf("Digit '%c' is valid.\n", input[i]);
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            printf("Operator '%c' is valid.\n", input[i]);
        } else if (isspace(input[i])) {
        } else {
            printf("Error: Unexpected character '%c' detected at position %d.\n", input[i], i);
            errorDetected = 1;
            break; 
        }
        i++;
    }
    if (!errorDetected) {
        printf("Expression parsed successfully.\n");
    } else {
        printf("Attempting error recovery...\n");
        while (input[i] != '\0' && !isdigit(input[i]) && input[i] != '+' && input[i] != '-') {
            printf("Skipping invalid character '%c'...\n", input[i]);
            i++;
        }
        if (input[i] == '\0') {
            printf("Error recovery failed: No valid input left.\n");
        } else {
            printf("Error recovery successful: Resuming at character '%c'.\n", input[i]);
        }
    }
}
int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter an arithmetic expression: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    parseExpression(input);
    return 0;
}

