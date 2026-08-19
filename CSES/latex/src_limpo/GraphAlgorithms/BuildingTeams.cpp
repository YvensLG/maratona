const int maxn = 1e3+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;
int n, m;
vector<int> ans;
graph G;
vi check;
bool flag = true;

void dfs(int i){
    for(auto x : G[i]){
        if(check[x] == 0){
            check[x] = 3 - check[i];
            dfs(x);
        }
        else if(check[x] == check[i]) flag = false;
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
            check[i] = 1;
            dfs(i);
        }
    }

    if(!flag){
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        cout << check[i] << ' ';
    }
    cout << '\n';
}
