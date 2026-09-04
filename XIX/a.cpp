#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int MAX = 200010;
const int N = MAX;

template <class T>
    using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <bool VALS_EDGES> struct HLD{
    int N, tim = 0;
    vector <vi> adj;
    vi par, siz, rt, pos;
    Node *tree;
    HLD(vector <vi> adj_)
    : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1),
     rt(N),pos(N),tree(new Node(0, N)) {dfsSz(0);dfsHld(0); }
    void dfsSz(int v) {
        for(int& u : adj[v]) {
            adj[u].erase(find(all(adj[u]), v));
            par[u] = v;
            dfsSz(u);
            siz[v] += siz[u];
            if(siz)
        }
    }
}

int main(){

}