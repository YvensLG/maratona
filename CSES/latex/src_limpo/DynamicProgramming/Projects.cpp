const int maxn = 5e2 + 5, inf = 2e9, M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<pair<pii, int>> v(n);

    for(int i = 0; i < n; i++) cin >> v[i].f.f >> v[i].f.s >> v[i].s;

    set<int> checkpoints;
    for(int i = 0; i < n; i++) {
        checkpoints.insert(v[i].f.f);
        checkpoints.insert(v[i].f.s);
    }

    unordered_map<int, int> comprime;
    int tot = 1;
    for(auto x : checkpoints){
        comprime[x] = tot;
        tot++;
    }

    sort(all(v));

    vector<ll> dp(tot + 1);
    int at = 0;

    for(int i = 1; i <= tot; i++){
        dp[i] = max(dp[i], dp[i - 1]);
        while(i == comprime[v[at].f.f]){
            dp[comprime[v[at].f.s]] = max(dp[comprime[v[at].f.s]], dp[i - 1] + v[at].s);
            at ++;
        }
    }

    cout << dp[tot] << '\n';
}
