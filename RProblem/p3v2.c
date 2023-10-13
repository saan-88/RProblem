#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./binarytoint.c"


int main()
{
    int N;
    scanf("%d", &N);

    char **list = (char **) malloc (N * sizeof(char *));
    for (int i = 0; i < N; i++)
    {
        list[i] = (char *) calloc (20, sizeof(char));
    }

    FILE *fp = fopen("input.txt", "r");
    if (NULL == fp)
    {
        printf("Could not open file\n");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        fgets(list[i], 20, fp);
    }

    int intvalue[N];

    for (int i = 0; i < N; i++)
    {
        intvalue[i] = binaryToInt(list[i], strlen(list[i]) - 1);
    }

    
    




    // Freeing memory
    for (int i = 0; i < N; i++)
    {
        free(list[i]);
    }
    free(list);
}