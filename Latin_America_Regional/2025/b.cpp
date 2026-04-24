#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int M = 998244353;
const int MAX = 2020;

int dp[MAX][MAX];

void solve(){
    int n, k; cin >> n >> k;

    for(int i = 1; i <= k; i++) dp[1][i] = 1;
    for(int p = 1; p <= k + 10; p++) {
        for(int at = 1; at <= k; at++) {
            int e = at % (p + 1);
            if(e == 0) e = p + 1;

            for(; e <= min(k, k * (p + 1) - at * p); e += (p + 1)) {
                dp[p + 1][(at * p + e) / (p + 1)] += dp[p][at];
                dp[p + 1][(at * p + e) / (p + 1)] %= M;
            }
        }
    }

    if(n > k + 10) n = k + 10;

    int ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += dp[n][i];
        ans %= M;
    }
    cout << ans << '\n';
}

signed main() { _
    solve();
    return 0;
}