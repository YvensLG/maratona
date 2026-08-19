#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;

vector<int> adj[9];
unordered_map<int, int> dp;
vector<pair<int, int>> macaco = {{1, 0}, {0, 1}};

int p[9] = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

int troca(int at, int i, int j) {
    int d1 = (at / p[i]) % 10;
    int d2 = (at / p[j]) % 10;
    return at + (d2 - d1) * p[i] + (d1 - d2) * p[j];
}

void solve() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(auto a : macaco) {
                if(a.first + i < 0 || a.first + i > 2 || a.second + j < 0 || a.second + j > 2) continue;
                adj[i * 3 + j].emplace_back((i + a.first) * 3 + (j + a.second));
            }
        }
    }

    int b = 123'456'789; dp[b] = 0;
    queue<int> q; q.push(b);

    int target = 0;
    for(int i = 0; i < 9; i++) {
        int a; cin >> a;
        target = 10 * target + a;
    }

    if(target == b) {
        cout << "0\n";
        return;
    }

    while(!q.empty()) {
        int at = q.front(); q.pop();
        int ans = dp[at];
        for(int k = 0; k < 9; k++) {
            for(auto x : adj[k]) {
                int u = troca(at, k, x);
                if (!dp.count(u)) {
                    dp[u] = ans + 1;
                    if(u == target) {
                        cout << ans + 1 << '\n';
                        return;
                    }
                    q.push(u);
                }
            }
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}