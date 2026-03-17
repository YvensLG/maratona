#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAX = 2e5 + 5;

int n;
vi G[MAX];
int d[MAX], par[MAX];
int df, c1, c2 = -1;

// queremos contar pra cima e pra baixo

void center(){
    int f;
    function<void(int)> dfs = [&] (int v) {
        if(d[v] > df) f = v, df = d[v];
        for (int u : G[v]) if (u != par[v]) 
            d[u] = d[v] + 1, par[u] = v, dfs(u);
    };

    f = df = par[0] = -1, d[0] = 0;
    dfs(0);

    int root = f;
    f = df = par[root] = -1, d[root] = 0;
    dfs(root);

    vector<int> c;
    while(f != -1) {
        if(d[f] == df / 2 or d[f] == (df + 1) / 2) c.push_back(f);
        f = par[f];
    }
    
    c1 = c[0];
    if(c.size() > 1) c2 = c[1];
    d[c1] = 0; par[c1] = -1;
    dfs(c1);
}

int check[MAX], ans[MAX];

void dfs(int s, int p) {
    if(s == c2) check[s] = 1;
    for(auto x : G[s]) {
        if(x == p) continue;
        if(check[s]) check[x] = 1;
        dfs(x, s);
    }

    if(check[s]) ans[s] = df / 2 + d[s];
    else ans[s] = (df + 1) / 2 + d[s];
}

void solve(){
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].pb(b); G[b].pb(a);
    }
    center();
    dfs(c1, -1);

    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}
