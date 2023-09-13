#include <iostream>
#include <vector>

using namespace std;

int contador(vector<int> V, int m, int n) {
    vector<vector<int>> T(m+1, vector<int>(n+1, 0));

    for (int j = 0; j <= n; j++) T[0][j] = 0;

    for (int i = 1; i <= m; i++) T[i][0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= V[i - 1]) {
                T[i][j] = T[i][j - V[i - 1]] + T[i - 1][j];
            } else {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    return T[m][n];
}

int main() {
    vector<int> V = {1, 2, 5, 10, 25, 50, 100};
    int m = V.size();
    int n = 19;
    int jeitos = contador(V, m, n);

    cout << "Numero de maneiras de fazer " << n << " usando as moedas " << jeitos << endl;

    return 0;
}
