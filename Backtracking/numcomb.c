#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *pegaLetras(char digito) {
    switch (digito) {
        case '2':
            return "abc";

        case '3':
            return "def";

        case '4':
            return "ghi";

        case '5':
            return "jkl";

        case '6':
            return "mno";

        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        
        case '9':
            return "wxyz";

        default:
            return "";
    }
}

void backtrack(char *digitos, int index, char *atual, char **resultado, int *tamanhoResultado) {
    if(index == strlen(digitos)) {
        atual[index] = '\0';
        resultado[*tamanhoResultado] = strdup(atual);
        (*tamanhoResultado)++;
        return;
    }

    char *letras = pegaLetras(digitos[index]);
    int len = strlen(letras);

    for(int i = 0; i < len; i++) {
        atual[index] = letras[i];
        backtrack(digitos, index + 1, atual, resultado, tamanhoResultado);
    }
}

char **combinaLetras(char *digitos, int *retornaTamanho) {
    int n = strlen(digitos);
    if (n == 0) {
        *retornaTamanho = 0;
        return NULL;
    }

    int maxComb = 1;

    for (int i = 0; i < n; i++) {
        maxComb *= strlen(pegaLetras(digitos[i]));
    }

    char** resultado = (char**)malloc(sizeof(char*) * maxComb);
    *retornaTamanho = 0; 
    char* atual = (char*)malloc(sizeof(char) * (n + 1));

    backtrack(digitos, 0, atual, resultado, retornaTamanho); // Fix the variable name here

    free(atual);

    return resultado;
}


int main(int argc, char *argv[]) {

    printf("Insira 4 numeros (2-9): ");
    
    char digitos[5];  // Assuming a maximum length of 4 digits
    fgets(digitos, sizeof(digitos), stdin);

    digitos[strcspn(digitos, "\n")] = '\0';

    if (strlen(digitos) == 0) {
        printf("Nada digitado, saindo...\n");
        return 0;
    }

    int tamanho;
    char** resultado = combinaLetras(digitos, &tamanho);

    printf("Letter combinations for %s:\n", digitos);
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", resultado[i]);
        free(resultado[i]);
    }
    printf("\n");

    free(resultado);

    return 0;
}
