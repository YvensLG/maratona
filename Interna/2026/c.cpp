#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e6 + 10; 
const int mod = 1e9 + 7; 
const int b1 = 1'000'033; 
const int b2 = 500'000'071;

int n, m;
vector<int> h, a, skills;
vector<vector<int>> G;

auto check(int mid) {
    vector<int> deg(n + 1, 0);
    vector<bool> atv(n + 1, false);
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (h[i] >= mid) atv[i] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (atv[i]) {
            for (int viz : G[i])
                if (atv[viz]) deg[i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (atv[i] && deg[i] < a[i]) {
            atv[i] = false;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int viz : G[u]) {
            if (atv[viz]) {
                deg[viz]--;
                if (deg[viz] < a[viz]) {
                    atv[viz] = false;
                    q.push(viz);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) if (atv[i]) return true;
    return false;
}

void solve() {
    cin >> n >> m;

    h.resize(n + 1), a.resize(n + 1), skills.clear();
    G.clear(), G.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        skills.push_back(h[i]);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    sort(skills.begin(), skills.end());

    int l = 0, r = n - 1;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        
        if (check(skills[mid])) {
            ans = skills[mid];
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 

    int t; cin >> t; while(t--)
    solve();

    return 0; 
}
