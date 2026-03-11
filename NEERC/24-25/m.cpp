#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = (M + 1) / 2;
const int maxn = 400005;

void solve(){
	int n, A, B; cin >> n >> A >> B;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    vector<vector<int>> cards;
    pii ant = {0, 0};
    for(auto x : a)
    {
        if(x.first == ant.first) cards[cards.size() - 1].push_back(x.second);
        else cards.push_back({x.second});
        ant = x;
    }

    int m = cards.size();

    vector<vector<int>> dp(m);
    for(int i = 0; i < m; i++) dp[i].resize(n + 1);

    for(int i = 0; i < m; i++)
    {
        int c = cards[i].size();
        vector<int> aux(c + 1, 0);

        for(int k = c - 1; k >= 0; k--)
        {
            aux[k] = max(aux[k + 1], (cards[i][c - k - 1] / 2) - (c - k - 1));
        }

        // for(int k = 0; k <= c; k++)
        //     cout << k << ' ' << aux[k] << '\n';

        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = LINF;
            if(i == 0)
                dp[i][j] = min(dp[i][j], aux[min(j, c)]);
            else
                for(int k = 0; k <= min(c, j); k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + aux[k]);
                }
        }
    }

    int ans = LINF;
    for(int j = 0; j <= n; j++)
    {
        ans = min(ans, max(dp[m - 1][j], j));
    }

    // for(int i = 0; i < m; i++)
    // {
    //     for(int j = 0; j <= n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << ans << '\n';
}

signed main() {
    // _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}