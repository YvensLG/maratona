#include <bits/stdc++.h>
using namespace std; 
 
#define all(x) (x).begin(),(x).end()
 
using ll = long long; 
using vll = vector<ll>; 
using vi = vector<int>; 
 
struct BIT{
    int *bit; 
    int n; 
    BIT( int n ) : n(n), bit(new int[n]) {}
    void update( int i, int x ){
        for(i++; i - 1 < n; i += i&-i ) bit[i - 1] += x; 
    }
 
    int query( int i ){
        int ans = 0; 
        for(i++; i - 1 >= 0; i -= i&-i ) ans += bit[i - 1]; 
        return ans; 
    }
 
    int query( int l, int r ){
        return query(r) - query(l - 1); 
    }
 
    void reset(){
        fill( bit, bit + n, 0 ); 
    }
};
 
void solve(){
    int n; cin >> n; 
    vi v(n); 
    for( int &x : v ) cin >> x; 
 
    vi o = v; 
    sort( all(o) ); 
 
    BIT bit(n); 
 
    vll pref(n), suf(n); 
    for( int i = 0; i < n; i++ ){
        v[i] = lower_bound( all(o), v[i] ) - o.begin();
 
        pref[i] += bit.query( v[i], n - 1 ); 
        bit.update( v[i], 1 ); 
    }
 
    ll ans = 0; 
 
    bit.reset();
    for( int i = n - 1; i >= 0; i-- ){
        suf[i] += bit.query( v[i], n - 1 ); 
        bit.update( v[i], 1 ); 
 
        ans += min( pref[i], suf[i] ); 
    }
    
    cout << ans << "\n";
    
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}