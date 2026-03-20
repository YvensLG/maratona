#include <bits/stdc++.h>

#define sz(v) ll((v).size())

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

const ll MOD = 1e9 + 7;

ll fexp(ll a, ll b) {
    if (b < 0) b = (MOD - 2) * abs(b);

    ll r = 1;
    for (; b > 0; b >>= 1) {
        if (b&1) r = r * a % MOD;
        a = a * a % MOD;
    }
    return r;
}

struct SegTree {
    ll n, a;
    vl lazyl, lazyr;

    SegTree(ll n, ll a) : n(n), a(a), lazyl(4 * n, 0), lazyr(4 * n, 0) {}

    void updl(int i, int l, int r, int p, ll x) {
        if (p < l) return;
        if (r <= p) return void(lazyl[i] = (lazyl[i] + x) % MOD);

        int t = (l + r) / 2;

        if (t < p) updl(2 * i + 1, t + 1, r, p, x);

        int q = min(t, p);
        updl(2 * i, l, t, q, (x * fexp(a, p - q)) % MOD);
    }

    void updr(int i, int l, int r, int p, ll x) {
        if (r < p) return;
        if (p <= l) return void(lazyr[i] = (lazyr[i] + x) % MOD);

        int t = (l + r) / 2;

        if (p <= t) updr(2 * i, l, t, p, x);

        ll q = max(p, t + 1);
        updr(2 * i + 1, t + 1, r, q, x * fexp(a, q - p) % MOD);
    }

    void add(ll i, ll b) {
        if (i > 0) updl(1, 0, n - 1, i - 1, b * a % MOD);
        updr(1, 0, n - 1, i, b);
    }

    ll qry(int i, int l, int r, ll p) {
        if (l == r) return (lazyl[i] + lazyr[i]) % MOD;
        int t = (l + r) / 2;

        ll x = (lazyl[i] * fexp(a, r - p) + lazyr[i] * fexp(a, p - l)) % MOD;

        if (p <= t) return (x + qry(2 * i, l, t, p)) % MOD;
        else return (x + qry(2 * i + 1, t + 1, r, p)) % MOD;
    }

    ll get(ll p) {return qry(1, 0, n - 1, p);}
};

ll string_to_ratio(string p) {
    ll t = 2;
    ll a = stoi(p.substr(t, sz(p)));

    ll f = fexp(10, -(sz(p) - t));
    return (MOD + 1 - (a * f % MOD)) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    string p; cin >> p;

    ll a = string_to_ratio(p);

    SegTree seg(n, a);

    for (int _=q;_--;) {
        char op; cin >> op;

        if (op == '?') {
            int x; cin >> x; x--;

            cout << seg.get(x) << "\n";
        } else {
            ll b, x; cin >> b >> x; x--;
            
            if (op == '-') b = MOD - b;

            seg.add(x, b);
        }
    }
}