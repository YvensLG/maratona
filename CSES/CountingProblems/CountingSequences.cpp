#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
#define int long long
 
using namespace std;
 
const int M = 1e9 + 7;
const int MAX = 1e6 + 10;
int fat[MAX], invfat[MAX];
 
int fexp(int b, int e) {
    int ans = 1;
    for (; e; b = b * b % M, e /= 2)
        if (e & 1) ans = ans * b % M;
    return ans;
}
 
int inv(int a) {
    return fexp(a, M - 2);
}
 
int calc(int a, int b) {
    if(b < 0 || b > a) return 0;
    return fat[a] * (invfat[b] * invfat[a - b] % M) % M;
}
 
// inclusao - exclusao em Ai = {seq's tais que i não apareece}
void solve() {
    int n, k; cin >> n >> k;

    int sgn = 1, tot = 0;

    for(int i = 1; i < k; i++) {
        int pot = (fexp(k - i, n) * calc(k, i)) % M; 
        pot = (pot * sgn + M) % M;

        tot = (tot + pot) % M;
        sgn = -sgn;
    }

    cout << (fexp(k, n) - tot + M) % M << '\n';
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