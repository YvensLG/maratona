using ll = long long;

const int maxn = 40;
const int inf = 1e9 + 10;

int v[2][(1<<(maxn/2))];

void solve(){
    int n, x; cin >> n >> x;
    int n0 = n/2, n1 = n - n0;

    for( int i = 0; i < n0; i++ ){
        int t; cin >> t;
        for( int j = 0; j < (1<<i); j++ ) v[0][j + (1<<i)] = min( inf, v[0][j] + t );
    }
    sort( v[0], v[0] + (1<<n0) );

    for( int i = 0; i < n1; i++ ){
        int t; cin >> t;
        for( int j = 0; j < (1<<i); j++ ) v[1][j + (1<<i)] = min( inf, v[1][j] + t );
    }
    sort( v[1], v[1] + (1<<n1), greater<int>() );

    ll ans = 0;
    for( int i = 0, j = 0, k = 0; i < (1<<n1); i++ ){
        while( j < (1<<n0) && v[1][i] + v[0][j] < x ) j++;
        k = max( k, j );
        while( k < (1<<n0) && v[1][i] + v[0][k] <= x ) k++;

        ans += k - j;
    }

    cout << ans << '\n';
}
