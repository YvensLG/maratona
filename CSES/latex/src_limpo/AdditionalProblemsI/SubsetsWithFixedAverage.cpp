const int maxx = 500*500 + 10;
const int mod = 1e9 + 7;

int dp[2*maxx];

int sum( int a, int b ){
    return ((a + b)%mod + mod)%mod;
}

void solve(){
    int n, k; cin >> n >> k;
    dp[maxx] = 1;
    for( int i = 0; i < n; i++ ){
        int x; cin >> x; x -= k;
        if( x >= 0 ) for( int j = 2*maxx - 1; j >= x; j-- ) dp[j] = sum( dp[j], dp[j - x] );
        else for( int j = 0; j - x < 2*maxx; j++ ) dp[j] = sum( dp[j], dp[j - x] );
    }

    cout << sum( dp[maxx], -1 ) << "\n";
}
