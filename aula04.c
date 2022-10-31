#include <stdio.h>

int fatorial(int num)
{
    if(num == 0 || num ==1 )
        return 1;
    else
        return(num * fatorial(num-1));
}

int main()
{
    int num;
    printf("\nDigite um número: ");
    scanf("%i", &num);
    fatorial(num);

    printf("\nO fatorial de %i é %i\n", num, fatorial(num));
    return 0;
}