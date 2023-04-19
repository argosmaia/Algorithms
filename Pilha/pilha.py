MAX_SIZE = 100

# Definição da classe para a pilha
class Pilha:
    def __init__(self):
        self.dados = [None] * MAX_SIZE # Lista para armazenar os dados
        self.topo = -1 # Variável para rastrear o topo da pilha

    # Função para verificar se a pilha está vazia
    def is_vazia(self):
        return self.topo == -1 # Retorna True se o topo for igual a -1, indicando pilha vazia

    # Função para verificar se a pilha está cheia
    def is_cheia(self):
        return self.topo == MAX_SIZE - 1 # Retorna True se o topo for igual ao tamanho máximo da pilha

    # Função para inserir uma string na pilha
    def inserir_string(self, string):
        if self.is_cheia():
            print("Erro: Pilha cheia")
            return
        self.topo += 1 # Incrementa o topo
        self.dados[self.topo] = string # Insere a string no topo da pilha

    # Função para verificar se uma string é um número real (float) ou inteiro (int)
    def is_numero(self, string):
        try:
            float(string)
            return True
        except ValueError:
            return False

    # Função para converter uma string para número real (float) ou inteiro (int)
    def converter_numero(self, string):
        if self.is_numero(string):
            inteiro = int(string) # Converte a string para inteiro
            print("Número inteiro:", inteiro)
        else:
            real = float(string) # Converte a string para float
            print("Número real: {:.2f}".format(real))

    # Função para remover o topo da pilha
    def remover_topo(self):
        if self.is_vazia():
            print("Erro: Pilha vazia")
            return
        self.topo -= 1 # Decrementa o topo

    # Função para verificar o topo da pilha
    def ver_topo(self):
        if self.is_vazia():
            print("Erro: Pilha vazia")
            return
        print("Topo da pilha:", self.dados[self.topo])

    # Função para visualizar toda a pilha
    def ver_pilha(self):
        if self.is_vazia():
            print("Pilha vazia")
            return
        print("Conteúdo da pilha:")
        for i in range(self.topo, -1, -1):
            print(self.dados[i])


pilha = Pilha()
while True:
    print("\nEscolha uma opção:")
    print("0. Sair")
    print("1. Inserir string")
    print("2. Verificar se é número e converter")
    print("3. Remover topo")
    print("4. Ver topo")
    print("5. Ver pilha toda")

    opcao = int(input("Opção: "))

    if opcao == 0:
        print("Saindo...")
        break
    elif opcao == 1:
        entrada = input("Digite a string a ser inserida: ")
        pilha.inserir_string(entrada)
    elif opcao == 2:
        entrada = input("Digite a string a ser verificada: ")
        pilha.converter_numero(entrada)
    elif opcao == 3:
        pilha.remover_topo()
    elif opcao == 4:
        pilha.ver_topo()
    else:
        pilha.ver_pilha()
     
