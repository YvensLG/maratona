#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s, t; cin >> s >> t;

    int falta1 = 0, falta2 = 0;
    for(auto x : s) if(x == '0') falta1++;
    for(auto x : t) if(x == '0') falta2++;
    
    ld p = 1;
    if(falta1 == 0 || falta2 == 0) p = 1;
    else p = 1 - (1 - min(a, falta1) / (ld)falta1) * (1 - min(b, falta2) / (ld)falta2);

    int tot = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1' || t[i] == '1') tot++;
    }

    cout << setprecision(15) << fixed;
    cout << tot + (n - tot) * p << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();

    return 0;
}
