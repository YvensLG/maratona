#include <bits/stdc++.h>
#define pb push_back
#define pc __builtin_popcount
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;
const int M = 1e9 + 7;
const int maxn = 5001;
const double pi = 3.1415926535897932384626;
int dp[maxn][maxn];
int add1[maxn][maxn];
int add2[maxn][maxn];

void solve() {
    int m, n; cin >> n >> m;

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = 0;
            add1[i][j] = 0;
            add2[i][j] = 0;
        }
    }

    int total = 0;
    int maximo = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a == 0){
            total ++;
        }
        else{
            if(a < 0 && total >= abs(a)){
                add1[abs(a)][total - abs(a)] ++;
            }
            else if(total >= abs(a)){
                add2[total - abs(a)][abs(a)] ++;
            }
        }
    }

    for(int tot = 1; tot <= m; tot ++){
        for(int i = 1; i <= tot; i++){
            add1[i][tot - i] += add1[i - 1][tot - i + 1];
            add2[tot - i][i] += add2[tot - i + 1][i - 1];
        }
    }

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m; j++){
            add1[i][j] = add1[i][j] + add2[i][j];
        }
    }

    for(int tot = 0; tot <= m; tot ++){
        for(int i = 0; i <= tot; i++){
            dp[i][tot - i] += max(dp[i][max(tot - i - 1, 0)], dp[max(i - 1, 0)][tot - i]);
            dp[i][tot - i] += add1[i][tot - i];
            maximo = max(dp[i][tot - i], maximo);
        }
    }

    cout << maximo << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}