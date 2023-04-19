#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 10 // Tamanho máximo da lista

// Função para gerar números aleatórios
int gerar_numero_aleatorio() {
    return rand() % 100 + 1; // Gera números aleatórios entre 1 e 100
}

// Função para imprimir a lista
void imprimir_lista(int lista[], int tamanho) {
    printf("Lista: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

// Função para realizar busca sequencial na lista
bool busca_sequencial(int lista[], int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == chave) {
            return true; // Chave encontrada na lista
        }
    }
    return false; // Chave não encontrada na lista
}

int main() {
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios com o tempo atual

    int lista[MAX_SIZE]; // Lista de números
    int tamanho = MAX_SIZE; // Tamanho da lista
    int opcao;
    int chave;

    // Preenche a lista com números aleatórios
    for (int i = 0; i < tamanho; i++) {
        lista[i] = gerar_numero_aleatorio();
    }

    imprimir_lista(lista, tamanho);

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1. Encontrar numero\n");
        printf("2. Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero a ser encontrado: ");
                scanf("%d", &chave);
                if (busca_sequencial(lista, tamanho, chave)) {
                    printf("O numero %d foi encontrado na lista.\n", chave);
                } else {
                    printf("O numero %d nao foi encontrado na lista.\n", chave);
                }
                break;

            case 2:
                printf("Saindo...\n");
                exit(0);

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
