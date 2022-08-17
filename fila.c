#include <stdio.h>
#define SIZE 10
void enfileirar();
void desenfileirar();
void mostrar();
int fileira[SIZE];
int Rear = -1;
int Front = -1;

void enfileirar()
{
	int inserir;
	if (Rear == SIZE - 1)
		printf("Fila Cheia\n");
	else
	{
		if (Front == -1)

			Front = 0;
		printf("\nElemento a inserir: ");
		scanf("%d", &inserir);
		Rear += 1;
		fileira[Rear] = inserir;
	}
}

void desenfileirar()
{
	if (Front == -1 || Front > Rear)
	{
		printf("\nFila Vazia\n");
		return;
	}
	else
	{
		printf("Elemento deletado: %d\n", fileira[Front]);
		Front = Front + 1;
	}
}

void mostrar()
{
	if (Front == -1)
		printf("Fila Vazia\n");
	else
	{
		printf("Fila: \n");
		for (int i = Front; i <= Rear; i++)
			printf("%d ", fileira[i]);
		printf("\n");
	}
}

int main()
{
	int ch;
	while (1)
	{
		printf("\n1. Enfileirar\n");
		printf("2. Desenfileirar\n");
		printf("3. Mostrar\n");
		printf("4. Sair\n");
		printf("Escolha uma opção: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			enfileirar();
			break;
		case 2:
			desenfileirar();
			break;
		case 3:
			mostrar();
			break;
		case 4:
			printf("\nSaindo...");
			exit(0);
		default:
			printf("Opção incorreta\n");
		}
	}
}