#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printGrid(const int grid[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool isNumberInRow(const int grid[][9], int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool isNumberInColumn(const int grid[][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool isNumberInMiniGrid(const int grid[][9], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + startRow][col + startCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isValid(const int grid[][9], int row, int col, int num) {
    return !isNumberInRow(grid, row, num) && !isNumberInColumn(grid, col, num) &&
           !isNumberInMiniGrid(grid, row - row % 3, col - col % 3, num);
}

void generateGrid(int grid[][9]) {
    srand(time(NULL));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = 0;
        }
    }

    for (int i = 0; i < 20; i++) {
        int row = rand() % 9;
        int col = rand() % 9;
        int num = rand() % 9 + 1;
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
        }
    }
}

int main() {
    int grid[9][9];
    generateGrid(grid);

    printf("Sudoku Game\n\n");

    while (1) {
        int row, col, num;
        printGrid(grid);
        printf("Enter row & col (space-separated): ");
        scanf("%d %d", &row, &col);

        printf("Number (1-9): ");
        scanf("%d", &num);
        printf("\n");

        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
            printf("Invalid input! Please try again.\n");
            continue;
        }

        if (isValid(grid, row - 1, col - 1, num)) {
            grid[row - 1][col - 1] = num;
        } else {
            printf("Invalid move! Please try again.\n");
        }

        // Check if the game is won
        bool gameWon = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == 0) {
                    gameWon = false;
                    break;
                }
            }
        }

        if (gameWon) {
            printf("Congratulations! You won the game.\n");
            break;
        }
    }

    return 0;
}
