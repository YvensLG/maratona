const int alphabet = 26;

class SuffixAutomaton{
private:
  struct State{
    int link, len;
    vector<int> next;
    State() : link(-1), len(0){
      next.resize(alphabet, -1);
    }
  };

  vector<State> st;
  int last;

  int create(){
    st.emplace_back();
    return (int)st.size() - 1;
  }
public:
  SuffixAutomaton( string &s ){
    last = create();
    for( int i = 0, cur = 0; i < s.size(); i++, last = cur ){
      cur = create();
      st[cur].len = st[last].len + 1;

      int p = last, c = s[i] - 'a';
      while( p != -1 && st[p].next[c] == -1 ){
        st[p].next[c] = cur;
        p = st[p].link;
      }

      if( p == -1 ){
        st[cur].link = 0;
        continue;
      }

      int q = st[p].next[c];
      if( st[p].len + 1 == st[q].len ){
        st[cur].link = q;
        continue;
      }

      int clone = create();
      st[clone] = st[q];
      st[clone].len = st[p].len + 1;

      while( p != -1 && st[p].next[c] == q ){
        st[p].next[c] = clone;
        p = st[p].link;
      }

      st[cur].link = st[q].link = clone;
    }
  }

  string minimum_with_lenght( int n ){
    string resp;
    for( int state = 0, i = 0; i < n; i++ ){
      for( int c = 0; c < alphabet; c++ ) if( st[state].next[c] != -1 ){
        resp.push_back(c + 'a');
        state = st[state].next[c];
        break;
      }
    }
    return resp;
  }
};

int main(){
  string s; cin >> s;
  s += s;

  SuffixAutomaton aut(s);

  cout << aut.minimum_with_lenght((int)s.size()/2) << endl;
}
