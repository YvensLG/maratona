#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
vector<vector<int>> dp;
vector<int> a, b;

int lcs(int n, int m) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[n][m];
}

void solve() {
    int n, m; cin >> n >> m;
    a.resize(n);
    b.resize(m);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    
    dp.resize(n + 1, vector<int>(m + 1, 0));

    int i = n, j = m, at = lcs(n, m);
    vector<int> ans;
    cout << at << '\n';

    while(i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1]) {
            ans.push_back(a[i - 1]);
            i--; j--;
        } 
        else if (dp[i - 1][j] >= dp[i][j - 1]) i--;
        else j--;
    }

    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}
