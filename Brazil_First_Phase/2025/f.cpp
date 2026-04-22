#include <bits/stdc++.h>

#define FOR(i, L, R) for (ll i = (L); i <= (R); i++)
#define RFOR(i, L, R) for (ll i = (R); i >= (L); i--)

#define sz(v) ll((v).size())
#define all(v) begin(v), end(v)
#define pb push_bacl

using namespace std;

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

const ll MOD = 1e9 + 7;

ll fexp(ll a, ll b) {
    ll r = 1;
    for (; b > 0; b>>=1) {
        if (b&1) r = r * a % MOD;
        a = a *a % MOD;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, m; cin >> n >> m;
    vl ans(n + 1), u(m);
    for (ll& x: u) cin >> x;
    ll acc = 0;
    ll inv2 = fexp(2, MOD - 2);
    RFOR(i, 0, m - 1) {
        ans[u[i]] = (ans[u[i]] + acc * inv2) % MOD;
        acc = (acc + u[i]) * inv2 % MOD; 
    }
    ans[1] = (ans[1] + acc) % MOD;
    FOR(i, 1, n) cout << ans[i] << "\n";
    return 0;
}