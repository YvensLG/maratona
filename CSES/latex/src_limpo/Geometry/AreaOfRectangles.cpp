const int maxn = 1e6 + 10;

using ll = long long;

struct Event{
  int x, y1, y2, val;
  Event( int x, int y1, int y2, int val ) : x(x), y1(y1), y2(y2), val(val) {}

  bool operator < ( Event e ){
    return x < e.x;
  }
};

class SegTree{
private:
  struct Node{
    int mini, qtd, lazy;
    Node( int mini = 0, int qtd = 0 ) : mini(mini), qtd(qtd), lazy(0) {}

    Node operator + ( Node n ){
      if( mini == n.mini ) return Node( mini, qtd + n.qtd );
      if( mini < n.mini ) return *this;
      return n;
    }
  };

  int minx, maxx;
  vector<Node> seg;

  void build( int pos, int ini, int fim ){
    if( ini == fim ){ seg[pos] = Node( 0, 1 ); return; }
    int l = 2*pos, r = 2*pos + 1, mid = (ini + fim)>>1;
    build( l, ini, mid ); build( r, mid + 1, fim );
    seg[pos] = seg[l] + seg[r];
  }

  void refresh( int pos, int ini, int fim ){
    if( seg[pos].lazy == 0 ) return;
    int x = seg[pos].lazy; seg[pos].lazy = 0;
    seg[pos].mini += x;
    if( ini == fim ) return;
    int l = 2*pos, r = 2*pos + 1;
    seg[l].lazy += x;
    seg[r].lazy += x;
  }

  void update( int pos, int ini, int fim, int ki, int kf, int val ){
    refresh( pos, ini, fim );
    if( ki > fim || ini > kf ) return;
    if( ki <= ini && fim <= kf ){
      seg[pos].lazy = val;
      refresh( pos, ini, fim );
      return;
    }
    int l = 2*pos, r = 2*pos + 1, mid = (ini + fim)>>1;
    update( l, ini, mid, ki, kf, val ); update( r, mid + 1, fim, ki, kf, val );
    seg[pos] = seg[l] + seg[r];
  }
public:
  SegTree( int minx, int maxx ) : minx(minx), maxx(maxx) {
    seg.resize(4*(maxx - minx + 1));
    build( 1, minx, maxx );
  }

  void update( int l, int r, int val ){
    update( 1, minx, maxx, l, r, val );
  }

  ll query(){
    return maxx - minx + 1 - (( seg[1].mini == 0 ) ? seg[1].qtd : 0 );
  }
};

int main(){
  int n; cin >> n;

  SegTree seg( -maxn, maxn );

  vector<Event> line;
  while( n-- ){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if( x1 > x2 ) swap( x1, x2 );
    if( y1 > y2 ) swap( y1, y2 );

    line.emplace_back( x1, y1, y2 - 1, 1 );
    line.emplace_back( x2, y1, y2 - 1, -1 );
  }

  sort( line.begin(), line.end() );

  ll area = 0;
  int prev_x = -maxn;
  for( auto evento : line ){
    area += seg.query()*(evento.x - prev_x);
    seg.update( evento.y1, evento.y2, evento.val );
    prev_x = evento.x;
  }

  cout << area << endl;
}
