#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;

const int MAX = 1005;

int pref[MAX][MAX];

void solve(){
    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char c; cin >> c;
            pref[i][j] = (c == '*' ? 1 : 0);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] += pref[i][j - 1];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] += pref[i - 1][j];
        }
    }

    while(q--) {
        int x1, x2, y1, y2; 
        cin >> y1 >> x1 >> y2 >> x2;
        
        int ans = pref[y2][x2] + pref[y1 - 1][x1 - 1] - pref[y2][x1 - 1] - pref[y1 - 1][x2];
        cout << ans << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}