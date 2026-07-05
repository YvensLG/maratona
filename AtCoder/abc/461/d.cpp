#include <bits/stdc++.h>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> pref(h + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            pref[i][j] = (grid[i - 1][j - 1] - '0') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    int tot = 0;
    vector<int> cnt(h * w + 1, 0);
    
    for (int r1 = 1; r1 <= h; r1++) {
        for (int r2 = r1; r2 <= h; r2++) {
            vector<int> rem;
            cnt[0] = 1;
            
            for (int c = 1; c <= w; c++) {
                int cur = pref[r2][c] - pref[r1 - 1][c];
                if (cur >= k) tot += cnt[cur - k];

                cnt[cur]++;
                rem.push_back(cur);
            }

            for(auto x : rem) cnt[x] = 0;
        }
    }

    cout << tot << '\n';
}

signed main() { _
    solve();
}