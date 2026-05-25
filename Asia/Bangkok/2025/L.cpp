#include <bits/stdc++.h>

using namespace std;

#define int long long

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll inf = 3e18 + 10;

class Segtree{
    private:
    vector<ll> seg; 
    int n; 

    void update( int node, int ini, int fim, int id, ll val ){
        if( ini > id || id > fim ) return; 
        if( ini == fim ){ seg[node] = min( seg[node], val ); return; }
        
        int l = 2*node, r = 2*node + 1, mid = ( ini + fim )/2; 
        update( l, ini, mid, id, val ); 
        update( r, mid + 1, fim, id, val ); 
        seg[node] = min( seg[l], seg[r] ); 
    }   

    ll query( int node, int ini, int fim, int qi, int qf ){
        if( qi > fim || ini > qf ) return inf; 
        if( qi <= ini && fim <= qf ) return seg[node]; 
        int l = 2*node, r = 2*node + 1, mid = ( ini + fim )/2; 
        return min( query( l, ini, mid, qi, qf ),
                    query( r, mid + 1, fim, qi, qf ) );
    }

    public:
    Segtree( int n ) : n(n), seg( 4*n, inf ) {} 

    void update( int id, ll val ){
        update( 1, 0, n - 1, id, val ); 
    }

    ll query( int l, int r ){
        return query( 1, 0, n - 1, l, r ); 
    }

    void reset(){
        fill( seg.begin(), seg.end(), inf ); 
    }
};

void solve() {
    int n, Q, A, B; cin >> n >> Q >> A >> B;
    
    swap(A, B);

    vector<tuple<int, int, ll>> a(n);
    for (auto&[x, y, z] : a) {
        cin >> x >> y >> z;
    }
    sort(all(a));

    vector<tuple<int, int, int>> q(Q);
    for (int i = 0; i < Q; ++i) {
        int x, y; cin >> x >> y;
        q[i] = make_tuple(x, y, i);
    }
    sort(all(q));

    vector<ll> ans(Q, inf);

    vi o;
    o.reserve(n + Q);
    for (auto [x, y, z] : a) {
        o.push_back(y);
    }
    for (auto [x, y, z] : q) {
        o.push_back(y);
    }
    sort(all(o));
    o.erase(unique(all(o)), end(o));

    map<int, int> mp;
    for (int i = 0; i < sz(o); ++i) {
        mp[o[i]] = i;
    }

    Segtree leg(sz(o)), reg(sz(o));

    int p = 0;
    for (auto [x, y, z] : q) {        
        while (p < sz(a) && (get<0>(a[p])) <= x) {
            auto [vx, vy, vz] = a[p];
            int k = mp[vy];
            ll lval = (ll) vy * (-A) + (ll) vx * (-B) + vz;
            ll rval = (ll) vy * ( A) + (ll) vx * (-B) + vz;
            leg.update(k, lval);
            reg.update(k, rval);
            ++p;
        }
        int k = mp[y];
        ans[z] = min({
            ans[z],
            (ll) y * ( A) + (ll) x * ( B) + leg.query(0, k),
            (ll) y * (-A) + (ll) x * ( B) + reg.query(k, sz(o) - 1),
        });
    }

    leg.reset();
    reg.reset();

    reverse(all(a));
    reverse(all(q));

    p = 0;
    for (auto [x, y, z] : q) {
        int vx = -1;
        while (p < sz(a) && (get<0>(a[p])) >= x) {
            auto [vx, vy, vz] = a[p];
            int k = mp[vy];
            ll lval = (ll) vy * (-A) + (ll) vx * ( B) + vz;
            ll rval = (ll) vy * ( A) + (ll) vx * ( B) + vz;
            leg.update(k, lval);
            reg.update(k, rval);
            ++p;
        }
        int k = mp[y];
        ans[z] = min({
            ans[z],
            (ll) y * ( A) + (ll) x * (-B) + leg.query(0, k),
            (ll) y * (-A) + (ll) x * (-B) + reg.query(k, sz(o) - 1),
        });
    }

    for (int i = 0; i < Q; ++i) {
        cout << ans[i] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 

    solve();

    return 0;
}
