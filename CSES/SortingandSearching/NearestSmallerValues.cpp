#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e5+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return true;
    else if(a.first == b.first){
        return a.second > b.second;
    }
    return false;
}
 
void solve(){
    int n; cin >> n;
    vector<pair<int, int>> a(n + 1);
    a[0] = {0, 0};
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end(), cmp);

    set<int> s;
    s.insert(0);

    vector<int> res(n + 1);

    for(int i = 1; i <= n; i++){
        auto it = s.lower_bound(a[i].second);
        it--;
        res[a[i].second] = *it;
        s.insert(a[i].second);
    }

    for(int i = 1; i <= n; i++) cout << res[i] << ' ';
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}