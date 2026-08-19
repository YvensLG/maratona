void solve(){
	int n, k; cin >> n >> k;
	vector<int> a(n);

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	map<int, int> freq;
	for(int i = 0; i < k; i++) {
		freq[a[i]]++;
		if(freq[a[i]] == 1) {
			ans++;
		}
	}

	cout << ans << " ";

	for(int i = k; i < n; i++) {
		freq[a[i - k]]--;
		if(freq[a[i - k]] == 0) {
			ans--;
		}
		freq[a[i]]++;
		if(freq[a[i]] == 1) {
			ans++;
		}
		cout << ans << " ";
	}

	cout << '\n';
}
