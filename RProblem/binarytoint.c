#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binaryToInt(char *s, int n)
{
    int sum = 0, x, p = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            printf("Not binary, character: %c\n", s[i]);
            exit(1);
        }
        sum += (s[i] - '0') * pow(2, p++);
    }
    return sum;
}

// int main()
// {
//     char s[20];
//     scanf("%s", s);

//     int n = strlen(s);
//     // printf("%s", s);
//     // for(int i = 0; i < 20; i++)
//     // {
//     //     printf("%d: %c\n", i, s[i]);
//     // }
//     int stoi = binaryToInt(s, n);

//     printf("%d\n", stoi);
// }