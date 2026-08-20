using vi = vector<int>;
using pii = pair<int, int>;

struct SCC{
    vector<vector<vi>> adj;
    vector<vi> adjc;
    vi scc, inc, outc;

    SCC( vector<vector<vi>> adj ) : adj(adj) {
        int n = sz(adj[0]);
        inc = outc = vi(n);
        adjc.resize(n);
        kosaraju();
    }

    void dfs( int u, int t, vi &o ){
        for( int v : adj[t][u] ) if( scc[v] == -1 ){
            scc[v] = scc[u]; dfs( v, t, o );
        }
        if(!t) o.push_back(u);
    }

    void kosaraju(){
        int n = sz(adj[0]);

        vi o;
        scc.assign(n, -1);
        FOR(i, 0, n) if( scc[i] == -1 ){
            scc[i] = i;
            dfs( i, 0, o );
        }

        scc.assign(n, -1);
        reverse(all(o));

        for( int i : o ) if( scc[i] == -1 ){
            scc[i] = i;
            dfs( i, 1, o );
        }

        reverse(all(o));
        FOR(i, 0, n) for( int v : adj[0][i] ) if( scc[i] != scc[v] ){
            inc[scc[v]]++;
            outc[scc[i]]++;
            adjc[scc[i]].push_back(scc[v]);
        }

        FOR(i, 0, n){
            sort(all(adjc[i]));
            adjc[i].erase(unique(all(adjc[i])), adjc[i].end());
        }
    }
};

const int maxn = 1e5 + 10;
bool marc[maxn];

int dfs( int u, SCC &scc ){
    marc[u] = true;
    if( scc.outc[u] == 0 ) return u;

    for( int v : scc.adjc[u] ) if( !marc[v] ){
        int x = dfs( v, scc );
        if( x != -1 ) return x;
    }
    return -1;
}

int calc( SCC &scc ){
    int n = sz(scc.scc);
    int in0 = 0, out0 = 0, tot = 0;

    FOR(i, 0, n) if( scc.scc[i] == i ){
        in0 += (scc.inc[i] == 0);
        out0 += (scc.outc[i] == 0);
        tot++;
    }

    return (tot == 1) ? 0 : max(in0, out0);
}

vector<pii> build_edges( SCC &scc ){
    int n = sz(scc.scc);

    vi in, out;
    vector<pii> edges;

    int ci = -1, cf = -1;

    FOR(i, 0, n) if( scc.scc[i] == i && scc.inc[i] == 0 ){
        int o = dfs( i, scc );
        if( o == -1 ){ in.push_back(i); continue; }
        if( ci == -1 ) tie(ci, cf) = pii( i, o );
        else{
            edges.push_back({ cf, i }); cf = o;
        }
    }

    edges.push_back({ cf, ci });

    FOR(i, 0, n) if( scc.scc[i] == i && scc.outc[i] == 0 && !marc[i] ) out.push_back(i);

    while( !in.empty() && !out.empty() ){
        int a = in.back(); in.pop_back();
        int b = out.back(); out.pop_back();

        edges.push_back({ b, a });
    }

    for( int u : out ) edges.push_back({ u, ci });
    for( int u : in ) edges.push_back({ ci, u });

    return edges;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<vi>> adj(2, vector<vi>(n));

    while( m-- ){
        int u, v; cin >> u >> v; u--; v--;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }

    SCC scc(adj);

    int ans = calc(scc);
    cout << ans << '\n';

    if( ans == 0 ) return;

    vector<pii> edges = build_edges(scc);
    for( auto [a, b] : edges ) cout << a + 1 << " " << b + 1 << '\n';
}
