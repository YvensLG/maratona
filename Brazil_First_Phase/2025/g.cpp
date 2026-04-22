#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define mkp make_pair
typedef pair<int, int> pii;

const int N = 4096, inf = 2e9;
bitset<N> c, d;
int n;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    string ln; cin >> ln;
    for (int i = 0; i < n; ++i) {
        c[i] = (ln[i] == '1');
    }
    pair<int, int> ans(inf, inf);
    for (int b = 0; b < 256; ++b) {
        if (b % 2 == 0 && b != 0) continue;
        for (int k = 0; k < 128; ++k) {
            int t = 0;
            int sum = 0;
            for (int j = 0; j < 7; ++j) {
                if (k & (1 << j)) {
                    t ^= b >> (j + 1);
                    ++sum;
                }
            }
            if (t == 0 && k != 0) continue;
            d = c;
            for (int j = 0; j < 7; ++j) {
                if (t & (1 << j)) {
                    d[n - j - 1] = !d[n - j - 1];
                }
            }
            for (int i = n - 1; i >= 0; --i) {
                if (!d[i]) continue;
                for (int j = 0; j < 8 && i - j >= 0; ++j) {
                    if (b & (1 << j)) {
                        d[i - j] = !d[i - j];
                    }
                }
                ++sum;
            }
            ans = min(ans, mkp(sum, b));
        }
    }
    string s;
    int x = ans.second;
    while (x) {
        s.push_back(x % 2 ? '1' : '0');
        x /= 2;
    }
    while (sz(s) < 8) s.push_back('0');
    reverse(all(s));
    cout << s << " " << ans.first << "\n";

    return 0;
}