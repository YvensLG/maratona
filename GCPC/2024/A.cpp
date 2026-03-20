#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;

    vector<vi> adj(n);
    vi vis(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    vi q(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int qi = 0, qe = 0;

        for (vis[i] = 1, q[qe++] = i; qi < qe; qi++) {
            int u = q[qi];

            for (int v: adj[u]) if (!vis[v]){
                vis[v] = 1;
                q[qe++] = v;
            }
        }

        ans = max(ans, qe);
    }

    cout << ans << "\n";
}