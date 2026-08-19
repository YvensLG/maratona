const int MOD = 1e9 + 7, MAX = 5005;

/*
se k = a + b, e A = 1 2 3 ... n
fixamos n - k posições iguais (empates) e permutamos A
ans = n! * binom(n, n - k) * ans(k, a)
onde ans(n, a) é a resposta quando n = a + b e A = 1 2 3 ... n
ou seja, número de perm. caóticas de tam. 'k' com 'a' elementos maiores q os originais
ans(n, a) = a * ans(n-1, a) + (n-a) * ans(n-1, a-1) + (n-1) * ans(n-2, a-1)
ans(n-1, a) -> pega um elemento dos 'a' e troca por 'n'
ans(n-1, a-1) -> pega um elemento dos 'b' e troca por 'n' (adicionando 1 no a)
ans(n-2, a-1) -> considera que um dentre os n-1 ta "empatado" (add dois elementos, o do empate e o n)
*/

vector<vector<int>> dp(MAX, vector<int>(MAX));
vector<int> fac(MAX);

int fexp(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % MOD;
		y >>= 1;
		x = (x * x) % MOD;
	}
	return ret;
}

void calc() {
    fac[0] = 1;
    for(int i = 1; i < MAX; i++) fac[i] = (fac[i - 1] * i) % MOD;

    dp[2][1] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;

    for(int i = 4; i < MAX; i++)
        for(int j = 1; j < i; j++)
            dp[i][j] = (j * dp[i-1][j] + (i - j) * dp[i-1][j-1] + (i-1) * dp[i-2][j-1]) % MOD;
}

int binom(int a, int b) {
    if(a < b) return 0;
    int ans = fac[a];
    ans = ( ans * fexp(fac[b], MOD - 2) ) % MOD;
    ans = ( ans * fexp(fac[a - b], MOD - 2) ) % MOD;
    return ans;
}

void solve() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    if(a == 0 && b == 0) {
        cout << fac[n] << '\n';
        return;
    }
    if(a + b > n) {
        cout << 0 << '\n';
        return;
    }
    int k = a + b;
    int ans = fac[n];
    ans = (ans * binom(n, k)) % MOD;
    ans = (ans * dp[k][a]) % MOD;
    cout << ans << '\n';

}

signed main() { _
    calc();
    int t; cin >> t; while(t--)
    solve();
}
