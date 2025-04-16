#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

struct dsu {
	vector<int> id, sz;

	dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

void solve() {
    int n, m; cin >> n >> m;
    dsu uniao(n + 1);

    for(int i = 0; i < m; i++)
    {
        int k; cin >> k;
        if(k > 0)
        {
            int a; cin >> a;
            for(int j = 1; j < k; j++)
            {
                int b; cin >> b;
                uniao.unite(a, b);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << uniao.sz[uniao.find(i)] << ' ';
    }
    cout << '\n';
}

signed main() { _
  solve();
}