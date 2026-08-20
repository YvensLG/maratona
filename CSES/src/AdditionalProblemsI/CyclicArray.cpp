#include <bits/stdc++.h>
using namespace std; 
 
using ll = long long;
 
const int maxn = 4e5 + 10; 
const int logn = 20; 
 
int v[maxn], jmp[logn][maxn];
 
int query( int l, int r ){
    int ans = 0; 
    for( int i = logn - 1; i >= 0; i-- ) if( jmp[i][l] < r ) ans += (1<<i), l = jmp[i][l]; 
    return ans + 1; 
}
 
void solve(){
    int n; ll k; cin >> n >> k; 
    for( int i = 0; i < n; i++ ){ cin >> v[i]; v[i + n] = v[i]; }
 
    for( ll i = 0, j = 0, sum = 0; i < 2*n; sum -= v[i++] ){
        while( j < 2*n && sum + v[j] <= k ) sum += v[j++]; 
        jmp[0][i] = j; 
    }
 
    jmp[0][2*n] = 2*n; 
 
    for( int i = 1; i < logn; i++ )
        for( int j = 0; j <= 2*n; j++ ) jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
 
    int ans = n; 
    for( int i = 0; i < n; i++ ) ans = min( ans, query( i, i + n ) ); 
    cout << ans << '\n'; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    solve(); 
}