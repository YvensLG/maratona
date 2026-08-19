vector<int> suffix_array(string s) {
	s += "$";
	int n = s.size(), N = max(n, 260LL);
	vector<int> sa(n), ra(n);
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];

	for(int k = 0; k < n; k ? k *= 2 : k++) {
		vector<int> nsa(sa), nra(n), cnt(N);

		for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
		for(int i = 1; i < N; i++) cnt[i] += cnt[i-1];
		for(int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
			ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		ra = nra;
		if (ra[sa[n-1]] == n-1) break;
	}
	return vector<int>(sa.begin()+1, sa.end());
}

string s;
bool complb(int p, const string& t) {
	return s.compare(p, t.size(), t) < 0;
}
bool compup(const string& t, int p) {
	return s.compare(p, t.size(), t) > 0;
}

void solve() {
	cin >> s;
    int k; cin >> k;

    vector<int> sa = suffix_array(s);

	for(int i = 0; i < k; i++) {
		string t; cin >> t;
		auto ub = upper_bound(sa.begin(), sa.end(), t, compup);
		auto lb = lower_bound(sa.begin(), sa.end(), t, complb);
		cout << ub - lb << '\n';
	}

}
