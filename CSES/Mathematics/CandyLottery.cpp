#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
 
int main() {
    ios::sync_with_stdio(0), cout.tie(0);
    int n, k; cin >> n >> k;
    ld total = 0;
 
    for(int i = 1; i <= k; i++){
        total += 1 - pow((i-1) / (ld)k, (ld)n);
    }
 
    cout << setprecision(6) << fixed;
    cout << total << '\n';
 
    return 0;
}