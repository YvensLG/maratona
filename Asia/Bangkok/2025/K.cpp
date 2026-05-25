#include <bits/stdc++.h>

#define int long long

using namespace std;

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

// soma piso((a * i + b) / c); 0 <= i <= n
int floor_sum(int a, int b, int c, int n) {
    if (a == 0) {
        return (b / c) * (n + 1);
    }

    int ans = (n * (n + 1) / 2) * (a / c) + (n + 1) * (b / c);
    a %= c; b %= c;

    int m = (a * n + b) / c;

    if (m == 0) return ans;
    return ans + m * n - floor_sum(c, c - b - 1, a, m - 1);
}

void solve() {
    int m, n, r, c; cin >> m >> n >> r >> c;
    r--; c--; m--; n--;

    if(n < m) {
        swap(n, m);
        swap(r, c);
    }

    // cx + ry = d
    int x, y;
    int d = euclid(c, r, x, y);

    if((n - m) % d != 0) {
        cout << -1 << '\n';
        return;
    }

    // cx + ry = n - m
    x *= (n - m) / d;
    y *= (n - m) / d;

    int mod_x = r / d;
    x = (x % mod_x + mod_x) % mod_x;

    if(c * x - n <= 0) {
        x += mod_x;
    }

    y = (c * x - (n - m)) / r; 

    // quantidade de batidas
    int F = c * x - n;

    int ans = 0;

    int K = F / (2 * c);
    if (K > 0) {
        ans += floor_sum(c, F + m - c * K, r, K - 1);
        ans -= floor_sum(c, m + c + r - 1, r, K - 1);
        ans += K;
    }

    K = F / (2 * r);
    if (K > 0) {
        ans += floor_sum(r, F + n - r * K, c, K - 1);
        ans -= floor_sum(r, n + r + c - 1, c, K - 1);
        ans += K;
    }

    cout << F + 1 - ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
