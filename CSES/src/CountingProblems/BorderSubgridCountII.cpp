#include <bits/stdc++.h>
using namespace std; 
 
#define bug(x) cout << #x << " " << x << endl;
 
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
 
using vi = vector<int>; 
using pii = pair<int, int>; 
using ll = long long;
 
const int maxn = 500; 
const int alpha = 26; 
int mat[maxn][maxn], h[maxn]; 
 
void solve(){
    int n, k; cin >> n >> k; 
    FOR(i, 0, n) FOR(j, 0, n){
        char c; cin >> c; 
        mat[i][j] = c - 'A'; 
    } 
 
    vector<ll> ans(k); 
 
    FOR(i1, 0, n){
        FOR(i2, i1, n ){
            int cnt = 0; 
            FOR(j, 0, n){
                if( i2 == i1 || mat[i2][j] != mat[i2 - 1][j] ) h[j] = 0; 
                h[j]++; 
 
                if( j == 0 || mat[i1][j] != mat[i1][j - 1] || mat[i2][j] != mat[i2][j - 1] ) cnt = 0; 
                if( h[j] == i2 - i1 + 1 ) ans[mat[i1][j]] += ++cnt; 
            }
        }
    } 
 
    for( auto x : ans ) cout << x << '\n'; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}