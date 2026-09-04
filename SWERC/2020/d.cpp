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

const int INF = 0x3f3f3f3f;

void solve(){
    int n, m, l, mx; cin >> n >> m >> l >> mx;

    vector<vector<pii>> adj(n);
    vector<int> dist(n, INF);
    vector<pair<pii, int>> edges;

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
        edges.pb({{a, b}, c});
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()){
        int id = pq.top().se, d = pq.top().fi;
        pq.pop();

        if(dist[id] < d)
            continue;

        for(auto u : adj[id]){
            if(dist[u.fi] > d + u.se){
                dist[u.fi] = d + u.se;
                pq.push({dist[u.fi], u.fi});
            }
        }
    }

    int ans = 0;
    for(auto u : edges){
        int mn = min(dist[u.fi.fi], dist[u.fi.se]);
        if(2 * mn < mx)
            ans++;
    }

    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while(tt--)
        solve();
    return 0;
}