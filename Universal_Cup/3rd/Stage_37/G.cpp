#include <bits/stdc++.h>
using namespace std;

#define bug(x) cout << #x << " " << x << endl;

const int maxn = 1e5 + 10; 
const int raizn = 320; 
const int mod = 998244353;

using tripla = tuple<int, int, int>;
using pii = pair<int, int>;
using ll = long long;

int dp[maxn], mat[maxn], paths[maxn][2];
int fat[maxn], inv_fat[maxn];

int mult( int a, int b ){
    return (1LL*a*b)%mod;
}

int sum( int a, int b ){
    return ((a + b)%mod + mod)%mod; 
}

int binomial( int a, int b ){
    if( b > a ) return 0; 
    return mult( fat[a], mult( inv_fat[b], inv_fat[a - b] ) );
}

int solve_heavy( vector<pii> &v, int n, int m ){
    auto id = [&]( int i, int j ){
        return i*m + j; 
    };

    for( auto [i, j] : v ) mat[id(i, j)] = true;  
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
            int &res = dp[id(i, j)]; 

            res = (( i == 0 && j == 0 ) ? 1 : 0 );
            if( i > 0 && !mat[id( i - 1, j)] ) res = sum( res, dp[id( i - 1, j )] );
            if( j > 0 && !mat[id( i, j - 1)] ) res = sum( res, dp[id( i, j - 1 )] );
        }
    }
    
    int ans = (( mat[id( n - 1, m - 1 )] ) ? 0 : dp[id( n - 1, m - 1 )] );
    for( auto [i, j] : v ) mat[id( i, j )] = false; 
    return sum( binomial( n + m - 2, n - 1 ), -ans); 
}

int solve_light( vector<pii> &v, int n, int m ){
    v.emplace_back( n - 1, m - 1 );
    int k = v.size(); 
    for( int i = 0; i < k; i++ ) paths[i][0] = paths[i][1] = 0; 
    for( int a = 0; a < k; a++ ){
        auto [ui, uj] = v[a];
        if( a != k - 1 ) paths[a][1] = sum( paths[a][1], binomial( ui + uj, ui ) ); 

        for( int b = a + 1; b < k; b++ ){
            auto [vi, vj] = v[b];
            if( ui > vi || uj > vj ) continue;

            int di = vi - ui, dj = vj - uj; 
            int qtd = binomial( di + dj, di ); 

            paths[b][1] = sum( paths[b][1], mult( paths[a][0], qtd ) );
            paths[b][0] = sum( paths[b][0], mult( paths[a][1], qtd ) );
        }
    }

    int ans = sum( paths[k - 1][0], -paths[k - 1][1] );

    return sum( paths[k - 1][0], -paths[k - 1][1] );
}

void solve(){
    int n, m; cin >> n >> m; 
    
    vector<vector<pii>> cells(n*m); 

    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
            int x; cin >> x; x--; 
            cells[x].push_back({ i, j });
        }
    }

    int ans = 0; 

    for( auto &v : cells ) if( !v.empty() ){
        if( v.size() <= raizn ) ans = sum( ans, solve_light(v, n, m) );
        else ans = sum( ans, solve_heavy(v, n, m)); 
    }

    cout << ans << endl;
}

void init(){
    vector<int> inv(maxn); 
    inv[0] = inv[1] = fat[0] = fat[1] = inv_fat[1] = inv_fat[0] = 1; 
    for( int i = 2; i < maxn; i++ ){
        inv[i] = mult( mod - mod/i, inv[mod%i] ); 
        fat[i] = mult( fat[i - 1], i ); 
        inv_fat[i] = mult( inv_fat[i - 1], inv[i] ); 
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 

    init();
    int t; cin >> t; 
    while( t-- ) solve(); 
}