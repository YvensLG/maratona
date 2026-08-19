const int maxn = 1010, inf = 2e9, M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        v.pb({a, 1});
        v.pb({b, -1});
    }

    sort(v.begin(), v.end());

    int maxi = 0;
    int total = 0;

    for(auto p : v){
        total += p.second;
        maxi = max(maxi, total);
    }

    cout << maxi << '\n';
}
