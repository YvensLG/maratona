#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

void solve() {
    int n; cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> dif(n + 1); dif[0] = a[0]; dif[n] = -a[n - 1];
    for (int i = 1; i < n; i++) dif[i] = a[i] - a[i - 1];

    int N = 1 << (n + 1);
    vector<int> sum(N, 0), dp(N, -1);
    dp[0] = 0;

    for (int mask = 0; mask < N; ++mask) {
        for (int i = 0; i <= n; ++i) {
            if (mask & (1 << i)) {
                sum[mask] += dif[i];
            }
        }
    }

    for (int mask = 1; mask < N; ++mask) {
        for (int i = 1; i < mask; i = i << 1) {
            int sub = mask ^ i;
            dp[mask] = max(dp[mask], dp[sub]);
        }        
        if(sum[mask] == 0) dp[mask] += 1;
    }

    cout << n - dp[N - 1] << endl;
}

signed main() { _
    solve();
}