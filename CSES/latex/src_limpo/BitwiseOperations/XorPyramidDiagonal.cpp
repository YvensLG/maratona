const int LMAX = 18;
vector<int> v(1 << LMAX);

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < LMAX; i++) for (int mask = 0; mask < (1 << LMAX); mask++)
		if (mask>>i&1) v[mask] ^= v[mask^(1<<i)];

	for(int i = 0; i < n; i++) cout << v[i] << ' '; cout << '\n';
}
