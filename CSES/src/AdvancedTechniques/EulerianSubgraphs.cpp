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

const int MAX = 1e5+5, MOD = 1e9+7;
vector<int> G[MAX];
bool vis[MAX];

void dfs(int s) {
    vis[s] = 1;
    for(auto x : G[s]) if(!vis[x]) dfs(x);
}

ll fexp(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % MOD, e /= 2)
		if (e & 1) ans = ans * b % MOD;
	return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int comp = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            comp++;
        }
    }

    int exp = m - (n - comp);
    cout << fexp(2, exp) << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}