#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pc __builtin_popcount

typedef long long ll;

const int MAX = 2e5 + 20;
const ll LINF = 4e18;

namespace seg {
	ll seg[4*MAX];
	pair<ll, ll> lazy[4*MAX];
	ll n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = {0, 0};
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, ll* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		ll ini = lazy[p].first, pulo = lazy[p].second, len = r - l + 1;
		seg[p] += ini * len;
		seg[p] += pulo * (len - 1) * len / 2;
		if (l != r) {
			lazy[2*p].first += ini;
			lazy[2*p].second += pulo;

			int len_esq = (r - l) / 2 + 1;
			lazy[2*p + 1].first += ini + pulo * len_esq;
			lazy[2*p + 1].second += pulo;
		}
		lazy[p] = {0, 0};
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p].first += (l - a + 1);
			lazy[p].second += 1;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, 2*p, l, m) + update(a, b, 2*p+1, m+1, r);
	}
};
 
void solve() {
    int n, q; cin >> n >> q;
    ll t[n + 1]; t[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    seg::build(n + 1, t);
    
    for(int i = 0; i < q; i++) {
        int c; cin >> c;
        int a, b; cin >> a >> b;

        if(c == 1) {
            seg::update(a, b);
        }
        else {
            cout << seg::query(a, b) << '\n';
        }

    }

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}