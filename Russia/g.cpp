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
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
	int n, k[3];
    cin >> n >> k[0] >> k[1] >> k[2];
    vector<int> dp[3], pref[3];
    for(int a = 0; a <= 2; a++){
        dp[a].resize(n + 1, 0); dp[a][0] = 1;
        pref[a].resize(n + 2, 0); pref[a][0] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int a = 0; a <= 2; a++)
            pref[a][i] = (pref[a][i - 1] + dp[a][i - 1]) % M;

        for(int a = 0; a <= 2; a++){
            dp[a][i] += pref[(a + 1) % 3][i] - pref[(a + 1) % 3][max(i - k[a], 0LL)];
            dp[a][i] += pref[(a + 2) % 3][i] - pref[(a + 2) % 3][max(i - k[a], 0LL)];
            dp[a][i] = ( dp[a][i] % M + M ) % M;
        }
    }

    cout << (((dp[0][n] + dp[1][n] + dp[2][n]) % M) * inv2 ) % M << '\n';

}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}