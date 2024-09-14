#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
 
void solve() {
    int n; cin >> n;
    ll sum = 0;
    vector<ll> v;
    v.pb(sum);
    
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a = (a % n + n) % n;
        sum = (sum + a) % n;
        v.pb(sum);
    } 
 
    ll cont = 0;

    map<ll, ll> rep;

    for(auto a : v){
        ll k = rep[a];
        rep[a] ++;
        cont += k;
    } 

    cout << cont << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}