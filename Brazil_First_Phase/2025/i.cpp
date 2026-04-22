#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> P;
    vector<int> D;

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        P.push_back({x, y});
    }

    for(int i = 1; i < n; i++) {
        D.push_back(abs(P[i].first + P[i].second - P[i - 1].first - P[i - 1].second));
    }

    int low = 1, up = D[0] - 1;
    int S = 0;
    int mul = 1;

    for(int i = 0; i < n - 1; i++) {
        S = D[i] * mul + S;
        mul *= -1;
        if(i % 2 == 0) {
            up = min(up, S - 1);
        }
        else {
            low = max(low, S + 1);
        }
    }

    if(up < low) cout << -1 << '\n';
    else cout << up << '\n';

    return 0;
}