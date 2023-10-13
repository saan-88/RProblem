#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main() {
    int m, n, N, row, col;
    char direction[4], board[MAX_SIZE][MAX_SIZE];
    bool visited[MAX_SIZE][MAX_SIZE] = { false };

    FILE *inputFile = fopen("pyq_22_4.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }
    fscanf(inputFile, "%d%d%d", &m, &n, &N);

    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] = ' ';
        }
    }

    
    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%d%d", &row, &col);
        board[row][col] = 'H';
    }


    fscanf(inputFile, " (%d,%d) %3s", &row, &col, direction);

    
    fclose(inputFile);

    while (1) {
        if (visited[row][col]) {
            printf("Bounces forever\n");
            break;
        }

        if (row < 1 || row > m || col < 1 || col > n) {
            printf("Bounces forever\n");
            break;
        }

        visited[row][col] = true;

        if (board[row][col] == 'H') {
            printf("Falls through hole at (%d,%d)\n", row, col);
            break;
        }

        if (direction[0] == 'N' && row == 1) {
            direction[0] = 'S';
        } else if (direction[0] == 'S' && row == m) {
            direction[0] = 'N';
        }

        if (direction[1] == 'E' && col == n) {
            direction[1] = 'W';
        } else if (direction[1] == 'W' && col == 1) {
            direction[1] = 'E';
        }

        
        if (direction[0] == 'N') {
            row--;
        } else {
            row++;
        }

        if (direction[1] == 'E') {
            col++;
        } else {
            col--;
        }
    }

    return 0;
}