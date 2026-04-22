#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) (x).size()
typedef pair<int, int> pii;
#define mkp make_pair

const int inf = 2e9 + 10;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    map<string, pii> mp;
    vector<string> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        int x, y; cin >> x >> y;
        mp[d[i]] = mkp(x, y);
    }    
    int m; cin >> m;
    vector<string> t(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }
    int q, K; cin >> q >> K;
    while (q--) {
        int f; cin >> f;
        vector<string> a(f);
        for (auto&x : a) cin >> x;
        int fnd = 0;
        for (int k = K; k >= 1; --k) {
            vector<string> b;
            for (int i = f - k; i < f; ++i) {
                b.push_back(a[i]);
            }
            vector<pii> c;
            for (int i = 0; i + k < m; ++i) {
                int eq = 1;
                for (int j = 0; j < k; ++j) {
                    if (b[j] != t[i + j]) {
                        eq = 0;
                        break;
                    }
                }
                if (eq) {
                    if (mp.count(t[i + k])) {
                        c.push_back(mp[t[i + k]]);
                    }
                }
            }
            if (sz(c) == 0) continue;
            string best;
            int score = -inf;
            for (auto s : d) {
                auto [x, y] = mp[s];
                int sum = 0;
                for (auto [vx, vy] : c) {
                    sum += x * vx + y * vy;
                }
                if (sum > score) {
                    best = s;
                    score = sum;
                }
            }
            for (auto &x : a) cout << x<< " ";
            cout << best << "\n";
            fnd = 1;
            break;
        }
        if (!fnd) {
            for (auto &x : a) cout << x<< " ";
            cout << "*" << "\n";
        }
    }

    return 0;
}