#include <stdio.h>
#include <string.h>

int x_min = 0, x_max, y_min = 0, y_max; // x_min is left wall, x_max is right wall, y_min is upper wall, y_max is lower wall
int x, y;                               // x, y is current position of the ball
int dx, dy;                             // dx is increment to x direction, dy increment to y direction
char direction[3];                      // direction is the current direction of the ball, here NE, SE, NW, SW

void NE()                               // North east
{
    dx = 1;
    dy = -1;
    strcpy(direction, "NE");
}

void NW()                               // north west
{
    dx = -1;
    dy = -1;
    strcpy(direction, "NW");
}

void SE()                               // south east
{
    dx = 1;
    dy = 1;
    strcpy(direction, "SE");
}

void SW()                               // south west
{
    dx = -1;
    dy = 1;
    strcpy(direction, "SW");
}

// void changedirection()                  // changedirection funtion changes the direction of the ball when required
// {
//     if ((x == x_min && y == y_min) && (strcmp(direction, "NW") == 0))
//     {
//         SE();
//     }
//     else if (x == x_max && y == y_min && (strcmp(direction, "NE") == 0))
//     {
//         SW();
//     }
//     else if (x == x_min && y == y_max && (strcmp(direction, "SW") == 0))
//     {
//         NE();
//     }
//     else if (x == x_max && y == y_max && (strcmp(direction, "SE") == 0))
//     {
//         NW();
//     }
    
//     else if ((x == x_min) && (strcmp(direction, "NW") == 0)) // hitting to left wall with direction NW
//     {
//         y--;
//         NE();
//     }
//     else if ((x == x_min) && (strcmp(direction, "SW") == 0))  // hitting to left wall with direction SW
//     {
//         y++;
//         SE();
//     }
//     else if ((y == y_min) && (strcmp(direction, "NE") == 0))  // hitting to upper wall with direction NE
//     {
//         x++;
//         SE();
//     }
//     else if ((y == y_min) && (strcmp(direction, "NW") == 0))
//     {
//         x--;
//         SW();
//     }
//     else if ((x == x_max) && (strcmp(direction, "NE") == 0))
//     {
//         y--;
//         NW();
//     }
//     else if ((x == x_max) && (strcmp(direction, "SE") == 0))
//     {
//         y++;
//         SW();
//     }
//     else if ((y == y_max) && (strcmp(direction, "SE") == 0))
//     {
//         x++;
//         NE();
//     }
//     else if ((y == y_max) && (strcmp(direction, "SW") == 0))
//     {
//         x--;
//         NW();
//     }
// }

void changedirection()
{
    if ((x == x_min && y == y_min) && (strcmp(direction, "NW") == 0))
    {
        SE();
    }
    else if (x == x_max && y == y_min && (strcmp(direction, "NE") == 0))
    {
        SW();
    }
    else if (x == x_min && y == y_max && (strcmp(direction, "SW") == 0))
    {
        NE();
    }
    else if (x == x_max && y == y_max && (strcmp(direction, "SE") == 0))
    {
        NW();
    }
    else if (x == x_min) // hitting the left wall
    {
        if (strcmp(direction, "NW") == 0)
        {
            y--;
            NE();
        }
        else if (strcmp(direction, "SW") == 0)
        {
            y++;
            SE();
        }
    }
    else if (x == x_max) // hitting the right wall
    {
        if (strcmp(direction, "NE") == 0)
        {
            y--;
            NW();
        }
        else if (strcmp(direction, "SE") == 0)
        {
            y++;
            SW();
        }
    }
    else if (y == y_min) // hitting the upper wall
    {
        if (strcmp(direction, "NE") == 0)
        {
            x++;
            SE();
        }
        else if (strcmp(direction, "NW") == 0)
        {
            x--;
            SW();
        }
    }
    else if (y == y_max) // hitting the lower wall
    {
        if (strcmp(direction, "SE") == 0)
        {
            x++;
            NE();
        }
        else if (strcmp(direction, "SW") == 0)
        {
            x--;
            NW();
        }
    }
}


int main()
{
    // int x_limit, y_limit;
    // printf("Number of rows and columns: ");
    // scanf("%d%d", &y_limit, &x_limit);
    // x_max = x_limit - 1;                     // position of right wall is number of column minus 1
    // y_max = y_limit - 1;                     // position of bottom wall is number of rows minus 1

    int step = 0, num_holes;                 // num_holes is number of given holes
    // scanf("%d", &num_holes);

    // int holes[num_holes][2];                 // holes is an array of num_holes elements each with two coordinate x and y
    // for (int i = 0; i < num_holes; i++)
    // {
    //     scanf("%d%d", &holes[i][0], &holes[i][1]);    // scanning the coordinates of holes
    // }

    // scanf("%d%d", &x, &y);                             // scanning starting position

    // scanf("%s", direction);                             // scanning direction

    x_max = 5;
    y_max = 2;
    num_holes = 2;
    int holes[num_holes][2];
    holes[0][0] = 0;
    holes[0][1] = 1;
    holes[1][0] = 1;
    holes[1][1] = 4;
    x = 1;
    y = 1;
    strcpy(direction, "NE");



    if (strcmp(direction, "NE") == 0)                   // If given direction is NE, we call NE
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
        x = x + dx;                     // incrementing x and y by appropiate dx and dy
        y = y + dy;

        for (int j = 0; j < num_holes; j++)     // If the current position is any hole we break the loop and print the hole
        {
            if (x == holes[j][0] && y == holes[j][1])
            {
                printf("Falls through hole at (%d, %d)\n", x, y);
                return 0;
            }
        }

        if (((x == x_min) && ((strcmp(direction, "NW") == 0) || (strcmp(direction, "SW") == 0))) || ((x == x_max) && ((strcmp(direction, "NE") == 0) || (strcmp(direction, "SE") == 0))) || ((y == y_min) && ((strcmp(direction, "NE") == 0) || (strcmp(direction, "NW") == 0))) || ((y == y_max) && ((strcmp(direction, "SE") == 0) || (strcmp(direction, "SW") == 0))))
        {
            changedirection();               // If it is hitting one of the walls, we change direction
        }
        step++;
    }
    printf("Bounces forever\n");
}