#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e3 + 5, maxx = 1e5 + 5, inf = 2e9, M = 1e9 + 7;
 
// dp[j] = melhor que consigo usando j dinheiros
int dp[maxx];
vector<int> h(maxn), s(maxn);
 
int calc(int n, int x){
    // vai usando um livro por vez
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= h[i]; j--){
            dp[j] = max(dp[j - h[i]] + s[i], dp[j]);
        }
    }
 
    return dp[x];
}
 
void solve() {
    int n, x; cin >> n >> x;
 
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> s[i];
 
    cout << calc(n, x) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}