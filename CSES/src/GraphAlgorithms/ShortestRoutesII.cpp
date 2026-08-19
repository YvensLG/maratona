#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef vector<vector<int>> vii;
const int inf = LLONG_MAX;

void floydWarshall(vector<vector<int>> &dist) {
    int n = dist.size();
    for(int k = 0; k < n; k++)
    for(int j = 0; j < n; j++)
    for(int i = 0; i < n; i++)
    if(dist[i][k] != inf && dist[k][j] != inf) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    vii dist(n, vector<int>(n, inf));

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        dist[a-1][b-1] = min(dist[a-1][b-1], c);
        dist[b-1][a-1] = min(dist[b-1][a-1], c);
    }
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    
    floydWarshall(dist);

    while(q--) {
        int a, b; cin >> a >> b;
        cout << (dist[a-1][b-1] == inf ? -1 : dist[a-1][b-1]) << '\n';
    }

    return 0;
}
