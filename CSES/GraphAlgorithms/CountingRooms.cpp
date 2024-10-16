#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e3+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;

char tab[maxn][maxn];
int check[maxn][maxn];
int n, m; 

void dfs(int i, int j){
    if(check[i][j] == 0) return; 
    check[i][j] = 0;
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}
 
void solve(){
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> tab[i][j];
            if(tab[i][j] == '.') check[i][j] = 1;
        }
    }

    int total = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(check[i][j] == 1){
                total++;
                dfs(i, j);
            }
        }
    }

    cout << total << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}