#include <stdio.h>
#include <string.h>

// Function to perform brute force string matching
void bruteForceStringMatch(char *text, char *pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    // Iterate over each position in the text
    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        
        // Check for a match of the pattern at the current position
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        
        // If the pattern was found, print the position
        if (j == patternLength) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "THIS IS A SIMPLE EXAMPLE";
    char pattern[] = "SIMPLE";
    
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    
    bruteForceStringMatch(text, pattern);
    
    return 0;
}
