#include <bits/stdc++.h>
#define int long long
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
pii tempo[MAX];
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
 
void dfs(int s, int p, const vector<int> &t) {
    at++;
    tempo[s].F = at; v[at] = t[s];
    for(auto x : G[s]) {
        if(x == p) continue;
        dfs(x, s, t);
    }
    at++;
    tempo[s].S = at; v[at] = -t[s];
}
 
void solve(){
    int n, q; cin >> n >> q;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
 
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].pb(b); G[b].pb(a);
    }
 
    dfs(0, -1, t);
 
    FT bit(2 * n);
    for(int i = 0; i < 2 * n; i++) bit.update(i, v[i]);
 
    for(int i = 0; i < q; i++) {
        int a; cin >> a;
        if(a == 1) {
            int s, x; cin >> s >> x; s--;
            auto [tin, tout] = tempo[s];
            bit.update(tin, x - v[tin]);
            bit.update(tout, v[tin] - x);
            v[tin] = x; v[tout] = -x;
        }
        else {
            int s; cin >> s; s--;
            auto [tin, tout] = tempo[s];
            cout << bit.query(tout) << '\n';
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}