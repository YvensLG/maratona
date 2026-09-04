#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int m = 1e9;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        m = min(m, b / a);
    }
    cout << m << '\n';
}