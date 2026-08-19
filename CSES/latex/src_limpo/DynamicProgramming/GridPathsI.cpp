const int maxn = 1e3 + 5, inf = 2e9, M = 1e9 + 7;

int dp[maxn][maxn];
char grid[maxn][maxn];
int n;

int calc(int a, int b){
    if(a < 0 || b < 0 || a >= n || b >= n) return 0;
    if(dp[a][b] >= 0) return dp[a][b];
    if(grid[a][b] == '*') return dp[a][b] = 0;

    return dp[a][b] = (calc(a + 1, b) + calc(a, b + 1)) % M;
}

void solve() {
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = -1;
            cin >> grid[i][j];
        }
    }

    dp[n - 1][n - 1] = grid[n - 1][n - 1] == '*' ? 0 : 1;
    calc(0, 0);

    cout << dp[0][0] << '\n';
}
