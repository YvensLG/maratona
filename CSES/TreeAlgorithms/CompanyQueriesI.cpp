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
vi adj[MAX];

int up[MAX][LOG];
int depth[MAX];

void dfs(int s, int p) {
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

void solve(){
    cin >> n >> q;

    for(int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1, 0);

    for(int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        int at = 0;
        while(k) {
            if(k % 2 == 1) {
                x = up[x][at];    
            }
            k >>= 1;
            at++;
        }
        if(x == 0) cout << -1 << '\n';
        else cout << x << '\n';
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}