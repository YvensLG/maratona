using vi = vector<int>;

struct CentroidTree{
    vector<vi> adj, lvl;
    vi sub, opt, cpai, clvl;

    CentroidTree( vector<vi> adj ){
        int n = sz(adj); this->adj = adj;
        sub = opt = cpai = clvl = vi(n, 0);
        lvl = vector<vi>(__lg(n) + 1, vi(n));

        build( 0, -1, 0 );
    }

    void dfs( int u, int p, int d, int clvl ){
        lvl[clvl][u] = d;
        sub[u] = 1;
        for( int v : adj[u] ) if( v != p && !opt[v] ) { dfs( v, u, d + 1, clvl ); sub[u] += sub[v]; }
    }

    int find( int u, int p, int t ){
        for( int v : adj[u] ) if( v != p && !opt[v] && sub[v] > t/2 ) return find( v, u, t );
        return u;
    }

    void build( int u, int p, int d  ){
        dfs(u, u, 0, d);
        int c = find( u, u, sub[u] );
        dfs(c, c, 0, d);

        cpai[c] = p; clvl[c] = d; opt[c] = sz(adj);
        for( int v : adj[c] ) if( !opt[v] ) build( v, c, d + 1 );
    }

    void enable( int u ){
        for( int c = u; c != -1; c = cpai[c] ) opt[c] = min( opt[c], lvl[clvl[c]][u] );
    }

    int closest( int u ){
        int ans = opt[u];
        for( int c = u; c != -1; c = cpai[c] ) ans = min( ans, opt[c] + lvl[clvl[c]][u] );
        return ans;
    }
};

void solve(){
    int n, k; cin >> n >> k;
    vector<vi> adj(n);
    for( int i = 1; i < n; i++ ){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    CentroidTree tree(adj);

    vi ordem(n);
    iota( all(ordem), 0 );
    sort( all(ordem), [&]( int u, int v ){
        return tree.lvl[0][u] > tree.lvl[0][v];
    });

    vi ans;
    for( int u : ordem ) if( tree.closest(u) >= k ){
        tree.enable(u);
        ans.push_back(u);
    }

    cout << sz(ans) << '\n';
    for( int x : ans ) cout << x + 1 << " "; cout << '\n';
}
