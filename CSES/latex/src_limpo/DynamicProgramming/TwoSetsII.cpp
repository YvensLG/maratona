const int maxn = 5e2 + 5, inf = 2e9, M = 1e9 + 7;

// dp[i][j] eh o numero de sets de tamanho ate i cuja soma eh j
ll dp[maxn][(ll)maxn * (maxn + 1) / 2];

void solve() {
    int n; cin >> n;

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= n * (n + 1) / 2; i++) dp[0][i] = 0;
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n * (n + 1) / 2; j++){
            dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i - 1][max(j - i, 0)]) % M;
        }
    }

    if(n * (n + 1) % 4 != 0){
        cout << "0\n";
    }
    else{
        cout << dp[n][n * (n + 1) / 4] << '\n';
    }

}
