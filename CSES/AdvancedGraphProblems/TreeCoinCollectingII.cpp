#include <bits/stdc++.h>
#define pb push_back
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAX = 2e5 + 5;
const int LOG = 19;

bool coin[MAX];
int pai[MAX];
int subtree[MAX];
int tam = 0;
vi adj[MAX];

int up[MAX][LOG];
int depth[MAX];

int calc_subtree(int s, int p) {
    subtree[s] = coin[s];

    for(auto x : adj[s]) {
        if(x == p) continue;
        subtree[s] += calc_subtree(x, s);
    }

    if(subtree[s]) tam++;
    return subtree[s];
}

void dfs(int s, int p) {
    if(subtree[s]) pai[s] = s;
    else pai[s] = pai[p];

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

int dist(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
}

void solve(){
    int n, q; cin >> n >> q;
    int root = 0;
    for(int i = 1; i <= n; i++) {
        cin >> coin[i];
        if(coin[i] == 1) root = i;
    }

    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calc_subtree(root, 0);
    dfs(root, 0);

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        int ans = 2 * (tam - 1);
        ans += dist(a, pai[a]);
        ans += dist(b, pai[b]);
        ans -= dist(pai[a], pai[b]);
        cout << ans << '\n';
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}