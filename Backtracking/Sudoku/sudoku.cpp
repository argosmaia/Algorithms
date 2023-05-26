#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void printGrid(const vector<vector<int>>& grid) {
    for(const auto& row : grid) {
        for(int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

bool isNumberInRow(const vector<vector<int>>& grid, int row, int num) {
    for(int col = 0; col < 9; col++) {
        if(grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool isNumberInColumn(const vector<vector<int>>& grid, int col, int num) {
    for(int row = 0; row < 9; row++) {
        if(grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool isNumberInMiniGrid(const vector<vector<int>>& grid, int startRow, int startCol, int num) {
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(grid[row + startRow][col + startCol] == num) {
                return false;
            }
        }
    }
    return false;
}

bool isValid(const vector<vector<int>>& grid, int row, int col, int num) {
    return !isNumberInRow(grid, row, num) && !isNumberInColumn(grid, col, num) &&
           !isNumberInMiniGrid(grid, row - row % 3, col - col % 3, num); 
}

vector<vector<int>> generateGrid() {
    vector<vector<int>> grid(9, vector<int>(9, 0));

    srand(time(0));
    for(int i = 0; i < 20; i++) {
        int row = rand() % 9;
        int col = rand() % 9;
        int num = rand() % 9 + 1;
        if(isValid(grid, row, col, num)) grid[row][col] = num;
    }
    return grid;
}

int main() {
    vector<vector<int>> grid = generateGrid();
    cout << "Sudoku Game" << endl;
    cout << endl;

    while(true) {
        int row, col, num;
        cout << "Enter row & col (space-separated): ";
        cin >> row >> col;

        cout << "\nNumber (1-9): ";
        cin >> num;
        cout << endl;
      
      if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
            cout << "Invalid input! Please try again." << endl;
            continue;
        }

        if (isValidMove(grid, row - 1, col - 1, num)) {
            grid[row - 1][col - 1] = num;
        } else {
            cout << "Invalid move! Please try again." << endl;
        }

        // Check if the game is won
        bool gameWon = true;
        for (const auto& row : grid) {
            for (int num : row) {
                if (num == 0) {
                    gameWon = false;
                    break;
                }
            }
        }

        if (gameWon) {
            cout << "Congratulations! You won the game." << endl;
            break;
        }
    }

    return 0;
}
