#include <bits/stdc++.h>
using namespace std; 

void solve(){
    int n; cin >> n; 
    vector<int> v(n); 
    for( int &x : v ) cin >> x; 
    sort( v.begin(), v.end() ); 

    auto dist = [&]( int a, int b ){
        return abs( a - b ); 
    };

    auto get_ans = [&]( int l, int r, int i ){
        int ans = min( dist( l, i ) + 1, dist(r, i) )*2;
        ans = max( ans, min( dist(l, i), dist(r, i) )*2 + 1);
        return ans; 
    };

    int ans = 1; 
    for( int i = 0; i < n; i++ ){
        for( int j = i + 1; j < n; j++ ){
            if( (v[i] + v[j])%2 != 0 ) continue; 
            int median = (v[i] + v[j])/2; 
            int l = lower_bound( v.begin(), v.end(), median ) - v.begin(); 
            int r = upper_bound( v.begin(), v.end(), median ) - v.begin() - 1;
            l = max( l, i ); 
            r = min( r, j ); 
            
            if( v[l] != median ) continue; 
            
            int cur_ans = max( get_ans( i, j, l ), get_ans( i, j, r ) ); 

            int k = ( i + j )/2; 
            if( v[k] == median ) cur_ans = max( cur_ans, get_ans( i, j, k ) ); 
            ans = max( ans, cur_ans ); 
        }
    }

    cout << ans << endl;
}

int main(){
    int t; cin >> t; 
    while( t-- ) solve();    
}