#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const double pi = acos((double)-1);
int r = 1;

struct P {
    double x, y, z;
    P(double _x = 0, double _y = 0, double _z = 0) {
        x = _x, y = _y, z = _z;
    }
    void P2(double a, double b, double c) {
        double s = sqrt(a * a + b * b + c * c);
        x = (a * r) / s;
        y = (b * r) / s;
        z = (c * r) / s;
    }
    void P2() {
        double s = sqrt(x * x + y * y + z * z);
        x = (x * r) / s;
        y = (y * r) / s;
        z = (z * r) / s;
    }
    P operator+(P p) const { return P (x + p.x, y + p.y, z + p.z); }
    P operator-(P p) const { return P (x - p.x, y - p.y, z - p.z); } 
    P operator*(double p) const { return P (x * p, y * p, z * p); } 
    P operator/(double p) const { return P (x / p, y / p, z / p); } 
};

double sphericalDistance(P P1, P P2) {
    double dx = P1.x - P2.x, dy = P1.y - P2.y, dz = P1.z - P2.z;
    double d = sqrt(dx * dx + dy * dy + dz * dz) / r;
    if(abs(2 - d) < 1e-9) return pi * r;
    return r * 2 * asin(d / 2);
}

void solve() {
    cin >> r;
    int a, b, c;
    cin >> a >> b >> c;
    P base; base.P2(a, b, c);
    cin >> a >> b >> c;
    P from; from.P2(a, b, c);
    cin >> a >> b >> c;
    P to; to.P2(a, b, c);

    double fL = 0, fR = 1000;

    int q = 300;
    while(q--) {
        P midR = (from + to * 2) / 3, midL = (from * 2 + to) / 3;
        midL.P2(); midR.P2();

        fL = sphericalDistance(base, midL);
        fR = sphericalDistance(base, midR);

        if(fL < fR) {
            to = midR;
        }
        else {
            from = midL;
        }
    }

    cout << fL << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << setprecision(10) << fixed;

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}
