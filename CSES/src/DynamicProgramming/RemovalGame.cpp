#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e6 + 5, inf = 2e9, M = 1e9 + 7;
 
void solve() {
    int n; cin >> n;
    vector<int>   v(n + 1);
    vector<ll > acc(n + 1); 

    for(int i = 1; i <= n; i++){
        cin >> v[i];
        acc[i] = acc[i-1] + v[i];
    }

    ll dp[n + 1][n + 1];

    for(int i = 0; i <= n; i++) dp[i][i] = v[i];

    for(int k = 1; k < n; k++){
        for(int i = 1; i <= n - k; i++){
            int j = i + k; 
            dp[i][j] = (acc[j] - acc[i-1]) - min(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[1][n] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}