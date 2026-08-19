const int MAX = 2e5 + 5;
const int LOG = 19;
const int INF = 1e9;

int n, q;
vi adj[MAX];

int up[MAX][LOG];
int depth[MAX];

void dfs(int s, int p) {
    up[s][0] = p;
    depth[s] = depth[p] + 1;
    for(int i = 1; i < LOG; i++) {
        up[s][i] = up[up[s][i-1]][i-1];
    }

    for(auto x : adj[s]) {
        if(x == p) continue;
        dfs(x, s);
    }
}

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];
    for(int i = 0; i < LOG; i++) {
        if((diff >> i) & 1) a = up[a][i];
    }

    if(a == b) return a;

    for(int i = LOG - 1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void solve(){
    cin >> n >> q;

    for(int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1, 0);

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << get_lca(a, b) << '\n';
    }
}
