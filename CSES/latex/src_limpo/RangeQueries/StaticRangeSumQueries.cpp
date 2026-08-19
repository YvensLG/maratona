void solve(){
    int n, q; cin >> n >> q;
    vector<ll> v(n + 1), pref(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = v[i] + pref[i - 1];
    }

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << pref[b] - pref[a - 1] << '\n';
    }
}
