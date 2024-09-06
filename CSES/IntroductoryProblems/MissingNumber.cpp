#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
 
int v[maxn];
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while (t--)
    int n; cin >> n;
    v[0] = 1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v[x] = 1;
    }
 
    for(int i = 0; i <= n; i++){
        if(v[i] != 1) cout << i << '\n';
    }
 
    return 0;
}