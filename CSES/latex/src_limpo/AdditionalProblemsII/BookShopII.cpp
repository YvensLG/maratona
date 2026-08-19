void solve(){
    int n, x; cin >> n >> x;
    vector<pll> list;

    vector<ll> p(n), h(n), k(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> k[i];

    for (int i = 0; i < n; i++) {
        ll c = 1;
        while (k[i] > c) {
            k[i] -= c;
            list.push_back({c * p[i], c * h[i]});
            c *= 2;
        }
        list.push_back({k[i] * p[i], k[i] * h[i]});
    }

    vector<ll> dp(x + 1, 0);

    for(auto item : list) {
        ll peso = item.first, valor = item.second;

        for(int j = x; j >= peso; j--) {
            dp[j] = max(dp[j], dp[j - peso] + valor);
        }
    }

    cout << dp[x] << '\n';
}
