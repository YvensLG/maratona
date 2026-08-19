void solve(){
	int n, k; cin >> n >> k;
	vector<int> v(n);
	int a, b, c; cin >> v[0] >> a >> b >> c;

	for(int i = 1; i < n; i++)
		v[i] = ((long long)v[i - 1] * a + b) % c;

	int buckets = (n + k - 1) / k;
	vector<int> pref(n + 1, 0);
	vector<int> suf(n + 1, 0);

	for(int i = 0; i < buckets; i++)
	{
		for (int j = min(k, n - i * k) - 1; j >= 0; --j)
			suf[i * k + j] = suf[i * k + j + 1] | v[i * k + j];
	}

	for(int i = buckets - 1; i >= 0; i--)
	{
		for (int j = 0; j < k && i * k + j < n; j++)
			pref[i * k + j + 1] = pref[i * k + j] | v[i * k + j];
	}

	int ans = 0;

	for(int i = 0; i <= n - k; i++)
	{
		if(i % k == 0)
			ans ^= suf[i];
		else
			ans ^= suf[i] | pref[i + k];
	}

	cout << ans << '\n';
}
