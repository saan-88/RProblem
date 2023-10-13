#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    getchar();

    char array[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &array[i][j]);
            getchar();
        }
        
    }

    getchar();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", array[i][j]);
        }
    }
}