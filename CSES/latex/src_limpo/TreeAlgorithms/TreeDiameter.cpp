const int MAX = 2e5 + 5;
const int LOG = 19;
const int INF = 1e9;

int dist[MAX];
vi adj[MAX];

void dfs(int s, int p) {
    dist[s] = dist[p] + 1;
    for(auto x : adj[s]) {
        if(x == p) continue;
        dfs(x, s);
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist[0] = -1;
    dfs(1, 0);
    int maxi = -1, at = 0;
    for(int i = 1; i <= n; i++) {
        if(maxi < dist[i]) {
            at = i;
            maxi = dist[i];
        }
    }

    dfs(at, 0);
    maxi = -1;
    for(int i = 1; i <= n; i++) {
        if(maxi < dist[i]) maxi = dist[i];
    }

    cout << maxi << '\n';
}
