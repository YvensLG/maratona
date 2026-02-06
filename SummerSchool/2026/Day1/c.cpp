#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<pll>;

using Edge = tuple<ll, ll, ll>;

ll choose(ll x) {
    return x * (x - 1) / 2;
}

struct DSU {
    ll n;
    vl v;
    vl cnt;
    ll tot;

    DSU(vl const& marked) : n(marked.size()), v(n, -1), cnt(marked), tot(0) {
    }

    ll find(ll x) {
        return v[x] < 0 ? x : (v[x] = find(v[x]));
    }

    void join(ll x, ll y) {
        x = find(x), y = find(y);
        if (x == y) return;

        if (v[x] > v[y]) swap(x, y);

        ll a = cnt[x], b = cnt[y];
        tot -= choose(a) + choose(b);
        tot += choose(a + b);

        v[x] += v[y];
        cnt[x] += cnt[y];
        v[y] = x;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    vl marked(n);
    for (int i = 0; i < k; i++) {
        ll v; cin >> v; v--;
        marked[v] = 1;
    }
    vector<Edge> edgs(m);
    for (auto& [w, u, v]: edgs) {
        cin >> u >> v >> w;
        u--; v--;
    }
    sort(edgs.rbegin(), edgs.rend());
    
    ll q; cin >> q;
    vl ans(q);
    vll qry(q);
    for (int i = 0; i < q; i++) {
        cin >> qry[i].first;
        qry[i].second = i;
    }
    sort(qry.rbegin(), qry.rend());
    
    DSU dsu(marked);
    ll ptr = 0;
    
    for (auto [d, q]: qry) {
        while (ptr < m && get<0>(edgs[ptr]) >= d) {
            auto[_, u, v] = edgs[ptr];
            dsu.join(u, v);
            ptr++;
        }

        ans[q] = dsu.tot;
    }
    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
    return 0;
}