#include <stdio.h>
#include <string.h>

int search(char words[], char uwords[][100], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(words, uwords[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

void sort(char uwords[][100], int counter[], int count)
{
    char temp[100];
    int min, temp_int, j;

    for (int i = 0; i < count - 1; i++)
    {
        min = i;
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(uwords[j], uwords[i]) < 0)
            {
                min = j;
            }
        }
        strcpy(temp, uwords[i]);
        strcpy(uwords[i], uwords[min]);
        strcpy(uwords[min], temp);

        temp_int = counter[i];
        counter[i] = counter[min];
        counter[min] = temp_int;
    }
}

int main()
{
    printf("Please enter number of string: ");
    int n;
    scanf("%d", &n);
    char words[n][100];

    FILE *fp = fopen("input.txt", "r");
    if (NULL == fp)
    {
        printf("File can not be opened\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s", words[i]);
    }

    fclose(fp);

    char uwords[n][100];
    int counter[n];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (search(words[i], uwords, count) == -1)
        {
            strcpy(uwords[count], words[i]);
            counter[count] = 1;
            count++;
        }
        else
        {
            counter[search(words[i], uwords, count)]++;
        }
    }

    sort(uwords, counter, count);

    for (int i = 0; i < count; i++)
    {
        printf("%s %d\n", uwords[i], counter[i]);
    }
}