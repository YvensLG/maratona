const int MAX = 508;
const int MOD = 1e9 + 7;

/*
dp[p][i][j] eh o numero de formas de colocar
j bispos nas diagonais de paridade p com indice ate i
(os indices das diagonais sao definidos da menor para a maior)
*/
int dp[2][MAX][2 * MAX];

int num_squares(bool p, int d) {
    if (p)
        return ((d - 1) / 2) * 2 + 1;
    else
        return ((d + 1) / 2) * 2;
}

void solve(){
    int n, k; cin >> n >> k;

    if (k >= 2 * n) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i <= n; i++) {
        dp[0][i][0] = 1;
        dp[1][i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[1][i][j] = (dp[1][i-1][j] + dp[1][i-1][j-1] * (num_squares(1, i) - j + 1) % MOD) % MOD;
            if(i < n)
            dp[0][i][j] = (dp[0][i-1][j] + dp[0][i-1][j-1] * (num_squares(0, i) - j + 1) % MOD) % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = (ans + dp[0][n - 1][i] * dp[1][n][k-i]) % MOD;
    }

    cout << ans << '\n';
}
