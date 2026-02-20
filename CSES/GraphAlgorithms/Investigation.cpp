#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int INF = 1000000000000000000;
const int M = 1e9 + 7;
 
struct Node {
    int mn = INF;
    int cnt = 1;
    int mnsz = 1;
    int mxsz = 1;
};
 
vector<vector<pair<int, int>>> adj;
vector<Node> d;
 
void dijkstra(int s) {
    int n = adj.size();
    
    d.resize(n);
    d[s] = {0, 1, 1, 1};
 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
 
    while (!q.empty()) {
        int len = q.top().first;
        int v = q.top().second;
        q.pop();

        if(len > d[v].mn) continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            int new_dist = d[v].mn + len;
 
            if(d[to].mn == new_dist) {
                d[to].cnt = (d[to].cnt + d[v].cnt) % M;
                d[to].mnsz = min(d[to].mnsz, d[v].mnsz + 1);
                d[to].mxsz = max(d[to].mxsz, d[v].mxsz + 1);
            }
            else if(d[to].mn > new_dist) {
                d[to].mn = new_dist;
                d[to].cnt = d[v].cnt;
                d[to].mnsz = d[v].mnsz + 1;
                d[to].mxsz = d[v].mxsz + 1;
                q.push({new_dist, to});
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
        a--; b--;
        adj[a].push_back({b, c});
    }
 
    dijkstra(0);
 
    cout << d[n-1].mn << ' ' << d[n-1].cnt << ' ' << d[n-1].mnsz - 1 << ' ' << d[n-1].mxsz - 1 << '\n';
 
    return 0;
}