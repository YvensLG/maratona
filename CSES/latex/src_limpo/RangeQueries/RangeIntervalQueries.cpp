const int MAXN = 200001;
int n, q;
vector<int> t[2 * MAXN];

void solve(){
	cin >> n >> q;

	// build
    for(int i = n; i < 2 * n; i++)  {
		t[i] = {0};
		cin >> t[i][0];
	}
	for (int i = n - 1; i; i--)
        merge(all(t[2 * i]), all(t[2 * i + 1]), back_inserter(t[i]));

	// query
	int a, b, c, d;
	for(int i = 0; i < q; i++) {
        cin >> a >> b >> c >> d; a--; b--;
		int res = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) {
				res += upper_bound(all(t[a]), d) - lower_bound(all(t[a]), c);
			}
			if (b % 2 == 0) {
				res += upper_bound(all(t[b]), d) - lower_bound(all(t[b]), c);
			}
		}
        cout << res << '\n';
    }
}
