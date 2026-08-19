#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
using namespace std;
 
void solve(){
    int n; cin >> n;
    vector<int> x(n), y(n), a(n), S(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];

    for(int i = 1; i < n; i++)
    {
        S[i] = S[i - 1] + y[i] - x[i];
    }

    int ans = 0;
    sort(S.begin(), S.end());
    int median = S[n/2];

    for(int i = 0; i < n; i++)
    {
        ans += abs(median - S[i]);
    }

    cout << ans << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}