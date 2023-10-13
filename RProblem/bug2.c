#include <stdio.h>

int main()
{
    int c,a[10000],count=0,i,j,temp;
	while(EOF!=(c=getchar()))      //Scanning string
	{
		a[count]=c-48;
		count++;
	}
	if(count==0)
		return 0;
	i=0;
    j=count-1;
    while(i<=j)
    {
        while(a[i]==0)             
            i++;
        while(a[j]==1)
            j--;
        if(a[i]==1 && i<=j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    for(i=0;i<count;i++)
        printf("%d",a[i]);

    return 0;
}
