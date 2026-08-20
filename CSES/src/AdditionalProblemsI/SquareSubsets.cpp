#include <bits/stdc++.h>
using namespace std; 
 
#define bug(x) cout << #x << " " << x << endl;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
 
using vi = vector<int>;
 
const int maxx = 5e5 + 10; 
const int mod = 1e9 + 7; 
const int logx = 20; 
 
int fator[maxx], id[maxx]; 
 
int prod( int a, int b ){
    return a * 1LL * b % mod;
}
 
struct XorBasis{
    vi b; 
    int LD; 
    XorBasis( int n ) : b(n, -1), LD(1) {}
 
    void insert( int mask, int msb ){
        if( msb == -1 ){ LD = prod( 2, LD ); return; }
        if( b[msb] == -1 ){ b[msb] = mask; return; } 
        else mask ^= b[msb];  
 
        for( int i = logx - 1; i >= 0; i-- ) if( (mask>>i)&1 ){
            if( b[i] == -1 ){ b[i] = mask; return; }
            mask ^= b[i];
        }
        LD = prod( 2, LD ); 
    }
};
 
int crivo(){
    int tot = 0; 
    FOR(i, 2, maxx ) if( !fator[i] ){
        id[i] = tot++; 
        for( int j = i; j < maxx; j += i ) fator[j] = i; 
    }
    return tot; 
}
 
void solve( int tot_primos ){
    int n; cin >> n; 
 
    XorBasis basis(tot_primos);     
 
    FOR(i, 0, n){
        int x; cin >> x; 
        vi v; 
        for(; x > 1; x /= fator[x] ){
            if( !v.empty() && v.back() == fator[x] ) v.pop_back(); 
            else v.push_back(fator[x]); 
        }
 
        int mask = 0, msb = (v.empty() ? -1 : id[v[0]]);
        FOR(j, 1, sz(v)) mask |= (1<<id[v[j]]); 
 
        basis.insert( mask, msb ); 
    }
 
    cout << basis.LD << '\n'; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);  
    solve(crivo()); 
}
