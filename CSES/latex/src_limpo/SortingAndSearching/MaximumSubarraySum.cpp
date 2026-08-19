const int maxn = 1010, inf = 2e9, M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    ll prefix = 0;
    ll minimo = 0;
    ll resp = -inf;

    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        prefix += a;
        resp = max(resp, prefix - minimo);
        minimo = min(minimo, prefix);
    }

    cout << resp << '\n';
}
