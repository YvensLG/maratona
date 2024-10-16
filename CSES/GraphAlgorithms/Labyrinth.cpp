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
vector<char> ans;
char tab[maxn][maxn];
int check[maxn][maxn];
pii pai[maxn][maxn];
int n, m; 

template <typename T,typename U>                                                   
pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    
template <typename T,typename U>                                                   
pair<T,U> operator-(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}    

bool bfs(pii A, pii B){
    queue<pii> fila;

    fila.push(A);

    while(!fila.empty()){
        pii X = fila.front();
        fila.pop();

        if(X == B) {
            break;
        }

        for(int i = 0; i < 4; i++){
            pii N = X + macaco[i];
            if(check[N.F][N.S] != 0){
                fila.push(N);
                check[N.F][N.S] = 0;
                pai[N.F][N.S] = X;
            }
        }
    }

    if(check[B.F][B.S] != 0) return false;

    pii X = B;
    while(X != A){
        for(int i = 0; i < 4; i++){
            if(macaco[i] == X - pai[X.F][X.S])
                ans.pb(pos[i]);
        }
        X = {pai[X.F][X.S]};
    }
    reverse(all(ans));
    return true;
}
 
void solve(){
    cin >> n >> m;
    pii A, B;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> tab[i][j];
            if(tab[i][j] != '#') check[i][j] = 1;
            if(tab[i][j] == 'A') A = {i, j};
            if(tab[i][j] == 'B') B = {i, j};
        }
    }

    if(!bfs(A, B)) cout << "NO\n";
    else{
        cout << "YES\n";
        cout << ans.size() << '\n';
        for(char x : ans) cout << x;
        cout << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}