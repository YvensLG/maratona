#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
 
unordered_map<int, int> qntt;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> x(n);
    vector<set<int>> lvl(n + 1);
    int bst = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        if(i < k) {
            qntt[x[i]]++;
            bst = max(bst, qntt[x[i]]);
        }
    }
    for(int i = 0; i < k; i++) {
        lvl[qntt[x[i]]].insert(x[i]);
    }
 
    cout << *lvl[bst].begin() << ' ';
    for(int i = k; i < n; i++) {
        lvl[qntt[x[i]]].erase(x[i]);
        qntt[x[i]]++;
        lvl[qntt[x[i]]].insert(x[i]);
        bst = max(bst, qntt[x[i]]);
        
        lvl[qntt[x[i - k]]].erase(x[i - k]);
        qntt[x[i - k]]--;
        if(qntt[x[i - k]] != 0)
            lvl[qntt[x[i - k]]].insert(x[i - k]);
        if(lvl[bst].empty())
            bst--;
 
        cout << *lvl[bst].begin() << ' ';
    }
    cout << '\n';
}
 
signed main() { _
    solve();
}