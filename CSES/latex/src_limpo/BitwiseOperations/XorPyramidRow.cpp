int bin_v2(int n, int k) {
	return pc(k) + pc(n - k) - pc(n);
}

void solve(){
	int n, k; cin >> n >> k;
	int shift = n - k;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	for(int i = 1 << 30; i > 0; i >>= 1) {
		if((i & shift) == 0) continue;

		vector<int> aux(n - i);
		for(int j = 0; j < n - i; j++) {
            aux[j] = v[j] ^ v[j + i];
        }

		v = aux;
		n = aux.size();
	}

	for(auto x : v) cout << x << ' '; cout << '\n';
}
