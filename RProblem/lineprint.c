#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac != 3)
    {
        printf("Usage %s <line number> <file name>\n", av[0]);
        exit(1);
    }
    int n = atoi(av[1]);
    if (n <= 0)
    {
        printf("Line number should be positive integer\n");
        exit(1);
    }
    FILE *fp = fopen("inputtext.txt", "r");
    int current_line = 1; char c;
    while (current_line < n)
    {
        do
        {
            c = fgetc(fp);
        }
        while (c != EOF && c != '\n');
        if (EOF == c)
        {
            printf("Not enough line\n");
            exit(1);
        }
        current_line++;
    }
    while (EOF != (c = fgetc(fp)))
    {
        putchar(c);
        if (c == '\n')
        {
            break;
        }
    }
    
}