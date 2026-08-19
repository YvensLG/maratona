vi triang;

void solve() {
	int n; cin >> n;
	for(auto x : triang) {
		if(x == n) {
			cout << 1 << '\n';
			return;
		}
	}

	int i = 0, j = triang.size() - 1;

	while(i <= j) {
		if(triang[i] + triang[j] == n) {
			cout << 2 << '\n';
			return;
		}
		else if(triang[i] + triang[j] >= n) j--;
		else i++;
	}

	cout << 3 << '\n';
	return;
}

signed main() {
	for(int i = 0; i < MAX; i++) triang.push_back((i * (i + 1)) / 2);

	int t; cin >> t; while(t--)
	solve();

	return 0;
}
