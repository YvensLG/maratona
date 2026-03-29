#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using vll = vector<pll>;

const ll INF = 0x3f3f3f3f;
const int MAXK = 17;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<vll> lim(MAXK, vll(MAXK + 1));

    lim[1][1] = pll(0, 0);
    lim[1][2] = pll(0, 0);

    for (int i = 2; i < MAXK; i++) {
        lim[i][2] = pll(0, 4);
        for (int j = 3; j <= i + 1; j++) {
            lim[i][j].fi = lim[i][j - 1].fi + lim[i - 1][j - 1].fi;
            lim[i][j].se = lim[i][j - 1].se + lim[i - 1][j - 1].se;

            lim[i][j].fi = lim[i][j].fi + (1ll << j);
            lim[i][j].se = lim[i][j].se + (1ll << j);

        }
    }

    int n, t; cin >> n >> t;
    for (int _=n;_--;) {
        int h; cin >> h;
        int k = t;
        if (h%4!=0) {
            cout << "-1\n";
            continue;
        }
        
        vector<ll> v;
        while (k > 0) {
            for (int j = k + 1; j > 0; j--) {
                auto[l, r] = lim[k][j];

                if (h < l) continue;

                h -= min(h, r);
                v.push_back(1ll << j);
                k--;
                break;
            }
        }

        if (h == 0) {
            cout << v.size() << " ";
            for (int x: v) cout << x << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
}