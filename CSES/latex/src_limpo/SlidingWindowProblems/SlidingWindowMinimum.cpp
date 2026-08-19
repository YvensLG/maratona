deque<int> minq;

void addmin(int a) {
	while(!minq.empty() && minq.back() > a)
		minq.pop_back();
	minq.push_back(a);
}

void remmin(int a) {
	if(!minq.empty() && minq.front() == a)
		minq.pop_front();
}

void solve(){
	int n, k; cin >> n >> k;
	int x, a, b, c; cin >> x >> a >> b >> c;
	int first = x;
	int sum = 0, at = x;
	int ans = 0;
	for(int i = 0; i < k; i++) {
		addmin(at);
		at = (at * a + b) % c;
	}
	sum = minq.front();
	ans = ans ^ sum;
	for(int i = k; i < n; i++) {
		addmin(at);
		remmin(first);
		sum = minq.front();
		at = (at * a + b) % c;
		first = (first * a + b) % c;
		ans ^= sum;
	}
	cout << ans << '\n';
}
