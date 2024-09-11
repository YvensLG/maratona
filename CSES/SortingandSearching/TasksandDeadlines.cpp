#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e5+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;
 
void solve(){
    int n; cin >> n;
    int d;
    ll soma = 0;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> d;
        soma += d;
    }

    sort(a.begin() + 1, a.end());

    for(int i = 1; i <= n; i++){
        soma -= (ll)a[i] * (n - i + 1);
    }

    cout << soma << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}