struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
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
        int a, b, c; cin >> a >> b >> c; b--;
        if(a == 1) {
            bit.update(b, c - v[b]);
            v[b] = c;
        }
        else {
            c--;
            cout << bit.query(c + 1) - bit.query(b) << '\n';
        }
    }
}
