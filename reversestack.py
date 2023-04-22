# Estrutura encadeada
class No:
    def __init__(self, dado):
        self.dado = dado
        self.prox = None

# Estrutura da pilha encadeada
class Pilha:
    def __init__(self):
        self.topo = None

    def cheia(self):
        return False

    def vazia(self):
        return self.topo is None

    def insere(self, dado):
        if self.cheia():
            print("\nPilha cheia!\n")
            return

        no = No(dado)
        no.prox = self.topo
        self.topo = no

    def remover(self):
        if self.vazia():
            print("\nPilha está vazia!\n")
            return -1
        temp = self.topo
        dado = temp.dado
        self.topo = temp.prox
        del temp
        return dado

    def topo(self):
        if self.vazia():
            print("\nPilha vazia!\n")
            return -1
        return self.topo.dado

# Estrutura da fila encadeada
class Fila:
    def __init__(self):
        self.frente = None
        self.fim = None

    def filavazia(self):
        return self.frente is None

    def enfileirar(self, dado):
        no = No(dado)
        no.prox = None
        if self.fim is None:
            self.frente = no
            self.fim = no
        else:
            self.fim.prox = no
            self.fim = no

    def desenfileirar(self):
        if self.filavazia():
            print("\nFila vazia!\n")
            return -1
        saida = self.frente
        dado = saida.dado
        self.frente = saida.prox
        if self.frente is None:
            self.fim = None
        del saida
        return dado

# Invertendo a pilha por meio da fila
def inverter(pilha):
    if pilha.vazia():
        print("\nPilha vazia\n")
        return

    temp = None
    fila = Fila()
    atual = pilha.topo

    # Passo 1: Enfileira todos os dados da pilha na fila
    while atual is not None:
        fila.enfileirar(atual.dado)
        atual = atual.prox

    # Passo 2: Desenfileira todos os elementos da fila para inverter a ordem
    while not fila.filavazia():
        desenfileira = fila.desenfileirar()
        no = No(desenfileira)
        no.prox = pilha.topo
        pilha.topo = no

# Função para imprimir a pilha
def imprimirPilha(pilha):
    if pilha.vazia():
        print("\nPilha vazia!\n")
        return

    atual = pilha.topo
    print("\nPilha: ", end="")
    while atual is not None:
        print(atual.dado, end=" ")
        atual = atual.prox
    print()

# Função para imprimir a pilha invertida
def imprimirPilhaInvertida(pilha):
    if pilha.vazia():
        print("\nPilha vazia!\n")
        return

    pilhaAuxiliar = Pilha()
    # Copia os elementos da pilha original para a pilha auxiliar
    atual = pilha.topo
    while atual is not None:
        pilhaAuxiliar.insere(atual.dado)
        atual = atual.prox

    print("\nPilha Invertida: ", end="")
    while not pilhaAuxiliar.vazia():
        print(pilhaAuxiliar.topo(), end=" ")
        pilhaAuxiliar.remover()

while True:
     print("\n----- MENU -----")
     print("1 - Inserir elemento na pilha")
     print("2 - Remover elemento da pilha")
     print("3 - Imprimir pilha")
     print("4 - Inverter pilha")
     print("5 - Imprimir pilha invertida")
     print("0 - Sair")
     opcao = int(input("\nDigite uma opção: "))

    if opcao == 1:
        dado = int(input("Digite o valor a ser inserido na pilha: "))
        pilha.insere(dado)
    elif opcao == 2:
        pilha.remover()
    elif opcao == 3:
        imprimirPilha(pilha)
    elif opcao == 4:
        inverter(pilha)
    elif opcao == 5:
        imprimirPilhaInvertida(pilha)
    elif opcao == 0:
        print("\nEncerrando o programa...")
        break
    else:
        print("\nOpção inválida! Tente novamente.")
