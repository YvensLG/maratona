#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pc __builtin_popcount

typedef long long ll;

const int MAX = 6e5+20;

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
    ll query(int a, int b) {
        return query(b + 1) - query(a);
    }
};
 
void solve() {
    int n, q; cin >> n >> q;
    vector<int> p(n); 
    vector<tuple<int, int, int>> queries(q);
    for(int i = 0; i < n; i++) cin >> p[i];

    for(int i = 0; i < q; i++) {
        char c; cin >> c;
        int a, b; cin >> a >> b;
        queries[i] = {c, a, b};
    }

    vector<int> all_salaries;
    for(auto x : p) all_salaries.push_back(x);
    for(auto [c, a, b] : queries) {
        all_salaries.push_back(b);
        if(c == '?') all_salaries.push_back(a);
    }

    sort(all_salaries.begin(), all_salaries.end());
    all_salaries.erase(unique(all_salaries.begin(), all_salaries.end()), all_salaries.end());

    for(int i = 0; i < n; i++) p[i] = lower_bound(all(all_salaries), p[i]) - all_salaries.begin();
    for(int i = 0; i < q; i++) {
        get<2>(queries[i]) = lower_bound(all(all_salaries), get<2>(queries[i])) - all_salaries.begin();
        if(get<0>(queries[i]) == '?') 
            get<1>(queries[i]) = lower_bound(all(all_salaries), get<1>(queries[i])) - all_salaries.begin();
    }

    FT bit(MAX);
    for(auto x : p) bit.update(x, 1);
    
    for(auto [c, a, b] : queries) {
        if(c == '!') {
            bit.update(b, 1);
            bit.update(p[a - 1], -1);
            p[a - 1] = b;
        }
        else {
            int ans = bit.query(a, b);
            cout << ans << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}