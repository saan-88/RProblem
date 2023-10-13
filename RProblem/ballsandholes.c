#include <stdio.h>
#include <limits.h>
#include <string.h>

int x_min = 0, x_max, y_min = 0, y_max;
int x, y;
int dx, dy;
char direction[3];

void NE()
{
    dx = 1;
    dy = 1;
    strcpy(direction, "NE");
}

void NW()
{
    dx = -1;
    dy = 1;
    strcpy(direction, "NW");
}

void SE()
{
    dx = 1;
    dy = -1;
    strcpy(direction, "SE");
}

void SW()
{
    dx = -1;
    dy = -1;
    strcpy(direction, "SW");
}


void changedirection()
{
    if ((x == x_min) && (strcmp(direction, "NW") == 0))
    {
        
        NE();
    }
    else if ((x == x_min) && (strcmp(direction, "SW") == 0))
    {
        SE();
    }
    else if ((y == y_min) && (strcmp(direction, "NE") == 0))
    {
        SE();
    }
    else if ((y == y_min) && (strcmp(direction, "NW") == 0))
    {
        SW();
    }
    else if ((x == x_max) && (strcmp(direction, "NE") == 0))
    {
        NW();
    }
    else if ((x == x_max) && (strcmp(direction, "SE") == 0))
    {
        SW();
    }
    else if ((y == y_max) && (strcmp(direction, "SE") == 0))
    {
        NE();
    }
    else if ((y == y_max) && (strcmp(direction, "SW") == 0))
    {
        NW();
    }
    
}

int main()
{
    
    int x_limit, y_limit;
    printf("Number of rows and columns: ");
    scanf("%d%d", &y_limit, &x_limit);
    x_max = x_limit - 1;
    y_max = y_limit - 1;

    int step = 0, num_holes;
    scanf("%d", &num_holes);

    int holes[num_holes][2];
    for (int i = 0; i < num_holes; i++)
    {
        scanf("%d%d", &holes[i][0], &holes[i][1]);
    }

    
    scanf("%d%d", &x, &y);
    
    scanf("%s", direction);

    // printf("%d %d", x_max, y_max);
    // printf("\n");
    // for (int i = 0; i < num_holes; i++)
    // {
    //     printf("%d %d\n", holes[i][0], holes[i][1]);
    // }
    // printf("%d %d", x, y);
    // printf("\n");
    // printf("%s", direction);

    if (strcmp(direction, "NE") == 0)
    {
        NE();
    }
    else if (strcmp(direction, "NW") == 0)
    {
        NW();
    }
    else if (strcmp(direction, "SE") == 0)
    {
        SE();
    }
    else if (strcmp(direction, "SW") == 0)
    {
        SW();
    }


    while (step < 1000000)
    {
        x = x + dx;
        y = y + dy;
        for (int j = 0; j < num_holes; j++)
        {
            if (x == holes[j][0] && y == holes[j][1])
            {
                printf("Falls through hole at (%d, %d)\n", x, y);
                return 0;
            }
        }

        if (((x == x_min) && ((strcmp(direction, "NW") == 0) || (strcmp(direction, "SW") == 0))) || ((x == x_max) && ((strcmp(direction, "NE") == 0) || (strcmp(direction, "SE") == 0))) || ((y == y_min) && ((strcmp(direction, "NE") == 0) || (strcmp(direction, "NW") == 0))) || ((y == y_max) && ((strcmp(direction, "SE") == 0) || (strcmp(direction, "SW") == 0))))
        {
            changedirection();
        }
        step++;
    }
    printf("Bounces forever\n");
}