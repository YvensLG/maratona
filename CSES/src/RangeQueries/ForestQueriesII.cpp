#include <bits/stdc++.h> 
using namespace std;
 
const int maxn = 1e3 + 10;
int v[maxn][maxn], bit[maxn][maxn];
 
void update( int i, int j, int val ){
    for( int a = i; a < maxn; a += a&-a ){
        for( int b = j; b < maxn; b += b&-b ) bit[a][b] += val;
    }
}
 
int query( int i, int j ){
    int resp = 0;
    for( int a = i; a > 0; a -= a&-a ){
        for( int b = j; b > 0; b -= b&-b ) resp += bit[a][b];
    }
    return resp;
}
 
int solve( int a, int b, int c, int d ){
    return query( c, d ) - query( a - 1, d ) - query( c, b - 1 ) + query( a - 1, b - 1 ); 
}
 
 
int main(){
    int n, q; cin >> n >> q;
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= n; j++ ){
            char c; cin >> c;
            v[i][j] = ((c == '*') ? 1 : 0 );
            if( v[i][j] ) update( i, j, v[i][j] );
        }
    }
    while( q-- ){
        int t; cin >> t;
        if( t == 1 ){
            int a, b; cin >> a >> b;
            if( v[a][b] ) update( a, b, -1 );
            else update( a, b, 1 );
            v[a][b] ^= 1;
        }
        else{
            int a, b, c, d; cin >> a >> b >> c >> d;
            cout << solve( a, b, c, d ) << endl;
        }
    }
}