#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s; cin >> s;
 
  auto get_id = [&]( char c ){
    if( c == 'A' ) return 0;
    if( c == 'T' ) return 1;
    if( c == 'C' ) return 2;
    return 3;
  };
 
  vector<bool> ok(4);
  int cont = 0;
  string resp;
  string letras = "ATCG";
 
  for( char c : s ){
    if( !ok[get_id(c)] ) cont++;
    ok[get_id(c)] = true;
 
    if( cont == 4 ){
      resp.push_back(c);
      fill( ok.begin(), ok.end(), false );
      cont = 0;
    }
  }
 
  for( int i = 0; i < 4; i++ ) if( !ok[i] ){
    resp.push_back(letras[i]);
    break;
  }
 
  cout << resp << endl;
 
}
