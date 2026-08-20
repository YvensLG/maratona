#include <bits/stdc++.h>
#define pb push_back

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi v;

pair<int, vi> check(int a1) {
    multiset<int> ms;
    for(auto x : v) ms.insert(x);
    vi ans = {a1};

    while(ms.size() > 0) {
        int nxt = *ms.begin() - a1;
        for(auto x : ans) {
            auto it = ms.find(x + nxt); 
            if(it == ms.end()) return {0, {}};
            ms.erase(it);
        }
        ans.push_back(nxt);
    }

    return {1, ans};
}

// os elementos vao ser a1 + a2, a1 + a3, ..., a1 + ak, a2 + a3, ...
// basta achar esse k
void solve(){
    int n; cin >> n;
    v.resize(n * (n - 1) / 2);
    for(auto &x : v) cin >> x;
    sort(all(v));

    for(int k = 2; k <= n; k++) {
        int a1 = (v[0] + v[1] - v[k - 1]) / 2;
        auto [flag, ans] = check(a1);
        if(flag) {
            for(auto x : ans) cout << x << ' ';
            cout << '\n';
            break;
        }
    };
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}