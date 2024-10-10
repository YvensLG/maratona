#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 2000000000
#define LINF 4000000000000000000 
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

 
vector<ll> dijkstra(int v, vector<vector<pair<int, int>>> g, int n) {
	vector<ll> d(n + 1); 
	for (int i = 0; i <= n; i++) d[i] = LINF;
	d[v] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0, v);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w] : g[u]){
			if (d[idx] > d[u] + w) {
				d[idx] = d[u] + w;
				pq.emplace(-d[idx], idx);
			}
		}
	}
	
	return d;
}

void solve(){
	int n, m, h; cin >> n >> m >> h;
	vector<vector<pair<int, int>>> g(2 * n + 1); // {vizinho, peso}
	
	for(int i = 1; i <= h; i++){
		int a; cin >> a; 
		g[a].push_back({a + n, 0});
		g[a + n].push_back({a, 0});
	}

	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		int w;    cin >> w;

		g[u].push_back({v, w});
		g[v].push_back({u, w});
		g[u + n].push_back({v + n, w / 2});
		g[v + n].push_back({u + n, w / 2});
	}

	vector<ll> mariah = dijkstra(1, g, 2 * n);
	vector<ll> robin  = dijkstra(n, g, 2 * n);

	ll ans = LINF;

	for(int i = 1; i <= n; i++){
		if(mariah[i] < LINF && robin[i] < LINF){
			ans = min(ans, max(mariah[i], robin[i]));
		}
		if(mariah[i + n] < LINF && robin[i] < LINF){
			ans = min(ans, max(mariah[i + n], robin[i]));
		}
		if(mariah[i] < LINF && robin[i + n] < LINF){
			ans = min(ans, max(mariah[i], robin[i + n]));
		}
		if(mariah[i + n] < LINF && robin[i + n] < LINF){
			ans = min(ans, max(mariah[i + n], robin[i + n]));
		}
	}

	if(ans == LINF) ans = -1;

	cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();

    return 0;
}