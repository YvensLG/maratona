#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e6 + 5, inf = 2e9, M = 1e9 + 7;
 
void solve() {
    string s, t;
    cin >> s >> t;
 
    int n = s.size(), m = t.size();
 
    int dp[n + 1][m + 1];
 
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = inf;
            if(s[i-1] == t[j-1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
 
    cout << dp[n][m] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}