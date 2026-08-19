const int maxn = 1e6 + 5, inf = 2e9, M = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;

    int dp[a + 1][b + 1];

    for(int i = 1; i <= min(a, b); i++) dp[i][i] = 0;

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j) continue;
            dp[i][j] = inf;
            for(int k = 1; k < i; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
            for(int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
        }
    }

    cout << dp[a][b] << '\n';
}
