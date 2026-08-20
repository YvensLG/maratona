#include <bits/stdc++.h>
using namespace std; 
 
#define bug(x) cout << #x << " " << x << endl;
 
/*
    k = prod p[i]**q[i]; 
 
    dp[n] = dp[n - 1] + q*dp[n - 2];
    dp[0] = 1; 
    dp[1] = q + 1
*/
using ll = long long; 
 
const int mod = 1e9 + 7; 
 
int sum( int a, int b ){
    return ((a + b)%mod + mod)%mod;  
}
 
int mult( int a, int b ){
    return (1LL*a*b)%mod; 
}
 
template<class T, int N> struct Matrix{
    typedef Matrix M; 
    array<array<T, N>, N> d{};
    M operator * ( const M& m ) const {
        M a; 
        for( int i = 0; i < N; i++ ) for( int j = 0; j < N; j++ )
            for( int k = 0; k < N; k++ ) a.d[i][j] = sum( a.d[i][j], mult( d[i][k], m.d[k][j] ) ); 
        return a; 
    }
    array<T, N> operator*( const array<T, N>& vec ) const{
        array<T, N> ret{};
        for( int i = 0; i < N; i++ ) for( int j = 0; j < N; j++ ) ret[i] = sum( ret[i], mult( d[i][j], vec[j] ) ); 
        return ret; 
    }
    M operator ^ ( ll p ) const {
        assert(p >= 0); 
        M a, b(*this); 
        for( int i = 0; i < N; i++ ) a.d[i][i] = 1; 
        for(;p; p >>= 1){
            if( p&1 ) a = a*b; 
            b = b*b; 
        }
        return a; 
    }
};
 
int solve( int n, int q ){
    Matrix<int, 2> base{ array<int, 2>{0, 1}, array<int, 2>{q, 1} }; 
    array<int, 2> dp{ 1, q + 1 }; 
 
    dp = (base^(n - 1))*dp; 
    return dp[1]; 
}
 
void solve(){
    int n, k; cin >> n >> k; 
 
    int ans = 1; 
    for( int p = 2; p*p <= k; p++ ){
        if( k%p != 0 ) continue; 
        int q = 0; 
        while( k%p == 0 ){
            q++; 
            k /= p; 
        }
 
        ans = mult( ans, solve(n, q) ); 
    }
    if( k > 1 ) ans = mult( ans, solve(n, 1)); 
 
    cout << ans << "\n"; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t; while( t-- )
        solve(); 
}
