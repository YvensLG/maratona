#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
typedef long long int ll;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
const ll linf = 4e18;
 
 
void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<ll> prefix(n + 1); prefix[0] = 0;

    for(int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    multiset<ll> minimo;
    ll resp = -linf;

    for(int i = a; i <= n; i++){
        ll at = prefix[i];
        
        minimo.insert(prefix[i - a]);
        if(i > b) minimo.erase(minimo.find(prefix[i - b - 1]));

        resp = max(resp, at - *minimo.begin());
    }

    cout << resp << '\n';
}
 
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}