#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, a, b; cin >> n >> a >> b;
    b = n - b - 1;
    if (b < a) swap(a, b);
    cout << b - a - 1 << "\n";

    return 0;
}
