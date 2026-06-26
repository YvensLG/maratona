#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<string> a, ans;
int N, M;

int f(int i, int j) {
    return i * M + j;
}

pii g(int x) {
    return pii(x / M, x % M);
}

struct TwoSat {
    int N;
    vector<vi> gr;
    vi values; // 0 = false, 1 = true

    TwoSat(int n = 0) : N(n), gr(2*n) {}

    int addVar() { // (optional)
        gr.emplace_back();
        gr.emplace_back();
        return N++;
    }

    void either(int f, int j) {
        f = max(2*f, -1-2*f);
        j = max(2*j, -1-2*j);
        gr[f].push_back(j^1);
        gr[j].push_back(f^1);
    }
    void setValue(int x) { either(x, x); }

    void xr(int f, int j) {
        either(f, j);
        either(~f, ~j);
    }

    void that(int u, int d, int l, int r) {
        // either(u, l);
        // either(u, r);
        // either(d, l);
        // either(d, r);
        xr(u, l);
        xr(u, r);
        xr(d, l);
        xr(d, r);
    }

    void atMostOne(const vi& li) { // (optional)
        if (sz(li) <= 1) return;
        int cur = ~li[0];
        rep(i,2,sz(li)) {
            int next = addVar();
            either(cur, ~li[i]);
            either(cur, next);
            either(~li[i], next);
            cur = ~next;
        }
        either(cur, ~li[1]);
    }

    vi val, comp, z; int time = 0;
    int dfs(int i) {
        int low = val[i] = ++time, x; z.push_back(i);
        for(int e: gr[i]) if (!comp[e])
            low = min(low, val[e] ?: dfs(e));
        if (low == val[i]) do {
            x = z.back(); z.pop_back();
            comp[x] = low;
            if (values[x>>1] == -1)
                values[x>>1] = x&1;
        } while (x != i);
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2*N, 0); comp = val;
        rep(i,0,2*N) if (!comp[i]) dfs(i);
        rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
        return 1;
    }
};

int u(int i, int j) {
    return f(2 * i, 2 * j + 1);
}

int d(int i, int j) {
    return f(2 * i + 2, 2 * j + 1);
}

int l(int i, int j) {
    return f(2 * i + 1, 2 * j);
}

int r(int i, int j) {
    return f(2 * i + 1, 2 * j + 2);
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    N = 2 * n + 1;
    M = 2 * m + 1;

    ans.resize(N);

    for (int i = 0; i < N; ++i) {
        ans[i].clear();
        for (int j = 0; j < M; ++j) {
            ans[i].push_back('.');
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '0') {
                ans[2 * i + 1][2 * j + 1] = 'o';
            }
        }
    }

    TwoSat ts(N * M);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            if (a[i][j] == '0') {
                ts.setValue(~u(i, j));
                ts.setValue(~d(i, j));
                ts.setValue(~l(i, j));
                ts.setValue(~r(i, j));
            } else if (a[i][j] == '1') {
                ts.that(u(i, j), d(i, j), l(i, j), r(i, j));
            } else if (a[i][j] == '2') {
                ts.xr(u(i, j), d(i, j));
                ts.xr(l(i, j), r(i, j));
            } else if (a[i][j] == '3') {
                ts.xr(u(i, j), r(i, j));
                ts.setValue(~l(i, j));
                ts.setValue(~d(i, j));
            } else if (a[i][j] == '4') {
                ts.xr(u(i, j), d(i, j));
                ts.setValue(~l(i, j));
                ts.setValue(~r(i, j));
            } else if (a[i][j] == '5') {
                ts.xr(u(i, j), l(i, j));
                ts.setValue(~d(i, j));
                ts.setValue(~r(i, j));
            } else if (a[i][j] == '6') {
                ts.xr(d(i, j), r(i, j));
                ts.setValue(~u(i, j));
                ts.setValue(~l(i, j));
            } else if (a[i][j] == '7') {
                ts.xr(l(i, j), r(i, j));
                ts.setValue(~u(i, j));
                ts.setValue(~d(i, j));
            } else if (a[i][j] == '8') {
                ts.xr(d(i, j), l(i, j));
                ts.setValue(~u(i, j));
                ts.setValue(~r(i, j));
            } else if (a[i][j] == '9') {
                ts.setValue(u(i, j));
                ts.setValue(d(i, j));
                ts.setValue(l(i, j));
                ts.setValue(r(i, j));
            } else if (a[i][j] == 'A') {
                ts.setValue(l(i, j));
                ts.setValue(r(i, j));
                ts.xr(u(i, j), d(i, j));
            } else if (a[i][j] == 'B') {
                ts.setValue(u(i, j));
                ts.setValue(d(i, j));
                ts.xr(l(i, j), r(i, j));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ts.setValue(~l(i, 0));
        ts.setValue(~r(i, m - 1));
    }
    for (int j = 0; j < m; ++j) {
        ts.setValue(~u(0, j));
        ts.setValue(~d(n - 1, j));
    }

    ts.solve();

    for (int k = 0; k < sz(ts.values); ++k) {
        if (ts.values[k]) {
            auto [i, j] = g(k);
            if (i % 2 == 1 && j % 2 == 0) {
                ans[i][j] = '-';
            } else if (i % 2 == 0 && j % 2 == 1) {
                ans[i][j] = '|';
            }
        }
    }

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < M - 1; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
