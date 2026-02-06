#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Point = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k; cin >> n >> k;

    vector<Point> poly(n);
    for (auto& [x, y]: poly) cin >> x >> y;

    double l = -1e5, r = 1e5;
    for (int it = 100; it--; ) {
        double t = (l + r) / 2;

        double left = 0, right = 0;

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            if (j >= n) j -= n;

            auto [x1, y1] = poly[i];
            auto [x2, y2] = poly[j];

            if (x1 <= t && x2 <= t) {
                left += (y2 - y1) * (x2 + x1 - 2 * t) / 2;
            } else if (x1 >= t && x2 >= t) {
                right += (y2 - y1) * (x2 + x1 - 2 * t) / 2;
            } else {
                double y = (y1 * (x2 - x1) + (t - x1) * (y2 - y1)) / (x2 - x1);

                if (x1 <= t) {
                    left += (y - y1) * (t + x1 - 2 * t) / 2;
                    right += (y2 - y) * (x2 + t - 2 * t) / 2;
                } else {
                    left += (y2 - y) * (x2 + t - 2 * t) / 2;
                    right += (y - y1) * (t + x1 - 2 * t) / 2;
                }
            }
        }

        double ratio = abs(right / left);
        // cout << ratio << "\n";

        if (ratio <= k) r = t;
        else l = t;
    }
    cout << setprecision(10) << fixed;
    cout << l << "\n";
    return 0;
}