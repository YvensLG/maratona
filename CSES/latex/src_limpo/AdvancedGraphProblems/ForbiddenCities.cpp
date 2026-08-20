using vi = vector<int>;

const int maxn = 1e5;
const int logn = 18;

int pai[maxn][logn], tin[maxn], tout[maxn], low[maxn];
int dfs_time;

vi adj[maxn];

void dfs( int u, int p ){

    pai[u][0] = p;
    for( int i = 1; i < logn; i++ ) pai[u][i] = pai[pai[u][i - 1]][i - 1];

    tin[u] = low[u] = ++dfs_time;

    int cnt = 0;
    for( int v : adj[u] ) if( v != p ){
        if( !tin[v] ){
            cnt++;

            dfs( v, u );
            low[u] = min( low[u], low[v] );
        }
        else low[u] = min( low[u], tin[v] );
    }
    tout[u] = dfs_time;
}

bool upper( int u, int v ){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca( int u, int v ){
    if( upper( u, v ) ) return u;
    if( upper( v, u ) ) return v;

    for( int i = logn - 1; i >= 0; i-- ) if( !upper( pai[u][i], v ) ) u = pai[u][i];
    return pai[u][0];
}

int lift( int u, int v ){
    assert(upper( v, u ));
    for( int i = logn - 1; i >= 0; i-- ) if( !upper( pai[u][i], v ) ) u = pai[u][i];
    return u;
}

bool check_path( int a, int b, int c ){

    if( a == c || b == c ) return true;
    if( !upper( lca(a, b), c ) ) return false;

    if( upper( c, a ) && tin[c] <= low[lift( a, c )] ) return true;
    if( upper( c, b ) && tin[c] <= low[lift( b, c )] ) return true;
    return false;
}

void solve(){
    int n, m, q; cin >> n >> m >> q;
    for( int i = 0; i < m; i++ ){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs( 0, 0 );

    while( q-- ){
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c--;

        if( !check_path( a, b, c ) ) cout << "YES\n";
        else cout << "NO\n";
    }
}
