ll pot[19], memo[19];
const ll INF = 1e18;

ll ans(ll n) {
    if(n == 0) return 0;
    if(n < 10) return 1;
    if(n == 10) return 2;
    ll a = n, k = 0;
    while(a > 9) {
        a /= 10;
        k++;
    }

    if(a > 1) {
        return ans(n - pot[k] * a) + memo[k] * a + pot[k];
    }
    else {
        return ans(n - pot[k] * a) + (n - pot[k] * a + 1) + memo[k];
    }
}

void solve(){
    ll n; cin >> n;
    ll l = 0, r = INF;

    while(r - l > 1) {
        ll m = (l + r) / 2;
        if(ans(m) <= n) l = m;
        else r = m;
    }

    cout << l << '\n';
}

signed main() {
    pot[0] = 1;
    for(int i = 1; i <= 18; i++) {
        pot[i] = 10 * pot[i - 1];
    }
    for(int i = 0; i <= 18; i++) {
        memo[i] = i * pot[i - 1];
    }
    solve();
    return 0;
}
