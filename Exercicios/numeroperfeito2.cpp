#include <stdio.h>

int main()
{
	int num, i = 0,j;
	int soma = 0;
	
	while (i < 300)
	{
		for(j = 1; j < i; j++)
		{
			if(i % j == 0)
			{
				soma += j;
			}
		}
		if(soma == i)
			printf("%i é um número perfeito.\n", i);
	i++;

	}
	return 0;
}
