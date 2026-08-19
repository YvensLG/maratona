
#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
 
typedef long long ftype;
typedef complex<ftype> point;
#define x real
#define y imag
 
// Li Chao tree
 
const int maxn = 2e5;
const long long INF = 4e18;
 
ftype dot(point a, point b) {
    return (conj(a) * b).x();
}
 
ftype f(point a,  ftype x) {
    return dot(a, {x, 1});
}
 
point line[4 * maxn];
 
void gen() {
    for (int i = 0; i < 4 * maxn; i++) {
        line[i] = {0, INF};
    }
}
 
void add_line(point nw, int v = 1, int l = 0, int r = maxn) {
    int m = (l + r) / 2;
    bool lef = f(nw, l) < f(line[v], l);
    bool mid = f(nw, m) < f(line[v], m);
    if(mid) {
        swap(line[v], nw);
    }
    if(r - l == 1) {
        return;
    } else if(lef != mid) {
        add_line(nw, 2 * v, l, m);
    } else {
        add_line(nw, 2 * v + 1, m, r);
    }
}
 
ftype get(int x, int v = 1, int l = 0, int r = maxn) {
    int m = (l + r) / 2;
    if(r - l == 1) {
        return f(line[v], x);
    } else if(x < m) {
        return min(f(line[v], x), get(x, 2 * v, l, m));
    } else {
        return min(f(line[v], x), get(x, 2 * v + 1, m, r));
    }
}
 
void solve() {
    gen();
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int q; cin >> q;
        if(q == 1) {
            int a, b; cin >> a >> b;
            add_line({-a, -b});
        }
        else {
            int x; cin >> x;
            cout << -get(x) << '\n';
        }
    }
 
}
 
signed main() { _
    solve();
}