#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int K = 2500;
ld c[K + 5], s[K + 5];

void calc() {
    c[0] = 1;
    
    for(int i = 1; i <= K; i++) {
        c[i] = c[i - 1];
        c[i] *= ((ld)1.5) / i - 1;
    }
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);

    for(auto &x : a) cin >> x;
    sort(all(a));

    ld ans = 0;

    for(int at = 0; at < n - 1; at++) {
        ld pot = 1;
        ld g = 0;
        for(int i = 0; i <= K; i++) {
            s[i] = (s[i] + 1) * (pot);
            g += s[i] * c[i];
            pot *= ((ld)a[at] / (ld)a[at + 1]);
        }
        g *= sqrt((ld)a[at + 1]);
        ans += g;
    }

    cout << setprecision(10) << fixed;
    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    calc();
    solve();
    return 0;
}
