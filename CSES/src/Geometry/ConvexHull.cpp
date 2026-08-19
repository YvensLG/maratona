#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
struct Point{
  ll x, y;
  Point( ll x = 0, ll y = 0 ) : x(x), y(y) {}
 
  ll operator ^ ( Point p ){
    return x*p.y - y*p.x;
  }
 
  Point operator - ( Point p ){
    return Point( x - p.x, y - p.y );
  }
 
  bool operator < ( Point p ) {
    if( x == p.x ) return y < p.y; 
    return x < p.x;
  }
};
 
vector<Point> build( vector<Point> &points ){
  vector<Point> upper_hull;
  for( auto p : points ){
    while( upper_hull.size() > 1 ){
      Point last = upper_hull.back();
      Point sec_last = upper_hull[upper_hull.size() - 2];
      if( ((last - sec_last)^(p - sec_last)) > 0 ) upper_hull.pop_back();
      else break;
    }
 
    upper_hull.push_back(p);
  }
 
  vector<Point> lower_hull;
  for( auto p : points ){
    while( lower_hull.size() > 1 ){
      Point last = lower_hull.back();
      Point sec_last = lower_hull[lower_hull.size() - 2];
      if( ((last - sec_last)^(p - sec_last)) < 0 ) lower_hull.pop_back();
      else break;
    }
 
    lower_hull.push_back(p);
  }
 
  lower_hull.insert(lower_hull.end(), upper_hull.begin() + 1, upper_hull.end() - 1 );
  return lower_hull;
}
 
int main(){
  int n; cin >> n;
 
  vector<Point> points(n);
  for( auto &p : points ) cin >> p.x >> p.y;
  sort( points.begin(), points.end() );
 
  vector<Point> convex_hull = build(points);
 
  cout << convex_hull.size() << endl;
  for( auto p : convex_hull ) cout << p.x << " " << p.y << endl;
}