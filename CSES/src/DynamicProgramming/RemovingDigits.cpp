#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e6 + 5, inf = 2e9, M = 1e9 + 7;
const int dado = 6;

int dp[maxn];

vector<int> digits(int x){
    vector<int> v;
    while(x > 0){
        if(x % 10 > 0)
            v.pb(x % 10);
        x /= 10;
    }
    return v;
}

void calc(int n){
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        vector<int> v = digits(i);
        for(auto x : v)
            dp[i] = min(dp[i], dp[i - x] + 1);
    }
}
 
void solve() {
    for(int i = 0; i < maxn; i++) dp[i] = inf;
    
    int n;
    cin >> n;
    calc(n);
    
    cout << dp[n] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}
