#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100
#define MAX_M 100

void moedas(int n, int m, int V[], int T[MAX_M][MAX_N + 1]) {
    
    int i, j;
    //Preenchimento da 1ª linha
    for(j = 0; j <= n; j++) T[0][j] = 0;
    
    for(i = 0; i <= m; i++) T[i][0] = 1;
    
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            if(j >= V[i]) {
                T[i][j] = T[i][j - V[i]] + T[i - 1][j];
            } else {
                T[i][j] = T[i - 1][j];
            }
        }
    }
}

int main() {
    int n, m, i, j;
    
    int V[MAX_M], T[MAX_M][MAX_N+1];
    
    // Leitura dos dados de entrada
    printf("Digite o valor a ser trocado: ");
    scanf("%d", &n);

    printf("Digite o numero de moedas: ");
    scanf("%d", &m);

    printf("Digite os valores das moedas:\n");
    
    for (i = 1; i <= m; i++) {
        scanf("%d", &V[i]);
    }
    
    // Preenchimento da tabela
    moedas(n, m, V, T);

    // Impressão da tabela
    printf("Tabela de troco:\n");
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    return 0;
}
