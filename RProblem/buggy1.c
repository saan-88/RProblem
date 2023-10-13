#include <stdio.h>

int f(int p)
{
    p = p + 2;
    return p;
}

int main()
{
    int x = 5;
    int y = 2;
    int z = x + y;
    printf("%d", f(z));
}