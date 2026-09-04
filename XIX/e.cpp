#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

set<int> adj[MAX];

void solve() {
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    set<pair<int, int>> degs;

    for(int i = 0; i < n; i++) {
        degs.insert({adj[i].size(), i});
    }

    while(true) {
        auto it = degs.lower_bound({2, -1});
        if(it == degs.end() || it -> first != 2) break;
    
        int v = it -> second;
        int r = *(adj[v].begin()); 
        int s = *(next(adj[v].begin())); 

        degs.erase({adj[r].size(), r});
        adj[r].erase(v);
        adj[r].insert(s);
        degs.insert({adj[r].size(), r});

        degs.erase({adj[s].size(), s});
        adj[s].erase(v);
        adj[s].insert(r);
        degs.insert({adj[s].size(), s});

        degs.erase({2, v}); degs.insert({0, v});
        adj[v].clear();
    }

    int um = 0, zero = 0;
    for(int i = 0; i < n; i++) {
        if(adj[i].size() == 1) um++; 
        if(adj[i].size() == 0) zero++; 
    }

    if(um + zero == n && um == 2) {
        cout << "Yes\n";
        return;
    } 
    cout << "No\n";
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}