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
const int M = 1e9 + 7;
const int inv2 = (M + 1) / 2;
const int maxn = 400005;

void solve(){
	int n, m; cin >> n >> m; 
    int cont = 0; 
    for( int i = 0; i < m; i++ ){
        int a, b; cin >> a >> b; 
        if( a < b ) cont++; 
    }

    if( 2*cont < m ) for( int i = n; i >= 1; i-- ) cout << i << " "; 
    else for( int i = 1; i<= n; i++ ) cout << i << " "; 
    cout << endl; 
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}