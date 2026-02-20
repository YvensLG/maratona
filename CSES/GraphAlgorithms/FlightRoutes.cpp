#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
const int INF = 1000000000000000000;

vector<vector<pair<int, int>>> adj;
vector<priority_queue<int>> d;
 
void dijkstra(int s) {
    int n = adj.size();
    
    d.assign(n, priority_queue<int>());
    d[s].push(0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});

    while (!q.empty()) {
        int tot = q.top().first;
        int v = q.top().second;
        q.pop();

        if (d[v].size() == 10 && tot > d[v].top()) continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            int new_dist = tot + len;

            if (d[to].size() < 10) {
                d[to].push(new_dist);
                q.push({new_dist, to});
            }
            else if(d[to].top() > new_dist) {
                d[to].pop();
                d[to].push(new_dist);
                q.push({new_dist, to});
            }
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    adj.resize(n);
 
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
    }
    dijkstra(0);
 
    while(d[n - 1].size() > k) d[n - 1].pop();
    vector<int> ans;
    for(int i = 0; i < k; i++){
        ans.push_back(d[n - 1].top());
        d[n - 1].pop();
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
 
    return 0;
}
