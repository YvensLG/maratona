const int LMAX = 20;
vector<int> sub(1 << LMAX);
vector<int> sup(1 << LMAX);

void solve(){
	int n; cin >> n; vector<int> v(n);
	for(int i = 0; i < n; i++) {
        cin >> v[i];
        sub[v[i]]++; sup[v[i]]++;
    }

	for (int i = 0; i < LMAX; i++) for (int mask = 0; mask < (1 << LMAX); mask++) {
		if (mask>>i&1)  sub[mask] += sub[mask^(1<<i)];
        if (~mask>>i&1) sup[mask] += sup[mask^(1<<i)];
    }

    int msk = (1 << LMAX) - 1;

	for(int i = 0; i < n; i++) {
        cout << sub[v[i]] << ' ' << sup[v[i]] << ' ' << n - sub[msk - v[i]] << '\n';
    }
}
