#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e5+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;

__int128_t ans(vector<ll> k, ll m){
    __int128_t sum = 0;
    for(auto x : k) sum += m / x;
    return sum;
}
 
void solve(){
    ll n, t; cin >> n >> t;
    vector<ll> k(n);

    for(int i = 0; i < n; i++){
        cin >> k[i];
    }

    ll l = 0, r = linf, m;

    while(r - l > 1){
        m = (l + r) / 2;
        __int128_t sum = ans(k, m);
        if(sum >= t) r = m;
        else l = m;
    }

    cout << r << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}