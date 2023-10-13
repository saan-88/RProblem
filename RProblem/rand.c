#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <math.h>

double normal(void)
{
    srand((double) time (NULL));
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    double z0 = sqrt(-2 * (log(u1))) * cos(2 * 3.14159265359 * u2);
    double z1 = sqrt(-2 * log(u1)) * sin(2 * M_PI * u2);

    return z1;

}



int main() {
    
    double x = normal();

    printf("%lf", x);


    return 0;
}
