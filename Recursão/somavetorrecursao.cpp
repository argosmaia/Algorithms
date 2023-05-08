#include <iostream>

int soma(int vet[], int TAM) {
    if(TAM == 0) {
        return 0;
    } else if(TAM == 1) {
        return vet[0];
    }
    
    int meio = TAM / 2;
    int dirtam = TAM - meio;
    int esqsoma = soma(vet, meio);
    int dirsoma = soma(vet + meio, dirtam);
    
    return esqsoma + dirsoma;
}

int main() {
    int TAM, i;
    srand(time(NULL));

    printf("Digite o tamanho da array: ");
    scanf("%d", &TAM);

    int vet[TAM];

    printf("Array gerada:\n");

    for (i = 0; i < TAM; i++) {
        vet[i] = rand() % 100; // gerando número aleatório entre 0 e 99
        printf("%d ", vet[i]);
    }

    printf("\nSoma dos elementos da array: %d\n", soma(vet, TAM));

    return 0;
}
