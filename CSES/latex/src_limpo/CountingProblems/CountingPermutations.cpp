const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;

int sum( int a, int b ){
    return (a + b)%mod;
}

int prod( int a, int b ){
    return 1LL * a * b % mod;
}

int dp[2][maxn][3][3];

void solve(){
    int n; cin >> n;

    auto push = []( int dp, int &next ){ next = sum( next, dp ); };

    int cur = 0, next = 1;
    dp[cur][1][2][2] = 1;

    for( int i = 1; i < n; i++, swap( cur, next ) )
        for( int k = 1; k <= n; k++ )
            for( int b = 0; b < 3; b++ )
                for( int e = 0; e <= b; e++ ) {
                    int &res = dp[cur][k][b][e];

                    // Adicionar componente nova

                    push( prod( k - 1, res ), dp[next][k + 1][2][0] ); // No meio
                    push( prod( 2    , res ), dp[next][k + 1][2][1] ); // Nas pontas

                    // Colocar na ponta de uma componente

                    push( prod( 2*(k - 1) - b + e, res ), dp[next][k][1][0] ); // No meio
                    push( prod( 2             - e, res ), dp[next][k][1][1] ); // Nas pontas

                    // Mergear componentes

                    push( prod( k - 1 - b + e, res ), dp[next][k - 1][0][0] );

                    res = 0;
                }

    int ans = 0;
    for( int b = 0; b < 3; b++ ) for( int e = 0; e <= b; e++ ) ans = sum( ans, dp[cur][1][b][e] );
    cout << ans << '\n';
}
