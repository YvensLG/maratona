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
    ll n; cin >> n;
    vl p(n), q(n);
    for (ll& x: p) cin >> x, x--;
    for (ll& x: q) cin >> x, x--;

    vl a(n), b(n), c(n);
    FOR(i, 0, n - 1) cin >> a[i];       
    FOR(i, 0, n - 1) cin >> b[i];
    FOR(i, 0, n - 1) cin >> c[i];

    vector<vl> adj(n);
    FOR(i, 0, n - 1) {
        adj[p[i]].push_back(q[i]);
        adj[q[i]].push_back(p[i]);
    }

    ll ans_tot = 0;
    vl vis(n);
    FOR(i, 0, n - 1) if (!vis[i]) {
        vl cycle;

        vis[i] = true;
        cycle.push_back(i);

        while (true) {
            ll v = cycle.back(), nxt = -1;

            for (ll u: adj[v]) if (!vis[u]) {
                nxt = u;
                break;
            }

            if (nxt == -1) break;

            cycle.push_back(nxt);
            vis[nxt] = true;
        }

        ll m = sz(cycle), ans = -INF;

        if (m == 1) {
            ans_tot += b[i];
            continue;
        }

        FOR(f0, 0, 1) {
            vector<vl> dp(m, vl(2));

            dp[0][f0] = 0;
            dp[0][f0^1] = -INF;

            FOR(i, 1, m - 1) {
                // f = 0
                dp[i][0] = max(
                    dp[i - 1][0] + b[cycle[i - 1]],
                    dp[i - 1][1] + c[cycle[i - 1]]
                );
                // f = 1
                dp[i][1] = max(
                    dp[i - 1][0] + a[cycle[i - 1]],
                    dp[i - 1][1] + b[cycle[i - 1]]
                );
            }
            
            // dp[m - 1][0] dp[m - 1][1]

            if (f0 == 0) {
                ans = max({
                    ans,
                    dp[m - 1][0] + b[cycle[m - 1]],
                    dp[m - 1][1] + c[cycle[m - 1]]
                });
            } else {
                ans = max({
                    ans,
                    dp[m - 1][0] + a[cycle[m - 1]],
                    dp[m - 1][1] + b[cycle[m - 1]]
                });
            }
        }

        ans_tot += ans;
    }

    cout << ans_tot << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t; cin >> t;
    REP(t) solve();
    return 0;
}