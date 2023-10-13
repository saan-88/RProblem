#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int binarytoint(char * s)
{
    int n = strlen(s);
    s[n-1]='\0';
    // printf("%d\n",n);
    int sum = 0,p=0;
    for(int i = n-2; i >= 0; i--){
        int c=s[i]-'0';
        int t=c*pow(2,p++);
        // printf("%c\n",s[i]);
        sum+=t;
    }
    // int sum=atoi(s);
    return sum;
}

void insertionSort(int arr[], int n, int brr[]) {
    int i, key, j,k;
    for (i = 0; i < n; i++) {
        brr[i]=i;
    }
    for (i = 1; i < n; i++) {
        key = arr[i];
        k=brr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            brr[j+1]=brr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        brr[j+1]=i;
    }
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    char s[100];
    int c=0, N;
    
    scanf("%d",&N);
    char A[N][100];
    int B[N];
    int C[N];
    while(NULL!=fgets(s,100,fp)){
        // printf("%s",s);
        strcpy(A[c++],s);
    }

    for(int i=0;i<N;i++){
        B[i]=binarytoint(A[i]);
    }

    // for(int i=0;i<N;i++){
    //     printf("%d\n",B[i]);
    // }

    insertionSort(B,N,C);

    // for(int i=0;i<N;i++){
    //     printf("%d\n",C[i]);
    // }

    int count=1;
    for(int i=1;i<N;i++){
        if(!(strcmp(A[C[i]],A[C[i-1]])))
            count++;
        else{
            printf("%s %d\n",A[C[i-1]],count);
            count=1;
        }
    }
    printf("%s %d\n",A[C[N-1]],count);
    // printf("%d",c);
}