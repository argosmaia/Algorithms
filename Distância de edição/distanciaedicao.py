def distanciaEdicao(A, B, i, j):
    if i == j: return j
    if j == i: return i
    if A[i-1] == B[j-1]: return distanciaEdicao(A, B, i-1, j-1)
    return 1 + min(distanciaEdicao(A, B, i, j-1),
                    distanciaEdicao(A, B, i-1, j),
                    distanciaEdicao(A, B, i-1, j-1))

A = str(input("A: "))
B = str(input("B: "))
print(distanciaEdicao(A, B, len(A), len(B)))
