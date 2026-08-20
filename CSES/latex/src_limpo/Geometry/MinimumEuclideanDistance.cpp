using ll = long long;

const ll inf = 8e18 + 10;

struct Point{
  ll x, y;
  Point( ll x = 0, ll y = 0 ) : x(x), y(y) {}

  ll squared_distance( Point p ){
    return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y);
  }

  bool operator < ( Point p ){
    return y < p.y;
  }
};

ll solve( ll xl, ll xr, vector<Point> &points ){
  if( points.size() <= 1 ) return inf;
  if( xl == xr ){
    ll resp = inf;
    for( int i = 1; i < points.size(); i++ ) resp = min( resp, points[i].squared_distance( points[i - 1] ) );
    return resp;
  }

  vector<Point> pl, pr;
  ll mid = ( xl + xr )>>1;
  for( auto p : points ){
    if( p.x <= mid ) pl.push_back(p);
    else pr.push_back(p);
  }

  ll resp = min( solve( xl, mid, pl ), solve( mid + 1, xr, pr ) );
  ll D = ceil(sqrt(resp));

  pl.clear(), pr.clear();

  for( auto p : points ) if( (p.x - mid)*(p.x - mid) <= resp ) {
    if( p.x <= mid ) pl.push_back(p);
    else pr.push_back(p);
  }

  int p1 = 0, p2 = 0;
  for( auto p : pl ){
    while( p1 < pr.size() && (pr[p1].y - p.y)*(pr[p1].y - p.y) > resp && pr[p1].y < p.y ) p1++;
    while( p2 < pr.size() && ( (pr[p2].y - p.y)*(pr[p2].y - p.y) <= resp || pr[p2].y < p.y ) ) p2++;

    for( int i = p1; i < p2; i++ ) resp = min( resp, p.squared_distance( pr[i] ) );
  }

  return resp;
}

int main(){
  int n; cin >> n;
  vector<Point> points(n);

  for( auto &p : points ) cin >> p.x >> p.y;
  sort( points.begin(), points.end() );

  cout << solve( -1e9, 1e9, points ) << endl;
}
