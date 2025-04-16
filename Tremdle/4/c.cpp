#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

const int MAX = 200005;

vector<int> g[MAX];

vector<int> topo_sort(int n) {
    vector<int> indegree(n, 0);

    for (int u = 0; u < n; u++) {
        for (int v : g[u]) {
            indegree[v]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        topo.push_back(u);

        for (int v : g[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    if (topo.size() < n)
        return {};

    return topo;
}

void solve() {
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; i++)
  {
    int a, b; cin >> a >> b;
    g[a].push_back(b);
  }
  vector<int> ans = topo_sort(n + 1);
  if(ans.size() == 0) cout << "-1\n";
  else {
    for(auto x : ans) if(x != 0) cout << x << ' ';
    cout << '\n';
  }
}

signed main() { _
  solve();
}