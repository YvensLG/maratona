#include <bits/stdc++.h>
using namespace std; 

const int inf = 2e9; 

using ll = long long;

void solve(){
    int n, q; cin >> n >> q; 
    vector<ll> a(n); 
    for( ll &x : a ) cin >> x; 
    vector<ll> l(n, -1), r(n, inf); 

    while( q-- ){
        ll p, L, R; cin >> p >> L >> R; 
        p--; 
        l[p] = max( l[p], L ); 
        r[p] = min( r[p], R ); 
    }

    ll ans = 0; 
    for( int i = 0; i < n; i++ ){
        if( l[i] > r[i] ){ cout << -1 << endl; return; }
        if( a[i] < l[i] ) ans += l[i] - a[i]; 
        else if( a[i] > r[i] ) ans += a[i] - r[i]; 
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t; 
    while( t-- ) solve(); 
}