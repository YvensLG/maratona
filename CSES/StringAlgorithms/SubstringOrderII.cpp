#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pc __builtin_popcount
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAX = 1e5 + 10;

namespace sam {
	int cur, sz, len[2*MAX], link[2*MAX], acc[2*MAX];
	ll cnt[2 * MAX];
	int nxt[2*MAX][26];

	void add(int c) {
		int at = cur;
		cnt[sz] = 1;
		len[sz] = len[cur]+1, cur = sz++;
		while (at != -1 and !nxt[at][c]) nxt[at][c] = cur, at = link[at];
		if (at == -1) { link[cur] = 0; return; }
		int q = nxt[at][c];
		if (len[q] == len[at]+1) { link[cur] = q; return; }
		int qq = sz++;
		cnt[qq] = 0;
		len[qq] = len[at]+1, link[qq] = link[q];
		for (int i = 0; i < 26; i++) nxt[qq][i] = nxt[q][i];
		while (at != -1 and nxt[at][c] == q) nxt[at][c] = qq, at = link[at];
		link[cur] = link[q] = qq;
	}
	void build(string& s) {
		cur = 0, sz = 0, len[0] = 0, link[0] = -1, sz++;
		for (auto i : s) add(i-'a');
		int at = cur;
		while (at) acc[at] = 1, at = link[at];
	}

	void calc_rep() {
        vector<pair<int, int>> v;
        for (int i = 1; i < sz; i++) {
            v.push_back({len[i], i});
        }
        sort(v.rbegin(), v.rend());
        
        for (auto [l, u] : v) {
            if (link[u] != -1) {
                cnt[link[u]] += cnt[u];
            }
        }
        cnt[0] = 0;
    }

	ll dp[2*MAX];
	ll paths(int i) {
		auto& x = dp[i];
		if (x) return x;
		x = cnt[i];
		for (int j = 0; j < 26; j++) if (nxt[i][j]) x += paths(nxt[i][j]);
		return x;
	}
	void kth_substring(ll k, int at=0) { // k=1 : menor substring lexicog.
		if(at == 0) calc_rep();
		if(k <= cnt[at]) {
			cout << '\n';
			return;
		}
		k -= cnt[at];
		for (int i = 0; i < 26; i++) if (k and nxt[at][i]) {
			if (paths(nxt[at][i]) >= k) {
				cout << char('a'+i);
				kth_substring(k, nxt[at][i]);
				return;
			}
			k -= paths(nxt[at][i]);
		}
	}
};

void solve() {
	string s; cin >> s;
	int n = sz(s);
    ll k; cin >> k;

    sam::build(s);
	sam::kth_substring(k);
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}