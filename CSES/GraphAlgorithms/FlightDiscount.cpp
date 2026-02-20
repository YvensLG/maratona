#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
const int INF = 1000000000000000000;
vector<vector<pair<int, int>>> adj;
 
void dijkstra(int s, vector<int> & d) {
    int n = adj.size();
    d.assign(2 * n, INF);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        if(v >= n) {
            for (auto edge : adj[v - n]) {
                int to = edge.first + n;
                int len = edge.second;
    
                if (d[v] + len < d[to]) {
                    q.erase({d[to], to});
                    d[to] = d[v] + len;
                    q.insert({d[to], to});
                }
            }    
        }
        else {
            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;
     
                if (d[v] + len < d[to]) {
                    q.erase({d[to], to});
                    d[to] = d[v] + len;
                    q.insert({d[to], to});
                }
                to = to + n;
                len /= 2;
                if (d[v] + len < d[to]) {
                    q.erase({d[to], to});
                    d[to] = d[v] + len;
                    q.insert({d[to], to});
                }
            }
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    adj.resize(n);
 
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }
 
    vector<int> d;
    dijkstra(0, d);
 
    cout << d[2 * n - 1] << '\n';
 
    return 0;
}
