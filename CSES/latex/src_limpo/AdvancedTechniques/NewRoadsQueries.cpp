const int maxn = 2e5 + 10;
const int inf = 1e9;
int pai[maxn], peso[maxn], h[maxn];

void init( int n ){ for( int i = 0; i <= n; i++ ) pai[i] = i, peso[i] = inf; }

int find( int a ){ return ( a == pai[a] ) ? a : find( pai[a] ); }
void join( int a, int b, int p ){
    a = find(a), b = find(b);
    if( a == b ) return;
    if( h[a] < h[b] + 1 ) swap( a, b );
    pai[b] = a; peso[b] = p;
    h[a] = max( h[a], h[b] + 1 );
}

int query( int a, int b ){
    int resp = 0;
    while( a != b ){
        if( peso[a] == inf && peso[b] == inf ) return -1;
        if( peso[a] < peso[b] ) resp = max( resp, peso[a] ), a = pai[a];
        else resp = max( resp, peso[b] ), b = pai[b];
    }
    return resp;
}

int main(){
    int n, m, q; cin >> n >> m >> q;
    init(n);
    for( int i = 1; i <= m; i++ ){
        int a, b; cin >> a >> b;
        join( a, b, i );
    }
    for( int i = 0; i < q; i++ ){
        int a, b; cin >> a >> b;
        cout << query( a, b ) << endl;
    }
}
