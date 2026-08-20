using ll = long long;

const int maxn = 3e3;

void solve(){
    int n; cin >> n;
    vector<bitset<maxn>> v(n);
    ll ans = 0;

    for( int i = 0; i < n; i++ ){
        cin >> v[i];

        for( int j = 0; j < i; j++ ){
            ll tot = (v[j]&v[i]).count();
            ans += tot*(tot - 1)/2;
        }
    }

    cout << ans << '\n';
}
