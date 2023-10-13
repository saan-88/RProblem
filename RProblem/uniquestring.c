#include<stdio.h>
#include<string.h>

#define NUM_WORDS 1000
#define WORD_LENGTH 10


int search( char word[NUM_WORDS][WORD_LENGTH], int n, char str[])
{
    int i;
    for(i=0; i<n;i++)
    {
        if(strcmp(word[i],str)==0){
            return i;
        }
    }
    return -1;
}

int main(){
    char word[NUM_WORDS][WORD_LENGTH];
    int counter[NUM_WORDS];
    char str[WORD_LENGTH];
    int count=0;
    while (EOF!= scanf("%s",str))
    {
        if(search(word,count,str)==-1) {
            strcpy(word[count],str);
            counter[count] = 1;
            count++;
        }
        else
        {
            counter[search(word,count,str)]++;
        }
    }

    for (int j=0; j<count; j++)
    {
        printf("%s %d\n",word[j], counter[j]);
    }
}