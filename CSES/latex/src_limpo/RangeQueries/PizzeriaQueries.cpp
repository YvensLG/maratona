const int MAX = 2e5;
const int INF = 2e9;
int v[MAX], n, q;

namespace seg {
	pair<ll, ll> seg[4*MAX];

	pair<ll, ll> build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {v[l] - l, v[l] + l};
		int m = (l+r)/2;
        auto esq = build(2*p, l, m), dir = build(2*p+1, m+1, r);
		return seg[p] = {min(esq.first, dir.first), min(esq.second, dir.second)};
	}
	pair<ll, ll> query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {INF, INF};
		int m = (l+r)/2;
        auto esq = query(a, b, 2*p, l, m), dir = query(a, b, 2*p+1, m+1, r);
		return {min(esq.first, dir.first), min(esq.second, dir.second)};
	}
	void update(int a, int x, int p=1, int l=0, int r=n-1) {
		if (l == r) {
			seg[p] = {x - l, x + l};
		}
        else {
            int m = (l+r)/2;
            if (a <= m)
                update(a, x, p*2, l, m);
            else
                update(a, x, p*2+1, m+1, r);
            auto esq = seg[p*2], dir = seg[p*2+1];
		    seg[p] = {min(esq.first, dir.first), min(esq.second, dir.second)};
        }
	}
};

void solve(){
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    seg::build();

    for(int i = 0; i < q; i++) {
        int qi; cin >> qi;
        if(qi == 1) {
            int k, x; cin >> k >> x; k--;
            seg::update(k, x);
        }
        else {
            int k; cin >> k; k--;
            int esq = seg::query(0, k).first + k;
            int dir = seg::query(k, n - 1).second - k;
            cout << min(esq, dir) << '\n';
        }
    }
}
