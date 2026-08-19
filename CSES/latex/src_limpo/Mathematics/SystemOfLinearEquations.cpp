const double eps = 1e-12;

ll pow(ll x, ll y, ll m) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

ll inv(ll a) {
	return pow(a, MOD - 2, MOD);
}

int solveLinear(vector<vi>& A, vi& b, vi& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		int v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = fabs(A[r][c])) > bv)
				br = r, bc = c, bv = v;
		if (bv <= eps) {
			rep(j,i,n) if (fabs(b[j]) > eps) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = inv(A[i][i]);
		rep(j,i+1,n) {
			int fac = (A[j][i] * bv) % MOD;
			b[j] = (b[j] + MOD - (fac * b[i] % MOD)) % MOD;
			rep(k,i+1,m) A[j][k] = (A[j][k] + MOD - (fac*A[i][k]) % MOD) % MOD;
		}
		rank++;
	}

	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] = (b[i] * inv(A[i][i])) % MOD;
		x[col[i]] = b[i];
		rep(j,0,i) b[j] = (b[j] + MOD - (A[j][i] * b[i]) % MOD) % MOD;
	}
	return rank;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a;
	vector<int> b;
	int x;
	for(int i = 0; i < n; i++) {
		a.push_back({});
		for(int j = 0; j < m; j++) {
			cin >> x;
			a.back().push_back(x);
		}
		cin >> x;
		b.push_back(x);
	}

	vector<int> y(m);
	int ans = solveLinear(a, b, y);

	if(ans == -1) {
		cout << ans << '\n';
		return;
	}

	for(auto k : y) cout << k << ' '; cout << '\n';
}
