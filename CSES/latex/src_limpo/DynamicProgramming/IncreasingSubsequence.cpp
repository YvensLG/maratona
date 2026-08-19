const int maxn = 5e2 + 5, inf = 2e9, M = 1e9 + 7;

template<typename T> int lis(vector<T> &v){
	vector<T> ans;
	for (T t : v){
		auto it = lower_bound(ans.begin(), ans.end(), t);
		if (it == ans.end()) ans.push_back(t);
		else *it = t;
	}
	return ans.size();
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    cout << lis<int> (v) << '\n';
}
