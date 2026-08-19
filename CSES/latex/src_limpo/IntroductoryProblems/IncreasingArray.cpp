const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

int main() {
    ll n; cin >> n;
    ll a = 0, total = 0;

    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        total += max(0LL, a - x);
        a = max(a, x);
    }

    cout << total << '\n';

    return 0;
}
