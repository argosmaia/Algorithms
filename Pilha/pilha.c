
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void Empilha()
{
    int num;
    if(topo == MAX - 1)
    {
        printf("\nPilha entupida\n");
    }else{
        printf("\nDigite um elemento: ");
        scanf("%d", &num);
        topo += 1;
        vet[topo] = num;
    }
}

void Desempilha()
{
    if(topo==-1)
    {
        printf("\nPilha vazia\n");
    }else{
		printf("\nExcluir topo:  %d", vet[topo]);
		topo -= 1;
    }
}
