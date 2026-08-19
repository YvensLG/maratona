// TLE CODE!!!!

#include <bits/stdc++.h>
using namespace std; 
 
#define bug(x) cout << #x << " " << x << endl;
 
using ll = long long;
 
const int maxn = 1e5 + 10; 
const ll inf = 1e11 + 10;
 
struct Point{
    ll x, y; 
    Point( ll x = 0, ll y = 0 ) : x(x), y(y) {}
    Point operator + ( const Point &o ) const { return Point( x + o.x, y + o.y ); }
    Point operator * ( const int c ) const { return Point( x*c, y*c ); }
    bool operator == ( const Point &o ) const { return x == o.x && y == o.y; }
    int dist( const Point &o ){ return abs(x - o.x) + abs(y - o.y); }
} pos[maxn], dir[maxn];
 
inline Point direction( char c ){
    if( c == 'U' ) return Point( 0, 1 ); 
    if( c == 'R' ) return Point( 1, 0 ); 
    if( c == 'D' ) return Point( 0, -1 ); 
    return Point( -1, 0 ); 
}
 
struct Event{
    ll y, x1, x2, val, id; 
    bool operator < ( const Event &o ) const {
        return ((y == o.y) ? val > o.val : y < o.y ); 
    }
} events[2*maxn];
 
ll xs[2*maxn];
 
inline int first_greater( ll x, int m ){
    return lower_bound( xs, xs + m, x ) - xs; 
}
 
inline int last_lower( ll x, int m ){
    return upper_bound(xs, xs + m, x ) - xs - 1;
}
 
struct Segtree{
    struct Node{
        int mx, lz; 
        Node( int mx = 0 ) : mx(mx), lz(0) {}
        Node operator + ( Node o ){ return Node( max(mx, o.mx) ); }
    }; 
 
    Node *seg; 
    int n; 
 
    Segtree( int n ) : n(n), seg(new Node[4*n]){}
 
    inline void refresh( int p, int ti, int tf ){
        if( seg[p].lz == 0 ) return; 
        int x = seg[p].lz; seg[p].lz = 0; 
 
        seg[p].mx += x; 
 
        if( ti == tf ) return;
        seg[2*p].lz += x; 
        seg[2*p + 1].lz += x; 
    }
 
    void update( int p, int ti, int tf, int qi, int qf, int x ){
        refresh( p, ti, tf ); 
        if( qi > tf || ti > qf ) return; 
        if( qi <= ti && tf <= qf ){ seg[p].lz = x; refresh( p, ti, tf ); return; }
        int l = 2*p, r = 2*p + 1, tm = (ti + tf)/2; 
        update( l, ti, tm, qi, qf, x ); update( r, tm + 1, tf, qi, qf, x ); 
        seg[p] = seg[l] + seg[r]; 
    }
 
    inline bool update( int l, int r, int x ){
        update( 1, 0, n - 1, l, r, x ); 
        return seg[1].mx >= 2;
    }
 
    inline void reset(){
        fill( seg, seg + 4*n, Node(0) );
    }
} seg(2*maxn); 
 
bool check( int n, int m, int q, ll dist ){
    int p = 0; 
 
    seg.reset();
    Event extra[2]; 
 
    while( dist > 0 ){
        if( dist > pos[p].dist(pos[p + 1]) ){
            dist -= pos[p].dist(pos[p + 1]);
            p++;
            continue;
        }
 
        Point p1 = pos[p] + dir[p]; 
        Point p2 = pos[p] + dir[p]*dist; 
        extra[0] = { min(p1.y, p2.y), min(p1.x, p2.x), max(p1.x, p2.x), 1, p }; 
        extra[1] = { max(p1.y, p2.y), min(p1.x, p2.x), max(p1.x, p2.x), -1, p }; 
        
        dist -= pos[p].dist(pos[p + 1]);
    }
 
    int t = 0; 
 
    for( int i = 0; i < q; i++ ) if( events[i].id < p ) {
        while( t < 2 && extra[t] < events[i] ){
            if( seg.update( first_greater( extra[t].x1, m ), last_lower( extra[t].x2, m ), extra[t].val ) ) return true; 
            t++; 
        }
        if( seg.update( events[i].x1, events[i].x2, events[i].val ) ) return true; 
    }
    return false;
}
 
ll bs( int n, int m, int q, ll total ){
    ll l = 1, r = total; 
    while( l < r ){
        ll mid = (l + r)/2; 
        if( check( n, m, q, mid ) ) r = mid;
        else l = mid + 1; 
    }
    return r; 
}
 
void solve(){
    int n; cin >> n; 
 
    int q = 0, m = 0; 
    auto create_line = [&]( ll x1, ll x2, ll y1, ll y2, int id ){
        if( x1 > x2 ) swap( x1, x2 ); 
        if( y1 > y2 ) swap( y1, y2 ); 
        
        events[q++] = { y1, x1, x2,  1, id }; 
        events[q++] = { y2, x1, x2, -1, id };
 
        xs[m++] = x1; 
        xs[m++] = x2; 
    };
 
    create_line( -inf, -inf, -inf, -inf, -1 ); 
    create_line( 0, 0, 0, 0, -1 );
    create_line( inf, inf, inf, inf, -1 ); 
 
    ll total = 0; 
    for( int i = 0; i < n; i++ ){
        char c; int d; cin >> c >> d; 
        if( i > 0 && dir[i - 1] + direction(c) == Point(0, 0) ){ n = i; break; }
        total += d; 
        dir[i] = direction(c); 
        
        Point p1 = pos[i] + dir[i]; 
        pos[i + 1] = pos[i] + dir[i]*d; 
 
        create_line( p1.x, pos[i + 1].x, p1.y, pos[i + 1].y, i );        
    }
 
    sort(xs, xs + m); 
    m = unique(xs, xs + m) - xs; 
    sort( events, events + q ); 
 
    for( int i = 0; i < q; i++ ){
        events[i].x1 = first_greater( events[i].x1, m ); 
        events[i].x2 = first_greater( events[i].x2, m ); 
    }
 
    cout << bs( n, m, q, total ) << '\n';
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}