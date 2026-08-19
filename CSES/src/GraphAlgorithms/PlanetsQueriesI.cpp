#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int MAX = 2e5 + 5, LOG = 30;
 
int n, q;
int bin_lift[MAX][LOG];
  
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
 
    for(int i = 1; i <= n; i++) cin >> bin_lift[i][0];
    
    for(int i = 1; i < LOG; i++)
        for(int s = 1; s <= n; s++) 
            bin_lift[s][i] = bin_lift[bin_lift[s][i-1]][i-1];
 
    while(q--) {
        int u, k; cin >> u >> k;
        int at = 0, dest = u;
        while(k > 0) {
            if(k % 2) dest = bin_lift[dest][at];
            at++; k/=2;
        }
 
        cout << dest << '\n';
    }
 
 
    return 0;
}