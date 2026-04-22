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

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string s, int lim=256) { // or vector<int>
		s.push_back(0); int n = sz(s), k = 0, a, b;
		vi x(all(s)), y(n), ws(max(n, lim));
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
			for (k && k--, j = sa[x[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

vector<int> next_smaller(const vi& v) {
	int n = v.size();
    vector<int> ans(n, -1), st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[i] < v[st.back()]) {
            ans[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}

void solve() {
	string s; cin >> s;
	int n = sz(s);
    ll k; cin >> k;

    SuffixArray SA(s);
	vi sa = SA.sa;
	vi lcp = SA.lcp;
	lcp.push_back(0);
	vi nxt = next_smaller(lcp);

	ll cnt = 0;

	for(int i = 1; i <= n; i++) {
		if(i != n && lcp[i + 1] > lcp[i]) {
			int rep = nxt[i + 1] - i;

			if(cnt + rep * (lcp[i + 1] - lcp[i]) >= k) {
				int j = (k - cnt + rep - 1) / rep + lcp[i];
				for(int k = 0; k < j; k++) {
					cout << s[k + sa[i]];
				}
				cout << '\n';
				return;
			}
			cnt += rep * (lcp[i + 1] - lcp[i]);

			if(cnt + n - sa[i] - lcp[i + 1] >= k) {
				int j = k - cnt;
				for(int k = 0; k < j; k++) {
					cout << s[k + sa[i]];
				}
				cout << '\n';
				return;
			}
			cnt += n - sa[i] - lcp[i + 1];
		}
		else {
			if(cnt + (n - SA.sa[i]) - SA.lcp[i] < k) {
				cnt += (n - SA.sa[i]) - SA.lcp[i];
				continue;
			}
	
			ll posfim = SA.lcp[i] + k - cnt;
	
			for(int j = SA.sa[i]; j < SA.sa[i] + posfim; j++) {
				cout << s[j];
			}
			cout << '\n';
			return;
		}
	}
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}