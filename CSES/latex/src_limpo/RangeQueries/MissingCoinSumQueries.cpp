using vi = vector<int>;
using ll = long long;

const int maxx = 1e9;

class PersistentSegtree{
    private:

    struct Node{
        ll sum;
        int mini, maxi, l, r;
        Node( ll sum = 0, int mini = maxx, int maxi = -maxx ) : sum(sum), mini(mini), maxi(maxi), l(0), r(0) {}
        void merge( Node L, Node R ){
            sum = L.sum + R.sum;
            mini = min( L.mini, R.mini );
            maxi = max( L.maxi, R.maxi );
        }
    };

    Node *seg;
    vi rt;
    int MIN, MAX, id;

    int create(){
        return id++;
    }

    int copy( int node ){
        int cp = create();
        return seg[cp] = seg[node], cp;
    }

    int update( int node, int ti, int tf, int id, int x ){
        int cp = copy(node);
        if( ti == tf ){
            seg[cp].merge(seg[node], Node( x, x, x ) );
            return cp;
        }

        int tm = (ti + tf)>>1, &l = seg[cp].l, &r = seg[cp].r;
        if( id <= tm ) l = update( seg[node].l, ti, tm, id, x );
        else r = update( seg[node].r, tm + 1, tf, id, x );

        seg[cp].merge( seg[l], seg[r] );
        return cp;
    }

    ll query( int n1, int n2, int ti, int tf, ll qi, ll qf ){
        if( qi > seg[n2].maxi || seg[n2].mini > qf || n1 == n2 ) return 0;
        if( qi <= seg[n2].mini && seg[n2].maxi <= qf ) return seg[n2].sum - seg[n1].sum;
        int tm = (ti + tf)>>1;
        return query( seg[n1].l, seg[n2].l, ti, tm, qi, qf ) + query( seg[n1].r, seg[n2].r, tm + 1, tf, qi, qf );
    }

    public:

    PersistentSegtree( int n, int MIN, int MAX ) : MIN(MIN), MAX(MAX), rt(1), id(0) {
        seg = new Node[n*__lg(MAX - MIN + 1) + 2*n];
        create();
    }

    void update( int id, int x ){
        rt.push_back(update(rt.back(), MIN, MAX, id, x ) );
    }

    ll query( int L, int R, ll D, ll U ){
        return query( rt[L], rt[R + 1], MIN, MAX, D, U );
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vi v(n);
    for( int &x : v ) cin >> x;

    vi c = v;
    sort(all(c));
    c.erase(unique(all(c)), c.end());

    PersistentSegtree seg( n, 0, sz(c) - 1 );
    for( int &x : v ){
        int id = lower_bound(all(c), x) - c.begin();
        seg.update( id, x );
    }

    while( q-- ){
        int l, r; cin >> l >> r; l--; r--;

        ll ans = 0;
        for( ll new_ans = seg.query(l, r, 1, ans + 1); new_ans != ans; new_ans = seg.query(l, r, 1, ans + 1) )
            ans = new_ans;

        cout << ans + 1 << '\n';
    }
}
