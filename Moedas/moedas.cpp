#include <iostream>
#include <vector>

using namespace std;

int contador(vector<int> V, int m, int n) {
    vector<vector<int>> T(m + 1, vector<int>(n + 1, 0));

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

void imprimirTroco(vector<int> V, int m, int n, vector<int> &tentativa, int &formasEncontradas) {
    if (n == 0) {
        cout << "Tentativa " << formasEncontradas + 1 << ": ";
        for (int i = 0; i < tentativa.size(); i++) {
            cout << tentativa[i] << " ";
        }
        cout << "(";

        int moedaAtual = tentativa[0];
        int contagem = 1;

        for (int i = 1; i < tentativa.size(); i++) {
            if (tentativa[i] == moedaAtual) {
                contagem++;
            } else {
                cout << contagem << " moeda";
                if (contagem > 1) {
                    cout << "s";
                }
                cout << " de " << moedaAtual;
                if (i < tentativa.size() - 1) {
                    cout << " e ";
                }
                moedaAtual = tentativa[i];
                contagem = 1;
            }
        }

        cout << contagem << " moeda";
        if (contagem > 1) {
            cout << "s";
        }
        cout << " de " << moedaAtual << ")" << endl;

        formasEncontradas++;
        return;
    }

    if (n < 0 || m <= 0) {
        return;
    }

    tentativa.push_back(V[m - 1]);
    imprimirTroco(V, m, n - V[m - 1], tentativa, formasEncontradas);
    tentativa.pop_back();

    imprimirTroco(V, m - 1, n, tentativa, formasEncontradas);
}

void printTentativas(vector<int> V, int m, int n) {
    cout << "Tentativas de dar troco de " << n << " usando as moedas disponíveis:" << endl;
    int totalFormas = contador(V, m, n);
    vector<int> tentativa;

    int formasEncontradas = 0;

    imprimirTroco(V, m, n, tentativa, formasEncontradas);

    cout << "Ao todo há " << formasEncontradas << " maneiras distintas de dar troco." << endl;
}

int main() {
    vector<int> V = {1, 5, 10, 25, 50, 100};
    int m = V.size();
    int n;

    cout << "Digite o valor total para dar troco: ";
    cin >> n;

    printTentativas(V, m, n);

    return 0;
}
