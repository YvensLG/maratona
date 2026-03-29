#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 0x3f3f3f3f;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    ll w = INF, h = INF, d = INF;

    for (int _=n;_--;) {
        vector<ll> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());

        w = min(w, v[0]);
        h = min(h, v[1]);
        d = min(d, v[2]);
    }

    cout << w * h * d << "\n";
}