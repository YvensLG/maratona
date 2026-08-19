const int MAX = 1e5 + 1;

vector<pii> G[MAX];
vector<pair<pii, bool>> edg;
bool vis[MAX];

int deg = 0;

void dfs(int at, int pai) {
    vis[at] = 1;
    for(auto [x, e] : G[at]) {
        if(!vis[x]) {
            dfs(x, at);
        }
    }
    deg = 0;
    int e_pai = -1;
    for(auto [x, e] : G[at]) {
        if(!edg[e].second && x != pai) {
            edg[e].second = 1;
            edg[e].first = {at, x};
            deg++;
        }
        else if(edg[e].second) {
            deg += (edg[e].first.first == at);
        }
        else {
            e_pai = e;
        }
    }

    if(e_pai == -1) return;

    if(deg % 2 == 0) edg[e_pai].first = {pai, at};
    else edg[e_pai].first = {at, pai};

    edg[e_pai].second = 1;
}

void solve(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        edg.push_back({{a, b}, 0});
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i, 0);
        if(deg % 2) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    for(auto [par, def] : edg) {
        cout << par.first << ' ' << par.second << '\n';
    }

}
