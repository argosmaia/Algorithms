N = 8  # Tamanho do tabuleiro
board = [[0] * N for _ in range(N)]  # Tabuleiro

def isValidMove(row, col):
    # Verifica se há alguma torre na mesma linha ou coluna
    for i in range(N):
        if board[row][i] == 1 or board[i][col] == 1:
            return False

    # Verifica se há alguma torre na diagonal principal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, N), range(col, N)):
        if board[i][j] == 1:
            return False

    # Verifica se há alguma torre na diagonal secundária
    for i, j in zip(range(row, -1, -1), range(col, N)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, N), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True

def solve(col):
    if col == N:
        # Imprime a configuração final do tabuleiro
        for row in board:
            print(' '.join(str(cell) for cell in row))
        return True

    for row in range(N):
        if isValidMove(row, col):
            # Coloca uma torre na posição (row, col)
            board[row][col] = 1

            # Chama recursivamente para a próxima coluna
            if solve(col + 1):
                return True

            # Se não encontrou uma solução, remove a torre da posição (row, col)
            board[row][col] = 0

    return False

solve(0)  # Começa na coluna 0
