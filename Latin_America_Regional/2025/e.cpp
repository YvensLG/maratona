#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MAX = 300010;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
    vector<int> v;
	int n;

	ll build(int p, int l, int r) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2) {
		n = n2;
        v.resize(n);
        v[0] = 0;
        for(int i = 1; i < n; i++)
            v[i] = LINF;

		build(1, 0, n-1);
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return LINF;
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
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
		return seg[p] = min(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

void solve(){
    int q; cin >> q;
    vector<tuple<int, int, int>> queries;
    for(int i = 0; i < q; i++) {
        char s; cin >> s;
        int x; cin >> x;
        if(s == '+') queries.push_back({x, 1LL, i});
        if(s == '-') queries.push_back({x, 2LL, i});
    }
    auto aux = queries;
    sort(aux.begin(), aux.end());
    int at = get<0>(aux[0]);
    int qtt = 0;
    int seg_pos = -1;
    int next_seg_pos = -1;

    for(int i = 0; i < q; i++) {
        auto [x, sig, i0] = aux[i];
        if(x == at){
            if(sig == 2 && get<1>(aux[i - 1]) == 1) qtt = 0;
            qtt++;
            get<2>(queries[i0]) = seg_pos + qtt;
            if(sig == 1) next_seg_pos = seg_pos + qtt;
        }
        else {
            at = x;
            qtt = 1;
            seg_pos = next_seg_pos;
            get<2>(queries[i0]) = seg_pos + qtt;
            next_seg_pos = seg_pos + qtt;
        }
    }

    seg::build(q + 1);

    int sz = 0;
    for(auto [x, sig, pos] : queries) {
        pos++;
        if(sig == 1) {
            seg::update(pos, q, -1);
            seg::update(pos, pos, -LINF + x);
            sz++;
        }
        else {
            seg::update(pos, q, +1);
            seg::update(pos, pos, +LINF - x);
            sz--;
        }
        cout << sz + seg::query(0, q) << ' ';
    }
    cout << '\n';
}

signed main() { _
    solve();
    return 0;
}