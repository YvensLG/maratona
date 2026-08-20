const int maxn = 100010;

vector< pair< int, int > > connections, breakdowns;
vector<int> resp;

map< int, map< int, bool > > bd;

int edge[maxn], h[maxn];
bool marc[maxn];

int find( int a ){

    if( a == edge[a] ) return a;

    return edge[a] = find( edge[a] );
}

void join( int a, int b ){

    a = find(a);
    b = find(b);

    if( a == b ) return;

    if( h[a] < h[b] ) swap( a, b );

    edge[b] = a;

    h[a] = max( h[a], h[b] + 1);

}

void reseta(){

    for( int i = 0; i < maxn; i++){

        h[i] = 0;

        edge[i] = i;
    }
}

int main(){

    reseta();

    int n, m, k; scanf("%d %d %d", &n, &m, &k);

    for( int i = 0; i < m; i++){

        int a, b; scanf("%d %d", &a, &b);

        connections.push_back({ a, b });
    }

    for( int i = 0; i < k; i++){

        int a, b; scanf("%d %d", &a, &b);

        bd[a][b] = true;
        bd[b][a] = true;

        breakdowns.push_back({ a, b });
    }

    for( int i = 0; i < m; i++){

        pair<int, int> p = connections[i];

        if( !bd[p.first][p.second] ) join( p.first, p.second );

    }

    for( int i = 0; i < maxn; i++) marc[i] = false;

    int componentes = 0;

    for( int i = 1; i <= n; i++){

        int a = find(i);

        if( !marc[a] ){

            marc[a] = true;

            componentes++;

        }
    }

    while( breakdowns.size() > 0 ){

        pair< int, int > p = breakdowns.back();
        breakdowns.pop_back();

        resp.push_back(componentes);

        int a = find( p.first );
        int b = find( p.second );

        if( a != b ) componentes--;

        join( a, b );
    }

    while( resp.size() > 0 ){

        printf("%d\n", resp.back() );
        resp.pop_back();
    }
}
