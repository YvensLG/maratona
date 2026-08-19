const int maxn = 1010, inf = 2e9, M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    ll sum = 0;
    vector<ll> v;
    v.pb(sum);

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a = (a % n + n) % n;
        sum = (sum + a) % n;
        v.pb(sum);
    }

    ll cont = 0;

    map<ll, ll> rep;

    for(auto a : v){
        ll k = rep[a];
        rep[a] ++;
        cont += k;
    }

    cout << cont << '\n';
}
