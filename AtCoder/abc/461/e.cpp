#include <bits/stdc++.h>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

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

void solve() {
    int n, q; cin >> n >> q;

    FT bit_row(q + 2), bit_col(q + 2);

    vector<int> time_row(n + 1, 0), time_col(n + 1, 1); 
    bit_col.update(1, n);

    int preto = 0;
    for (int t = 2; t <= q + 1; t++) {
        int id, pos; cin >> id >> pos;

        if (id == 1) { 
            int old = time_row[pos];
            if (old > 0) bit_row.update(old, -1);
            
            preto += n - bit_col.query(old);
            
            time_row[pos] = t;
            bit_row.update(t, 1);

        } else { 
            int old = time_col[pos];
            if (old > 0) bit_col.update(old, -1);
            
            preto -= bit_row.query(q + 2) - bit_row.query(old + 1);
            
            time_col[pos] = t;
            bit_col.update(t, 1);
        }
        
        cout << preto << '\n';
    }
}

signed main() { _
    solve();
}