#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAX = 2e5 + 5;
vi G[MAX];
int dp[MAX][2];
 
void dfs(int s, int p) {
    for(auto x : G[s]) {
        if(x == p) continue;
        dfs(x, s);
    }
    for(auto x : G[s]) {
        if(x == p) continue;
        dp[s][0] += max(dp[x][0], dp[x][1]);
    }
    for(auto x : G[s]) {
        if(x == p) continue;
        dp[s][1] = max(dp[s][1], 1 + dp[s][0] - max(dp[x][0], dp[x][1]) + dp[x][0]);
    }
}
 
void solve(){
    int n; cin >> n;
 
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].pb(b); G[b].pb(a);
    }
 
    dfs(0, -1);
 
    cout << max(dp[0][0], dp[0][1]) << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}