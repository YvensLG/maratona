#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

const int MOD = 998244353;
const int MAX = 524288;

int p[MAX], grundy[MAX];
int n, k, r;

class Segtree{
    private:
    vector<ll> seg; 
    int n; 

    void update( int node, int ini, int fim, int id, ll val ){
        if( ini > id || id > fim ) return; 
        if( ini == fim ){ seg[node] = val; return; }
        
        int l = 2*node, r = 2*node + 1, mid = ( ini + fim )/2; 
        update( l, ini, mid, id, val ); 
        update( r, mid + 1, fim, id, val ); 
        seg[node] = min( seg[l], seg[r] ); 
    }   

    int find_mex(int node, int ini, int fim, int limit) {
        if (ini == fim) return ini;
        int l = 2*node, r = 2*node + 1, mid = ( ini + fim ) /2; 
        
        if (seg[l] < limit) return find_mex(l, ini, mid, limit);
        else return find_mex(r, mid + 1, fim, limit);
    }

    public:
    Segtree( int n ) : n(n), seg( 4*n, -1 ) {} 

    void update( int id, ll val ){
        update( 1, 0, n - 1, id, val ); 
    }

    int find_mex(int limit) {
        return find_mex(1, 0, n - 1, limit);
    }
};

// grundy[i] = MEX(grundy[i - 1], ..., grundy[i - p[i]])
void calc_grundy() {
    Segtree seg(n + 1);
    grundy[0] = 0;
    seg.update(grundy[0], 0);

    for(int i = 1; i <= n; i++) {
        int at = i - p[i];
        grundy[i] = seg.find_mex(at);
        seg.update(grundy[i], i);
    }
}

ll fexp(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % MOD, e /= 2)
		if (e & 1) ans = ans * b % MOD;
	return ans;
}

void FST(vi& a, bool inv) {
    int n = sz(a);
	for (int step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			int u = a[j];
            int v = a[j + step];
            a[j] = (u + v) % MOD;
            a[j + step] = (u - v + MOD) % MOD;
		}
	}
    if (inv) {
        ll inv_n = fexp(n, MOD - 2);
        for (int& x : a) x = (x * inv_n) % MOD;
    }
}

void solve() {
    cin >> n >> k >> r;
    for(int i = 1; i <= n; i++) cin >> p[i];
    calc_grundy();

    vector<int> a(MAX), b(MAX);

    for(int i = 0; i <= n; i++) {
        a[grundy[i]]++;
        if(i + k > n || grundy[i] == grundy[i + k])
            b[grundy[i]]++;
    }

    FST(a, 0); FST(b, 0);

    for(int i = 0; i < MAX; i++) {
        a[i] = fexp(a[i], r);
        b[i] = fexp(b[i], r);
    }

    FST(a, 1); FST(b, 1);

    cout << (a[0] - b[0] + MOD) % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
    return 0;
}
