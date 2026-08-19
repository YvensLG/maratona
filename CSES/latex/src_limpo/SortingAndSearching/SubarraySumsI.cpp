const int maxn = 1010, inf = 2e9, M = 1e9 + 7;

void solve() {
    int n, x; cin >> n >> x;
    ll sum = 0;
    set<ll> v;
    v.insert(sum);

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        sum += a;
        v.insert(sum);
    }

    int cont = 0;

    for(auto a : v){
        auto it = v.find(x + a);
        if(it != v.end())
            cont++;
    }

    cout << cont << '\n';
}
