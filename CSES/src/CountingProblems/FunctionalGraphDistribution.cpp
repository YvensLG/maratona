#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
#define int long long
 
using namespace std;
 
const int M = 1e9 + 7;
const int MAX = 5008;
int fat[MAX], invfat[MAX];

int fexp(int b, int e) {
    int ans = 1;
    for (; e; b = b * b % M, e /= 2)
        if (e & 1) ans = ans * b % M;
    return ans;
}
 
int inv(int a) {
    return fexp(a, M - 2);
}
 
int choose(int a, int b) {
    if(b < 0 || b > a) return 0;
    return fat[a] * (invfat[b] * invfat[a - b] % M) % M;
}

// dp[n][k] = numero de formas de fazer k ciclos com n elementos (Numeros de Stirling)
// dp[n][k] = dp[n - 1][k - 1] + (n - 1)dp[n - 1][k]
// n faz o proprio ciclo ou adiciona em um existente
int dp[MAX][MAX]; 
 
// T(n, k) = sum dp[j][k] * (n choose j) * j * n^(n-j-1)
// numero de ciclos * permutacoes * numero de arvores enraizadas em j caras
void solve() {
    int n; cin >> n;

    dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int k = 1; k <= i; k++) {
            dp[i][k] = (dp[i - 1][k - 1] + (i - 1) * dp[i - 1][k]) % M;
        }
    }

    for(int k = 1; k <= n; k++) {
        int ans = 0;
        int pot = 1;
        for(int j = n; j >= k; j--) {
            ans = (ans + dp[j][k] * (choose(n - 1, j - 1) * pot % M)) % M;
            pot = (pot * n) % M;
        }

        cout << ans << '\n';
    }

}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    fat[0] = 1;
    for(int i = 1; i < MAX; i++) fat[i] = (fat[i - 1] * i) % M; 
    invfat[MAX - 1] = inv(fat[MAX - 1]);
    for(int i = MAX - 2; i >= 0; i--) invfat[i] = (invfat[i + 1] * (i + 1)) % M; 
 
    solve();
    return 0;
}