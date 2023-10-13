#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **lines = NULL; // Pointer to an array of strings (lines)
    size_t numLines = 0; // Number of lines read
    char buffer[1024]; // Buffer to read each line

    printf("Enter lines of text. Enter an empty line to stop.\n");

    while (1) {
        // Read a line of text
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break; // End of input or an error occurred
        }

        // Remove the newline character, if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Dynamically allocate memory for the line and copy it
        char *line = strdup(buffer);
        if (line == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        // Resize the array of lines
        lines = (char **)realloc(lines, (numLines + 1) * sizeof(char *));
        if (lines == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        // Store the line in the array
        lines[numLines] = line;
        numLines++;
    }

    // Print the stored lines
    printf("\nStored lines:\n");
    for (size_t i = 0; i < numLines; i++) {
        printf("Line %zu: %s\n", i + 1, lines[i]);
        free(lines[i]); // Free the memory for each line
    }
    
    free(lines); // Free the array of lines

    return 0;
}
