#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<pii>> graph;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

int n, m;
graph G;
vector<int> d;

void dijkstra(int v) {
	for (int i = 0; i < G.size(); i++) d[i] = LINF;
	d[v] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0, v);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w] : G[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.emplace(-d[idx], idx);
		}
	}
}
void add_edge(int a, int b, char c){
    if(a < 0 || b < 0) return;
    if(c == '#') G[a].pb({b, 0});
    else G[a].pb({b, 1});
}

int to_vertex(int i, int j){
    return (i - 1) * m + j - 1;
}

void solve(){
	cin >> n >> m;
    G.resize(n * m + 2);
    int ini = n * m, fim = n * m + 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c;
            if(i == 1) add_edge(ini, to_vertex(i, j), '#');
            if(i == n) add_edge(to_vertex(i, j), fim, c);
            add_edge(to_vertex(i, j), to_vertex(i, j - 1), c);
            add_edge(to_vertex(i, j), to_vertex(i - 1, j), c);
            if(j < m){
                add_edge(to_vertex(i, j), to_vertex(i, j + 1), c);
            }
            if(i < n){
                add_edge(to_vertex(i, j), to_vertex(i + 1, j), c);
            }

            if(i % 2 == 1){
                add_edge(to_vertex(i, j), to_vertex(i - 1, j - 1), c);
                if(i < n)
                add_edge(to_vertex(i, j), to_vertex(i + 1, j - 1), c);
            }
            else if(j < m){
                add_edge(to_vertex(i, j), to_vertex(i - 1, j + 1), c);
                if(i < n)
                add_edge(to_vertex(i, j), to_vertex(i + 1, j + 1), c);
                
            }
        }
    }

    d.resize(G.size());

    dijkstra(ini);

    // for(int i = 0; i < 5; i++){
    //     for(int j = 0 ; j < 5; j++){
    //         cout << d[i * m + j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << d[18] << '\n';
    // for(auto x : G[18]){
    //     cout << x.first << ' ' << x.second << '\n';
    // }

    cout << d[fim] << '\n';

}

signed main() {
    _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}