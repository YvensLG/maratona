#include <bits/stdc++.h>
using namespace std; 
 
#define FOR(i, a, b) for( int i = a; i < b; i++ )
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define bug(x) cout << #x << " " << x << endl;
 
using vi = vector<int>;
using pii = pair<int, int>; 
using ll = long long;
 
const int maxn = 2e5; 
const int inf = 2e9; 
 
struct Segtree{
    pii *seg; 
    int n; 
    Segtree( int n ) : n(n), seg(new pii[4*n]){
        fill(seg, seg + 4*n, pii(inf, -1));
    }
 
    void update( int node, int ti, int tf, int id, pii p ){
        if( ti == tf ){ seg[node] = p; return; }
        int l = 2*node, r = 2*node + 1, tm = (ti + tf)/2; 
        if( id <= tm )  update( l, ti, tm, id, p ); 
        else            update( r, tm + 1, tf, id, p ); 
        seg[node] = min( seg[l], seg[r] ); 
    }
 
    void update( int id, pii p ){
        update( 1, 0, n - 1, id, p ); 
    }
 
    pii query( int node, int ti, int tf, int qi, int qf ){
        if( qi > tf || ti > qf ) return pii( inf, -1 ); 
        if( qi <= ti && tf <= qf ) return seg[node]; 
        int l = 2*node, r = 2*node + 1, tm = (ti + tf)/2; 
        return min(query( l, ti, tm, qi, qf ), query( r, tm + 1, tf, qi, qf ));
    }
 
    pii query( int l, int r ){
        return query( 1, 0, n - 1, l, r ); 
    }
}; 
 
bool check( vector<pii> &v ){
    reverse(all(v)); 
    stack<pii> s; 
 
    for( auto [L, R] : v ){
        while( !s.empty() && s.top().second < R ) s.pop(); 
        if( !s.empty() && s.top().first < R ) return false; 
        s.push({ L, R });
    }
    return true; 
}
 
void solve(){
    int n; cin >> n; 
    vi v(n), in(n), out(n), marc(n, -1); 
    int cur = 0, t = 0; 
    FOR(i, 0, n){
        cin >> v[i]; 
        marc[--v[i]] = i; 
 
        in[i] = t++; 
        while( cur < n && marc[cur] != -1 ) out[marc[cur++]] = t++;
    }
 
    Segtree ins(t), outs(t);
    FOR(i, 0, n){
        ins.update( out[i], pii(in[i], i) ); 
        outs.update( in[i], pii(-out[i], i) ); 
    }
    
    fill(all(marc), -1);
    vector<pii> choices[2]; 
    vi ans(n);
    FOR(i, 0, n){
        if( marc[i] == -1 ){
            queue<int> q; 
            marc[i] = 0; 
            for(q.push(i); !q.empty(); q.pop()){
                int j = q.front(); 
    
                // Olhar seg dos ins
                for( auto [IN, k] = ins.query(in[j] + 1, out[j] - 1);
                    IN < in[j];
                    tie(IN, k) = ins.query(in[j] + 1, out[j] - 1) ){
    
                    q.push(k); 
                    marc[k] = !marc[j];
    
                    ins.update( out[k], pii(inf, -1) ); 
                    outs.update( in[k], pii(inf, -1) );
                }
    
                // Olhar seg dos outs
                for( auto [OUT, k] = outs.query(in[j] + 1, out[j] - 1);
                    out[j] < -OUT;
                    tie(OUT, k) = outs.query(in[j] + 1, out[j] - 1) ){
    
                    q.push(k); 
                    marc[k] = !marc[j];
    
                    ins.update( out[k], pii(inf, -1) ); 
                    outs.update( in[k], pii(inf, -1) );
                }
            }
        }
        choices[marc[i]].push_back({ in[i], out[i] });
        ans[i] = marc[i] + 1;
    } 
 
    if( !check( choices[0] ) || !check( choices[1] ) ){ cout << "IMPOSSIBLE\n"; return; }
    for( int x : ans ) cout << x << " "; cout << '\n'; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}
