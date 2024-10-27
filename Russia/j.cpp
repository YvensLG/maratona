#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define all(x) x.begin(), x.end()
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
	int n, m; cin >> n >> m;
    char M[n + 2][m + 2];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> M[i][j];
        }
    }

    vector<vector<int>> linha;
    linha.pb({});

    for(int i = 1; i <= n; i++){
        linha.pb({0});
        for(int j = 1; j <= m; j++){
            if(M[i][j] == '#') linha[i].pb(j);
        }
        linha[i].pb(m + 1);
    }

    vector<vector<int>> coluna;
    coluna.pb({});

    for(int j = 1; j <= m; j++){
        coluna.pb({0});
        for(int i = 1; i <= n; i++){
            if(M[i][j] == '#') coluna[j].pb(i);
        }
        coluna[j].pb(n + 1);
    }

    // for(int i = 1; i <= m; i++){
    //     cout << i << ": ";
    //     for(auto x : coluna[i]) cout << x << ' ';
    //     cout << '\n';
    // }

    string s; cin >> s;
    pair<int, int> at = {n, 1};
    for(char c : s){
        if(c == 'U'){
            at.first = *prev(lower_bound(all(coluna[at.second]), at.first)) + 1;
        }
        if(c == 'D'){
            at.first = *lower_bound(all(coluna[at.second]), at.first) - 1;
        }
        if(c == 'L'){
            at.second = *prev(lower_bound(all(linha[at.first]), at.second)) + 1;
        }
        if(c == 'R'){
            at.second = *lower_bound(all(linha[at.first]), at.second) - 1;
        }
    }

    cout << at.second << ' ' << n - at.first + 1 << '\n';

}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}