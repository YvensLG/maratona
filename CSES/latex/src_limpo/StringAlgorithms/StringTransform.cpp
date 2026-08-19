void solve() {
	string s;
	vector<pair<char, int>> t;
	cin >> s;

	for(int i = 0; i < sz(s); i++) {
		t.push_back({s[i], i});
	}
	sort(t.begin(), t.end());

	char c; int p = 0;
	for(int i = 0; i < sz(s); i++) {
		tie(c, p) = t[p];
		if(c != '#') cout << c;
	}
	cout << '\n';
}
