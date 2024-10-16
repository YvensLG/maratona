#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long int  ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> graph;
 
const int maxn = 1e3+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;
int n, m;
vector<int> ans;
graph G;
vi check;
vi pai;

bool bfs(int a, int b){
    queue<int> fila;
    fila.push(a);
    check[a] = 1;
    pai[a] = 0;

    while(!fila.empty()){
        int x = fila.front();
        fila.pop();

        if(x == b) {
            break;
        }

        for(auto y : G[x]){
            if(check[y] != 1){
                fila.push(y);
                check[y] = 1;
                pai[y] = x;
            }
        }
    }

    if(check[b] != 1) return false;
    return true;
}
 
void solve(){
    cin >> n >> m;
    G.resize(n + 1);
    check.resize(n + 1);
    pai.resize(n + 1);

    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        G[a].pb(b); G[b].pb(a);
    }

    if(!bfs(1, n)){
        cout << "IMPOSSIBLE\n";
        return;
    }

    int x = n;
    ans.pb(n);

    while(pai[x] != 0){
        ans.pb(pai[x]);
        x = pai[x];
    }
    reverse(all(ans));

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';  
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}