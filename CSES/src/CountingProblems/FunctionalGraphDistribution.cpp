#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
#define int long long
 
using namespace std;
 
const int M = 1e9 + 7;
const int MAX = 5008;
int fat[MAX], invfat[MAX];
int dp[MAX][MAX]; 

int fexp(int b, int e) {
    int ans = 1;
    for (; e; b = b * b % M, e /= 2)
        if (e & 1) ans = ans * b % M;
    return ans;
}
 
int inv(int a) {
    return fexp(a, M - 2);
}
 
int choose(int a, int b) {
    if(b < 0 || b > a) return 0;
    return fat[a] * (invfat[b] * invfat[a - b] % M) % M;
}
 
void solve() {
    int n; cin >> n;

    dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i][i] = 1;
        int sum = 1;
        for(int k = 2; k < i; k++) {
            for(int j = 1; j < i; j++) {
                dp[i][k] += dp[i - j][k - 1] * dp[j][1] * choose(i - 1, j - 1);
            }
            sum += dp[i][k];
        }
        dp[i][1] = fexp(i, i) - sum;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    fat[0] = 1;
    for(int i = 1; i < MAX; i++) fat[i] = (fat[i - 1] * i) % M; 
    invfat[MAX - 1] = inv(fat[MAX - 1]);
    for(int i = MAX - 2; i >= 0; i--) invfat[i] = (invfat[i + 1] * (i + 1)) % M; 
 
    solve();
    return 0;
}