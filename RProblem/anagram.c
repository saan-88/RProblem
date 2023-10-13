#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *string2, int i, int j)
{
    char temp = string2[i];
    string2[i] = string2[j];
    string2[j] = temp;
}

int main()
{
    char *string1, *string2;
    string1 = (char *) calloc (100, sizeof(char));
    string2 = (char *) calloc (100, sizeof(char));
    printf("Enter the first string: ");
    scanf("%s", string1);
    printf("Enter the second string: ");
    scanf("%s", string2);

    int len1, len2;
    len1 = strlen(string1);
    len2 = strlen(string2);

    if (len1 != len2)
    {
        printf("Not anagram\n");
        return 0;
    }

    for (int i = 0; i < len1; i++)
    {
        for (int j = i; j < len2; j++)
        {
            if (string1[i] == string2[j])
            {
                swap(string2, i, j);
                break;
            }
            if (j == len2 - 1)
            {
                printf("Not anagram\n");
                return 0;
            }
        }
    }
    printf("Anagram\n");
}