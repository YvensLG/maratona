#include <bits/stdc++.h>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;
const int MAX = 3e6 + 5;

int fat[MAX], invfat[MAX];

int fexp(int b, int e) {
    int res = 1;
    b %= MOD;
    while (e > 0) {
        if (e % 2 == 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        e /= 2;
    }
    return res;
}

int inv(int n) {
    return fexp(n, MOD - 2);
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (fat[n] * invfat[k] % MOD) * invfat[n - k] % MOD;
}

void solve() {
    int x1, x2, x3; cin >> x1 >> x2 >> x3;
    
    int ans = 0;

    int max_k = min({x2, 2 * x1, 2 * x3});

    for(int k = 1; k <= max_k; k++) {
        int ans13 = 0;
        
        int m = (k + 1) / 2;
        if(k % 2 == 1) {
            ans13 =( 2 * C(x1 - 1, m - 1) * C(x3 - 1, m - 1) )% MOD;
        } else {
            ans13 = ((C(x1 - 1, m) * C(x3 - 1, m - 1) % MOD) + (C(x1 - 1, m - 1) * C(x3 - 1, m) % MOD)) % MOD;
        }

        int ans2 = C(x2 - k + x1 + x3, x1 + x3);
        ans = (ans + ans13 * ans2) % MOD;
    }

    cout << ans << '\n';

}

signed main() { _
    fat[0] = 1;
    for(int i = 1; i < MAX; i++) {
        fat[i] = (fat[i - 1] * i) % MOD;
    }
    invfat[MAX - 1] = inv(fat[MAX - 1]);
    for(int i = MAX - 2; i >= 0; i--) {
        invfat[i] = (invfat[i + 1] * (i + 1)) % MOD;
    }
    solve();
}