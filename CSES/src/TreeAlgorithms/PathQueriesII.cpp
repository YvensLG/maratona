#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAX = 2e5 + 5;
int v[MAX];
vector<vi> G;

namespace seg {
    int tree[2 * MAX];
    int n;

    void build(int n2) {
        n = n2;
        for(int i = 0; i <= 2 * n; i++) tree[i] = 0;
    }

    void update(int pos, int x) {
        for (tree[pos += n] = x; pos > 1; pos >>= 1)
            tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        }
        return res;
    }
}

template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, rt, pos;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1),
		  rt(N),pos(N){ dfsSz(0); dfsHld(0); seg::build(N);}
	void dfsSz(int v) {
		for (int& u : adj[v]) {
			adj[u].erase(find(all(adj[u]), v));
			par[u] = v;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(int u, int v, B op) {
		for (;; v = par[rt[v]]) {
			if (pos[u] > pos[v]) swap(u, v);
			if (rt[u] == rt[v]) break;
			op(pos[rt[v]], pos[v] + 1);
		}
		op(pos[u] + VALS_EDGES, pos[v] + 1);
	}
	void updateNode(int u, int val) {
        seg::update(pos[u], val);
    }
    
    int queryPath(int u, int v_node) {
        int res = 0;
        process(u, v_node, [&](int l, int r) {
            res = max(res, seg::query(l, r));
        });
        return res;
    }
};
 
void solve(){
    int n, q; cin >> n >> q;
    G.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
 
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].pb(b); G[b].pb(a);
    }
 
    HLD<false> hld(G);
    for(int i = 0; i < n; i++) {
        hld.updateNode(i, v[i]);
    }

    for(int i = 0; i < q; i++) {
        int c; cin >> c;
        if(c == 1) {
            int s, x; cin >> s >> x; s--;
            hld.updateNode(s, x);
            v[s] = x;
        }
        else {
            int a, b; cin >> a >> b; a--; b--;
            cout << hld.queryPath(a, b) << '\n';
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}