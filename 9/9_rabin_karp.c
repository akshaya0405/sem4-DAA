#include <stdio.h>
#include <string.h>

#define d 256  // Number of possible characters in the input alphabet
#define q 101  // A prime number used for hashing

int rabin_karp(char* text, char* pattern) {
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);
    int i, j;
    int pattern_hash = 0;  // Hash value for the pattern
    int text_hash = 0;  // Hash value for the current text window
    int h = 1;  // Used to calculate hash values for the text windows

    // Calculate the value of h as (d^(m-1)) % q
    for (i = 0; i < pattern_length - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value for the pattern and the first window of text
    for (i = 0; i < pattern_length; i++) {
        pattern_hash = (d * pattern_hash + pattern[i]) % q;
        text_hash = (d * text_hash + text[i]) % q;
    }

    // Slide the window of text over the input text one character at a time
    for (i = 0; i <= text_length - pattern_length; i++) {
        // Check if the hash values of the current window of text and the pattern match
        if (text_hash == pattern_hash) {
            // Check if the characters in the current window of text and the pattern match
            for (j = 0; j < pattern_length; j++) {
                if (text[i+j] != pattern[j]) {
                    break;
                }
            }

            // If the characters match, we have found a match
            if (j == pattern_length) {
                return i;
            }
        }

        // Calculate the hash value for the next window of text
        if (i < text_length - pattern_length) {
            text_hash = (d * (text_hash - text[i] * h) + text[i+pattern_length]) % q;

            // Make sure the hash value is positive
            if (text_hash < 0) {
                text_hash += q;
            }
        }
    }

    // If we get here, no match was found
    return -1;
}

int main() {
    char text[1000], pattern[1000];

    // Get input from the user
    printf("Enter the text: ");
    fgets(text, 1000, stdin);
    printf("Enter the pattern to search for: ");
    fgets(pattern, 1000, stdin);

    // Remove the newline character at the end of the strings
    text[strcspn(text, "\n")] = 0;
    pattern[strcspn(pattern, "\n")] = 0;
    // Call the Rabin-Karp algorithm and print the result
    int result = rabin_karp(text, pattern);
    if (result == -1) {
        printf("Pattern not found in text.\n");
    } else {
        printf("Pattern found in text starting at index %d.\n", result);
    }

    return 0;
}