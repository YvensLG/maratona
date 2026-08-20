void solve(){
    int a, b, x; cin >> a >> b >> x;
    cout << ((x <= a && x%__gcd(a, b) == 0) ? "YES" : "NO" ) << '\n';
}
