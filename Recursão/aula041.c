#include <stdio.h>

int recurfibonacci(int n)
{
    if(n < 2)
        return n;
    else
        return(recurfibonacci(n-1) + recurfibonacci(n-2));
}

int iterfibonacci(int n)
{
    int result, prim = 0, seg = 1;
    printf("\nSequencia até pos x = ");
    scanf("%d", &n);
    printf("\nSéries:\n");
    for(int i = 0; i < n; i++)
    {
        if (i <= 1)
            result = i;
        else
        {
            result = prim + seg;
            prim = seg;
            seg = result;
        }
        printf("%d\n", result);
    }
}

int main()
{
    int num, op, n;
    printf("\n1 - Recursiva\n2 - Iterada: ");
    scanf("%i", &op);
    while(1)
    {
        switch(op)
        {
            case 1:
                printf("\nUm n° para parar a sequencia: ");
                scanf("%i", &num);

                for(int i = 0; i < num; i++)
                    printf("%i\n", recurfibonacci(i));
                return 0;
            break;

            case 2:
                printf("Um numero para parar a sequencia: ");
                scanf("%i", &num);
                iterfibonacci(n);
            break;
        }
    } 
}
