#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e6 + 5, inf = 2e9, M = 1e9 + 7;
 
void solve() {
    int n; cin >> n;
    vector<int> mark(maxn);
    mark[0] = 1;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        vector<int> aux;
        for(auto x : s)
            aux.pb(a + x);
        for(auto x : aux)
            s.insert(x);
    }

    s.erase(0);
    cout << s.size() << '\n';
    for(auto x : s) cout << x << ' '; 
    cout << '\n';

}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}