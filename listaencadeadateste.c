/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
} no;

no *inicioL;

void inicializa(){
    inicioL = NULL;
}

int listavazia(){
    if(inicioL == NULL)
        return 1;
    return 0;
}

void insereinicio(int valor){
    no *aux;
    aux = (no*)malloc(sizeof(no));
    if(aux == NULL){
        aux->info = valor;
        aux->prox = inicioL;
        inicioL = aux;
    }else{
        printf("\nImpossível alocar espaço\n");
    }
}

void inserefim(int valor){
    no *aux, *p;
    aux = (no*)malloc(sizeof(no));
    if(aux == NULL){
        aux->info = valor;
        aux->prox = NULL;
        if(listavazia()){
            inicioL = aux;
        }else{
            p = inicioL;
            while(p->prox != NULL)
                p = p->prox;
            p->prox = aux;
        }
    }

}

void percorre(){
    if(!listavazia()){
        no *aux;
        aux = inicioL;
        while (aux != NULL)
        {
            printf("\n%d\n", aux->info);
            aux = aux->prox;
        }
    }else{
        printf("\nLista Vazia!\n");
    }
}

void remover(int valor){
    no *ant, *aux;
    aux = inicioL;
    ant = NULL;
    if (!listavazia()) {
        while (aux != NULL && aux->info != valor) {
            ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL) {
            printf("\nValor nao encontrado.\n");
        }else{
            if(ant == NULL){
                inicioL = aux->prox;
            }else{
                ant->prox = aux->prox;
            }
        free(aux);
        }
    }else{
        printf("\nLista Vazia!");
    }
}

int main(){
    inicializa();
    int op, valor;
    while(1){
        printf("\n1 - Insere no inicio\n2 - Insere no fim\n3 - Remover inicio\n4 - Percorre\n5 - Sair\n");
        scanf("%i", &op);
        switch (op){
            case 1: /* constant-expression */
                printf("\nDigite um valor: ");
                scanf("%i", &valor);
                insereinicio(valor);
                break;

            case 2:
                printf("\nDigite um valor: ");
                scanf("%i", &valor);
                inserefim(valor);
                break;

            case 3:
                printf("\nValor a remover: ");
                scanf("%i", &valor);
                remover(valor);
                break;
            
            case 4:
                percorre();
                break;
            
            case 5:
                exit(0);
                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    }
}


