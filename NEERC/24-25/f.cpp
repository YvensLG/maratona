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
	int n; cin >> n; 
    vector<int> v(n); 
    for( int i = 0; i < n; i++ ){
        string s; cin >> s; 
        int h = s[0] - '0';
        int m = (s[2] - '0')*10 + s[3] - '0'; 

        v[i] = h*60 + m; 
    }

    int p = 0; 
    int resp = 3; 
    for( int i = 0; i < n; i++ ){
        while( p < n && v[p] <= v[i] + 10 ) p++;
        if( p - i >= 3 ) resp = 0; 
        else resp = min( resp, 3 - (p - i) ); 
    }

    cout << resp << endl;
}

signed main() { _
    // int t; cin >> t; 
    int t = 1;
    while(t--)
    solve();

    return 0;
}