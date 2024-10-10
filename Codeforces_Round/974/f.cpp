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

vector<vector<int>> graph;
vector<vector<int>> filho;
vector<int> pai;
vector<int> gold;
vector<ll> dp[2];
int c;

void dfs(int v){
	for(auto x : graph[v]) if(x != pai[v]){
		filho[v].pb(x);
		pai[x] = v;
		dfs(x);
	}
}

ll calc(int v, int q){
	if(dp[q][v] > -LINF) return dp[q][v];

	ll cont;

	if(q == 0){ // nao salva v
		cont = 0;
		for(auto f : filho[v]){
			cont += max(calc(f, 0), calc(f, 1));
		}
	}
	else{ // salva v
		cont = gold[v];
		for(auto f : filho[v]){
			cont += max(calc(f, 0), calc(f, 1) - 2 * c);
		}
	}

	return dp[q][v] = cont;
}

void solve(){
	int n; 
	cin >> n >> c;
	gold.resize(n + 1);
	graph.clear();
	graph.resize(n + 1);

	for(int i = 1; i <= n; i++) cin >> gold[i];

	for(int i = 1; i <= n - 1; i++){
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	pai.clear();
	pai.resize(n + 1);
	filho.clear();
	filho.resize(n + 1);
	dp[0].clear();
	dp[0].resize(n + 1, -LINF);
	dp[1].clear();
	dp[1].resize(n + 1, -LINF);

	pai[1] = 0;
	dfs(1);

	cout << max(calc(1, 0), calc(1, 1)) << '\n';
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();

    return 0;
}