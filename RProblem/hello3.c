#include<stdio.h>

#define SIZE 100

//struct hole{

//}
void searchA(int i, int j, int m,int n){
            while(i>0 && j<n-1){
               /* printf("%d %d",i,j);
                printf("\n");*/
                i--;
                j++;
                }
}

void searchB(int i, int j, int m,int n){
            while(i>0 && j>0){
              /*  printf("%d %d",i,j);
                printf("\n");*/
                i--;
                j--;
                }
}
void searchC(int i, int j, int m,int n){
            while(i<m-1 && j<n-1){
               /* printf("%d %d",i,j);
                printf("\n");*/
                i++;
                j++;
                }
}
void searchD(int i, int j, int m,int n){
            while(i<m-1 && j>=0){
               /* printf("%d %d",i,j);
                printf("\n");*/
                i++;
                j--;
                }
}
int main(){
    int m,n,i,j,N;
    char A,B,C,D;
    char d;
    scanf("%d %d %d",&m,&n,&N);
    scanf("%d %d ",&i,&j);
    scanf("%c",&d);
    printf("%d%d%c\n",m,n,d);
    //for(int k=0;k<N;k++){
       // while(hole.1[k]==i && hole.2[k]==j){
            if(d=='A'){
            searchA(i,j,m,n);
            }
            if(d=='B'){
            searchB(i,j,m,n);
            }
            if(d=='C'){
            searchB(i,j,m,n);
            }
            if(d=='D'){
            searchB(i,j,m,n);
            }
        }