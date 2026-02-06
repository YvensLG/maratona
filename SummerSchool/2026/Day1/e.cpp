#include <bits/stdc++.h>

#define FOR(x, L, R) for (ll x = (L); x <= (R); x++)
#define RFOR(x, L, R) for (ll x = (R); x >= (L); x--)
#define REP(n) for (ll _ = n; _--; )

#define sz(v) ll((v).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<pll>;

const ll INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n, V; cin >> n >> V;
    vll items(n);

    
    FOR(i, 0, n - 1) cin >> items[i].first;
    FOR(i, 0, n - 1) cin >> items[i].second;
    
    if (V <= 400) {
        ll ans = 0;
        vl dp(V + 1, 0);

        FOR(i, 0, n - 1) {
            RFOR(j, 0, V) if (items[i].first <= j) {
                dp[j] = max(dp[j], dp[j - items[i].first] + items[i].second);
                ans = max(ans, dp[j]);
            }
        }

        cout << ans << "\n";
        return;
    }

    sort(all(items));

    vl mx(n);
    mx[0] = items[0].second;
    FOR(i, 1, n - 1) {
        mx[i] = max(mx[i - 1], items[i].second);
    }

    auto solve2 = [&](ll V) {
        ll l = 0;
        ll ans = 0;
        FOR(i, 0, n - 1) if (items[i].first <= V)
            ans = max(ans, items[i].second);
        RFOR(r, 0, n - 1) if (items[r].first <= V) {
            while (l < n && items[l].first + items[r].first <= V) l++;

            ll k = min(r - 1, l - 1);

            if (k >= 0) ans = max(ans, mx[k] + items[r].second);
        }
        return ans;
    };

    ll ans = solve2(V);

    map<ll, pll> m;
    FOR(i, 0, n - 1) {
        auto[v, c] = items[i];

        if (3 * v <= V){
            if (c > m[v].first) {
                m[v] = pll(c, i);
            }
        }
    }

    for (auto [v, p]: m) {
        auto[c, i] = p;        mx[0] = items[0].second;
        FOR(i, 1, n - 1) {
            mx[i] = max(mx[i - 1], items[i].second);
        }
        items[i].second = -INF;

        mx[0] = items[0].second;
        FOR(i, 1, n - 1) {
            mx[i] = max(mx[i - 1], items[i].second);
        }

        ans = max(ans, solve2(V - items[i].first) + c);
        items[i].second = c;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t; cin >> t;
    REP(t) solve();
    return 0;
}