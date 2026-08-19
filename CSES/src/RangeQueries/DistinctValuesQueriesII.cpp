#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define F first 
#define S second
#define pc __builtin_popcount
 
using namespace std;
 
const int MAX = 2e5;

int n, q;
vector<int> v, next_eq, prev_eq;
set<int> seq[2 * MAX];

namespace seg {
    // o proximo que eh igual a alguem do node
	int seg[4*MAX];
 
	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) {
            auto it = seq[v[l]].lower_bound(l + 1);
            if(it != seq[v[l]].end()) return seg[p] = *it;
            return seg[p] = MAX + 1;
        }
		int m = (l+r)/2;
        return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return MAX + 1;
		int m = (l+r)/2;
        return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	void update(int a, int p=1, int l=0, int r=n-1) {
		if (l == r) {
            auto it = seq[v[l]].lower_bound(l + 1);
            if(it != seq[v[l]].end()) seg[p] = *it;
            else seg[p] = MAX + 1;
        }
        else {
            int m = (l+r)/2;
            if (a <= m)
                update(a, p*2, l, m);
            else
                update(a, p*2+1, m+1, r);
            seg[p] = min(seg[p*2], seg[p*2 + 1]);
        }
	}
};

void solve(){
    cin >> n >> q; v.resize(n);
    vector<int> all_numbers;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        all_numbers.push_back(v[i]);
    }
 
    vector<pair<int, pair<int, int>>> query(q);
    for(int i = 0; i < q; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) {
            query[i] = {a, {b - 1, c}};
            all_numbers.push_back(c);
        }
        else {
            query[i] = {a, {b - 1, c - 1}};
        }
    }

    sort(all(all_numbers));
    all_numbers.erase(unique(all(all_numbers)), all_numbers.end());

    for(int i = 0; i < n; i++) v[i] = lower_bound(all(all_numbers), v[i]) - all_numbers.begin();

    for(int i = 0; i < n; i++) seq[v[i]].insert(i);

    seg::build();

    for(int i = 0; i < q; i++) {
        if(query[i].F == 1) {
            query[i].S.S = lower_bound(all(all_numbers), query[i].S.S) - all_numbers.begin();
            auto [u, k] = query[i].S;

            vector<int> alts;
            alts.push_back(u);

            auto it = seq[v[u]].find(u);
            if(it != seq[v[u]].begin()) alts.push_back(*prev(it));
            seq[v[u]].erase(it);

            v[u] = k;
            seq[k].insert(u);

            it = seq[v[u]].find(u);
            if(it != seq[v[u]].begin()) alts.push_back(*prev(it));
            
            for(auto x : alts) seg::update(x);
        }
        else {
            auto [a, b] = query[i].S;
            cout << ((seg::query(a, b) <= b) ? "NO\n" : "YES\n");
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}