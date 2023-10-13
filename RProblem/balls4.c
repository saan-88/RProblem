#include<stdio.h>

int main()
{
    int m,n,i,j;
    int north;
    int east;
    int hole1A, hole1B, hole2A, hole2B;
    char D;
    char NE,SE,NW,SW;
    printf("Enter the row of chess board:\n");
    scanf("%d",&m);
    printf("Enter the column of chess board:\n");
    scanf("%d",&n);
    //printf("Enter the NO of holes:\n");
    //scanf("%d\n");
    scanf("%c",&D);
    while(north>=0 && north<n && east>=0 && east<m){
        if(D==NE){
            while(i>=0 && j<n){
                if((i==hole1A && j==hole1B)||(i==hole2A && j==hole2B)){
                    break;
                }
                i--;
                j++;
                }
        }
                if(D==SE){
            while(i<m && j<n){
                if((i==hole1A && j==hole1B)||(i==hole2A && j==hole2B)){
                    break;
                }
                i++;
                j++;
                }
                }
                if(D==NW){
                    while(i>=0 && j>=0){
                        if((i==hole1A && j==hole1B)||(i==hole2A && j==hole2B)){
                        break;
                }
                i--;
                j--;
            }
                }
                if(D==SW){
            while(i<m && j>=0){
                if((i==hole1A && j==hole1B)||(i==hole2A && j==hole2B)){
                    break;
                }
                i++;
                j--;
            }
        }
            
    }
    printf("%d %d",i,j);

}