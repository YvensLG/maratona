#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pc __builtin_popcount
 
#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	string s;
	vector<pair<char, int>> t;
	cin >> s;

	for(int i = 0; i < sz(s); i++) {
		t.push_back({s[i], i});
	}
	sort(t.begin(), t.end());

	char c; int p = 0;
	for(int i = 0; i < sz(s); i++) {
		tie(c, p) = t[p];
		if(c != '#') cout << c;
	}
	cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}