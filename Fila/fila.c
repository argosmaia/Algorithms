#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int dado[SIZE];
    int frente;
    int fim;
} Fila;

void inicializa(Fila* fila) {
    fila->frente = -1;
    fila->fim = -1;
}

// Função para verificar se a fila está vazia
int vazio(Fila* fila) {
    return fila->frente == -1;
}

// Função para verificar se a fila está cheia
int cheio(Fila* fila) {
    return (fila->fim + 1) % SIZE == fila->frente;
}

void enfileirar(Fila* fila, int valor) {
    if(cheio(fila)) {
        printf("\nFila cheia!\n");
        return;
    }

    if(vazio(fila)) {
        fila->frente = 0;
        fila->fim = 0;
    } else {
        fila->fim = (fila->fim + 1) % SIZE;
    }

    fila->dado[fila->fim] = valor;
}

void desenfileira(Fila* fila) {
    if(vazio(fila)) {
        printf("\nFila vazia!\n");
        return;
    }

    if(fila->frente == fila->fim) {
        fila->frente = -1;
        fila->fim = -1;
    } else {
        fila->frente = (fila->frente + 1) % SIZE;
    }
}

// Função para ver o elemento do início da fila
void frente(Fila* fila) {
    if (vazio(fila)) {
        printf("A fila está vazia!\n");
        return;
    }

    printf("Elemento do inicio da fila: %d\n", fila->dado[fila->frente]);
}

// Função para ver o elemento do fim da fila
void fim(Fila* fila) {
    if (vazio(fila)) {
        printf("A fila está vazia!\n");
        return;
    }

    printf("Elemento do fim da fila: %d\n", fila->dado[fila->fim]);
}

// Função para ver toda a fila
void mostrar(Fila* fila) {
    if (vazio(fila)) {
        printf("A fila está vazia!\n");
        return;
    }

    printf("Elementos da fila: ");
    int i = fila->frente;
    while (i != fila->fim) {
        printf("%d ", fila->dado[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", fila->dado[fila->fim]);
}

int main() {
    Fila fila;
    inicializa(&fila);
    
    int opcao, valor;
    
    while(1) {
        printf("\n----- Menu de Opcoes -----\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Ver frente\n");
        printf("4. Ver fim\n");
        printf("5. Ver toda a fila\n");
        printf("6. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite o valor para enfileirar: ");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                break;
            case 2:
                desenfileira(&fila);
                break;
            case 3:
                frente(&fila);
                break;
            case 4:
                fim(&fila);
                break;
            case 5:
                mostrar(&fila);
                break;
            case 6:
                printf("Saindo...\n");
                exit(0);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }
    
    return 0;
}
