#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pc __builtin_popcount
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

struct kuhn {
	int n, m;
	vector<vector<int>> g;
	vector<int> vis, ma, mb;

	kuhn(int n_, int m_) : n(n_), m(m_), g(n),
		vis(n+m), ma(n, -1), mb(m, -1) {}

	void add(int a, int b) { g[a].push_back(b); }

	bool dfs(int i) {
		vis[i] = 1;
		for (int j : g[i]) if (!vis[n+j]) {
			vis[n+j] = 1;
			if (mb[j] == -1 or dfs(mb[j])) {
				ma[i] = j, mb[j] = i;
				return true;
			}
		}
		return false;
	}
	int matching() {
		int ret = 0, aum = 1;
		for (auto& i : g) shuffle(i.begin(), i.end(), rng);
		while (aum) {
			for (int j = 0; j < m; j++) vis[n+j] = 0;
			aum = 0;
			for (int i = 0; i < n; i++)
				if (ma[i] == -1 and dfs(i)) ret++, aum = 1;
		}
		return ret;
	}
};

pair<vector<int>, vector<int>> recover(kuhn& K) {
	K.matching();
	int n = K.n, m = K.m;
	for (int i = 0; i < n+m; i++) K.vis[i] = 0;
	for (int i = 0; i < n; i++) if (K.ma[i] == -1) K.dfs(i);
	vector<int> ca, cb;
	for (int i = 0; i < n; i++) if (!K.vis[i]) ca.push_back(i);
	for (int i = 0; i < m; i++) if (K.vis[n+i]) cb.push_back(i);
	return {ca, cb};
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    kuhn G(n, m);
    for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G.add(a, b);
    }

    int t = G.matching();
    cout << t << '\n';
    for(int i = 0; i < n; i++) {
        if(G.ma[i] != -1) cout << i + 1 << ' ' << G.ma[i] + 1 << '\n';
    }
}
  
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}