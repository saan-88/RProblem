#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
    int z;
}
POINT;


int len;

void getInput(POINT *points)
{
    for(int i = 0; i < len; i++)
    {
        scanf("%d", &points[i].x);
        scanf("%d", &points[i].y);
        scanf("%d", &points[i].z);
    }
}

int distance (POINT p1, POINT p2)
{
    int d = 0;
    d = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
    return d;
}

int main()
{
    scanf("%d", &len);
    POINT *points = (POINT *) malloc (len * sizeof(POINT));

    // int nPair = len * (len - 1) / 2;
    // PAIR *pairs = (PAIR *) malloc (nPair * sizeof(PAIR));

    POINT minmax[2];
    
    int minDist = INT_MAX, d;
    getInput(points);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            d = distance(points[i], points[j]);
            if (d < minDist)
            {
                minDist = d;
                minmax[0] = points[i];
                minmax[1] = points[j];
            }
        }
    }

    printf("(%d, %d, %d), (%d, %d, %d)", minmax[0].x, minmax[0].y, minmax[0].z, minmax[1].x, minmax[1].y, minmax[1].z);


    // Freeing memory
    free(points);

}