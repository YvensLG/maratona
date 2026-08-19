const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

void solve(ll n){
    ll total = (n * n) * (n * n - 1);

    total -= 4 * 2;
    total -= 8 * 3;
    total -= (4 * (n - 3)) * 4;
    total -= (4 * (n - 4)) * 6;
    total -= ((n - 4) * (n - 4)) * 8;

    cout << total / 2 << '\n';
}

int main() {
    int t; cin >> t; for(int i = 1; i <= t; i++)
    solve(i);
    return 0;
}
