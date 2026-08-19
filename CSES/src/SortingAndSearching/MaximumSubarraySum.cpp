#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
typedef long long int ll;
 
void solve() {
    int n; cin >> n;
    ll prefix = 0;
    ll minimo = 0;
    ll resp = -inf;

    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        prefix += a;
        resp = max(resp, prefix - minimo);
        minimo = min(minimo, prefix);
    }

    cout << resp << '\n';
}
 
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}