using vi = vector<int>;

const int maxn = 1e2 + 5;
const int maxx = 5e3 + 5;
const int mod = 1e9 + 7;

int sum( int a, int b ){
    return (a + b)%mod;
}

int prod( int a, int b ){
    return 1LL*a*b % mod;
}

int dp[2][maxn][maxx];

void solve(){
    int n, x; cin >> n >> x;
    vi v(n);
    for( int &x : v ) cin >> x;

    sort(all(v));

    int cur = 0, prev = 1;
    for( int j = 0; j <= x; j++ ) dp[cur][0][j] = 1;

    for( int t : v ){
        swap( cur, prev );
        for( int j = 0; j <= n/2; j++ )
            for( int k = 0; k < maxx; k++ ){
                // Colocar em um grupo existente ou em um grupo proprio
                dp[cur][j][k] = prod( j + 1, dp[prev][j][k] );

                // Criar novo grupo
                if( k + t < maxx ) dp[cur][j][k] = sum( dp[cur][j][k], dp[prev][j + 1][k + t] );

                // Terminar um grupo
                if( k - t >= 0 && j > 0  ) dp[cur][j][k] = sum( dp[cur][j][k], prod( j, dp[prev][j - 1][k - t] ) );
            }
    }

    cout << dp[cur][0][0] << '\n';
}
