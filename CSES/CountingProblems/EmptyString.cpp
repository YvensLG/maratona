#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
#define int long long
 
using namespace std;
 
const int M = 1e9 + 7;
const int MAX = 505;
int dp[MAX][MAX]; //dp[a][b] = formas de deletar os caracteres de a ate b
int fat[MAX], fatinv[MAX];

int fexp(int b, int e) {
    int ans = 1;
    for (; e; b = b * b % M, e /= 2)
        if (e & 1) ans = ans * b % M;
    return ans;
}

void calcfat() {
    fat[0] = 1;
    for(int i = 1; i < MAX; i++) fat[i] = (i * fat[i - 1]) % M;
    fatinv[MAX - 1] = fexp(fat[MAX - 1], M - 2);
    for(int i = MAX - 2; i >= 0; i--) fatinv[i] = ((i + 1) * fatinv[i + 1]) % M;
}

int choose(int a, int b) {
    return ((fat[a] * fatinv[b] % M) * fatinv[a - b]) % M;
}

void calc(const string& s) {
    for(int i = 0; i + 1 < s.size(); i++) if(s[i] == s[i+1]) dp[i][i+1] = 1;

    for(int tam = 4; tam <= s.size(); tam+=2)
    for(int i = 0, j = i + tam - 1; j < s.size(); i++, j++) {
        // s[i] opera com s[k]
        
        if(s[i] == s[i + 1]) 
            dp[i][j] = (dp[i][j] + dp[i + 2][j] * (j - i + 1) / 2) % M;

        for(int k = i + 3; k < j; k += 2) {
            if(s[i] == s[k]) dp[i][j] = (dp[i][j] + (dp[i + 1][k - 1] * dp[k + 1][j] % M) * choose((j - i + 1) / 2, (j - k) / 2)) % M;
        }

        if(s[i] == s[j]) dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % M;
    }
}

void solve() {
    string s; cin >> s;
    calc(s);
    cout << dp[0][(int)s.size() - 1] << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    calcfat();
    solve();
    return 0;
}