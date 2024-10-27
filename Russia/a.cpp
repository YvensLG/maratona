#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second
#define mp make_pair
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
	int n, m; cin >> n >> m;
    char M[n + 2][m + 2];
    int N[n + 2][m + 2];
    char aux[n + 2][m + 2];
    char certo[n + 2][m + 2];


    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++){
            M[i][j] = '.';
            aux[i][j] = '.';
            certo[i][j] = '.';
            N[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> M[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int x = -1; x <= 1; x++){
                for(int y = -1; y <= 1; y++){
                    N[i][j] += (int)(M[i + x][j + y] == '#');
                }
            }
        }
    }

    if(n == 1 && m == 1){
        cout << "Possible\n" << M[1][1] << '\n';
        return;
    }

    if(n == 1){
        for(int i = 1; i <= m; i++){
            if((i == 1 || i == m) && N[1][i] == 2) aux[1][i] = '#';
            else if(N[1][i] == 3) aux[1][i] = '#';
            else aux[1][i] = '.';
        }
    }
    else if(m == 1){
        for(int i = 1; i <= n; i++){
            if((i == 1 || i == n) && N[i][1] == 2) aux[i][1] = '#';
            else if(N[i][1] == 3) aux[i][1] = '#';
            else aux[i][1] = '.';
        }
    }
    else{
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(N[i][j] == 9) aux[i][j] = '#';
                else if((i == 1 || i == n || j == 1 || j == m) && N[i][j] == 6) aux[i][j] = '#';
                else if((mp(i, j) == mp(1, 1) || mp(i, j) == mp(n, 1) || mp(i, j) == mp(1, m) || mp(i, j) == mp(n, m))
                        && N[i][j] == 4) aux[i][j] = '#';
                else aux[i][j] = '.';
            }
        }
    }

    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            certo[i][j] = '.';
            for(int x = -1; x <= 1; x++){
                for(int y = -1; y <= 1; y++){
                    if(aux[i + x][j + y] == '#') certo[i][j] = '#';
                }
            }
        }
    }

    bool flag = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j ++){
            if(certo[i][j] != M[i][j]) flag = false;
        }
    }

    if(!flag) cout << "Impossible\n";
    else{
        cout << "Possible\n";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << aux[i][j];
            }
            cout << '\n';
        }
    }

}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}