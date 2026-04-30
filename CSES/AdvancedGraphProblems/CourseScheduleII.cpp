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
 
const int MAX = 1e5 + 10;
vector<int> G[MAX], ans;
int deg_in[MAX];
 
void solve(){
    int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		G[b].push_back(a);
		deg_in[a]++;
	}
 
	priority_queue<int> pq;
 
	for(int i = n; i >= 1; i--) {
		if(!deg_in[i]) pq.push(i);
	}
 
	while(!pq.empty()) {
		int at = pq.top(); pq.pop();
		ans.push_back(at);
		for(auto x : G[at]) {
			deg_in[x]--;
			if(deg_in[x] == 0) pq.push(x);
		}
	}
 
	reverse(all(ans));
	for(auto x : ans) cout << x << ' ';
	cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}