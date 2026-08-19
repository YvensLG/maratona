#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define int long long
#define pb push_back
 
const int maxn = 2e6+6, m = 6, mod = 1e9+7;
 
int base[m][m] = {
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, -1},
    {0, 0, 0, 1, -1, 0},
    {0, 0, 1, -1, 0, 0},
    {0, 1, -1, 0, 0, 0}
};
 
int multiplicador[m][m] = {
    {1, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0}
};
 
void mult(int a[m][m], int b[m][m]){
    int c[m][m];
 
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            c[i][j] = 0;
            for(int k=0; k<m; k++){
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
 
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            a[i][j] = c[i][j];
}
 
void fexp(int a[m][m], int exp){
    if(exp == 0){
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                if(i == j) a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        return;
    }
    if(exp == 1) return;
 
    int b[m][m];
    if(exp % 2 == 1)
        for(int i=0; i<m; i++) for(int j=0; j<m; j++) b[i][j] = a[i][j];
 
    fexp(a, exp / 2);
    mult(a, a);
 
    if(exp % 2 == 1) mult(a, b);
}
 
void solve() {
    int n; cin >> n;
    fexp(multiplicador, n);
    mult(base, multiplicador);
    cout << base[0][0] << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}
