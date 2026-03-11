#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 10'100;

vector<string> a[N];
bool p[N];

void f(int n) {
    if (sz(a[n])) return;
    if (n % 2 == 0) {
        f(n / 2);
        if (!p[n / 2]) {
            p[n] = 0;
            return;
        }
        p[n] = 1;
        for (auto x : a[n / 2]) {
            x.push_back('B');
            a[n].push_back(x);
        }
        reverse(all(a[n]));
        for (auto x : a[n / 2]) {
            x.push_back('W');
            a[n].push_back(x);
        }
    } else {
        
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    f(n);

    for (auto x : a[n]) {
        cout << x << "\n";
    }

    return 0;
}
