#include<stdio.h>
#include<stdlib.h>


//DATA-ERROR: O PROGRAMA NÃO ESTÁ LENDO A ENTRADA PELO FINAL

typedef struct no
{
    int info;
    struct no* prox;
} no;

no *inicioL;

void inicializa()
{
    inicioL = NULL;
}

int listavazia()
{
    if(inicioL == NULL)
        return 1;
    return 0;
}

void insere(int valor)
{
    no *aux;
    aux = (no*)malloc(sizeof(no));
    if(aux != NULL)
    {
        aux->info = valor;
        aux->prox = inicioL;
        inicioL = aux;
    }
}

void inserefinal(int valor)
{
    no *aux, *p;
    aux = (no*)malloc(sizeof(no));
    if(aux != NULL)
    {
        aux->info = valor;
        aux->prox = NULL;
        if(listavazia())
        {
            inicioL = aux;
        }else{
            p = inicioL;
            while(p->prox != NULL)
                p = p->prox;
            p = p->prox;
        }
    }
}

void percorrer()
{
    if(!listavazia())
    {
        no * aux;
        aux = inicioL;
        while(aux != NULL)
        {
            printf("%d", aux->info);
            aux = aux->prox;
        }
    }else{
        printf("\nLista Vazia\n");
    }
}

int tamanho()
{
    struct no *p;
    int cont = 0;
    p = inicioL;
    while (p != NULL)
    {
        // Visit to next node
        p = p->prox;
        // Increase the node counter
        cont++;
    }
    printf("%i nós", cont);
    return cont;
}

int main()
{
    int op, item;
    printf("\nMenu da lista encadeada");
    printf("\n1 - Insere no inicio\n2 - Insere no fim\n3 - Percorre\n4 - Tamanho dos nós\n5 - Sair");
    while(1)
    {
        printf("\nEscolha uma opção: ");
        scanf("%i", &op);
        switch(op)
        {
            case 1:
                printf("Elemento à ser inserido: ");
                scanf("%i", &item);
                insere(item);
                break;

            case 2:
                printf("Elemento à ser inserido no final: ");
                scanf("%i", &item);
                inserefinal(item);
                break;
            
            case 3:
                percorrer();
                break;
            
            case 4:
                tamanho();
                break;
            
            case 5:
                exit(0);
                break;
            
            default:
                printf("Opção Inválida!");
        }
    }
}
