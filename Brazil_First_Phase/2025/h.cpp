#include <bits/stdc++.h>

using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define mkp make_pair
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1024 * 1024;
vi a(MAX), a2(MAX);

int to_bin(const string& s) {
    int ans = 0;
    for(int i = 0; i < sz(s); i++) {
        ans <<= 1;
        ans += (s[i] - '0');
    }
    return ans;
}

void FST (vi & a, bool inv) {
    for (int n = sz(a), step = 1; step < n; step *= 2) {
        for (int i = 0; i < n; i+= 2 * step) rep(j,i,i+step) {
            int &u = a[j], &v = a[j + step]; tie(u, v) = inv ? pii(v, u - v) : pii(u + v, u);
        }
    }
}

vi conv(vi a, vi b) {
    FST(a, 0); FST(b, 0);
    rep(i, 0, sz(a)) a[i] *= b[i];
    FST(a, 1); return a;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        a[to_bin(s)]++;
    }
    for(int i = 0; i < MAX; i++) a2[i] = a[i] * a[i];

    vi or11 = conv(a, a);
    vi or3  = conv(a, or11);
    vi or21 = conv(a2, a);

    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        string E; cin >> E;
        int e = to_bin(E);
        int ans = 0;
        ans += (or3[e] - 3 * or21[e] + 2 * a[e] * a[e] * a[e]) / 6;
        ans += (or21[e] - or11[e]) / 2 - a[e] * a[e] * (a[e] - 1) / 2;
        ans += a[e] * (a[e] - 1) * (a[e] - 2) / 6;
        cout << ans << '\n';
    }

    return 0;
}