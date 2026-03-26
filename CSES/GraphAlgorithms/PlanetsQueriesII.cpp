#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int MAX = 2e5 + 5, LOG = 30;
 
int n, q;
vector<int> g[MAX], gi[MAX], comp_elem[MAX], comp_graph[MAX], comp_graph_inv[MAX];
// root, dist_root, tin, tout 
tuple<int, int, int, int> dist[MAX];
stack<int> S;
int vis[MAX], comp[MAX], comp_place[MAX];

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

int t = 0;
void dfs_calc(int s, int p) {
	dist[s] = {get<0>(dist[p]), get<1>(dist[p]) + 1, t, -1}; t++;
	if(get<1>(dist[s]) == 1) get<0>(dist[s]) = g[s][0];

	for(auto x : comp_graph_inv[s]) dfs_calc(x, s);

	get<3>(dist[s]) = t; t++;
}

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
        if (comp[i] == i) {
            int at = i, pos = 0;
            do {
                comp_elem[i].push_back(at);
                comp_place[at] = pos++;
                at = g[at][0];
            } while (at != i && comp[at] == i);
        }
    }

	for(int i = 0; i < n; i++)
		for(auto x : comp_elem[i]) 
			for(auto u : g[x])
				if(comp[u] != i) {
					comp_graph[i].push_back(comp[u]);
					comp_graph_inv[comp[u]].push_back(i);
				}

	for(int i = 0; i < n; i++) {
		if((g[i].size() == 1 && g[i][0] == i) || (comp_elem[comp[i]].size() > 1 && comp[i] == i)) {
			dist[i] = {i, -1, 0, 0};	
			dfs_calc(i, i);
		}
	}

	for(int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; a--; b--;
		auto da = dist[a], db = dist[b];
		if(comp[a] == comp[b]) {
			int ans = comp_place[b] - comp_place[a];
			if(ans < 0) ans += comp_elem[comp[a]].size();
			cout << ans << '\n';
		}
		else if(comp[get<0>(da)] == comp[b]) {
			int ans = comp_place[b] - comp_place[get<0>(da)];
			if(ans < 0) ans += comp_elem[comp[get<0>(da)]].size();
			ans += get<1>(da);
			cout << ans << '\n';
		}
		else if(get<0>(da) == get<0>(db) && get<2>(da) > get<2>(db) && get<3>(da) < get<3>(db)) {
			cout << get<1>(da) - get<1>(db) << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
	
	return 0;
}
