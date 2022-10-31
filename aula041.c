#include <stdio.h>

int fibonacci(int n)
{
    if(n < 2)
        return n;
    else
        return(fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
    int num;
    printf("\nUm n° para parar a sequencia: ");
    scanf("%i", &num);
    for(int i = 0; i < num; i++)
        printf("%i\n", fibonacci(i));
    return 0;  
}