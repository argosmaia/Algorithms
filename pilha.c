#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int topo = -1; int vet[MAX];

void Empilha();
void Desempilha();
void Mostra();

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

void Mostra()
{
    if(topo == -1)
	{
		printf("\nPilha Vazia!!\n");
	}
	else
	{
		printf("\nElementos da pilha: \n");
		for(int i = topo; i >= 0; --i)
			printf("%d\n", vet[i]);
	}
}

int main()
{
    int op;
    while(1){
        printf("\nAlgoritmo de pilha\n");
        printf("\n1. Empilha\n2. Desempilha\n3. Mostrar pilha\n4. Finalizar\n");
        printf("\nEscolha a opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            Empilha();
            break;
        case 2:
            Desempilha();
            break;
        case 3:
            Mostra();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Pilha Inválida");
            break;
        }
    }

}