#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
 
using namespace std;

const int MAX = 2e5 + 5;
const int INF = 2e9;
int v[MAX];
 
typedef long long int ll;
 
namespace seg {
	ll seg[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return INF;
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	void update(int a, int x, int p=1, int l=0, int r=n-1) {
		if (l == r) {
			seg[p] = x;
		}
        else {
            int m = (l+r)/2;
            if (a <= m)
                update(a, x, p*2, l, m);
            else
                update(a, x, p*2+1, m+1, r);
            seg[p] = min(seg[p*2], seg[p*2+1]);
        }
	}
};
 
void solve(){
    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    seg::build(n, v);

    for(int i = 0; i < q; i++) {
        int qi; cin >> qi;
        if(qi == 1) {
            int k, u; cin >> k >> u; k--;
            seg::update(k, u);
        }
        else {
            int a, b; cin >> a >> b; a--; b--;
            cout << seg::query(a, b) << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}