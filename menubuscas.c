/*
Complemente sua implementação, acrescentando um menu de opções para que,
após informar um conjunto de valores, o usuário possa escolher que tipo de busca
efetuar. */
#include <stdio.h>

int buscaSequencial(int vetor[], int chave, int tam){
	int cont;
	for(cont = 0; cont < tam; cont++){
		if(vetor[cont] == chave)
			return cont;
	}
	return -1;
}

int buscaSeqOrd(int vetor[], int chave, int tam){
	int cont;
	for(cont=0;cont<tam;cont++){
		if(vetor[cont] == chave)
			return cont;
		if(vetor[cont] > chave)
			return -1;
	}
	return -1;
}

int buscaBinaria(int vetor[], int chave, int tam){
	int piso, teto, meio;
	piso = 0;
	teto = tam-1;
	meio = 0;
	while (piso <= teto){
		meio = (piso+teto)/2;
		if (vetor[meio] == chave)
			return meio;
		if(chave > vetor[meio])
			piso = meio + 1;
		else
			teto = meio-1;
	}
	return -1;
}

int main(){
	int vet[10];
	int cont, chave, res, op;
	for(cont=0; cont < 4; cont++){
		printf("Informe o valor da posição %d:",cont+1);
		scanf("%d",&vet[cont]);
	}
		printf("Que tipo de busca deseja fazer?");
		printf("\n1 - Sequencial\n2 - Sequencial Ordenada\n3 - Binária?\nEscolha: ");
		scanf("%i", &op);
		switch(op){
			case 1:
				printf("Que valor você deseja buscar? ");
				scanf("%d",&chave);
				res = buscaSequencial(vet,chave,4);
				//res = buscaSeqOrd(vet,chave,4);
				if(res!=-1)
					printf("\nO valor foi encontrado na posição: %d", res+1);
				else
					printf("\nValor não foi encontrado!");
			return 0;

			case 2:
				printf("Que valor você deseja buscar? ");
				scanf("%d",&chave);
				//res = buscaSequencial(vet,chave,4);
				res = buscaSeqOrd(vet,chave,4);
				if(res!=-1)
					printf("\nO valor foi encontrado na posição: %d", res+1);
				else
					printf("\nValor não foi encontrado!");
			return 0;

			case 3:
				printf("Que valor você deseja buscar? ");
				scanf("%d",&chave);
				res = buscaBinaria(vet,chave,4);
				//res = buscaSeqOrd(vet,chave,4);
				if(res!=-1)
					printf("\nO valor foi encontrado na posição: %d",res+1);
				else
					printf("\nValor não foi encontrado!");
			return 0;
			
			default:
				printf("Opção Inválida!");
		}
}