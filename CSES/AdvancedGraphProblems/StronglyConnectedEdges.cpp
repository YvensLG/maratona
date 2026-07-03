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
 
const int MAX = 1e5 + 1;

vi G[MAX];
int vis[MAX];
int pai[MAX];

int cnt = 0;

void dfs(int at) {
    cnt++; vis[at] = cnt;
    for(auto x : G[at]) {
        if(!vis[x]) {
            pai[x] = at;
            dfs(x);
        }
    }
}

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
    int low = val[j] = ++Time, x; z.push_back(j);
    for (auto e : g[j]) if (comp[e] < 0)
        low = min(low, val[e] ?: dfs(e,g,f));
    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        f(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
    int n = sz(g);
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

void solve(){
    int n, m; cin >> n >> m;
    vector<pii> edg(m);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        edg[i] = {a, b};
    }

    dfs(1);
    if(cnt != n) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<vi> G_aux(n + 1);

    for(auto [a, b] : edg) {
        if(pai[a] == b) {
            G_aux[b].push_back(a);
            continue;
        }
        if(pai[b] == a) {
            G_aux[a].push_back(b);
            continue;
        }
        if(vis[a] > vis[b]) swap(a, b);
        G_aux[b].push_back(a);
    }

    int res = 0;
    
    scc(G_aux, [&](vi& c) {
        res = max(res, sz(c));
    });

    if (res == n) {
        for(int i = 1; i <= n; i++) {
            for(auto x : G_aux[i]) {
                cout << i << ' ' << x << '\n';
            }
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }

}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}