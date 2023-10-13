#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *word = (char *) calloc (10, sizeof(char));
    scanf("%s", word);
    int n = strlen(word);
    // printf("%d", n);
    printf("%s", word + 1);
}