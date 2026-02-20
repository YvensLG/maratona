#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int INF = 1000000000000000000;

vector<vector<int>> adj;
vector<int> vis, pai;
vector<int> ans;
int cnt = 0;

bool dfs(int v) {
    vis[v] = 1;
    for(auto x : adj[v]) {        
        if(vis[x] == 1) {
            ans.push_back(x);
            int at = v;
            while(at != x) {
                ans.push_back(at);
                at = pai[at];
            }
            ans.push_back(x);

            return 1;
        }
        else if (vis[x] == 0) {
            pai[x] = v;
            if(dfs(x)) return 1;
        }
    }
    vis[v] = 2;
    return 0;
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    adj.resize(n); vis.resize(n); pai.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) {
            if(dfs(i)) {
                reverse(ans.begin(), ans.end());
                cout << ans.size() << '\n';
                for(auto x : ans) cout << x + 1 << ' ';
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
 
    return 0;
}
