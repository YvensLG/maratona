using vi = vector<int>;
using trio = tuple<int, int, int>;
using ll = long long;
using pii = pair<int, int>;

struct BinaryLifting{
    vector<vector<pii>> adj;
    vector<vi> pai, maxi;
    vi tin, tout;

    int t = -1;

    BinaryLifting( vector<vector<pii>> adj ) : adj(adj){
        int n = sz(adj);
        pai = maxi = vector<vi>(n, vi(__lg(n) + 1));
        tin = tout = vi(n);

        dfs(0, 0, 0);
    }

    void dfs( int u, int p, int pw ){
        pai[u][0] = p;
        maxi[u][0] = pw;
        for( int i = 1; i < sz(maxi[u]); i++ ){
            pai[u][i] = pai[pai[u][i - 1]][i - 1];
            maxi[u][i] = max( maxi[u][i - 1], maxi[pai[u][i - 1]][i - 1] );
        }

        tin[u] = ++t;
        for( auto [v, w] : adj[u] ) if( v != p ) dfs( v, u, w );
        tout[u] = t;
    }

    bool upper( int u, int v ){
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int query( int u, int v ){
        int ans = -1;
        for( int i = sz(pai[0]) - 1; i >= 0; i-- ){
            if( !upper( pai[u][i], v ) ){
                ans = max( ans, maxi[u][i] );
                u = pai[u][i];
            }
            if( !upper( pai[v][i], u ) ){
                ans = max( ans, maxi[v][i] );
                v = pai[v][i];
            }
        }

        if( !upper( u, v ) ) ans = max( ans, maxi[u][0] );
        if( !upper( v, u ) ) ans = max( ans, maxi[v][0] );

        return ans;
    }

    int lca( int u, int v ){
        if( upper( u, v ) ) return u;
        if( upper( v, u ) ) return v;

        for( int i = sz(pai[0]); i >= 0; i-- ) if( !upper( pai[u][i], v ) ) u = pai[u][i];
        return pai[u][0];
    }
};

struct DSU{
    vi pai;
    DSU( int n ) : pai(n){
        iota(all(pai), 0);
    }

    int find( int u ){
        return (( u == pai[u] ) ? u : pai[u] = find(pai[u]));
    }

    void join( int u, int v ){
        pai[find(u)] = find(v);
    }
};

void solve(){
    int n, m; cin >> n >> m;

    vector<trio> edges(m);
    for( auto &[w, u, v] : edges ){
        cin >> u >> v >> w;
        u--; v--;
    }

    vector<trio> sorted = edges;
    sort(all(sorted));

    DSU dsu(n);
    vector<vector<pii>> adj(n);

    ll cost = 0;
    for( auto [w, u, v] : sorted ) if( dsu.find(u) != dsu.find(v) ){
        cost += w;
        dsu.join(u, v);

        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    BinaryLifting tree(adj);
    for( auto [w, u, v] : edges ) cout << cost + w - tree.query(u, v) << '\n';
}
