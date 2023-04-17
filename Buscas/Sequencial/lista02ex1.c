#include <stdio.h>
#include <stdlib.h>
#define max 20
int sequentialSearch(int k, int busca[], int n) {
    int i = 0;
    while (i < n) {
        if (k == busca[i]) {
            break;
        } else {
            i++;
        }
    }
    if (i < n) {
        return i;
    } else {
        return -1;
    }
}

int main() {
    int choice, value;
    int busca[max];
    printf("\n:: Sequential Search ::\n");
    
    for(int i = 0; i < max; i++)
    {
        printf("\nInsira um elemento: ");
        scanf("%i", &busca[i]);
    }
    while (1) {
        printf("\nMenu\n");
        printf("1. Procurar\n2. Finalizar\n");
        printf("\nInsira sua opção: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Insira o valor a ser procurado: ");
                scanf("%d", &value);
                int index = sequentialSearch(value, busca, 7);
                if (index > 0) {
                    printf("\nValor achado no índice %d da lista\n", index + 1);
                } else {
                    printf("\nValor não encontrado\n");
                }
                break;
            case 2: exit(0);
            default: printf("\nErro!!! Tente de novo!!!\n");
        }
    }
}
