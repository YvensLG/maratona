#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
	int n; cin >> n;
    vector<pii> points(n);
    vector<int> pref_y(n + 1);
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        points[i] = {x, y};
        pref_y[y] = 1;
    }

    for(int i = 1; i <= n; i++) {
        pref_y[i] += pref_y[i - 1];
    }

    sort(all(points));

    vector<int> suf_min(n), suf_max(n);
    suf_min[n - 1] = points[n - 1].second;
    suf_max[n - 1] = points[n - 1].second;

    for (int i = n - 2; i >= 0; i--) {
        suf_min[i] = min(suf_min[i + 1], points[i].second);
        suf_max[i] = max(suf_max[i + 1], points[i].second);
    }

    int at = 0;
    ll tot = 0;
    
    int min_y_left = INF;
    int max_y_left = -INF;

    int i = 0;
    while(i < n) {
        if(points[i].first == at) continue;
        at = points[i].first;

        while (i < n && points[i].first == at) {
            min_y_left = min(min_y_left, points[i].second);
            max_y_left = max(max_y_left, points[i].second);
            i++;
        }

        if (i == n) break;

        int min_y_right = suf_min[i];
        int max_y_right = suf_max[i];

        int r = min(max_y_left, max_y_right);
        int l = max(min_y_left, min_y_right);

        if(r > l) tot += pref_y[r] - pref_y[l];
    }
    cout << tot << '\n';
}

signed main() { _
    int t = 1;
    cin >> t;
    while(t--)
    solve();

    return 0;
}