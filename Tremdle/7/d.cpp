#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

// achar o maior grafo de modo que há no max um ciclo por componente
// ou seja, MST + 1 aresta p cada comp

const int MAX = 200'005;
vector<tuple<int, int, int>> edg; // {peso,[x,y]}

// DSU em O(a(n))
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
dsu component(MAX);
vector<int> usado(MAX, 0); 

// Kruskal 2.0 
pair<int, vector<tuple<int, int, int>>> kruskal(int n) {
    sort(edg.begin(), edg.end());
    
    //Maximum
    reverse(edg.begin(), edg.end());

	int cost = 0;
	vector<tuple<int, int, int>> mst;
	for (auto [w,x,y] : edg){
        if (usado[component.find(x)] + usado[component.find(y)] <= 1) {
            mst.emplace_back(w, x, y);
            cost += w;
            int ant = usado[component.find(x)] + usado[component.find(y)];
            if(component.find(x) == component.find(y))
                usado[component.find(x)] = 1;
            else {
                component.unite(x,y);
                usado[component.find(x)] = ant;
            }
        }
    }
    return {cost, mst};
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, w; cin >> a >> b >> w;
        edg.push_back({w, a, b});
    }

    pair<int, vector<tuple<int, int, int>>> MST = kruskal(n+1);

    int tot = MST.first;

    cout << tot << '\n';
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();
}