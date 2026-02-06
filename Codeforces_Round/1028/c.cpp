#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define INF 1000000000
#define LINF 1000000000000000000LL
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int MAX = 5005;

vector<int> dist;
vector<int> a;
void bfs()
{
    dist.resize(MAX, INF);
    queue<int> q;

    for(int x : a){
        if(dist[x] > 1){
            dist[x] = 1;
            q.push(x);
        }
    }

    while(!q.empty()){
        int v = q.front(); q.pop();
        int dv = dist[v];
        for(int x : a){
            int ng = __gcd(v, x);
            if(dv + 1 < dist[ng]){
                dist[ng] = dv + 1;
                q.push(ng);
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    a.resize(n);
    for(int &x : a) cin >> x;

    int G = 0, cntG = 0;
    for(int x : a) G = __gcd(G, x);
    for(int x : a) if(x == G) ++cntG;

    if(cntG > 0){
        cout << (n - cntG) << '\n';
        return;
    }

    bfs();
    int S = dist[G];
    cout << (n + S - 2) << '\n';
}

signed main(){ _
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
