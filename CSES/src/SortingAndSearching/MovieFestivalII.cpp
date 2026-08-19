#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v;
    
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
 
        v.pb({b, a});
    }
 
    sort(v.begin(), v.end());
 
    int total = 0;
    multiset<int> atual;
 
    for(auto x : v){
        int ini = x.second, ed = x.first;
        
        if(atual.empty()){
            atual.insert(ed);
            total ++;
            continue;
        }
 
        if(ini >= *atual.begin()){
            auto it = atual.lower_bound(ini);
            if(it == atual.end() || *it > ini) it = prev(it);
            atual.erase(it);
            atual.insert(ed);
            total++;
        }
        else if(atual.size() < k) {
            atual.insert(ed);
            total++;
        }
    }
 
    cout << total << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}