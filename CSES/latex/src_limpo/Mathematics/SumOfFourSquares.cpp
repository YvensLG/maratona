void solve() {
    int n; cin >> n;
    vector<int> quad;
    int at = 0;
    for(int i = 1; at <= n; i++) {
        quad.push_back(at);
        at += 2 * i - 1;
    }

    bitset<MAX> sumsquare;
    for(auto x : quad)
        for(auto y : quad)
            if(x + y < MAX) sumsquare.set(x + y);

    int a[2] = {0, 0};

    for(int i = 0; i <= n; i++) {
        if(sumsquare[i] == 1 && sumsquare[n - i] == 1) {
            a[0] = i;
            a[1] = n - i;
            break;
        }
    }

    for(auto x : a)
        for(int i = 0; i * i <= x; i++) {
            int d = x - i * i;
            int s = round(sqrt((double) d));
            if(s * s == d) {
                cout << i << ' ' << s << ' ';
                break;
            }
        }

    cout << '\n';
}
