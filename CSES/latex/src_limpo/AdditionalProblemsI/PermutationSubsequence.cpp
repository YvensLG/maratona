const int INF = 2000000000;

template<typename T> vector<T> lis(vector<T>& v) {
	int n = v.size(), m = -1;
	vector<T> d(n+1, INF);
	vector<int> l(n);
	d[0] = -INF;

	for (int i = 0; i < n; i++) {
		// Para non-decreasing use upper_bound()
		int t = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
		d[t] = v[i], l[i] = t, m = max(m, t);
	}

	int p = n;
	vector<T> ret;
	while (p--) if (l[p] == m) {
		ret.push_back(v[p]);
		m--;
	}
	reverse(ret.begin(),ret.end());

	return ret;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	vector<int> dec(n + 1);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		dec[a[i]] = i;
	}
	for(int j = 0; j < m; j++) cin >> b[j];
	if (n < m) {
		swap(n, m);
		swap(a, b);
	}
	vector<int> c(m + 1);
	for(int j = 0; j < m; j++) c[j] = dec[b[j]];

	vector<int> ans = lis<int>(c);
	cout << ans.size() << '\n';
	for(auto x : ans) {
		cout << a[x] << ' ';
	}
	cout << '\n';
}
