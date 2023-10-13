#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count = 0;
int len;
char **list;

void insert(char *word, char c, int n)
{
    word[n] = c;
    for (int i = 0; i < n; i++)
    {
        list[count][i] = c;
        int index = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                list[count][index] = word[j];
            }
            else
            {
                list[count][++index] = word[j];
            }
            index++;
        }
        count++;
    }
}

void Permutation(char *word, int n)
{
    if (n == 1)
    {
        list[count][0] = word[0];
        count++;
    }
    else
    {
        Permutation(word + 1, n - 1);
        for (int i = 0; i < count; i++)
        {
            insert(list[i], word[0], n-1);
        }
    }
}


int main()
{
    printf("Enter the string: ");
    char *word = (char *) calloc (20, sizeof(char));
    scanf("%s", word);
    len = strlen(word);

    int num_permutations = 1;
    for (int i = 1; i <= len; i++)
    {
        num_permutations = num_permutations * i;
    }

    list = (char **) malloc (num_permutations * sizeof(char *));
    for (int i = 0; i < num_permutations; i++)
    {
        list[i] = (char *) calloc (len + 1, sizeof(char));
    } 

    Permutation(word, len);

    // char *word = (char *) malloc (10 * sizeof(char));

    // strcpy(list[0], "abcd");
    // count++;

    // printf("%s", list[0]);

    // insert(list[0], 'o', 4);
    // for (int i = 0; i < count; i++)
    // {
    //     printf("%s ", list[i]);
    // }
    
    // Freeing memory
    
    for (int i = 0; i < (tgamma(len + 1)); i++)
    {
        free(list[i]);
    }
    free(list);
}