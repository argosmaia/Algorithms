/*
Faça um programa que preencha um vetor com 10 números inteiros positivos e crie
um segundo vetor, em que cada posição receberá o fatorial do valor armazenado no
1º vetor na posição correspondente. Ao final, o programa deve exibir os dois vetores
na tela
*/
#include <stdio.h>
int fatorial(int i){
    int fatorial = 1;
    
    for(fatorial = 1; i > 1; i = i -1){
        fatorial *= i;
    }

    return fatorial;
}
int main(){
  int vetorA[5];
  int vetorB[5];
  int i;

  for(i = 0; i< 5; i++){
        printf("Digite um valor: ");
        scanf("%i", &vetorA[i]);
  }
   for(i =0; i < 5; i++){
        vetorB[i] = fatorial(vetorA[i]);
   }
   printf("\nNumeros do vetor: ");
   for(int j = 0; j < 5; j++)
   {
    printf("%d\n", vetorA[j]);
   }
   printf("\nFatorial dos números do primeiro vetor:\n");
   for(i = 0; i < 5; i++)
    {
        printf("%d\n", vetorB[i]);
    }
}