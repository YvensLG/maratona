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
    int a, b; cin >> a >> b;

    if(315 * b > a * 100 && a * 100 >= 314 * b) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 

    int t; cin >> t; while(t--)
    solve();

    return 0; 
}
