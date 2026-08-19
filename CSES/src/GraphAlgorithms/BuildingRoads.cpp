#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long int  ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> graph;
 
const int maxn = 1e3+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;
int n, m;
vector<int> ans;
graph G;
vi check;

void dfs(int i){
    check[i] = 1;
    for(auto x : G[i]){
        if(check[x] == 0) dfs(x);
    }
}
 
void solve(){
    cin >> n >> m;
    G.resize(n + 1);
    check.resize(n + 1);

    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        G[a].pb(b); G[b].pb(a);
    }

    for(int i = 1; i <= n; i++){
        if(check[i] == 0){
            dfs(i);
            ans.pb(i);
        }
    }

    cout << ans.size() - 1 << '\n';
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i - 1] << ' ' << ans[i] << '\n';  
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}