#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int INF = 1000000000000000000;
const int MAX = 100010;
 
vector<int> g[MAX];
 
vector<int> topo_sort(int n) {
	vector<int> ret(n,-1), vis(n,0);
	
	int pos = n-1, dag = 1;
	function<void(int)> dfs = [&](int v) {
		vis[v] = 1;
		for (auto u : g[v]) {
			if (vis[u] == 1) dag = 0;
			else if (!vis[u]) dfs(u);
		}
		ret[pos--] = v, vis[v] = 2;
	};
 
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
 
	if (!dag) ret.clear();	
	return ret;
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
 
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
 
    vector<int> ans = topo_sort(n);
 
    if(ans.size() == 0)
        cout << "IMPOSSIBLE\n";
    else {
        for(auto x : ans) cout << x + 1 << ' ';
        cout << '\n';
    }
 
    return 0;
}