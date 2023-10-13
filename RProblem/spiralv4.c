#include <stdio.h>
#include <stdlib.h>

int left = 0, right, up = 0, bottom;
int i = 0, j = 0, di = 0, dj = 1;

void changedirection()
{
    if (di == 0 && dj == 1)
    {
        di = 1; dj = 0;
        up++;
    }
    else if (di == 1 && dj == 0)
    {
        di = 0; dj = -1;
        right--;
    }
    else if (di == 0 && dj == -1)
    {
        di = -1; dj = 0;
        bottom--;
    }
    else if (di == -1 && dj == 0)
    {
        di = 0; dj = 1;
        left++;
    }
}

int main()
{
    FILE *fp = fopen("inputmatrix.txt", "r");
    if (NULL == fp)
    {
        printf("Can not open file\n");
        return 1;
    }
    int row, col;
    fscanf(fp, "%d%d", &row, &col);
    // printf("%d %d\n", row, col);
    char **matrix = (char **) malloc (row * sizeof(char *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (char *) malloc (col * sizeof(char));
    }
    fgetc(fp);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fscanf(fp, "%c", &matrix[i][j]);
            fgetc(fp);
        }
    }

    fclose(fp);

    printf("Given matrix is:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Elements of the matrix in spiral order:\n");

    right = col - 1; bottom = row - 1;

    for (int index = 0, matrixsize = row * col; index < matrixsize; index++)
    {
        printf("%c ", matrix[i][j]);
        if ((j == right && dj == 1) || (i == bottom && di == 1) || (j == left && dj == -1) || (i == up && di == -1))
        {
            changedirection();
        }
        
        i = i + di;
        j = j + dj;
    }


    for (int j = 0; j < row; j++)
    {
        free(matrix[j]);
    }
    free(matrix);

    fclose(fp);
    return 0;
}