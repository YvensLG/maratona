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
 

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), q;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push_back(i);
	rep(j,0,sz(q)) for (int x : gr[q[j]])
		if (--indeg[x] == 0) q.push_back(x);
	return q;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> G(n+1), Grev(n+1);

    for(int i = 1; i <= n; i++) {
        G[0].push_back(i);
        Grev[i].push_back(0);
    }

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        Grev[b].push_back(a);
    }

    auto top = topoSort(G);
    vi rec(n+1);
    set<int> S = {0};

    vector<bool> liga(n + 1);
    for(int i = 1; i <= n; i++) {
        int v = top[i], u = top[i-1];
        for(auto x : Grev[v]) {
            if(x == u) {
                liga[i] = true;
                break;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        int v = top[i], u = top[i-1];
        int q = -1;

        for(auto x : Grev[v]) {
            auto it = S.find(x);
            if(it != S.end()) {
                q = *it;
                break;
            }
        }

        if(!liga[i]) {
            if(q != -1) {
                rec[i] = q;
                S.clear();
                S.insert(u);
            }
            else {
                cout << "NO\n";
                return;
            }
        }
        else {
            if(q != -1) {
                rec[i] = q;
                S.insert(u);
            }
        }
    }

    cout << "YES\n";
    vi color(n + 1);
    color[top[n]] = 1;
    for(int i = n; i >= 1; i--) {
        int v = top[i];
        int u = top[i-1];
        
        if(color[u] == 0 && liga[i]) {
            color[u] = color[v];
        }
        else if(color[u] == 0 && !liga[i]) {
            color[u] = 3 - color[v];
        }
        
        if(color[u] != color[v]) {
            color[rec[i]] = color[v];
        }
    }

    vi c[2];
    for(int i = 1; i <= n; i++) {
        c[color[top[i]] - 1].push_back(top[i]);
    }

    for(int q = 0; q <= 1; q++){
        cout << c[q].size() << ' ';
        for(auto x : c[q]) cout << x << ' '; cout << '\n';
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}