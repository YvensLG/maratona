#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> S;
    for(int i = 0; i < 10; i++) {
        int a; cin >> a;
        S.insert(a);
    }
    cout << 4 - S.size() << '\n';
}