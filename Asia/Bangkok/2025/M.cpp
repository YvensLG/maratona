#include <bits/stdc++.h>

using namespace std;

struct BIT{
    vector<int> bit; 
    int n; 
    BIT( int n ) : n(n), bit(n) {
        for( int i = 0; i < n; i++ ) update( i, 1 ); 
    }

    void update( int i, int x ){
        for(i++; i - 1 < bit.size(); i += i&-i ) bit[i - 1] += x; 
    }

    int query( int i ){
        int ans = 0; 
        for(i++; i > 0; i -= i&-i ) ans += bit[i - 1]; 
        return ans;
    }

    int query( int l, int r ){
        if( l > r ) return query(0, r) + query(l, n - 1);
        return query(r) - query(l - 1);
    }
};

void solve(){
    int n; cin >> n; 
    vector<int> pos(n); 
    for( int i = 0; i < n; i++ ){
        int x; cin >> x; x--; 
        pos[x] = i; 
    } 

    BIT bit(n); 
    int cur = n - 1; 

    vector<int> ans; 
    for( int i = n - 1; i >= 0; i-- ){
        ans.push_back(bit.query(pos[i], cur)); 
        cur = pos[i]; 
        bit.update( pos[i], -1 ); 
    }

    reverse( ans.begin(), ans.end() ); 
    for( int x : ans ) cout << x << " "; cout << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    // int t; cin >> t; 
    // while( t-- ) 
        solve(); 
    return 0;
}
