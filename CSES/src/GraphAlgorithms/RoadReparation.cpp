#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define F first
#define S second

#define int long long
 
using namespace std;
 
int n, m;
vector<tuple<int, int, int>> edg; // {peso,[x,y]}

struct dsu {
	vector<int> id, sz;

	dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

pair<int, vector<tuple<int, int, int>>> kruskal(int n) {
	dsu D(n);
	sort(edg.begin(), edg.end());
	
	int cost = 0;
	vector<tuple<int, int, int>> mst;
	for (auto [w,x,y] : edg) if (D.find(x) != D.find(y)) {
		mst.emplace_back(w, x, y);
		cost += w;
		D.unite(x,y);
	}

    int root = D.find(0);
    for(int i = 0; i < n; i++)
        if (D.find(i) != root) return{-1, {}};

	return {cost, mst};
}

void solve(){
    cin >> n >> m;    
    
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edg.push_back({c, a - 1, b - 1});
    }

    auto ans = kruskal(n);
    if(ans.first == -1) cout << "IMPOSSIBLE\n";
    else cout << ans.first << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}