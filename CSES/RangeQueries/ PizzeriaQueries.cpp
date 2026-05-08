#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pc __builtin_popcount

typedef long long ll;

const int MAX = 2e5+20;
const ll LINF = 4e18;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	ll n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, ll* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return -LINF;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};
 
void solve() {
    int n, q; cin >> n >> q;
    ll x[n + 1], pref[n + 1]; x[0] = 0; pref[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> x[i]; pref[i] = pref[i - 1] + x[i];
    }

    seg::build(n + 1, pref);
    
    for(int i = 0; i < q; i++) {
        int c; cin >> c;
        int a, b; cin >> a >> b;

        if(c == 1) {
            seg::update(a, n, b - x[a]);
            x[a] = b;
        }
        else {
            ll ans = seg::query(a, b) - seg::query(a - 1, a - 1);
            cout << max(ans, 0LL) << '\n';
        }

    }

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}