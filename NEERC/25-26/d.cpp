#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 0x3f3f3f3f;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll a, b, c; cin >> a >> b >> c;

    if(a == 0 and b == 0 and c == 0){
        cout << "Yes\na\na\na\n";
        return 0;
    }
    if (2 * a > a + b + c) return cout << "No\n", 0;
    if (2 * b > a + b + c) return cout << "No\n", 0;
    if (2 * c > a + b + c) return cout << "No\n", 0;
    
    bool odd = (a + b + c)&1;

    if (odd) {
        a--;
        b--;
        c--;
    }

    ll q1 = (a + b - c) / 2;
    ll q2 = (a - b + c) / 2;
    ll q3 = (-a + b + c) / 2;

    string s = string(q1, 'e') + string(q2, 'b') + string(q3, 'c');
    string t = string(q1, 'a') + string(q2, 'd') + string(q3, 'c');
    string u = string(q1, 'a') + string(q2, 'b') + string(q3, 'f');

    if (odd) {
        s += 'x';
        t += 'y';
        u += 'z';
    }

    cout << "Yes\n";
    cout << s << "\n";    
    cout << t << "\n";
    cout << u << "\n";
}