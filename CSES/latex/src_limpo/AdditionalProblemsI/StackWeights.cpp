class Segtree{
    private:

    struct Node{
        int tot, suf;
        Node( int tot = 0, int suf = 0 ) : tot(tot), suf(suf) {}
        Node operator + ( Node o ){ return Node( tot + o.tot, max( o.suf, suf + o.tot ) ); }
    };

    Node *seg;
    int n;

    public:

    void update( int node, int ti, int tf, int id, int x ){
        if( ti == tf ){ seg[node] = Node( x, max( x, 0 ) ); return; }
        int l = 2*node, r = 2*node + 1, tm = (ti + tf)/2;
        if( id <= tm ) update( l, ti, tm, id, x );
        else update( r, tm + 1, tf, id, x );
        seg[node] = seg[l] + seg[r];
    }

    Segtree( int n ) : n(n), seg(new Node[4*n]){}

    void update( int id, int x ){
        update( 1, 0, n - 1, id, x );
    }

    int query(){ return seg[1].suf; }
};

void solve(){
    int n; cin >> n;

    Segtree left(n), right(n);
    for( int i = 0; i < n; i++ ){
        int x, t; cin >> x >> t; x--;

        if( t == 2 ) t = -1;

        left.update( x, t );
        right.update( x, -t );

        if( left.query() > 0 && right.query() > 0 ) cout << "?\n";
        else if( left.query() > 0 ) cout << ">\n";
        else cout << "<\n";
    }
}
