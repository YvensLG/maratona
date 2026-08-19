const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

int main() {
    ll n; cin >> n;
    if(n == 1) {
        cout << "1\n";
        return 0;
    }
    if(n < 4) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    if(n == 4) {
        cout << "2 4 1 3\n";
        return 0;
    }

    vector<int> v1, v2;

    for(int i = 1; i <= n/2; i++) v1.pb(i);
    for(int i = n/2 + 1; i <= n; i++) v2.pb(i);

    for(int i = 0; i < n; i++) {
        if(i % 2 == 1) {
            cout << v1.back() << ' ';
            v1.pop_back();
        }
        else {
            cout << v2.back() << ' ';
            v2.pop_back();
        }
    }

    cout << '\n';

    return 0;
}
