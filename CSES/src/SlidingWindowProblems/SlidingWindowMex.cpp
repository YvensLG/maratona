#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> x(n);
    vector<int> v(n, 0);
    set<int> ans;
    int rem = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        if(x[i] < n && i < k) v[x[i]]++;
    }
    ans.insert(n);
    for(int i = 0; i < n; i++) {
        if(v[i] == 0) {
            ans.insert(i);
        }
    }
    cout << *ans.begin() << ' ';
    for(int i = k; i < n; i++) {
        if(x[i] < n) {
            v[x[i]]++;
            ans.erase(x[i]);
        }
        if(x[i - k] < n) {
            v[x[i - k]]--;
            if(v[x[i - k]] == 0) ans.insert(x[i - k]);
        }
        cout << *ans.begin() << ' ';
    }
    cout << '\n';
}
 
signed main() { _
    solve();
}
