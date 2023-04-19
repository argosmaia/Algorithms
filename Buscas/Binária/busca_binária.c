#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para realizar a busca binária em uma lista ordenada
int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; // Elemento encontrado, retorna o índice
        } else if (arr[mid] < x) {
            left = mid + 1; // Elemento está na metade direita
        } else {
            right = mid - 1; // Elemento está na metade esquerda
        }
    }

    return -1; // Elemento não encontrado
}

int main() {
    // Seed para geração de números aleatórios
    srand(time(0));

    // Tamanho da lista de dados
    int n = 10;

    // Geração aleatória dos dados
    int arr[10];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Números aleatórios de 0 a 99
    }

    // Ordenação da lista de dados
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Imprime a lista de dados
    printf("Lista de Dados: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Loop para permitir ao usuário fazer buscas ou sair
    int choice;
    int searchValue;
    while (1) {
        printf("Digite o valor a ser buscado (ou -1 para sair): ");
        scanf("%d", &choice);

        if (choice == -1) {
            printf("Saindo...\n");
            break;
        }

        // Realiza a busca binária e imprime o resultado
        int result = binarySearch(arr, n, choice);
        if (result == -1) {
            printf("Valor nao encontrado na lista.\n");
        } else {
            printf("Valor encontrado na posicao %d da lista.\n", result);
        }
    }

    return 0;
}
