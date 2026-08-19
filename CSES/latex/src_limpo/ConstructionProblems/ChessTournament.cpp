void solve(){
    int n; cin >> n;
    priority_queue<pii> pq;
    for(int i = 0; i < n; i++) {
        int d; cin >> d;
        if(d != 0) pq.push({d, i + 1});
    }

    vector<pii> ans;

    while(pq.size() > 0) {
        vector<pii> aux;
        auto [at, pos] = pq.top(); pq.pop();

        while(at > 0) {
            if(pq.size() == 0) {
                cout << "IMPOSSIBLE\n";
                return;
            }

            auto [nxt, nxt_pos] = pq.top(); pq.pop();
            aux.push_back({nxt - 1, nxt_pos});
            ans.push_back({pos, nxt_pos});
            at--;
        }

        for(auto [x, y] : aux) if(x > 0) pq.push({x, y});
    }

    cout << ans.size() << '\n';
    for(auto [x, y] : ans) cout << x << ' ' << y << '\n';
}
