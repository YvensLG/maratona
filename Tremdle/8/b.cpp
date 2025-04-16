#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

vector<int> oneCompression(1, 1);
vector<vector<int>> G;
vector<int> path;
int actual_size = 0;

void keepOnlyPathEdges() {
    unordered_set<int> keep(path.begin(), path.end());

    for (int u = 0; u < G.size(); u++) {
        if (!keep.count(u)) {
            G[u].clear();
            continue;
        }

        vector<int> newAdj;
        for (int v : G[u]) {
            if (keep.count(v)) {
                newAdj.push_back(v);
            }
        }
        G[u] = move(newAdj);
    }
}

void compressPathToOne() {
    unordered_set<int> pathSet(path.begin(), path.end());

    unordered_set<int> outgoing;
    for (int u : path) {
        if(u != 1) oneCompression.push_back(u);
        for (int v : G[u]) {
            if (!pathSet.count(v))
                outgoing.insert(v);
        }
    }

    for (int u = 0; u < G.size(); ++u) {
        if (pathSet.count(u)) continue;
        for (int& v : G[u]) {
            if (pathSet.count(v)) {
                v = 1;
            }
        }
    }

    for (int u : path) {
        if (u != 1) {
            G[u].clear();
        }
    }

    G[1].clear();
    for (int v : outgoing) {
        if (v != 1)
            G[1].push_back(v);
    }
}

void find_path(int at, int pai)
{
    path.push_back(at);
    if(2 * path.size() >= actual_size) return;
    for(auto v : G[at])
    {
        if(v != pai)
        {
            find_path(v, at);
            if(2 * path.size() >= actual_size) return;
        }
    }
}

void solve() {
    int n; cin >> n;
    actual_size = n;
    G.resize(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n == 1)
    {
        cout << "! 1\n";
        cout.flush();
        return; 
    }

    while(true)
    {
        if(actual_size <= 1)
        {
            cout << "! 1\n";
            cout.flush();
            return;
        }
        if(actual_size == 2 && oneCompression.size() > 1)
        {
            cout << "! " << G[1][0] << '\n';
            cout.flush();
            return;
        }
        else if (actual_size == 2)
        {
            cout << "? 1 1\n"; 
            cout.flush();
            int a; cin >> a;
            if(a == 0) cout << "! " << G[1][0] << '\n';
            else cout << "! 1\n";
            return;
        }

        path.clear();
        find_path(1, -1);
        
        cout << "? " << path.size() + oneCompression.size() - 1 << ' ';
        for(auto x : path) 
        {
            if(x == 1)
            {
                for(auto y : oneCompression) cout << y << ' ';
                continue;
            }
            cout << x << ' ';
        }
        cout << '\n';
        cout.flush();

        int esta;
        cin >> esta;

        if(esta == 1) 
        {
            keepOnlyPathEdges();
        }
        else
        {
            compressPathToOne();
        }

        actual_size = 0;
        for(int i = 0; i <= n; i++) if(G[i].size() != 0) actual_size++;
    }

    for(auto x : path) cout << x << ' ';
    cout << '\n';

    for(int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for(auto x : G[i])
            cout << x << ' ';
        cout << '\n';
    }

}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();
}