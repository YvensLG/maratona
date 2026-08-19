const int MAX = 501;
const int MOD = 1e9 + 7;

// dp[t] = quantidade de perm com t invercoes
int dp[MAX * MAX / 2];

void solve() {
    int n, k; cin >> n >> k;

	dp[0] = 1;

	for(int i = 2; i <= n; i++) {
		int maxj = i * (i - 1) / 2;
		int window = 0;

		for(int j = maxj - (i - 1); j <= maxj; j++) {
			window = (window + dp[j]) % MOD;
		}

		for(int j = maxj; j >= 0; j--) {
			int ant = dp[j];
			dp[j] = window;
			if(j >= i) window = ((ll)window - ant + dp[j - i] + MOD) % MOD;
			else window = (window - ant + MOD) % MOD;
		}
	}

	cout << dp[k] << '\n';
}
