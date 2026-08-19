#include <bits/stdc++.h>
#define pb push_back

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int x, y; cin >> x >> y;
    cout << ((x - 1) ^ (y - 1)) << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
