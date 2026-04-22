
#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    long long ans = 0;
    for (int j = 0; j < m; ++j) {
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, a[i][j]);

        }
        ans += mx;
    }
    cout<<ans<<endl;

    return 0;
}