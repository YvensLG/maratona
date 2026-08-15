#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int h, l1, l2, l3;
int v1, v2, v3;

template<class F>
double gss(double a, double b, F f) {
	double r = (sqrt(5)-1)/2, eps = 1e-7;
	double x1 = b - r*(b-a), x2 = a + r*(b-a);
	double f1 = f(x1), f2 = f(x2);
	while (b-a > eps)
		if (f1 < f2) { //change to > to find maximum
			b = x2; x2 = x1; f2 = f1;
			x1 = b - r*(b-a); f1 = f(x1);
		} else {
			a = x1; x1 = x2; f1 = f2;
			x2 = a + r*(b-a); f2 = f(x2);
		}
	return a;
}

void solve() {
    cin >> h >> l1 >> l2 >> l3;
    int t; cin >> t;

    while(t--) {
        cin >> v1 >> v2 >> v3;

        auto eval_h1 = [&](double h1) {
            auto eval_h2 = [&](double h2) {
                double h3 = h - h1 - h2;
                return  sqrt(l1 * l1 + h1 * h1) / v1 + 
                        sqrt(l2 * l2 + h2 * h2) / v2 + 
                        sqrt(l3 * l3 + h3 * h3) / v3;
            };
            
            double best_h2 = gss(0.0, h - h1, eval_h2);
            return eval_h2(best_h2);
        };

        double best_h1 = gss(0.0, h, eval_h1);
        double ans = eval_h1(best_h1);
        
        cout << fixed << setprecision(11) << ans << "\n";
    }    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();

    return 0; 
}
