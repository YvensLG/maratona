#include <bits/stdc++.h>
using namespace std; 
 
#define all(x) (x).begin(),(x).end()
 
using ld = long double;
using vi = vector<int>;
 
const ld inf = 1e9; 
const int loginf = 60; 
 
pair<ld, int> solve( vector<ld> &v, ld x ){
    int n = v.size();
    ld dp = -inf; 
    int len = 0; 
    for( auto val : v ){
        if( dp < 0 ) dp = 0, len = 0; 
        dp += val - x; 
        len++; 
    }
 
    return make_pair( dp, len ); 
}
 
ld bs( vector<ld> &a, vector<ld> &b ){
    ld l = 0, r = inf;  
    for( int i = 0; i < loginf; i++ ){
        ld m = (l + r)/2; 
        auto [dpA, lenA] = solve( a, m ); 
        auto [dpB, lenB] = solve( b, m ); 
        if( dpA + dpB >= 0 ) l = m; 
        else r = m; 
    }
    return r; 
}
 
void solve(){
    int n; cin >> n; 
    vector<ld> a(n), b(n); 
    for( auto &x : a ) cin >> x; 
    for( auto &x : b ) cin >> x; 
 
    reverse( all(a) );
    reverse( all(b) ); 
 
    ld ans = bs( a, b ); 
 
    auto [dpA, lenA] = solve( a, ans );
    auto [dpB, lenB] = solve( b, ans ); 
 
    cout << lenA << " " << lenB << "\n"; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}