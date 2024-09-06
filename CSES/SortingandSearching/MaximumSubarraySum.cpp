#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
 
void solve() {
    int n; cin >> n;
    vector<int> v; int a; cin >> a; v.pb(a);
    
    for(int i = 1; i < n; i ++){
        int a; cin >> a;
        v.pb(a + v.back());
    }
 
    if(n == 1){
        cout << v[0] << '\n';
        return;
    }
 
    vector<int> M(n), m(n);
 
    for(int i = 0; i < n; i++){
        M[i] = v[i];
        m[i] = min(v[i], 0LL);
    }
 
    for(int i = n - 2; i >= 0; i--){
        M[i] = max(M[i + 1], M[i]);
    }
 
    for(int i = 1; i < n; i++){
        m[i] = min(m[i - 1], m[i]);
    }
 
    int maxi = -inf * (int)inf;
 
    for(int i = 0; i < n - 1; i++){
        maxi = max(maxi , M[i + 1] - m[i]);
    }
 
    cout << maxi << '\n';
 
}
 
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}