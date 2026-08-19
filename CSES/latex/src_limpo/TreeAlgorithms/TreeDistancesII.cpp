int n;
graph G;
vi sz, down, up;
int ans = 0;

// queremos contar pra cima e pra baixo
void dfs_down(int s, int p){
    sz[s] = 1;
    down[s] = 0;
    for(auto x : G[s]){
        if(x == p) continue;
        dfs_down(x, s);
        down[s] += down[x];
        sz[s] += sz[x];
    }
    down[s] += sz[s] - 1;
}

void dfs_up(int s, int p){
    if(p != -1)
        up[s] = up[p] + (down[p] - down[s] - sz[s]) + (n - sz[s]);

    for(auto x : G[s]){
        if(x == p) continue;
        dfs_up(x, s);
    }
}

void solve(){
    cin >> n;

    G.resize(n + 1);
    sz.resize(n + 1);
    down.resize(n + 1);
    up.resize(n + 1);

    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].pb(b); G[b].pb(a);
    }

    dfs_down(0, -1);
    dfs_up(0, -1);

    for(int i = 0; i < n; i++) {
        cout << up[i] + down[i] << ' ';
    }
    cout << '\n';
}
