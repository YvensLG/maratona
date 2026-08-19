#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 2e5 + 10;
const int logn = 20;
const int inf = 1e9;
 
int pai[logn][maxn], ans[maxn];
 
struct intervalo{
    
    int l, r, id; 
    intervalo( int l, int r ) : l(l), r(r) {}
    
    bool operator < ( intervalo i ){
        if( r == i.r ) return l < i.l;
        return r < i.r;
    }
};
 
struct query{
    int l, r, id, ub = -1;
    query( int l, int r, int id ) : l(l), r(r), id(id) {}
    bool operator < ( query q ){ return l < q.l; }
};
 
vector<intervalo> I;
queue<intervalo> fila;
vector<query> queries;
 
int lca( int a, int x ){
    
    int resp = 0;
    for( int k = logn - 1; k >= 0; k-- ){
        if( I[ pai[k][a] ].r <= x ){
            resp += ( 1<<k );
            a = pai[k][a];
        }
    }
    
    return resp + 1;
}
 
int main(){
    
    int n, q; cin >> n >> q;
    
    for( int i = 0; i < n; i++ ){
        
        int l, r; cin >> l >> r;
        I.push_back( intervalo( l, r ) );
    }
    sort( I.begin(), I.end() );
    I.push_back( intervalo( inf, inf ) );
    
    for( int i = 1; i <= q; i++ ){
        
        int l, r; cin >> l >> r;
        queries.push_back( query( l, r, i ) );
    }
    sort( queries.begin(), queries.end() );
    
    
    int cont = 0, p = 0;
    for( intervalo& cur : I ){
        cur.id = cont++;
        
        while( p < queries.size() && queries[p].l <= cur.l ){
            queries[p].ub = cur.id;
            p++;
        }
        
        if( !fila.empty() ){
            while( !fila.empty() && fila.front().r <= cur.l ){
                pai[0][ fila.front().id ] = cur.id;
                fila.pop();
            }
        }
        fila.push(cur);
    }
    pai[0][n] = n;
    for( int k = 1; k < logn; k++ )
        for( int i = 0; i <= n; i++ ) pai[k][i] = pai[k - 1][ pai[k - 1][i] ];
    
    
    for( query cur : queries ){
        
        if( I[cur.ub].r > cur.r ){
            ans[ cur.id ] = 0; 
            continue;
        }
        ans[cur.id] = lca( cur.ub, cur.r );
    }
    
    
    for( int i = 1; i <= q; i++ ) cout << ans[i] << endl;
}