#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define int long long
#define pb push_back
 
const int maxn = 2e6+6, mod = 1e9+7;
 
void multi(int a[2][2], int b[2][2]){
    int x1 = ( (a[0][0] * b[0][0]) % mod + (a[0][1] * b[1][0]) % mod ) % mod;
    int x2 = ( (a[0][0] * b[0][1]) % mod + (a[0][1] * b[1][1]) % mod ) % mod;
    int x3 = ( (a[1][0] * b[0][0]) % mod + (a[1][1] * b[1][0]) % mod ) % mod;
    int x4 = ( (a[1][0] * b[0][1]) % mod + (a[1][1] * b[1][1]) % mod ) % mod;
 
    a[0][0] = x1; a[0][1] = x2; a[1][0] = x3; a[1][1] = x4;
}
 
void fexp(int n[2][2], int exp){
    if(exp == 0){
        n[0][0] = 1; n[0][1] = 0; n[1][0] = 0; n[1][1] = 1;
        return;
    }
    if(exp == 1) return;
 
    int m[2][2] = {{n[0][0], n[0][1]}, {n[1][0], n[1][1]}};
    fexp(n, exp / 2);
    multi(n, n);
 
    if(exp % 2 == 1) multi(n, m);
}
 
void solve() {
    int n; cin >> n;
    int m[2][2] = {{1, 1}, {1, 0}};
    fexp(m, n);
    cout << m[0][1] << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // int t; cin >> t; while(t--)
    solve();
 
    return 0;
}