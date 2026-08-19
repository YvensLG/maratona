const int MAXN = 3005;
const int MAXK = 26;

// maior quad com canto em (i, j) sem letra X
int dp[2][MAXN][MAXK];
int mat[MAXN][MAXN];

void solve() {
    int n, k; cin >> n >> k;

    if(k == 1) {
        cout << (ll)n * (n + 1LL) * (2 * n + 1LL) / 6 << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < n; j++) {
            mat[i][j] = s[j] - 'A';
        }
    }

    for(int j = 0; j < n; j++) {
        for(int c = 0; c < k; c++) {
            if(mat[0][j] != c) dp[0][j][c] = 1;
        }
    }

    ll tot = 0;

    for(int i = 1; i < n; i++) {
        for(int c = 0; c < k; c++)
            if(mat[i][0] != c) dp[1][0][c] = 1;

        for(int j = 1; j < n; j++) {
            int aux = 0;
            for(int c = 0; c < k; c++) {
                if(mat[i][j] == c) dp[1][j][c] = 0;
                else dp[1][j][c] = min({dp[1][j - 1][c], dp[0][j][c], dp[0][j - 1][c]}) + 1;
                aux = max(aux, dp[1][j][c]);
            }
            tot += min(i, j) - aux + 1;
        }

        for(int j = 0; j < n; j++) {
            for(int c = 0; c < k; c++) {
                dp[0][j][c] = dp[1][j][c];
                dp[1][j][c] = 0;
            }
        }
    }

    cout << tot << '\n';
}
