#include <bits/stdc++.h>
#define int long long

using namespace std;
using vi = vector<int>;

const int INF = 0x3f3f3f3f;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, h; cin >> n >> h;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        
        int w = INF;

        if (x <= h) w = min({w, y, z});
        if (y <= h) w = min({w, z, x});
        if (z <= h) w = min({w, y, x});

        if (w == INF) return cout << "impossible\n", 0;

        ans += w;
    }
    cout << ans << "\n";
}