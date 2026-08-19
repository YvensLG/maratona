#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int maxn = 2e5 + 10;
ll v[maxn];
 
struct node{
    vector<ll> v, sv;
    ll cont = 0, maxi = 0; 
    node(){}
    node( ll x ): cont(0), maxi(x) { v.push_back(0); v.push_back(x); sv.push_back(0); sv.push_back(x); }
    node operator + ( node n ){
        node resp;
        ll sum = 0;
        resp.cont = cont + n.cont;
        resp.v.push_back(0); resp.sv.push_back(0);
        for( int i = 1; i < v.size(); i++ ){
            sum += v[i]; resp.maxi = v[i];
            resp.v.push_back(v[i]); 
            resp.sv.push_back(sum);
        } 
        for( int i = 1; i < n.v.size(); i++ ){
            if( n.v[i] < resp.maxi ){ resp.cont += resp.maxi - n.v[i]; n.v[i] = resp.maxi; }
            else resp.maxi = n.v[i];
            sum += n.v[i];
            resp.v.push_back(n.v[i]); resp.sv.push_back(sum);
        }
        return resp;
    }
} seg[4*maxn];
 
struct aux_query{
    ll maxi, resp; aux_query( ll maxi = 0, ll resp = 0 ) : maxi(maxi), resp(resp) {}
    aux_query operator + ( aux_query a ){ return aux_query( max(maxi, a.maxi), resp + a.resp ); }
} nulo;
 
void build( int pos, int ini, int fim ){
    if( ini == fim ){ 
        seg[pos] = node(v[ini]); 
        return; 
    }
    int mid = ( ini + fim )/2;
    int l = 2*pos, r = 2*pos + 1;
    build( l, ini, mid ); build( r, mid + 1, fim );
    seg[pos] = seg[l] + seg[r];
}
 
aux_query query( int pos, int ini, int fim, int ki, int kf, ll val ){
    if( ki > fim || ini > kf ) return nulo;
    if( ki <= ini && fim <= kf ){
        ll id = upper_bound( seg[pos].v.begin(), seg[pos].v.end(), val ) - seg[pos].v.begin(); 
        return aux_query( max( seg[pos].v.back(), val ), (id - 1)*val - seg[pos].sv[id - 1] + seg[pos].cont );
    }
    int mid = ( ini + fim )/2;
    int l = 2*pos, r = 2*pos + 1;
    aux_query ql = query( l, ini, mid, ki, kf, val );
    aux_query qr = query( r, mid + 1, fim, ki, kf, max( ql.maxi, val ) );
    return ql + qr;
}
 
int main(){
    int n, q; scanf("%d %d", &n, &q );
    for( int i = 1; i <= n; i++ ) scanf("%d", &v[i] );
    build( 1, 1, n );
    while( q-- ){
        int a, b; scanf("%d %d", &a, &b );
        aux_query x = query( 1, 1, n, a, b, 0 );
        printf("%lld\n", x.resp );
    }
}