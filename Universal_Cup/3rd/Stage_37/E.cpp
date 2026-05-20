#include <bits/stdc++.h>
using namespace std; 

#define bug(x) cout << #x << " " << x << endl;

void solve(){
    int n, m; cin >> n >> m; 
    vector<vector<pair<int, int>>> adj(n + 1); 

    int id = 0; 
    for( int i = 0; i < m; i++ ){
        int a, b; cin >> a >> b; 
        a--; b--; 
        adj[a].push_back({ b, id }); 
        adj[b].push_back({ a, id }); 
        id++; 
    }

    for( int i = 0; i < n; i++ ) if( ((int)adj[i].size())%2 == 1 ){
        adj[n].push_back({ i, id }); 
        adj[i].push_back({ n, id });
        id++; 
    }

    vector<bool> marc(id), inp(n + 1); 
    vector<pair<int, int>> ordem; 
    vector<int> ans(id); 
    int cor = 1; 
    
    function<void(int, int)> dfs = [&]( int u, int eu ){
        while( !adj[u].empty() ){
            auto [v, ev] = adj[u].back(); 
            adj[u].pop_back(); 
            if( marc[ev] ) continue; 
            marc[ev] = true; 

            dfs( v, ev );
        }

        ordem.push_back({ u, eu });
    };

    for( int i = 0; i < n; i++ ) if( !adj[i].empty() ){
        dfs( i, -1 );
        stack<pair<int, int>> pilha; 

        for( auto [u, e] : ordem ){
            if( inp[u] ){
                while( pilha.top().first != u ){
                    ans[pilha.top().second] = cor; 
                    inp[pilha.top().first] = false; 
                    pilha.pop();
                } 
                ans[pilha.top().second] = cor; 
                inp[pilha.top().first] = false; 
                pilha.pop();
                cor++;
            }
            pilha.push({ u, e });
            inp[u] = true;
        }


        while( !pilha.empty() ){
            inp[pilha.top().first] = false; 
            pilha.pop();
        } 
        ordem.clear();
    } 

    for( int i = 0; i < m; i++ ) cout << ans[i] << " "; cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);     
    int t; cin >> t; 
    while( t-- ) solve(); 
}