#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
bool ans(vector<int> v, ll m, int k){
    int n = v.size();
    ll at = 0;
    int cont = 0;

    for(int i = 0; i < n; i++){
        if(cont > k) break;
        if(at + v[i] > m){
            at = v[i];
            if(at > m){
                cont = k + 1;
                break;
            }
            cont++;
        }
        else{
            at += v[i];
        }
    }
    if(at > 0) cont++;
    
    return cont <= k;
}
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    
    ll l = 1, r = 1;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        r   += v[i];
    }

    while(r - l > 1){
        ll m = (l + r) / 2;

        if(ans(v, m, k)) r = m;
        else l = m;
    }

    cout << r << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}   