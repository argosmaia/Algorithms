#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3+5;

int** dp;

int distanciaEdicao(string A, string B, int i, int j) {
    if(i == 0) return j;
    if(j == 0) return i;
    if(dp[i][j] != -1) return dp[i][j];

    int cost = (A[i - 1] == B[j - 1]) ? 0 : 1;
    int del = distanciaEdicao(A, B, i-1, j) + 1;
    int ins = distanciaEdicao(A, B, i, j + 1) + 1;
    int sub = distanciaEdicao(A, B, i-1, j-1) + 1;

    dp[i][j] = min(del, min(ins, sub));

    return dp[i][j];
}

int main() {
    string A, B;

    cin >> A >> B;

    dp = new int*[A.size()+1];

    for(int i = 0; i <= A.size(); i++) dp[i] = new int[B.size()+1];

    memset(dp[0], -1, sizeof(int)*(A.size()+1)*(B.size()+1)); // inicia memoização com -1

    cout << distanciaEdicao(A, B, A.size(), B.size()) << endl;

    for(int i = 0; i <= A.size(); i++) delete[] dp[i]; // erro nessa linha

    delete[] dp;

    return 0;
}
