#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Estrutura encadeada
typedef struct No {
    int dado;
    struct No* prox;
} No;

// Estrutura da pilha encadeada
typedef struct Pilha {
    No* topo;
} Pilha;

//Estrutura da fila encadeada
typedef struct Fila {
    No* frente;
    No* fim;
} Fila;

//Pilha
void inicializar(Pilha* pilha) {
    pilha->topo = NULL; // Correção: inicializa o topo com NULL
}

int cheia() {
    return 0; // Como é uma pilha simplesmente encadeada, nunca estará cheia
}

int vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void insere(Pilha* pilha, int dado) {
    if(cheia()) { // Correção: chamada da função cheia()
        printf("\nPilha cheia!\n");
        return;
    }

    No* no = (No*)malloc(sizeof(No));
    no->dado = dado;
    no->prox = pilha->topo;
    pilha->topo = no; 
}

int remover(Pilha* pilha) {
    if(vazia(pilha)) {
        printf("\nPilha está vazia!\n");
        return -1;
    }
    No* temp = pilha->topo;
    int dado = temp->dado;
    pilha->topo = temp->prox; // Correção: atualiza o topo corretamente
    free(temp);
    return dado;
}

int topo(Pilha* pilha) {
    if(vazia(pilha)) {
        printf("\nPilha vazia!\n");
        return -1;
    }

    return pilha->topo->dado;
}

//Fila
void inicializafila(Fila* fila) {
    fila->frente = NULL;
    fila->fim = NULL;
}

int filavazia(Fila* fila){
    return fila->frente == NULL;
}

void enfileirar(Fila* fila, int dado) {
    No* no = (No*)malloc(sizeof(No));
    no->dado = dado;
    no->prox = NULL;
    if(fila->fim == NULL) {
        fila->frente = no;
        fila->fim = no;
    } else {
        fila->fim->prox = no;
        fila->fim = no;
    }
}

int desenfileirar(Fila* fila) {
    if(filavazia(fila)) {
        printf("\nFila vazia!\n");
        return -1;
    }
    No* saida = fila->frente;
    int dado = saida->dado;
    fila->frente = saida->prox;
    if(fila->frente == NULL) {
        fila->fim = NULL;
    }
    free(saida);
    return dado;
}

//Invertendo a pilha por meio da fila
void inverter(Pilha* pilha) {
    if(vazia(pilha)){
        printf("\nPilha vazia\n");
        return;
    }

    No* temp = NULL;
    Fila* fila;
    inicializafila(&fila);
    No* atual = pilha->topo;

    //Passo 1: Enfileira todos os dados da pilha na fila
    while(atual != NULL) {
        enfileirar(&fila, atual->dado);
        atual = atual->prox;
    }
    
    //Passo 2: Desenfileira todos os elementos da fila para inverter a ordem
    while(!filavazia(&fila)) {
        int desenfileira = desenfileirar(&fila);
        No* no = (No*)malloc(sizeof(No));
        no->dado = desenfileira;
        no->prox = pilha->topo;
        pilha->topo = no;
    }
}

void imprimirPilha(Pilha* pilha) {
    if(vazia(pilha)) {
        printf("\nPilha vazia!\n");
        return;
    }

    No* atual = pilha->topo;
    printf("\nPilha: ");
    while(atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void imprimirPilhaInvertida(Pilha* pilha) {
    if(vazia(pilha)) {
        printf("\nPilha vazia!\n");
        return;
    }

    Pilha pilhaAuxiliar;
    inicializar(&pilhaAuxiliar);

    // Copia os elementos da pilha original para uma pilha auxiliar invertendo a ordem
    No* atual = pilha->topo;
    while(atual != NULL) {
        insere(&pilhaAuxiliar, atual->dado);
        atual = atual->prox;
    }

    // Imprime a pilha invertida
    printf("\nPilha Invertida: ");
    atual = pilhaAuxiliar.topo;
    while(atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializar(&pilha);
    int opcao, dado;

    do {
        printf("\nMenu de Opcoes:\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Inverter\n");
        printf("4 - Imprimir Topo\n");
        printf("5 - Imprimir Pilha Toda\n");
        printf("6 - Imprimir Pilha Invertida\n");
        printf("7 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &dado);
                insere(&pilha, dado);
                break;
            case 2:
                remover(&pilha);
                break;
            case 3:
                inverter(&pilha);
                printf("Pilha invertida com sucesso!\n");
                break;
            case 4:
                dado = topo(&pilha);
                if(dado != -1)
                    printf("Topo: %d\n", dado);
                break;
            case 5:
                imprimirPilha(&pilha);
                break;
            case 6:
                imprimirPilhaInvertida(&pilha);
                break;
            case 7:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                exit(0);
        }
    } while(opcao != 7);

    return 0;
}
