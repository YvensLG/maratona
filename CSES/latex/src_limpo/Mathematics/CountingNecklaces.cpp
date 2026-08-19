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
    int n, m; cin >> n >> m;
    int total = 0;
    for(int k=0; k<n; k++)
        total = (total + fexp(m, __gcd(k, n))) % mod;

    total = (total * inv(n)) % mod;

    cout << total << '\n';
}
