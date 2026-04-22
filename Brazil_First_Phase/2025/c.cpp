
#include <bits/stdc++.h>

#define FOR(i, L, R) for (ll i = (L); i <= (R); i++)
#define RFOR(i, L, R) for (ll i = (R); i >= (L); i--)
#define REP(t) for (ll _=(t); _--;)

#define sz(v) ll((v).size())
#define all(v) begin(v), end(v)
#define pb push_bacl

using namespace std;

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll d, n = 0; cin >> d;
    REP(d + 1) {
        ll a; cin >> a;
        n = 2 * n + a;
    }
    ll ans = 0;
    while (n > 1) {
        if (n&1) {
            n = (n << 1) ^ n ^ 1;
        } else {
            n >>= 1;
        }
        ans++;
    }
    cout << ans << "\n";
    return 0;
}