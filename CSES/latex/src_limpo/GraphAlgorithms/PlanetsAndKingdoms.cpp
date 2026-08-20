const int MAX = 1e5+5;

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

int vischeck[MAX];
void dfscheck(int k) {
	vischeck[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vischeck[g[k][i]]) dfscheck(g[k][i]);
}

void solve(){
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		gi[b].push_back(a);
	}

	kosaraju();

    vector<int> transf(n);
    int at = 1;

    for(int i = 0; i < n; i++) {
        if(transf[comp[i]] == 0) {
            transf[comp[i]] = at;
            at++;
        }
    }

    cout << at - 1 << '\n';
	for(int i = 0; i < n; i++) cout << transf[comp[i]] << ' ';
    cout << '\n';

}
