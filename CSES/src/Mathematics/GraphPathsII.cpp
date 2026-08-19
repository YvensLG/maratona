#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define int long long
#define pb push_back
 
const int maxn = 2e6+6, n = 101, mod = 1e9+7, inf = 9e18;
 
int grafo[n][n];
 
void mult(int a[n][n], int b[n][n]){
    int c[n][n];
 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            c[i][j] = inf;
            for(int k=0; k<n; k++){
                if(a[i][k] == 0 || b[k][j] == 0) continue;
                c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
            }
            if(c[i][j] == inf) c[i][j] = 0;
        }
    }
 
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j] = c[i][j];
}
 
void fexp(int a[n][n], int exp){
    if(exp == 0){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        return;
    }
    if(exp == 1) return;
 
    int b[n][n];
    if(exp % 2 == 1)
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) b[i][j] = a[i][j];
 
    fexp(a, exp / 2);
    mult(a, a);
 
    if(exp % 2 == 1) mult(a, b);
}
 
void solve() {
    int n1, m, k; cin >> n1 >> m >> k;
 
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        int peso; cin >> peso;
        if(grafo[a][b] == 0) grafo[a][b] = inf;
        
        grafo[a][b] = min(grafo[a][b], peso);
    }
 
    fexp(grafo, k);
 
    if(grafo[1][n1] == 0) cout << "-1\n";
    else cout << grafo[1][n1] << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // int t; cin >> t; while(t--)
    solve();
 
    return 0;
}