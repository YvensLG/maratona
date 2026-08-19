#include <bits/stdc++.h>
#define pb push_back
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAX = 2e5 + 5;
const int LOG = 19;
const int INF = 1e9;

int subtree[MAX];
vi adj[MAX];

void dfs(int s, int p) {
    subtree[s] = 1;
    for(auto x : adj[s]) {
        if(x == p) continue;
        dfs(x, s);
        subtree[s] += subtree[x];
    }
}

void solve(){
    int n; cin >> n;    
    for(int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    
    dfs(1, 0);
    for(int i = 1; i <= n; i++) cout << subtree[i] - 1 << ' ';
    cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}