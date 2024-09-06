#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
 
void solve(){
    ll x, y; cin >> y >> x;
 
    ll a = max(x, y);
 
    ll resp = (a-1)*(a-1);
 
    if(a % 2 == 0){
        resp += y + a - x;
    }
    else{
        resp += x + a - y;
    }
 
    cout << resp << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}