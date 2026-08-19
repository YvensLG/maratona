const int maxn = 1e4+2;
int gnumbers[maxn];

void grundy() {
    array<bool, maxn/2+1> excluded;
    for (int i = 0; i <= maxn; ++i) {
        auto e_begin = excluded.begin();
        auto e_end = e_begin + i/2;
        fill(e_begin, e_end, false);
        for (int j = 1; j < (i+1)/2; ++j) {
            int const k = i - j;
            excluded[gnumbers[j] ^ gnumbers[k]] = true;
        }
        gnumbers[i] = find(e_begin, e_end, false) - e_begin;
    }
}

void solve() {
    int n; cin >> n;
    if(n < maxn) {
        if(gnumbers[n] == 0) cout << "second\n";
        else cout << "first\n";
    }
    else {
        cout << "first\n";
    }
}

int main() {
    grundy();
    int t; cin >> t; while(t--)
    solve();

    return 0;
}
