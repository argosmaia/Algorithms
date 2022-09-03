#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int info;
    struct no *prox;
    struct no *ant;
} no;

no *inicioL;
no *inicioD;

void inicializa()
{
    inicioL = NULL;
    inicioD = NULL;
}

int listavazia()
{
    if(inicioL == NULL && inicioD == NULL)
    {
        return 1;
    }
    return 0;
}

no* criaNo(int valor)
{
    no *aux;
    aux = (no*)malloc(sizeof(no));
    if(aux != NULL)
    {
        aux->info = valor;
        aux->ant = NULL;
        aux->prox = NULL;
    }
    return aux;
}

void inserirDir(int info)
{
    no *aux;
    aux = criaNo(valor);
    if(aux != NULL)
    {
        if(listavazia())
        {
            inicioL = aux;
            inicioD = aux;
        }else{
            aux->ant = inicioD;
            inicioD->prox = aux;

        }
    }else{
        printf("Não foi possível inserir pela direita\n");
    }
}

void inserirEsq(int info)
{
    no *aux;
    aux = criaNo(valor);
    if(aux != NULL)
    {
        if(listavazia())
        {
            inicioL = aux;
            inicioD = aux;
        }else{
            aux->ant = inicioL;
            inicioL->prox = aux;

        }
    }else{
        printf("Não foi possível inserir pela esquerda\n");
    }
}

void percorrerDir()
{
    if(!listavazia())
    {
        no *aux = inicioD;
        while(aux != NULL)
        {
            printf("\n%d", aux->info);
            aux = aux->ant;
        }
    }
}

void percorrerEsq()
{
    if(!listavazia())
    {
        no *aux = inicioL;
        while(aux != NULL)
        {
            printf("\n%d", aux->info);
            aux = aux->ant;
        }
    }
}

no *buscaLDE(int valor){}

void remover(int valor)
{
    if(!listavazia())
    {
        no *aux;
        aux = buscaLDE(valor);
        if(aux != NULL)
        {
            if(inicioD == inicioL)
            {
                inicioD = NULL;
                inicioL = NULL;
            }else{
                if(aux == inicioL)
                {
                    inicioL = aux;
                    inicioL->ant = NULL;

                }else{
                    if(aux == inicioD)
                    {
                        inicioD = aux->ant;
                        inicioD->prox = NULL;
                    }else{
                        no *anterior = aux->ant;
                        no *posterior = aux->prox;
                        anterior->prox = posterior;
                        posterior->ant = anterior;
                    }
                }
            }
            free(aux);
        }
    }
}

int main()
{
    inicializa();
    int op, item;
    printf("Bem vindo a lista encadeada, faça a tua opção: ");
    while(1)
    {
        printf("\n1 - Inserir no pela direita\n2 - Inserir pela esquerda\n3 - Percorrer pela direita\n4 - Percorrer pela esquerda\n5 - Remover\n6 - Sair\nEscolha a opção: ");
        scanf("%i", &op);
        switch(op)
        {
            case 1:
                printf("\nDigite o valor a inserir pela direita: ");
                scanf("%i", &item);
                inserirDir(item);
                break;
            
            case 2:
                printf("\nDigite o valor a inserir pela esquerda: ");
                scanf("%i", &item);
                inserirEsq(item);
                break;

            case 3:
                percorrerDir();
            
            case 4:
                percorrerEsq();
            
            case 5:
                printf("Remover que elemento da lista: ");
                scanf("%i", &item);
                remover(item);
            case 6:
                exit(0);
        }
    }
}