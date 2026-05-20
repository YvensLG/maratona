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

int dist[MAX];
vi adj[MAX];

void dfs(int s, int p) {
    dist[s] = dist[p] + 1;
    for(auto x : adj[s]) {
        if(x == p) continue;
        dfs(x, s);
    }
}

void solve(){
    int n; cin >> n;    
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dist[0] = -1;
    dfs(1, 0);
    int maxi = -1, at = 0;
    for(int i = 1; i <= n; i++) {
        if(maxi < dist[i]) {
            at = i;
            maxi = dist[i];
        }
    }

    dfs(at, 0);
    maxi = -1;
    for(int i = 1; i <= n; i++) {
        if(maxi < dist[i]) maxi = dist[i];
    }

    cout << maxi << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}