#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e5+5, inf = 2e9, M = 1e9 + 7;
 
void solve(){
    int n; cin >> n;
    map<int, int> mapa;
    
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mapa[a]++;
    }

    ll ans = 1;
    for(auto x : mapa)
        ans = (ans * (x.second + 1)) % M;

    cout << ans - 1 << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}