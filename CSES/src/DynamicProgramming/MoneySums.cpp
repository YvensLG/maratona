#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1e6 + 5, inf = 2e9, M = 1e9 + 7;
 
void solve() {
    int n; cin >> n;
    bitset<maxn> mark;
    mark[0] = 1;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mark = (mark | mark << a);
    }

    cout << mark.count() - 1 << '\n';
    for(int i = 1; i < maxn; i++)
        if(mark[i] == 1)
            cout << i << ' ';
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}