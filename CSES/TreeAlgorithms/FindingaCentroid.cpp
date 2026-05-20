#include <bits/stdc++.h>
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
 
const int MAX = 2e5 + 5;
const int LOG = 19;
const int INF = 1e9;

int n, subsize[MAX];
vector<int> g[MAX];

void dfs(int k, int p=-1) {
	subsize[k] = 1;
	for (int i : g[k]) if (i != p) {
		dfs(i, k);
		subsize[k] += subsize[i];
	}
}

int centroid(int k, int p=-1, int size=-1) {
	if (size == -1) size = subsize[k];
	for (int i : g[k]) if (i != p) if (subsize[i] > size/2)
		return centroid(i, k, size);
	return k;
}

pair<int, int> centroids(int k=0) {
	dfs(k);
	int i = centroid(k), i2 = i;
	for (int j : g[i]) if (2*subsize[j] == subsize[k]) i2 = j;
	return {i, i2};
}

void solve(){
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto ans = centroids();
    cout << ans.first + 1 << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}