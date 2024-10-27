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
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
	int n, m, k; cin >> n >> m >> k;
    int M[n + 2][m + 2]; for(int i = 0; i <= n + 1; i++) for(int j = 0; j <= m + 1; j++) M[i][j] = 0;

    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        M[a][b] = 1;
    }

    int maxi = 0;
    int a = 0, b = 0;

    for(int i = 1; i <= n; i++){
        int tot = 0;
        for(int j = 1; j <= m; j++){
            tot += M[i][j];
        }
        int at = 0;
        for(int j = 1; j <= m; j++){
            at += M[i][j];
            if(M[i][j] == 0){
                if(maxi < max(at, tot - at)){
                    maxi = max(at, tot - at);
                    a = i; b = j;
                }
            }
        }
    }


    for(int j = 1; j <= m; j++){
        int tot = 0;
        for(int i = 1; i <= n; i++){
            tot += M[i][j];
        }
        int at = 0;
        for(int i = 1; i <= n; i++){
            at += M[i][j];
            if(M[i][j] == 0){
                if(maxi < max(at, tot - at)){
                    maxi = max(at, tot - at);
                    a = i; b = j;
                }
            }
        }
    }

    cout << maxi << '\n';
    cout << a << ' ' << b << '\n';
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}