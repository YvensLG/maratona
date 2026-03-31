#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
void solve(){
    int n; cin >> n;
    priority_queue<int> pq;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        // slope aumenta em 2 
        pq.push(x); pq.push(x);
        tot += pq.top() - x;
        pq.pop();
    }
    cout << tot << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}