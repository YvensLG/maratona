const int maxn = 1e5+5, inf = 2e9, M = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<int> x(n);

    for(int i = 0; i < n; i++) cin >> x[i];

    set<int> at;
    ll p1 = 0, p2 = 0;
    ll ans = 0;

    for(p1 = 0; p1 < n; p1++) {
        while(p2 < n && at.find(x[p2]) == at.end()) {
            at.insert(x[p2]);
            p2++;
        }

        ans += (p2 - p1);
        at.erase(x[p1]);
    }

    cout << ans << '\n';
}
