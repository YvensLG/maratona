#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int MAX = 1e5, INF = 2e9;
int n, q;
vector<int> next_h, h;
 
void next_higher() {
    next_h.resize(n, n);
    stack<int> st;
 
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && h[st.top()] <= h[i])
            st.pop();
        if (!st.empty())
            next_h[i] = st.top();
        st.push(i);
    }
}

namespace seg {
    // (answer, pos of the biggest) 
	pair<int, int> seg[4*MAX];

	pair<int, int> query(int a, int b, int p=1, int l=0, int r=n-1) {
        if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {0, -1};
		int m = (l+r)/2;

        auto [esq_ans, esq_big] = query(a, b, 2*p, l, m);
        if (esq_big == -1) {
            return query(a, b, 2*p+1, m+1, r);
        } 
        int nxt = next_h[esq_big];
        if(nxt > b || nxt > r) return {esq_ans, esq_big};

        auto [dir_ans, dir_big] = query(nxt, b, 2*p+1, m+1, r);
		return {dir_ans + esq_ans, dir_big};
	}
 
	pair<int, int> build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {1, l};
		int m = (l+r)/2;

        auto [esq_ans, esq_big] = build(2*p, l, m); build(2*p+1, m+1, r);
        
        int nxt = next_h[esq_big];
        if(nxt > r) return seg[p] = {esq_ans, esq_big};

        auto [dir_ans, dir_big] = query(nxt, r, 2*p+1, m+1, r);
		return seg[p] = {dir_ans + esq_ans, dir_big};
	}
};
 
void solve(){
    cin >> n >> q;
    h.resize(n);
    for(int i = 0; i < n; i++) cin >> h[i];
	next_higher();
 
    seg::build();

	for(int i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r; l--; r--;
        cout << seg::query(l, r).first << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}