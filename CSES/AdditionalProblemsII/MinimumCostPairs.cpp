#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
void solve(){
    int n; cin >> n;
    vector<int> x(n);
    // num colisoes, diferenca, posicao
    set<tuple<int, int, int>> d;
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(all(x));

    for(int i = 0; i < n - 1; i++) {
        d.insert({0, x[i + 1] - x[i], i});
    }

    int tot = 0;
    for(int k = 1; k <= n / 2; k++) {
        auto top = *d.begin(); d.erase(d.begin());
        int i = get<2>(top);

        if(get<0>(top) == 0) {
            tot += get<1>(top);

            if(i + 1 < n - 1 && d.find({0, x[i + 2] - x[i + 1], i + 1}) != d.end()) {
                d.erase({0, x[i + 2] - x[i + 1], i + 1});
                d.insert({1, x[i + 2] - x[i + 1], i + 1});
            } else if(i + 1 < n - 1 && d.find({1, x[i + 2] - x[i + 1], i + 1}) != d.end()) {
                d.erase({1, x[i + 2] - x[i + 1], i + 1});
                d.insert({2, x[i + 2] - x[i + 1], i + 1});
            }

            if(i - 1 >= 0 && d.find({0, x[i] - x[i - 1], i - 1}) != d.end()) {
                d.erase({0, x[i] - x[i - 1], i - 1});
                d.insert({1, x[i] - x[i - 1], i - 1});
            } else if(i - 1 >= 0 && d.find({1, x[i] - x[i - 1], i - 1}) != d.end()) {
                d.erase({1, x[i] - x[i - 1], i - 1});
                d.insert({2, x[i] - x[i - 1], i - 1});
            }

            d.insert({2, x[i + 1] - x[i], i});
        
            cout << tot << '\n';
        }

        else if(get<1>(top) == 1) {

            

        }

    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}