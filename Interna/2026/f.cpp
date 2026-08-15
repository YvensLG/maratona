#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> nxt = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m, h, w;
vector<string> grid;
vector<vector<int>> comp;

void dfs(int r, int c, int id) {
    comp[r][c] = id;
    
    for (int i = 0; i < 4; i++) {
        int nr = r + nxt[i].first;
        int nc = c + nxt[i].second;
        
        if (nr >= 0 && nr < n && nc >= 0 && nc < m)
            if (grid[nr][nc] == '.' && comp[nr][nc] == 0) dfs(nr, nc, id);
    }
}

void solve() {
    cin >> n >> m >> h >> w;

    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    comp.assign(n, vector<int>(m, 0));
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + (grid[i][j] == '#' ? 1 : 0);
        }
    }

    int comp_id = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && comp[i][j] == 0) {
                comp_id++;
                dfs(i, j, comp_id);
            }
        }
    }

    vector<bool> furo(comp_id + 1, false);

    for (int i = 0; i <= n - h; i++) {
        for (int j = 0; j <= m - w; j++) {
            if (grid[i][j] == '.') {
                if (pref[i + h][j + w] - pref[i][j + w] - pref[i + h][j] + pref[i][j] == 0) {
                    furo[comp[i][j]] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= comp_id; i++) {
        if (furo[i]) ans++;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();

    return 0; 
}
