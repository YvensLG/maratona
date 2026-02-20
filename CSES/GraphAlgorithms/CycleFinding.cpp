#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int MAX = 2505;
const int INF = 1000000000000000000;

struct Edge {
    int a, b, cost;
};

int n, m;
vector<int> g[MAX], gi[MAX];
vector<Edge> edges;
int vis[MAX];
stack<int> S;
int comp[MAX];

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

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        edges.push_back({a, b, c});
        if(a == b && c < 0) {
            cout << "YES\n" << a + 1 << ' ' << b + 1 << '\n';
            return;
        }
        g[a].push_back(b);
        gi[b].push_back(a);
    }

    kosaraju();

    int tot = 0;
    for(int i = 0; i < n; i++)
        tot = max(tot, comp[i]);

    vector<vector<int>> C(tot + 1);

    for(int i = 0; i < n; i++)
        C[comp[i]].push_back(i);

    vector<int> d(n, INF), p(n, -1);
    for(int i = 0; i <= tot; i++) {
        if(C[i].size() <= 1) continue;

        int v = C[i][0]; n = C[i].size();        
        d[v] = 0;
        
        int x;
        for (int i = 0; i < n; ++i) {
            x = -1;
            for (Edge e : edges) {
                if (comp[e.a] != comp[v] || comp[e.b] != comp[v]) continue;
                if (d[e.a] < INF)
                    if (d[e.b] > d[e.a] + e.cost) {
                        d[e.b] = max(-INF, d[e.a] + e.cost);
                        p[e.b] = e.a;
                        x = e.b;
                    }
            }
        }

        if(x != -1) {
            int y = x;
            for (int i = 0; i < n; ++i)
                y = p[y];
            
            vector<int> path;
            for (int cur = y;; cur = p[cur]) {
                path.push_back(cur);
                if (cur == y && path.size() > 1)
                break;
            }
            reverse(path.begin(), path.end());
            
            cout << "YES\n";
            for (int u : path)
               cout << u + 1 << ' ';
            return;
        }

    }

    cout << "NO\n";
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
