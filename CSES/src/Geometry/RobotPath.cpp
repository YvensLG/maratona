#pragma GCC optimize("O3")
 
#include <bits/stdc++.h>
using namespace std; 
 
#pragma GCC optimize("unroll-loops")
 
#define bug(x) cout << #x << " " << x << endl;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define FOR(i, a, b) for( int i = a; i < b; i++ ) 
 
using ll = long long;
using vi = vector<int>; 
using pii = pair<ll, ll>; 
 
const int maxn = 1e5 + 10; 
const ll inf = 1e11 + 10;
 
struct Point{
    ll x, y; 
    Point( ll x = 0, ll y = 0 ) : x(x), y(y) {}
    Point operator + ( const Point &o ) const { return Point( x + o.x, y + o.y ); }
    Point operator * ( const int c ) const { return Point( x*c, y*c ); }
    bool operator == ( const Point &o ) const { return x == o.x && y == o.y; }
    ll dist( const Point &o ){ return abs(x - o.x) + abs(y - o.y); }
} pos[maxn], dir[maxn];
 
Point direction( char c ){
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
 
ll total[maxn];
 
bool check( int n, int q, int p ){
    set<pii> s; 
    auto update = [&]( ll l, ll r, int op ){
        if( op == -1 ){ s.erase({ r, l }); return false; }
        
        auto it = s.lower_bound({ l, -1 }); 
        if( it != s.end() && it->second <= r ) return true; 
        
        s.insert({ r, l });
        return false; 
    }; 
    
    int t = 0; 
    for( int i = 0; i < q; i++ ) 
        if( events[i].id <= p && update( events[i].x1, events[i].x2, events[i].val ) )
            return true; 
    return false;
}
 
int bs( int n, int q ){
    int l = 0, r = n - 1; 
    while( l < r ){
        int m = (l + r)/2; 
        if( check( n, q, m ) ) r = m;
        else l = m + 1; 
    }
    return r; 
}
 
bool inter( Point a1, Point a2, Point b1, Point b2 ){
    if( a1.x > a2.x ) swap( a1.x, a2.x ); 
    if( a1.y > a2.y ) swap( a1.y, a2.y ); 
    if( b1.x > b2.x ) swap( b1.x, b2.x ); 
    if( b1.y > b2.y ) swap( b1.y, b2.y ); 
 
    if( a2.x < b1.x || b2.x < a1.x ) return false; 
    if( a2.y < b1.y || b2.y < a1.y ) return false; 
    return true; 
}
 
void check_max_len( int i, int j, ll &len ){
    while( len > 0 ){
        Point i1 = pos[i] + dir[i], i2 = pos[i] + dir[i] * len; 
        Point j1 = pos[j], j2 = pos[j + 1]; 
        if( !inter( i1, i2, j1, j2 ) ) break;
        len--;
    }
}
 
void solve(){
    int n; cin >> n; 
 
    int q = 0; 
    auto create_line = [&]( ll x1, ll x2, ll y1, ll y2, int id ){
        if( x1 > x2 ) swap( x1, x2 ); 
        if( y1 > y2 ) swap( y1, y2 ); 
        
        events[q++] = { y1, x1, x2,  1, id }; 
        events[q++] = { y2, x1, x2, -1, id };
    };
 
    create_line( -inf, -inf, -inf, -inf, -1 ); 
    create_line( 0, 0, 0, 0, -1 );
    create_line( inf, inf, inf, inf, -1 ); 
 
    FOR(i, 0, n){
        char c; int d; cin >> c >> d; 
        dir[i] = direction(c); 
        if( i > 0 && dir[i - 1] + dir[i] == Point(0, 0) ){ n = i; break; }
        total[i] += d; total[i + 1] += total[i];  
        
        Point p1 = pos[i] + dir[i]; 
        pos[i + 1] = pos[i] + dir[i]*d; 
 
        create_line( p1.x, pos[i + 1].x, p1.y, pos[i + 1].y, i );        
    }
 
    sort( events, events + q ); 
 
    int id = bs( n, q );
 
    ll ans = (id == 0) ? 0 : total[id - 1];
    ll len = pos[id].dist(pos[id + 1]) - 1;
    FOR(i, 0, id) check_max_len( id, i, len ); 
    
    cout << ans + len + 1 << '\n';
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
