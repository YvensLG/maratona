#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

// grafo bipartido de linha vs colunas. 
// tudo na mesma componente conexa vai ser preenchido

const int MAX = 100005;
vector<vector<int>> G(2 * MAX);
vector<int> mark(2 * MAX);

pair<int, int> dfs(int at, int c)
{
    mark[at] = 1;
    pair<int, int> ans;
    for(auto x : G[at])
    {
        if(mark[x] == 0){
            pair<int, int> at = dfs(x, 1 - c);
            ans.first += at.first;
            ans.second += at.second;
        }
    }

    if(c == 0) ans.first += 1;
    else ans.second += 1;

    return ans;
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        G[x].push_back(y + MAX);
        G[y + MAX].push_back(x);
    }

    int tot = 0;

    for(int i = 0; i < MAX; i++)
    {
        pair<int, int> ans;
        if(mark[i] == 0) ans = dfs(i, 0);
        tot += ans.first * ans.second;
    }

    cout << tot - n << '\n';
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();
}