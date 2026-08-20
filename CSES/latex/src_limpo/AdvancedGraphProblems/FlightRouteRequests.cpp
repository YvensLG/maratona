using vi = vector<int>;

const int maxn = 1e5;
vi adj[2][maxn];
int in[maxn];
bool marc[maxn];

void dfs( int u, vi &c ){
    marc[u] = true;
    c.push_back(u);
    for( int t = 0; t < 2; t++ )
    for( int v : adj[t][u] ) if( !marc[v] ) dfs(v, c);
}

bool check_cycle( int node ){
    vi c;
    dfs( node, c );

    queue<int> q;
    for( int u : c ) if( !in[u] ) q.push(u);

    for(;!q.empty(); q.pop() ){
        int u = q.front();
        for( int v : adj[0][u] ) if( --in[v] == 0 ) q.push(v);
    }

    for( int u : c ) if( in[u] ) return true;
    return false;
}

void solve(){
    int n, m; cin >> n >> m;
    while( m-- ){
        int u, v; cin >> u >> v; u--; v--;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
        in[v]++;
    }

    int ans = n;
    for( int i = 0; i < n; i++ ) if( !marc[i] && !check_cycle(i) ) ans--;
    cout << ans << endl;
}
