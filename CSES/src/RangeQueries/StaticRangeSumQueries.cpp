#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
 
 
using namespace std;
 
typedef long long int ll;
 
void solve(){
    int n, q; cin >> n >> q;
    vector<ll> v(n + 1), pref(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = v[i] + pref[i - 1];
    }
 
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << pref[b] - pref[a - 1] << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}