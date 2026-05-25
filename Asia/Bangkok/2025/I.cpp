#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 200'100;

int I[N], C[N], P[N], C2[N];
bool b[N];
string a;

bool f(int x) {
    if (x == 0) {
        return true;
    }

    int n = sz(a);

    int i = 0, c = 0, p = 0;

    for (int k = 0; k < n; ++k) {
        b[k] = 0;
    }

    for (int k = 0; k < n; ++k) {
        if (a[k] == 'I') {
            if (i < x) {
                I[i++] = k;
                b[k] = 1;
            }
        } else if (a[k] == 'C') {
            if (c < i) {
                C[c++] = k;
                b[k] = 1;
            }
        } else {
            if (p < c) {
                P[p++] = k;
                b[k] = 1;
            }
        }
    }

    if (p < x) {
        return false;
    }

    int p2 = 0, c2 = 0;
    for (int k = 0; k < n; ++k) {
        if (a[k] == 'P') {
            if (b[k] == 1) {
                ++p2;
            }
        } else if (a[k] == 'C') {
            if (b[k] == 0) {
                if (c2 < p2) {
                    C2[c2++] = k;
                }
            }
        }
    }

    return c2 >= x;
}

void solve() {
    cin >> a;

    int n = sz(a);

    int is = 0, cs = 0, ps = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 'I') {
            ++is;
        } else if (a[i] == 'C') {
            ++cs;
        } else {
            ++ps;
        }
    }

    int l = 0, r = min({is, cs / 2, ps});
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (f(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    f(l);
    cout << l << "\n";
    for (int k = 0; k < l; ++k) {
        cout << I[k] + 1 << " " << C[k] + 1 << " "
             << P[k] + 1 << " " << C2[k] + 1 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
