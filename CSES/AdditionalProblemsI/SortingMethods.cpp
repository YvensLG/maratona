#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
#define int long long

typedef long long ll;

using namespace std;

// inversion count
int sort_swap_adj(int n, vector<int> l) {
    vector<int> r = l; sort(r.begin(), r.end());
    vector<int> v(n), bit(n);

	vector<pair<int, int>> w;
	for (int i = 0; i < n; i++) w.push_back({r[i], i+1});
	sort(w.begin(), w.end());

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(w.begin(), w.end(), make_pair(l[i], 0LL));
		if (it == w.end() or it->first != l[i]) return -1;
		v[i] = it->second;
		it->second = -1;
	}

	ll ans = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int j = v[i]-1; j; j -= j&-j) ans += bit[j];
		for (int j = v[i]; j < n; j += j&-j) bit[j]++;
	}
	return ans;
}

int sort_swap(int n, vector<int> v) {
    vector<int> find(n);
    int tot = 0;
    for(int i = 0; i < n; i++) find[v[i]] = i;
    for(int i = 0; i < n; i++) {
        if(v[i] != i) {
            int x = v[i];
            swap(v[i], v[find[i]]);
            swap(find[i], find[x]);
            tot++;
        }
    }
    return tot;
}

// n - lis
int sort_move(int n, vector<int> v) {
	vector<int> ans;
	for (auto t : v){
		auto it = lower_bound(ans.begin(), ans.end(), t);
		if (it == ans.end()) ans.push_back(t);
		else *it = t;
	}
	return n - ans.size();
}

int sort_front(int n, vector<int> v) {
    int at = n - 1;
    for(int i = n - 1; i >= 0; i--) {
        if(v[i] == at) at--;
    }
    return at + 1;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i]; v[i]--;
    }

    cout << sort_swap_adj(n, v) << ' ' << sort_swap(n, v) << ' ' << sort_move(n, v) << ' ' << sort_front(n, v) << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}