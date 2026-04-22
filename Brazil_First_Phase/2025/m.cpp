#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int& x: v) cin >> x;

    int l = 1, r = 2e9;
    while (l <= r) {
        int t = (l + r) / 2;
        int i = n - 1;
        for (; i >= 0 && v[i] >= t; i--);
        
        bool good = true;
        for (int j = i, d = m; j >= 0; j--, d && d--)
            good &= v[j] + d >= t;

        if (good) l = t + 1;
        else r = t - 1;
    }

    cout << r << "\n";
    return 0;
}