const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
const ll linf = 4e18;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<ll> prefix(n + 1); prefix[0] = 0;

    for(int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    multiset<ll> minimo;
    ll resp = -linf;

    for(int i = a; i <= n; i++){
        ll at = prefix[i];

        minimo.insert(prefix[i - a]);
        if(i > b) minimo.erase(minimo.find(prefix[i - b - 1]));

        resp = max(resp, at - *minimo.begin());
    }

    cout << resp << '\n';
}
