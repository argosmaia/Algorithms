#include <stdio.h>
#include <stdlib.h>

int expr(int a, int n) {
    if(n == 0) {
        return 1;
    } else if(n % 2 == 1) {
        return expr(a, n-1) * a;
    } else {
        int p = expr(a, n/2);
        return p*p;
    }
}

int main() {
    int a, n;
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    int result = expr(a, n);
    printf("%d elevado a %d é igual a %d\n", a, n, result);
    return 0;
}
