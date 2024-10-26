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
typedef vector<int> vi;
typedef vector<vi> graph;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

bool flag = true;
map<int, int> compress;
map<int, int> decompress;
vi check;
graph G;

int dfs(int s){
    int maximo = decompress[s];
    for(auto x : G[s]){
        if(check[x] == 0){
            check[x] = 1;
            maximo = max(dfs(x), maximo);
        }
    }
    return maximo;
}

void solve(){
	int n; cin >> n;
    G.clear();
    compress.clear();
    decompress.clear();
    G.pb({});
    int sz = 1;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(compress[a + i] == 0){
            compress[a + i] = sz;
            decompress[sz] = a + i;
            G.pb({});
            sz++;
        }
        if(compress[a + 2 * i] == 0){
            compress[a + 2 * i] = sz;
            decompress[sz] = a + 2 * i;
            G.pb({});
            sz++;
        }
        G[compress[a + i]].pb(compress[a + 2 * i]);
    }

    check.clear();
    check.resize(G.size());
    if(compress[n] == 0) cout << n << '\n';
    else cout << dfs(compress[n]) << '\n';
}

signed main() { 
    _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}