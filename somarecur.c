#include <stdio.h>

int soma(int num1, int num2)
{
    if(num1 == 0 && num2 == 0)
        return 0;
    else
        return(soma(num1)+soma(num2));
}

int main()
{
    int num1, num2;
    printf("\nDigite as somas p/ n1 e n2:");
    scanf("%i %i", &num1, &num2);

    printf("\nA solução de %i + %i = %i", num1, num2, soma(num1+num2));
}