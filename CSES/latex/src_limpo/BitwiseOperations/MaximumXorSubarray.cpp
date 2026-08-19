int find_ans(vector<int>&v0, vector<int>&v1, int mxbit) {
	if(v0.size() == 0 || v1.size() == 0) return 0;
	if(mxbit == 0) {
		return (v0.back() ^ v1.back());
	}

	int mxbit_new = 0;
	for(int i = 0; i < mxbit; i++) {
		for(auto x : v0) if(x & (1 << i)) mxbit_new = i;
		for(auto x : v1) if(x & (1 << i)) mxbit_new = i;
	}

	vector<int> v00, v01, v10, v11;

	for(auto x : v0) {
		if(x & (1 << mxbit_new)) v01.push_back(x);
		else v00.push_back(x);
	}
	for(auto x : v1) {
		if(x & (1 << mxbit_new)) v11.push_back(x);
		else v10.push_back(x);
	}
	if((v00.size() == 0 || v11.size() == 0) && (v01.size() == 0 || v10.size() == 0)) {
		return find_ans(v0, v1, mxbit_new);
	}

	return max(find_ans(v00, v11, mxbit_new), find_ans(v01, v10, mxbit_new));
}

void solve(){
    int n; cin >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] ^= v[i - 1];
	}

	sort(v.begin(), v.end());

	int lst = v.back(), mxbit = 0;
	for(int i = 0; i <= 30; i++) {
		if(lst & (1 << i)) mxbit = i;
	}

	vector<int> v0, v1;

	for(auto x : v) {
		if(x & (1 << mxbit)) v1.push_back(x);
		else v0.push_back(x);
	}

	int ans = find_ans(v0, v1, mxbit);

	cout << ans << '\n';
}
