#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long 
 
const int maxn = 200010;
vector<int> adj[maxn];
int sub[maxn];
bool removed[maxn];
ll resp;
int f[maxn];
int n, k;
vector<int> freq;
 
void dfsInit( int cur, int pai ){
    sub[cur] = 1;
    for( int i = 0; i < adj[cur].size(); i++ ){
        int viz = adj[cur][i];
        if( viz == pai ) continue;
        if( removed[viz] ) continue;
        dfsInit( viz, cur );
        sub[cur] += sub[viz];
    }
}
 
int findCentroid( int cur, int pai, int size ){
    for( int i = 0; i < adj[cur].size(); i++ ){
        int viz = adj[cur][i];
        if( viz == pai ) continue;
        if( removed[viz] ) continue;
        if( sub[viz] > size/2 ) return findCentroid( viz, cur, size );
    }
    return cur;
}
 
void dfs( int cur, int pai, int nivel ){
    freq.pb(nivel);
    if( nivel <= k ) resp += f[k - nivel];
    for( int i = 0; i < adj[cur].size(); i++ ){
        int viz = adj[cur][i];
        if( viz == pai ) continue;
        if( removed[viz] ) continue;
        dfs( viz, cur, nivel + 1 );
    }
}
 
void decompose( int node ){
    dfsInit( node, node );
    int centroid = findCentroid( node, node, sub[node] );
    // conquer
    
    f[0]++;
    for( int i = 0; i < adj[centroid].size(); i++ ){
        int viz = adj[centroid][i];
        if( removed[viz] ) continue;
        dfs( viz, centroid, 1 );
        for( int i = 0; i < freq.size(); i++ ) f[ freq[i] ]++;
        freq.clear();
    }
    
    for( int i = 0; i <= sub[node]; i++ ) f[i] = 0;
    
    removed[centroid] = true;
    
    // divide
    for( int i = 0; i < adj[centroid].size(); i++ ){
        int viz = adj[centroid][i];
        if( removed[viz] ) continue;
        decompose( viz );
    }
}
 
int main(){
    scanf("%d %d", &n, &k );
    for( int i = 1; i < n; i++ ){
        int a, b; scanf("%d %d", &a, &b );
        adj[a].pb(b);
        adj[b].pb(a);
    }
    decompose( 1 );
    printf("%lld", resp );
}