def moedas(n, m, V):
    T = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

    # Preenchimento da 1ª linha
    for j in range(n + 1):
        T[0][j] = 0

    for i in range(m + 1):
        T[i][0] = 1

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if j >= V[i]:
                T[i][j] = T[i][j - V[i]] + T[i - 1][j]
            else:
                T[i][j] = T[i - 1][j]

    return T


def main():
    n = int(input("Digite o valor a ser trocado: "))
    m = int(input("Digite o numero de moedas: "))

    V = [0] * (m + 1)

    print("Digite os valores das moedas:")
    for i in range(1, m + 1):
        V[i] = int(input())

    T = moedas(n, m, V)

    print("Tabela de troco:")
    for i in range(m + 1):
        for j in range(n + 1):
            print(T[i][j], end=" ")
        print()


if __name__ == "__main__":
    main()
