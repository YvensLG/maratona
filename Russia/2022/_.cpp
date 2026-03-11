#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> d(n);
    for (auto&x:d) cin >> x;
    int Time; cin >> Time;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    
    do {

    } while (next_permutation(all(p)));

    return 0;
}
