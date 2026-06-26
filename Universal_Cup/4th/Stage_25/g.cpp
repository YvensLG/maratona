#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 998244353;

int dp[2][1 << 24], vis[1 << 24];
queue<int> q[2], aux;

void solve() {
    int n, m; cin >> n >> m;
    int basis = (1 << m) - 1;

    memset(dp[0], 0, sizeof(dp[0]));
    memset(dp[1], 0, sizeof(dp[1]));
    memset(vis, 0, sizeof(vis));

    q[0].push(basis);

    int pot = 1 << (m - 1);

    dp[0][basis] = 1;

    int dp_at = 0;

    for(int i = 0; i < n; i++) {
        while(q[dp_at].size()) {
            int at = q[dp_at].front(); q[dp_at].pop();
            if(vis[at]) continue; vis[at] = 1; aux.push(at);

            if((at & pot)) {
                q[1 - dp_at].push((at - pot) * 2);
                dp[1 - dp_at][q[1 - dp_at].back()] = (dp[1 - dp_at][q[1 - dp_at].back()] + dp[dp_at][at]) % MOD; 

                q[1 - dp_at].push((at - pot) * 2 + 1);
                dp[1 - dp_at][q[1 - dp_at].back()] = (dp[1 - dp_at][q[1 - dp_at].back()] + dp[dp_at][at]) % MOD;                 
            }
            else if(!(at & pot)) {
                q[1 - dp_at].push((at) * 2 + 1);
                dp[1 - dp_at][q[1 - dp_at].back()] = (dp[1 - dp_at][q[1 - dp_at].back()] + dp[dp_at][at]) % MOD; 
            }
        }

        while(aux.size()) {
            int at = aux.front(); aux.pop();
            dp[dp_at][at] = 0;
            vis[at] = 0;
        }

        dp_at = 1 - dp_at; 

        for(int j = 1; j < m; j++) {
            while(q[dp_at].size()) {
                int at = q[dp_at].front(); q[dp_at].pop();
                if(vis[at]) continue; vis[at] = 1; aux.push(at);

                if((at & pot) && (at & 1)) {
                    q[1 - dp_at].push((at - pot) * 2);
                    dp[1 - dp_at][q[1 - dp_at].back()] = (dp[1 - dp_at][q[1 - dp_at].back()] + dp[dp_at][at]) % MOD; 

                    q[1 - dp_at].push((at - pot) * 2 + 1);
                    dp[1 - dp_at][q[1 - dp_at].back()] = (dp[1 - dp_at][q[1 - dp_at].back()] + dp[dp_at][at]) % MOD;                 
                }
                else if(!(at & pot) && (at & 1)) {
                    q[1 - dp_at].push((at) * 2 + 1);
                    dp[1 - dp_at][q[1 - dp_at].back()] = (dp[1 - dp_at][q[1 - dp_at].back()] + dp[dp_at][at]) % MOD; 
                }
                else if((at & pot) && !(at & 1)) {
                    q[1 - dp_at].push((at - pot) * 2 + 1);
                    dp[1 - dp_at][q[1 - dp_at].back()] = (dp[1 - dp_at][q[1 - dp_at].back()] + dp[dp_at][at]) % MOD; 
                }
                else if(!(at & pot) && !(at & 1)) {
                    q[1 - dp_at].push((at) * 2 + 1);
                    dp[1 - dp_at][q[1 - dp_at].back()] = (dp[1 - dp_at][q[1 - dp_at].back()] + dp[dp_at][at]) % MOD; 
                }
            }

            while(aux.size()) {
                int at = aux.front(); aux.pop();
                dp[dp_at][at] = 0;
                vis[at] = 0;
            }

            dp_at = 1 - dp_at; 
        }
    }

    int ans = 0;
    for(auto x : dp[dp_at]) ans = (ans + x) % MOD;

    cout << (2 * ans) % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();

    return 0;
}
