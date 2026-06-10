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
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5 + 5;
vi g[MAX];
int vis[MAX];

int dfs(int v) {
    vis[v] = 1;
    int at = 1;

    for(auto x : g[v]) {
        if(vis[x]) continue;
        at += dfs(x);
    }

    return at;
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<int> sizes;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) sizes.push_back(dfs(i));
    }
    sort(all(sizes));

    bitset<MAX> dp = 1;

    for(auto x : sizes) {
        dp |= (dp << x);
    }

    for(int i = n - 1; i >= 0; i--) cout << dp[i];
    cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
