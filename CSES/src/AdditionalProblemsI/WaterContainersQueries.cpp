#include <bits/stdc++.h>
using namespace std; 
 
void solve(){
    int a, b, x; cin >> a >> b >> x; 
    cout << ((x <= a && x%__gcd(a, b) == 0) ? "YES" : "NO" ) << '\n'; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t; while( t-- )
        solve(); 
}
