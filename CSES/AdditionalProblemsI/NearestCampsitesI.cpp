#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
 
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2e6+10;
const int INF = 1e9;

struct FT {
    vector<ll> pref;
    vector<ll> suff;
    
    FT(int n) : pref(n, INF), suff(n, INF) {}

    void update(int pos, ll dif) {
        for (int i = pos; i < sz(pref); i |= i + 1) {
            pref[i] = min(pref[i], dif);
        }
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
            suff[i] = min(suff[i], dif);
        }
    }

    ll query_pref(int pos) { // [0, pos - 1]
        ll res = INF; 
        for (int i = pos; i > 0; i &= i - 1) {
            res = min(res, pref[i-1]);
        }
        return res;
    }

    ll query_suff(int pos) { // [pos, MAX - 1]
        ll res = INF; 
        for (int i = pos; i < sz(suff); i |= i + 1) {
            res = min(res, suff[i]);
        }
        return res;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> p1(n), p2(m);
    vector<int> ans(m);

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        p1[i] = {a + MAX / 2, b + MAX / 2, i};
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        p2[i] = {a + MAX / 2, b + MAX / 2, i};
    }
    sort(all(p1)); sort(all(p2));
    auto aux1 = p1, aux2 = p2;

    reverse(all(p1));

    FT nw(MAX), sw(MAX);

    for(int i = 0; i < p2.size(); i++) {
        auto [x, y, ind] = p2[i];
        while(p1.size() > 0) {
            auto [a, b, ii] = p1.back();

            if(a <= x) {
                nw.update(b, -a + b);
                sw.update(b, -a - b);
                p1.pop_back();
            }
            else break;
        }

        int ans_nw = nw.query_suff(y) + x - y;
        int ans_sw = sw.query_pref(y) + x + y;
        
        ans[ind] = min(ans_sw, ans_nw);
    }

    p1 = aux1; p2 = aux2;
    reverse(all(p2));
    FT ne(MAX), se(MAX);

    for(int i = 0; i < p2.size(); i++) {
        auto [x, y, ind] = p2[i];
        while(p1.size() > 0) {
            auto [a, b, ii] = p1.back();

            if(a >= x) {
                ne.update(b, a + b);
                se.update(b, a - b);
                p1.pop_back();
            }
            else break;
        }

        int ans_ne = ne.query_suff(y) - x - y;
        int ans_se = se.query_pref(y) - x + y;
        
        ans[ind] = min({ans[ind], ans_se, ans_ne});
    }

    int res = -1;
    for(auto x : ans) res = max(res, x);
    cout << res << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}