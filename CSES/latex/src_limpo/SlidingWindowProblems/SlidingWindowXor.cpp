void solve(){
	int n, k; cin >> n >> k;
	int x, a, b, c; cin >> x >> a >> b >> c;

	int sum = 0;
	int at = x;
	for(int i = 0; i < k - 1; i++){
		if((i + 1) % 2 == 1)
			sum ^= at;
		at = (a * at + b) % c;
	}
	for(int i = k - 1; i <= n - k; i++){
		if(k % 2 == 1)
			sum ^= at;
		at = (a * at + b) % c;
	}
	for(int i = n - k + 1; i < n; i++){
		if((n - i) % 2 == 1)
			sum ^= at;
		at = (a * at + b) % c;
	}

	cout << sum << '\n';
}
