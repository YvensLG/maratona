#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto u : adj[curr]){
            if(dist[u] == -1){
                dist[u] = dist[curr] + 1;
                q.push(u);
            }
        }
    }

    int mx = -1;
    for(int i = 0; i < n; i++){
        if(dist[i] == -1){
            cout << -1 << "\n";
            return;
        }
        mx = max(mx, dist[i]);
    }

    int res = 0;
    while(mx > (1 << res))
        res++;
    
    cout << res + 1 << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while(tt--)
        solve();
    return 0;
}