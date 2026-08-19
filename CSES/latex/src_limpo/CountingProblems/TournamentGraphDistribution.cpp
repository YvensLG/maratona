const int MAX = 505;
const int MOD = 1e9 + 7;

int ans[MAX][MAX];
int bin[MAX][MAX];

/*
existe exatamente uma ordenação topológica que representa o torneio
(considerando apenas as k componentes)

k > 1
ans[n][k] = sum ans[n - i][k - 1] * ans[i][1] * (n choose i)

i é a quantidade de elementos no primeiro grupo da ordenação

(a1 a2 ... ai) | (resto)

ans[n][1] = 2^{n(n-1)/2} - sum ans[n][i]
*/

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
    ans[1][1] = 1;
    bin[0][0] = 1;

    for(int n = 1; n < MAX; n++) {
        bin[n][0] = 1;
        for(int k = 1; k <= n; k++) {
            bin[n][k] = (bin[n - 1][k] + bin[n - 1][k - 1]) % MOD;
        }
    }

    for(int n = 2; n < MAX; n++) {
        int tot = 0;
        for(int k = 2; k <= n; k++) {
            for(int i = 1; n - i >= k - 1; i++) {
                int aux = (ans[n - i][k - 1] * ans[i][1]) % MOD;
                aux = (aux * bin[n][i]) % MOD;
                ans[n][k] = (ans[n][k] + aux) % MOD;
            }
            tot = (tot + ans[n][k]) % MOD;
        }
        ans[n][1] = fexp(2, n * (n - 1) / 2);
        ans[n][1] = ((ans[n][1] - tot) % MOD + MOD) % MOD;
    }
}

void solve() {
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << ans[n][i] << '\n';
    }
}

signed main() { _
    calc();
    solve();
}
