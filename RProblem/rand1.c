#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(1);

    // Generate a random number between 0 and 1
    double random_number1 = (double)rand() / RAND_MAX;

    srand(2);
    double random_number2 = (double)rand() / RAND_MAX;
    // Print the random number
    printf("Random number between 0 and 1: %lf\n", random_number1);
    printf("Random number between 0 and 1: %lf\n", random_number2);

    return 0;
}