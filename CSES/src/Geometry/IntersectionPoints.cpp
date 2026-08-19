#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int maxn = 1e6 + 10;
 
struct Event{
  int x, y1, y2;
  Event( int x, int y1, int y2 ) : x(x), y1(y1), y2(y2) {}
 
  bool operator < ( Event e ){
    return x < e.x;
  }
};
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n;
 
  vector<Event> line;
  for( int i = 0; i < n; i++ ){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    x1 += maxn;
    x2 += maxn;
    y1 += maxn;
    y2 += maxn;
    if( y1 > y2 ) swap( y1, y2 );
    if( x1 > x2 ) swap( x1, x2 );
 
    if( x1 == x2 ) line.emplace_back( x1, y1, y2 );
    else{
      line.emplace_back( x1, y1, 1 );
      line.emplace_back( x2, y1, -1 );
    }
  }
 
  sort( line.begin(), line.end() );
 
  vector<int> BIT( 2*maxn );
 
  auto update = [&]( int i, int val ){
    for(; i < BIT.size(); i += i&-i ) BIT[i] += val;
  };
 
  auto query = [&]( int i ){
    int resp = 0;
    for(; i > 0; i -= i&-i ) resp += BIT[i];
    return resp;
  };
 
  ll resp = 0;
 
  for( auto evento : line ){
    if( abs(evento.y2) == 1 ) update( evento.y1, evento.y2 );
    else resp += query( evento.y2 ) - query( evento.y1 );
  }
 
  cout << resp << endl;
}
