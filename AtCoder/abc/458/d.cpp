#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int x; cin >> x;
    int q; cin >> q;

    ord_set<pii> s;
    int tot = 1;

    s.insert({x, tot});

    for(int i = 0; i < q; i++) {
        tot++;
        int a; cin >> a;
        s.insert({a, tot});
        tot++; cin >> a;
        s.insert({a, tot});

        cout << s.find_by_order(tot / 2) -> first << '\n';
    }

}

signed main() { _
    solve();
}