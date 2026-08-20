#include <bits/stdc++.h>
using namespace std;
 
using vi = vector<int>; 
const int maxn = 100; 
 
vi adj[2*maxn]; 
int match[2*maxn]; 
bool marc[2*maxn]; 
 
bool dfs( int u ){
    for( int v : adj[u] ) if( !marc[v] ){
        marc[v] = true; 
        if( match[v] == -1 || dfs(match[v]) ){
            match[u] = v; match[v] = u; 
            return true; 
        }
    }
    return false; 
}
 
int matching( int n ){
    bool ok = true; 
    int ans = 0; 
 
    fill( match, match + 2*n, -1 ); 
    while( ok ){
        ok = false; 
        fill( marc + n, marc + 2*n, false );
        for( int i = 0; i < n; i++ ) if( match[i] == -1 && dfs(i) ){
            ans++; ok = true; 
        }
    }
    return ans; 
}
 
vi get_cover( int n ){
    fill( marc, marc + 2*n, false ); 
    queue<int> q; 
    for( int i = 0; i < 2*n; i++ ) if( match[i] == -1 ){
        q.push(i);
    }
 
    vi cover; 
    for(; !q.empty(); q.pop() ){
        int u = q.front(); 
        for( int v : adj[u] ) if( !marc[v] ){
            cover.push_back(v); marc[v] = true; 
            q.push(match[v]); 
        }
    }
 
    for( int i = 0; i < 2*n; i++ ) if( match[i] != -1 ){
        if( !marc[i] && !marc[match[i]] ){
            marc[i] = true; 
            cover.push_back(i); 
        }
    }
    return cover; 
}
 
void solve(){
    int n; cin >> n; 
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ ){
            char c; cin >> c; 
            if( c == 'o' ){
                adj[i].push_back(j + n); 
                adj[j + n].push_back(i); 
            } 
        }
 
    cout << matching(n) << endl;
 
    vi cover = get_cover(n); 
    for( int x : cover ) cout << x/n + 1 << " " << x%n + 1 << "\n"; 
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve(); 
}