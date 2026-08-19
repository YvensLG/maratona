struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] ^= dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res ^= s[pos-1];
		return res;
	}
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    FT bit(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        bit.update(i, v[i]);
    }

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--; b--;
        cout << (bit.query(b + 1) ^ bit.query(a)) << '\n';
    }
}
