#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int maxn = 2e5 + 10;
ll v[maxn];
 
struct node{
    ll sum = 0, lzs = 0, lzi = 0; node( ll sum = 0 ) : sum(sum) {}
    node operator + ( node n ){ return node( sum + n.sum ); }
} seg[4*maxn];
 
void build( int pos, int ini, int fim ){
    if( ini == fim ){ seg[pos] = node( v[ini] ); return; }
    int mid = ( ini + fim )/2;
    int l = 2*pos, r = 2*pos + 1;
    build( l, ini, mid ); build( r, mid + 1, fim );
    seg[pos] = seg[l] + seg[r];
}
 
void refresh( int pos, ll ini, ll fim ){
    if( !seg[pos].lzi && !seg[pos].lzs ) return;
    ll s = seg[pos].lzs; seg[pos].lzs = 0;
    ll i = seg[pos].lzi; seg[pos].lzi = 0;
    if( s ) seg[pos] = ( fim - ini + 1 )*s;
    seg[pos].sum += ( fim - ini + 1 )*i ;
    if( ini == fim ) return;
    int l = 2*pos, r = 2*pos + 1;
    if( s ){
        seg[l].lzi = 0; seg[l].lzs = s;
        seg[r].lzi = 0; seg[r].lzs = s;
    }
    seg[l].lzi += i;
    seg[r].lzi += i;
}
 
void update( int pos, int ini, int fim, int ki, int kf, ll val, int t ){
    refresh( pos, ini, fim );
    if( ki > fim || ini > kf ) return;
    if( ki <= ini && fim <= kf ){
        if( t == 1 ) seg[pos].lzi += val;
        else seg[pos].lzi = 0, seg[pos].lzs = val;
        refresh( pos, ini, fim ); return;
    }
    int mid = ( ini + fim )/2;
    int l = 2*pos, r = 2*pos + 1;
    update( l, ini, mid, ki, kf, val, t ); 
    update( r, mid + 1, fim, ki, kf , val, t );
    seg[pos] = seg[l] + seg[r];
}
 
ll query( int pos, int ini, int fim, int ki, int kf ){
    refresh( pos, ini, fim );
    if( ki > fim || ini > kf ) return 0;
    if( ki <= ini && fim <= kf ) return seg[pos].sum;
    int mid = ( ini + fim )/2;
    int l = 2*pos, r = 2*pos + 1;
    return query( l, ini, mid, ki, kf ) + query( r, mid + 1, fim, ki, kf );
}
 
int main(){
    int n, m; cin >> n >> m;
    for( int i = 1; i <= n; i++ ) cin >> v[i];
    build( 1, 1, n );
    while( m-- ){
        int t; cin >> t;
        if( t != 3 ){
            ll l, r, val; cin >> l >> r >> val;
            update( 1, 1, n, l, r, val, t );
        }
        else{
            ll l, r; cin >> l >> r;
            cout << query( 1, 1, n, l, r ) << endl;
        }
    }
}