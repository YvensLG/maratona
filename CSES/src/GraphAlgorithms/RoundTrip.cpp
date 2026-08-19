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
graph G;
vi check;
vi pai;

pii bfs(int a){
    queue<int> fila;
    fila.push(a);
    check[a] = 1;
    pai[a] = 0;

    int p1 = 0, p2 = 0;

    while(!fila.empty()){
        int x = fila.front();
        fila.pop();

        for(auto y : G[x]){
            if(check[y] == 1 && y != pai[x]){
                p1 = x;
                p2 = y;
                break;
            }
            else if(check[y] != 1){
                fila.push(y);
                check[y] = 1;
                pai[y] = x;
            }
        }

        if(p1 != 0) break;
    }

    return {p1, p2};
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

    pii p;

    for(int i = 1; i <= n; i++){
        if(check[i] == 0){
            p = bfs(i);
            if(p.F != 0) break;
        }
    }

    if(p.F == 0){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vi ans1, ans2, ans;

    int x = p.F;
    ans1.pb(x);
    while(pai[x] != 0){
        ans1.pb(pai[x]);
        x = pai[x];
    }

    x = p.S;
    ans2.pb(x);
    while(pai[x] != 0){
        ans2.pb(pai[x]);
        x = pai[x];
    }

    int bck = 0;
    while(ans1.back() == ans2.back()){
        bck = ans1.back();
        ans1.pop_back(); ans2.pop_back();
    }

    cout << ans1.size() + ans2.size() + 2 << '\n';
    for(int i = 0; i < ans1.size(); i++){
        cout << ans1[i] << ' ';  
    }
    cout << bck << ' ';
    for(int i = ans2.size() - 1; i >= 0; i--){
        cout << ans2[i] << ' ';  
    }
    cout << ans1[0] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}