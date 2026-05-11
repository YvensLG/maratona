#include <bits/stdc++.h>
#define pb push_back

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    auto aux = v;

    sort(all(aux));
    aux.erase(unique(all(aux)), aux.end());

    int max_el = 0;

    for(int i = 0; i < n; i++) {
        v[i] = lower_bound(all(aux), v[i]) - aux.begin();
        max_el = max(max_el, v[i]);
    }

    vector<vi> pos(max_el + 1, vi(1, -1));

    for(int i = 0; i < n; i++) {
        int aux = i - pos[v[i]].back(); pos[v[i]].pop_back();
        pos[v[i]].push_back(aux);
        pos[v[i]].push_back(i);
    }

    for(int i = 0; i <= max_el; i++) {
        if(pos[i].size() == 1) pos[i].pop_back();
        else {
            int aux = n - pos[i].back(); pos[i].pop_back();
            pos[i].push_back(aux);
        }
    }

    ll tot = 0;

    for(int i = 0; i <= max_el; i++) {
        if(pos[i].size() == 0) continue;
        int m = pos[i].size();
        vector<ll> pref_sum(m, 0), pref_sq(m, 0);

        pref_sum[0] = pos[i][0];
        pref_sq[0] = (ll)pos[i][0] * pos[i][0];

        for(int j = 1; j < m; j++) {
            pref_sum[j] = pref_sum[j - 1] + pos[i][j];
            pref_sq[j] = pref_sq[j - 1] + pos[i][j] * pos[i][j];
        }

        ll aux = 0;

        for(int j = 0; j < m; j++) {
            int at = pos[i][j];
            // a_j * a_k * (j + 1), j < k
            aux -= at * (j + 1) * (pref_sum[m - 1] - pref_sum[j]); 
            // a_j * a_k * (j), j > k
            if(j > 0) aux += at * (j) * (pref_sum[j - 1]); 
        }

        tot += aux;
    }

    cout << ((ll) n ) * (n + 1) * (n + 2) / 6 - tot << endl;


}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}