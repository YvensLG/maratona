#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e5 + 5, maxm = 1e2 + 5, inf = 2e9, M = 1e9 + 7;

// dp[i][j] = número de maneiras até a posição i e terminando em j
int dp[maxn][maxm];
vector<int> x(maxn);

int calc(int n, int m){
    if(x[0] != 0) dp[0][x[0]] = 1;
    else{
        for(int j = 1; j <= m; j++) dp[0][j] = 1;
    } 
    
    for(int i = 1; i < n; i++){
        if(x[i] == 0){
            for(int j = 1; j <= m; j++){
                dp[i][j] = ( (ll) dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % M;
            }
        }
        else{
            dp[i][x[i]] = ( (ll) dp[i - 1][x[i] - 1] + dp[i - 1][x[i]] + dp[i - 1][x[i] + 1]) % M;
        }
    }

    int tot = 0;
    for(int j = 1; j <= m; j++) tot = (tot + dp[n - 1][j]) % M;

    return tot;
}
 
void solve() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> x[i];

    cout << calc(n, m) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}
