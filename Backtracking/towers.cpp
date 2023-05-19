#include <iostream>
#include <vector>
//Argos
using namespace std;

const int N = 8; // Tamanho do tabuleiro

vector<vector<int>> board(N, vector<int>(N, 0)); // Tabuleiro

bool isValidMove(int row, int col) {
    // Verifica se há alguma torre na mesma linha ou coluna
    for (int i = 0; i < N; i++) {
        if (board[row][i] == 1 || board[i][col] == 1)
            return false;
    }

    // Verifica se há alguma torre na diagonal principal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i < N && j < N; i++, j++) {
        if (board[i][j] == 1)
            return false;
    }

    // Verifica se há alguma torre na diagonal secundária
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int col) {
    if (col == N) {
        // Imprime a configuração final do tabuleiro
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    for (int row = 0; row < N; row++) {
        if (isValidMove(row, col)) {
            // Coloca uma torre na posição (row, col)
            board[row][col] = 1;

            // Chama recursivamente para a próxima coluna
            if (solve(col + 1))
                return true;

            // Se não encontrou uma solução, remove a torre da posição (row, col)
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    solve(0); // Começa na coluna 0

    return 0;
}
