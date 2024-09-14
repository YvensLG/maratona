#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e6 + 5, inf = 2e9, M = 1e9 + 7;
const int dado = 6;

int dp[maxn];
vector<int> coins;

void calc(){
    dp[0] = 0;
    
    for(int i = 0; i < maxn; i++){
        if(dp[i] == inf) continue;
        
        for(int coin : coins){
            if(i + coin >= maxn) continue;
            dp[i + coin] = min(dp[i + coin], dp[i] + 1);
        }
    }
}
 
void solve() {
    for(int i = 0; i < maxn; i++) dp[i] = inf;
    
    int n, x, c;
    cin >> n >> x;
    
    for(int i = 0; i < n; i++){
        cin >> c;
        coins.push_back(c);
    }
    
    calc();
    
    if(dp[x] == inf) dp[x] = -1;
    cout << dp[x] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}
