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
const int M = 1e9 + 7;
const int inv2 = (M + 1) / 2;
const int maxn = 400005;

struct Evento{
    int x, id, type; Evento( int x, int id, int type ) : x(x), id(id), type(type) {}
    bool operator < ( Evento e ){
        if( x == e.x ) return type < e.type; 
        return x < e.x; 
    }
}

void solve(){
	int n; cin >> n; 

    vector<int> x(n), y(n), r(n); 

    vector<Evento> line; 
    set<pair<int, int>> s; 

    for( int i = 0; i < n; i++ ){
        cin >> x[i] >> y[i] >> r[i]; 
        line.push_back( Evento( x[i] - r[i], i, 0 ) ); 
        line.push_back( Evento( x[i] + r[i], i, 1 ) ); 
    }

    sort( line.begin(), line.end() ); 

    int resp = 0; 

    auto check = [&]( int a, int b ){
        return (x[a] - x[b])*(x[a] - x[b]) + (y[a] - y[b])*(y[a] - y[b]) == (r[a] + r[b])*(r[a] + r[b]); 
    }

    for( auto cur : line ){
        if( cur.type == 0 ){
            auto it = s.upper_bound({ y[cur.id], -1 });
            if( it != s.end() ){
                int id2 = it->second; 
                if( check( cur.id, id2 ) ) resp++; 
            }
            if( it != s.begin() ){
                int id2 = prev(it)->second; 
                if( check( cur.id, id2 ) ) resp++; 
            }

            
        }
        else{
            s.erase({ y[cur.id], cur.id }); 
        }
    }
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}