#include <stdio.h>
#include <stdlib.h>

void Addmatrix(int **matrix1, int **matrix2, int **matrix3, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main()
{
    int row, col;
    printf("Number of row and col: ");
    scanf("%d%d", &row, &col);
    int **matrix1 = (int **) malloc (row * sizeof(int *));
    int **matrix2 = (int **) malloc (row * sizeof(int *));
    int **matrix3 = (int **) malloc (row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix1[i] = (int * ) malloc (col * sizeof(int));
    }

    for (int i = 0; i < row; i++)
    {
        matrix2[i] = (int * ) malloc (col * sizeof(int));
    }

    for (int i = 0; i < row; i++)
    {
        matrix3[i] = (int * ) malloc (col * sizeof(int));
    }

    printf("Input the first matrix: ");
    for (int  i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Input the second matrix: ");
    for (int  i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    Addmatrix(matrix1, matrix2, matrix3, row, col);

    for (int  i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }


}