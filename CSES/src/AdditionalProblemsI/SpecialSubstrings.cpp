#include <bits/stdc++.h>
using namespace std; 
 
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
 
using ll = long long; 
using pii = pair<int, int>; 
using vi = vector<int>; 
 
const int mod = 1e9 + 7;
const int b1 = 2e6 + 39;
const int b2 = 2e6 + 3; 
 
 
int sum( int a, int b ){
    return ((a + b)%mod + mod)%mod; 
}
 
int prod( int a, int b ){
    return (1LL*a*b)%mod; 
}
 
void solve(){
    string s; cin >> s; 
 
    string letras = s; 
    sort( all(letras) ); 
    letras.erase( unique(all(letras)), letras.end() ); 
 
    vi p1(sz(letras), 1), p2(sz(letras), 1); 
 
    int h1 = 0, h2 = 0; 
    for( int i = 0; i + 1 < sz(letras); i++ ){
        p1[i + 1] = prod( p1[i], b1 ); 
        p2[i + 1] = prod( p2[i], b2 );
        h1 = sum( h1, prod( sz(s), p1[i] ) );
        h2 = sum( h2, prod( sz(s), p2[i] ) ); 
    } 
 
    map<pii, int> cnt; 
    cnt[pii(h1, h2)]++; 
 
    ll ans = 0; 
    for( int i = 0; i < sz(s); i++ ){
        char c = s[i]; 
        int x = lower_bound( all(letras), c ) - letras.begin(); 
 
        if( x > 0 ){
            h1 = sum( h1, -p1[x - 1] ); 
            h2 = sum( h2, -p2[x - 1] ); 
        } 
        if( x + 1 < sz(letras) ){
            h1 = sum( h1, p1[x] ); 
            h2 = sum( h2, p2[x] ); 
        } 
 
        ans += cnt[pii( h1, h2 )]; 
        cnt[pii( h1, h2 )]++; 
    }
 
    cout << ans << "\n";
 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}