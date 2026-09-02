#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep( i, a, b ) for( int i = a; i < (b); i++ )

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii; 
typedef vector<int> vi; 

const int MAX = 1024;
int M[MAX][MAX];

int hopcroftKarp(vector<vi>& g, vi& r) {
    int n = sz(g), res = 0;
    vi l(n, -1), q(n), d(n);
    auto dfs = [&](auto f, int u) -> bool {
        int t = exchange(d[u], 0) + 1;
        for (int v : g[u])
            if (r[v] == -1 || (d[r[v]] == t && f(f, r[v])))
                return l[u] = v, r[v] = u, 1;
        return 0;
    };
    for (int t = 0, f = 0;; t = f = 0, d.assign(n, 0)) {
        rep(i,0,n) if (l[i] == -1) q[t++] = i, d[i] = 1;
        rep(i,0,t) for (int v : g[q[i]]) {
            if (r[v] == -1) f = 1;
            else if (!d[r[v]]) d[r[v]] = d[q[i]] + 1, q[t++] = r[v];
        }
        if (!f) return res;
        rep(i,0,n) if (l[i] == -1) res += dfs(dfs, i);
    }
}

void solve(){
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c; cin >> c;
            M[i][j] = c - '0';
        }
    }

    vector<pii> edge(n, {-1, -1});
    int new_c1 = 0, new_c2 = 0;
    queue<int> q;
    vector<bool> vis(n, false);
    
    for(int ini = 0; ini < n; ini++) {
        if(vis[ini]) continue;
        vis[ini] = true;
        q.push(ini);

        while(!q.empty()) {
            int i = q.front(); q.pop();
            if(edge[i].first != -1 && edge[i].second != -1) continue;
            
            vi comp1, comp2;
            for(int j = 0; j < n; j++) {
                if(M[i][j]) {
                    if(comp1.empty() || M[j][comp1[0]]) comp1.push_back(j);
                    else comp2.push_back(j);
                }
            }
            
            if(comp1.empty()) {
                if(edge[i].first == -1) edge[i].first = new_c1++;
                if(edge[i].second == -1) edge[i].second = new_c2++;
                continue;
            }
            
            bool troca = false;

            if(edge[i].first != -1) {
                if(!comp2.empty() && edge[comp2[0]].first == edge[i].first) troca = true;
            }
            else if(edge[i].second != -1) {
                if(!comp1.empty() && edge[comp1[0]].second == edge[i].second) troca = true;
            }
            else {
                bool f1 = false, f2 = false;
                for(int x : comp1) if(edge[x].first != -1) f1 = true;
                for(int x : comp2) if(edge[x].second != -1) f2 = true;
                
                troca = f1 || f2;
            }
            if(troca) swap(comp1, comp2);

            if(edge[i].first == -1) {
                edge[i].first = new_c1++;
                for(int x : comp1) edge[x].first = edge[i].first;
            }
            
            if(edge[i].second == -1) {
                edge[i].second = new_c2++;
                for(int x : comp2) edge[x].second = edge[i].second;
            }

            for(int x : comp1) if(!vis[x]) { vis[x] = true; q.push(x); }
            for(int x : comp2) if(!vis[x]) { vis[x] = true; q.push(x); }
        }
    }

    vector<vi> g(n + 1); vi r(n + 1, -1);
    for(auto [a, b] : edge) g[a].push_back(b);
    cout << hopcroftKarp(g, r) << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}