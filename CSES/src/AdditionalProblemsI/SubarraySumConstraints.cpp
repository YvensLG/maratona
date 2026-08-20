#include <bits/stdc++.h>
using namespace std; 
 
using ll = long long;
using vi = vector<int>; 
using pii = pair<ll, ll>;
 
const ll inf = 1e15;
 
struct UnionFind{
    int *p, *sz; 
    ll *w; 
 
    UnionFind( int n ) : p(new int[n]), sz(new int[n]), w(new ll[n]){
        iota( p, p + n, 0 ); fill( sz, sz + n, 1 ); 
    }
 
    int find( int u ){
        while( u != p[u] ) u = p[u]; 
        return u; 
    }
 
    ll cost( int u ){
        ll ans = 0; 
        while( u != p[u] ){ ans += w[u]; u = p[u]; }
        return ans; 
    }
 
    bool join( int u, int v, ll val ){
        ll wu = cost(u);
        ll wv = cost(v); 
 
        u = find(u); v = find(v); 
        if( u == v ) return wu - wv == val; 
 
        if( sz[u] < sz[v] ) val = -val, swap( u, v ), swap( wu, wv ); 
 
        p[v] = u;
        w[v] = wu - wv - val; 
        sz[u] += sz[v]; 
        return true; 
    }
}; 
 
struct InequationSystem{
    vector<vector<pii>> adj; 
    vector<ll> ans;
    InequationSystem( int n ) : adj(n), ans(n, LLONG_MAX) {}
    void add( int x1, int x2, ll y ){ // Adicionar inequacao x1 <= x2 + y
        adj[x2].push_back({ x1, y }); 
    }
 
    void solve( int x0, ll v0 ){
        ans[x0] = v0; 
        bool done = false; 
        while( !done ){
            done = true; 
            for( int u = 0; u < adj.size(); u++ ) 
                for( auto [v, w] : adj[u] ) if( ans[v] > ans[u] + w ) ans[v] = ans[u] + w, done = false; 
        }
    }
};
 
void solve(){
    int n, m; cin >> n >> m; 
    UnionFind dsu(n + 1); 
 
    while( m-- ){
        int l, r, x; cin >> l >> r >> x; 
        if( !dsu.join( l - 1, r, x ) ){ cout << "NO\n"; return; }
    }
 
    InequationSystem system(n + 1); 
    for( int i = 0; i <= n; i++ ){
        if( dsu.p[i] != i ){
            system.add( i, dsu.p[i], -dsu.w[i] ); 
            system.add( dsu.p[i], i, dsu.w[i] ); 
        }
        if( i + 1 <= n ){
            system.add( i + 1, i, inf ); 
            system.add( i, i + 1, inf ); 
        }
    }
 
    system.solve( 0, 0 ); 
    cout << "YES\n"; 
    for( int i = 1; i <= n; i++ ) cout << system.ans[i] - system.ans[i - 1] << " "; cout << "\n";  
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}