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
    dp[0] = 1;
    
    for(int coin : coins){
        for(int i = 0; i < maxn; i++){
            if(i + coin >= maxn) continue;
            dp[i + coin] = (dp[i + coin] + dp[i]) % M;
        }
    }
}
 
void solve() {
    for(int i = 0; i < maxn; i++) dp[i] = 0;
    
    int n, x, c;
    cin >> n >> x;
    
    for(int i = 0; i < n; i++){
        cin >> c;
        coins.push_back(c);
    }
    
    calc();
    
    cout << dp[x] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}
