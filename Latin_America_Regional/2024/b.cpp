#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep( i, a, b ) for( int i = a; i < (b); i++ )

using ll = long long; 
using pii = pair<int, int>; 
using vi = vector<int>; 

const int MAX = 2e5+10;

vi G[MAX];
int vis[MAX], pai[MAX], dist[MAX];
pii best_be = {0, 0};
int n, m;

void dfs(int v) {
    vis[v] = 1;
    for(auto x : G[v]) {
        if(x == pai[v]) continue;
        if(vis[x] == 0) {
            dist[x] = dist[v] + 1;
            pai[x] = v;
            dfs(x);
        }
        else {
            if(min(dist[x], dist[v]) >= min(dist[best_be.first], dist[best_be.second])) {
                best_be = {x, v};
            }
        }
    }
    vis[v] = 2;
}

void solve(){
    cin >> n >> m;
    vector<pair<pii, int>> edges;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        edges.push_back({{min(u, v), max(u, v)}, i});
    }
    sort(all(edges));

    dfs(1);

    auto [u, v] = best_be;
    if(dist[v] < dist[u]) swap(u, v);

    vector<int> ans = {u, v};
    while(pai[v] != u) {
        ans.push_back(pai[v]);
        v = pai[v];
    }
    ans.push_back(u);

    cout << sz(ans) - 1 << '\n';
    for(int i = 0; i < sz(ans) - 1; i++) {
        auto it = lower_bound(all(edges), make_pair(make_pair(min(ans[i], ans[i + 1]), max(ans[i], ans[i + 1])), 0));
        cout << it -> second << ' ';
    }
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}