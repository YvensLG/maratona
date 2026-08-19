#include <bits/stdc++.h>
#define pb push_back

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Line {
	mutable ll k, m;
    mutable ld p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ld x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	static constexpr ld inf = 1e18;
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = ((ld)y->m - x->m) / ((ld)x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
};
 
void solve(){
    int n; cin >> n;
    LineContainer cht;
    cht.add(0, 0);
    ll pref = 0;
    for(int i = 1; i <= n; i++) {
        int v; cin >> v; pref += v;
        cht.add(i, -pref);
        int bst = next(cht.rbegin()) -> k;
        cout << i - bst << ' ';
    }
    cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}