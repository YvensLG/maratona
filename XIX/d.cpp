#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef pair<int,int> pii;
const int mod = 1e9 + 7;
int n,q;
int peso[200010];
pii aresta[200010];
vector<int> adj[200010];
int sz[200010];
bool visitado[200010];
void dfs(int v){
    visitado[v] = true;
    for(auto u : adj[v]){
        if(!visitado[u]){
            dfs(u);
            sz[v] += sz[u];
        }
    }
}
signed main(){
    cin >> n >> q;
    for(int i = 1;i <= n - 1;i++){
        int a,b,w;
        cin >> a >> b >> w;
        peso[i] = w;
        aresta[i] = {a , b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i <= n;i++){
        sz[i] = 1;
    }
    dfs(1);
    int ans = 0;
    for(int i = 1;i <= n - 1;i++){
        int a = aresta[i].first, b = aresta[i].second;
        if(sz[a] < sz[b]){
            swap(a , b);
        }
        ans += ((peso[i]*sz[b] % mod)*(n - sz[b]))%mod;
        ans %= mod;
    }
    for(int i = 1; i<= q;i++){
        int v,w;
        cin >> v >> w;
        int a = aresta[v].first, b = aresta[v].second;
        if(sz[a] < sz[b]){
            swap(a , b);
        }
        ans += (((w - peso[v])*sz[b] % mod)*(n - sz[b]))%mod;
        ans %= mod;
        peso[v] = w;
        cout << ans << "\n";
    }
}