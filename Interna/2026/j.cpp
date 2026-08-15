#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

#define int long long
#define double long double

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 2e5 + 5;
int f[MAX];

ord_set<int> pos[MAX];

struct Node {
    int cand;
    int cont;
};

namespace seg {
	Node seg[4*MAX];
	int n, *v;

    Node merge(Node a, Node b) {
        if (a.cand == b.cand) {
            return {a.cand, a.cont + b.cont};
        }
        if (a.cont > b.cont) {
            return {a.cand, a.cont - b.cont};
        }
        if (b.cont > a.cont) {
            return {b.cand, b.cont - a.cont};
        }
        return {-1, 0};
    }

	Node build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {v[l], 1};
		int m = (l+r)/2;
		return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	Node query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {-1, 0};
		int m = (l+r)/2;
		return merge(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	Node update(int a, int x, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= a) {
			return seg[p] = {x, 1};
		}
		if (a < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = merge(update(a, x, 2*p, l, m), update(a, x, 2*p+1, m+1, r));
	}
};

void solve() {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> f[i];
        pos[f[i]].insert(i);
    }

    seg::build(n, f);

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int i, v; cin >> i >> v; 
            i--;
            int ant = f[i];
            
            seg::update(i, v);
            pos[ant].erase(i);
            pos[v].insert(i);
            f[i] = v;
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;
            int c = seg::query(l, r).cand;
            
            int freq = 0;
            if(c >= 0) freq = pos[c].order_of_key(r + 1) - pos[c].order_of_key(l);

            int s = r - l + 1;
            if (freq > s / 2) {
                cout << s - freq << "\n";
            } else {
                cout << s / 2 << "\n";
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();

    return 0; 
}
