#include<bits/stdc++.h>
#define int long long

using namespace std;

const int K = 10;
const int N = 250010;
const int inf = 1e18;
int dp[2][K][K][K][2][2];
int v[N];

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> v[i];
    }
    for(int k1 = 0;k1 <= k;k1++)
        for(int k2 = 0;k2 <= k;k2++)
            for(int k3 = 0;k3 <= k;k3++)
                dp[0][k1][k2][k3][0][0] = dp[0][k1][k2][k3][0][1] = dp[0][k1][k2][k3][1][0] = dp[0][k1][k2][k3][1][1] = inf;
    dp[0][k][0][0][1][0] = dp[0][k][0][0][0][1] = dp[0][k][0][0][1][1] = 0;
    for(int i = 1;i <= n;i++){
        for(int k1 = 0;k1 <= k;k1++){
            for(int k2 = 0;k2 <= k-k1;k2++){
                for(int k3 = 0;k3 <= k-k1-k2;k3++){
                    for(int f0 = 0;f0 < 2;f0++){
                        for(int f1 = 0;f1 < 2;f1++){
                            if(f0 == 0 and f1 == 0){
                                dp[i%2][k1][k2][k3][0][0] = min({dp[(i+1)%2][k1][k2][k3][1][0] + v[i], 
                                    (k2 == k or k1+k2+k3+1 > k? inf : dp[(i+1)%2][k1][k2+1][k3][1][0]), 
                                    (k1 == k or k3 == 0 > k ? inf : dp[(i+1)%2][k1+1][k2][k3-1][1][0])});
                            }
                            else{
                                dp[i%2][k1][k2][k3][f0][f1] = min({dp[(i+1)%2][k1][k2][k3][1][f0] + v[i], 
                                    (k2 == k or k1 + k2 + k3 + 1 > k ? inf : dp[(i+1)%2][k1][k2+1][k3][1][f0]), 
                                    (k1 == k or k3 == 0 > k ? inf : dp[(i+1)%2][k1+1][k2][k3-1][1][f0]),
                                    dp[(i+1)%2][k1][k2][k3][0][f0],
                                    (k1 == k or k2 == 0 ? inf : dp[(i+1)%2][k1+1][k2-1][k3][0][f0] + v[i]),
                                    (k3 == k or k1 + k2 + k3 + 1 > k? inf : dp[(i+1)%2][k1][k2][k3+1][0][f0] + v[i])
                                });
                            }
                        }
                    }
                }
            }
        }
    }
    int res = inf;
    //cout << dp[n%2][0][0][0][0][1] << '\n';
    for(int i = 0;i <= k;i++){
        res = min(res, dp[(n%2)][i][0][0][0][1]);
    }
    cout << res << '\n';
}