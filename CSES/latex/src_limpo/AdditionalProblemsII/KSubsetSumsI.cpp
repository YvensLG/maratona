void solve(){
    int n, k; cin >> n >> k;
    vector<ll> v(n);
    ll base = 0;

    for(auto &x : v) {
        cin >> x;
        if(x < 0) base += x;
        x = abs(x);
    }
    sort(all(v));

    cout << base << ' '; k--;
    // (minimo, posicao minima)
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({base + v[0], 0});

    while(!pq.empty() && k--) {
        auto [at, pos] = pq.top(); pq.pop();
        cout << at << ' ';
        if(pos == n - 1) continue;
        pq.push({at - v[pos] + v[pos + 1], pos + 1});
        pq.push({at + v[pos + 1], pos + 1});
    }
    cout << '\n';

}
