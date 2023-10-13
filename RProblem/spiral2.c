#include<stdio.h>
#include<stdlib.h>

void spiralmatrix(int n)
{   
    int rowstart, colstart, rowend, colend,numb,i,row,col;
    int **matrix=(int**)malloc(row*sizeof(int));
    for(int i=0;i<n;i++)
    {
        matrix[i]=(int*)malloc(row*sizeof(int));
    }
    rowstart=0;
    rowend=n-1;
    colstart=0;
    colend=n-1;
    numb=1;
    while(rowstart<=rowend && colstart<=colend)
    {
        for(i=colstart;i<=colend;i++)
        {
        matrix[rowstart][i]=numb;
        numb++;
        }
        rowstart++;
        for(i=rowstart; i<=rowend;i++)
        {
        matrix[i][colend]=numb;
        numb++;
        }
        colend--;
        for(i=colend;i>=colstart;i--)
        {
        matrix[rowend][i]=numb;
        numb++;
        }
        rowend--;
        for(i=rowend; i>=rowstart;i--)
        {
        matrix[i][colstart]=numb;
        numb++;
        }
        colstart++;
    }
    for(int i=0; i<n; i++)
    {
       for(int j=0; j<n; j++)
       {
        printf("%3d",matrix[i][j]);
       }
       printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    spiralmatrix(n);
    return 0;
}