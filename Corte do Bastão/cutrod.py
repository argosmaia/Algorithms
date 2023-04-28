# -*- coding: utf-8 -*-

def max(a, b):
    return a if a > b else b

def cortarbastao(preco, n, memo):
    if n == 0:
        return 0

    if memo[n] != -1:
        return memo[n]

    max_value = -1
    
    for i in range(n):
        max_value = max(max_value, preco[i] + cortarbastao(preco, n - i - 1, memo))
    
    memo[n] = max_value

    return max_value

preco = [1, 5, 8, 9, 10, 17, 17, 20]
n = len(preco)

memo = [-1] * (n + 1)

print("\nVALOR MAXIMO: ", cortarbastao(preco, n, memo))
