using ll = long long;

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    auto calc = [&]( ll len, ll dist ){
        ll flips = dist/(len - 1);
        ll pos = (flips%2) ? len - dist%(len - 1) : dist%(len - 1) + 1;
        return make_pair( pos, flips );
    };

    auto [i, qi] = calc( n, k );
    auto [j, qj] = calc( m, k );

    ll lcm = (n - 1)*(m - 1)/__gcd(n - 1, m - 1);

    cout << i << " " << j << " " << qi + qj - k/lcm << "\n";
}
