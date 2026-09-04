#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep( i, a, b ) for( int i = a; i < (b); i++ )

#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1e5+10;

int n, S, K;
int h[MAX], u[MAX], l[MAX];
vi act;
vector<pii> ord;

bool comp(int a, int b) {
    pii fa, fb;
    if(a > 0) fa = {l[a], h[a]};
    else fa = {u[-a], h[-a]};
    if(b > 0) fb = {l[b], h[b]};
    else fb = {u[-b], h[-b]};

    ll lft = (ll)fa.F * fb.S, rgt = (ll)fa.S * fb.F;

    if(lft == rgt) {
        return a > b;
    }
    else return lft < rgt;
}

pll min_frac(pll a, pll b) {
    if((__int128)a.F * b.S < (__int128)a.S * b.F) return a;
    else return b;
}

// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
// Pode usar a seguinte funcao para indexar os nohs:
// f(l, r) = (l+r)|(l!=r), usando 2N de memoria
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

namespace seg {
	pll seg[4*MAX];
	int n, *v;

    pll junta(pll a1, pll a2) {
        return {a1.F + a2.F, a1.S + a2.S};
    }

	pll build(int p, int l, int r) {
		if (l == r) return seg[p] = {0, 0};
		int m = (l+r)/2;
		return seg[p] = junta(build(2*p, l, m), build(2*p+1, m+1, r));
	}

	void build(int n2) {
		n = n2;
		build(1, 0, n-1);
	}
    
    pll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {0, 0};
		int m = (l+r)/2;
		return junta(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}

	pll update(int a, pll x, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= a) {
			return seg[p];
		}
		if (a < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = junta(update(a, x, 2*p, l, m),
			update(a, x, 2*p+1, m+1, r));
	}

    void ativa(int x, int sig) {
        int pos = lower_bound(all(ord), make_pair(h[x], x)) - ord.begin();
        int si = (K / h[x]);
        update(pos, {sig * si, sig * si * h[x]});
    }

    // Se tiver uma seg de soma sobre um array nao negativo v, da pra
    // descobrir em O(log(n)) o maior j tal que v[i]+v[i+1]+...+v[j-1] < val
    int lower_bound(int i, pll& val, int p, int l, int r) {
        if (r < i) return n;
        if (i <= l and seg[p] < val) {
            val = junta(val, {-seg[p].F, -seg[p].S});
            return n;
        }
        if (l == r) return l;
        int m = (l+r)/2;
        int x = lower_bound(i, val, 2*p, l, m);
        if (x != n) return x;
        return lower_bound(i, val, 2*p+1, m+1, r);
    }

	ll query_problem() {
        pll val = {(ll)S, -1LL};
        int j = lower_bound(0, val, 1, 0, n-1);
        if(j == n) return LINF;

        auto [s, sh] = query(0, j - 1);
        auto [s_nxt, sh_nxt] = query(0, j);
        ll h = sh_nxt / s_nxt;

        return (S - s) * h + sh;
    }
};


void solve(){
    cin >> n >> S >> K;

    for(int i = 1; i <= n; i++) {
        cin >> h[i] >> l[i] >> u[i];
        ord.push_back({h[i], i});
        act.push_back(i);
        act.push_back(-i);
    }

    sort(all(h));
    sort(all(act), comp);

    seg::build(n + 1);

    pll tot = {LINF, 1};
    for(auto x : act) {
        if(x > 0) seg::ativa(x, 1);
        else {
            seg::ativa(-x, -1);
            continue;
        }

        pll c = {l[x] / __gcd(l[x], h[x]), h[x] / __gcd(l[x], h[x])};
        pll ans = {seg::query_problem(), 1};

        ans = {c.F * ans.F, c.S * ans.S};
        ll mdc = __gcd(ans.F, ans.S);
        ans = {ans.F / mdc, ans.S / mdc};

        tot = min_frac(tot, ans);
    }

    if(tot.first == LINF) cout << "*\n";
    else cout << tot.F << ' ' << tot.S << '\n';
}

signed main() { _
    solve();
    return 0;
}