#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;

        if (l <= 5 && 5 <= r) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}