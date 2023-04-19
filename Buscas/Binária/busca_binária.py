import random

# Função para realizar a busca binária em uma lista ordenada
def binary_search(arr, x):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == x:
            return mid # Elemento encontrado, retorna o índice
        elif arr[mid] < x:
            left = mid + 1 # Elemento está na metade direita
        else:
            right = mid - 1 # Elemento está na metade esquerda

    return -1 # Elemento não encontrado

if __name__ == '__main__':
    # Tamanho da lista de dados
    n = 10

    # Geração aleatória dos dados
    arr = [random.randint(0, 99) for _ in range(n)]

    # Ordenação da lista de dados
    arr.sort()

    # Imprime a lista de dados
    print("Lista de Dados:", arr)

    # Loop para permitir ao usuário fazer buscas ou sair
    while True:
        choice = int(input("Digite o valor a ser buscado (ou -1 para sair): "))
        if choice == -1:
            print("Saindo...")
            break

        # Realiza a busca binária e imprime o resultado
        result = binary_search(arr, choice)
        if result == -1:
            print("Valor nao encontrado na lista.")
        else:
            print(f"Valor encontrado na posicao {result} da lista.")
