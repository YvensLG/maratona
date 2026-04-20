#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};
 
void solve(){
    int n, q; cin >> n >> q;
    FT bit(n + 2);

    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        bit.update(i, a);
        bit.update(i + 1, -a);
    }

    for(int i = 0; i < q; i++) {
        int c; cin >> c;
        if(c == 1) {
            int a, b, u; cin >> a >> b >> u;
            bit.update(a, u);
            bit.update(b + 1, -u);
        }
        else {
            int k; cin >> k;
            cout << bit.query(k + 1) << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}