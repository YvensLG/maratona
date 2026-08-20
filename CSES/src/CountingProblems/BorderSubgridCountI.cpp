// TLE !!!

#include <bits/stdc++.h>
using namespace std; 
 
#define bug(x) cout << #x << " " << x << '\n'; 
 
#define FOR(i, a, b) for( int i = a; i < b; i++ )
#define iFOR(i, a, b) for( int i = b - 1; i >= a; i-- )
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
 
#define ff first
#define ss second
 
using pii = pair<int, int>; 
using ll = long long;
 
const int maxn = 3e3 + 10; 
 
int L[maxn][maxn], R[maxn][maxn], U[maxn][maxn], D[maxn][maxn]; 
char mat[maxn][maxn]; 
 
struct BIT{
    int *bit, n; 
    BIT( int n = maxn ) : n(n), bit(new int[n]) {}
 
    void update( int i, int x ){
        for(i++; i - 1 < n; i += i&-i) bit[i - 1] += x; 
    }
 
    int query( int i ){
        int ans = 0; 
        for(i++; i - 1 >= 0; i -= i&-i ) ans += bit[i - 1]; 
        return ans; 
    }
 
    int query( int l, int r ){
        return query(r) - query(l - 1); 
    }
} bit; 
 
ll calc( vector<pii> &v ){
    vector<pii> undo; 
    for( auto [i, j] : v ) undo.push_back({ j + min( R[i][j], D[i][j] ), j }); 
    sort(all(undo)); 
    
    int p = 0; 
    ll ans = 0; 
    for( auto [i, j] : v ){
        while( p < sz(undo) && undo[p].first <= j ) bit.update( undo[p++].second, -1 ); 
 
        bit.update(j, 1); 
        ans += bit.query( j - min( L[i][j], U[i][j] ) +  1, j ); 
    }
 
    while( p < sz(undo) ) bit.update( undo[p++].second, -1 );
    return ans; 
}
 
ll solve( vector<pii> &v ){
    sort(all(v), []( pii a, pii b ){
        if( a.ff - a.ss == b.ff - b.ss ) return a.ff > b.ff; 
        return a.ff - a.ss < b.ff - b.ss;
    });
 
    int n = sz(v); 
 
    ll ans = 0; 
    while( !v.empty() ){
        vector<pii> cur; 
        while( cur.empty() || ( !v.empty() && v.back().ff - v.back().ss == cur.back().ff - cur.back().ss ) ){
            cur.push_back(v.back()); 
            v.pop_back(); 
        } 
 
        ans += calc(cur); 
    }
    
    return ans; 
}
 
void solve(){ 
    int n, k; cin >> n >> k; 
    vector<vector<pii>> cells(k); 
 
    FOR(i, 0, n) FOR(j, 0, n){
        cin >> mat[i][j]; 
        cells[mat[i][j] - 'A'].push_back({ i, j }); 
        
        L[i][j] = U[i][j] = 1; 
        if( i > 0 && mat[i - 1][j] == mat[i][j] ) U[i][j] += U[i - 1][j]; 
        if( j > 0 && mat[i][j - 1] == mat[i][j] ) L[i][j] += L[i][j - 1];
    }
 
    iFOR(i, 0, n) iFOR(j, 0, n){
        R[i][j] = D[i][j] = 1; 
        if( i + 1 < n && mat[i + 1][j] == mat[i][j] ) D[i][j] += D[i + 1][j]; 
        if( j + 1 < n && mat[i][j + 1] == mat[i][j] ) R[i][j] += R[i][j + 1]; 
    }
 
    for( auto &v : cells ) cout << solve(v) << '\n'; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}
