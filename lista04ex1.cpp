#include<stdio.h>
#include<stdlib.h>

//INCOMPLETO

typedef struct no
{
    int info;
    struct no *prox;
} no;

no *inicioL;

void inicializa()
{
    inicioL = NULL;
}

int listavazia()
{
    if(inicioL == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}

//INSERE NO INICIO
void inserir(int valor)
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

void insere_final(int valor)
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
            while (p->prox != NULL)
                p = p->prox;
            p->prox = aux;
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

void soma()
{
    int s = 0;
    no *p;
    p = inicioL;
    if(!listavazia())
    {
        while(p != NULL)
        {
            s += s + p->info;
            p = p->prox;
        }
        printf("%i", s); 
    }else{
        printf("Lista vazia");
    }
}

int main()
{
    int op, item;
    printf("\nBem vindo a lista encadeada, faça a tua opção: ");

    while(1)
    {
        printf("\n1 - Insere no inicio\n2 - Insere no fim\n3 - Percorre\n4 - Soma\n5 - Sair\nEscolha: ");
        scanf("%i", &op);
        switch(op)
        {
            case 1:
                printf("Insira um valor: ");
                scanf("%i", &item);
                inserir(item);
                break;
            
            case 2:
                printf("Insira um valor: ");
                scanf("%i", &item);
                insere_final(item);
                break;
    
            case 3:
                percorrer();
                break;
            
            case 4:
                soma();
                break;
            case 5:
                exit(0);
    
            default:
                printf("Opção Inválida");
                break;
        }
    }
}
