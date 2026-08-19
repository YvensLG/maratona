#include <bits/stdc++.h>
 
#define int long long
#define pb push_back
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

const int MAX = 3001;

int n, k;
ll dp[MAX], x[MAX], psum[MAX];
ll res[MAX];

struct DP { // Modify at will:
    int lo(int ind) { return 0; }
    int hi(int ind) { return ind; }
    ll f(int ind, int fim) { 
        ll at = psum[ind] - psum[fim];
        return at * at + dp[fim];
    }
    void store(int ind, int k, ll v) { res[ind] = v; }
    void rec(int L, int R, int LO, int HI) {
        if (L >= R) return;
        int mid = (L + R) >> 1;
        pair<ll, int> best(LLONG_MAX, LO);
        rep(k, max(LO,lo(mid)), min(HI,hi(mid)))
            best = min(best, make_pair(f(mid, k), k));
        store(mid, best.second, best.first);
        rec(L, mid, LO, best.second+1);
        rec(mid+1, R, best.second, HI);
    }
    void solve(int L, int R) { rec(L, R, INT_MIN, INT_MAX); }
};

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        psum[i] = psum[i - 1] + x[i];
        dp[i] = psum[i] * psum[i];
    }

    DP dcdp;

    for(int j = 1; j < k; j++) {
        dcdp.solve(1, n + 1);
        for(int i = 0; i <= n; i++) dp[i] = res[i];
    }
    
    cout << dp[n] << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}