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
typedef long double ld;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

tuple<bool, ld, ld> solve_quad(int a, int b, int c){
    ld delta = b * b - 4 * a * c;
    if(delta <= 0) return {0, 0, 0};

    delta = sqrt(delta);
    ld x1 = (-b - delta) / (2 * a);
    ld x2 = (-b + delta) / (2 * a);

    return {1, min(x1, x2), max(x1, x2)};
}

int calc_non_intersect(const vector<pair<ld, ld>>& v) {
    int tot = 0, n = v.size();
    for(int i = 0; i < n; i++) {
        ld r = v[i].second;
        auto it = lower_bound(v.begin(), v.end(), make_pair(r, -(ld)INF));
        tot += n - (it - v.begin());
    }
    return tot;
}

int calc_rep(const vector<pair<ld, ld>>& v) {
    if(v.size() == 0) return 0;
    ld at = v[0].first;
    int rep = 0;
    int tot = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].first == at) rep++;
        else {
            tot += rep * (rep - 1) / 2;
            rep = 1;
            at = v[i].first;
        }
    }
    tot += rep * (rep - 1) / 2;
    return tot;
}

int calc_rep_rev(const vector<pair<ld, ld>>& v) {
    if(v.size() == 0) return 0;
    ld at = v[0].second;
    int rep = 0;
    int tot = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].second == at) rep++;
        else {
            tot += rep * (rep - 1) / 2;
            rep = 1;
            at = v[i].second;
        }
    }
    tot += rep * (rep - 1) / 2;
    return tot;
}

template<typename T> ll inv_count(vector<T> l, vector<T> r = {}) {
	if (!r.size()) {
		r = l;
		sort(r.begin(), r.end());
	}
	int n = l.size();
	vector<int> v(n), bit(n);
	vector<pair<T, int>> w;
	for (int i = 0; i < n; i++) w.push_back({r[i], i+1});
	sort(w.begin(), w.end());
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(w.begin(), w.end(), make_pair(l[i], 0LL));
		if (it == w.end() or it->first != l[i]) return -1; // nao da
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

bool comp(pair<ld, ld> a, pair<ld, ld> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void solve(){
    int n, a, b; cin >> n >> a >> b;
    vector<pair<ld, ld>> v;

    for(int i = 0; i < n; i++) {
        int m, c; cin >> m >> c;
        auto [f, x1, x2] = solve_quad(a, -m, b - c);
        if(f) v.push_back({x1, x2});
    }

    n = v.size();
    
    sort(v.begin(), v.end(), comp);
    int ans1 = inv_count<pair<ld, ld>>(v);
    int ans4 = calc_rep_rev(v);

    sort(v.begin(), v.end());
    int ans2 = calc_non_intersect(v);
    int ans3 = calc_rep(v);

    cout << n * (n - 1) / 2 - ans1 - ans2 - ans3 - ans4 << '\n';
}

signed main() { _
    solve();
    return 0;
}