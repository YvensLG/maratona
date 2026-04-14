#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
#define F first
#define S second
 
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAX = 2e5 + 5;
vector<vi> G(MAX);
int ans[MAX];

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
 
struct LCA {
	int T = 0;
	vi time, path, ret, pai;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), pai(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
        pai[v] = par;
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

void dfs(int v, int p) {
    for(auto x : G[v]) {
        if(x == p) continue;
        dfs(x, v);
        ans[v] += ans[x];
    }
}
 
void solve(){
    int n, m; cin >> n >> m;
 
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].pb(b); G[b].pb(a);
    }

    LCA lca(G);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        int c = lca.lca(a, b);

        if(c == b) swap(a, b);
        if(c == a) {
            ans[b]++;
        }
        else {
            ans[a]++; ans[b]++; ans[c]--;
        }

        if(lca.pai[c] >= 0) ans[lca.pai[c]]--;
    }

    dfs(0, -1);

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
 
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}