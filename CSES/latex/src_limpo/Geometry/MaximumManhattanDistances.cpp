void solve(){
	int n; cin >> n;
	set<int> px;
	set<int> py;
	for(int i = 0; i < n; i++){
		int x1, y1; cin >> x1 >> y1;
		// Chebyshev distance
		int x = x1 + y1;
		int y = x1 - y1;

		px.insert(x);
		py.insert(y);
		int ansx = *px.rbegin() - *px.begin();
		int ansy = *py.rbegin() - *py.begin();
		cout << max(ansx, ansy) << '\n';
	}
}
