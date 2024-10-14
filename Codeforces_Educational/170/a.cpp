#include <bits/stdc++.h>
#define pb push_back
#define pc __builtin_popcount
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;
const int M = 1e9 + 7;
const int maxn = 55;
const double pi = 3.1415926535897932384626;

void solve() {
    string s, t; cin >> s >> t;
    int prefix = 0;
    for(int i = 0; i < min(s.size(), t.size()); i++){
        if(s[i] == t[i]) prefix ++;
        else break;
    }
    cout << min(s.size() + t.size(), (int)s.size() + t.size() -prefix + 1) << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}