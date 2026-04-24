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
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
    int n, k; cin >> n >> k;
    if(n == 1) {
        cout << "1\n";
        return;
    }
    vector<pii> p(n);
    int top = -INF, down = INF, left = INF, right = -INF;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        top = max(top, p[i].second);
        down = min(down, p[i].second);
        right = max(right, p[i].first);
        left = min(left, p[i].first);
    }
    
    for(int i = 0; i < n; i++) {
        int h = top - down + 1, w = right - left + 1;
        int k1 = k;

        int dist_vert = min(top - p[i].second, p[i].second - down);
        int dist_horz = min(right - p[i].first, p[i].first - left);
        
        if(dist_vert > dist_horz) w += min(dist_vert - dist_horz, k);
        else h += min(dist_horz - dist_vert, k);

        k1 -= min(max(dist_horz, dist_vert), k);

        ans = max(ans, (h + k1) * (w + k1));
    }

    for(int i = 0; i <= k; i++) {
        int h = top - down + 1, w = right - left + 1;
        ans = max(ans, (h + k - i) * (w + i));        
    }

    cout << ans << '\n';
}

signed main() { _
    solve();
    return 0;
}