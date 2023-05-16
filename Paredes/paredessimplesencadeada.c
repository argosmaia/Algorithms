#include <stdio.h>

#include <stdlib.h>

typedef struct no {

    int linha;

    int coluna;

    char orientacao;

    struct no *prox;

} No;

int azuleijar_parede(int n, int linha, No *topo) {

    if(n == 0) return 1;

    int memo[n][3];

    for(int i = 0; i <= n; i++) {

        for(int j = 0; j < 3; j++) {

            memo[i][j] = -1;

        }

    }

    while(topo != NULL) {

        memo[topo->coluna][topo->linha] = 0;

        if(topo->orientacao == 'h') {

            memo[topo->coluna+1][topo->linha] = 0;

        } else {

            memo[topo->coluna][topo->linha+1] = 0;

        }

        topo = topo->prox;

    }

    

    int cont = 0;

    

    if(linha == 0) {

        cont += azuleijar_parede(n - 1, 1, topo);

    } else if(linha == 1) {

        cont += azuleijar_parede(n - 1, 0, topo);

        cont += azuleijar_parede(n - 1, 2, topo);

    } else {

        cont += azuleijar_parede(n - 1, 1, topo);

    }

    

    return cont;

}

void imprimir_estado_da_parede(int n, No *topo) {

    printf("\nEstado da parede:\n");

    int memo[n][3];

    for(int i = 0; i <= n; i++) {

        for(int j = 0; j < 3; j++) {

            memo[i][j] = -1;

        }

    }

    while(topo != NULL) {

        memo[topo->coluna][topo->linha] = 0;

        if(topo->orientacao == 'h') {

            memo[topo->coluna+1][topo->linha] = 0;

        } else {

            memo[topo->coluna][topo->linha+1] = 0;

        }

        topo = topo->prox;

    }

    

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

void inserir_azuleijo(int linha, int coluna, char orientacao, No **topo) {

    No *novo = (No*) malloc(sizeof(No));

    novo->linha = linha;

    novo->coluna = coluna;

    novo->orientacao = orientacao;

    novo->prox = *topo;

    *topo = novo;

}

int main() {

    No *topo = NULL;

    int opcao;

    int n, linha, coluna;

    char orientacao;

    

    do {

        printf("\n----- MENU -----\n");

        printf("1 - Inserir azuleijo\n");

        printf("2 - Azuleijar parede\n");

        printf("3 - Imprimir estado da parede\n");

        printf("0 - Sair\n");

        printf("Digite a opcao desejada: ");

        scanf("%d", &opcao);

        

        switch(opcao) {

            case 1:

                printf("Digite a linha: ");

                scanf("%d", &linha);

                printf("Digite a coluna: ");

                scanf("%d", &coluna);

                printf("Digite a orientacao (h/v): ");

                scanf(" %c", &orientacao);

                inserir_azuleijo(linha, coluna, orientacao, &topo);

                break;

            case 2:

                printf("Digite o tamanho da parede: ");

                scanf("%d", &n);

                printf("Quantidade de formas de azuleijar a parede: %d\n", azuleijar_parede(n, 0, topo));

                break;

            case 3:

                imprimir_estado_da_parede(n, topo);

                break;

            case 0:

                printf("Saindo...\n");

                break;

            default:

                printf("Opcao invalida! Digite novamente.\n");

                break;

        }

    } while(opcao != 0);

    

    return 0;

}

