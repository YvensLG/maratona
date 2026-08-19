const int MAX = 2e5 + 5;
const int LOG = 19;
const int INF = 1e9;

int subtree[MAX];
vi adj[MAX];

void dfs(int s, int p) {
    subtree[s] = 1;
    for(auto x : adj[s]) {
        if(x == p) continue;
        dfs(x, s);
        subtree[s] += subtree[x];
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; i++) cout << subtree[i] - 1 << ' ';
    cout << '\n';
}
