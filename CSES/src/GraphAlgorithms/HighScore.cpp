#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const ll inf=LLONG_MAX;
struct Ed{int a,b,w,s(){return a<b?a:-a;}};
struct Node{ll dist=inf; int prev=-1;};
 
void bellmanFord(vector<Node>&nodes,vector<Ed>&eds, int s){
    nodes[s].dist=0;
    sort(all(eds),[](Ed a,Ed b){return a.s()<b.s();});
 
    int lim=sz(nodes)/2+2;
    rep(i,0,lim) for (Ed ed:eds){
        Node cur=nodes[ed.a],&dest=nodes[ed.b];
        if (abs(cur.dist)==inf) continue;
        ll d=cur.dist+ed.w;
        if (d<dest.dist){
            dest.prev=ed.a;
            dest.dist=(i<lim-1?d:-inf);
        }
    }
    rep(i,0,lim) for(Ed e:eds){
        if (nodes[e.a].dist==-inf)
            nodes[e.b].dist=-inf;
    }
}
 
void solve() {
    int n, m; cin >> n >> m;
    vector<Node> nodes(n);
    vector<Ed> edges(m);
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges[i] = {a - 1, b - 1, -w};
    }
    bellmanFord(nodes, edges, 0);
    if(nodes[n - 1].dist == -inf) cout << -1 << '\n';
    else cout << -nodes[n - 1].dist << '\n';
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    solve();
 
    return 0;
}
