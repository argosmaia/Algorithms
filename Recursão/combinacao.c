#include <stdio.h>
#include <stdlib.h>

int combinacoes(int n, int p) {
    if(p = 1) {
        return n;
    } else {
        return combinacoes(n-1, p-1) * n/p
    }
}

//INCOMPLETE
