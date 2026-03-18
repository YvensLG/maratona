#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
#define int long long

using namespace std;

const int M = 1e9 + 7;
const int MAX = 2e6 + 10;
int fat[MAX];

int fexp(int b, int e) {
    int ans = 1;
    for (; e; b = b * b % M, e /= 2)
        if (e & 1) ans = ans * b % M;
    return ans;
}

int inv(int a) {
    return fexp(a, M - 2);
}

int calc(int a, int b) {
    return fat[a + b] * (inv(fat[a]) * inv(fat[b]) % M) % M;
}

void solve() {
    int n; cin >> n;
    int m; cin >> m;

    vector<int> dp(m + 1);
    vector<pair<int, int>> trap(m + 1);

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        trap[i] = {x - 1, y - 1};
        if(x == n && y == n) {
            cout << 0 << '\n';
            return;
        }
    }
    trap[m] = {n - 1, n - 1};

    sort(trap.begin(), trap.end());

    for(int i = 0; i <= m; i++) {
        dp[i] = calc(trap[i].first, trap[i].second);
        for(int j = 0; j < i; j++) {
            if(trap[i].second < trap[j].second) continue;
            dp[i] = (dp[i] - dp[j] * calc(trap[i].first - trap[j].first, trap[i].second - trap[j].second)) % M;
            dp[i] = (M + dp[i]) % M;
        }
    }

    cout << dp[m] << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    fat[0] = 1;
    for(int i = 1; i < MAX; i++) fat[i] = (fat[i - 1] * i) % M; 

    solve();
    return 0;
}