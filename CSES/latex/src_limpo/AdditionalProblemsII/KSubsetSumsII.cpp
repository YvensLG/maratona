void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<ll> v(n);
    ll base = 0;

    for(auto &x : v) {
        cin >> x;
    }
    sort(all(v));

    for(int i = 0; i < m; i++) base += v[i];

    // (minimo possivel, ficha que ta mexendo, pos_atual, pos_final)
    priority_queue<tll, vector<tll>, greater<tll>> pq;

    pq.push({base, m - 1, m - 1, n - 1});
    vector<ll> ans;

    while(!pq.empty() && ans.size() < k) {
        auto [mini, at, pos, fim] = pq.top(); pq.pop();
        ans.push_back(mini);

        if(pos + 1 <= fim)
            pq.push({mini - v[pos] + v[pos + 1], at, pos + 1, fim});

        if(at >= 1 && at <= pos - 1)
            pq.push({mini - v[at - 1] + v[at], at - 1, at, pos - 1});
    }

    for(auto x : ans) cout << x << ' ';
    cout << '\n';

}
