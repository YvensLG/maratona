const int maxn = 2e6+6, mod = 1e9+7;

int fat[maxn], invfat[maxn];

void calcfat(){
    fat[0] = 1;
    for(int i=1; i<maxn; i++){
        fat[i] = (fat[i-1] * i) % mod;
    }
}

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

void calcinvfat(){
    for(int i=0; i<maxn; i++){
        invfat[i] = inv(fat[i]);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    cout << (((fat[n+m-1] * invfat[m]) % mod) * invfat[n-1]) % mod << '\n';
}

int32_t main() {
    calcfat();
    calcinvfat();
    solve();

    return 0;
}
