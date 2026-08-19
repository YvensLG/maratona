struct Evento{
  int val, pos, id; Evento( int val, int pos, int id ) : val(val), pos(pos), id(id) {}
  bool operator < ( Evento e ){
    return (( val == e.val ) ? abs(id) < abs(e.id) : val < e.val );
  }
};
vector<Evento> line;

int main(){
  int n, q; cin >> n >> q;
  for( int i = 1; i <= n; i++ ){
    int x; cin >> x;
    line.push_back( Evento( x, i, 0 ) );
  }

  for( int i = 1; i <= q; i++ ){
    int l, r, mini, maxi; cin >> l >> r >> mini >> maxi;
    line.push_back( Evento( mini - 1, l - 1, i ) );
    line.push_back( Evento( mini - 1, r, -i ) );
    line.push_back( Evento( maxi, l - 1, -i ) );
    line.push_back( Evento( maxi, r, i ) );
  }

  vector<int> resp(q + 1);

  sort( line.begin(), line.end() );

  vector<int> bit( n + 1 );
  auto update = [&]( int id, int val ){
    for( int i = id; i < bit.size(); i += i&-i ) bit[i] += val;
  };

  auto query = [&]( int id ){
    int sum = 0;
    for( int i = id; i > 0; i -= i&-i ) sum += bit[i];
    return sum;
  };

  for( auto evento : line ){
    if( evento.id == 0 ) update( evento.pos, 1 );
    else if( evento.id < 0 ) resp[-evento.id] -= query( evento.pos );
    else resp[evento.id] += query( evento.pos );
  }

  for( int i = 1; i <= q; i++ ) cout << resp[i] << endl;
}
