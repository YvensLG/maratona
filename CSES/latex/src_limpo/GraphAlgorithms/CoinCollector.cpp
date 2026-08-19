const int MAX = 1e5 + 5;

int n, m;
vector<int> g[MAX];
vector<int> gi[MAX]; // grafo invertido
int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice

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

vector<int> new_g[MAX];
int new_k[MAX];
int dp[MAX];

vector<int> topo_sort(int n) {
	vector<int> ret(n,-1), vis(n,0);

	int pos = n-1, dag = 1;
	function<void(int)> dfs = [&](int v) {
		vis[v] = 1;
		for (auto u : new_g[v]) {
			if (vis[u] == 1) dag = 0;
			else if (!vis[u]) dfs(u);
		}
		ret[pos--] = v, vis[v] = 2;
	};

	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	if (!dag) ret.clear();
	return ret;
}

void solve(){
	cin >> n >> m;

	vector<int> k(n);
	for(int i = 0; i < n; i++) cin >> k[i];

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		gi[b].push_back(a);
	}

	kosaraju();

	for(int i = 0; i < n; i++) {
		for(auto x : g[i]) {
			if(comp[x] != comp[i]) new_g[comp[i]].push_back(comp[x]);
		}
		new_k[comp[i]] += k[i];
	}

	vi ret = topo_sort(n);

	int ans = 0;

	for(int i = ret.size() - 1; i >= 0; i--) {
		dp[ret[i]] = new_k[ret[i]];
		for(auto x : new_g[ret[i]]) {
			dp[ret[i]] = max(dp[x] + new_k[ret[i]], dp[ret[i]]);
		}
		ans = max(ans, dp[ret[i]]);
	}

	cout << ans << '\n';

}
