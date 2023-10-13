#include <stdio.h>
#include <stdlib.h>

struct Point3D {
    double x;
    double y;
    double z;
};

int main() {
    int numPoints = 0; // To keep track of the number of points read
    int maxPoints = 10; // Initial capacity, can be increased as needed
    struct Point3D *points = (struct Point3D *)malloc(maxPoints * sizeof(struct Point3D));

    if (points == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Enter 3D points (x y z), one per line. Enter '0 0 0' to stop:\n");

    while (1) {
        double x, y, z;
        int result = scanf("%lf %lf %lf", &x, &y, &z);

        if (result != 3) {
            if (result == EOF) {
                break; // End of input
            }
            // else {
            //     printf("Invalid input. Please enter x y z.\n");
            //     while (getchar() != '\n'); // Clear the input buffer
            //     continue;
            // }
        }

        // Store the point in the array
        if (numPoints == maxPoints) {
            // If the array is full, double its capacity
            maxPoints *= 2;
            points = (struct Point3D *)realloc(points, maxPoints * sizeof(struct Point3D));
            if (points == NULL) {
                perror("Memory allocation failed");
                return 1;
            }
        }

        points[numPoints].x = x;
        points[numPoints].y = y;
        points[numPoints].z = z;
        numPoints++;
    }

    // Print the stored points
    printf("Stored 3D points:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: (%lf, %lf, %lf)\n", i + 1, points[i].x, points[i].y, points[i].z);
    }

    // Free dynamically allocated memory
    free(points);

    return 0;
}
