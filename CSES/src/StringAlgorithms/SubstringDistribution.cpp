#include <bits/stdc++.h>
using namespace std;
 
const int alphabet = 26;
 
class SuffixAutomaton{
public:
  struct State{
    int link, len;
    vector<int> adj;
    State( int link = -1, int len = 0 ) : link(link), len(len) {
      adj.resize(alphabet, -1);
    }
  };
  vector<State> st;
 
  int last;
 
  int create(){
    st.emplace_back();
    return (int)st.size() - 1;
  }
 
  SuffixAutomaton( const string &s ){
    last = create();
    for( int i = 0, cur = 0; i < (int)s.size(); i++, last = cur ){
      cur = create();
      st[cur].len = st[last].len + 1;
      int p = last, c = s[i] - 'a';
      while( p != -1 && st[p].adj[c] == -1 ){
        st[p].adj[c] = cur;
        p = st[p].link;
      }
 
      if( p == -1 ){
        st[cur].link = 0;
        continue;
      }
 
      int q = st[p].adj[c];
      if( st[p].len + 1 == st[q].len ){
        st[cur].link = q;
        continue;
      }
 
      int clone = create();
      st[clone] = st[q];
      st[clone].len = st[p].len + 1;
 
      while( p != -1 && st[p].adj[c] == q ){
        st[p].adj[c] = clone;
        p = st[p].link;
      }
 
      st[q].link = st[cur].link = clone;
    }
  }
};
 
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string s; cin >> s;
 
  SuffixAutomaton aut(s);
 
  vector<int> resp(s.size());
 
  for( int i = 1; i < aut.st.size(); i++ ){
    resp[aut.st[aut.st[i].link].len]++;
    if( aut.st[i].len < s.size() ) resp[aut.st[i].len]--;
  }
 
  for( int i = 0; i < resp.size(); i++ ){
    if(i) resp[i] += resp[i - 1];
    cout << resp[i] << " ";
  } cout << endl;
}
