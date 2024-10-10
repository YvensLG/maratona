#include <bits/stdc++.h>
#define pb push_back
#define pc __builtin_popcount
#define all(x) x.begin(), x.end()
#define F first
#define S second
// #define int long long
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
    int n; cin >> n;
    int z = 0, u = 0;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == '0') z++;
        else u++;
    }
    if(16 * (u + z) == (u + 4) * (u + 4)){
        cout << "Yes\n";
    }
    else cout << "No\n";
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}