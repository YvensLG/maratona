#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 2e5 + 5;
vi G[MAX];
int v[2 * MAX];
pair<pii, int> query[MAX];
int at = -1;

struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

void solve_DistinctValuesQueries(int n, int q) {
    vector<int> is_first(n), next_eq(n);
    map<int, int> M;
 
    for(int i = n - 1; i >= 0; i--) {
        auto it = M.find(v[i]);
        if(it == M.end()) {
            is_first[i] = 1;    
            next_eq[i] = n;
        }
        else {
            is_first[i] = 1;
            is_first[it -> second] = 0;
            next_eq[i] = it -> second;
        }
        M[v[i]] = i;
    }
 
    sort(query, query + q);
    vector<int> ans(q);
 
    FT bit(n);
    for(int i = 0; i < n; i++) if(is_first[i]) bit.update(i, 1);
 
    int at = 0;
    for(int i = 0; i < q; i++) {
        int a = query[i].F.F, b = query[i].F.S;
        for(; at < a; at++) if(next_eq[at] <= n - 1) bit.update(next_eq[at], 1);
        ans[query[i].S] = bit.query(b + 1) - bit.query(a);
    }
 
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}

void dfs(int s, int p) {
    at++;
    query[s].S = s;
    query[s].F.F = at; v[at] = s;
    for(auto x : G[s]) {
        if(x == p) continue;
        dfs(x, s);
    }
    at++;
    query[s].F.S = at; v[at] = s;
}

void solve(){
    int n; cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].pb(b); G[b].pb(a);
    }

    dfs(0, -1);

    for(int i = 0; i < 2 * n; i++) v[i] = c[v[i]];

    solve_DistinctValuesQueries(2 * n, n);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}
