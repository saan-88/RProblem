#include <stdio.h>
#include <string.h>


int main()
{
    char word[100];
    scanf("%s", word);
    int length = strlen(word);
    if (word[0] == '-')
    {
        printf("-");
        for(int i = length - 1; i >= 1; i--)
        {
            printf("%c", word[i]);
        }
    }
    else
    {
        for (int i = length - 1; i >= 0; i--)
        {
            printf("%c", word[i]);
        }
    }
}