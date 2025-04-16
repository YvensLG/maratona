#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

void solve() {
    int x, u = 6;
    cout << "? " << u << '\n';
    cout.flush();
    cin >> x;
    x = x ^ u;
    cout << "! " << x << '\n';
    cout.flush();
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();
}