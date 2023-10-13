#include<stdio.h>
#include<math.h>
#include <stdlib.h>

/*void spiral_matrix(int n){
    int row_start, row_end, col_start, col_end,row;
    char *matrix=(char)malloc(row*sizeof(char));
    for(int i=0; i) 
}*/


int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int k;
    k=m*n;
    char *array = (char *) malloc (k * sizeof(char));

    int i = 0;
    while(i < k){
        array[i] = getchar();
        i++;
    }

    printf("%d",k);
    free(array);
    for(int i=0; i<k; i++){
        printf("%c",array[i]);
    }
}