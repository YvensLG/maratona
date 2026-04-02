#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

typedef long long ll;
 
using namespace std;
 
const int MAX = 20;
const int MOD = 1e9 + 7;

int dp[MAX][1 << MAX];
int adj[MAX][MAX];

void calc(int n) {
    dp[0][1] = 1;
    for(int b = 0; b < (1 << (n - 1)); b++) {
        for(int at = 0; at < n - 1; at++) {
            int pot = 1 << at;
            if(!(pot & b)) continue;
            for(int nxt = 0; nxt < n - 1; nxt++) {
                int pot2 = 1 << nxt;
                if(pot2 & b || !adj[at][nxt]) continue;
                dp[nxt][b | pot2] = ((ll)dp[nxt][b | pot2] + (ll) dp[at][b] * adj[at][nxt]) % MOD;
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1][b - 1]++;
    }

    calc(n);

    int ans = 0;

    for(int at = 0; at < n - 1; at++) {
        if(!adj[at][n - 1]) continue;
        ans = ((ll)ans + (ll) dp[at][(1 << (n - 1)) - 1] * adj[at][n - 1]) % MOD;
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
	return 0;
}
