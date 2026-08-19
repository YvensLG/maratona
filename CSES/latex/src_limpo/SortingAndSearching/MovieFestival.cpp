const int maxn = 1010, inf = 2e9, M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        v.pb({b, a});
    }

    sort(v.begin(), v.end());

    int total = 0, atual = 0;

    for(auto x : v){
        int ini = x.second, ed = x.first;
        if(ini >= atual){
            atual = ed;
            total++;
        }
    }

    cout << total << '\n';
}
