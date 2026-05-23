#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pii;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    ordered_set s;

    for(int i = 0; i < n; i++) s.insert({0, i});
    for(int i = 0; i < q; i++) {
        int a, x; cin >> a >> x;
        if(a == 1) {
            x--;
            s.erase({v[x], x});
            v[x]++;
            s.insert({v[x], x});
        }
        else {
            int mini = s.begin() -> first;
            cout << n - s.order_of_key({mini + x, -1}) << '\n';
        }
    }
}

signed main() { _
    solve();
}