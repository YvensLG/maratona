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
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll> tll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n, x; cin >> n >> x;
    vector<pll> list;

    vector<ll> p(n), h(n), k(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> k[i];

    for (int i = 0; i < n; i++) {
        ll c = 1;
        while (k[i] > c) {
            k[i] -= c;
            list.push_back({c * p[i], c * h[i]});
            c *= 2;
        }
        list.push_back({k[i] * p[i], k[i] * h[i]});
    }

    vector<ll> dp(x + 1, 0);

    for(auto item : list) {
        ll peso = item.first, valor = item.second;
        
        for(int j = x; j >= peso; j--) {
            dp[j] = max(dp[j], dp[j - peso] + valor);
        }
    }

    cout << dp[x] << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
