#include<stdio.h>

#define SIZE 1000

int main(){
    int num_box;
    int array[SIZE];
    int amount,sum=0,fix,total=1;
    int count=0;
    printf("Number of box: ");
    scanf("%d",&num_box);
    for(int i=0; i<num_box; i++){
        printf("Box %d capacity: ", i + 1);
        scanf("%d",&array[i]);
    }
    printf("Amount: ");
    scanf("%d", &amount);
    //fix=amount;
    printf("%d ",num_box);
    for(int i=0; i<num_box; i++){
        printf("%d",array[i]);
    }
   // printf("%d",amount);
   /* for(int i=0; i<num_box ;i++){
        total=total*array[i];
    }
    for(int i=1; i<num_box ;i++){
        sum = sum + array[i];
    }
    while(amount>0){
        amount=amount-total;
        count=count+sum;
    }
    count=count-sum;
    amount=amount+total;
    printf("%d",count);*/
    return 0;
}