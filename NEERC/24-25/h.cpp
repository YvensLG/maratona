#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 998244353;
const int inv2 = (M + 1) / 2;
const int maxn = 400005;

vector<int> ini, fim; 

int dp[maxn][3][3]; 

void init( int n ){
    for( int i = 1; i <= n; i++ ){
        dp[i][0][1] = dp[i - 1][0][2] + 1 + dp[i - 1][2][1]; 
        dp[i][2][1] = dp[i][0][1]; 

        dp[i][1][0] = dp[i - 1][1][2] + 1 + dp[i - 1][2][0]; 
        dp[i][1][2] = dp[i][1][0]; 

        dp[i][0][2] = dp[i][0][1] + dp[i][1][2]; 
        dp[i][2][0] = dp[i][0][2]; 

        for( int j = 0; j < 3; j++ ) for( int k = 0; k < 3; k++ ) dp[i][j][k] %= M; 
    }
}

int build( int id, int pos ){
    if( id == 0 ) return 0; 
    if( pos == ini[id] ) return build( id - 1, pos ); 
    if( abs(pos - ini[id]) == 1 ){
        int outro = 3 - ini[id] - pos; 
        return (build( id - 1, outro ) + 1 + dp[id - 1][outro][pos]); 
    }
    return ( build( id - 1, pos ) + 1 + dp[id - 1][pos][1] + dp[id][1][pos] )%M; 
}

int calcula( int id, int pos ){
    if( id == 0 ) return 0; 
    if( fim[id] == pos ) return calcula( id - 1, pos ); 
    if( abs( pos - fim[id]) == 1 ){
        int outro = 3 - fim[id] - pos; 
        return ( dp[id - 1][pos][outro] + calcula( id - 1, outro ) + 1 )%M; 
    }
    return ( )
}

void solve(){
	int n; cin >> n; 
    ini = fim = vector<int>(n + 1); 
    for( int i = 1; i <= n; i++ ) cin >> ini[i]; 
    for( int i = 1; i <= n; i++ ) cin >> fim[i]; 

    int first = n; 
    while( first > 0 && ini[first] == fim[first] ) first--; 

    if( first == 0 ){ cout << 0 << endl; return; }

    int resp = 0, pos = 0; 

    if( abs( ini[first] - fim[first]) == 1 ){
        pos = 3 - ini[first] - fim[first]; 
        resp = build( first - 1, pos ); 
    }
    else{
        pos = fim[first]; 
        resp = build( first - 1, pos ); 
    }

    resp += calcula( first, pos ); 


}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}