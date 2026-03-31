#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
bool mark[1 << 15];
string s;
int mod;

void dfs(int u) {
    s += '0' + (u % 2);
    mark[u] = 1; int v = (u << 1) % mod;
    if(!mark[v + 1]) dfs(v + 1);
    else if(!mark[v]) dfs(v);
}

void solve(){
    int n; cin >> n;
    mod = 1 << n;
    s.resize(n - 1, '0');
    dfs(0);
    cout << s << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}