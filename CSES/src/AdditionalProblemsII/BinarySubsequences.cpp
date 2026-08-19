#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
 
int ans_tam(int a, int b) {
    if (a == b || a == 0 || b == 0) return 0;
    else if (a > b) return a / b + ans_tam(a % b, b);
    else return b / a + ans_tam(a, b % a);
}
 
string ans(int a, int b) {
    if (a == b) return "";
    else if (a > b) 
        return '1' + ans(a - b, b);
    else
        return '0' + ans(a, b - a);
}
 
void solve() {
    int n; cin >> n; n++;
    int a, b, mini = -1;
    int bsta, bstb;
 
    for (a = 1; a <= n + 1; a++) {
        if (__gcd(n + 1, a) != 1) continue;
        b = n + 1 - a;
        int tam = ans_tam(a, b);
        if (mini == -1 || tam < mini) {
            mini = tam;
            bsta = a;
            bstb = b;
        }
    }
 
    cout << ans(bsta, bstb) << '\n';
}
 
signed main() { _
    solve();
}