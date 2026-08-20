#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 2e5 + 10;
bool marc[maxn];
int p[maxn]; int n; 
deque<int> deq;
 
int count(){
    int cont = 0;
    for( int i = 1; i <= n; i++ ){
        if( p[i] == i ) cont = max( cont, 0 );
        else if( p[p[i]] == i ) cont = max( cont, 1 );
        else cont = 2;
    }
    return cont;
}
 
void marca( int cur ){
    deq.clear();
    while( true ){ marc[cur] = true; deq.push_back(cur); cur = p[cur]; if( marc[cur] ) return; }
}
 
void quebra(){
    vector< pair< int, int > > v;
    for( int i = 1; i <= n; i++ ){
        if( p[i] == i || p[p[i]] == i ) continue;
        if( marc[i] ) continue; marca(i);
        deq.pop_back();
        while( deq.size() > 1 ){
            int ini = deq.front(), fim = deq.back();
            v.push_back({ ini, fim });
            swap( p[ini], p[fim] );
            deq.pop_front(); deq.pop_back();
        } 
    }
    cout << v.size() << endl;
    for( auto x : v ) cout << x.first << " " << x.second << endl;
}
 
void troca(){
    vector< pair< int, int > > v;
    for( int i = 1; i <= n; i++ ) if( p[p[i]] == i && p[i] > i ) v.push_back({ i, p[i] });
    cout << v.size() << endl;
    for( auto x : v ) cout << x.first << " " << x.second << endl;
}
 
int main(){
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> p[i];
    int qtd = count();
    cout << qtd << endl;
    if( qtd == 2 ) quebra();
    if( qtd >= 1 ) troca();
}
