#include <bits/stdc++.h>

#define FOR(i, L, R) for (ll i = (L); i <= (R); i++)
#define RFOR(i, L, R) for (ll i = (R); i >= (L); i--)
#define REP(t) for (ll _=t;_--;)

#define sz(v) ll((v).size())
#define all(v) begin(v), end(v)
#define pb push_back
#define pc(x) __builtin_popcountll(x)

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int fexp(int a, int b) {
    int r = 1;
    for (; b > 0; b>>=1) {
        if (b&1) r = r * a % MOD;
        a = a *a % MOD;
    }
    return r;
}


void solve() {
    int A, B;
    cin >> A >> B;

    A--; B--;
    int n = 0;
    
    for(int S = A + B; S >= max(A + B - 70, 0LL); S--) {
        for(int x = min(A, S), y = S - x; (x >= 0) && (y <= B); x--, y++) {
            n = max(n, x + y + pc(x + y) - pc(x) - pc(y));
        }
    }
    
    cout << fexp(2, n + 1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}