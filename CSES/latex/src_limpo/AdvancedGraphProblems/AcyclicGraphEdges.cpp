void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cout << min(a, b) << ' ' << max(a, b) << '\n';
    }
}
