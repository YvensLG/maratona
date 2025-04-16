#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first;
    for(int i = 0; i < n; i++) cin >> a[i].second;
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        if(k >= a[i].first) k += a[i].second;
    }

    cout << k << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();
}