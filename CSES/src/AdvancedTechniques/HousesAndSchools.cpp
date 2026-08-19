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
 
const int MAX = 3e3 + 3;
const int LINF = 4000000000000000000;
 
int dp[MAX][MAX];

int n, K;
int cur_j;
int c[MAX], pref[MAX], pref1[MAX];

int cost(int i, int k) {
    int m = (k + i) / 2;
    int p1 = (pref1[m] - pref1[k - 1]) - k * (pref[m] - pref[k - 1]);
    int p2 = i * (pref[i] - pref[m]) - (pref1[i] - pref1[m]);
    return p1 + p2;
}

struct DP {
	int lo(int ind) { return cur_j - 1; }
	int hi(int ind) { return ind; }
	ll f(int ind, int k) { return dp[k][cur_j - 1] + cost(ind, k); }
	void store(int ind, int k, ll v) { dp[ind][cur_j] = v; }

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
	void solve(int L, int R) { rec(L, R, 0, n + 1); }
};
 
void solve(){
    cin >> n >> K;
	for(int i = 1; i <= n; i++) {
        cin >> c[i];
        pref[i] = pref[i - 1] + c[i];
        pref1[i] = pref1[i - 1] + c[i] * i;
    }
 
    DP dcdp;

    for(int i = 1; i <= n; i++) dp[i][1] = pref[i] * i - pref1[i];
 
    for(int j = 2; j <= K; j++) {
        cur_j = j;
        dcdp.solve(1, n + 1);
    }
 
    int ans = LINF;
 
    for(int i = K; i <= n; i++) {
        ans = min(ans, dp[i][K] + (pref1[n] - pref1[i - 1]) - i * (pref[n] - pref[i - 1]));
    }
 
    cout << ans << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}