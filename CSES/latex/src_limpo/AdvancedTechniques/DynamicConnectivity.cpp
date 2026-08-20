using pii = pair<int, int>;

const int maxn = 1e5 + 10;

struct UnionFind{
    int *p, *sz, *stk;
    int comp, top;

    UnionFind( int n = 1, int q = 1 ) : p(new int[n]), sz(new int[n]), stk(new int[q]), comp(n), top(-1) {
        fill( sz, sz + n, 1 );
        iota( p, p + n, 0 );
    }

    int find( int u ){
        while( u != p[u] ) u = p[u];
        return u;
    }

    void join( int u, int v ){
        u = find(u); v = find(v);
        if( u == v ){ stk[++top] = -1; return; }
        if( sz[u] < sz[v] ) swap( u, v );

        p[v] = u;
        sz[u] += sz[v];

        stk[++top] = v;
        comp--;
    }

    void rollback(){
        if( top < 0 ) return;
        int v = stk[top--]; if( v == -1 ) return;

        sz[p[v]] -= sz[v];
        p[v] = v;
        comp++;
    }
};

struct DynamicConnectivity{
    vector<pii> *v;
    UnionFind dsu;

    int k;
    DynamicConnectivity( int n, int m, int k ) : dsu(UnionFind(n, m + k)), v(new vector<pii>[4*(k + 1)]), k(k) {}

    void update( int node, int ti, int tf, int qi, int qf, pii p ){
        if( qi > tf || ti > qf ) return;
        if( qi <= ti && tf <= qf ){
            v[node].push_back(p);
            return;
        }
        int l = 2*node, r = 2*node + 1, tm = (ti + tf)/2;
        update( l, ti, tm, qi, qf, p );
        update( r, tm + 1, tf, qi, qf, p );
    }

    void update( int l, int r, pii p ){
        update( 1, 0, k, l, r, p );
    }

    void solve( int node, int ti, int tf ){
        for( auto &[u, v] : v[node] ) dsu.join( u, v );
        if( ti == tf ) cout << dsu.comp << " ";
        else{
            int l = 2*node, r = 2*node + 1, tm = (ti + tf)/2;
            solve( l, ti, tm ); solve( r, tm + 1, tf );
        }
        for( auto &[u, v] : v[node] ) dsu.rollback();
    }

    void solve(){
        solve( 1, 0, k );
    }
};

void solve(){
    int n, m, k; cin >> n >> m >> k;

    DynamicConnectivity DC( n, m, k );

    map<pii, int> mp;
    for( int i = 0; i < m; i++ ){
        int u, v; cin >> u >> v; u--; v--;
        if( u > v ) swap( u, v );
        mp[pii(u, v)] = 0;
    }

    for( int i = 1; i <= k; i++ ){
        int t, u, v; cin >> t >> u >> v; u--; v--;
        if( u > v ) swap( u, v );
        if( t == 1 ) mp[pii(u, v)] = i;
        else{
            DC.update( mp[pii(u, v)], i - 1, pii(u, v) );
            mp.erase(pii(u, v));
        }
    }

    for( auto &[par, id] : mp ) DC.update( id, k, par );

    DC.solve();
    cout << "\n";
}
