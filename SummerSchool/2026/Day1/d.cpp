#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;

int fexp(int x, int y) {
    int ret = 1;
    while(y) {
        if(y & 1) ret = (ret * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), prod(n + 1), s(n + 1);

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n - 1; i++) cin >> b[i];

    prod[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        prod[i] = (prod[i + 1] * b[i]) % MOD;
    }

    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        s[i] = (s[i - 1] + a[i] * prod[i]) % MOD;
    }

    int t = 0; cin >> t;
    while(t --) {
        int l, r; cin >> l >> r;
        int ans = ((s[r] - s[l - 1]) % MOD + MOD) % MOD;
        ans = (ans * fexp(prod[r], MOD - 2)) % MOD;
        cout << ans << '\n';
    }

    return 0;
}