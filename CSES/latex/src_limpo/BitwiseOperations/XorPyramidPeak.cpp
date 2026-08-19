int bin_v2(int n, int k) {
	return pc(k) + pc(n - k) - pc(n);
}

void solve(){
	int n; cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		if(bin_v2(n - 1, i) == 0) ans ^= a;
	}

	cout << ans << '\n';
}
