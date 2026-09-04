#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll r, n, m; cin >> r >> n >> m;

    auto choose2 = [](ll c) {return c*(c - 1)/2;};

    vl dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        vl ndp(n+1, 0);
        for (int c = 1; c < n; c++) {
            ndp[c] = dp[c - 1];

            if (i != r) {
                ndp[c] = (ndp[c] + c * dp[c]) % m;
                ndp[c] = (ndp[c] + choose2(c + 1) * dp[c + 1]) % m;
            }
        }
        dp.swap(ndp);
    }
    cout << dp[1] << "\n";
}
