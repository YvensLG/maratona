const int MAX = 1005;

int pref[MAX][MAX];

void solve(){
    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char c; cin >> c;
            pref[i][j] = (c == '*' ? 1 : 0);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] += pref[i][j - 1];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] += pref[i - 1][j];
        }
    }

    while(q--) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int ans = pref[y2][x2] + pref[y1 - 1][x1 - 1] - pref[y2][x1 - 1] - pref[y1 - 1][x2];
        cout << ans << '\n';
    }
}
