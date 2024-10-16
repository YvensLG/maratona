#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long int  ll;
typedef pair<int, int> pii;
 
const int maxn = 1e3+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;

vector<pii> macaco = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<char> pos = {'D', 'U', 'R', 'L'};
vector<pii> ans;
char tab[maxn][maxn];
pii pai[maxn][maxn];
int n, m;
pii A;
vector<pii> Monster;

template <typename T,typename U>                                                   
pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    
template <typename T,typename U>                                                   
pair<T,U> operator-(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}    

pii bfs(){
    queue<pii> fila;

    for(auto x : Monster){
        fila.push(x);
        pai[x.F][x.S] = {0, 0};
    }
    fila.push(A);
    pai[A.F][A.S] = {0, 0};

    while(!fila.empty()){
        pii X = fila.front();
        fila.pop();

        for(int i = 0; i < 4; i++){
            pii N = X + macaco[i];
            if(tab[N.F][N.S] == '.'){
                fila.push(N);
                tab[N.F][N.S] = tab[X.F][X.S];
                pai[N.F][N.S] = X;
            }
        }
    }

    pii ans = {0, 0};

    for(int i = 1; i <= n; i++){
        if(tab[i][1] == 'A') ans = {i, 1};
        if(tab[i][m] == 'A') ans = {i, m};
    }
    for(int i = 1; i <= m; i++){
        if(tab[1][i] == 'A') ans = {1, i};
        if(tab[n][i] == 'A') ans = {n, i};
    }

    return ans;
}
 
void solve(){
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> tab[i][j];
            if(tab[i][j] == 'A') A = {i, j};
            if(tab[i][j] == 'M') Monster.pb({i, j});
        }
    }

    pii res = bfs();
    
    if(res.F == 0){
        cout << "NO\n";
        return;
    }

    while(pai[res.F][res.S].F != 0){
        ans.pb(res - pai[res.F][res.S]);
        res = pai[res.F][res.S];
    }

    reverse(all(ans));

    cout << "YES\n";
    cout << ans.size() << '\n';
    for(pii x : ans){
        for(int i = 0; i < 4; i++){
            if(x == macaco[i]) cout << pos[i];
        }
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}