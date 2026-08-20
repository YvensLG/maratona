const int maxn = 2e6+5;
int v[maxn];

void solve() {
    int n; int x; int result = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        x = x % 4;
        result ^= x;
    }

    if(result == 0) cout << "second\n";
    else cout << "first\n";
}
