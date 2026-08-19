const int maxn = 1e3+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;
int n, m;
vector<int> ans;
graph G;
vi check;

void dfs(int i){
    check[i] = 1;
    for(auto x : G[i]){
        if(check[x] == 0) dfs(x);
    }
}

void solve(){
    cin >> n >> m;
    G.resize(n + 1);
    check.resize(n + 1);

    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        G[a].pb(b); G[b].pb(a);
    }

    for(int i = 1; i <= n; i++){
        if(check[i] == 0){
            dfs(i);
            ans.pb(i);
        }
    }

    cout << ans.size() - 1 << '\n';
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i - 1] << ' ' << ans[i] << '\n';
    }
}
