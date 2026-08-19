const int maxn = 2e5 + 10;
vector<ll> adj[maxn], v[maxn], lazy( maxn );

ll dfs( int cur, int pai, int k1, int k2 ){
    ll resp = 0;
    for( ll& viz : adj[cur] ) if( viz != pai ){
        resp += dfs( viz, cur, k1, k2 );
        if( adj[cur][0] == pai || (int)v[viz].size() > (int)v[adj[cur][0]].size() ) swap( adj[cur][0], viz );
    }

    if( adj[cur].empty() || adj[cur][0] == pai ){
        v[cur].push_back(-lazy[cur]); lazy[cur]++;
        return 0;
    }
    swap( v[adj[cur][0]], v[cur] ); swap( lazy[cur], lazy[adj[cur][0]] );

    v[cur].push_back(-lazy[cur]);
    int t = (int)v[cur].size();
    int p2 = max( t - k2 - 1, 0 ), p1 = max( t - k1, 0 );
    resp += ( v[cur][p2] - v[cur][p1] );

    lazy[cur]++;
    v[cur].push_back(-lazy[cur]);
    t++;

    for( int viz : adj[cur] ) if( viz != adj[cur][0] && viz != pai ){
        v[viz].push_back(-lazy[viz]);
        reverse( v[viz].begin(), v[viz].end() );
        for( int dist = 1; dist < (int)v[viz].size(); dist++ ){
            ll qtd = v[viz][dist] - v[viz][dist - 1];

            int p2 = max( t - (k2 - dist) - 2, 0 ), p1 = max( t - (k1 - dist) - 1, 0 );
            p2 = min( p2, t - 1 ); p1 = min( p1, t - 1 );

            resp += qtd*( v[cur][p2] - v[cur][p1]);
        }

        lazy[cur] += v[viz].back() + lazy[viz];
        v[cur].back() = -lazy[cur];
        for( int dist = 0; dist < (int)v[viz].size(); dist++ ) v[cur][t - dist - 2] += v[viz][dist] - v[viz].back();
    }

    v[cur].pop_back();

    return resp;
}

int main(){
    int n, k1, k2; cin >> n >> k1 >> k2;
    for( int i = 1; i < n; i++ ){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs( 1, 1, k1, k2 ) << endl;
}
