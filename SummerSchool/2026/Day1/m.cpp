#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    int count = 0;
    
    for(int i = 0; i < n; i++) {
        if(v[i] % 2 == i % 2) {
            count = n - i;
            break;
        }
    }

    cout << count << '\n';

    return 0;
}