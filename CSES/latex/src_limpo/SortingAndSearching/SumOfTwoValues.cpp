const int maxn = 1010, inf = 2e9, M = 1e9 + 7;

void solve() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        int a; cin >> a;
        v.pb({a, i});
    }

    sort(v.begin(), v.end());

    int fim = n-1, ini = 0;
    int soma = 0;

    while(soma != x && fim != ini){
        soma = v[fim].first + v[ini].first;
        if(soma < x) ini++;
        else if(soma > x) fim--;
    }

    if(soma == x) cout << v[ini].second + 1 << ' ' << v[fim].second + 1 << '\n';
    else cout << "IMPOSSIBLE\n";
}
