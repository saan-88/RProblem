#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello,World,How,are,You";
    const char delim[] = ",";

    // Tokenize the string using strtok
    char *token = strtok(str, delim);

    // Keep looping until all tokens are extracted
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delim); // Pass NULL to continue tokenizing the same string
    }

    return 0;
}
