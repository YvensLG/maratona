#include <bits/stdc++.h>
using namespace std; 
 
#define bug(x) cout << #x << " " << x << endl;
 
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).begin()
#define FOR(i, a, b) for(int i = a; i < b; i++)
 
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;
 
class PersistentSegtree{
    private:
 
    struct Node{
        ll sum; 
        int l, r;
        Node( ll sum = 0 ) : sum(sum), l(0), r(0) {}
        void merge( Node L, Node R ){
            sum = L.sum + R.sum; 
        }
    }; 
 
    Node *seg; 
    vi rt; 
    int MIN, MAX, id; 
 
    int create(){
        return id++; 
    }
 
    int copy( int node ){
        int cp = create(); 
        return seg[cp] = seg[node], cp; 
    }
 
    int update( int node, int ti, int tf, int id, int x ){
        int cp = copy(node); 
        if( ti == tf ){ 
            seg[cp].merge(seg[node], Node(x) ); 
            return cp; 
        }
 
        int tm = (ti + tf)>>1, &l = seg[cp].l, &r = seg[cp].r; 
        if( id <= tm ) l = update( seg[node].l, ti, tm, id, x );  
        else r = update( seg[node].r, tm + 1, tf, id, x );
 
        seg[cp].merge( seg[l], seg[r] ); 
        return cp; 
    }
 
    ll query( int n1, int n2, int ti, int tf, ll qi, ll qf ){
        if( qi > tf || ti > qf || n1 == n2 ) return 0; 
        if( qi <= ti && tf <= qf ) return seg[n2].sum - seg[n1].sum; 
        int tm = (ti + tf)>>1; 
        return query( seg[n1].l, seg[n2].l, ti, tm, qi, qf ) + query( seg[n1].r, seg[n2].r, tm + 1, tf, qi, qf ); 
    }
 
    public:
 
    PersistentSegtree( int n, int MIN, int MAX ) : MIN(MIN), MAX(MAX), rt(1), id(0) { 
        seg = new Node[n*__lg(MAX - MIN + 1) + 2*n];
        create();
    }
 
    void update( int id, int x ){
        rt.push_back(update(rt.back(), MIN, MAX, id, x ) ); 
    }
 
    ll query( int L, int R, ll D, ll U ){
        return query( rt[L], rt[R + 1], MIN, MAX, D, U ); 
    }
};
 
void solve(){
    int n, k; cin >> n >> k; 
    vector<pii> xs(n); 
    vi v(n); 
    FOR(i, 0, n){ cin >> v[i]; xs[i] = pii( v[i], i ); }
 
    PersistentSegtree seg(n, 0, n - 1);
 
    sort(all(xs)); 
    FOR(i, 0, n){
        v[i] = lower_bound(all(xs), pii(v[i], i)) - xs.begin();
        seg.update(v[i], 1); 
    }
    
    vi p(n); iota(all(p), 0); 
    stable_sort(all(p), [&]( int i, int j ){
        bool inv = (i > j); 
        if( i > j ) swap( i, j ); 
 
        if( v[i] < v[j] ) inv ^= true; 
        else inv ^= (seg.query( 0, j - 1, v[i] + 1, n - 1 ) >= k); 
        return inv;
    }); 
 
    FOR(i, 0, n) cout << xs[v[p[i]]].first << " "; cout << '\n'; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}