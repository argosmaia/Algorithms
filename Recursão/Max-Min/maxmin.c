#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int max;
  int min;
} Array;


Array maxmin(int array[], int inicio, int fim) {
  Array resultado;

  if(inicio == fim) {
    resultado.max = array[inicio];
    resultado.min = array[inicio];
    return resultado;
  } else if(inicio + 1 == fim) {
    if(array[inicio] > array[fim]) {
      resultado.max = array[inicio];
      resultado.min = array[fim];
    } else {
      resultado.max = array[fim];
      resultado.min = array[inicio];
    }
    return resultado;
  }

  int meio = (inicio + fim) / 2;
  Array esquerda = maxmin(array, inicio, meio);
  Array direita = maxmin(array, meio + 1, fim);

  resultado.max = (esquerda.max > direita.max) ? esquerda.max : direita.max;
  resultado.min = (esquerda.min < direita.min) ? esquerda.min : direita.min;

  return resultado;
}

int main() {
  int n;
  printf("Número de elementos:\n");
  scanf("%d", &n);

  int* valores = malloc(n * sizeof(int));
  if (!valores) {
    printf("Erro de alocação de memória.\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("Digite o valor #%d: ", i + 1);
    scanf("%d", &valores[i]);
  }

  Array resultado = maxmin(valores, 0, n - 1);
  printf("\nMáximo: %d\n", resultado.max);
  printf("Mínimo: %d\n", resultado.min);

  free(valores);
  return 0;
}
