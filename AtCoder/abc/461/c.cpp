#include <bits/stdc++.h>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, k, m; cin >> n >> k >> m;
    vector<bool> mark(n + 1);
    priority_queue<pii> pq;
    for(int i = 0; i < n; i++) {
        int c, v; cin >> c >> v;
        pq.push({v, c});
    }
    vector<pii> not_used;
    int col = 0, ans = 0, tot = m;
    while(pq.size() && col < m) {
        auto [v, c] = pq.top(); pq.pop();
        if(!mark[c]) {
            col++;
            mark[c] = 1;
            ans += v;
        }
        else {
            not_used.push_back({v, c});
        }
    }

    for(auto x : not_used) pq.push(x);

    while(tot < k) {
        auto [v, c] = pq.top(); pq.pop();
        ans += v;
        tot++;
    }

    cout << ans << '\n';
}

signed main() { _
    solve();
}