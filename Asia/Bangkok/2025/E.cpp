#include <bits/stdc++.h>
using namespace std; 

#define int long long

using ll = long long;
using pii = pair<ll, ll>;

const int maxn = 110; 
const ll inf = 1e18; 

vector<ll> max_dist[maxn];
ll dist[maxn][maxn];

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int n, m, q; cin >> n >> m >> q; 
    vector<int> passes; 

    vector<tuple<int, int, int, int>> edges; 

    while( m-- ){
        int a, b, p, c; cin >> a >> b >> p >> c; 
        a--; b--; 
        edges.emplace_back( p, a, b, c );
        passes.push_back(p); 
    }

    sort( edges.begin(), edges.end() ); 
    sort( passes.begin(), passes.end() ); 

    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ) dist[i][j] = inf; 
        dist[i][i] = 0; 
    }

    for( auto [p, a, b, c] : edges ){
        for( int i = 0; i < n; i++ ){
            max_dist[i].push_back(-1); 
            for( int j = 0; j < n; j++ ){
                dist[i][j] = min( dist[i][j], dist[i][a] + dist[b][j] + c ); 
                max_dist[i].back() = max( max_dist[i].back(), dist[i][j] ); 
            } 
        }
    }

    vector<pii> ans(q); 
    vector<pii> queries; 

    for( int i = 0; i < q; i++ ){
        int t; cin >> t; 
        if( t == 1 ){
            ll u, h; cin >> u >> h; 
            u--; 
            int l = 0, r = max_dist[u].size(); 
            while( l < r ){
                int mid = ( l + r )/2; 
                if( max_dist[u][mid] <= h ) r = mid; 
                else l = mid + 1; 
            }
            ans[i] = pii( (( l == max_dist[u].size() ) ? -1 : passes[l] ), -2 );
        }
        else{
            ll h; cin >> h; 
            queries.push_back({ h, i });
        }
    }

    vector<int> ptr(n); 
    set<pii> pointers; 

    sort( queries.rbegin(), queries.rend() );

    set<pii> s; 
    for( int i = 0; i < n; i++ ) s.insert({max_dist[i][0], i}), pointers.insert({ passes[0], i });

    for( auto [h, i] : queries ){
        while( !s.empty() && s.rbegin()->first > h ){
            auto [_, id] = *s.rbegin(); s.erase(prev(s.end()));
            pointers.erase({ passes[ptr[id]], id });
            
            if( ++ptr[id] < max_dist[id].size() ){
                s.insert({ max_dist[id][ptr[id]], id });
                pointers.insert({ passes[ptr[id]], id });
            }  
        }

        ans[i] = (( pointers.empty() ) ? pii( -1, -1 ) : pii( pointers.begin()->second + 1, pointers.begin()->first ));
    }

    for( auto [a, b] : ans ){
        if( b == -2 ) cout << a << endl; 
        else cout << a << " " << b << endl;
    }
}