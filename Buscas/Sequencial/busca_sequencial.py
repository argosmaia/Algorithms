import random

MAX_SIZE = 10  # Tamanho máximo da lista


# Função para gerar números aleatórios
def gerar_numero_aleatorio():
    return random.randint(1, 100)  # Gera números aleatórios entre 1 e 100


# Função para imprimir a lista
def imprimir_lista(lista, tamanho):
    print("Lista:", end=" ")
    for i in range(tamanho):
        print(lista[i], end=" ")
    print()


# Função para realizar busca sequencial na lista
def busca_sequencial(lista, tamanho, chave):
    for i in range(tamanho):
        if lista[i] == chave:
            return True  # Chave encontrada na lista
    return False  # Chave não encontrada na lista


if __name__ == "__main__":
    lista = [gerar_numero_aleatorio() for _ in range(MAX_SIZE)]  # Preenche a lista com números aleatórios
    tamanho = MAX_SIZE  # Tamanho da lista

    imprimir_lista(lista, tamanho)

    while True:
        print("\nEscolha uma opcao:")
        print("1. Encontrar numero")
        print("2. Sair")

        opcao = int(input())

        if opcao == 1:
            chave = int(input("Digite o numero a ser encontrado: "))
            if busca_sequencial(lista, tamanho, chave):
                print("O numero", chave, "foi encontrado na lista.")
            else:
                print("O numero", chave, "nao foi encontrado na lista.")
        elif opcao == 2:
            print("Saindo...")
            break
        else:
            print("Opcao invalida. Tente novamente.")
