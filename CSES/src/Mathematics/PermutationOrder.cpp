#include <bits/stdc++.h>
using namespace std;
#define MAX 21
#define M 1000000007
#define INF 2000000007
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef vector<double> vd;
typedef vector<int> vi;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll fat[MAX];

void calc(){
	fat[0] = 1;
	for(int i = 1; i < MAX; i++) fat[i] = fat[i - 1] * i;
}

bool comp(vi a, vi b) {
	int flag = false;
	for(int i = 0; i < min(a.size(), b.size()); i++) {
		if(a[i] > b[i]) {
			flag = false;
			break;
		}

		if(a[i] < b[i]) {
			flag = true;
			break;
		}
	}

	return flag;
}

vi solve1(ll n, ll k) {
	ordered_set<int> s;
	for(int i = 1; i <= n; i++) s.insert(i);
	vi p;

	while(!s.empty()) {
		ll at = (k - 1) / fat[s.size() - 1];
		k -= at * fat[s.size() - 1];
		
		auto it = s.find_by_order(at);
		p.push_back(*it);
		s.erase(it);
	}

	return p;
}

void solve2() {
	int n; cin >> n;
	vi p(n);
	for(int i = 0; i < n; i++) cin >> p[i];

	ll l = 0, r = fat[n];
	while(r - l > 1) {
		ll m = (l + r) / 2;
		if(comp(solve1(n, m), p)) l = m;
		else r = m;
	}

	cout << r << '\n';
}

signed main() {
	calc();
	int t; cin >> t; while(t--) {
		int a; cin >> a;
		if(a == 1) {
			ll n, k; cin >> n >> k;
			for(auto x : solve1(n, k)) cout << x << ' '; cout << '\n';
		}
		else solve2();
	}

	return 0;
}