#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100

int memo[MAX_N][3];

int azuleijar_parede(int n, int linha) {
    if(n == 0) return 1;
    
    if(memo[n][linha] != -1) {
        return memo[n][linha];
    }
    
    int cont = 0;
    
    if(linha == 0) {
        cont += azuleijar_parede(n - 1, 1);
    } else if(linha == 1) {
        cont += azuleijar_parede(n - 1, 0);
        cont += azuleijar_parede(n - 1, 2);
    } else {
        cont += azuleijar_parede(n - 1, 1);
    }

    memo[n][linha] = cont;
    
    return cont;
}

void imprimir_estado_da_parede(int n) {
    printf("\nEstado da parede:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            switch(memo[j+1][i]) {
                case -1:
                    printf("?");
                    break;
                case 0:
                    printf("X");
                    break;
                default:
                    printf("O");
                    break;
            }
        }
        printf("\n");
    }
}

void inserir_azuleijo(int n, int linha, int coluna, char orientacao) {
    if (orientacao == 'h') {
        memo[coluna][linha] = 0;
        memo[coluna+1][linha] = 0;
    } else {
        memo[coluna][linha] = 0;
        memo[coluna][linha+1] = 0;
    }
}

int main() {
    int n;
    int linha, coluna;
    char orientacao;
    int opcao;

    printf("Insira o número de colunas da parede: ");
    scanf("%d", &n);

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            memo[i][j] = -1;
        }
    }

    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Ver estado da parede\n");
        printf("2 - Inserir azuleijo\n");
        printf("3 - Ver número de maneiras distintas\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            
            case 1:
                imprimir_estado_da_parede(n);
                break;
            
            case 2:
                printf("Insira a linha e a coluna onde deseja inserir o azuleijo e a orientação (h para horizontal, v para vertical) (exemplo: 1 3 h): ");
                scanf("%d %d %c", &linha, &coluna, &orientacao);
                if (orientacao == 'h') {
                    inserir_azuleijo(n, linha-1, coluna-1, 'h');
                } else {
                    inserir_azuleijo(n, linha-1, coluna-1, 'v');
                }
                break;
            
            case 3:
                printf("\nNúmero de maneiras distintas: %d\n", azuleijar_parede(n, 0) + azuleijar_parede(n, 2));
                break;
            
            case 0:
                exit(0);
                break;
        }
    }while(opcao != 0);
    
    return 0;
    
}
