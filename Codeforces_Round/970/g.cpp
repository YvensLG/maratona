#include <bits/stdc++.h>
#define pb push_back
#define pc __builtin_popcount
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;
const int M = 1e9 + 7;
const int maxn = 55;
const double pi = 3.1415926535897932384626;

#define int long long

void solve() {
    int n, k; cin >> n >> k;
    int d; cin >> d;
    for(int i = 1; i < n; i++){
        int a; cin >> a;
        d = __gcd(d, a);
    }

    if(n == 1){
        if(d < k) cout << k << '\n';
        else cout << k - 1 << '\n';
        return;
    }
    
    if(d == 1){
        cout << n + k - 1 << '\n';
        return;
    }

    int x = (k - 1) / (d - 1);
    if(x >= (n - 1)) cout << k + (n - 1) << '\n';
    else cout << k + x << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}