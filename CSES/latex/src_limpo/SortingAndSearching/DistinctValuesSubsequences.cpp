const int maxn = 1e5+5, inf = 2e9, M = 1e9 + 7;

void solve(){
    int n; cin >> n;
    map<int, int> mapa;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mapa[a]++;
    }

    ll ans = 1;
    for(auto x : mapa)
        ans = (ans * (x.second + 1)) % M;

    cout << ans - 1 << '\n';
}
