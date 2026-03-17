#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int MAX = 2e5 + 5, LOG = 30;
 
int n, q;
int t[MAX];

vector<int> g[MAX];
vector<int> gi[MAX];
int vis[MAX];
stack<int> S;
int comp[MAX];
vector<int> comp_elem[MAX];
vector<int> comp_graph[MAX];

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
	for (int i = 0; i < (int) gi[k].size(); i++)
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
}

void kosaraju() {
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	for (int i = 0; i < n; i++) vis[i] = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]) scc(u, u);
	}
}

// int tin[MAX], tout[MAX];
// void dfs_time(int s) {
//     tin[s] = ++timer;

//     for (int u : gi[v]) {
//         if (u != p)
//             dfs(u, v);
//     }

//     tout[v] = ++timer;
// }

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
 
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        g[i].push_back(a - 1);
        gi[a - 1].push_back(i);
    }
    
    kosaraju();


	
    for(int i = 0; i < n; i++) {
		comp_elem[comp[i]].push_back(i);
	}
	for(int i = 0; i < n; i++)
		for(auto x : comp_elem[i]) 
			for(auto u : gi[x])
				if(comp[u] != i) comp_graph[i].push_back(u);

	vector<int> root;

	for(int i = 0; i < n; i++) {
		if(comp_elem[i].size() > 1) root.push_back(i);
		else if(comp_elem[i].size() == 1 && g[comp_elem[i][0]][0] == comp_elem[i][0]) root.push_back(i);
	}

	for(auto x : root) cout << x << '\n';
 
 
    return 0;
}