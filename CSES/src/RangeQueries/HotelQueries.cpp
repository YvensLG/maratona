#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;

const int MAX = 2e5+20;
const ll LINF = 1e18;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	ll query(int a, int p=1, int l=0, int r=n-1) {
        if(seg[p] < a) return -1;
        if(l == r) return l;
		int m = (l+r)/2;
        int pos = query(a, 2*p, l, m);
        if(pos != -1) return pos;
        return query(a, 2*p+1, m+1, r);
    }
	ll update(int a, int x, int p=1, int l=0, int r=n-1) {
        if (a < l || r < a) {
			return seg[p];
		}
        if(l == r) {
            return seg[p] = seg[p] + x;
        }
		int m = (l+r)/2;
		return seg[p] = max(update(a, x, 2*p, l, m), update(a, x, 2*p+1, m+1, r));
	}
};

void solve() {
    int n, m; cin >> n >> m;

    int h[n];
    for(int i = 0; i < n; i++) cin >> h[i];

    seg::build(n, h);

    for(int i = 0; i < m; i++) {
        int s; cin >> s;
        int ans = seg::query(s);
        cout << ans + 1 << ' ';
        if(ans != -1)
            seg::update(ans, -s);
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}