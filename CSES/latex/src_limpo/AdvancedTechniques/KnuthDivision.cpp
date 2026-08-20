using ll = long long;

const int maxn = 5e3;
const ll inf = 1e18;

ll dp[maxn][maxn], sum[maxn];
int opt[maxn][maxn];

ll cost( int i, int j ){
    return sum[j] - ((i > 0) ? sum[i - 1] : 0);
}

void solve(){
    int n; cin >> n;

    for( int i = 0; i < n; i++ ){
        int x; cin >> x;
        sum[i] += x;
        sum[i + 1] = sum[i];

        fill( dp[i], dp[i] + maxn, inf );
    }

    for( int len = 1; len <= n; len++ )
        for( int l = 0, r = len - 1; r < n; l++, r++ ){
            if( len == 1 ){
                dp[l][r] = 0; opt[l][r] = l; continue;
            }

            dp[l][r] = inf;
            opt[l][r] = l;
            for( int m = opt[l][r - 1]; m <= opt[l + 1][r]; m++ )
                if( dp[l][m] + dp[m + 1][r] < dp[l][r] ){
                    dp[l][r] = dp[l][m] + dp[m + 1][r];
                    opt[l][r] = m;
                }
            dp[l][r] += cost( l, r );
        }

    cout << dp[0][n - 1] << '\n';
}
