#include <bits/stdc++.h>

using namespace std;

#define int long long

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 998244353;

const __int128 lim = 2.1e23;

int fexp(int a, int b) {
    int ans = 1;
    while (b) {
        if (b % 2) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<pii> a(n);
    for (auto&[x, y] : a) {
        cin >> y >> x;
    }
    
    sort(all(a));
    reverse(all(a));

    vector<pii> c;
    for (auto [x, y] : a) {
        if (sz(c) == 0 || c.back().first != x) {
            c.emplace_back(x, y);
        } else {
            c.back().second += y;
        }
    }
    a = c;

    int ans = 0;

    __int128 f = m;
    int b = 1;

    for (int i = 0; i < sz(a); ++i) {
        auto [x, y] = a[i];
        if (b == 0) {
            if (y >= f) {
                y -= f;
                f = m;
                b = 1;
            } else if (i + 1 < sz(a)) {
                auto [x1, y1] = a[i + 1];
                f -= y;
                for (int j = 0; j < x - x1; ++j) {
                    f *= 2;
                    if (f > lim) {
                        return cout << (int) ans << "\n", void();
                    }
                }
            }
        }
        if (b == 1) {
            ans = (ans + fexp(2, x) * ((y + f - 1) / f)) % mod;
            if (y % f != 0 && i + 1 < sz(a)) {
                auto [x1, y1] = a[i + 1];
                f = (m - y % m);
                for (int j = 0; j < x - x1; ++j) {
                    f *= 2;
                    if (f > lim) {
                        return cout << (int) ans << "\n", void();
                    }
                }
                b = 0;
            }
        }
    }

    cout << (int) ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
