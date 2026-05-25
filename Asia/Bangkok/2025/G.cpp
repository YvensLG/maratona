#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 2e5 + 10; 

vector<pair<int, ll>> adj[maxn]; 

struct Point{
    ll x, y, z; Point( ll x = 0, ll y = 0, ll z = 0 ) : x(x), y(y), z(z) {}
};

Point p[maxn];

ll val[maxn][2][2][2];

ll x[] = { -1LL, 1LL };

ll dfs( int u, int pai, ll depth ){

    ll ans = 0; 

    for( int i = 0; i < 2; i++ )
    for( int j = 0; j < 2; j++ )
    for( int k = 0; k < 2; k++ )
        val[u][i][j][k] = depth + x[i]*p[u].x + x[j]*p[u].y + x[k]*p[u].z; 

    for( auto [v, w] : adj[u] ) if( v != pai ){
        ans = max( ans, dfs( v, u, depth + w ) );

        for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 2; j++ )
        for( int k = 0; k < 2; k++ )
            ans = max( ans, val[u][1 - i][1 - j][1 - k] + val[v][i][j][k] - 2*depth ); 
        
        for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 2; j++ )
        for( int k = 0; k < 2; k++ ) 
            val[u][i][j][k] = max( val[u][i][j][k], val[v][i][j][k] ); 
    }

    return ans; 
}   

void solve(){
    int n; cin >> n; 
    for( int i = 1; i < n; i++ ){
        int a, b, c; cin >> a >> b >> c; 
        a--; b--; 
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    for( int i = 0; i < n; i++ ) cin >> p[i].x >> p[i].y >> p[i].z; 

    cout << dfs( 0, 0, 0 ) << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    // int t; cin >> t; 
    // while( t-- ) 
        solve(); 
    return 0;
}
