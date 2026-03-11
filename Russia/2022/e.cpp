#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define X first
#define R second

// presta atenção nessa linha
#define int long long
#define double long double
#define PI 3.1415926535897932384626
 
using namespace std;
typedef long long ll;
typedef pair<double, double> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

double heron(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

void solve(){
	int n; cin >> n;
    vector<pii> v(n);
    double tot = 0;
    for(int i = 0; i < n; i++)
    {   
        cin >> v[i].first >> v[i].second;
        tot += PI * v[i].R * v[i].R;
    }

    // cout << tot << endl;

    sort(v.begin(), v.end());

    for(int i = 0; i < n - 1; i++)
    {
        pii p1 = v[i], p2 = v[i + 1];
        double d = p2.X - p1.X;
        if(p1.R + p2.R <= d) continue;

        double A = heron(p1.R, p2.R, d);
        double a1 = 2 * asin(2 * A / (d * p1.R));
        double a2 = 2 * asin(2 * A / (d * p2.R));

        tot -= (p1.R * p1.R * (a1 - sin(a1))/ 2);
        tot -= (p2.R * p2.R * (a2 - sin(a2))/ 2);
    }

    cout << fixed << setprecision(10);
    cout << tot << '\n';
    
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}