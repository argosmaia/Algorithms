#include <iostream>
#include <stdlib.h>

int buscabinaria(int vet[], int esq, int dir, int x) {
    if(dir >= esq){
        int meio = (esq + dir) / 2;
        
        if(vet[meio] == x) return meio;
        
        if (vet[meio] >= x) return buscabinaria(vet, esq, meio - 1, x);
        
        return buscabinaria(vet, meio + 1, dir, x);
    }
    return -1;
}


int main() {
    int n;
    std::cout << "Digite o tamanho do array: ";
    std::cin >> n;
    
    int arr[n];
    
    std::cout << "Digite os elementos do array em ordem crescente:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    int x;
    
    std::cout << "Digite o elemento a ser buscado: ";
    std::cin >> x;
    
    int result = buscabinaria(arr, 0, n - 1, x);
    
    if (result == -1)
        std::cout << "Elemento nao encontrado no array";
    else
        std::cout << "Elemento encontrado no indice " << result;
    return 0;
}
