#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pc __builtin_popcount
 
 
void solve() {
    int n; cin >> n;
    vector<int> x(n);
    for(auto &a : x) cin >> a;

    ord_set<int> s;
    for(int i = 0; i < n; i++) s.insert(i);

    for(int i = 0; i < n; i++) {
        int p; cin >> p;
        auto pos = s.find_by_order(p - 1);
        cout << x[*pos] << ' ';
        s.erase(pos);
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}