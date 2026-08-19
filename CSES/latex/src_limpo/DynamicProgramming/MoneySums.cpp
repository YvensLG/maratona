const int maxn = 1e6 + 5, inf = 2e9, M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    bitset<maxn> mark;
    mark[0] = 1;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mark = (mark | mark << a);
    }

    cout << mark.count() - 1 << '\n';
    for(int i = 1; i < maxn; i++)
        if(mark[i] == 1)
            cout << i << ' ';
    cout << '\n';
}
