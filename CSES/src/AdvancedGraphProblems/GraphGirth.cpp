#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
 
const int maxn = 2510;
 
vector<int> adj[maxn];
 
int nivel[maxn], pai[maxn];
bool marc[maxn];
 
queue<int> fila;
 
int resp = maxn;
 
void reseta(){
    
    for( int i = 0; i < maxn; i++ ){
        marc[i] = false; 
        pai[i] = 0;
        nivel[i] = 0;
    } 
    
}
 
void add( int p, int x, int n ){
    
    nivel[x] = n;
    marc[x] = true;
    
    fila.push(x);
    
    pai[x] = p;
}
 
void bfs( int source ){
    
    add( 0, source, 0 );
    
    while( !fila.empty() ){
        
        int cur = fila.front();
        fila.pop();
        
        for( int i = 0; i < adj[cur].size(); i++ ){
            
            int viz = adj[cur][i];
            
            if( !marc[viz] ) add( cur, viz, nivel[cur] + 1 );
            else if( viz != pai[cur] ){
                
                resp = min( resp, nivel[viz] + nivel[cur] + 1 );
                
            } 
        }
    }
}
 
int main(){
    
    int n, m; scanf("%d %d", &n, &m );
    
    for( int i = 0; i < m; i++ ){
        
        int a, b; scanf("%d %d", &a, &b );
        
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    for( int i = 1; i <= n; i++ ){
        
        bfs(i);
        
        reseta();
    } 
    
    if( resp == maxn ) resp = -1;
    
    printf("%d", resp );
}