#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>; 
#define bug(x) cout << #x << " " << x << endl;
const int inf = 1e9; 
const int maxx = 1e5 + 10; 

struct BIT{
    vector<pii> bit; 
    int n; 
    BIT( int n ) : n(n), bit(n, pii(inf, -1)) {}

    void update( int i, pii x ){
        for(i++; i - 1 < bit.size(); i += i&-i ) bit[i - 1] = min( bit[i - 1], x ); 
    }

    pii query( int i ){
        pii ans(inf, -1); 
        for(i++; i > 0; i -= i&-i ) ans = min( ans, bit[i - 1] ); 
        return ans;
    }

    void reset(){
        fill( bit.begin(), bit.end(), pii( inf, -1 ) );
    }
};

const int maxn = 5e4 + 10; 
const int raizn = 450; 
pii dp[raizn][maxn];

void solve(){
    int n; cin >> n; 
    vector<int> v(n); 
    for( int &x : v ) cin >> x; 

    BIT bit(maxx);
    bit.update( 0, pii( 0, -1 ) ); 

    for( int j = 0; j < raizn; j++ )
    for( int i = 0; i < maxn; i++ )
        dp[j][i] = pii( inf, -1 ); 

    int ans = 0; 
    int opt = -1; 
    bool ok = true; 
    while( ok ){
        ok = false; 
        for( int i = 0; i < n; i++ ){
            if( i && ans ) bit.update( ((ans == 1) ? 0 : dp[ans][i - 1].first) + v[i - 1], pii( -v[i - 1], i - 1 ) );
            
            auto [x, j] = bit.query( v[i] - 1 ); 

            if( x == inf ) continue; 
            ok = true; 
            dp[ans + 1][i] = pii( v[i] + x, j );
            opt = i; 
        }
        if( ok ) ans++;
        bit.reset(); 
    }

    cout << ans << endl;
    vector<int> resp; 
    while( opt >= 0 && ans > 0 ){
        resp.push_back(opt); 
        opt = dp[ans--][opt].second;
    } 

    reverse( resp.begin(), resp.end() ); 
    for( int x : resp ) cout << x + 1 << " "; cout << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    // int t; cin >> t; 
    // while( t-- ) 
        solve(); 
    return 0;
}
