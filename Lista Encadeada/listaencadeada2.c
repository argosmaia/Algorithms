#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    struct no *prox;
} no;

no *inicioL;

void inicializar()
{
    inicioL = NULL;
}

int listaVazia()
{
    if(inicioL == NULL)
        return 1;
    return 0;
}

void inserir(int valor)
{
    no *aux;
    aux = (no*)malloc(sizeof(no));
    if(aux != NULL)
    {
        aux->info = valor;
        aux->prox = inicioL;
        aux = inicioL;
    }else{
        printf("\nNão foi possivel inserir!\n");
    }
}

int percorrer()
{
    no *aux;
    if(!listaVazia())
    {
        aux = inicioL;
        while (aux != NULL)
        {
            printf("%d", aux->info);
            aux = aux->prox;
        }
        
    }else{
        printf("\nLista Vazia!");
    }
}

int main()
{
    inicializar();
    return 0;
}
