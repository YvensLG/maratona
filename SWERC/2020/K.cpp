#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string s, int lim=256) {
        s.push_back(0); int n = sz(s), k = 0, a, b;
        vi x(all(s)), y(n), ws(max(n, lim));
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i,0,n) if(sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i,0,n) ws[x[i]]++;
            rep(i, 1, lim) ws[i] += ws[i - 1];
            for (int i = n; i--; ) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i, 1, n) a = sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b]  && y[a + j] == y[b + j]) ? p-1 : p++;
        }
        for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
            for (k && k--, j = sa[x[i] - 1];
                s[i + k] == s[j + k]; k++);
    }
};

void solve() {
    string s; cin >> s;
    SuffixArray SA(s);
    int n = s.size();

    int ans = -1, mini = 1e9;
    for(int i = 1; i <= n; i++) {
        int at = SA.lcp[i] + 1;
        if(i != n) at = max(at, SA.lcp[i + 1] + 1);

        if(at + SA.sa[i] >= n + 1) continue;
        if(at < mini) {
            mini = at;
            ans = SA.sa[i];
        }
        else if(at == mini) {
            ans = min(ans, SA.sa[i]);
        }
    }

    for(int i = ans; i < ans + mini; i++) {
        cout << s[i];
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}