#include <bits/stdc++.h>
#define pb push_back
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 16;

vi G[MAX];
pii dp[1 << MAX];

bool check(int mask) {
    for(int i = 0; i < MAX; i++) {
        if(!((1 << i) & mask)) continue;
        for(auto x : G[i])
        if((1 << x) & mask)
            return false;
    }
    return true;
}

void solve(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    for(int mask = 1; mask < (1 << n); mask++) {
        if(check(mask)) {
            dp[mask] = {1, mask};
            continue;
        }

        for (int x = mask; x; ) {
            --x &= mask;
            if(dp[x].first != 1) continue;
            int novo = dp[x].first + dp[mask ^ x].first;
            if(dp[mask].first == 0 || dp[mask].first > novo) {
                dp[mask].first = novo;
                dp[mask].second = x;
            }
        } 
    }

    int k = (1 << n) - 1;
    cout << dp[k].first << '\n';
    vector<int> ans(MAX, 0);
    int c = 1;
    while(k != 0) {
        for(int i = 0; i < MAX; i++) {
            if((1 << i) & dp[k].second) ans[i] = c;
        }
        k = dp[k].second ^ k;
        c++;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}