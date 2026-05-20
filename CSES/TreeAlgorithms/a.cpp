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
const int INF = 1e9;

int n, q;
bool coin[MAX];
int tam = 0;
vi adj[MAX];

int up[MAX][LOG];
int dist_to_coin[MAX][LOG];
int depth[MAX];

void calc_dist_to_coin() {
    queue<int> q;

    for(int i = 0; i < LOG; i++) dist_to_coin[0][i] = INF;

    for(int i = 1; i <= n; i++) {
        dist_to_coin[i][0] = INF;
        if(coin[i]) {
            q.push(i);
            dist_to_coin[i][0] = 0;
        }
    }

    while(!q.empty()) {
        int at = q.front(); q.pop();
        for(auto x : adj[at]) {
            if(dist_to_coin[x][0] == INF) {
                dist_to_coin[x][0] = dist_to_coin[at][0] + 1;
                q.push(x);
            }
        }
    }
}

void dfs(int s, int p) {
    up[s][0] = p;
    depth[s] = depth[p] + 1;
    for(int i = 1; i < LOG; i++) {
        up[s][i] = up[up[s][i-1]][i-1];
        dist_to_coin[s][i] = min(dist_to_coin[s][i - 1], dist_to_coin[up[s][i-1]][i-1]);
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

int min_dist(int a, int b) {
    int ans = INF;
    if(depth[a] < depth[b]) swap(a, b);
    
    int diff = depth[a] - depth[b];
    for(int i = 0; i < LOG; i++) {
        if((diff >> i) & 1) {
            ans = min(ans, dist_to_coin[a][i]);
            a = up[a][i];
        }
    }
    
    if(a == b) {
        return min(ans, dist_to_coin[a][0]);
    }
    
    for(int i = LOG - 1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            ans = min(ans, dist_to_coin[a][i]);
            ans = min(ans, dist_to_coin[b][i]);
            a = up[a][i];
            b = up[b][i];
        }
    }
    
    ans = min({ans, dist_to_coin[a][0], dist_to_coin[b][0], dist_to_coin[up[a][0]][0]});
    
    return ans;
}

void solve(){
    cin >> n >> q;
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

    calc_dist_to_coin();
    dfs(root, 0);

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        int ans = dist(a, b);
        ans += 2 * min_dist(a, b);
        cout << ans << '\n';
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}