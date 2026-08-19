#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
const int INF = 1000000000000000000;
vector<vector<pair<int, int>>> adj;
 
void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
 
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
 
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
 
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    adj.resize(n+1);
 
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    vector<int> d, p;
    dijkstra(1, d, p);
 
    for(int i = 1; i <= n; i++){
        cout << d[i] << ' ';
    }
    cout << '\n';
 
    return 0;
}
