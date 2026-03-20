#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

struct Wave {
    ll p, l, a;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n, w; cin >> n >> w;
    vector<Wave> waves;
    for (int i = 0; i < n; i++) {
        char op; cin >> op;

        if (op == '!') {
            ll p, l, a; cin >> p >> l >> a;

            waves.push_back({p, l, a});
        } else {
            ll q; cin >> q;

            ll ans = 0;
            for (auto [p, l, a]: waves) {
                if (q < p || q >= p + l) continue;

                int d = (q - p) % 4;

                if (d == 0) ans += a;
                if (d == 2) ans -= a;
            }
            cout << ans << "\n";
        }
    }
}