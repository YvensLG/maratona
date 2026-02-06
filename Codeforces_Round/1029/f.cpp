#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1'000'000'007LL;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

int n;
vector<vector<int>> g;
vector<int> parent, depth;
vector<int> order;

int fexp(int base, int exp) {
    int res = 1;
    int b = base;
    while (exp) {
        if (exp & 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        exp >>= 1;
    }
    return res;
}

void bfs()
{
    parent.clear();
    depth.clear();
    order.clear();
    parent.resize(n + 1, 0);
    depth.resize(n + 1, 0);
    order.resize(n + 1, 0);
    queue<int> q;
    q.push(1);
    parent[1] = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : g[u]) if (!parent[v]) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            q.push(v);
        }
    }
}

int chain_len(int start, int root)
{
    int len  = 1;
    int prev = root;
    int cur  = start;

    while (true) {
        int next = -1;

        for (int to : g[cur]) {
            if (to == prev) continue;
            if (parent[to] == cur) {
                next = to;
                break;
            }
        }

        if (next == -1) break;

        prev = cur;
        cur  = next;
        ++len;
    }
    return len;
}


void solve(){
    cin >> n;
    g.clear();
    g.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs();

    int folhas = 0;
    int ramos = 0;
    int raiz = -1;
    vector<int> filhos(n + 1, 0);
    for (int v = 2; v <= n; ++v) {
        filhos[parent[v]]++;
    }
    for (int u = 1; u <= n; ++u) {
        if (filhos[u] == 0 && u != 1) folhas++;
        if (filhos[u] > 1) {
            ramos++;
            raiz = u;
        }
    }

    if (folhas > 2 || ramos > 1) {
        cout << 0 << '\n';
        return;
    }

    if (ramos == 0) {
        cout << fexp(2, n) << '\n';
        return;
    }


    vector<int> arms;
    for (int v : g[raiz]) if (parent[v] == raiz) arms.push_back(v);

    int len1 = chain_len(arms[0], raiz);
    int len2 = chain_len(arms[1], raiz);

    if (len1 == len2) {
        int ans = fexp(2, depth[raiz]);
        ans = (ans * 4) % MOD;
        cout << ans << '\n';
    } else {
        int diff = llabs(len1 - len2);
        int expo = depth[raiz] + diff;
        long long ans = fexp(2, expo);
        ans = (ans * 3) % MOD;
        cout << ans << '\n';
    }
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}