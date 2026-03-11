#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = (M + 1) / 2;
const int maxn = 110;
const int maxk = 3; 

const int mod = 998244353;
int n, m, k; 

int dp1[maxn][(1<<maxk)], dp2[maxn][(1<<maxk)];

int bt( int id, vector<int>& marc, vector<int> &w ){
    if( id == marc.size() ){
        int val_w = 0; 
        for( int i = 0, pot = 1; i < w.size(); i++, pot *= 2 ) val_w += w[i]*pot; 

        int inv_w = 0; 
        for( int i = w.size() - 1, pot = 1; i >= 0; i--, pot *= 2 ) inv_w += w[i]*pot; 

        // calcula s
        for( int mask = 0; mask < (1<<k); mask++ ) dp1[0][mask] = dp2[0][mask] = 0; 
        dp1[0][val_w] = 1; 
        dp2[0][inv_w] = 1; 

        for( int i = 0; i < n; i++ ){
            for( int mask = 0; mask < (1<<k); mask++ ) dp1[i + 1][mask] = dp2[i + 1][mask] = 0; 
            for( int mask = 0; mask < (1<<k); mask++ ){
                for( int j = 0; j < 2; j++ ){
                    int mask_ = (2*mask + j)%(1<<k); 
                    if( marc[2*mask + j] == 0 ){
                        dp1[i + 1][mask_] += dp1[i][mask]; 
                        dp1[i + 1][mask_] %= mod; 
                        dp2[i + 1][mask_] += dp2[i][mask]; 
                        dp2[i + 1][mask_] %= mod; 
                    }
                }
            }
        }

        int val_s = 0; 
        for( int i = 0; i <= n - k; i++ ){
            int v1 = 0, v2 = 0; 
            for( int mask = 0; mask < (1<<k); mask++ ){
                v1 += dp1[i][mask]; 
                v1 %= mod; 
                v2 += dp2[n - i - k][mask]; 
                v2 %= mod; 
            } 

            val_s += (v1*v2)%mod; 
            val_s %= mod; 
        }


        for( int i = 0; i < m; i++ ){
            for( int mask = 0; mask < (1<<k); mask++ ) dp1[i + 1][mask] = dp2[i + 1][mask] = 0; 
            for( int mask = 0; mask < (1<<k); mask++ ){
                for( int j = 0; j < 2; j++ ){
                    int mask_ = (2*mask + j)%(1<<k); 
                    if( marc[2*mask + j] == 1 ){
                        dp1[i + 1][mask_] += dp1[i][mask]; 
                        dp1[i + 1][mask_] %= mod; 
                        dp2[i + 1][mask_] += dp2[i][mask]; 
                        dp2[i + 1][mask_] %= mod; 
                    }
                }
            }
        }


        int val_t = 0; 
        for( int i = 0; i <= m - k; i++ ){
            int v1 = 0, v2 = 0; 
            for( int mask = 0; mask < (1<<k); mask++ ){
                v1 += dp1[i][mask]; 
                v1 %= mod; 
                v2 += dp2[m - i - k][mask]; 
                v2 %= mod; 
            } 

            val_t += (v1*v2)%mod; 
            val_t %= mod; 
        }

        return (val_s*val_t)%mod;
    }

    int resp = bt( id + 1, marc, w ); 
    marc[id] = true; 
    resp += bt( id + 1, marc, w ); 
    marc[id] = false; 

    return resp%mod; 
}

void solve(){
	cin >> n >> m >> k; 
    vector<int> w(k); 
    for( int i = 0; i < k; i++ ){
        char c; cin >> c; 
        w[i] = c - '0';
    }

    vector<int> marc((1<<(k + 1)));
    cout << bt( 0, marc, w ); 
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}