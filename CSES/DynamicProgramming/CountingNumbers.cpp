#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxbse = 9, maxexp = 18, maxm = 1005, inf = 2e9, M = 1e9 + 7;

// dp[a][b] = quantidade < a * 10 ^ b sem dig adjacentes iguais.
ll dp[maxbse + 1][maxexp + 1];

void calcdp(){
    for(int b = 1; b <= maxbse; b++) dp[b][0] = b - 1; 
    dp[1][1] = 9;
    
    for(int e = 1; e <= maxexp; e++){
        // [1, 99999] = [1, 89999] + [90000, 99999]
        //                          + [0001, 8999]
        if(e == 2) dp[1][e] = dp[9][e - 1] + dp[9][e - 2] + 1; // adiciona o "90"
        if(e > 2)  dp[1][e] = dp[9][e - 1] + dp[9][e - 2] - dp[1][e - 3]; // remove "[90000, 90099]"

        for(int b = 2; b <= maxbse; b++){
            // [1, 69999] = [1, 59999] + [60000, 69999]
            //                       [0001, 9999] - [1, 6999] + [1, 5999]
            if(e == 1)
                dp[b][e] = dp[b - 1][e] + dp[1][e] - dp[b][e - 1] + dp[b - 1][e - 1] + 1; // adiciona o "60"
            else
                dp[b][e] = dp[b - 1][e] + dp[1][e] - dp[b][e - 1] + dp[b - 1][e - 1] - dp[1][e - 2]; // remove "[60000, 60099]"
        }
    }  

    // for(int e = 0; e <= 4; e++){
    //     for(int b = 1; b <= maxbse; b++){
    //         cout << "1 a " << b * pow(10, e) - 1 << " : " << dp[b][e] << '\n';
    //     }
    // }
}

ll ans(ll x){
    if(x == 0) return 0;
    vector<int> dig;
    int e = -1;
    while(x > 0){
        dig.pb(x % 10);
        x /= 10;
        e++;
    }
    reverse(all(dig));

    ll tot = dp[dig[0]][e] + 1;

    // cout << tot << '\n';

    for(int i = 1; i < dig.size(); i++){
        e--;
        tot += dp[dig[i]][e];
        if(e >= 2 && dig[i] > 0 && dig[i-1] > 0 ) tot -= dp[1][e - 1]; 
        if(e == 0 && dig[i] > 0 && dig[i-1] != 0) tot++; //????
        // cout << tot << '\n';

        if(dig[i] == dig[i-1]) break;
        if(dig[i] > dig[i-1]){
            tot += -dp[dig[i-1] + 1][e] + dp[dig[i-1]][e];
        }
    }

    return tot;
}

void solve() {
    calcdp();
    // for(int i = 1; i < 110000; i++){
    //     cout << i << " : " << ans(i) << '\n';
    // }
    ll a, b; cin >> a >> b;
    cout << ans(b + 1) - ans(a) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}