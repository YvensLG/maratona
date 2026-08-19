#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
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
 
void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n), is_first(n), next_eq(n);
    map<int, int> M;
    for(int i = 0; i < n; i++) cin >> v[i];
 
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
 
    vector<pair<pair<int, int>, int>> query(q);
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        query[i] = {{a - 1, b - 1}, i};
    }
 
    sort(all(query));
    vector<int> ans(q);
 
    FT bit(n);
    for(int i = 0; i < n; i++) if(is_first[i]) bit.update(i, 1);
 
    int at = 0;
    for(int i = 0; i < q; i++) {
        int a = query[i].first.first, b = query[i].first.second;
        for(; at < a; at++) if(next_eq[at] <= n - 1) bit.update(next_eq[at], 1);
        ans[query[i].second] = bit.query(b + 1) - bit.query(a);
    }
 
    for(auto x : ans) cout << x << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}