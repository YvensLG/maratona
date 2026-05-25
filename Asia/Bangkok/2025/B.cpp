#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n >> m; 

    if( n == 2 ){
        if( m%2 == 0 ) cout << "1 2" << endl; 
        else cout << "2 1" << endl;
        return;
    }

    m = min( m, n ); 
    for( int i = n; i > n - m; i-- ) cout << i << " "; 
    for( int i = 1; i <= n - m; i++ ) cout << i << " "; 
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t; 
    while( t-- ) solve(); 
    return 0;
}
