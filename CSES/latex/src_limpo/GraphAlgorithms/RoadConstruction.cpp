int n, m;

struct dsu {
	vector<int> id, sz;

	dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

void solve(){
    cin >> n >> m;
	dsu D(n);

	int tot = n, maxi = 1;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
		if(D.find(a) != D.find(b)) tot--;
        D.unite(a, b);
		maxi = max(maxi, D.sz[D.find(a)]);
		cout << tot << ' ' << maxi << '\n';
	}
}
