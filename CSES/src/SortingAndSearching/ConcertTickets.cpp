#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
 
void solve() {
    int n, m; cin >> n >> m;
    multiset<int> h;
 
    for(int i=0; i<n; i++){
        int a; cin >> a;
        h.insert(-a);
    }
 
    // for(auto x : h) cout << -x << ' ';
    // cout << '\n';
 
    for(int i=0; i<m; i++){
        int t; cin >> t;
        auto lwb = h.lower_bound(-t);
 
        if(lwb == h.end()) cout << "-1\n";
        else{
            cout << -*lwb << '\n';
            h.erase(lwb);
        }
 
        // for(auto x : h) cout << -x << ' ';
        // cout << '\n';
        
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}