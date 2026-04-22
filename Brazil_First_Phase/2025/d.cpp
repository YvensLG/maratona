
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define FOR(i, L, R) for (ll i = (L); i <= (R); i++)
#define RFOR(i, L, R) for (ll i = (R); i >= (L); i--)
#define REP(t) for (ll _=t;_--;)

#define sz(v) ll((v).size())
#define all(v) begin(v), end(v)
#define pb push_back

using namespace std;

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

const ll K = 6, N = 21;
ll valid[1 << N];
ll num[K][K];
vll dom;

void solve() {
    ll n; cin >> n;
    ll mask = 0;
    FOR(i, 0, n - 1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        mask |= 1 << num[a][b];
    }

    cout << valid[mask] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    FOR(i, 0, K - 1) FOR(j, i, K - 1) {
        num[i][j] = num[j][i] = sz(dom);
        dom.pb(pll(i, j));
    }

    vl vis(K, 0), q(K), bad(K);
    vector<vl> adj(K, vl(K));
    
    FOR(mask, 1, (1 << N) - 1) {
        FOR(i, 0, K - 1)
            FOR(j, 0, K - 1)
            adj[i][j] = 0;
        FOR(i, 0, N - 1) if(mask&(1<<i)) {
            auto[a, b] = dom[i];
            
            adj[a][b] = adj[b][a] = 1;
        }

        ll cnt_odd = 0;
        FOR(i, 0, K - 1) {
            ll deg = 0;
            FOR(j, 0, K - 1) {
                if (i != j)
                    deg += adj[i][j];
                else
                    deg += 2 * adj[i][j];
            }

            vis[i] = deg == 0 ? mask : 0;
            cnt_odd += deg&1;
        }
        
        if (cnt_odd != 0 && cnt_odd != 2) continue;
        
        FOR(i, 0, K - 1) if (!vis[i]) {
            ll qi = 0, qe = 0;
            for (q[qe++] = i, vis[i] = mask; qi < qe; qi++) {
                ll v = q[qi];

                FOR(u, 0, K - 1) if (adj[v][u] && vis[u] < mask){
                    q[qe++] = u;
                    vis[u] = mask;
                }
            }
            break;
        }
        
        valid[mask] = 1;
        FOR(i, 0, K - 1) valid[mask] &= vis[i] == mask;
    }
    
    
    FOR(i, 0, N - 1) FOR(mask, 0, (1<<N) - 1) {
        if (mask&(1<<i)) valid[mask] += valid[mask^(1<<i)];
    }

    ll t; cin >> t;
    REP(t) solve();
    return 0;
}