#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, m, x; cin >> n >> m >> x;
    int r = 0, c = m - 1, v;

    while (r < n && c >= 0) {
        cout << "? " << r << ' ' << c << endl;
        cin >> v;

        if (v == x) {
            cout << "! " << r << ' ' << c << endl;
            return;
        } else if (v > x) {
            c--;
        } else {
            r++;
        }
    }

    cout << "! -1" << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t; while(t--)
    solve();
    return 0; 
}
