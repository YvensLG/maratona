#include <bits/stdc++.h>
 
#define int long long
#define pb push_back
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

const int MAX = 2e5+1;

// matar custa s_i * f tempo e vc recebe a forca f_i
// dp[i] = resposta matando o monstro i
// dp[n] = 0
// dp[k] = min(s[l] * f[k] + dp[l]); k + 1 <= l <= n.
// CHT em s[l] * x + dp[l]

int dp[MAX], s[MAX], f[MAX];
int n, x;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

void solve(){
    cin >> n >> x; dp[n] = 0;
    for(int i = 1; i <= n; i++) cin >> s[i]; s[0] = 0;
    for(int i = 1; i <= n; i++) cin >> f[i]; f[0] = x;

    LineContainer cht;
    cht.add(-s[n], -dp[n]);

    for(int at = n - 1; at >= 0; at--) {
        dp[at] = -cht.query(f[at]);
        cht.add(-s[at], -dp[at]);
    }

    cout << dp[0] << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}