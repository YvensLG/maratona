#include <bits/stdc++.h>
using namespace std; 
 
using pii = pair<int, int>; 
using vi = vector<int>; 
 
void solve(){
    int n; cin >> n; 
    vector<pii> v(n); 
    for( int i = 0; i < n; i++ ){ cin >> v[i].first; v[i].second = i; }
    sort( v.rbegin(), v.rend() ); 
 
    int ans = 0, invs = 0, p = n - 1; 
 
    vi marc(n); 
    for( auto [_, i] : v ){
        marc[i] = true; 
        if( i <= p ) invs++; 
        while( p >= 0 && marc[p] ){ invs--; p--; }
        ans = max( ans, invs ); 
    }
 
    cout << ans << '\n'; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}
