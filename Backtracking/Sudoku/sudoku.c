/* Future implementations:
   1. Solve why removePreviousMove() is not removing the last play automaticlly
   2. Errors inserting
*/

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

    for (int i = 0; i < 9; i++) {
        int count = rand() % 3 + 1; // Número de elementos a serem gerados nesta linha
        int generated = 0; // Número de elementos gerados até agora
        while (generated < count) {
            int j = rand() % 9; // Coluna aleatória

            int num;
            do {
                num = rand() % 9 + 1; // Número aleatório
            } while (!isValid(grid, i, j, num));

            grid[i][j] = num;
            generated++;
        }
    }
}

void removePreviousMove(int grid[][9], int row, int col) {
    if (row >= 0 && row < 9 && col >= 0 && col < 9 && grid[row][col] != 0) {
        grid[row][col] = 0;
    }
}

void removeElement(int grid[][9], int row, int col) {
    if (row >= 0 && row < 9 && col >= 0 && col < 9) {
        if (grid[row][col] != 0) {
            printf("Cannot remove a generated number.\n");
        } else {
            printf("Position (%d, %d) is already empty.\n", row + 1, col + 1);
        }
    } else {
        printf("Invalid position.\n");
    }
}

int main() {
    int grid[9][9];
    generateGrid(grid);

    printf("Sudoku Game\n\n");

    int previousRow = -1;
    int previousCol = -1;

    while (1) {
        int choice;
        printGrid(grid);
        printf("\n1. Insert number\n2. Remove previous move\n3. Remove element at position\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int row, col, num;
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
                previousRow = row - 1;
                previousCol = col - 1;
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
        } else if (choice == 2) {
            if (previousRow != -1 && previousCol != -1) {
                removePreviousMove(grid, previousRow, previousCol);
                previousRow = -1;
                previousCol = -1;
                printf("Previous move removed.\n");
            } else {
                printf("No previous move found.\n");
            }
        } else if (choice == 3) {
            int row, col;
            printf("Enter row & col (space-separated): ");
            scanf("%d %d", &row, &col);
            printf("\n");
            removeElement(grid, row - 1, col - 1);
        } else if (choice == 4) {
            printf("Exiting the game.\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
