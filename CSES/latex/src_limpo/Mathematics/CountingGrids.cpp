const int maxn = 2e6+6, n = 8, m = 64, mod = 1e9+7;

int fexp(int n, int exp){
    if(exp == 0) return 1;
    if(exp == 1) return n;
    int x = fexp(n, exp / 2);
    x = (x * x) % mod;
    if(exp % 2 == 1){
        return (n * x) % mod;
    }
    return x;
}

int inv(int n){
    return fexp(n, mod-2);
}

void solve() {
    int n; cin >> n;
    int ans = 0;

    if(n % 2 == 0){
        ans += fexp(2, n * n);
        ans += fexp(2, n * n / 4 + 1);
        ans += fexp(2, n * n / 2);
    }
    else{
        ans += fexp(2, n * n);
        ans += fexp(2, (n * n + 3) / 4 + 1);
        ans += fexp(2, (n * n + 1) / 2);
    }

    ans = ans % mod;
    ans = (ans * inv(4)) % mod;

    cout << ans << '\n';
}
