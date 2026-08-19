#include <bits/stdc++.h>
using namespace std; 
 
#define bug(x) cout << #x << " " << x << endl;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define FOR(i, a, b) for( int i = a; i < b; i++ )
 
using vi = vector<int>; 
using ll = long long;
using pii = pair<int, int>; 
 
struct LichaoTree{
    struct Line{
        ll a, b; Line( ll a = 0, ll b = 0 ) : a(a), b(b) {}
        ll f(ll x){ return a*x + b; }
    }; 
 
    Line *t; 
    int n; 
 
    LichaoTree( int n ) : n(n), t(new Line[4*n]){}
 
    void update( int node, int ti, int tf, Line line ){
        int l = 2*node, r = 2*node + 1, tm = (ti + tf)/2; 
        if( t[node].f(tm) < line.f(tm) ) swap( line, t[node] ); 
        if( ti == tf ) return; 
 
        if( t[node].f(ti) < line.f(ti) ) update( l, ti, tm, line ); 
        else update( r, tm + 1, tf, line ); 
    }
 
    void update( int node, int ti, int tf, int qi, int qf, Line line ){
        if( qi > tf || ti > qf ) return; 
        if( qi <= ti && tf <= qf ){ update( node, ti, tf, line ); return; }
        int l = 2*node, r = 2*node + 1, tm = (ti + tf)/2; 
        update( l, ti, tm, qi, qf, line ); update( r, tm + 1, tf, qi, qf, line ); 
    }
 
    void insert( int l, int r, ll a, ll b ){
        update( 1, 0, n - 1, l, r, Line( a, b ) ); 
    }
 
    ll query( int node, int ti, int tf, int id ){
        ll ans = t[node].f(id); 
        if( ti == tf ) return ans; 
        int l = 2*node, r = 2*node + 1, tm = (ti + tf)/2; 
        if( id <= tm ) return max( query( l, ti, tm, id ), ans ); 
        return max( query( r, tm + 1, tf, id ), ans ); 
    }
 
    ll query( int x ){ 
        return query( 1, 0, n - 1, x ); 
    }
};
 
/*
    Considere a window [i, i + k - 1] e o indice j
 
    Caso 1: i <= l[j] && r[j] <= i + k - 1
 
        Ou seja, r[j] - k + 1 <= i <= l[j]
        Adicionar reta 0*i + v[j]*(r[j] - l[j] - 1)
 
    Caso 2: l[j] < i && i + k - 1 < r[j]
 
        Ou seja, l[j] + 1 <= i <= r[j] - k
        Adicionar reta 0*i + v[j]*k
 
    Caso 3: l[j] < i <= j && r[j] <= i + k - 1 
 
        Ou seja, max( l[j] + 1, r[j] - k + 1 ) <= i <= j 
        Adicionar a reta -v[j]*i + v[j]*r[j]
 
    Caso 4: i <= l[j] && j <= i + k - 1 < r[j]
 
        Ou seja, j - k + 1 <= i <= min( l[j], r[j] - k )
        Adicionar reta v[j]*i + v[j]*(k - 1 - l[j])
*/
 
void solve(){
    int n, k; cin >> n >> k;    
    vi l(n, -1), r(n, n), v(n); 
    stack<pii> s; s.push({ -1, -1 }); 
    FOR(i, 0, n){
        cin >> v[i]; 
        for(; s.top().first >= v[i]; s.pop() ) r[s.top().second] = i; 
        l[i] = s.top().second; 
        s.push({ v[i], i });
    }
 
    LichaoTree t(n); 
    FOR(j, 0, n){
        t.insert(r[j] - k + 1, l[j], 0, 1LL*v[j]*(r[j] - l[j] - 1) ); 
        t.insert(l[j] + 1, r[j] - k, 0, 1LL*v[j]*k );
        t.insert(max(l[j] + 1, r[j] - k + 1), j, -v[j], 1LL*v[j]*r[j] ); 
        t.insert(j - k + 1, min(l[j], r[j] - k), v[j], 1LL*v[j]*(k - 1 - l[j]) );
    }
 
    FOR(i, 0, n - k + 1) cout << t.query(i) << " "; cout << '\n'; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}