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
	int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    vector<int> pref(n + 2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    pref[n + 1] = LINF;
    for(int i = 1; i <= m; i++) cin >> b[i];

    vector<vector<int>> dp(m + 1);
    for(int i = 0; i <= m; i++) dp[i].resize(n + 1, LINF);

    for(int k = m; k >= 1; k--){

        if(k != m) dp[k][n] = dp[k + 1][n];
        if(a[n] <= b[k]) dp[k][n] = min(dp[k][n], m - k);

        for(int i = n - 1; i >= 1; i--){
            int aux = LINF;
            if(k != m) aux = dp[k + 1][i];
            if(a[i] > b[k]) {
                dp[k][i] = aux;
                continue;
            }

            int l = i, r = n + 1;
            while(r - l > 1){
                int m = (r + l) / 2;
                if(pref[m] - pref[i - 1] <= b[k]) l = m;
                else r = m;
            }

            if(l == n) aux = min(aux, m - k);
            else aux = min(aux, dp[k][l + 1] + m - k);

            dp[k][i] = aux;
        }
    }

    if(dp[1][1] >= LINF) cout << "-1\n";
    else cout << dp[1][1] << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}