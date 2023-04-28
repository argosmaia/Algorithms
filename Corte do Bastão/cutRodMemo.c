#include <stdio.h>

/**
 * FEITO POR ARGOS A. MAIA, ARTHUR A. AGUIAR E PEDRO S. BARCIELA
*/

int max(int a, int b) {
    return a > b ? a : b;
}

int cortarbastao(int preco[], int n, int *memo) {
    if(n == 0) {
        return 0;
    }

    if(memo[n] != -1) {
        return memo[n];
    }

    int max_value = -1;
    
    for(int i = 0; i < n; i++)
        max_value = max(max_value, preco[i] + cortarbastao(preco, n - i - 1, memo));
    
    memo[n] = max_value;

    return max_value;
}

int main() {
    int preco[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(preco) / sizeof(preco[0]);

    int memo[n+1];

    for(int i = 0; i <= n; i++)
        memo[i] = -1;

    printf("\nVALOR MÁXIMO %d\n", cortarbastao(preco, n, memo));
}
