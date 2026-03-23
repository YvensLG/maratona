#include <bits/stdc++.h>
#define int long long

using namespace std;

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int calc(int k, int a, int b, int c, int ab, int ac, int bc, int abc) {
    a += ab; ab = 0;
    if(a % k == 0) {
        c += ac; ac = 0;
    }
    else if(a + ac >= (a / k + 1) * k) {
        ac -= (a / k + 1) * k - a;
        a = (a / k + 1) * k;
        c += ac; ac = 0;
    }
    else  {
        a += ac;
        ac = 0;
    }

    if(b % k == 0) {
        c += bc; bc = 0;
    }
    else if(b + bc >= (b / k + 1) * k) {
        bc -= (b / k + 1) * k - b;
        b = (b / k + 1) * k;
        c += bc; bc = 0;
    }
    else  {
        b += bc;
        bc = 0;
    }


    if(a % k && a + abc >= (a / k + 1) * k) {
        abc -= (a / k + 1) * k - a;
        a = (a / k + 1) * k;
    }
    else if(a % k){
        a += abc; abc = 0;
    }
    if(b % k && b + abc >= (b / k + 1) * k) {
        abc -= (b / k + 1) * k - b;
        b = (b / k + 1) * k;
    }
    else if(b % k){
        b += abc; abc = 0;
    }

    c += abc; abc = 0;

    return (a + k - 1) / k + (b + k - 1) / k + (c + k - 1) / k; 
}

void solve() {
    int k; cin >> k;
    int a, b, c, ab, bc, ac, abc;
    cin >> a >> b >> c >> ab >> bc >> ac >> abc;

    int at =     calc(k, a, b, c, ab, ac, bc, abc);
    at = min(at, calc(k, a, c, b, ac, ab, bc, abc));
    at = min(at, calc(k, b, a, c, ab, bc, ac, abc));
    at = min(at, calc(k, b, c, a, bc, ab, ac, abc));
    at = min(at, calc(k, c, a, b, ac, bc, ab, abc));
    at = min(at, calc(k, c, b, a, bc, ac, ab, abc));

    cout << at << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
