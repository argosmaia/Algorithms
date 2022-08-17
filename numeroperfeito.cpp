#include <stdio.h>

int main()
{
	int num, i;
	int soma = 0;
	
	printf("Digite um número: ");
	scanf("%i", &num);
	
	for(i = 1; i < num; i++)
	{
		if(num % i == 0)
		{
			soma += i;
		}
	}
	if(soma == num)
		printf("%i é um número perfeito.\n", num);
	return 0;
}