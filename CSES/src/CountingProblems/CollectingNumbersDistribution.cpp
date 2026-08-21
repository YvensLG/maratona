#include <bits/stdc++.h>
#define pb push_back

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 5008;
const int MOD = 1e9 + 7;

// dp[n][k] = k * dp[n - 1][k] + (n - k + 1) * dp[n - 1][k - 1]
int dp[MAX][MAX];

void solve(){
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        for(int j = 2; j <= i; j++) {
            dp[i][j] = ((ll)j * dp[i - 1][j] + ((ll)i - j + 1) * dp[i - 1][j - 1]) % MOD;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dp[n][i] << ' '; 
    }
    cout << '\n';

}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
