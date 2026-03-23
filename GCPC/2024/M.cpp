#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto&x : a) {
        cin >> x;
    }
    vi b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] - i;
    }
    sort(all(b));
    int h = b[n / 2];
    for (auto&x : b) {
        x -= h;
    }
    ll ans = 0;
    for (auto x : b) {
        ans += abs(x);
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
